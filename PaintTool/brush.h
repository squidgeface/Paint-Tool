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

#ifndef __BRUSH_H__
#define __BRUSH_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>
#include "shape.h"

class CBrush : public IShape
{
public:
	CBrush(int _iStyle, int _iWidth, COLORREF _newColor, int _iStartX, int _iStartY);
	CBrush();
	~CBrush();

	virtual void Draw(HDC _hdc);
	void SetWidth(int _iNewWidth);

private:

	int m_iStyle;
	int m_iWidth;
	COLORREF m_Color;
};


#endif