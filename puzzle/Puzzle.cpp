#include "Puzzle.h"
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition;

//Hàm ẩn con trỏ
void Puzzle::ancontro()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
//Hàm hiện con trỏ
void hiencontro()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void Puzzle::gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
// Hàm in logo
void Puzzle::logo()
{
	textcolor(4);
	gotoXY(Xp, Yp + 0);	cout << " ________    __     __    _________    _________     __           _________ " << endl;
	gotoXY(Xp, Yp + 1);	cout << "|   __   |  |  |   |  |  |____     |  |____     |   |  |         |   ______|" << endl;
	gotoXY(Xp, Yp + 2);	cout << "|  |__|  |  |  |   |  |       /   /        /   /    |  |         |  |______ " << endl;
	gotoXY(Xp, Yp + 3);	cout << "|  |_____|  |  |   |  |      /   /        /   /     |  |         |   ______|" << endl;
	gotoXY(Xp, Yp + 4);	cout << "|  |        |  |___|  |     /   /___     /   /___   |  |______   |  |______ " << endl;
	gotoXY(Xp, Yp + 5);	cout << "|__|        |_________|    |________|   |________|  |_________|  |_________|" << endl;
}
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void Puzzle::resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm tô màu
void Puzzle::textcolor(int x)
{
	ancontro();
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
// Hàm tạo menu
void Puzzle::menu()
{
	resizeConsole(700, 300);
	system("cls");
	logo();
	int menu_item = 0, run, x = 7;
	bool running = true;
	while (running)
	{
		ancontro();
		gotoXY(Xo + 17, Yo + x); cout << "-->";
		gotoXY(Xo + 41, Yo + x); cout << "<--";	textcolor(7);
		gotoXY(Xo + 22, Yo + 7); cout << "    Start game";
		gotoXY(Xo + 22, Yo + 8); cout << "   How to play";
		gotoXY(Xo + 22, Yo + 9); cout << " Make some color";
		
		if (menu_item == 3) {

			for (int i = 1; i < 16; i++)
			{
				if (GetAsyncKeyState(VK_RETURN)) {
					textcolor(i); gotoXY(Xo + 22, Yo + 10);  cout << " Rainbow Rainbow";
					Sleep(100);
					if (i == 15)
					i = 1;
				}
			}
		}
		else {
			gotoXY(Xo + 22, Yo + 10);  cout << " Rainbow Rainbow";
		}
		textcolor(7);
		gotoXY(Xo + 22, Yo + 11); cout << "    Exit game";


		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
		{
			gotoXY(Xo + 17, Yo + x); cout << "   ";
			gotoXY(Xo + 41, Yo + x); cout << "   ";
			x++;
			gotoXY(Xo + 17, Yo + x); cout << "-->";
			gotoXY(Xo + 41, Yo + x); cout << "<--";
			menu_item++;

			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(Xo + 17, Yo + x); cout << "   ";
			gotoXY(Xo + 41, Yo + x); cout << "   ";
			x--;
			gotoXY(Xo + 17, Yo + x); cout << "-->";
			gotoXY(Xo + 41, Yo + x); cout << "<--";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed
			switch (menu_item) {
				case 0: {
					running = false;
					system("cls");
					resizeConsole(500, 500);
					game();
					break;
				}
				case 1: {
					running = false;
					system("cls");
					resizeConsole(600, 350);
					gotoXY(9, 4);
					textcolor(4);
					cout << "Move the box |  | to get the following results:";
					gotoXY(28, 7);
					cout << "1    2    3";
					gotoXY(28, 9);
					cout << "4    5    6";
					gotoXY(28, 11);
					cout << "7    8   |  |";
					gotoXY(9, 14);
					cout << "ESC -> Back";
				ge:	gotoXY(9, 15);
					esc();
					goto ge;
					break;
				}
				case 2: {				
					running = false;
					system("cls");
					testcolor();
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					running = false;
					gotoXY(28, 14);
					cout << "Thanks for testing our app <3";
					gotoXY(30, 15);
						cout << "Game will be closed in 3";
					Sleep(1000);
					gotoXY(30, 15);
						cout << "Game will be closed in 2";
					Sleep(1000);
					gotoXY(30, 15);
						cout << "Game will be closed in 1";
					Sleep(1000);
					exit(0);
					break;
				}
			}
		}
	}
}
//Hàm ESC
void Puzzle::esc()
{
	system("pause >nul");
	if (GetAsyncKeyState(VK_ESCAPE))
		menu();
}
// Hàm game chính
void Puzzle::game()
{
	ancontro();
F5:
	gotoXY(2, 0);
	cout << "ENTER -> Random number";
	gotoXY(2, 1);
	cout << "ARROW -> Play";
	gotoXY(2, 2);
	cout << "ESC -> Back";
	resizeConsole(310, 310);
	for (int i = 0; i < MAX; i++)
	{
		srand(time(NULL));
		gamedl[i] = 1 + rand() % (8);
		for (int j = i - 1; j >= 0; j--) {
			if (gamedl[i] != gamedl[j])
				continue;
			else
			{
				gamedl[i] = 1 + rand() % (8);
				j = i;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		hang1[i] = gamedl[i];
	}
	for (int i = 3; i < 6; i++)
	{
		hang2[i - 3] = gamedl[i];
	}
	for (int i = 3; i < 8; i++)
	{
		hang3[i - 6] = gamedl[i];
	}
	hang3[2] = 0;
	textcolor(775);


	int u = 0, o = 0;

	for (int i = 0; i < 3; i++) {
		gotoXY(u + 10, 5);
		if (hang1[i] == 0)	cout << "| |";
		else
			cout << " " << hang1[i];
		gotoXY(u + 10, 7);
		if (hang2[i] == 0) cout << "| |";
		else
			cout << " " << hang2[i];
		gotoXY(u + 10, 9);
		if (hang3[i] == 0)	cout << "| |";
		else
			cout << " " << hang3[i];;
		u += 5;

	}
	int yy = 2, xx = 2;
	for (;;) {
		system("pause>nul");
		if (GetAsyncKeyState(VK_UP) && yy > 0)
		{
			if (yy == 2) {
				int tam = hang3[xx];
				hang3[xx] = hang2[xx];
				hang2[xx] = tam;
				yy -= 1;
			}
			else if (yy == 1) {
				int tam = hang2[xx];
				hang2[xx] = hang1[xx];
				hang1[xx] = tam;
				yy -= 1;
			}
			system("cls");
			u = 0;
			for (int i = 0; i < 3; i++) {
				gotoXY(u + 10, 5);
				if (hang1[i] == 0)	cout << "| |";
				else
					cout << " " << hang1[i];
				gotoXY(u + 10, 7);
				if (hang2[i] == 0) cout << "| |";
				else
					cout << " " << hang2[i];
				gotoXY(u + 10, 9);
				if (hang3[i] == 0)	cout << "| |";
				else
					cout << " " << hang3[i];;
				u += 5;
			}
		}

		if (GetAsyncKeyState(VK_DOWN) && yy < 2)
		{
			if (yy == 0) {
				int tam = hang1[xx];
				hang1[xx] = hang2[xx];
				hang2[xx] = tam;
				yy += 1;
			}
			else if (yy == 1) {
				int tam = hang3[xx];
				hang3[xx] = hang2[xx];
				hang2[xx] = tam;
				yy += 1;
			}
			system("cls");
			u = 0;
			for (int i = 0; i < 3; i++) {
				gotoXY(u + 10, 5);
				if (hang1[i] == 0)	cout << "| |";
				else
					cout << " " << hang1[i];
				gotoXY(u + 10, 7);
				if (hang2[i] == 0) cout << "| |";
				else
					cout << " " << hang2[i];
				gotoXY(u + 10, 9);
				if (hang3[i] == 0)	cout << "| |";
				else
					cout << " " << hang3[i];;
				u += 5;
			}
		}
		if (GetAsyncKeyState(VK_LEFT) && xx > 0) {
			if (yy == 0)
			{
				if (xx == 2) {
					int tam = hang1[xx];
					hang1[xx] = hang1[xx - 1];
					hang1[xx - 1] = tam;
					xx -= 1;
				}
				else if (xx == 1) {
					int tam = hang1[xx];
					hang1[xx] = hang1[xx - 1];
					hang1[xx - 1] = tam;
					xx -= 1;
				}

			}
			else if (yy == 1) {
				if (xx == 2) {
					int tam = hang2[xx];
					hang2[xx] = hang2[xx - 1];
					hang2[xx - 1] = tam;
					xx -= 1;
				}
				else if (xx == 1) {
					int tam = hang2[xx];
					hang2[xx] = hang2[xx - 1];
					hang2[xx - 1] = tam;
					xx -= 1;
				}
			}
			else if (yy == 2) {
				if (xx == 2) {
					int tam = hang3[xx];
					hang3[xx] = hang3[xx - 1];
					hang3[xx - 1] = tam;
					xx -= 1;
				}
				else if (xx == 1) {
					int tam = hang3[xx];
					hang3[xx] = hang3[xx - 1];
					hang3[xx - 1] = tam;
					xx -= 1;
				}
			}
			system("cls");
			u = 0;
			for (int i = 0; i < 3; i++) {
				gotoXY(u + 10, 5);
				if (hang1[i] == 0)	cout << "| |";
				else
					cout << " " << hang1[i];
				gotoXY(u + 10, 7);
				if (hang2[i] == 0) cout << "| |";
				else
					cout << " " << hang2[i];
				gotoXY(u + 10, 9);
				if (hang3[i] == 0)	cout << "| |";
				else
					cout << " " << hang3[i];;
				u += 5;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) && xx < 3) {
			if (yy == 0)
			{
				if (xx == 0) {
					int tam = hang1[xx];
					hang1[xx] = hang1[xx + 1];
					hang1[xx + 1] = tam;
					xx += 1;
				}
				else if (xx == 1) {
					int tam = hang1[xx];
					hang1[xx] = hang1[xx + 1];
					hang1[xx + 1] = tam;
					xx += 1;
				}

			}
			else if (yy == 1) {
				if (xx == 0) {
					int tam = hang2[xx];
					hang2[xx] = hang2[xx + 1];
					hang2[xx + 1] = tam;
					xx += 1;
				}
				else if (xx == 1) {
					int tam = hang2[xx];
					hang2[xx] = hang2[xx + 1];
					hang2[xx + 1] = tam;
					xx += 1;
				}
			}
			else if (yy == 2) {
				if (xx == 0) {
					int tam = hang3[xx];
					hang3[xx] = hang3[xx + 1];
					hang3[xx + 1] = tam;
					xx += 1;
				}
				else if (xx == 1) {
					int tam = hang3[xx];
					hang3[xx] = hang3[xx + 1];
					hang3[xx + 1] = tam;
					xx += 1;
				}
			}
			system("cls");
			u = 0;
			for (int i = 0; i < 3; i++) {
				gotoXY(u + 10, 5);
				if (hang1[i] == 0)	cout << "| |";
				else
					cout << " " << hang1[i];
				gotoXY(u + 10, 7);
				if (hang2[i] == 0) cout << "| |";
				else
					cout << " " << hang2[i];
				gotoXY(u + 10, 9);
				if (hang3[i] == 0)	cout << "| |";
				else
					cout << " " << hang3[i];;
				u += 5;
			}
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			goto F5;
		}
		if (hang1[0] == 1 && hang1[1] == 2 && hang1[2] == 3 && hang2[0] == 4 && hang2[1] == 5 && hang2[2] == 6 && hang3[0] == 7 && hang3[1] == 8 && hang3[2] == 0)
		{
			gotoXY(6, 12);
			cout << "CONGRATULATIONS! YOU WIN" << endl;
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			menu();
		}
	}
}
//Hàm test màu
void Puzzle::testcolor()
{
	for (int i = 1;; i++)
	{
		ancontro();
		textcolor(i);
		cout  << "PUZZLE ";
		Sleep(50);
		textcolor(7);
		if (i == 15) i = 1;
		if (GetAsyncKeyState(VK_ESCAPE)) {
			menu();
		}
	}
}

Puzzle::Puzzle()
{
}

Puzzle::~Puzzle()
{
}
