#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstring>
#include <time.h>
#include <cstdlib>
#pragma warning(disable:4996)
using namespace std;

//콘솔 크기
const int cols = 92;
const int lines = 26;

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ENTER 4

//함수 선언
void Init();
int keyControl();
int menuDraw();
void gotoxy(int, int);
void titleDraw();
int EndDraw();
void ScreenPause();
void ShowLose();
void ShowWin();

//숫자 야구 코드 '1'
class BullsAndCow
{
	int level, round = 0;
	const int series = 9;
	int *a,*ball,*strike,*out;
	int **m = new int*[series];
public:
	BullsAndCow() {	}

	void play()
	{
		round = 0;
		LevelDraw();
		system("cls");
		MakeRand();
		ball = new int[series];
		strike = new int[series];
		out = new int[series];
		for (int i = 0; i < series; i++)
		{
			m[i] = new int[level];
			ball[i] = 0;
			strike[i] = 0;
			out[i] = 0;
		}
		ShowManual();
		system("cls");

		for (int i = 0; i < series; i++)
		{
			DrawTurn();
			system("cls");
			ShowBoard();
			ScreenPause();
			system("cls");
			if (strike[i] == level)
			{
				ShowWin();
				return;
			}
			else if (out[i] == 2)
			{
				ShowLose();
				return;
			}
		}
		ShowLose();
		return;
	}

	//게임진행
	void DrawTurn()
	{
		gotoxy(39, 7);
		cout << "# round " << round+1 << " #";

		for (int i = 0; i < level; i++)
		{	
			// _ _ _ , _ _ _ _ 표기
			gotoxy(cols / level * i + 8, 15);
			cout << "_";
		}

	
		int n;
		for (int i = 0; i < level; i++)
		{
			while (1)
			{
				int n;
			TryCin:
				gotoxy(cols / level * i+8, 15);
				while (!(cin>>n) )		 //숫자아니면 무시하고 재입력
				{
					cin.clear();
					cin.ignore();
					gotoxy(cols / level * i + 8, 15);
					cout << "_        ";
					gotoxy(cols / level * i + 8, 15);
				}
				for (int j = 0; j < i; j++)
				{
					if (n == m[round][j])
					{
						gotoxy(50, 24);
						cout << "※ 중복된 숫자는 입력불가능합니다.";
						gotoxy(cols / level * i + 8, 15);
						cout << "_        ";
						goto TryCin;
					}
				}
				if (n < 10 && n >= 0)	//1-10사이면 m[][]에 저장하고 break;
				{
					m[round][i] = n;
					break;
				}
				else
				{
					cin.clear();
					cin.ignore();
					gotoxy(50, 23);
					cout << "※ 0부터 9사이의 숫자만 입력하십시오.";
					gotoxy(cols / level * i + 8, 15);
					cout << "_        ";
				}
			}
		}

		//볼,스트라이크,아웃 계산
		int outtemp = 0;
		for (int i = 0; i < level; i++)
		{
			for (int j = 0; j < level; j++)
			{
				if (m[round][i] == a[j] && m[round][i] != a[i])
				{
					(ball[round])++;
					//break;
				}
				else if (m[round][i] == a[j] && m[round][i] == a[i])
				{ 
					(strike[round])++;
					//break;
				}
				else
					outtemp++;
				
			}
		}
		if (outtemp == level)
			(out[round])++;
		round++;

	}

	//게임난이도 메뉴
	void LevelDraw()
	{
		int x = 38, y = 12;
		gotoxy(35, 7);
		cout << "[ 게 임 난 이 도 ]";
		gotoxy(38, 12);
		cout << "▶ NORMAL";
		gotoxy(41, 17);
		cout << "HARD";

		while (1)
		{
			int temp = keyControl();
			switch (temp)
			{
			case UP:
			{
				if (y > 12)
				{
					gotoxy(x, y);
					cout << " ";
					gotoxy(x, y-5);
					y -= 5;
					cout << "▶";
				}
				break;
			}
			case DOWN:
				if (y < 17)
				{
					gotoxy(x, y);
					cout << " ";
					gotoxy(x, y+5);
					y += 5;
					cout << "▶";
				}
				break;
			case ENTER:
			{
				if (y == 12)
					level = 3;
				else if (y == 17)
					level = 4;
				return;
			}
			}

		}
	}

