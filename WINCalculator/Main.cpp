#include <Windows.h>
#include <string>
#include "Definitions.h"
#include "Setting.h"

/*
,--.   ,--. ,--. ,--.  ,--.  ,-----.          ,--.                 ,--.            ,--.
|  |   |  | |  | |  ,'.|  | '  .--./  ,--,--. |  |  ,---. ,--.,--. |  |  ,--,--. ,-'  '-.  ,---.  ,--.--.
|  |.'.|  | |  | |  |' '  | |  |     ' ,-.  | |  | | .--' |  ||  | |  | ' ,-.  | '-.  .-' | .-. | |  .--'
|   ,'.   | |  | |  | `   | '  '--'\ \ '-'  | |  | \ `--. '  ''  ' |  | \ '-'  |   |  |   ' '-' ' |  |
'--'   '--' `--' `--'  `--'  `-----'  `--`--' `--'  `---'  `----'  `--'  `--`--'   `--'    `---'  `--'
*/


int WINAPI WinMain(
	HINSTANCE hInst,
	HINSTANCE hPrevInst,
	LPSTR argd,
	int ncmdshow)
{

	WNDCLASS MainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_APPLICATION),
		kProgramName, MainProcedure);

	if (!RegisterClassW(&MainClass)) {
		return ERORR;
	}

	MSG MainMessage = { 0 };

	CreateWindow(kProgramName, kProgramName, (WS_OVERLAPPEDWINDOW | WS_VISIBLE), 100, 100,
		kWindowWidth, kWindowHeight, NULL, NULL, hInst /*hInst*/, NULL);

	while (GetMessage(&MainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&MainMessage);
		DispatchMessage(&MainMessage);
	}
	return 0;
}

WNDCLASS NewWindowClass(HBRUSH bgColor, HCURSOR cursor, HINSTANCE hInst, HICON icon, LPCWSTR name, WNDPROC procedure) {

	WNDCLASS NWC = { 0 };

	NWC.hIcon = icon;
	NWC.hCursor = cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = name;
	NWC.hbrBackground = bgColor;
	NWC.lpfnWndProc = procedure;

	return NWC;
}

LRESULT CALLBACK MainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	GetCursorPos(&mouse);	
	switch (msg)
	{
	case WM_CREATE:
		MainWindowAddWidgets(hWnd);
		break;
	case WM_COMMAND:
		switch (wp)
		{
		case ON_CLICK_BUTTON_1:
			
			SetWindowTextA(TextBox1,(LPCSTR)mouse.x);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
		break;
	}
}

void MainWindowAddWidgets(HWND hWnd) {


	TextBox1  = CreateWindowA("edit", "", BINDING_STYLE | ES_RIGHT, 5, 5, kWindowWidth-25, 100, hWnd, NULL, NULL, NULL); // BUTTON
	GenerickButtons(hWnd,5,100,75,50,2);
}

void GenerickButtons(HWND hWnd, int x0, int y0, int width, int height, int padding) {
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++)
		{
			int x = x0 + padding + ((width + padding) * i);
			int y = y0 + padding + ((height + padding) * j);
			buttons[i][j] = CreateWindowA("button", charButton[counter], BINDING_STYLE | ES_CENTER, x, y, width, height, hWnd, (HMENU)ON_CLICK_BUTTON_1, NULL, NULL); // BUTTON
			counter++;
		}
	}
}
//int GetButtonId(long mouse, int x0, int y0, int width, int height, int padding) {
//
//	int mous = mouse;
//	int countInerationToZero = 0;
//
//	for (unsigned i = 0; i < NUMBER_OF_BUTTON; i++) {
//		if (mous / (size + padding) != 0) {
//			countInerationToZero++;
//		}
//	}
//	return countInerationToZero;
//	
//}