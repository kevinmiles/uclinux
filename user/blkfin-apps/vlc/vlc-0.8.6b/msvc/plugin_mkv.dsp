# Microsoft Developer Studio Project File - Name="plugin_mkv" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=plugin_mkv - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "plugin_mkv.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "plugin_mkv.mak" CFG="plugin_mkv - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "plugin_mkv - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "plugin_mkv - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "plugin_mkv - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_MT" /D "_DLL" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "." /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_MT" /D "_DLL" /YX /FD -I..\include /c
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib /nologo /dll /machine:I386 /entry:_CRT_INIT@12 /out:"plugins\libmkv_plugin.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib netapi32.lib winmm.lib comctl32.lib rpcrt4.lib /nologo /dll /machine:I386 /entry:_CRT_INIT@12 /opt:ref /out:"plugins\libmkv_plugin.dll"

!ELSEIF  "$(CFG)" == "plugin_mkv - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_MT" /D "_DLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_MT" /D "_DLL" /FR /YX /FD /GZ -I..\include /c
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib /nologo /dll /subsystem:console /debug /machine:I386 /pdbtype:sept /entry:_CRT_INIT@12 /pdb:"plugins\libmkv_plugin.pdb" /out:"plugins\libmkv_plugin.dll"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib netapi32.lib winmm.lib comctl32.lib rpcrt4.lib /nologo /dll /subsystem:console /debug /machine:I386 /pdbtype:sept /entry:_CRT_INIT@12 /pdb:"plugins\libmkv_plugin.pdb" /out:"plugins\libmkv_plugin.dll"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "plugin_mkv - Win32 Release"
# Name "plugin_mkv - Win32 Debug"

# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"

# Begin Source File
SOURCE="..\modules\demux\mkv.cpp"
# ADD CPP /D "__VLC__" /D "__PLUGIN__"  /D "MODULE_NAME=mkv" /D "MODULE_NAME_IS_mkv" 
!IF "$(CFG)" == "plugin_mkv - Win32 Release"
# PROP Output_Dir "Release\modules\demux"
# PROP Intermediate_Dir "Release\modules\demux"
!ELSEIF "$(CFG)" == "plugin_mkv - Win32 Debug"
# PROP Output_Dir "Debug\modules\demux"
# PROP Intermediate_Dir "Debug\modules\demux"
# End Source File
# Begin Source File
SOURCE="..\modules\demux\mp4\libmp4.c"
# ADD CPP /D "__VLC__" /D "__PLUGIN__"  /D "MODULE_NAME=mkv" /D "MODULE_NAME_IS_mkv" 
!IF "$(CFG)" == "plugin_mkv - Win32 Release"
# PROP Output_Dir "Release\modules\demux"
# PROP Intermediate_Dir "Release\modules\demux"
!ELSEIF "$(CFG)" == "plugin_mkv - Win32 Debug"
# PROP Output_Dir "Debug\modules\demux"
# PROP Intermediate_Dir "Debug\modules\demux"
# End Source File
# Begin Source File
SOURCE="..\modules\demux\mp4\drms.c"
# ADD CPP /D "__VLC__" /D "__PLUGIN__"  /D "MODULE_NAME=mkv" /D "MODULE_NAME_IS_mkv" 
!IF "$(CFG)" == "plugin_mkv - Win32 Release"
# PROP Output_Dir "Release\modules\demux"
# PROP Intermediate_Dir "Release\modules\demux"
!ELSEIF "$(CFG)" == "plugin_mkv - Win32 Debug"
# PROP Output_Dir "Debug\modules\demux"
# PROP Intermediate_Dir "Debug\modules\demux"
# End Source File

# End Group

# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"


# End Group

# End Target
# End Project