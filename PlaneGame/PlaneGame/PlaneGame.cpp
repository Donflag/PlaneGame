//������Ŀ������ͷ�ļ�

#include <graphics.h>	//����EasyX�е�ͼ�ο�
#include <conio.h>		//����̨������������ڴ�ӡ��Ϸ����
#include <cmath>			//���ڼ������ֵ�������ײ���
#include <iostream>		//C++��׼�������ͷ�ļ�
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS		//�رղ���ȫ��������

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