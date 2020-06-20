

#include "framework.h"

#pragma comment(linker,"\"/manifestdependency:type='win32' name = 'Microsoft.Windows.Common-Controls' version = '6.0.0.0' processorArchitecture = '*' publicKeyToken = '6595b64144ccf1df' language = '*'\"")

#pragma warning(disable:4996)

#define MAX_LOADSTRING 100

#ifdef _DEBUG

#define FIRSTIN FALSE

#else

#define FIRSTIN TRUE

#endif

HWND hWndMain;
HINSTANCE hInst;                                // 当前实例

//Global strings

LPCTSTR title = _T("刘氏五子棋v4.1");
LPCTSTR MENUNAME[2] = { _T("MAINMENU"), _T("MAINMENU1") };
LPCTSTR pleasewait1[2] = { _T("此功能尚未开放，敬请期待！"), _T("This function has't been opened to public, so please wait!") };
LPCTSTR pleasewait2[2] = { _T("敬请期待！"), _T("Please wait!") };
LPCTSTR about = _T("名称/Name：刘氏五子棋\n版本/Edition：v4.1\n作者/Author：ClothNose Studio-Timothy Liu\n平台/Platform：Win all\nMade with Visual Studio 2019\n");
LPCTSTR abouttitle[2] = { _T("关于"), _T("About") };
LPCTSTR whatisit[2] = { _T("你猜"), _T("Guess") };
LPCTSTR whatisittitle[2] = { _T("这是什么？"), _T("What is it?") };
LPCTSTR logostr1 = _T("刘  氏  五  子  棋  ");
LPCTSTR logostr2 = _T("v4.0");
LPCTSTR logostr3 = _T("谨以此次更新为武汉加油");
LPCTSTR logostr4 = _T("Developed by ClothNose Sudio");
LPCTSTR logostr5 = _T("Timothy Liu");
LPCTSTR difficultychoose[2] = { _T("ChooseDifficulty"), _T("ChooseDifficulty1") };
LPCTSTR languagechooserestart[2] = { _T("语言已更改，请重新启动游戏"), _T("The language has been changed, please restart this game.") };
LPCTSTR languagechooserestarttitle[2] = { _T("请重新启动！"), _T("Please restart!") };
LPCTSTR start1[2] = { _T("请点击“开始”菜单开始游戏") , _T("Please click \"Begin\" to start the game.") };
LPCTSTR start2[2] = { _T("初次进入游戏请查看“帮助”"), _T("If you play this game for the first time, please read \"Help\".") };
LPCTSTR restart[2] = { _T("你确定要重新开始吗？"), _T("Do you want to restart?") };
LPCTSTR restarttitle[2] = { _T("重新开始"), _T("Restart") };
LPCTSTR pausing[2] = { _T("暂停中..."), _T("Pausing...") };
LPCTSTR pausingtitle[2] = { _T("暂停"), _T("Pause") };
LPCTSTR error[2] = { _T("游戏加载错误，请重新打开"), _T("Game-loading error! Please restart!") };
LPCTSTR errortitle[2] = { _T("错误"), _T("ERROR") };
LPCTSTR warmwarntitle[2] = { _T("温馨提示"), _T("Notice") };
LPCTSTR blackgaming[2] = { _T("现在是黑方落子："), _T("Now it's the black player's turn") };
LPCTSTR whitegaming[2] = { _T("现在是白方落子："), _T("Now it's the white player's turn") };
LPCTSTR black_win[2] = { _T("游戏结束！黑方胜！"), _T("Game over! The black player wins!") };
LPCTSTR white_win[2] = { _T("游戏结束！白方胜！"), _T("Game over! The white player wins!") };
LPCTSTR white_time_up[2] = { _T("白方时间到！黑方胜！"), _T("Time\'s up! The black player wins!") };
LPCTSTR black_time_up[2] = { _T("黑方时间到！白方胜！"), _T("Time\'s up! The white player wins!") };
LPCTSTR gameovertitle[2] = { _T("游戏结束！"), _T("Game over!") };
LPCTSTR update1 = _T("刘氏五子棋首发，控制台操作");
LPCTSTR update2 = _T("1.全新的界面，多彩的颜色\n2.方向键操作——新的操作方式，爽滑的手感，全新的体验");
LPCTSTR update3 = _T(
"1.增加了“更新内容”\n\
2.增加WASD操作，更适合双人游戏\n\
3.增加“重新开始”功能，玩完一局接着玩\n\
4.增加计时功能，思考有时间限制啦\n\
5.美丽的图标\n\
6.修复了快捷键无法使用的Bug"
);
LPCTSTR update3d1 = _T("1.重写了部分更新内容\n2.更新了图标\n3.重新布局了菜单栏\n4.细节优化");
LPCTSTR update4 = _T("v4.0重大更新！\n1.炫酷的动画，更棒的体验（需要Haettenschweiler字体）\n2.增加了对英文的支持（需要Haettenschweiler字体）\n");
LPCTSTR update4d1 = _T("完善了产品的详细信息");
LPCTSTR localhelptitle[2] = { _T("本地帮助"), _T("Local Help") };
LPCTSTR localhelp[2] = { _T("1.黑方：WASD移动，J键落子\n   白方：方向键移动，回车键落子\n2.参见第一条\n3.没了"), _T("1.The black: Press \"WASD\" to move and \"J\" to confirm\n\
   The white: Press \"↑↓←→\" to move and \"Enter\" to confirm\n2. Please read Tip 1\n3. Nothing") };
