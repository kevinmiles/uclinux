#ifndef lint
static char *RCSid = "$Id: wpause.c 629 2005-02-17 10:27:26Z hennerich $";
#endif

/* GNUPLOT - win/wpause.c */
/*[
 * Copyright 1992, 1993, 1998   Russell Lang
 *
 * Permission to use, copy, and distribute this software and its
 * documentation for any purpose with or without fee is hereby granted,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 *
 * Permission to modify the software is granted, but not the right to
 * distribute the complete modified source code.  Modifications are to
 * be distributed as patches to the released version.  Permission to
 * distribute binaries produced by compiling modified sources is granted,
 * provided you
 *   1. distribute the corresponding source modifications from the
 *    released version in the form of a patch file along with the binaries,
 *   2. add special version identification to distinguish your version
 *    in addition to the base release version number,
 *   3. provide your name and address as the primary contact for the
 *    support of your modified version, and
 *   4. retain our contact information in regard to use of the base
 *    software.
 * Permission to distribute the released version of the source code along
 * with corresponding source modifications in the form of a patch file is
 * granted with same provisions 2 through 4 for binary distributions.
 *
 * This software is provided "as is" without express or implied warranty
 * to the extent permitted by applicable law.
]*/

/*
 * AUTHORS
 * 
 *   Russell Lang
 * 
 * Send your comments or suggestions to 
 *  info-gnuplot@dartmouth.edu.
 * This is a mailing list; to join it send a note to 
 *  majordomo@dartmouth.edu.  
 * Send bug reports to
 *  bug-gnuplot@dartmouth.edu.
 */
/* PauseBox() */

/* MessageBox ALWAYS appears in the middle of the screen so instead */
/* we use this PauseBox so we can decide where it is to be placed */

#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <string.h>
#include "wgnuplib.h"
#include "wresourc.h"
#include "wcommon.h"

/* Pause Window */
LRESULT CALLBACK WINEXPORT WndPauseProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WINEXPORT PauseButtonProc(HWND, UINT, WPARAM, LPARAM);

/* Create Pause Class */
/* called from PauseBox the first time a pause window is created */
void
CreatePauseClass(LPPW lppw)
{
	WNDCLASS wndclass;

	wndclass.style = 0;
	wndclass.lpfnWndProc = (WNDPROC)WndPauseProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = sizeof(void FAR *);
	wndclass.hInstance = lppw->hInstance;
	wndclass.hIcon = NULL;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szPauseClass;
	RegisterClass(&wndclass);
}

/* PauseBox */
int WDPROC
PauseBox(LPPW lppw)
{
	MSG msg;
	HDC hdc;
	int width, height;
	TEXTMETRIC tm;
	RECT rect;

	if (!lppw->hPrevInstance)
		CreatePauseClass(lppw);
	GetWindowRect(GetDesktopWindow(), &rect);
	if ( (lppw->Origin.x == CW_USEDEFAULT) || (lppw->Origin.x == 0) )
		lppw->Origin.x = (rect.right + rect.left) / 2;
	if ( (lppw->Origin.y == CW_USEDEFAULT) || (lppw->Origin.y == 0) )
		lppw->Origin.y = (rect.bottom + rect.top) / 2;

	hdc = GetDC(NULL);
	SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
	GetTextMetrics(hdc, &tm);
	width  = max(24,4+_fstrlen(lppw->Message)) * tm.tmAveCharWidth;
	width = min(width, rect.right-rect.left);
	height = 28 * (tm.tmHeight + tm.tmExternalLeading) / 4;
	ReleaseDC(NULL,hdc);

#ifndef WIN32
	lppw->lpfnPauseButtonProc = 
#ifdef __DLL__
		(WNDPROC)GetProcAddress(hdllInstance, "PauseButtonProc");
#else
		(WNDPROC)MakeProcInstance((FARPROC)PauseButtonProc ,hdllInstance);
#endif
#endif
	lppw->hWndPause = CreateWindowEx(WS_EX_DLGMODALFRAME, 
		szPauseClass, lppw->Title,
/* HBB 981202: WS_POPUPWINDOW would have WS_SYSMENU in it, but we don't
 * want, nor need, a System menu in our Pause windows. Actually, it was
 * emptied manually, in the WM_CREATE handler below, in the original code.
 * This solution seems cleaner. */
		WS_POPUP | WS_BORDER | WS_CAPTION,
		lppw->Origin.x - width/2, lppw->Origin.y - height/2,
		width, height,
		lppw->hWndParent, NULL, lppw->hInstance, lppw);
	ShowWindow(lppw->hWndPause, SW_SHOWNORMAL);
	BringWindowToTop(lppw->hWndPause);
	UpdateWindow(lppw->hWndPause);

	lppw->bPause = TRUE;
	lppw->bPauseCancel = IDCANCEL;
	while (lppw->bPause) {
		/* HBB 20021211: Nigel Nunn found a better way to avoid
		 * 100% CPU load --> use it */
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			/* wait until window closed */
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else
			WaitMessage();
	}
	DestroyWindow(lppw->hWndPause);
#ifndef WIN32
#ifndef __DLL__
	FreeProcInstance((FARPROC)lppw->lpfnPauseButtonProc);
#endif
#endif

	return(lppw->bPauseCancel);
}

