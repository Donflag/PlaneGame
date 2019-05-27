//引入项目中所需头文件

#include <graphics.h>	//导入EasyX中的图形库
#include <conio.h>		//控制台输入输出，用于打印游戏分数
#include <cmath>			//用于计算绝对值，检测碰撞情况
#include <iostream>		//C++标准输入输出头文件
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS		//关闭不安全函数警告

//调用windows api,播放音乐时使用
#pragma comment(lib,"Winmm.lib")

//定义游戏画面尺寸
#define High 700
#define Width 550

//抽象移动体
class mover {
public:
	//我机位置
	double x;
	double y;
};
//抽象我方飞机类(以下简称我机)
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

//抽象敌方飞机类(以下简称敌机)
class Enemy :public mover {
public:
	//敌机自然下落
	void down() {
		if (y < High - 25) {
			y = y + 1;
		}
	}
};

//抽象子弹类(以下简称子弹)
class Bullet :public mover {
public:
	//子弹自然上升
	void up() {
		if (y > -25) {
			y = y - 4;
		}
	}
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
	while (isGameover==0)		//正常游戏
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

	//加载背景音乐
	mciSendString("open ../source/bgm.mp3 alias bgm",NULL,0,NULL);
	//背景音乐循环播放
	mciSendString("play bgm repeat", NULL, 0, NULL);
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
	bullet.x = -300;
	bullet.y = High * 0.7-100.0;

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
			enemy[i].y = enemy[(i + 2) % 3].y-170.0;
		}
	}

	//开始批处理绘制，以处理闪屏现象
	BeginBatchDraw();		
	
}

//定义展示游戏界面函数
void Show() {

	//显示背景图片
	putimage(0, 0, &background);

	//正常游戏状态
	if (isGameover == false) {
		//显示我机
		putimage(plane.x-50.0, plane.y-60.0, &plane1, NOTSRCERASE);
		putimage(plane.x-50.0, plane.y-60.0, &plane2, SRCINVERT);

		//显示敌机
		for (auto i = 0; i < 3; i++) {
			putimage(enemy[i].x, enemy[i].y,&enemy1, NOTSRCERASE);
			putimage(enemy[i].x, enemy[i].y,&enemy2, SRCINVERT);
		}

		//显示子弹
		putimage(bullet.x, bullet.y, &bullet1, NOTSRCERASE);
		putimage(bullet.x, bullet.y, &bullet2, SRCINVERT);

	}
	//游戏结束状态
	else {
		//显示爆炸飞机
		putimage(plane.x - 50.0, plane.y - 60.0, &explode1, NOTSRCERASE);
		putimage(plane.x - 50.0, plane.y - 60.0, &explode2 , SRCINVERT);
	}
	
	//推送绘制的批处理
	outtextxy(Width*0.88, 0, "得分：");
	char s[5];
	sprintf_s(s, "%d", score);
	outtextxy(Width*0.95, 0, s);
	FlushBatchDraw();
	Sleep(3);
}

//定义处理与输入无关的数据更新函数
void WithoutInput() {

	//正常游戏状态
	if (isGameover == false) {

		//敌机自然下落
		for (auto i = 0; i < 3; i++) {
			enemy[i].down();
			if (enemy[i].y >= 650) {
				isGameover = true;
			}
		}

		//子弹自然上升
		bullet.up();

		//敌机被击毁后重新生成
		for (auto i = 0; i < 3; i++) {
			//检测每个敌机与子弹的距离
			if (fabs(enemy[i].x - bullet.x) + fabs(enemy[i].y - bullet.y) < 100) {
				//增加游戏分数
				score++;
				//随机生成敌机的坐标
				enemy[i].x = rand() % Width - 50.0;
				enemy[i].y = enemy[(i + 2) % 3].y - 170.0;

				//暂时隐藏子弹
				bullet.y = -1000;
			}
		}
		//敌机与我机碰撞
		for (auto i = 0; i < 3; i++) {
			if (fabs(enemy[i].x - plane.x) + fabs(enemy[i].y - plane.y) < 200) {
				//敌机与我机碰撞，游戏结束
				isGameover = true;
			}
		}
	}
}
//定义处理与输入有关的数据更新函数
void WithInput() {

	//正常游戏状态
	if (isGameover == false) {	
		//鼠标监听输入部分

		//定义鼠标消息
		MOUSEMSG message;
		//当鼠标有消息产生时
		if (MouseHit()) {
			//获取鼠标产生的消息
			message = GetMouseMsg();
			//如果鼠标在移动
			if (message.uMsg == WM_MOUSEMOVE) {
				//更新飞机位置为鼠标位置
				plane.x = message.x;
				plane.y = message.y;
			}
			//如果按下鼠标左键
			else if (message.uMsg == WM_LBUTTONDOWN) {
				//更新子弹位置为鼠标位置
				bullet.x = message.x;
				bullet.y = message.y;
			}
		}
		//键盘监听输入部分
		
		//如果键盘有输入
		char input;
		if (_kbhit()) {
			input = _getch();
			//向上移动
			if (input == 'W' || input == 'w') {
				plane.up();
			}
			//向下移动
			else if (input == 'S' || input == 's') {
				plane.down();
			}
			//向左移动
			else if (input == 'A' || input == 'a') {
				plane.left();
			}
			//向右移动
			else if (input == 'D' || input == 'd') {
				plane.right();
			}
			//发射子弹
			else if (input == ' ') {
				bullet.x = plane.x-15;
				bullet.y = plane.y-80;
			}
		}
	}
}

//定义处理游戏结束后功能的函数
void GameOver() {
	mciSendString("close bgm", NULL, 0, NULL);
	putimage(plane.x - 50.0, plane.y - 60.0, &explode1, NOTSRCERASE);
	putimage(plane.x - 50.0, plane.y - 60.0, &explode2, SRCINVERT);
	EndBatchDraw();
	_getch();
	closegraph();
}