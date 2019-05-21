//������Ŀ������ͷ�ļ�

#include <graphics.h>	//����EasyX�е�ͼ�ο�
#include <conio.h>		//����̨������������ڴ�ӡ��Ϸ����
#include <cmath>			//���ڼ������ֵ�������ײ���
#include <iostream>		//C++��׼�������ͷ�ļ�
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS		//�رղ���ȫ��������

//������Ϸ����ߴ�
#define High 700
#define Width 550

//�����ҷ��ɻ���(���¼���һ�)
class Plane {
public:
	//�һ�λ��
	double x;
	double y;
};

//����з��ɻ���(���¼�Ƶл�)
class Enemy {
public:
	//�л�λ��
	double x;
	double y;
};

//�����ӵ���(���¼���ӵ�)
class Bullet {
public:
	//�ӵ�λ��
	double x;
	double y;
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
	while (true)		//������Ϸ
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
	bullet.x = plane.x;
	bullet.y = -150;

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
			enemy[i].y = enemy[(i + 2) % 3].y-150.0;
		}
	}

	BeginBatchDraw();		//��ʼ��������ƣ��Դ�����������
	
}

//����չʾ��Ϸ���溯��
void Show() {

}

//���崦���������޹ص����ݸ��º���
void WithoutInput() {

}

//���崦���������йص����ݸ��º���
void WithInput() {

}

//���崦����Ϸ�������ܵĺ���
void GameOver() {

}