LRESULT CALLBACK WINEXPORT
WndPauseProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	TEXTMETRIC tm;
	LPPW lppw;
	int cxChar, cyChar, middle;

	lppw = (LPPW)GetWindowLong(hwnd, 0);

	switch(message) {
		case WM_KEYDOWN:
			if (wParam == VK_RETURN) {
				if (lppw->bDefOK)
					SendMessage(hwnd, WM_COMMAND, IDOK, 0L);
				else
					SendMessage(hwnd, WM_COMMAND, IDCANCEL, 0L);
			}
			return(0);
		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDCANCEL:
				case IDOK:
					lppw->bPauseCancel = LOWORD(wParam);
					lppw->bPause = FALSE;
					break;
			}
			return(0);
		case WM_SETFOCUS:
			SetFocus(lppw->bDefOK ? lppw->hOK : lppw->hCancel);
			return(0);
		case WM_PAINT:
			{
			hdc = BeginPaint(hwnd, &ps);
			SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
			SetTextAlign(hdc, TA_CENTER);
			GetClientRect(hwnd, &rect);
			SetBkMode(hdc,TRANSPARENT);
			TextOut(hdc,(rect.right+rect.left)/2, (rect.bottom+rect.top)/6,
				lppw->Message,_fstrlen(lppw->Message));
			EndPaint(hwnd, &ps);
			return 0;
			}
		case WM_CREATE:
			{
			/* HBB 981202 HMENU sysmenu = GetSystemMenu(hwnd, FALSE); */
			lppw = ((CREATESTRUCT FAR *)lParam)->lpCreateParams;
			SetWindowLong(hwnd, 0, (LONG)lppw);
			lppw->hWndPause = hwnd;
			hdc = GetDC(hwnd);
			SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
			GetTextMetrics(hdc, &tm);
			cxChar = tm.tmAveCharWidth;
			cyChar = tm.tmHeight + tm.tmExternalLeading;
			ReleaseDC(hwnd,hdc);
			middle = ((LPCREATESTRUCT) lParam)->cx / 2;
			lppw->hOK = CreateWindow((LPSTR)"button", (LPSTR)"OK",
				WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
					middle - 10*cxChar, 3*cyChar,
					8*cxChar, 7*cyChar/4,
					hwnd, (HMENU)IDOK,
					((LPCREATESTRUCT) lParam)->hInstance, NULL);
			lppw->bDefOK = TRUE;
			lppw->hCancel = CreateWindow((LPSTR)"button", (LPSTR)"Cancel",
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					middle + 2*cxChar, 3*cyChar,
					8*cxChar, 7*cyChar/4,
					hwnd, (HMENU)IDCANCEL,
					((LPCREATESTRUCT) lParam)->hInstance, NULL);
			lppw->lpfnOK = (WNDPROC) GetWindowLong(lppw->hOK, GWL_WNDPROC);
#ifdef WIN32
			SetWindowLong(lppw->hOK, GWL_WNDPROC, (LONG)PauseButtonProc);
#else
			SetWindowLong(lppw->hOK, GWL_WNDPROC, (LONG)lppw->lpfnPauseButtonProc);
#endif
			lppw->lpfnCancel = (WNDPROC) GetWindowLong(lppw->hCancel, GWL_WNDPROC);
#ifdef WIN32
			SetWindowLong(lppw->hCancel, GWL_WNDPROC, (LONG)PauseButtonProc);
#else
			SetWindowLong(lppw->hCancel, GWL_WNDPROC, (LONG)lppw->lpfnPauseButtonProc);
#endif
			if (GetParent(hwnd))
				EnableWindow(GetParent(hwnd),FALSE);
#if 0 /* HBB 981203 */
			DeleteMenu(sysmenu,SC_RESTORE,MF_BYCOMMAND);
			DeleteMenu(sysmenu,SC_SIZE,MF_BYCOMMAND);
			DeleteMenu(sysmenu,SC_MINIMIZE,MF_BYCOMMAND);
			DeleteMenu(sysmenu,SC_MAXIMIZE,MF_BYCOMMAND);
			DeleteMenu(sysmenu,SC_TASKLIST,MF_BYCOMMAND);
			DeleteMenu(sysmenu,0,MF_BYCOMMAND); /* a separator */
			DeleteMenu(sysmenu,0,MF_BYCOMMAND); /* a separator */
#endif
			}
			return 0;
		case WM_DESTROY:
			GetWindowRect(hwnd, &rect);
			lppw->Origin.x = (rect.right+rect.left)/2;
			lppw->Origin.y = (rect.bottom+rect.top)/2;
			lppw->bPause = FALSE;
			if (GetParent(hwnd))
				EnableWindow(GetParent(hwnd),TRUE);
			break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}


