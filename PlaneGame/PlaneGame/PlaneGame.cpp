//引入项目中所需头文件

#include <graphics.h>	//导入EasyX中的图形库
#include <conio.h>		//控制台输入输出，用于打印游戏分数
#include <cmath>			//用于计算绝对值，检测碰撞情况
#include <iostream>		//C++标准输入输出头文件
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS		//关闭不安全函数警告

//定义游戏画面尺寸
#define High 700
#define Width 550

//抽象我方飞机类(以下简称我机)
class Plane {
public:
	//我机位置
	double x;
	double y;
};

//抽象敌方飞机类(以下简称敌机)
class Enemy {
public:
	//敌机位置
	double x;
	double y;
};

//抽象子弹类(以下简称子弹)
class Bullet {
public:
	//子弹位置
	double x;
	double y;
};

//定义游戏中所出现的图片素材变量等全局变量
IMAGE background;			//定义背景图片变量
IMAGE plane1, plane2;		//定义我机图片变量
IMAGE explode1, explode2;	//定义爆炸图片变量
IMAGE enemy1, enemy2;		//定义敌机图片变量
IMAGE bullet1, bullet2;		//定义子弹图片变量
bool isGameover = false;	//定义游戏结束变量
int score = 0;				//定义分数记录变量
Plane plane;				//定义一个我机实例
Enemy enemy[3];				//定义三个敌机实例
Bullet bullet;				//定义一个子弹实例

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

	//游戏画布初始化
	initgraph(Width, High);

	//加载背景图片
	loadimage(&background, "../source/background.jpg");

	//加载我机图片
	loadimage(&plane1, "../source/plane1.jpg");
	loadimage(&plane2, "../source/plane2.jpg");

	//加载爆炸图片
	loadimage(&explode1, "../source/explode1.jpg");
	loadimage(&explode2, "../source/explode2.jpg");

	//加载敌机图片
	loadimage(&enemy1, "../source/enemy1.jpg");
	loadimage(&enemy2, "../source/enemy2.jpg");

	//加载子弹图片
	loadimage(&bullet1, "../source/bullet1.jpg");
	loadimage(&bullet2, "../source/bullet2.jpg");

	//初始化我机位置,使得我机处在屏幕中间偏下的位置
	plane.x = Width * 0.5;
	plane.y = High * 0.7;

	//初始化子弹位置
	bullet.x = plane.x;
	bullet.y = -150;

	//初始化敌机位置
	for (auto i = 0; i < 3; i++) {

		//第一个飞机位置确定，
		if (i == 0) {
			enemy[i].x = plane.x;
			enemy[i].y = 10;
		}

		//其他飞机位置的横坐标随机生成，从坐标根据前一个飞机的位置确定
		else {
			enemy[i].x = rand() % Width - 50.0;
			enemy[i].y = enemy[(i + 2) % 3].y-150.0;
		}
	}

	BeginBatchDraw();		//开始批处理绘制，以处理闪屏现象
	
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