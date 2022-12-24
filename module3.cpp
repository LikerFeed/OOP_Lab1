#include "framework.h"
#include "module3.rh"

WCHAR* ptext;
TCHAR indx;

static INT_PTR CALLBACK Dlg3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"IM-11");
        SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"IM-12");
        SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"IM-13");
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            indx = SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETTEXT, indx, LPARAM(ptext));
            EndDialog(hDlg, 1);
            break;
        }
        if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
        break;
    }
    return (INT_PTR)FALSE;
}

int Func_MOD3(HWND hWnd, HINSTANCE hI, WCHAR* p)
{
    ptext = p;
    return DialogBox(hI, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, Dlg3);
}
