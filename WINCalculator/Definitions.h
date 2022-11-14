#pragma once

#define BINDING_STYLE		WS_VISIBLE | WS_CHILD  
#define ERORR				-1

#define ON_CLICK_BUTTON_1   1

#define NUMBER_OF_BUTTON_X	4
#define NUMBER_OF_BUTTON_Y	6
#define NUMBER_OF_BUTTON	(NUMBER_OF_BUTTON_Y * NUMBER_OF_BUTTON_X)



LPCSTR charButton[24] = {"%",  "#", "7", "4", "1", "-", 
						 "CE", "^", "8", "5", "2", "0", 
						 "C",  "S", "9", "6", "3", ",",
						 "<",  "/", "*", "-", "+", "="};
HWND buttons[NUMBER_OF_BUTTON_X][NUMBER_OF_BUTTON_Y];

HWND TextBox1;

LPCSTR Buffer;

POINT mouse;

LRESULT CALLBACK MainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
void GenerickButtons(HWND hWnd, int x0, int y0, int width, int height, int padding);
int GetButtonId(long mouse, int size, int padding);
void MainWindowAddWidgets(HWND hWnd);