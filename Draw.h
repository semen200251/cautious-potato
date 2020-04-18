#pragma once
#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
typedef struct {
	double x, y;
}mypoint;

void DrawLine(HDC hdc, mypoint A, mypoint B);
void DrawIteration(HDC hdc, mypoint A, mypoint B, int present, int n);