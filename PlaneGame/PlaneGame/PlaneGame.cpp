//������Ŀ������ͷ�ļ�

#include <graphics.h>	//����EasyX�е�ͼ�ο�
#include <conio.h>		//����̨������������ڴ�ӡ��Ϸ����
#include <cmath>			//���ڼ������ֵ�������ײ���
#include <iostream>		//C++��׼�������ͷ�ļ�
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS		//�رղ���ȫ��������

//����windows api,��������ʱʹ��
#pragma comment(lib,"Winmm.lib")

//������Ϸ����ߴ�
#define High 700
#define Width 550

//�����ƶ���
class mover {
public:
	//�һ�λ��
	double x;
	double y;
};
//�����ҷ��ɻ���(���¼���һ�)
class Plane:public mover {
public:
	void up() {
		y = y - 20;
	}
	void down() {
		y = y + 20;
	}
	void left() {
		x = x - 20;
	}
	void right() {
		x = x + 20;
	}
};

//����з��ɻ���(���¼�Ƶл�)
class Enemy :public mover {
public:
	//�л���Ȼ����
	void down() {
		if (y < High - 25) {
			y = y + 1;
		}
	}
};

//�����ӵ���(���¼���ӵ�)
class Bullet :public mover {
public:
	//�ӵ���Ȼ����
	void up() {
		if (y > -25) {
			y = y - 4;
		}
	}
};

//������Ϸ�������ֵ�ͼƬ�زı�����ȫ�ֱ���
IMAGE background;			//���屳��ͼƬ����
IMAGE plane1, plane2;		//�����һ�ͼƬ����
IMAGE explode1, explode2;	//���屬ըͼƬ����
IMAGE enemy1, enemy2;		//����л�ͼƬ����
IMAGE bullet1, bullet2;		//�����ӵ�ͼƬ����
bool isGameover = false;	//������Ϸ��������
int score = 0;				//���������¼����
Plane plane;				//����һ���һ�ʵ��
Enemy enemy[3];				//���������л�ʵ��
Bullet bullet;				//����һ���ӵ�ʵ��

//���躯������
void Initdata();
void Show();
void WithInput();
void WithoutInput();
void GameOver();

//��Ϸ������
int main() {
	Initdata();			//���ݳ�ʼ��
	while (isGameover==0)		//������Ϸ
	{		
		Show();			//��ʾ��Ϸ����
		WithoutInput();	//���û������޹ص����ݸ���
		WithInput();	//���û������йص����ݸ���
	}
	GameOver();
	return 0;
}

//�������ݳ�ʼ������
void Initdata() {

	//���ر�������
	mciSendString("open ../source/bgm.mp3 alias bgm",NULL,0,NULL);
	//��������ѭ������
	mciSendString("play bgm repeat", NULL, 0, NULL);
	//��Ϸ������ʼ��
	initgraph(Width, High);

	//���ر���ͼƬ
	loadimage(&background, "../source/background.jpg");

	//�����һ�ͼƬ
	loadimage(&plane1, "../source/plane1.jpg");
	loadimage(&plane2, "../source/plane2.jpg");

	//���ر�ըͼƬ
	loadimage(&explode1, "../source/explode1.jpg");
	loadimage(&explode2, "../source/explode2.jpg");

	//���صл�ͼƬ
	loadimage(&enemy1, "../source/enemy1.jpg");
	loadimage(&enemy2, "../source/enemy2.jpg");

	//�����ӵ�ͼƬ
	loadimage(&bullet1, "../source/bullet1.jpg");
	loadimage(&bullet2, "../source/bullet2.jpg");

	//��ʼ���һ�λ��,ʹ���һ�������Ļ�м�ƫ�µ�λ��
	plane.x = Width * 0.5;
	plane.y = High * 0.7;

	//��ʼ���ӵ�λ��
	bullet.x = -300;
	bullet.y = High * 0.7-100.0;

	//��ʼ���л�λ��
	for (auto i = 0; i < 3; i++) {

		//��һ���ɻ�λ��ȷ����
		if (i == 0) {
			enemy[i].x = plane.x;
			enemy[i].y = 10;
		}

		//�����ɻ�λ�õĺ�����������ɣ����������ǰһ���ɻ���λ��ȷ��
		else {
			enemy[i].x = rand() % Width - 50.0;
			enemy[i].y = enemy[(i + 2) % 3].y-170.0;
		}
	}

	//��ʼ��������ƣ��Դ�����������
	BeginBatchDraw();		
	
}

