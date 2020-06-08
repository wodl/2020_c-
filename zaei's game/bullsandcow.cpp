#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstring>
#include <time.h>
#include <cstdlib>
#pragma warning(disable:4996)
using namespace std;

//�ܼ� ũ��
const int cols = 92;
const int lines = 26;

//Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ENTER 4

//�Լ� ����
void Init();
int keyControl();
int menuDraw();
void gotoxy(int, int);
void titleDraw();
int EndDraw();
void ScreenPause();
void ShowLose();
void ShowWin();

//���� �߱� �ڵ� '1'
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

	//��������
	void DrawTurn()
	{
		gotoxy(39, 7);
		cout << "# round " << round+1 << " #";

		for (int i = 0; i < level; i++)
		{	
			// _ _ _ , _ _ _ _ ǥ��
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
				while (!(cin>>n) )		 //���ھƴϸ� �����ϰ� ���Է�
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
						cout << "�� �ߺ��� ���ڴ� �ԷºҰ����մϴ�.";
						gotoxy(cols / level * i + 8, 15);
						cout << "_        ";
						goto TryCin;
					}
				}
				if (n < 10 && n >= 0)	//1-10���̸� m[][]�� �����ϰ� break;
				{
					m[round][i] = n;
					break;
				}
				else
				{
					cin.clear();
					cin.ignore();
					gotoxy(50, 23);
					cout << "�� 0���� 9������ ���ڸ� �Է��Ͻʽÿ�.";
					gotoxy(cols / level * i + 8, 15);
					cout << "_        ";
				}
			}
		}

		//��,��Ʈ����ũ,�ƿ� ���
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

	//���ӳ��̵� �޴�
	void LevelDraw()
	{
		int x = 38, y = 12;
		gotoxy(35, 7);
		cout << "[ �� �� �� �� �� ]";
		gotoxy(38, 12);
		cout << "�� NORMAL";
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
					cout << "��";
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
					cout << "��";
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

	//�ߺ����� ��������
	void MakeRand()
	{
		srand((unsigned int)time(NULL));
		int bFound;

		a = new int[level];
		for (int i = 0; i < level; i++)
		{
			while (1)
			{
				a[i] = rand() % 10 + 1;		//1~10������ ��������
				bFound = 0;					//������ �ִ��� Ȯ�ο�
				for (int j = 0; j < i; j++)	//�ߺ�üũ
				{
					if (a[j] == a[i])
					{
						bFound = 1;	//�ߺ������� bFound=1
						break;
					}
				}
				if (!bFound)	//1(������)�� �ƴϸ� while�� Ż��
					break;
			}
		}
	}

	//������ӻ�Ȳ
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

	//���ӹ�� �Ұ�
	void ShowManual()
	{
		gotoxy(38, 7);
		cout << "[ �� �� �� �� ]";
		gotoxy(10, 10);
		cout << "'���ھ߱�'�� �� 9��2�ƿ����� ���̰� ���ϴ� 3/4�ڸ��� ���ڸ� ���ߴ� �����̴�.";
		gotoxy(10, 12);
		cout << "- NORMAL���� 3��, HARD���� 4���� ���ڸ� ����Ѵ�. ";
		gotoxy(10, 14);
		cout << "- ���Ǵ� ���ڴ� 0���� 9���� ���� �ٸ� �����̴�.";
		gotoxy(10, 16);
		cout << "- ���ڴ� ������ ��ġ�� Ʋ���� ��� ��[B], ���ڿ� ��ġ�� ���� ��Ʈ����ũ[S],";
		gotoxy(10, 17);
		cout << "  ���ڿ� ��ġ�� ���� Ʋ���� �ƿ�[OUT].";
		ScreenPause();
	}

	//�Ҹ���
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
		case 1:	//���ھ߱�
		{
			
			game1.play();
			ScreenPause();
			system("cls");
			menu = menuDraw();
		}
		break;
		case 2:


		case 3:	//����
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

//�ܼ� ũ�� �ʱ�ȭ �Լ�
void Init()
{
	system("mode con cols=92 lines=26 | title ������ ���� ");
}

//���ӽ���ȭ��
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
	
	system("cls");	//�ܼ�â ��� ���� ���
}

//���ʹ����������� ȭ�����
void ScreenPause()	//���ʹ����������� ȭ�����
{
	while (1)	
	{
		if (keyControl() == ENTER)
			break;

	}
}

//�޴�	
int menuDraw()
{
	system("cls");
	int x = 38, y = 10;
	gotoxy(x, 5);
	cout << " [ �� �� ]"<<endl;
	gotoxy(x - 2, y);	//10 2
	cout << "> �� �� �� �� " << endl;
	gotoxy(x, y+5);		//15 3 
	cout << " �� �� �� ";
	gotoxy(x, y+5*2);	//20 4
	cout << "  �� �� ";
	
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP: 
		{
			if (y > (lines * 2 / 5))	//y�� '���ھ߱�'���� ���� ������� (Ŀ���� �̵����� ����)
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
			if (y < (lines * 4 / 5))	//y�� '����'���� �Ʒ��� ������� (Ŀ���� �̵����� ����)
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

//����Ű,���� �Է¹޴� �Լ�
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

//Ŀ�� ��ġ �̵��Լ�
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
	cout << "������ �����Ͻðڽ��ϱ�?";
	gotoxy(28, 15);
	cout << "yes";
	gotoxy(60, 15);
	cout << "no";
	gotoxy(28, 16);
	cout << "��";

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
				cout << "��";
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
				cout << "��";
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