﻿
#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

//Logo
void logo()
{
	textcolor(6);
	gotoxy(X, Y + 1);	cout << "PP PP      UU      UU     ZZZZZZZZ   ZZZZZZZZ    LL         EEEEEEEE" << endl;
	gotoxy(X, Y + 2);	cout << "PP   PP    UU      UU          ZZ         ZZ     LL         EE        " << endl;
	gotoxy(X, Y + 3);	cout << "PP PP      UU      UU        ZZ         ZZ       LL         EEEEEEEE " << endl;
	gotoxy(X, Y + 4);	cout << "PP         UU      UU      ZZ         ZZ         LL         EE        " << endl;
	gotoxy(X, Y + 5);	cout << "PP         UUUUUUUUUU     ZZZZZZZZ   ZZZZZZZZ    LLLLLLLL   EEEEEEEE" << endl;

}
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */

// Hàm tự viết
void ToMau(int x, int y, char *a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}