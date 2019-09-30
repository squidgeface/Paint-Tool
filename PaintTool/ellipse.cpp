#include "ellipse.h"

CEllipse::CEllipse(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _PenWidth, int _X, int _Y)
{
	m_iBrushStyle = _iBrushStyle;
	m_iHatchStyle = _iHatchStyle;
	m_iFillColor = _FillColor;
	m_iPenStyle = _iPenStyle;
	m_iPenColor = _PenColor;
	m_iPenWidth = _PenWidth;
}

CEllipse::CEllipse()
{
}

void CEllipse::Draw(HDC _hdc)
{
	HPEN black_pen = CreatePen(m_iPenStyle, m_iPenWidth, m_iPenColor);
	// Select the pen into the context: 
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, black_pen));

	SetBrushStyle(m_iBrushStyle);
	HBRUSH old_brush = static_cast<HBRUSH>(SelectObject(_hdc, myBrush));

	//start x to end x
	Ellipse(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen);
	// Restore old pen. 
	DeleteObject(black_pen);
	DeleteObject(myBrush);
	// Delete the green pen. 
}

void CEllipse::SetBrushStyle(EBRUSHSTYLE _brushStyle)
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