LRESULT CALLBACK WINEXPORT
PauseButtonProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LPPW lppw;
#ifdef WIN32
	LONG n = GetWindowLong(hwnd, GWL_ID);
#else
	WORD n = GetWindowWord(hwnd, GWW_ID);
#endif
	lppw = (LPPW)GetWindowLong(GetParent(hwnd), 0);
	switch(message) {
		case WM_KEYDOWN:
			switch(wParam) {
			  case VK_TAB:
			  case VK_BACK:
			  case VK_LEFT:
			  case VK_RIGHT:
			  case VK_UP:
			  case VK_DOWN:
				lppw->bDefOK = !(n == IDOK);
				if (lppw->bDefOK) {
					SendMessage(lppw->hOK,     BM_SETSTYLE, (WPARAM)BS_DEFPUSHBUTTON, (LPARAM)TRUE);
					SendMessage(lppw->hCancel, BM_SETSTYLE, (WPARAM)BS_PUSHBUTTON, (LPARAM)TRUE);
					SetFocus(lppw->hOK);
				}
				else {
					SendMessage(lppw->hOK,     BM_SETSTYLE, (WPARAM)BS_PUSHBUTTON, (LPARAM)TRUE);
					SendMessage(lppw->hCancel, BM_SETSTYLE, (WPARAM)BS_DEFPUSHBUTTON, (LPARAM)TRUE);
					SetFocus(lppw->hCancel);
				}
				break;
			  default:
				SendMessage(GetParent(hwnd), message, wParam, lParam);
			}
			break;
	}
	return CallWindowProc(((n == IDOK) ? lppw->lpfnOK : lppw->lpfnCancel),
		 hwnd, message, wParam, lParam);
}