LPCTSTR fontwarn = _T("在游戏之前，请确保你的电脑安装了隶书以及Haettenschweiler字体，以保证正常的游戏体验\n\
Before playing, please make sure that you have installed the font \"隶书\" and the font \"Haettenschweiler\" to better enjoy this game.");
LPCSTR loadlanguage = "Gomoku_langue_Liu.dat";
LPCTSTR emptytimewarning[2] = { _T("时间不能为空！"), _T("The time cannot be empty!") };
LPCTSTR timeoverflow[2] = { _T("时间必须在5~999内！"), _T("The time must be between 5 and 999!")};
LPCTSTR warning[2] = { _T("警告"), _T("Warning!") };


//Global variables


BOOLEAN firstin = FIRSTIN;
SHORT language = 0; //0 for Chinese, and 1 for English.
UINT role = 0;    //0 for unstart, 1 for player1, 2 for player2
UINT test = 0;
int Windheight = 700, Windwidth = 1000;  //The height and the width of the window
LONG RadiumOfChess = 7, RadiumOfCursor = 10;
BOOLEAN first = TRUE;
COLORREF boardColor;
POINT CurrentPos = { (Timothy::NUM - 1) / 2, (Timothy::NUM - 1) / 2 };  //  The position of the cursor
BOOLEAN odd = TRUE;    //Half second
BOOLEAN Languagecundang = FALSE;
LONG secondsLeft = 0; //Time left
LONG seconds = 30;  //seconds per turn
Timothy::Judge judger;
Timothy::Board board;

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK ChslngProc(HWND hCdP, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ChsdifProc(HWND hCdP, UINT message, WPARAM wParam, LPARAM lParam);


int WINAPI _tWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPTSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    std::ifstream fin(loadlanguage, std::ios::in);
    std::ofstream fout;
    if (!fin) Languagecundang = FALSE;
    else
    {
        if (fin >> language)
            switch (language)
            {
            case 0:
            case 1:
                Languagecundang = TRUE;
                break;
            default:
                language = 0;
                Languagecundang = FALSE;
            }
        else
        {
            language = 0;
            Languagecundang = FALSE;
        }
        fin.close();
    }

    if (!MyRegisterClass(hInstance)) {
        MessageBox(NULL, _T("Register failed!"), _T("error"), NULL);
    }

    if (!InitInstance(hInstance, nCmdShow))
    {
        MessageBox(NULL, _T("Failed!"), _T("ERROR"), NULL);
        return FALSE;
    }


    MSG msg;
    HACCEL hAccel = LoadAccelerators(hInstance, _T("MAINMENU"));
    
    while (GetMessage(&msg, nullptr, 0, 0))
        if (!TranslateAccelerator(hWndMain, hAccel, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

    return (int)msg.wParam;
}




ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    
    boardColor = RGB(249, 187, 83);

    wcex.cbSize = sizeof(WNDCLASSEX);
    
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    //wcex.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(MAINICON));
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MAINICON));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = CreateSolidBrush(boardColor);
    wcex.lpszMenuName = MENUNAME[language];
    wcex.lpszClassName = _T("WindowClass");
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(SMALLICON));

    return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; 

    HWND hWnd = CreateWindow(_T("WindowClass"), title, WS_VISIBLE | WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        0, 0, 1000, 700, nullptr, nullptr, hInstance, nullptr);
    
    if (!hWnd)
    {
        return FALSE;
    }

    hWndMain = hWnd;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        MessageBox(hWnd, fontwarn, warmwarntitle[language], MB_OK);
        if (!Languagecundang)
        {
            switch (DialogBox(hInst, _T("ChooseLanguage"), hWnd, ChslngProc))
            {
            case IDB_CHINESE:
                language = 0;
                break;
            case IDB_ENGLISH:
                language = 1;
                break;
            default:
                language = 0;
            }
            std::ofstream fout;
            fout.open(loadlanguage, std::ios::out);
            fout << language;
            fout.close();
            if (language == 1)
            {
                MessageBox(hWnd, languagechooserestart[1], languagechooserestarttitle[1], MB_OK);
                PostQuitMessage(0);
            }
        }
    }
    break;
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDM_START:
        {
            HMENU hMenu = GetMenu(hWnd);
            switch (DialogBox(hInst, difficultychoose[language], hWnd, ChsdifProc))
            {
            case IDB_PRIMARY:
                seconds = 60;
                break;
            case IDB_MODEST:
                seconds = 30;
                break;
            case IDB_SENIOR:
                seconds = 15;
                break;
            case IDB_SELF:
                break;
            case 0:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
            role = 1;
            first = FALSE;
            EnableMenuItem(hMenu, IDM_START, MF_BYCOMMAND | MF_GRAYED);
            EnableMenuItem(hMenu, IDM_RESTART, MF_BYCOMMAND | MF_ENABLED);
            EnableMenuItem(hMenu, IDM_PAUSE, MF_BYCOMMAND | MF_ENABLED);
            MoveWindow(hWnd, 0, 0, (Timothy::NUM + 1) * 30 + 20, (Timothy::NUM + 3) * 30 + 30, TRUE);
            if (!SetTimer(hWnd, 1000, 500, NULL))
            {
                MessageBox(hWnd, error[language], errortitle[language], MB_ICONERROR);
                SendMessage(hWnd, WM_DESTROY, 0, 0);
            }
            secondsLeft = seconds;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
        case IDM_RESTART: 
        {
            KillTimer(hWnd, 1000);
            switch (MessageBox(hWnd, restart[language], restarttitle[language], MB_YESNO | MB_ICONQUESTION))
            {
            case IDYES:
            {
                HMENU hMenu = GetMenu(hWnd);
                switch (DialogBox(hInst, difficultychoose[language], hWnd, ChsdifProc))
                {
                case IDB_PRIMARY:
                    seconds = 60;
                    break;
                case IDB_MODEST:
                    seconds = 30;
                    break;
                case IDB_SENIOR:
                    seconds = 15;
                    break;
                case IDB_SELF:
                    break;
                case 0:
                    return DefWindowProc(hWnd, message, wParam, lParam);
                }
                role = 1;
                CurrentPos.x = CurrentPos.y = (Timothy::NUM - 1) / 2;
                board.resetBlank();
                judger.resetResult();
                odd = TRUE;
                secondsLeft = seconds;
                EnableMenuItem(hMenu, IDM_PAUSE, MF_BYCOMMAND | MF_ENABLED);
                if (!SetTimer(hWnd, 1000, 500, NULL))
                {
                    MessageBox(hWnd, error[language], errortitle[language], MB_ICONERROR);
                    SendMessage(hWnd, WM_DESTROY, 0, 0);
                }
                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
            default:
            {
                if (!SetTimer(hWnd, 1000, 500, NULL))
                {
                    MessageBox(hWnd, error[language], errortitle[language], MB_ICONERROR);
                    SendMessage(hWnd, WM_DESTROY, 0, 0);
                }
                break;
            }
            }
        }
        break;
        case IDM_PAUSE:
        {
            KillTimer(hWnd, 1000);
            MessageBox(hWnd, pausing[language], pausingtitle[language], MB_OK);
            if (!SetTimer(hWnd, 1000, 500, NULL))
            {
                MessageBox(hWnd, error[language], errortitle[language], MB_ICONERROR);
                SendMessage(hWnd, WM_DESTROY, 0, 0);
            }
        }
        break;
        case IDM_LOCALHELP:
            MessageBox(hWnd, localhelp[language], localhelptitle[language], MB_OK);
        break;
        case IDM_ONLINEHELP:
            MessageBox(hWnd, pleasewait1[language], pleasewait2[language], MB_OK);
        break;
        case IDM_UPDATE1:
        {
            MessageBox(hWnd, update1, _T("v1.0更新内容"), MB_OK);
        }
        break;
        case IDM_UPDATE2:
        {
            MessageBox(hWnd, update2, _T("v2.0更新内容"), MB_OK);
        }
        break;
        case IDM_UPDATE3:
        {
            MessageBox(hWnd, update3, _T("v3.0更新内容"), MB_OK);
        }
        break;
        case IDM_UPDATE3d1:
        {
            MessageBox(hWnd, update3d1, _T("v3.1更新内容"), MB_OK);
        }
        break;
        case IDM_UPDATE4:
        {
            MessageBox(hWnd, update4, _T("v4.0更新内容"), MB_OK);
        }
        break;
        case IDM_UPDATE4d1:
        {
            MessageBox(hWnd, update4d1, _T("v4.1更新内容"), MB_OK);
        }
        break;
        case IDM_SETTINGS:
        {
            switch (DialogBox(hInst, _T("ChooseLanguage"), hWnd, ChslngProc))
            {
            case IDB_CHINESE:
                language = 0;
                break;
            case IDB_ENGLISH:
                language = 1;
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
            std::ofstream fout;
            fout.open(loadlanguage, std::ios::out);
            fout << language;
            fout.close();
            MessageBox(hWnd, languagechooserestart[language], languagechooserestarttitle[language], MB_OK);
            PostQuitMessage(0);
        }
        break;
        case IDM_ABOUT:
            MessageBox(hWnd, about, abouttitle[language], MB_OK);
        break;
        case IDM_WHAT:
            MessageBox(hWnd, whatisit[language], whatisittitle[language], MB_OK);
        break;
        case IDM_EXIT:
            SendMessage(hWnd, WM_DESTROY, 0, 0);
        break;
        }
    }
    break;
    case WM_PAINT:
    {        
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        if (firstin)
        {
            HBRUSH hb = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH hbold = (HBRUSH)SelectObject(hdc, hb);
            RECT rc;
            GetClientRect(hWnd, &rc);
            Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
            SelectObject(hdc, hbold);
            DeleteObject(hb);
            HFONT hf1 = CreateFont
            (
                50,
                0,
                0,
                0,
                FW_HEAVY,
                0,
                0,
                0,
                GB2312_CHARSET,
                OUT_DEFAULT_PRECIS,
                CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY,
                DEFAULT_PITCH,
                _T("隶书")
            );
            HFONT hf2 = CreateFont
            (
                40,
                0,
                0,
                0,
                FW_HEAVY,
                0,
                0,
                0,
                ANSI_CHARSET,
                OUT_DEFAULT_PRECIS,
                CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY,
                DEFAULT_PITCH,
                _T("Haettenschweiler")
            );
            HFONT hfold = (HFONT)SelectObject(hdc, hf1);
            TEXTMETRIC tm;
            int len1 = _tcslen(logostr1);
            for (int i = 0; i < 256; i += 8)
            {
                if (i == 8) Sleep(800);
                SetTextColor(hdc, RGB(i, i, i));
                SetBkColor(hdc, RGB(255, 0, 0));
                SelectObject(hdc, hf1);
                TextOut(hdc,190, 50, logostr1, len1);
                GetTextMetrics(hdc, &tm);
                TextOut(hdc, tm.tmAveCharWidth * (5 * 2 + len1 - 5) + 190, 50, logostr2, _tcslen(logostr2));
                TextOut(hdc, 220, 120, logostr3, _tcslen(logostr3));
                SelectObject(hdc, hf2);
                TextOut(hdc, 320, 450, logostr4, _tcslen(logostr4));
                TextOut(hdc, 430, 500, logostr5, _tcslen(logostr5));
                HPEN hp = CreatePen(PS_SOLID, 5, RGB(i, i, i));
                HPEN hpold = (HPEN)SelectObject(hdc, hp);
                int r = 100;
                SetWindowOrgEx(hdc, -Windwidth / 2, -Windheight / 2 + 30, NULL);
                Ellipse(hdc, - r, - r, r, r);
                Arc(hdc, - 0.707 * r - 0.383 * r, (0.707 * r) - 0.383 * r, - 0.707 * r + 0.383 * r, (0.707 * r) + 0.383 * r, - 0.383 * r, 0.924 * r, - 0.924 * r, (0.383 * r));
                Arc(hdc, 0.707 * r - 0.383 * r, (0.707 * r) - 0.383 * r, 0.707 * r + 0.383 * r, (0.707 * r) + 0.383 * r, 0.924 * r, 0.383 * r, 0.383 * r, (0.924 * r));
                Arc(hdc, - 2.613 * r, 2.414 * r - 2.613 * r, 2.613 * r, 2.414 * r + 2.613 * r, r, 0,  - r, 0);
                OffsetWindowOrgEx(hdc, Windwidth / 2, Windheight / 2 - 30, NULL);
                SelectObject(hdc, hpold);
                DeleteObject(hp);
                Sleep(90);
            }
            Sleep(800);
            SelectObject(hdc, hfold);
            DeleteObject(hf2);
            DeleteObject(hf1);
            firstin = FALSE;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        else
        {
            if (role)
            {
                HFONT hf = NULL;
                INT len = _tcslen(blackgaming[language]);
                switch (language)
                {
                default:
                case 0:
                    hf = CreateFont
                    (
                        ((Timothy::NUM + 1) * 30 + 20) * 0.6 / (len + 1),
                        0,
                        0,
                        0,
                        FW_HEAVY,
                        0,
                        0,
                        0,
                        GB2312_CHARSET,
                        OUT_DEFAULT_PRECIS,
                        CLIP_DEFAULT_PRECIS,
                        DEFAULT_QUALITY,
                        DEFAULT_PITCH,
                        _T("隶书")
                    );
                    break;
                case 1:
                    hf = CreateFont
                    (
                        ((Timothy::NUM + 1) * 30 + 20) * 0.6 / (len + 1) * 3,
                        0,
                        0,
                        0,
                        FW_HEAVY,
                        0,
                        0,
                        0,
                        ANSI_CHARSET,
                        OUT_DEFAULT_PRECIS,
                        CLIP_DEFAULT_PRECIS,
                        DEFAULT_QUALITY,
                        DEFAULT_PITCH,
                        _T("Haettenschweiler")
                    );
                    break;
                }
                HFONT hfold = (HFONT)SelectObject(hdc, hf);
                SetBkColor(hdc, boardColor);
                TCHAR Role[50];
                _tcscpy(Role, blackgaming[language]);
                if (role == 2) _tcscpy(Role, whitegaming[language]);
                TextOut(hdc, ((Timothy::NUM + 1) * 30 + 20) * 0.17, 10, Role, len);
                TEXTMETRIC tm;
                GetTextMetrics(hdc, &tm);
                TCHAR sec[5];
                _itot(secondsLeft, sec, 10);
                LONG numOfChars[2] = { 15, len };
                TextOut(hdc, ((Timothy::NUM + 1) * 30 + 20) * 0.17 + tm.tmAveCharWidth * numOfChars[language], 10, sec, _tcslen(sec));
                SelectObject(hdc, hfold);
                DeleteObject(hf);
                SetWindowOrgEx(hdc, -30, -60, NULL);
                HPEN hp = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
                HPEN hpold = (HPEN)SelectObject(hdc, hp);

                //绘制网格线

                for (int i = 0; i < Timothy::NUM; ++i)
                {
                    MoveToEx(hdc, 0, i * 30, NULL);
                    LineTo(hdc, (Timothy::NUM - 1) * 30, i * 30);
                    MoveToEx(hdc, i * 30, 0, NULL);
                    LineTo(hdc, i * 30, (Timothy::NUM - 1) * 30);
                }
                HBRUSH hb1 = CreateSolidBrush(RGB(0, 0, 0));        //black brush
                HBRUSH hb2 = CreateSolidBrush(RGB(255, 255, 255));  //write brush
                HBRUSH hbold = (HBRUSH)SelectObject(hdc, hb1);

                //绘制棋子

                for (int i = 0; i < Timothy::NUM; ++i)      //board y
                    for (int j = 0; j < Timothy::NUM; ++j)      //board x
                    {
                        if (board.Blank(i, j) == 1)
                        {
                            SelectObject(hdc, hb1);
                            Ellipse(hdc, j * 30 - RadiumOfChess, i * 30 - RadiumOfChess, j * 30 + RadiumOfChess, i * 30 + RadiumOfChess);
                        }
                        if (board.Blank(i, j) == 2)
                        {
                            SelectObject(hdc, hb2);
                            Ellipse(hdc, j * 30 - RadiumOfChess, i * 30 - RadiumOfChess, j * 30 + RadiumOfChess, i * 30 + RadiumOfChess);
                        }
                    }
                SelectObject(hdc, hbold);
                DeleteObject(hb2);
                DeleteObject(hb1);
                SelectObject(hdc, hpold);
                DeleteObject(hp);

                //绘制当前光标

                hp = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));
                hb1 = (HBRUSH)GetStockObject(NULL_BRUSH);
                SelectObject(hdc, hp);
                SelectObject(hdc, hb1);
                if (odd)
                    Rectangle(hdc, CurrentPos.y * 30 - RadiumOfCursor, CurrentPos.x * 30 - RadiumOfCursor, CurrentPos.y * 30 + RadiumOfCursor, CurrentPos.x * 30 + RadiumOfCursor);
                SelectObject(hdc, hbold);
                SelectObject(hdc, hpold);
                DeleteObject(hp);
            }
            else if (first)
            {
                HFONT hf = NULL;
                switch (language)
                {
                case 0:
                    hf = CreateFont
                    (
                        50,
                        0,
                        0,
                        0,
                        FW_HEAVY,
                        0,
                        0,
                        0,
                        GB2312_CHARSET,
                        OUT_DEFAULT_PRECIS,
                        CLIP_DEFAULT_PRECIS,
                        DEFAULT_QUALITY,
                        DEFAULT_PITCH,
                        _T("隶书")
                    );
                    break;
                case 1:
                    hf = CreateFont
                    (
                        50,
                        0,
                        0,
                        0,
                        FW_HEAVY,
                        0,
                        0,
                        0,
                        ANSI_CHARSET,
                        OUT_DEFAULT_PRECIS,
                        CLIP_DEFAULT_PRECIS,
                        DEFAULT_QUALITY,
                        DEFAULT_PITCH,
                        _T("Haettenschweiler")
                    );
                    break;
                default:
                    hf = CreateFont
                    (
                        50,
                        0,
                        0,
                        0,
                        FW_HEAVY,
                        0,
                        0,
                        0,
                        GB2312_CHARSET,
                        OUT_DEFAULT_PRECIS,
                        CLIP_DEFAULT_PRECIS,
                        DEFAULT_QUALITY,
                        DEFAULT_PITCH,
                        _T("隶书")
                    );
                }
                
                HFONT hfold = (HFONT)SelectObject(hdc, hf);
                SetBkColor(hdc, boardColor);
                TextOut(hdc, 50, 50, (LPCTSTR)start1[language], _tcslen((LPCTSTR)start1[language]));
                TEXTMETRIC tm;
                GetTextMetrics(hdc, &tm);
                TextOut(hdc, 50, 50 + tm.tmHeight + tm.tmExternalLeading, (LPCTSTR)start2[language], _tcslen(start2[language]));
                SelectObject(hdc, hfold);
                DeleteObject(hf);
            }
        }
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_TIMER:
    {
        switch (wParam)
        {
        case 1000:
        {
            odd = !odd;
            if (odd) --secondsLeft;
            if (secondsLeft == 0)
            {
                KillTimer(hWnd, 1000);
                odd = TRUE;
                HMENU hMenu = GetMenu(hWnd);
                EnableMenuItem(hMenu, IDM_PAUSE, MF_GRAYED);
                InvalidateRect(hWnd, NULL, role);
                if(role == 2) MessageBox(hWnd,white_time_up[language], gameovertitle[language], MB_OK);
                else if(role == 1) MessageBox(hWnd, black_time_up[language], gameovertitle[language], MB_OK);
                role = 0;
            }
            InvalidateRect(hWnd, NULL, role);
        }
        }
    }
    break;
    case WM_KEYDOWN:
    {
        if (!role) break;
        switch (wParam)
        {
        case 'W':
            if (role == 2) break;
            if (CurrentPos.x > 0) --CurrentPos.x;
            InvalidateRect(hWnd, NULL, role);
            break;
        case VK_UP:
            if (role == 1) break;
            if (CurrentPos.x > 0) --CurrentPos.x;
            InvalidateRect(hWnd, NULL, role);
            break;
        case 'S':
            if (role == 2) break;
            if (CurrentPos.x < Timothy::NUM - 1) ++CurrentPos.x;
            InvalidateRect(hWnd, NULL, role);
            break;
        case VK_DOWN:
            if (role == 1) break;
            if (CurrentPos.x < Timothy::NUM - 1) ++CurrentPos.x;
            InvalidateRect(hWnd, NULL, role);
            break;
        case 'A':
            if (role == 2) break;
            if (CurrentPos.y > 0) --CurrentPos.y;
            InvalidateRect(hWnd, NULL, role);
            break;
        case VK_LEFT:
            if (role == 1) break;
            if (CurrentPos.y > 0) --CurrentPos.y;
            InvalidateRect(hWnd, NULL, role);
            break;
        case 'D':
            if (role == 2) break;
            if (CurrentPos.y < Timothy::NUM - 1) ++CurrentPos.y;
            InvalidateRect(hWnd, NULL, role);
        case VK_RIGHT:
            if (role == 1) break;
            if (CurrentPos.y < Timothy::NUM - 1) ++CurrentPos.y;
            InvalidateRect(hWnd, NULL, role);
            break;
        case 'J':
        {
            if (role == 2) break;
            if (board.act(CurrentPos.x, CurrentPos.y, role))
            {
                InvalidateRect(hWnd, NULL, role);
                if (judger.JudgeIfOver(CurrentPos.x, CurrentPos.y, role, &board))
                {
                    KillTimer(hWnd, 1000);
                    odd = TRUE;
                    MessageBox(hWnd, black_win[language], gameovertitle[language], MB_OK);
                    HMENU hMenu = GetMenu(hWnd);
                    EnableMenuItem(hMenu, IDM_PAUSE, MF_GRAYED);
                    role = 0;
                }
                else
                {
                    role = 3 - role;
                    secondsLeft = seconds;
                    KillTimer(hWnd, 1000);
                    if (!SetTimer(hWnd, 1000, 500, NULL))
                    {
                        MessageBox(hWnd, error[language], errortitle[language], MB_ICONERROR);
                        SendMessage(hWnd, WM_DESTROY, 0, 0);
                    }
                    odd = TRUE;
                }
            }
        };
        break;
        case VK_RETURN:
        {
            if (role == 1) break;
            if (board.act(CurrentPos.x, CurrentPos.y, role))
            {
                InvalidateRect(hWnd, NULL, role);
                if (judger.JudgeIfOver(CurrentPos.x, CurrentPos.y, role, &board))
                {
                    KillTimer(hWnd, 1000);
                    odd = TRUE;
                    MessageBox(hWnd, white_win[language], gameovertitle[language], MB_OK);
                    HMENU hMenu = GetMenu(hWnd);
                    EnableMenuItem(hMenu, IDM_PAUSE, MF_GRAYED);
                    role = 0;
                }
                else
                {
                    role = 3 - role;
                    secondsLeft = seconds;
                    KillTimer(hWnd, 1000);
                    if (!SetTimer(hWnd, 1000, 500, NULL))
                    {
                        MessageBox(hWnd, error[language], errortitle[language], MB_ICONERROR);
                        SendMessage(hWnd, WM_DESTROY, 0, 0);
                    }
                    odd = TRUE;
                }
            }
        }
        break;
        }
    }
    break;
    case WM_DESTROY:
        KillTimer(hWnd, 1000);
        role = 0;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

BOOL CALLBACK ChsdifProc(HWND hCdP, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        SendMessage(GetDlgItem(hCdP, IDC_SELFEDIT), EM_SETLIMITTEXT, 3, 0);
        break;
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDB_MODEST:
        case IDB_PRIMARY:
        case IDB_SENIOR:
            if(HIWORD(wParam) == BN_CLICKED)
                EndDialog(hCdP, LOWORD(wParam)); 
            break;
        case IDB_SELF:
        {
            TCHAR timebuf[4];
            GetDlgItemText(hCdP, IDC_SELFEDIT, timebuf, 4);
            if (timebuf[0] == '\0') MessageBox(hCdP, emptytimewarning[language], warning[language], MB_OK | MB_ICONWARNING);
            else
            {
                int time = _ttoi(timebuf);
                if (time < 5 || time > 999) MessageBox(hCdP, timeoverflow[language], warning[language], MB_OK | MB_ICONWARNING);
                else { seconds = time; EndDialog(hCdP, LOWORD(wParam)); }
            }
            break;
        }
        }
    }
    break;
    case WM_CLOSE:
    {
        EndDialog(hCdP, 0);
    }
    break;
    }
    return 0;
}

BOOL CALLBACK ChslngProc(HWND hCdP, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDB_CHINESE:
        case IDB_ENGLISH:
            EndDialog(hCdP, LOWORD(wParam));
            break;
        }
    }
    break;
    case WM_CLOSE:
    {
        EndDialog(hCdP, 0);
    }
    break;
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
