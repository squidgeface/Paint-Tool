#include "rectangle.h"


CRectangle::CRectangle(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _X, int _Y)
{
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
	HPEN black_pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	// Select the pen into the context: 
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, black_pen));

	//start x to end x
	
	Rectangle(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);
	
	SelectObject(_hdc, old_pen);
	// Restore old pen. 
	DeleteObject(black_pen);
	// Delete the green pen. 
}

void CRectangle::SetBrushStyle(EBRUSHSTYLE _brushStyle)
{
	

}

void CRectangle::SetFillColor(COLORREF _newColor)
{

	
}

void CRectangle::SetPenStyle(int _iPenStyle)
{
}

void CRectangle::SetPenColor(COLORREF _newColor)
{
}

void CRectangle::SetHatchStyle(int _iHatchStyle)
{
}
