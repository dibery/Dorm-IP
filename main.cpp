#include <windows.h>
#include <cstring>
#include <cstdio>
#include "resource.h"

const char* get_addr();
void set(), setxp(), set8(), clear(), clearxp(), clear8();
HWND hEdit, hIPa, hIPb;
int ver, ipa = -1, ipb = -1;

LRESULT CALLBACK WinProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{
    WNDCLASSEX wClass;
    ZeroMemory(&wClass,sizeof(WNDCLASSEX));
    wClass.cbClsExtra=0;
    wClass.cbSize=sizeof(WNDCLASSEX);
    wClass.cbWndExtra=0;
    wClass.hbrBackground=(HBRUSH)COLOR_WINDOW;
    wClass.hCursor=LoadCursor(NULL,IDC_ARROW);
    wClass.hIcon=LoadIcon(hInst,MAKEINTRESOURCE(IDI_APP_ICON));
    wClass.hIconSm=LoadIcon(hInst,MAKEINTRESOURCE(IDI_APP_ICON));
    wClass.hInstance=hInst;
    wClass.lpfnWndProc=(WNDPROC)WinProc;
    wClass.lpszClassName="Window Class";
    wClass.lpszMenuName=NULL;
    wClass.style=CS_HREDRAW|CS_VREDRAW;

    if(!RegisterClassEx(&wClass))
    {
        //int nResult=GetLastError();
        MessageBox(NULL,
                   "Window class creation failed\r\n",
                   "Window Class Failed",
                   MB_ICONERROR);
    }

    HWND hWnd=CreateWindowEx(0,
                             "Window Class",
                             "NCCU �J�����U�u��",
                             WS_OVERLAPPEDWINDOW,
                             200,
                             80,
                             580,
                             610,
                             NULL,
                             NULL,
                             hInst,
                             NULL);

    if(!hWnd)
    {
//        int nResult=GetLastError();

        MessageBox(NULL,
                   "Window creation failed\r\n",
                   "Window Creation Failed",
                   MB_ICONERROR);
    }
	MessageBox(NULL,"���{���ѷ|�p�t 99 �Ůդͻs�@\n�p��������D�A�ШӫH unullife@gmail.com\n�`�N�A���楻�{���ɽФŶ}�Ҩ䥦�����]�w\n�]�Ҧp�����M�@�Τ��ߡ^","About the Author",MB_ICONINFORMATION);
    ShowWindow(hWnd,SW_SHOW);

    MSG msg;
    ZeroMemory(&msg,sizeof(MSG));

    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
    switch(msg)
    {
    case WM_CREATE:
    {
        // Create an edit box
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "Step 1. ���o�����d�d��",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    40,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP1,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "Step 2. �����d�d��",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    100,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP2,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "Step 3. �ƻs�����d�d��",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    160,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP3,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "Step 4. �}�ҵ������U����",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    220,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP4,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "Step 5. ��ܧ@�~�t�Ϊ���",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    280,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP5,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "Step 6. ��J���U�n�� IP",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    340,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP6,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "Step 7. �]�w IP",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    400,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP7,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "Step 8. �]�w����",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    460,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP8,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "���J����M�� IP �]�w�A���I�o��",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    50,
                                    520,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)STEP_CLEAR,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );
        TCHAR A[160];
        hEdit=CreateWindowEx(0,
                             "STATIC",
                             "",
                             WS_CHILD|WS_VISIBLE|SS_LEFT,
                             //ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,
                             300,
                             100,
                             200,
                             50,
                             hWnd,
                             (HMENU)IDC_MAIN_EDIT,
                             GetModuleHandle(NULL),
                             NULL);
        HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);
        SendMessage(hEdit,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));
        SendMessage(hEdit,
                    WM_SETTEXT,
                    0,
                    (LPARAM)"00:00:00:00:00:00");

        // Create a push button
        HWND hWndButton=CreateWindowEx(0,
                                       "BUTTON",
                                       "�ƻs�����d�d��",
                                       WS_TABSTOP|WS_VISIBLE|
                                       WS_CHILD|BS_PUSHBUTTON,
                                       300,
                                       156,
                                       200,
                                       24,
                                       hWnd,
                                       (HMENU)IDC_MAIN_BUTTON,
                                       GetModuleHandle(NULL),
                                       NULL);
        SendMessage(hWndButton,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));
        HWND MAC_Button=CreateWindowEx(0,
                                       "BUTTON",
                                       "���o�����d��",
                                       WS_TABSTOP|WS_VISIBLE|
                                       WS_CHILD|BS_PUSHBUTTON,
                                       300,
                                       36,
                                       200,
                                       24,
                                       hWnd,
                                       (HMENU)IDC_MAC_BUTTON,
                                       GetModuleHandle(NULL),
                                       NULL);
        SendMessage(MAC_Button,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));
        HWND web_Button=CreateWindowEx(0,
                                       "BUTTON",
                                       "�}�ұJ�����U����",
                                       WS_TABSTOP|WS_VISIBLE|
                                       WS_CHILD|BS_PUSHBUTTON,
                                       300,
                                       216,
                                       200,
                                       24,
                                       hWnd,
                                       (HMENU)IDC_WEB_BUTTON,
                                       GetModuleHandle(NULL),
                                       NULL);
        SendMessage(web_Button,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));
        HWND ver_Combo=CreateWindowEx(0,
                                      "COMBOBOX",
                                      "",
                                      CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
                                      300,
                                      276,
                                      200,
                                      24,
                                      hWnd,
                                      (HMENU)IDC_VER_DROP,
                                      GetModuleHandle(NULL),
                                      NULL);
        SendMessage(ver_Combo,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));
        TCHAR Planets[][30] =
        {
            TEXT("Windows XP"), TEXT("Windows Vista"), TEXT("Windows 7"), TEXT("Windows 8")
        };


        int  k = 0;

        memset(&A,0,sizeof(A));
        for (k = 0; k < 4; k += 1)
        {
            strcpy(A, Planets[k]);

            // Add string to combobox.
            SendMessage(ver_Combo,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A);
        }

        SendMessage( CreateWindowEx(0,
                                    "STATIC",
                                    "140 . 119 .                 .",
                                    WS_CHILD|WS_VISIBLE|SS_LEFT,
                                    300,
                                    340,
                                    200,
                                    100,
                                    hWnd,
                                    (HMENU)IPFIX,
                                    GetModuleHandle(NULL),
                                    NULL), WM_SETFONT, WPARAM( GetStockObject(DEFAULT_GUI_FONT) ), MAKELPARAM(FALSE,0) );

        hIPa=CreateWindowEx(0,
                            "COMBOBOX",
                            "",
                            CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
                            355,
                            336,
                            41,
                            24,
                            hWnd,
                            (HMENU)IDC_IPA,
                            GetModuleHandle(NULL),
                            NULL);
        SendMessage(hIPa,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));



        memset(&A,0,sizeof(A));
        for (int k = 0; k < 256; k += 1)
        {
            //strcpy(A, Planets[k]);
            sprintf( A, "%d", k );

            // Add string to combobox.
            SendMessage(hIPa,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A);
        }
