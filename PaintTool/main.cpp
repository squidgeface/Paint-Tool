/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2019 Media Design School

  File Name   :   [Filename]
  Description :   [One line description of what is the file is for]
  Author      :   [Your name]
  Mail        :   [your.name]@mediadesign.school.nz
********************/

//#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

#include "resource.h"
#include "shape.h"
#include "line.h"
#include "canvas.h"
#include "rectangle.h"
#include "ellipse.h"
#include "polygon.h"
#include "stamp.h"
#include "brush.h"
#include "backBuffer.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"

//Global variables
HINSTANCE g_hInstance;
CCanvas* g_pCanvas;
IShape* g_pShape = 0;
HMENU g_hMenu;


//Enum to decalre the type of tool supported by the application.
enum ESHAPE
{
	FREEHAND = 0,
	LINESHAPE,
	RECTANGLESHAPE,
	ELLIPSESHAPE,
	POLYGONSHAPE,
	STAMP
};


void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.
	static ESHAPE s_currentShape = FREEHAND;
	static int s_iMouseX = 0;
	static int s_iMouseY = 0;
	static bool s_mIsDown = false;
	
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.
		g_pCanvas = new CCanvas();

		// Return Success.
		return (0);
	}
	break;
	case WM_PAINT:
	{
		hdc = BeginPaint(_hwnd, &ps);
		// You would do all your painting here...
		if (g_pCanvas)
		{
			g_pCanvas->Draw(hdc);
		}

		EndPaint(_hwnd, &ps);
		// Return Success.
		return (0);
	}
	break;

	case WM_LBUTTONUP:
	{
		s_mIsDown = false;
	}
	break;

	case WM_LBUTTONDOWN:
	{
		s_iMouseX = static_cast<int>(LOWORD(_lparam));
		s_iMouseY = static_cast<int>(HIWORD(_lparam));
		s_mIsDown = true;

		switch (s_currentShape)
		{
		case FREEHAND:
		{

			g_pShape = new CBrush();
			g_pShape->SetStartX(s_iMouseX);
			g_pShape->SetStartY(s_iMouseY);
			g_pShape->SetEndX(s_iMouseX);
			g_pShape->SetEndY(s_iMouseY);
			g_pCanvas->AddShape(g_pShape);
			break;
		}
		case LINESHAPE:
		{

			g_pShape = new CLine();
			g_pShape->SetStartX(s_iMouseX);
			g_pShape->SetStartY(s_iMouseY);
			g_pShape->SetEndX(s_iMouseX);
			g_pShape->SetEndY(s_iMouseY);
			g_pCanvas->AddShape(g_pShape);
			break;
		}
		case RECTANGLESHAPE:
		{

			g_pShape = new CRectangle();
			g_pShape->SetStartX(s_iMouseX);
			g_pShape->SetStartY(s_iMouseY);
			g_pShape->SetEndX(s_iMouseX);
			g_pShape->SetEndY(s_iMouseY);
			g_pCanvas->AddShape(g_pShape);
			break;
		}
		case ELLIPSESHAPE:
		{

			g_pShape = new CEllipse();
			g_pShape->SetStartX(s_iMouseX);
			g_pShape->SetStartY(s_iMouseY);
			g_pShape->SetEndX(s_iMouseX);
			g_pShape->SetEndY(s_iMouseY);
			g_pCanvas->AddShape(g_pShape);
			break;
		}
		case POLYGONSHAPE:
		{

			g_pShape = new CPolygon();
			g_pShape->SetStartX(s_iMouseX);
			g_pShape->SetStartY(s_iMouseY);
			g_pShape->SetEndX(s_iMouseX);
			g_pShape->SetEndY(s_iMouseY);
			g_pCanvas->AddShape(g_pShape);
			break;
		}
		default:
			break;
		}

		return (0);
	}
	break;

	//Mouse button
	case WM_MOUSEMOVE: 
	{ 
		// get the position of the mouse 
		s_iMouseX = static_cast<int>(LOWORD(_lparam));
		s_iMouseY = static_cast<int>(HIWORD(_lparam));
		int iButtons = static_cast<int>(_wparam); 
		

			// Test if left button is down... 
			if (iButtons & MK_LBUTTON)
			{
				if (g_pShape)
				{
					g_pShape->SetEndX(s_iMouseX);
					g_pShape->SetEndY(s_iMouseY);
				}
				InvalidateRect(_hwnd, NULL, true);
			}
			// Test if right button is down... 
			if (iButtons & MK_RBUTTON)
			{
				// Do something...
			}
		
	}
	break;


	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
				//File Menu
			case ID_FILE_EXIT:
			{
				PostQuitMessage(0);
				break;
			}

			case ID_FILE_SAVE:
			{
			
				break;
			}

			case ID_FILE_OPEN:
			{

				break;
			}
	

			//Shape Menu
			case ID_SHAPE_LINE:
			{
				//g_pShape = new CLine(PS_SOLID, 1, BLACK_PEN,);
				s_currentShape = LINESHAPE;
				break;
			}

			case ID_SHAPE_R:
			{
				s_currentShape = RECTANGLESHAPE;
				break;
			}

			case ID_SHAPE_ELLIPSE:
			{
				s_currentShape = ELLIPSESHAPE;
				break;
			}

			case ID_SHAPE_POLYGON:
			{
				s_currentShape = POLYGONSHAPE;
				break;
			}

			//Pen menu
			case ID_WIDTH_THIN:
			{
			
				break;
			}

			case ID_WIDTH_MEDIUM:
			{

				break;
			}


			case ID_WIDTH_THICK:
			{

				break;
			}


			case ID_COLOR_RED:
			{

				break;
			}

			case ID_COLOR_BLUE:
			{

				break;
			}
			case ID_COLOR_GREEN:
			{

				break;
			}
			case ID_COLOR_YELLOW:
			{

				break;
			}
			case ID_COLOR_CUSTOM:
			{

				break;
			}

			case ID_STYLE_SOLID:
			{

				break;
			}

			case ID_STYLE_STIPED:
			{

				break;
			}

			case ID_STYLE_CROSSHATCH:
			{

				break;
			}

			//Brush Menu
			case ID_BRUSH_COLOR:
			{

				break;
			}

			case ID_BRUSH_STYLE:
			{

				break;
			}
		
			//Stamp Menu
			case ID_ADD_STAMP:
			{

				break;
			}

			case ID_HELP_ABOUT:
			{
				MessageBox(_hwnd, L"This paint tool was developed by .............", L"Author Information", MB_OK | MB_ICONINFORMATION);
				break;
			}
			default:
				break;
		}
		return(0);
	}
	break;
	case WM_DESTROY:
	{
		delete g_pCanvas;
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
	break;

		default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}

int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

	g_hInstance = _hInstance;
	// First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));
	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"My Paint Tool",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100,                    // Initial x,y.
		1500, 800,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}



	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			// Translate any accelerator keys.
			TranslateMessage(&msg);
			// Send the message to the window proc.
			DispatchMessage(&msg);
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}
