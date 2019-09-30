#include "polygon.h"

CPolygon::CPolygon(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth)
{
	m_nPoints = 0;
	m_iBrushStyle = _iBrushStyle;
	m_iFillColor = _FillColor;
	m_iPenColor = _PenColor;
	m_iFillStyle = _iHatchStyle;
	m_iPenStyle = _iPenStyle;
	m_iPenWidth = _iPenWidth;
}

CPolygon::CPolygon()
{
	
}

void CPolygon::Draw(HDC _hdc)
{
	HPEN black_pen = CreatePen(m_iPenStyle, m_iPenWidth, m_iPenColor);
	// Select the pen into the context: 
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, black_pen));

	SetBrushStyle(m_iBrushStyle);
	HBRUSH old_brush = static_cast<HBRUSH>(SelectObject(_hdc, myBrush));



	Polygon(_hdc, m_pPointList, m_nPoints);

	SelectObject(_hdc, old_pen);

	DeleteObject(black_pen);
	DeleteObject(myBrush);
}

void CPolygon::SetFillColor(COLORREF _newColor)
{
}

void CPolygon::SetPenColor(COLORREF _newColor)
{
}

void CPolygon::AddPoint(POINT p)
{
	m_pPointList[m_nPoints] = p;
	m_nPoints++;
}

void CPolygon::SetBrushStyle(EBRUSHSTYLE _brushStyle)
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
		myBrush = CreateHatchBrush(m_iFillStyle, m_iFillColor);
		break;
	}
	}
}