// Send the CB_SETCURSEL message to display an initial item
//  in the selection field
//        SendMessage( ver_Combo, CB_SETCURSEL, (WPARAM)2, (LPARAM)0);

        hIPb=CreateWindowEx(0,
                            "COMBOBOX",
                            "",
                            CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL	,
                            410,
                            336,
                            41,
                            24,
                            hWnd,
                            (HMENU)IDC_IPB,
                            GetModuleHandle(NULL),
                            NULL);
        SendMessage(hIPb,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));



        memset(&A,0,sizeof(A));
        for (int k = 0; k < 256; k += 1)
        {
            //strcpy(A, Planets[k]);
            sprintf( A, "%d", k );

            // Add string to combobox.
            SendMessage(hIPb,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A);
        }

        HWND set_Button=CreateWindowEx(0,
                                       "BUTTON",
                                       "�]�w IP ��m�A�I���еy���Ƭ�",
                                       WS_TABSTOP|WS_VISIBLE|
                                       WS_CHILD|BS_PUSHBUTTON,
                                       300,
                                       396,
                                       200,
                                       24,
                                       hWnd,
                                       (HMENU)IDC_SET_BUTTON,
                                       GetModuleHandle(NULL),
                                       NULL);
        SendMessage(set_Button,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));
        HWND clear_Button=CreateWindowEx(0,
                                         "BUTTON",
                                         "�M�� IP �]�w�A�I���еy���Ƭ�",
                                         WS_TABSTOP|WS_VISIBLE|
                                         WS_CHILD|BS_PUSHBUTTON,
                                         300,
                                         516,
                                         200,
                                         24,
                                         hWnd,
                                         (HMENU)IDC_CLEAR_BUTTON,
                                         GetModuleHandle(NULL),
                                         NULL);
        SendMessage(clear_Button,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));

        HWND quit_Button=CreateWindowEx(0,
                                        "BUTTON",
                                        "���}",
                                        WS_TABSTOP|WS_VISIBLE|
                                        WS_CHILD|BS_PUSHBUTTON,
                                        300,
                                        456,
                                        200,
                                        24,
                                        hWnd,
                                        (HMENU)IDC_QUIT_BUTTON,
                                        GetModuleHandle(NULL),
                                        NULL);
        SendMessage(quit_Button,
                    WM_SETFONT,
                    (WPARAM)hfDefault,
                    MAKELPARAM(FALSE,0));
    }
    break;

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
        case IDC_VER_DROP:
        {
            int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,
                                        (WPARAM) 0, (LPARAM) 0);
            TCHAR  ListItem[256];
            SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT, (WPARAM) ItemIndex, (LPARAM) ListItem);
            if( !strcmp( ListItem, "Windows XP" ) )
                ver = 1;
            else if( !strcmp( ListItem, "Windows Vista" ) )
                ver = 2;
            else if( !strcmp( ListItem, "Windows 7" ) )
                ver = 3;
            else
                ver = 4;
            //MessageBox(hWnd, (LPCSTR) ListItem, TEXT("Item Selected"), MB_OK);
        }
        break;
        case IDC_IPA:
        {
            int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,
                                        (WPARAM) 0, (LPARAM) 0);
            TCHAR  ListItem[256];
            SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT, (WPARAM) ItemIndex, (LPARAM) ListItem);
            ipa = atoi( ListItem );//printf("%d %d\n",ipa,ipb);
            //MessageBox(hWnd, (LPCSTR) ListItem, TEXT("Item Selected"), MB_OK);
        }
        break;
        case IDC_IPB:
        {
            int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,
                                        (WPARAM) 0, (LPARAM) 0);
            TCHAR  ListItem[256];
            SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT, (WPARAM) ItemIndex, (LPARAM) ListItem);
            ipb = atoi( ListItem );//printf("%d %d\n",ipa,ipb);
            //MessageBox(hWnd, (LPCSTR) ListItem, TEXT("Item Selected"), MB_OK);
        }
        break;
        case IDC_MAIN_BUTTON:
        {
            char buffer[256];
            SendMessage(hEdit,
                        WM_GETTEXT,
                        sizeof(buffer)/sizeof(buffer[0]),
                        reinterpret_cast<LPARAM>(buffer));
			if( *buffer == 'S' )
				MessageBox( hWnd,"��p�A�ڵL�k���d���A�ХѩR�O���ܦr������J ipconfig /all �Ӭd�ݥd��","OOPS!",MB_ICONERROR );
            else if( strcmp( buffer, "00:00:00:00:00:00" ) )
            {
                const size_t len = strlen(buffer) + 1;
                HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
                memcpy(GlobalLock(hMem), buffer, len);
                GlobalUnlock(hMem);
                OpenClipboard(hEdit);
                EmptyClipboard();
                SetClipboardData(CF_TEXT, hMem);
                CloseClipboard();
                MessageBox(hWnd,"�w�ƻs��ŶKï","Copy",MB_ICONINFORMATION);
                //MessageBox(hWnd,buffer,"Copy",MB_ICONINFORMATION);
            }
            else
                MessageBox(hWnd, "�ƻs�e�Х���B�J�@���o�����d�d��","Nothing to copy...",MB_ICONWARNING);
        }
        break;
        case IDC_MAC_BUTTON:
        {
            //system( "@ipconfig /all > mac.txt" );
            SECURITY_ATTRIBUTES sa;
            sa.nLength = sizeof(sa);
            sa.lpSecurityDescriptor = NULL;
            sa.bInheritHandle = TRUE;
            HANDLE h = CreateFile("mac.txt",
                                  FILE_APPEND_DATA,
                                  FILE_SHARE_WRITE | FILE_SHARE_READ,
                                  &sa,
                                  CREATE_ALWAYS,
                                  FILE_ATTRIBUTE_NORMAL,
                                  NULL );
            STARTUPINFO si;
            ZeroMemory(&si, sizeof(si));
            si.dwFlags |= STARTF_USESTDHANDLES;
            si.hStdInput = NULL;
            si.hStdError = h;
            si.hStdOutput = h;
            si.cb = sizeof(si);

            PROCESS_INFORMATION pi;
            ZeroMemory(&pi, sizeof(pi));

            //creating new process
            //system("ipconfig /all > mac.txt");
            //printf(LPSTR("ipconfig /all > mac.txt"));
            //char Cmd[] = ;
            if( CreateProcess(NULL, LPSTR("ipconfig /all"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi) )
            {
                //waiting for process termination
                WaitForSingleObject(pi.hProcess, INFINITE);
                //cleanup
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
            }
//            else
//                MessageBox(hWnd,"DD","AA",MB_OK);
            //MessageBox(hWnd,"�w���o�����d��","Success",MB_OK);
            SetWindowText(hEdit,get_addr());
            CloseHandle(h);
            DeleteFile(LPCTSTR("mac.txt"));
            //MessageBox(hWnd,"�w���o�����d��","Success",MB_ICONINFORMATION);
//			CreateProcess(NULL, "del mac.txt", NULL, NULL, FALSE, CREATE_NO_WINDOW,
//                                         NULL, NULL, &si, &pi);
//            SendMessage(hEdit,
//                    WM_SETTEXT,
//                    NULL,
//                    (LPARAM)"1.2.3.4");
            break;
        }
        case IDC_WEB_BUTTON:
        {
            STARTUPINFO si;
            ZeroMemory(&si, sizeof(si));

            PROCESS_INFORMATION pi;
            ZeroMemory(&pi, sizeof(pi));

            //creating new process
            //system("ipconfig /all > mac.txt");
            //printf(LPSTR("ipconfig /all > mac.txt"));
            //char Cmd[] = ;

            ShellExecute(NULL, "open", "http://flow2.nccu.edu.tw/Reg/stulogin.php", NULL, NULL, SW_SHOWMAXIMIZED);
            //if( CreateProcess(NULL, LPSTR("cmd /C start http://flow2.nccu.edu.tw/Reg/stulogin.php"), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi) )
            {
                //waiting for process termination
                WaitForSingleObject(pi.hProcess, INFINITE);
                //cleanup
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
            }
//            else
//				MessageBox(NULL,"aa","bb",MB_OK);
            break;
        }
        case IDC_SET_BUTTON:
        {
            if( !ver )
            {
                MessageBox( hWnd, "�Х���B�J����� Windows ����", "Which type of Windows?", MB_ICONWARNING );
                break;
            }
            else if( ipa < 0 || ipb < 0 )
            {
                MessageBox( hWnd, "�Х���B�J������J���U�n�� IP", "No IP...", MB_ICONWARNING );
                break;
            }
            else if( ver == 2 || ver == 3 )
                set();
            else if( ver == 1 )
                setxp();
            else if( ver == 4 )
                set8();
            MessageBox(hWnd,"�]�w�����I�еy�ݾ��I��]�w�ͮĦA�}�l�W��","Done", MB_ICONINFORMATION);
        }
        break;
        case IDC_QUIT_BUTTON:
            PostQuitMessage( 0 );
            break;
        case IDC_CLEAR_BUTTON:
        {
            STARTUPINFO si;
            ZeroMemory(&si, sizeof(si));
            PROCESS_INFORMATION pi;
            ZeroMemory(&pi, sizeof(pi));
            if( !ver )
            {
                MessageBox( hWnd, "�Х���B�J����� Windows ����", "Which type of Windows?", MB_ICONWARNING );
                break;
            }
            else if( ver == 2 || ver == 3 )
            {
                CreateProcess(NULL, LPSTR("netsh interface ipv4 set address name=\"�ϰ�s�u\" source=dhcp"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
                CreateProcess(NULL, LPSTR("netsh interface ipv4 set dnsservers name=\"�ϰ�s�u\" source=dhcp"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
            }
            else if( ver == 1 )
            {
                CreateProcess(NULL, LPSTR("netsh interface ip set address \"�ϰ�s�u\" DHCP"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
                CreateProcess(NULL, LPSTR("netsh interface ip set dns \"�ϰ�s�u\" DHCP"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
            }
            else if( ver == 4 )
            {
                if( MessageBox(hWnd,"�M�� IP �e�A�Х����J�����u�A�_�h�i��L�k�M��","Did you plug in?",MB_OKCANCEL|MB_ICONWARNING) == IDCANCEL )
                    break;
                CreateProcess(NULL, LPSTR("netsh interface ipv4 set dnsservers name=\"�A�Ӻ���\" source=dhcp"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
                CreateProcess(NULL, LPSTR("netsh interface set interface name=\"�A�Ӻ���\" admin=DISABLED"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
                CreateProcess(NULL, LPSTR("netsh interface ipv4 set address name=\"�A�Ӻ���\" source=dhcp"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
                CreateProcess(NULL, LPSTR("netsh interface set interface name=\"�A�Ӻ���\" admin=ENABLED"), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
            }
            MessageBox( hWnd, "�w�M�� IP �]�w�A�p�n�A���]�w�A�ЦA���ާ@", "Cleared", MB_ICONINFORMATION );
            break;
        }
        }
        break;

    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    break;
    }

    return DefWindowProc(hWnd,msg,wParam,lParam);
}

bool all_0( char *a )
{
    for( int i = 0; i <= 16; ++i )
        if( i % 3 != 2 && a[ i ] != '0' )
            return false;
    return true;
}

const char* get_addr()
{
    static char word[ 1024 ] = { 0 };
    //system( "ipconfig /all > addr.txt" );
    FILE *file = fopen( "mac.txt", "r" );
    if( !file )
        return "bad";
search:
    //if( lang == 1 )
    while( fscanf( file, "%s", word ) != EOF && strcmp( word, "�ϰ�s�u" ) && strcmp( word, "�ϰ�s�u:" ) && strcmp( word, "�A�Ӻ���" ) && strcmp( word, "�A�Ӻ���:" ) );
    //else
    //while( fscanf( file, "%s", word ) != EOF && strcmp( word, "local" ) && strcmp( word, "local" ) && strcmp( word, "ethernet" ) && strcmp( word, "Ethernet" ) );
    while( fscanf( file, "%s", word ) != EOF && ( !( word[ 2 ] == '-' && word[ 5 ] == '-' && word[ 8 ] == '-' && word[ 11 ] == '-' && word[ 14 ] == '-' && strlen( word ) == 17 ) || all_0( word ) ) )
        if( !strcmp( word, "VPN" ) || !strcmp( word, "virtual" ) || !strcmp( word, "Virtual" ) || !strcmp( word, "Bluetooth" ) )
            goto search;
    word[ 2 ] = word[ 5 ] = word[ 8 ] = word[ 11 ] = word[ 14 ] = ':';
    //io.close();
    fclose( file );
    if( word[ 2 ] == ':' && word[ 5 ] == ':' && word[ 8 ] == ':' && word[ 11 ] == ':' && strlen( word ) == 17 )
        return word;
    //io << endl << word << endl;
    else
        return "Sorry, I couldn't find your MAC address.\nYou may use command prompt to get it.\n";//);//,"Fail",MB_ICONERROR);

//    system( "notepad mac.txt" );
//    system( "del /F mac.txt addr.txt" );
}

void set8()
{
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));
    int a = ipa, b = ipb;
    char cmd[ 1024 ];
    sprintf( cmd, "netsh interface ipv4 set address name=\"�A�Ӻ���\" source=static address=140.119.%d.%d mask=255.255.255.0 gateway=140.119.%d.254", a, b, a );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    sprintf( cmd, "netsh interface ipv4 add dnsserver name=\"�A�Ӻ���\" address=140.119.1.110 index=1" );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    sprintf( cmd, "netsh interface ipv4 add dnsserver name=\"�A�Ӻ���\" address=140.119.252.12 index=2" );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void set()
{
    int a = ipa, b = ipb;
    char cmd[ 1024 ];
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));
    sprintf( cmd, "netsh interface ipv4 set address \"�ϰ�s�u\" static 140.119.%d.%d 255.255.255.0 140.119.%d.254", a, b, a );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    sprintf( cmd, "netsh interface ipv4 set dnsservers name=\"�ϰ�s�u\" static 140.119.1.110 primary" );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    sprintf( cmd, "netsh interface ipv4 add dnsservers name=\"�ϰ�s�u\" 140.119.252.12 index=2" );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void setxp()
{
    int a = ipa, b = ipb;
    char cmd[ 1024 ];
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));
    sprintf( cmd, "netsh interface ip set address \"�ϰ�s�u\" static 140.119.%d.%d 255.255.255.0 140.119.%d.254 1", a, b, a );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    sprintf( cmd, "netsh interface ip set dns \"�ϰ�s�u\" static 140.119.1.110" );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    sprintf( cmd, "netsh interface ip add dns \"�ϰ�s�u\" 140.119.252.12" );
    CreateProcess(NULL, LPSTR(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