	//중복없는 난수생성
	void MakeRand()
	{
		srand((unsigned int)time(NULL));
		int bFound;

		a = new int[level];
		for (int i = 0; i < level; i++)
		{
			while (1)
			{
				a[i] = rand() % 10 + 1;		//1~10사이의 난수생성
				bFound = 0;					//같은값 있는지 확인용
				for (int j = 0; j < i; j++)	//중복체크
				{
					if (a[j] == a[i])
					{
						bFound = 1;	//중복됐으면 bFound=1
						break;
					}
				}
				if (!bFound)	//1(같은값)이 아니면 while문 탈출
					break;
			}
		}
	}

	//현재게임상황
	void ShowBoard()
	{
		int x = 3, y = 4;
		for (int i = 0; i < round; i++)
		{
			gotoxy(x, y);
			cout << "round " << i + 1 << " :	" << m[i][0] << "  " << m[i][1] << "  " << m[i][2] ;
			if (level == 3)
			{
				cout << "   |   ";
			}
			else
			{
				cout << "  " << m[i][0] << "   |   ";
			} 
			if (strike[i] == 0 && ball[i] == 0)
				cout << " OUT ";
			else
				cout << strike[i] << "S " << ball[i] << "B ";
			y += 2;
		}

	}

	//게임방식 소개
	void ShowManual()
	{
		gotoxy(38, 7);
		cout << "[ 게 임 방 식 ]";
		gotoxy(10, 10);
		cout << "'숫자야구'는 총 9판2아웃제로 재이가 정하는 3/4자리의 숫자를 맞추는 게임이다.";
		gotoxy(10, 12);
		cout << "- NORMAL모드는 3개, HARD모드는 4개의 숫자를 사용한다. ";
		gotoxy(10, 14);
		cout << "- 사용되는 숫자는 0에서 9까지 서로 다른 숫자이다.";
		gotoxy(10, 16);
		cout << "- 숫자는 맞지만 위치가 틀렸을 경우 볼[B], 숫자와 위치가 전부 스트라이크[S],";
		gotoxy(10, 17);
		cout << "  숫자와 위치가 전부 틀리면 아웃[OUT].";
		ScreenPause();
	}

	//소멸자
	~BullsAndCow()
	{
		delete[]ball;
		delete[]strike;
		delete[]out;
		for (int i = 0; i < series; i++)
		{
			delete[]m[i];
		}
		delete[]a;
	}
};

int main()
{
	Init();
	titleDraw();
	int menu = menuDraw();

	BullsAndCow game1;

	while (1)
	{
		switch (menu)
		{
		case 1:	//숫자야구
		{
			
			game1.play();
			ScreenPause();
			system("cls");
			menu = menuDraw();
		}
		break;
		case 2:


		case 3:	//종료
		{
			int end = EndDraw();
			if (end == 1)
			{
				return 0;
			}
			else if (end == 2)
				menu = menuDraw();
		}
		default:
			break;
		}
	}
	

	return 0;
}

//콘솔 크기 초기화 함수
void Init()
{
	system("mode con cols=92 lines=26 | title 재이의 게임 ");
}

//게임시작화면
void titleDraw()
{
	cout << "\n\n\n\n\n\n";
	cout << "                  ## ##    ###   ##    ####  ##             ##  ##   #####   ## " << endl;
	cout << "          ######  ## ##   #####  ##   ###### ##      #####  ##  ##  ##   ##  ## " << endl;
	cout << "              ##  ## ##  ###  ## ##   ##  ## ##         ##  ##  ##  ##   ##  ## " << endl;
	cout << "              ##  ## ##  ##   ## ##   ##  ## ##         ##  ##  ##  ##   ##  ## " << endl;
	cout << "             ##   #####  ##   ## ##   ##  ## ##         ######  ##   #####   ## " << endl;
	cout << "            ###   ## ##  ##   ## ##    ####  ##         ##  ##  ##           ## " << endl;
	cout << "           ## ##  ## ##   ## ### ##          ##       ###   ##  ##    ######### " << endl;
	cout << "          ##   ## ## ##   #####  ##  ##########      ###    ##  ##    ##     ## " << endl;
	cout << "                  ## ##          ##          ##             ##  ##    ##     ## " << endl;
	cout << "                  ## ##          ##          ##             ##  ##    ##     ## " << endl;
	cout << "                     ##          ##          ##                 ##    ######### " << endl;
	cout << "\n";
	cout << "                                              <  Press Enter key to Start  >    " << endl;

	ScreenPause();
	
	system("cls");	//콘솔창 모든 글자 비움
}

//엔터누르기전까지 화면멈춤
void ScreenPause()	//엔터누르기전까지 화면멈춤
{
	while (1)	
	{
		if (keyControl() == ENTER)
			break;

	}
}

