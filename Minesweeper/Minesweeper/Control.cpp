#include "Control.h"



Control::Control() : m_ix(0), m_iy(0)
{
}

void Control::PosControl(int w, int h)
{
	int ch = getch();
	if (ch == 224)
	{
		ch = getch();
		switch (ch)
		{
		case UP:
			if (m_iy-1 >= 0)
				m_iy--;
			break;
		case DOWN:
			if (m_iy+1 < h)
				m_iy++;
			break;
		case LEFT:
			if (m_ix - 1 >= 0)
				m_ix--;
			break;
		case RIGHT:
			if (m_ix + 1 < w)
				m_ix++;
			break;
		default:
			break;
		}
		gotoxy(m_ix*2+2, m_iy+1);
	}
} 


Control::~Control()
{
}
