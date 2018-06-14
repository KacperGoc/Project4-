// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <cstdio>
#include <fstream>
#include <cmath>

#define MAX_LOADSTRING 100
#define TMR_1 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
int Lenght1 = 150;
int Lenght2 = 100;
int N = 1;
int n = 0;
int value = N;
double pi = 3.1415926535897;
double T = 0;
double A = 0;
double Delay = 0.05;
double AX1 = 220, AY1 = 380;
double AX2 = 290, AY2 = 380;
double AX3 = 340, AY3 = 380;
double AX4 = 490, AY4 = 380;
double AX5 = 560, AY5 = 380;
double AX6 = 600, AY6 = 380;
int Angle1 = 0;
int Angle2 = 0;
int Angle1_saved = 0;
int Angle2_saved= 0;
int range = 18;
bool Hold = false;
bool HoldBox1 = false;
bool HoldBox2 = false;
bool HoldBox3 = false;
bool HoldBox4 = false;
bool HoldBox5 = false;
bool HoldBox6 = false;
bool repaint=true;
bool animation = false;
Point Box1(220, 380);
Point Box2(290, 380);
Point Box3(340, 380);
Point Box4(490, 380);
Point Box5(560, 380);
Point Box6(600, 380);
// buttons
HWND hwndButton;

