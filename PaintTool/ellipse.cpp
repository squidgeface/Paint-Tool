#include "ellipse.h"

CEllipse::CEllipse(COLORREF _newColor, int, int)
{
}

CEllipse::CEllipse()
{
}

void CEllipse::Draw(HDC _hdc)
{
	// Create the green pen: 
	HPEN black_pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	// Select the pen into the context: 
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, black_pen));

	//start x to end x
	Ellipse(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen);
	// Restore old pen. 
	DeleteObject(black_pen);
	// Delete the green pen. 
}

void CEllipse::SetColor(COLORREF _newColor)
{
}
