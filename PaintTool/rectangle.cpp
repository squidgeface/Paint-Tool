#include "rectangle.h"


CRectangle::CRectangle(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _PenWidth, int _X, int _Y)
{
	m_iBrushStyle = _iBrushStyle;
	m_iHatchStyle = _iHatchStyle;
	m_iFillColor = _FillColor;
	m_iPenStyle = _iPenStyle;
	m_iPenColor = _PenColor;
	m_iPenWidth = _PenWidth;
}

CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
}

void CRectangle::Draw(HDC _hdc)
{

	// Create the green pen: 
	HPEN black_pen = CreatePen(m_iPenStyle, m_iPenWidth, m_iPenColor);
	// Select the pen into the context: 
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, black_pen));

	RECT myTangle;

	SetBrushStyle(m_iBrushStyle);

	HBRUSH old_brush = static_cast<HBRUSH>(SelectObject(_hdc, myBrush));

	//start x to end x
	SetRect(&myTangle, m_iStartX, m_iStartY, m_iEndX, m_iEndY);

	Rectangle(_hdc, myTangle.left, myTangle.top, myTangle.right, myTangle.bottom);


	
	SelectObject(_hdc, old_pen);
	// Restore old pen. 
	DeleteObject(black_pen);
	DeleteObject(myBrush);
	
	


	// Delete the green pen. 
}

void CRectangle::SetBrushStyle(EBRUSHSTYLE _brushStyle)
{

	switch (_brushStyle)
	{
	case NOSTYLE:
		{
		LOGBRUSH logbrush;
		
		logbrush.lbStyle = BS_NULL;//or BS_HOLLOW
	
		myBrush = CreateBrushIndirect(&logbrush);
			break;
		}

		case SOLID:
		{
			myBrush = CreateSolidBrush(m_iFillColor);
			break;
		}

		case HATCH:
		{
			myBrush = CreateHatchBrush(m_iHatchStyle, m_iFillColor);
			break;
		}
	}
}

void CRectangle::SetFillColor(COLORREF _newColor)
{
	m_iFillColor = _newColor;
	
}

void CRectangle::SetPenStyle(int _iPenStyle)
{
	m_iPenStyle = _iPenStyle;
}

void CRectangle::SetPenColor(COLORREF _newColor)
{
	m_iPenColor = _newColor;
}

void CRectangle::SetHatchStyle(int _iHatchStyle)
{
	m_iHatchStyle = _iHatchStyle;
}