//����չʾ��Ϸ���溯��
void Show() {

	//��ʾ����ͼƬ
	putimage(0, 0, &background);

	//������Ϸ״̬
	if (isGameover == false) {
		//��ʾ�һ�
		putimage(plane.x-50.0, plane.y-60.0, &plane1, NOTSRCERASE);
		putimage(plane.x-50.0, plane.y-60.0, &plane2, SRCINVERT);

		//��ʾ�л�
		for (auto i = 0; i < 3; i++) {
			putimage(enemy[i].x, enemy[i].y,&enemy1, NOTSRCERASE);
			putimage(enemy[i].x, enemy[i].y,&enemy2, SRCINVERT);
		}

		//��ʾ�ӵ�
		putimage(bullet.x, bullet.y, &bullet1, NOTSRCERASE);
		putimage(bullet.x, bullet.y, &bullet2, SRCINVERT);

	}
	//��Ϸ����״̬
	else {
		//��ʾ��ը�ɻ�
		putimage(plane.x - 50.0, plane.y - 60.0, &explode1, NOTSRCERASE);
		putimage(plane.x - 50.0, plane.y - 60.0, &explode2 , SRCINVERT);
	}
	
	//���ͻ��Ƶ�������
	outtextxy(Width*0.88, 0, "�÷֣�");
	char s[5];
	sprintf_s(s, "%d", score);
	outtextxy(Width*0.95, 0, s);
	FlushBatchDraw();
	Sleep(3);
}

//���崦���������޹ص����ݸ��º���
void WithoutInput() {

	//������Ϸ״̬
	if (isGameover == false) {

		//�л���Ȼ����
		for (auto i = 0; i < 3; i++) {
			enemy[i].down();
			if (enemy[i].y >= 650) {
				isGameover = true;
			}
		}

		//�ӵ���Ȼ����
		bullet.up();

		//�л������ٺ���������
		for (auto i = 0; i < 3; i++) {
			//���ÿ���л����ӵ��ľ���
			if (fabs(enemy[i].x - bullet.x) + fabs(enemy[i].y - bullet.y) < 100) {
				//������Ϸ����
				score++;
				//������ɵл�������
				enemy[i].x = rand() % Width - 50.0;
				enemy[i].y = enemy[(i + 2) % 3].y - 170.0;

				//��ʱ�����ӵ�
				bullet.y = -1000;
			}
		}
		//�л����һ���ײ
		for (auto i = 0; i < 3; i++) {
			if (fabs(enemy[i].x - plane.x) + fabs(enemy[i].y - plane.y) < 200) {
				//�л����һ���ײ����Ϸ����
				isGameover = true;
			}
		}
	}
}
//���崦���������йص����ݸ��º���
void WithInput() {

	//������Ϸ״̬
	if (isGameover == false) {	
		//���������벿��

		//���������Ϣ
		MOUSEMSG message;
		//���������Ϣ����ʱ
		if (MouseHit()) {
			//��ȡ����������Ϣ
			message = GetMouseMsg();
			//���������ƶ�
			if (message.uMsg == WM_MOUSEMOVE) {
				//���·ɻ�λ��Ϊ���λ��
				plane.x = message.x;
				plane.y = message.y;
			}
			//�������������
			else if (message.uMsg == WM_LBUTTONDOWN) {
				//�����ӵ�λ��Ϊ���λ��
				bullet.x = message.x;
				bullet.y = message.y;
			}
		}
		//���̼������벿��
		
		//�������������
		char input;
		if (_kbhit()) {
			input = _getch();
			//�����ƶ�
			if (input == 'W' || input == 'w') {
				plane.up();
			}
			//�����ƶ�
			else if (input == 'S' || input == 's') {
				plane.down();
			}
			//�����ƶ�
			else if (input == 'A' || input == 'a') {
				plane.left();
			}
			//�����ƶ�
			else if (input == 'D' || input == 'd') {
				plane.right();
			}
			//�����ӵ�
			else if (input == ' ') {
				bullet.x = plane.x-15;
				bullet.y = plane.y-80;
			}
		}
	}
}

//���崦����Ϸ�������ܵĺ���
void GameOver() {
	mciSendString("close bgm", NULL, 0, NULL);
	putimage(plane.x - 50.0, plane.y - 60.0, &explode1, NOTSRCERASE);
	putimage(plane.x - 50.0, plane.y - 60.0, &explode2, SRCINVERT);
	EndBatchDraw();
	_getch();
	closegraph();
}