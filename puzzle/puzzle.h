#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>;
#include <io.h>
#include <fcntl.h>
using namespace std;

#define Xp 2
#define Yp 0
#define Xo 11
#define Yo 1
#define MAX 8
using namespace std;

class Puzzle
{
private:
	int x, y, width, height, n;
	int gamedl[MAX], hang1[MAX], hang2[MAX], hang3[MAX];

public:
	void logo();
	void gotoXY(int x, int y);
	void resizeConsole(int width, int height);
	void textcolor(int x);
	void XoaManHinh();
	void menu();
	void game();
	void testcolor();
	void esc();
	void ancontro();
	void hiencontro();
	Puzzle();
	~Puzzle();
};

