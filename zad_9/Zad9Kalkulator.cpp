// standard libs
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <unordered_map>

// classes
#include "IDrawable.h"

// typedefs
typedef void(*FUNC_EVENT_HANDLER)(HWND, int); // int here is the button id

using namespace std;

// consts
const int windowWidth = 320; // px
const int windowHeight = 480; // px
const int windowPadding = 8; // px
const int buttonSpacing = 8; // px
const int buttonHeight = 56; // px

// global variables
static TCHAR szWindowClass[] = _T("Zad9Kalkulator");
static TCHAR szTitle[] = _T("Epic gamer calculator 69420");

std::unordered_map<int, FUNC_EVENT_HANDLER> clickEventHandlers;

// helper functions

HINSTANCE hInst;

// buttons
HWND btnEquals;
HWND btnPlus;

#pragma region forward declarations

// I fucking hate that this has to be a thing, fuck c++
LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam);
void RegisterClickEventHandler(int, FUNC_EVENT_HANDLER);
void DispatchClickEvent(HWND, int);
void Window_Init(HWND);
void btnEquals_Click(HWND hWnd, int btnId);

#pragma endregion

// the equivalent of main() for a windows program
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// populate this class with information about the window
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);							// size of the structure, no idea why it's done this way.
	wcex.style = CS_HREDRAW | CS_VREDRAW;						// style options for the window class.
	wcex.lpfnWndProc = WndProc;									// pointer to the wndproc function so windows can send messages to this window.
	wcex.cbClsExtra = 0;										// how many extra bytes should be allocated after this window class structure.
	wcex.cbWndExtra = 0;										// how many extra bytes should be allocated after the window instance.
	wcex.hInstance = hInstance;									// handle to the window instance containing the window procedure.
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// handle to this form's icon.
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);					// handle to this window's cursor.
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);			// handle to this window's background brush, or a colour value.
	wcex.lpszMenuName = NULL;									// application menu resource name, null terminated string. if null, the window will have no default menu.
	wcex.lpszClassName = szWindowClass;							// specifies the window class name if a string, but it can also be an atom (?)
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);	// small icon associated with the window class, if null, the system searches for a replacement or something.

	if (!RegisterClassExW(&wcex))
	{
		// registration failed for some reason
		MessageBox(NULL, _T("Could not register window"), _T("Zad9Kalkulator"), NULL);
		return 1; // return something that isn't 0 to indicate failure
	}

	// create the actual window, comments copied from microsoft docs

	HWND hWnd = CreateWindow(
		szWindowClass,						// the name of the application
		szTitle,							// the text that appears in the title bar

		// normal window with maximizing and resizing disabled
		WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME,

		CW_USEDEFAULT, CW_USEDEFAULT,		// initial position (x, y)
		windowWidth, windowHeight,			// initial size (width, height)
		NULL,								// the parent of this window
		NULL,								// no menu bar handle
		hInstance,							// the first parameter from WinMain
		NULL								// some parameter(s?) not used here so I won't bother
	);

	if (!hWnd)
	{
		// creation failed for some reason
		MessageBox(NULL, _T("Could not create window"), _T("Zad9Kalkulator"), NULL);
		return 1; // return something that isn't 0 to indicate failure
	}

	// after creating the window, we can finally show it
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // update the window immediately after it is shown, I assume this is important

	// start a message loop
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) // wait for a message
	{
		// send the message to the wndproc function
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// end the program at some point I suppose
	return (int)msg.wParam;
}

// window procedure function handling messages receieved from windows
LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR cock[] = L"cock";
	switch (message)
	{
	case WM_CREATE: // message dispatched when the window is first created

		Window_Init(hWnd);
		break;

	case WM_PAINT: // message dispatched when the window should update itself

		hdc = BeginPaint(hWnd, &ps); // start painting the window, start using device context

		// this is where controls and other stuff should be drawn
		//TextOut(hdc, 16, 16, cock, _tcslen(cock)); // draw some text in the top right corner


		EndPaint(hWnd, &ps); // end painting, stop using device context

		break;

	case WM_DESTROY: // message dispatched when the window is closed
		PostQuitMessage(0); // quit with code 0
		break;

	case WM_COMMAND:


		switch (HIWORD(wParam))
		{
		case BN_CLICKED:

			DispatchClickEvent(hWnd, LOWORD(wParam));
			break;
		}


		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

void RegisterClickEventHandler(int btnId, FUNC_EVENT_HANDLER handler)
{
	clickEventHandlers.emplace(btnId, handler);
}

void DispatchClickEvent(HWND hWnd, int btnId)
{
	auto iter = clickEventHandlers.find(btnId);			// find event handler for button id
	if (iter == clickEventHandlers.end()) return;		// no event handler found, return
	(*iter->second)(hWnd, btnId);								// call the event handler
}

HWND CreateButton(HWND hWnd, long id, int x, int y, int w, int h, const TCHAR text[])
{
	return CreateWindowExW(
		// button extended styles
		0,
		L"BUTTON",		// predefined class
		text,			// button text
		// button styles
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		x, y,			// X, Y
		w, h,			// W, H
		hWnd,			// parent window
		(HMENU)id,		// for some reason this is the way you add ids to buttons.
		hInst,
		NULL
	);
}

// handle 
void Window_Init(HWND hWnd)
{
	/*btnEquals = CreateButton(hWnd, '=', windowPadding, windowPadding, windowWidth - windowPadding * 2, buttonHeight, _T("="));
	RegisterClickEventHandler('=', &btnEquals_Click);*/

	btnPlus = CreateButton(hWnd, '+', 0, 0, windowWidth, buttonHeight, _T("+"));
	RegisterClickEventHandler('+', &btnEquals_Click);
}

void btnEquals_Click(HWND hWnd, int btnId)
{
	MessageBox(hWnd, _T("buton clic"), _T("clic"), 0);
}