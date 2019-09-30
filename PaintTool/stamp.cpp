#include "stamp.h"

CStamp::CStamp()
{
}

CStamp::CStamp(HINSTANCE _hInstance, int _ID)
{
	m_hBitMap = LoadBitmap(_hInstance, MAKEINTRESOURCE(_ID));
	GetObject(m_hBitMap, sizeof(BITMAP), &m_bitmapStructure);
	myBrush = CreateSolidBrush(RGB(255,0,0));
}

CStamp::~CStamp()
{
}

void CStamp::Draw(HDC _hdc)
{
	

	HDC bmHDC = CreateCompatibleDC(_hdc);
	HBRUSH old_brush = static_cast<HBRUSH>(SelectObject(_hdc, myBrush));

	HBITMAP oldBM = static_cast<HBITMAP>(SelectObject(bmHDC, m_hBitMap));
	//BitBlt(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY, bmHDC, 0, 0, SRCCOPY);
	StretchBlt(_hdc, m_iStartX, m_iStartY, 100, 100, bmHDC, 0, 0, m_bitmapStructure.bmWidth, m_bitmapStructure.bmHeight, SRCCOPY);

	SelectObject(bmHDC, oldBM); 

	DeleteDC(bmHDC); 
	DeleteObject(myBrush);
	
	

}

void CStamp::SetStartX(int _iX)
{

}

void CStamp::SetStartY(int _iY)
{

}