//메뉴	
int menuDraw()
{
	system("cls");
	int x = 38, y = 10;
	gotoxy(x, 5);
	cout << " [ 메 뉴 ]"<<endl;
	gotoxy(x - 2, y);	//10 2
	cout << "> 숫 자 야 구 " << endl;
	gotoxy(x, y+5);		//15 3 
	cout << " 준 비 중 ";
	gotoxy(x, y+5*2);	//20 4
	cout << "  종 료 ";
	
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP: 
		{
			if (y > (lines * 2 / 5))	//y가 '숫자야구'보다 위에 있을경우 (커서의 이동범위 제한)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y - (lines / 5));
				y -= (lines / 5);
				printf(">");
			}
			break;
		}

		case DOWN:
		{
			if (y < (lines * 4 / 5))	//y가 '종료'보다 아래에 있을경우 (커서의 이동범위 제한)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y + (lines / 5));
				y += (lines / 5);
				printf(">");
			}
			break;
		}

		case ENTER: 
		{
			system("cls");
			return (y / 5 -1 );
		}
		}
	}
}

//방향키,엔터 입력받는 함수
int keyControl()
{

	int key;
	while (1)
	{
		if (kbhit())
		{
			key = getch();
			if (key == 224)
			{
				key = getch();
				switch (key)
				{
				case 72:
					return UP;
					break;
				case 80:
					return DOWN;
					break;
				case 75:
					return LEFT;
					break;
				case 77:
					return RIGHT;
					break;
				default:
					break;
				}
			}
			else if (key == 13)
				return ENTER;
		}
	}
}

//커서 위치 이동함수
void gotoxy(int x, int y)
{
	HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consolehandle, pos);
}

int EndDraw()
{
	system("cls");
	int x = 28, y = 16;
	gotoxy(33, 10);
	cout << "게임을 종료하시겠습니까?";
	gotoxy(28, 15);
	cout << "yes";
	gotoxy(60, 15);
	cout << "no";
	gotoxy(28, 16);
	cout << "▲";

	while (1)
	{
		int temp = keyControl();
		switch (temp)
		{
		case LEFT:
		{
			if (x > 28)
			{
				gotoxy(x, y);
				cout << " ";
				gotoxy(x-32, y);
				x -= 32;
				cout << "▲";
			}
			break;
		}
		case RIGHT:
			if (x < 60)
			{
				gotoxy(x, y);
				cout << " ";
				gotoxy(x + 32, y);
				x += 32;
				cout << "▲";
			}
			break;
		case ENTER:
		{
			if (x == 28)
				return 1;
			if (x == 60)
				return 2;
		}
		}

	}
}

void ShowWin()
{
	cout << "\n\n\n\n\n\n\n\n";
	cout << "         ##      ##  #####   ###   ##    ##  ###  ##  ###  ##   ## " << endl;
	cout << "          ##    ##  ###  ##  ###   ##    ##  ###  ##  ###  ###  ## " << endl;
	cout << "           ## ##   ##    ##  ###   ##    ### #### ##  ###  ###  ## " << endl;
	cout << "            ####   ##    ##  ###   ##     ## #### ##  ###  #### ## " << endl;
	cout << "            ###    ##    ##  ###   ##     #### ####   ###  ####### " << endl;
	cout << "            ###    ##    ##  ###  ###      ### ####   ###  ## #### " << endl;
	cout << "            ###    ###  ###  ###  ###      ###  ##    ###  ## #### " << endl;
	cout << "            ###     ######    ######        ##  ##    ###  ##  ### " << endl;
}

void ShowLose()
{
	cout << "\n\n\n\n\n\n\n\n";
	cout << "         ##       ##  #####   ###   ##     ###      ######    ######  ####### " << endl;
	cout << "           ##    ##  ###  ##  ###   ##     ###     ###   ##  ###      ###     "<< endl;
	cout << "            ## ##   ##    ##  ###   ##     ###     ##    ##  ###      ###     " << endl;
	cout << "             ###    ##    ##  ###   ##     ###     ##    ##   ####    ####### " << endl;
	cout << "             ###    ##    ##  ###   ##     ###     ##    ##     ####  ###     " << endl;
	cout << "             ###    ##    ##  ###  ###     ###     ##    ##       ##  ###     " << endl;
	cout << "             ###    ###  ###  ###  ###     ###     ###  ###       ##  ###     " << endl;
	cout << "             ###     ######    ######      #######  ######   #######  ####### " << endl;

}