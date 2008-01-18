/*
 * Copyright (c) 2007 Supercomputing Systems AG
 * All rights reserved.
 *
 * Author: Markus Berner
 */

#include <stdio.h>
#include <stdlib.h>

#define TEMP_FILE_LOCATION "/tmp/"
#define U_BOOT_PARTITION "/dev/mtd1"
#define LINUX_PARTITION "/dev/mtd2"
//#define SERVER_IP "192.168.0.3"

int main(int argc, char** argv)
{
  FILE * pF;
  void * pBuf;
  char sTemp[256];
  char * sImgName;

  int ret = -1;
  unsigned int * pWrd;
  
  if(argc != 2)
  {
      printf("Usage: %s <image file>\n", argv[0]);
      return -1;
  }
  
  sImgName = argv[1];
  
  printf("Transferring %s from %s over tftp.\n", sImgName, SERVER_IP);
  sprintf(sTemp, "tftp %s -g -l %s%s -r %s\n", SERVER_IP, TEMP_FILE_LOCATION, sImgName, sImgName);
  ret = system(sTemp);
  if(ret != 0)
    {
      printf("Transfer failed! Aborting...\n");
      return -1;
    }

  sprintf(sTemp, "%s%s", TEMP_FILE_LOCATION, sImgName);
  pF = fopen(sTemp, "rb");
  if(!pF)
  {
      printf("Unable to open %s!\n", sImgName);
      return -1;
  }
  
  pBuf = malloc(1024);
  
  fread(pBuf, 4, 1, pF);
  pWrd = (unsigned int*)pBuf;
  
  switch(*pWrd)
    {
    case 0xFF800020:
    case 0xFF800040:
    case 0xFF800060:
      printf("Magic word of U-Boot image found\n");
      printf("Copying to %s...\n", U_BOOT_PARTITION);
      sprintf(sTemp, "cp %s%s %s\n", TEMP_FILE_LOCATION, sImgName, U_BOOT_PARTITION); 
      ret = system(sTemp);
      goto cleanup;
      break;
    case 0x56190527:
      printf("Magic word of OS image found!\n");
      printf("Copying to %s...\n", LINUX_PARTITION);
      sprintf(sTemp, "cp %s%s %s\n", TEMP_FILE_LOCATION, sImgName, LINUX_PARTITION); 
      ret = system(sTemp);
      goto cleanup;
      break;
    default:
      printf("Image not recognized!\n");
      goto cleanup;
      break;
    }
 cleanup:
   sprintf(sTemp, "rm %s%s\n", TEMP_FILE_LOCATION, sImgName);
   return ret;
}
