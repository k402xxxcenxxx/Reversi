#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <iostream>
#include <sstream>
#include "Reversi.h"

using namespace std;

Checkerboard* myCheckerBroad;

LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

void clear() {
	COORD topLeft  = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	SetConsoleCursorPosition(console, topLeft);
}

void paint(void){
		clear();
		
		cout<<myCheckerBroad->toString()<<endl;
}

void KeyDownEvent( WPARAM wParam )
{
	//==== Tab、Enter、Ctrl... ====//
	if( wParam == VK_TAB )
	{
		cout << "Tab Down" << endl;
		myCheckerBroad->redo();
		paint();
	}

	if (wParam == 0x08)// Process a backspace.
	{
		cout << "back Down" << endl;
		myCheckerBroad->undo();
		paint();
	}

	//==== 英文字母或數字 ====//
	switch( wParam )
	{
	case  VK_LEFT:
		myCheckerBroad->cursorMove(0);
		break;
	case  VK_RIGHT:
		myCheckerBroad->cursorMove(3);
		break;
	case  VK_UP:
		myCheckerBroad->cursorMove(1);
		break;
	case  VK_DOWN:
		myCheckerBroad->cursorMove(2);
		break;

	case 0x0D://enter
		myCheckerBroad->setChess(myCheckerBroad->currentPosition[0], myCheckerBroad->currentPosition[1]);
		break;
	case 'a':
	case 'A':
		cout << "A Down" << endl;
		break;
	case 's':
		case 'S':
		cout<<"S"<<endl;
		break;
	}
}

void KeyUpEvent( WPARAM wParam )
{
	//==== Tab、Enter、Ctrl... ====//
	if( wParam == VK_TAB )
	{
		cout << "Tab Up" << endl;
	}

	//==== 英文字母或數字 ====//
	switch( wParam )
	{
	case 'a':
	case 'A':
		cout << "A Up" << endl;
		break;
	}
}

int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow )
{
	//==== 註冊視窗類別 ====//
	const wchar_t CLASS_NAME[]  = L"Sample Window Class";

	WNDCLASS wc = {};

	wc.lpfnWndProc   = WindowProc;
	wc.hInstance     = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass( &wc );

	//==== 創建視窗 ====//
	HWND hwnd = CreateWindowEx(
		0,                      // Optional window styles.
		CLASS_NAME,             // 視窗類別
		L"Reversi",				// 視窗標題
		WS_OVERLAPPEDWINDOW,    // 視窗風格
		0, 0, 500, 50,				// 視窗大小及位置
		NULL,					// Parent 視窗    
		NULL,					// 選單
		hInstance,				// Instance handle
		NULL					// Additional application data
	);

	if (hwnd == NULL)
	{
		return 0;
	}
	myCheckerBroad = new Checkerboard();

	//==== 創建 console 視窗 ====//
	AllocConsole();
	freopen( "CONOUT$", "wb", stdout );

	ShowWindow( hwnd, nCmdShow );

	//==== 執行訊息迴圈 ====//
	MSG msg = { };
	while ( GetMessage(&msg, NULL, 0, 0) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	

	return 0;
}

LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch ( uMsg )
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint( hwnd, &ps );
			FillRect( hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			EndPaint( hwnd, &ps );

			paint();
		}
		return 0;

	case WM_KEYDOWN:
		KeyDownEvent( wParam );
		InvalidateRect(hwnd, NULL, TRUE);
		UpdateWindow(hwnd);
		break;

	case WM_KEYUP:
		KeyUpEvent( wParam );
		InvalidateRect (hwnd, NULL, TRUE);
		UpdateWindow (hwnd);
		break;
	}
	return DefWindowProc( hwnd, uMsg, wParam, lParam );
}