#include "Draw.h"




void DrawLine(HDC hdc, mypoint A, mypoint B)
{
		MoveToEx(hdc, A.x, A.y, NULL);
		LineTo(hdc, B.x, B.y);
}

void DrawIteration(HDC hdc, mypoint A, mypoint B, int present, int n)
{
	mypoint C, M, D;
	if (n - present)
	{
		M.x = A.x;
		M.y = A.y;
		D.x = B.x;
		D.y = B.y;
		C.x = (M.x + D.x) *0.5 + (D.y - M.y) *0.5;
		C.y = (M.y + D.y) *0.5 - (D.x - M.x) *0.5;
		DrawIteration(hdc, M, C, present + 1, n);
		DrawIteration(hdc, C, D, present + 1, n);
	}
	else
	{
		DrawLine(hdc, A, B);
	}

}