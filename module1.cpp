#include "framework.h"
#include "module1.rh"

static INT_PTR CALLBACK Dlg1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return 1;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDNEXT)
		{
			EndDialog(hDlg, 1);
			return 1;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, 0);
			return 1;
		}
		break;
	}
	return 0;
}
int Func_MOD1(HWND hWnd, HINSTANCE hInst)

{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg1);
}
