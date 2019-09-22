#include "polygon.h"

CPolygon::CPolygon(int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth)
{
}

CPolygon::CPolygon()
{
}

void CPolygon::Draw(HDC _hdc)
{
	// Create the green pen: 
	HPEN green_pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	// Select the pen into the context: 
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	POINT points[3];
	points[0] = { m_iStartX, m_iStartY };
	points[1] = { m_iEndX, m_iEndY };
	points[2] = { m_iStartX, m_iEndY };
	Polygon(_hdc, points, 3);

	SelectObject(_hdc, old_pen);
	// Restore old pen. 
	DeleteObject(green_pen);
	// Delete the green pen. 
}

void CPolygon::SetFillColor(COLORREF _newColor)
{
}

void CPolygon::SetPenColor(COLORREF _newColor)
{
}

void CPolygon::AddPoint(POINT p)
{
	
}