// sent data
RECT drawArea1 = { 0, 101, 1500, 500 };
RECT drawArea2 = { 750, 0, 1200, 100};

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen2(Color(255, 0, 255, 0));
	Pen pen3(Color(255, 255, 0, 0));
	Pen pen4(Color(0, 0, 0, 0));

	if (animation) {
		//Arm1
		if ((Angle1 + T) == Angle1_saved) {
			Point first1(400, 400);
			Point second1(cos(Angle1*pi / range) * Lenght1, sin(Angle1*pi / range) * Lenght1);
			graphics.DrawLine(&pen, first1.X, first1.Y, 400 + second1.X, 400 - second1.Y);
		}
		if ((Angle1 + T) > Angle1_saved) {
			Point first1(400, 400);
			Point second1(cos((T + Angle1)*pi / range) * Lenght1, sin((T + Angle1)*pi / range) * Lenght1);
			graphics.DrawLine(&pen, first1.X, first1.Y, 400 + second1.X, 400 - second1.Y);
			T = T - Delay;
		}
		if ((Angle1 + T) < Angle1_saved) {
			Point first1(400, 400);
			Point second1(cos((T + Angle1)*pi / range) * Lenght1, sin((T + Angle1)*pi / range) * Lenght1);
			graphics.DrawLine(&pen, first1.X, first1.Y, 400 + second1.X, 400 - second1.Y);
			T = T + Delay;
		}

		//Arm2
		if ((Angle2 + A) == Angle2_saved) {
			Point first2(cos((T + Angle1)*pi / range) * Lenght1, sin((T + Angle1)*pi / range) * Lenght1); //same as second1
			Point second2(cos((Angle1 + Angle2 + T)*pi / range) * Lenght2, sin((Angle1 + Angle2 + T)*pi / range) * Lenght2);
			graphics.DrawLine(&pen, 400 + first2.X, 400 - first2.Y, 400 + first2.X + second2.X, 400 - first2.Y - second2.Y);

		}
		if ((Angle2 + A) > Angle2_saved) {
			Point first2(cos((T + Angle1)*pi / range) * Lenght1, sin((T + Angle1)*pi / range) * Lenght1); //same as second1
			Point second2(cos((Angle1 + Angle2 + A + T)*pi / range) * Lenght2, sin((Angle1 + Angle2 + A + T)*pi / range) * Lenght2);
			graphics.DrawLine(&pen, 400 + first2.X, 400 - first2.Y, 400 + first2.X + second2.X, 400 - first2.Y - second2.Y);
			A = A - Delay;
		}
		if ((Angle2 + A) < Angle2_saved) {
			Point first2(cos((T + Angle1)*pi / range) * Lenght1, sin((T + Angle1)*pi / range) * Lenght1); //same as second1
			Point second2(cos((Angle1 + Angle2 + A + T)*pi / range) * Lenght2, sin((Angle1 + Angle2 + A + T)*pi / range) * Lenght2);
			graphics.DrawLine(&pen, 400 + first2.X, 400 - first2.Y, 400 + first2.X + second2.X, 400 - first2.Y - second2.Y);
			A = A + Delay;

		}
		Point Box1(220, 380);
		graphics.DrawRectangle(&pen2, Box1.X, Box1.Y, 20, 20);
		Point Box2(290, 380);
		graphics.DrawRectangle(&pen2, Box2.X, Box2.Y, 20, 20);
		Point Box3(340, 380);
		graphics.DrawRectangle(&pen2, Box3.X, Box3.Y, 20, 20);
		Point Box4(490, 380);
		graphics.DrawRectangle(&pen2, Box4.X, Box4.Y, 20, 20);
		Point Box5(560, 380);
		graphics.DrawRectangle(&pen2, Box5.X, Box5.Y, 20, 20);
		Point Box6(600, 380);
		graphics.DrawRectangle(&pen2, Box6.X, Box6.Y, 20, 20);

	}
	else
	{
		Angle1 = Angle1 + T;
		T = 0;
		Angle2 = Angle2 + A;
		A = 0;
		Point first1(400, 400);
		Point second1(cos(Angle1*pi / range) * Lenght1 + 400, 400 - sin(Angle1*pi / range) * Lenght1);
		graphics.DrawLine(&pen, first1.X, first1.Y, second1.X, second1.Y);
		Point first2(cos(Angle1*pi / range) * Lenght1 + 400, 400 - sin(Angle1*pi / range) * Lenght1); //same as second1
		Point second2(cos((Angle1 + Angle2)*pi / range) * Lenght2, sin((Angle1 + Angle2)*pi / range) * Lenght2);
		graphics.DrawLine(&pen, first2.X, first2.Y, first2.X + second2.X, first2.Y - second2.Y);
	}
		if (Hold) {
			if (HoldBox1) {
				Point Box1(first2.X + second2.X - 10, first2.Y - second2.Y - 10);
				graphics.DrawRectangle(&pen3, Box1.X, Box1.Y, 20, 20);
				if (Box1.X < Box2.X + 20 && Box1.X > Box2.X - 20 || Box1.X < Box3.X + 20 && Box1.X > Box3.X - 20 || Box1.X < Box4.X + 20 && Box1.X > Box4.X - 20 || Box1.X < Box5.X + 20 && Box1.X > Box5.X - 20 || Box1.X < Box6.X + 20 && Box1.X > Box6.X - 20) {
					AX1 = first2.X + second2.X - 10;
					AY1 = 380 - 20 * n;
				}
				else {
					AX1 = first2.X + second2.X - 10;
					AY1 = 380;
				}
			}
			else {
				graphics.DrawRectangle(&pen2, AX1, AY1, 20, 20);
			}
			if (HoldBox2) {
				Point Box2(first2.X + second2.X - 10, first2.Y - second2.Y - 10);
				graphics.DrawRectangle(&pen3, Box2.X, Box2.Y, 20, 20);
				if (Box2.X < Box1.X + 20 && Box2.X > Box1.X - 20 || Box2.X < Box3.X + 20 && Box2.X > Box3.X - 20 || Box2.X < Box4.X + 20 && Box2.X > Box4.X - 20 || Box2.X < Box5.X + 20 && Box2.X > Box5.X - 20 || Box2.X < Box6.X + 20 && Box2.X > Box6.X - 20) {
					AX2 = first2.X + second2.X - 10;
					AY2 = 380 - 20 * n;
				}
				else {
					AX2 = first2.X + second2.X - 10;
					AY2 = 380;
				}
			}
			else {
				graphics.DrawRectangle(&pen2, AX2, AY2, 20, 20);
			}
			if (HoldBox3) {
				Point Box3(first2.X + second2.X - 10, first2.Y - second2.Y - 10);
				graphics.DrawRectangle(&pen3, Box3.X, Box3.Y, 20, 20);
				if (Box3.X < Box2.X + 20 && Box3.X > Box2.X - 20 || Box3.X < Box1.X + 20 && Box3.X > Box1.X - 20 || Box3.X < Box4.X + 20 && Box3.X > Box4.X - 20 || Box3.X < Box5.X + 20 && Box3.X > Box5.X - 20 || Box3.X < Box6.X + 20 && Box3.X > Box6.X - 20) {
					AX3 = first2.X + second2.X - 10;
					AY3 = 380 - 20 * n;
				}
				else {
					AX3 = first2.X + second2.X - 10;
					AY3 = 380;
				}
			}
			else {
				graphics.DrawRectangle(&pen2, AX3, AY3, 20, 20);
			}
			if (HoldBox4) {
				Point Box4(first2.X + second2.X - 10, first2.Y - second2.Y - 10);
				graphics.DrawRectangle(&pen3, Box4.X, Box4.Y, 20, 20);
				if (Box4.X < Box2.X + 20 && Box4.X > Box2.X - 20 || Box4.X < Box3.X + 20 && Box4.X > Box3.X - 20 || Box4.X < Box1.X + 20 && Box4.X > Box1.X - 20 || Box4.X < Box5.X + 20 && Box4.X > Box5.X - 20 || Box4.X < Box6.X + 20 && Box4.X > Box6.X - 20) {
					AX4 = first2.X + second2.X - 10;
					AY4 = 380 - 20 * n;
				}
				else {
					AX4 = first2.X + second2.X - 10;
					AY4 = 380;
				}
			}
			else {
				graphics.DrawRectangle(&pen2, AX4, AY4, 20, 20);
			}
			if (HoldBox5) {
				Point Box5(first2.X + second2.X - 10, first2.Y - second2.Y - 10);
				graphics.DrawRectangle(&pen3, Box5.X, Box5.Y, 20, 20);
				if (Box5.X < Box2.X + 20 && Box5.X > Box2.X - 20 || Box5.X < Box3.X + 20 && Box5.X > Box3.X - 20 || Box5.X < Box4.X + 20 && Box5.X > Box4.X - 20 || Box5.X < Box1.X + 20 && Box5.X > Box1.X - 20 || Box5.X < Box6.X + 20 && Box5.X > Box6.X - 20) {
					AX5 = first2.X + second2.X - 10;
					AY5 = 380 - 20 * n;
				}
				else {
					AX5 = first2.X + second2.X - 10;
					AY5 = 380;
				}
			}
			else {
				graphics.DrawRectangle(&pen2, AX5, AY5, 20, 20);
			}
			if (HoldBox6) {
				Point Box6(first2.X + second2.X - 10, first2.Y - second2.Y - 10);
				graphics.DrawRectangle(&pen3, Box6.X, Box6.Y, 20, 20);
				if (Box6.X < Box2.X + 20 && Box6.X > Box2.X - 20 || Box6.X < Box3.X + 20 && Box6.X > Box3.X - 20 || Box6.X < Box4.X + 20 && Box6.X > Box4.X - 20 || Box6.X < Box5.X + 20 && Box6.X > Box5.X - 20 || Box6.X < Box1.X + 20 && Box6.X > Box1.X - 20) {
					AX6 = first2.X + second2.X - 10;
					AY6 = 380 - 20 * n;
				}
				else {
					AX6 = first2.X + second2.X - 10;
					AY6 = 380;
				}
			}
			else {
				graphics.DrawRectangle(&pen2, AX6, AY6, 20, 20);
			}
			if (first2.X + second2.X >= Box1.X && first2.X + second2.X <= Box1.X + 20 && first2.Y - second2.Y >= Box1.Y && first2.Y - second2.Y <= Box1.Y + 20) {
				if (HoldBox2 == 0 && HoldBox3 == false && HoldBox4 == false && HoldBox5 == false && HoldBox6 == false) {
					Point Box1(second2.X + first2.X - 10 + AX1, first2.Y - second2.Y - 10 + AY1);
					graphics.DrawRectangle(&pen2, AX1, AY1, 20, 20);
					HoldBox1 = true;
				}

			}
			else {
				//	graphics.DrawRectangle(&pen2, Box1.X, Box1.Y, 20, 20);
			}

			if (first2.X + second2.X >= Box2.X && first2.X + second2.X <= Box2.X + 20 && first2.Y - second2.Y >= Box2.Y &&  first2.Y - second2.Y <= Box2.Y + 20) {
				if (HoldBox1 == 0 && HoldBox3 == false && HoldBox4 == false && HoldBox5 == false && HoldBox6 == false) {
					Point Box2(second2.X + first2.X - 10 + AX2, first2.Y - second2.Y - 10 + AY2);
					graphics.DrawRectangle(&pen2, AX2, AY2, 20, 20);
					HoldBox2 = true;
				}

			}
			else {
				//	graphics.DrawRectangle(&pen2, Box2.X, Box2.Y, 20, 20);
			}
			if (first2.X + second2.X >= Box3.X && first2.X + second2.X <= Box3.X + 20 && first2.Y - second2.Y >= Box3.Y && first2.Y - second2.Y <= Box3.Y + 20) {
				if (HoldBox1 == 0 && HoldBox2 == false && HoldBox4 == false && HoldBox5 == false && HoldBox6 == false) {
					Point Box3(second2.X + first2.X - 10 + AX3, first2.Y - second2.Y - 10 + AY3);
					graphics.DrawRectangle(&pen3, AX3, AY3, 20, 20);
					HoldBox3 = true;
				}

			}
			else {
				//	graphics.DrawRectangle(&pen2, Box3.X, Box3.Y, 20, 20);
			}
			if (first2.X + second2.X >= Box4.X && first2.X + second2.X <= Box4.X + 20 && first2.Y - second2.Y >= Box4.Y && first2.Y - second2.Y <= Box4.Y + 20) {
				if (HoldBox1 == 0 && HoldBox2 == false && HoldBox3 == false && HoldBox5 == false && HoldBox6 == false) {
					Point Box4(second2.X + first2.X - 10 + AX4, first2.Y - second2.Y - 10 + AY4);
					graphics.DrawRectangle(&pen3, AX4, AY4, 20, 20);
					HoldBox4 = true;
				}

			}
			else {
				//	graphics.DrawRectangle(&pen2, Box4.X, Box4.Y, 20, 20);
			}
			if (first2.X + second2.X >= Box5.X && first2.X + second2.X <= Box5.X + 20 && first2.Y - second2.Y >= Box5.Y && first2.Y - second2.Y <= Box5.Y + 20) {
				if (HoldBox1 == 0 && HoldBox2 == false && HoldBox3 == false && HoldBox4 == false && HoldBox6 == false) {
					Point Box5(second2.X + first2.X - 10 + AX5, first2.Y - second2.Y - 10 + AY5);
					graphics.DrawRectangle(&pen3, AX5, AY5, 20, 20);
					HoldBox5 = true;
				}

			}
			else {
				//	graphics.DrawRectangle(&pen2, Box5.X, Box5.Y, 20, 20);
			}
			if (first2.X + second2.X >= Box6.X && first2.X + second2.X <= Box6.X + 20 && first2.Y - second2.Y >= Box6.Y && first2.Y - second2.Y <= Box6.Y + 20) {
				if (HoldBox1 == 0 && HoldBox2 == false && HoldBox3 == false && HoldBox4 == false && HoldBox5 == false) {
					Point Box6(second2.X + first2.X - 10 + AX6, first2.Y - second2.Y - 10 + AY6);
					graphics.DrawRectangle(&pen3, AX6, AY6, 20, 20);
					HoldBox6 = true;
				}

			}
			else {
				//graphics.DrawRectangle(&pen2, Box6.X, Box6.Y, 20, 20);
			}

			//graphics.DrawRectangle(&pen2, Box1.X, Box1.Y, 20, 20);
			//	Point Box2(290, 380);
			//	graphics.DrawRectangle(&pen2, Box2.X, Box2.Y, 20, 20);
			//	Point Box3(340, 380);
			//	graphics.DrawRectangle(&pen2, Box3.X, Box3.Y, 20, 20);
			//	Point Box4(490, 380);
			//	graphics.DrawRectangle(&pen2, Box4.X, Box4.Y, 20, 20);
			//	Point Box5(560, 380);
			//	graphics.DrawRectangle(&pen2, Box5.X, Box5.Y, 20, 20);
		}
		else {
			graphics.DrawRectangle(&pen2, AX1, AY1, 20, 20);
			graphics.DrawRectangle(&pen2, AX2, AY2, 20, 20);
			graphics.DrawRectangle(&pen2, AX3, AY3, 20, 20);
			graphics.DrawRectangle(&pen2, AX4, AY4, 20, 20);
			graphics.DrawRectangle(&pen2, AX5, AY5, 20, 20);
			graphics.DrawRectangle(&pen2, AX6, AY6, 20, 20);
		}
}
void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (repaint)
		InvalidateRect(hWnd, drawArea, TRUE); // repaint all
	else
		InvalidateRect(hWnd, drawArea, FALSE); //repaint drawArea
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc);
	EndPaint(hWnd, &ps);
}

