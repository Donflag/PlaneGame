//������Ŀ������ͷ�ļ�

#include <graphics.h>	//����EasyX�е�ͼ�ο�
#include <conio.h>		//����̨������������ڴ�ӡ��Ϸ����
#include <cmath>			//���ڼ������ֵ�������ײ���
#include <iostream>		//C++��׼�������ͷ�ļ�
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS		//�رղ���ȫ��������

//������Ϸ����ߴ�
#define Canvas_High 700
#define Width 550

//������Ϸ�������ֵ�ͼƬ�زı�����ȫ�ֱ���
IMAGE background;			//���屳��ͼƬ����
IMAGE plane1, plane2;		//�����һ�ͼƬ����
IMAGE explode1, explode2;	//���屬ըͼƬ����
IMAGE enemy1, enemy2;		//����л�ͼƬ����
IMAGE bullet1, bullet2;		//�����ӵ�ͼƬ����
bool isGameover = false;	//������Ϸ��������
int score = 0;				//���������¼����

//�����ҷ��ɻ���(���¼���һ�)
class Plane {
public :
	//�һ�λ��
	float x;
	float y;
};

//����з��ɻ���(���¼�Ƶл�)
class Enemy {
public:
	//�л�λ��
	float x;
	float y;
};

//�����ӵ���(���¼���ӵ�)
class Bullet {
public:
	//�ӵ�λ��
	float x;
	float y;
};
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