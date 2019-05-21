//引入项目中所需头文件

#include <graphics.h>	//导入EasyX中的图形库
#include <conio.h>		//控制台输入输出，用于打印游戏分数
#include <cmath>			//用于计算绝对值，检测碰撞情况
#include <iostream>		//C++标准输入输出头文件
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS		//关闭不安全函数警告

//定义游戏画面尺寸
#define Canvas_High 700
#define Width 550

//定义游戏中所出现的图片素材变量等全局变量
IMAGE background;			//定义背景图片变量
IMAGE plane1, plane2;		//定义我机图片变量
IMAGE explode1, explode2;	//定义爆炸图片变量
IMAGE enemy1, enemy2;		//定义敌机图片变量
IMAGE bullet1, bullet2;		//定义子弹图片变量
bool isGameover = false;	//定义游戏结束变量
int score = 0;				//定义分数记录变量

//抽象我方飞机类(以下简称我机)
class Plane {
public :
	//我机位置
	float x;
	float y;
};

//抽象敌方飞机类(以下简称敌机)
class Enemy {
public:
	//敌机位置
	float x;
	float y;
};

//抽象子弹类(以下简称子弹)
class Bullet {
public:
	//子弹位置
	float x;
	float y;
};
//所需函数声明
void Initdata();
void Show();
void WithInput();
void WithoutInput();
void GameOver();

//游戏主函数
int main() {
	Initdata();			//数据初始化
	while (true)		//正常游戏
	{		
		Show();			//显示游戏画面
		WithoutInput();	//与用户输入无关的数据更新
		WithInput();	//与用户输入有关的数据更新
	}
	GameOver();
	return 0;
}

//定义数据初始化函数
void Initdata() {

}

//定义展示游戏界面函数
void Show() {

}

//定义处理与输入无关的数据更新函数
void WithoutInput() {

}

//定义处理与输入有关的数据更新函数
void WithInput() {

}

//定义处理游戏结束后功能的函数
void GameOver() {

}