int OnCreate(HWND window)
{
	return 0;
}


// main function (exe hInstance)
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);



	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance; // Store instance handle (of exe) in our global variable

	// main window
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	// create button and store the handle                                                       
	
	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Lewo"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Prawo"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		140, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Lewo2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		230, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON3,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Prawo2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		320, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON4,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Zapis"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		410, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON5,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),    // The class name required is button
		TEXT("Złap"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		500, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON6,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Puść"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		590, 500,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON7,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                             // extra bits you dont really need



	// create button and store the handle                                                       

	hwndButton = CreateWindow(TEXT("button"), TEXT("Auto ON"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		40, 560, 100, 30, hWnd, (HMENU)ID_RBUTTON1, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("Auto OFF"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		40, 595, 100, 30, hWnd, (HMENU)ID_RBUTTON2, GetModuleHandle(NULL), NULL);

	OnCreate(hWnd);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window (low priority)
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// MENU & BUTTON messages
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON1 :
			repaint = true;
			if (Angle1 < range && Angle1 >= 0)
				Angle1++;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON2:
			repaint = true;
			if (Angle1 <= range && Angle1 > 0)
				Angle1--;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON3:
			repaint = true;
			if (Angle2 < range && Angle2 >= -range)
				Angle2++;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		case ID_BUTTON4:
			repaint = true;
			if (Angle2 <= range && Angle2 > -range)
				Angle2--;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		case ID_BUTTON5:
			repaint = true;
			Angle1_saved = Angle1;
			Angle2_saved = Angle2;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
	case ID_BUTTON6:
			repaint = true;
			Hold = true;
			n++;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON7:
			repaint = true;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			Hold = false;
			HoldBox1 = false;
			HoldBox2 = false;
			HoldBox3 = false;
			HoldBox4 = false;
			HoldBox5 = false;
			HoldBox6 = false;
			break;

		case ID_RBUTTON1:
			animation = true;
			SetTimer(hWnd, TMR_1, 25, 0);
			break;
		case ID_RBUTTON2:
			animation = false;
			KillTimer(hWnd, TMR_1);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here (not depend on timer, buttons)
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			//force window to repaint
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			repaint = true;
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			repaint = false;
			value++;
			if(value==1140){
				value = N;
				repaint = true;
			}
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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
