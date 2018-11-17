// 魔塔课设2。0.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <conio.h>
#include <graphics.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include "标头.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace std;
//#include "map.h"

int map_[5][13][13] = {
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 9, 1, 2, 3, 2, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 8, 1, 1, 16, 1, 0, 5, 6, 1, 0, 1, 0 },
		{ 0, 1, 12, 1, 0, 1, 0, 4, 8, 1, 0, 1, 0 },
		{ 0, 0, 16, 0, 0, 1, 0, 0, 0, 16, 0, 1, 0 },
		{ 0, 6, 1, 1, 0, 1, 16, 10, 11, 10, 0, 1, 0 },
		{ 0, 1, 13, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 16, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 0, 0, 16, 0, 0, 0, 16, 0, 0 },
		{ 0, 8, 1, 6, 0, 6, 1, 6, 0, 1, 10, 1, 0 },
		{ 0, 8, 1, 6, 0, 1, 18, 1, 0, 2, 14, 2, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 7, 4, 0, 7, 14, 7, 0, 1, 0, 1, 8, 0 },
        { 0, 1 ,8,0,14,7,14,0,1,17,10,1, 0 },
		{ 0, 11,1,0,7,6,7,0,1,0,0,0, 0 },
		{ 0, 17,0,0,0,1,0,0,1,0,1,1, 0 },
		{ 0, 1,1,10,1,1,1,2,1,1,1,1, 0 },
		{ 0, 17,0,0,1,1,1,0,1,0,0,0, 0 },
		{ 0, 12,1,0,0,1,0,0,1,0,1,8, 0 },
		{ 0, 1,7,0,1,1,1,0,1,17,11,7, 0 },
		{ 0, 8,5,0,1,1,1,0,1,0,0,0, 0 },
		{ 0, 0,0,0,0,1,0,0,3,0,1,1, 0 },
		{ 0, 15,18,1,1,1,1,0,1,17,1,9, 0 },
		
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 19,3,7,0,8,8,8,0,0,0,0, 0 },
		{ 0, 3,7,1,0,1,1,1,0,1,10,1, 0 },
		{ 0, 7,12,1,0,0,17,0,0,1,0,1, 0 },
		{ 0, 0,17,0,0,1,12,1,0,7,0,3, 0 },
		{ 0, 1,1,1,0,0,0,1,0,7,0,10, 0 },
		{ 0, 2,0,1,10,3,10,1,0,7,0,3, 0 },
		{ 0, 2,0,0,10,1,0,1,1,1,0,1, 0 },
		{ 0, 1,1,1,1,1,0,0,17,0,0,1, 0 },
		{ 0, 0,0,0,0,10,0,3,1,3,0,1, 0 },
		{ 0, 0,1,1,1,1,0,4,10,7,0,1, 0 },
		{ 0, 15,18,0,0,0,0,5,14,7,0,9, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0,1,1,12,17,1,15,1,17,2,1,8, 0 },
		{ 0, 1,7,1,0,1,18,1,0,1,2,1, 0 },
		{ 0, 13,0,0,0,0,16,0,0,0,0,1, 0 },
		{ 0,1,7,1,0,7,1,7,17,17,1,1, 0 },
		{ 0, 4,1,10,17,1,5,1,0,0,0,0, 0 },
		{ 0, 0,0,0,0,0,0,3,0,1,1,13, 0 },
		{ 0, 7,0,17,13,7,0,1,0,20,0,1, 0 },
		{ 0, 13,1,0,1,1,0,1,0,0,0,17, 0 },
		{ 0, 17,0,0,0,17,0,1,0,7,1,11, 0 },
		{ 0, 1,8,0,1,12,0,10,0,1,12,1, 0 },
		{ 0, 9,1,16,1,1,17,1,17,11,1,8, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 14, 1, 14, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 1, 1, 1, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 1, 1, 1, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }}
};

struct monster
{
	int 血量;
	int 攻击;
	int 防御;
	int 经验;
};

struct gamerole
{
	char name[20] = { "勇士" };
	int x, y;
	int 血量;
	int 蓝量;
	int 防御;
	int 攻击;
	int 蓝钥匙;
	int 黄钥匙;
	int 等级;
	int 经验;
};

TCHAR str[100] = "";
//整数转换为字符
char *inttoWchar(int Number)
{
	_stprintf_s(str, "%d", Number);
	return str;
}

HWND hwnd;
int map[13][13];
time_t start, now;
//class Game
//{   
int floor1, game;

bool can;
bool flag, flag_boss;
IMAGE 墙, 地板, 绿史莱姆, 红史莱姆, 剑, 盾, 蓝水晶, 红水晶,
      蓝钥匙, 黄钥匙, 小红药水, 上梯子, 小蝙蝠, 小巫师, 骷髅兵, 
	  大骷髅兵, 小蓝药水, 蓝门, 黄门, 信息, 人,大魔王,下楼梯;

gamerole role;

struct monster 绿史莱姆属性 = { 100, 15, 2, 100 };
struct monster 红史莱姆属性 = { 100, 25, 0, 100 };
struct monster 小蝙蝠属性 = { 100, 40, 10, 100 };
struct monster 骷髅兵属性 = { 200,60,20,200 };
struct monster 大骷髅兵属性 = { 250,80,25,250 };
struct monster 小巫师属性 = { 100,50,10,300 };
struct monster 大魔王属性 = { 4000,150,110,10000 };
//
void welcome();
void userInfo();
void initgame();
void initGame();
void playGame();
bool isgameover();
void up_down();
void end();
void bloodPK(struct monster);
void open_file();


void bloodPK(struct monster 怪物)
{
	can = 0;
	//属性加成
	int 血 = role.血量 + role.血量*role.蓝量 / 100;
	int 防 = role.防御 + role.防御*role.蓝量 / 100;
	int 攻 = role.攻击 + role.攻击*role.蓝量 / 100;

	//双方伤害
	int hero = 怪物.攻击 - 防;
	int mons = 攻 - 怪物.防御;

	if (mons > 0 && hero <= 0) {
		can = true;
		return;
	}
	if (mons <= 0 && hero > 0) {
		can = false;
		return;
	}
	if (hero > 0 && mons > 0) 
	{
		//回合数量
		int num1 = 血 / hero + 1;
		int num2 = 怪物.血量 / mons + 1;

		if(role.蓝量>=5)
		   role.蓝量 -= 5;
		else role.蓝量 = 0;
		if (num1 >= num2)
		{
			can = true;
			role.血量 -= (num2 - 1)*hero;
			role.经验 += 怪物.经验;
		}
		else role.血量 = 0;
	}

}

void initgame()
{
	loadimage(&墙, "墙.jpg", 60, 60);
	loadimage(&地板, "地板.jpg", 60, 60);
	loadimage(&绿史莱姆, "绿史莱姆.jpg", 60, 60);
	loadimage(&红史莱姆, "红史莱姆.jpg", 60, 60);
	loadimage(&蓝水晶, "蓝水晶.jpg", 60, 60);
	loadimage(&红水晶, "红水晶.jpg", 60, 60);
	loadimage(&蓝钥匙, "蓝钥匙.jpg", 60, 60);
	loadimage(&黄钥匙, "黄钥匙.jpg", 60, 60);
	loadimage(&小红药水, "小红药水.jpg", 60, 60);
	loadimage(&上梯子, "梯子.jpg", 60, 60);
	loadimage(&下楼梯, "下楼.JPG", 60, 60);
	loadimage(&小蝙蝠, "小蝙蝠.jpg", 60, 60);
	loadimage(&小巫师, "小巫师.jpg", 60, 60);
	loadimage(&骷髅兵, "骷髅兵.jpg", 60, 60);
	loadimage(&大骷髅兵, "大骷髅兵.jpg", 60, 60);
	loadimage(&小蓝药水, "小蓝药水.jpg", 60, 60);
	loadimage(&蓝门, "蓝门.jpg", 60, 60);
	loadimage(&黄门, "黄门.jpg", 60, 60);
	loadimage(&人, "人.jpg", 60, 60);
	loadimage(&盾, "盾.jpg", 60, 60);
	loadimage(&剑, "剑.jpg", 60, 60);
	loadimage(&大魔王, "大魔王.jpg", 60, 60);
	loadimage(&信息, "info.jpg");
}

int main()
{
	mciSendString("open 背景.mp3", 0, 0, 0);	//打开音乐
	mciSendString("play 背景.mp3", 0, 0, 0);	//播放音乐
	mciSendString("play 背景.mp3 repeat", 0, 0, 0);

	userInfo();
	initgraph(60 * 14, 60 * 13);
	welcome();
	initgame();

	open_file();
	initGame();//初始化游戏,构建最初的图像
	playGame();

	end();
	Sleep(6000);
	closegraph();
	return 0;
}

void end()
{
	for (int i = 0; i < 14; i++) 
	{
		for (int j = 0; j < 13; j++) 
		{
			putimage(i * 60, j * 60, &墙);
		}
	}

	settextstyle(80,0, "黑体");
	setfillcolor(BLUE);
	if (game == 1) 
	{
		mciSendString("open 胜利.mp3", 0, 0, 0);	//打开音乐
		mciSendString("play 胜利.mp3", 0, 0, 0);	//播放音乐
		
		fillrectangle(250, 250, 720, 600);
		outtextxy(350, 300, "星辰大海");
		outtextxy(300, 400, "任君翱翔");
	}
	else {
		mciSendString("open 失败.mp3", 0, 0, 0);	//打开音乐
		mciSendString("play 失败.mp3", 0, 0, 0);	//播放音乐

		fillrectangle(250, 250, 720, 600);
		outtextxy(350, 300, "胜败常事");
		outtextxy(300, 400, "屡败屡战");
	}
}

void welcome() 
{
	IMAGE img;
	loadimage(&img, "wel.jpg", 60 * 14, 60 * 13,false);
	putimage(0, 0, &img);

	setbkmode(TRANSPARENT);
	// 实现闪烁的"按任意键继续"
	int c = 255;
	while (!_kbhit())
	{
		settextcolor(RGB(0, c, 0));
		outtextxy(360, 500, "按空格键继续");
		outtextxy(350, 600, "按R/r重新开始\n");
		outtextxy(350, 650, "按V/v存档\n");
		outtextxy(350, 700, "按Q/q读档\n");

		c -= 8;
		if (c < 0)
			c = 255;
		Sleep(20);
	}
	cleardevice();
}

void saved()
{
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			map_[floor1 - 1][i][j] = map[i][j];
		}
	}
	ofstream outFile;
	outFile.open("save.txt");
	outFile.clear();
	outFile << 'Y' << endl;
	for (int k = 0; k < 5; k++) {

		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {
				outFile << map_[k][i][j] << ' ';
			}
			outFile << endl;
		}
	}
	outFile << role.name << endl;
	outFile << role.x << ' ' << role.y << endl;
	outFile << role.等级 << ' ' << role.防御 << '\n';
	outFile << role.攻击 << ' ' << role.黄钥匙 << '\n';
	outFile << role.经验 << ' ' << role.蓝量 << '\n';
	outFile << role.蓝钥匙 << ' ' << role.血量 << endl;
	outFile << floor1;
	outFile.close();
}

void open_file()
{
	HWND hWnd = GetHWnd();
	ifstream Infile;
	ofstream outFile;

	Infile.open("save.txt");
	if (!Infile.is_open())
	{
		int ret = MessageBox(hWnd, TEXT("读取存档失败，是否忽略继续游戏？"), TEXT("选择"), MB_YESNO | MB_ICONQUESTION);
		if (ret == IDYES)
		{
			return;
		}
		else {
			exit(EXIT_FAILURE);
		}
	}
	char ch;
	Infile >> ch;
	if (ch == 'Y') 
	{
		int ret = MessageBox(hWnd, TEXT("读取存档成功 ，是否从存档处继续？"), TEXT("选择"), MB_YESNO | MB_ICONQUESTION);
		if (ret == IDYES)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 13; j++)
					{
						int a;
						Infile >> a;
						map_[k][i][j] = a;
					}
				}
			}
		}
		Infile >> role.name;
		Infile >> role.x >> role.y;
		Infile >> role.等级 >> role.防御;
		Infile >> role.攻击 >> role.黄钥匙;
		Infile >> role.经验 >> role.蓝量;
		Infile >> role.蓝钥匙 >> role.血量;
		int f;
		Infile >> f; 
		floor1 = f;
		flag_boss = false;
        for (int i = 0; i < 13; i++) 
    	{
	    	for (int j = 0; j < 13; j++) 
	    	{
	    		map[i][j] = map_[floor1-1][i][j];
	    	}
    	}
	}

	outFile.open("save.txt");
	outFile.clear();
	outFile.close();
	Infile.close();
	
}

void userInfo()
{
	//初始化角色信息
	role.攻击 = 10;
	role.防御 = 10;
	role.等级 = 1;
	role.经验 = 0;
	role.黄钥匙 = 0;
	role.蓝钥匙 = 2;
	role.血量 = 1500;
	role.蓝量 = 0;

	flag_boss = false;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			map[i][j] = map_[0][i][j];
		}
	}
}

void up_down()
{
	if (floor1 > 0 && floor1 < 6)
	{
		if (flag == 1)
		{
			for (int i = 0; i < 13; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					map_[floor1 - 1][i][j] = map[i][j];
					map[i][j] = map_[floor1][i][j];
				}
			}
		}
		else {
			for (int i = 0; i < 13; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					map_[floor1 + 1][i][j] = map[i][j];
					map[i][j] = map_[floor1][i][j];
				}
			}
		}
	}

}

void initGame()
{
	int i, j;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			switch (map[i][j])
			{
			case 0:
				putimage(j * 60, i * 60, &墙);
				break;
			case 1:
				putimage(j * 60, i * 60, &地板);
				break;
			case 2:
				putimage(j * 60, i * 60, &绿史莱姆);
				break;
			case 3:
				putimage(j * 60, i * 60, &红史莱姆);
				break;
			case 4:
				putimage(j * 60, i * 60, &蓝水晶);
				break;
			case 5:
				putimage(j * 60, i * 60, &红水晶);
				break;
			case 6:
				putimage(j * 60, i * 60, &蓝钥匙);
				break;
			case 7:
				putimage(j * 60, i * 60, &黄钥匙);
				break;
			case 8:
				putimage(j * 60, i * 60, &小红药水);
				break;
			case 9:
				putimage(j * 60, i * 60, &上梯子);
				break;
			case 10:
				putimage(j * 60, i * 60, &小蝙蝠);
				break;
			case 11:
				putimage(j * 60, i * 60, &小巫师);
				break;
			case 12:
				putimage(j * 60, i * 60, &骷髅兵);
				break;
			case 13:
				putimage(j * 60, i * 60, &大骷髅兵);
				break;
			case 14:
				putimage(j * 60, i * 60, &小蓝药水);
				break;
			case 15:
				putimage(j * 60, i * 60, &下楼梯);
				break;
			case 16:
				putimage(j * 60, i * 60, &蓝门);
				break;
			case 17:
				putimage(j * 60, i * 60, &黄门);
				break;
			case 18:
				putimage(j * 60, i * 60, &人);
				break;
			case 19:
				putimage(j * 60, i * 60, &剑);
				break;
			case 20:
				putimage(j * 60, i * 60, &盾);
				break;
			case 21:
				putimage(j * 60, i * 60, &大魔王);
				break;
			}
		}
	}
	//显示信息
	putimage(60 * 13, 0, &信息);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT); //设置背景透明
	outtextxy(60 * 13 + 12, 100, role.name);
	outtextxy(60 * 13 + 12, 180, inttoWchar(role.等级));
	outtextxy(60 * 13 + 12, 235, inttoWchar(role.经验));
	outtextxy(60 * 13 + 12, 362, inttoWchar(role.血量));
	outtextxy(60 * 13 + 12, 425, inttoWchar(role.蓝量));
	outtextxy(60 * 13 + 12, 517, inttoWchar(role.攻击));
	outtextxy(60 * 13 + 12, 567, inttoWchar(role.防御));
	outtextxy(60 * 13 + 12, 689, inttoWchar(role.黄钥匙));
	outtextxy(60 * 13 + 12, 759, inttoWchar(role.蓝钥匙));
}

bool isgameover()
{

	if (flag_boss)
	{
		game = 1;
		return true;
	}
	else if (role.血量 == 0) {
		game = 2;
		return true;
	}
	return false;
}

void playGame()
{
	char cUser; //用来接收用户按键
	int i = 0, j = 0;
	while (1)
	{
		hwnd = GetHWnd();
		if (isgameover())break;
		for (i = 0; i < 13; i++)
		{
			for (j = 0; j < 13; j++)
			{
				if (map[i][j] == 18)
					break;
			}
			if (map[i][j] == 18)
				break;//只能跳出一次循环
		}
		initGame();
		cUser = _getch(); //使用不可见输入 getch(); getchar()
		switch (cUser)
		{
			//左边
			//方向键:上:72;下:80:左:75;右:77;
		case 75:
		case'a':
		case'A':
			if (map[i][j - 1] == 1)
			{
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 17;
			}

			else if (map[i][j - 1] == 2)
			{
				int ID = MessageBox(hwnd, "遇到绿史莱姆", "是否攻击?", MB_YESNO);
				bloodPK(绿史莱姆属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j - 1] += 16;
				}
			}

			else if (map[i][j - 1] == 3)
			{
				int ID = MessageBox(hwnd, "遇到红史莱姆", "是否攻击?", MB_YESNO);
				bloodPK(红史莱姆属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j - 1] += 15;
				}
			}
			else if (map[i][j - 1] == 4)
			{
				role.防御 += 5;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 14;
			}
			else if (map[i][j - 1] == 5)
			{
				role.攻击 += 5;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 13;
			}
			else if (map[i][j - 1] == 6)
			{
				role.蓝钥匙++;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 12;
			}
			else if (map[i][j - 1] == 7)
			{
				role.黄钥匙++;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 11;
			}
			else if (map[i][j - 1] == 8)
			{
				role.血量 += 100;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 10;
			}
			else if (map[i][j - 1] == 9)
			{
				flag = 1;
				floor1++;
				up_down();
				initGame();
			}
			else if (map[i][j - 1] == 10)
			{
				int ID = MessageBox(hwnd, "遇到小蝙蝠", "是否攻击?", MB_YESNO);
				bloodPK(小蝙蝠属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j - 1] += 8;
				}
			}
			else if (map[i][j - 1] == 11)
			{
				int ID = MessageBox(hwnd, "遇到巫师", "是否攻击?", MB_YESNO);
				bloodPK(小巫师属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j - 1] += 7;
				}
			}
			else if (map[i][j - 1] == 12)
			{
				int ID = MessageBox(hwnd, "遇到骷髅兵", "是否攻击?", MB_YESNO);
				bloodPK(骷髅兵属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j - 1] += 6;
				}
			}
			else if (map[i][j - 1] == 13)
			{
				int ID = MessageBox(hwnd, "遇到大骷髅兵", "是否攻击?", MB_YESNO);
				bloodPK(大骷髅兵属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j - 1] += 5;
				}
			}
			else if (map[i][j - 1] == 14)
			{
				role.蓝量 += 10;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 4;
			}
			else if (map[i][j - 1] == 15)
			{
		    	flag = 0;
		    	floor1--;
	    		up_down();
	    		initGame();
			}
			else if (map[i][j - 1] == 16 && role.蓝钥匙 > 0)
			{
				role.蓝钥匙--;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 2;
			}
			else if (map[i][j - 1] == 17 && role.黄钥匙 > 0)
			{
				role.黄钥匙--;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] += 1;
			}
			else if (map[i][j - 1] == 19)
			{
				role.攻击 += 120;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] -= 1;
			}
			else if (map[i][j - 1] == 20)
			{
				role.防御 += 120;
				map[i][j] = map[i][j] - 17;
				map[i][j - 1] -= 2;
			}
			else if (map[i][j - 1] == 21)
			{
				int ID = MessageBox(hwnd, "大魔王来了", "是否攻击?", MB_YESNO);
				bloodPK(大魔王属性);
				if (ID == IDYES && can)
				{
					flag_boss = true;
					map[i][j] = map[i][j] - 17;
					map[i][j - 1] += 5;
				}
			}
			break;

		case 77:
		case'd':
		case'D':
			if (map[i][j + 1] == 1)
			{
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 17;
			}

			else if (map[i][j + 1] == 2)
			{
				int ID = MessageBox(hwnd, "遇到绿史莱姆", "是否攻击?", MB_YESNO);
				bloodPK(绿史莱姆属性);
				if (ID == IDYES)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j + 1] += 16;
				}
			}

			else if (map[i][j + 1] == 3)
			{
				int ID = MessageBox(hwnd, "遇到红史莱姆", "是否攻击?", MB_YESNO);
				bloodPK(红史莱姆属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j + 1] += 15;
				}
			}
			else if (map[i][j + 1] == 4)
			{
				role.防御 += 10;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 14;
			}
			else if (map[i][j + 1] == 5)
			{
				role.攻击 += 10;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 13;
			}
			else if (map[i][j + 1] == 6)
			{
				role.蓝钥匙++;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 12;
			}
			else if (map[i][j + 1] == 7)
			{
				role.黄钥匙++;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 11;
			}
			else if (map[i][j + 1] == 8)
			{
				role.血量 += 10;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 10;
			}
			else if (map[i][j + 1] == 9)
			{
				flag = 1;
				floor1++;
				up_down();
				initGame();
			}
			else if (map[i][j + 1] == 10)
			{
				int ID = MessageBox(hwnd, "遇到小蝙蝠", "是否攻击?", MB_YESNO);
				bloodPK(小蝙蝠属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j + 1] += 8;
				}
			}
			else if (map[i][j + 1] == 11)
			{
				int ID = MessageBox(hwnd, "遇到巫师", "是否攻击?", MB_YESNO);
				bloodPK(小巫师属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j + 1] += 7;
				}
			}
			else if (map[i][j + 1] == 12)
			{
				int ID = MessageBox(hwnd, "遇到骷髅兵", "是否攻击?", MB_YESNO);
				bloodPK(骷髅兵属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j + 1] += 6;
				}
			}
			else if (map[i][j + 1] == 13)
			{
				int ID = MessageBox(hwnd, "遇到大骷髅兵", "是否攻击?", MB_YESNO);
				bloodPK(大骷髅兵属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i][j + 1] += 5;
				}
			}
			else if (map[i][j + 1] == 14)
			{
				role.蓝量 += 10;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 4;
			}
			else if (map[i][j + 1] == 15)
			{
		    	flag = 0;
	     		floor1--;
	    		up_down();
	    		initGame();
			}
			else if (map[i][j + 1] == 16 && role.蓝钥匙 > 0)
			{
				role.蓝钥匙--;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 2;
			}
			else if (map[i][j + 1] == 17 && role.黄钥匙 > 0)
			{
				role.黄钥匙--;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] += 1;
			}
			else if (map[i][j + 1] == 19)
			{
				role.攻击 += 120;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] -= 1;
			}
			else if (map[i][j + 1] == 20)
			{
				role.防御 += 120;
				map[i][j] = map[i][j] - 17;
				map[i][j + 1] -= 2;
			}
			else if (map[i][j + 1] == 21)
			{
				int ID = MessageBox(hwnd, "大魔王来了", "是否攻击?", MB_YESNO);
				bloodPK(大魔王属性);
				if (ID == IDYES && can)
				{
					flag_boss = true;
					map[i][j] = map[i][j] - 17;
					map[i][j + 1] += 5;
				}
			}
			break;
			//上边
		case 72:
		case'w':
		case'W':
			if (map[i - 1][j] == 1)
			{
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 17;
			}

			else if (map[i - 1][j] == 2)
			{
				int ID = MessageBox(hwnd, "遇到绿史莱姆", "是否攻击?", MB_YESNO);
				bloodPK(绿史莱姆属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i - 1][j] += 16;
				}
			}

			else if (map[i - 1][j] == 3)
			{
				int ID = MessageBox(hwnd, "遇到红史莱姆", "是否攻击?", MB_YESNO);
				bloodPK(红史莱姆属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i - 1][j] += 15;
				}
			}
			else if (map[i - 1][j] == 4)
			{
				role.防御 += 10;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 14;
			}
			else if (map[i - 1][j] == 5)
			{
				role.攻击 += 10;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 13;
			}
			else if (map[i - 1][j] == 6)
			{
				role.蓝钥匙++;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 12;
			}
			else if (map[i - 1][j] == 7)
			{
				role.黄钥匙++;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 11;
			}
			else if (map[i - 1][j] == 8)
			{
				role.血量 += 10;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 10;
			}
			else if (map[i - 1][j] == 9)
			{
				flag = 1;
				floor1++;
				up_down();
				initGame();
			}
			else if (map[i - 1][j] == 10)
			{
				int ID = MessageBox(hwnd, "遇到小蝙蝠", "是否攻击?", MB_YESNO);
				bloodPK(小蝙蝠属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i - 1][j] += 8;
				}
			}
			else if (map[i - 1][j] == 11)
			{
				int ID = MessageBox(hwnd, "遇到巫师", "是否攻击?", MB_YESNO);
				bloodPK(小巫师属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i - 1][j] += 7;
				}
			}
			else if (map[i - 1][j] == 12)
			{
				int ID = MessageBox(hwnd, "遇到骷髅兵", "是否攻击?", MB_YESNO);
				bloodPK(骷髅兵属性);
				if (ID == IDYES)
				{
					map[i][j] = map[i][j] - 17;
					map[i - 1][j] += 6;
				}
			}
			else if (map[i - 1][j] == 13)
			{
				int ID = MessageBox(hwnd, "遇到大骷髅兵", "是否攻击?", MB_YESNO);
				bloodPK(大骷髅兵属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i - 1][j] += 5;
				}
			}
			else if (map[i - 1][j] == 14)
			{
				role.蓝量 += 10;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 4;
			}
			else if (map[i - 1][j] == 15)
			{
			flag = 0;
			floor1--;
			up_down();
			initGame();
			}
			else if (map[i - 1][j] == 16 && role.蓝钥匙 > 0)
			{
				role.蓝钥匙--;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 2;
			}
			else if (map[i - 1][j] == 17 && role.黄钥匙 > 0)
			{
				role.黄钥匙--;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] += 1;
			}
			else if (map[i - 1][j] == 19)
			{
				role.攻击 += 120;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] -= 1;
			}
			else if (map[i - 1][j] == 20)
			{
				role.防御 += 120;
				map[i][j] = map[i][j] - 17;
				map[i - 1][j] -= 2;
			}
			else if (map[i - 1][j] == 21)
			{
				int ID = MessageBox(hwnd, "大魔王来了", "是否攻击?", MB_YESNO);
				bloodPK(大魔王属性);
				if (ID == IDYES && can)
				{
					flag_boss = true;
					map[i][j] = map[i][j] - 17;
					map[i - 1][j] += 5;
				}
			}
			break;
			//下边
		case 80:
		case's':
		case'S':
			if (map[i + 1][j] == 1)
			{
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 17;
			}

			else if (map[i + 1][j] == 2)
			{
				int ID = MessageBox(hwnd, "遇到绿史莱姆", "是否攻击?", MB_YESNO);
				bloodPK(绿史莱姆属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i + 1][j] += 16;
				}
			}

			else if (map[i + 1][j] == 3)
			{
				int ID = MessageBox(hwnd, "遇到红史莱姆", "是否攻击?", MB_YESNO);
				bloodPK(红史莱姆属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i + 1][j] += 15;
				}
			}
			else if (map[i + 1][j] == 4)
			{
				role.防御 += 10;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 14;
			}
			else if (map[i + 1][j] == 5)
			{
				role.攻击 += 10;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 13;
			}
			else if (map[i + 1][j] == 6)
			{
				role.蓝钥匙++;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 12;
			}
			else if (map[i - 1][j] == 7)
			{
				role.黄钥匙++;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 11;
			}
			else if (map[i + 1][j] == 8)
			{
				role.血量 += 10;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 10;
			}
			else if (map[i + 1][j] == 9)
			{
				flag = 1;
				floor1++;
				up_down();
				initGame();
			}
			else if (map[i + 1][j] == 10)
			{
				int ID = MessageBox(hwnd, "遇到小蝙蝠", "是否攻击?", MB_YESNO);
				bloodPK(小蝙蝠属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i + 1][j] += 8;
				}
			}
			else if (map[i + 1][j] == 11)
			{
				int ID = MessageBox(hwnd, "遇到巫师", "是否攻击?", MB_YESNO);
				bloodPK(小巫师属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i + 1][j] += 7;
				}
			}
			else if (map[i + 1][j] == 12)
			{
				int ID = MessageBox(hwnd, "遇到骷髅兵", "是否攻击?", MB_YESNO);
				bloodPK(骷髅兵属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i + 1][j] += 6;
				}
			}
			else if (map[i + 1][j] == 13)
			{
				int ID = MessageBox(hwnd, "遇到大骷髅兵", "是否攻击?", MB_YESNO);
				bloodPK(大骷髅兵属性);
				if (ID == IDYES && can)
				{
					map[i][j] = map[i][j] - 17;
					map[i + 1][j] += 5;
				}
			}
			else if (map[i + 1][j] == 14)
			{
				role.蓝量 += 10;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 4;
			}
			else if (map[i + 1][j] == 15)
			{
	    		flag = 0;
	    		floor1--;
	    		up_down();
	    		initGame();
			}
			else if (map[i + 1][j] == 16 && role.蓝钥匙 > 0)
			{
				role.蓝钥匙--;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 2;
			}
			else if (map[i + 1][j] == 17 && role.黄钥匙 > 0)
			{
				role.黄钥匙--;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] += 1;
			}
			else if (map[i + 1][j] == 19)
			{
				role.攻击 += 120;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] -= 1;
			}
			else if (map[i + 1][j] == 20)
			{
				role.防御 += 120;
				map[i][j] = map[i][j] - 17;
				map[i + 1][j] -= 2;
			}
			else if (map[i + 1][j] == 21)
			{
				int ID = MessageBox(hwnd, "大魔王来了", "是否攻击?", MB_YESNO);
				bloodPK(大魔王属性);
				if (ID == IDYES && can)
				{
					flag_boss = true;
					map[i][j] = map[i][j] - 17;
					map[i + 1][j] += 5;
				}
			}
			break;
		case 'R':
		case 'r': 
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 13; j++) 
				{
					for (int k = 0; k < 13; k++) 
					{
						map_[i][j][k] = map_1[i][j][k];
					}
				}
			}
			userInfo();
			break;
		case 'V':
		case 'v':
			saved();
			break;
		/*case 'Q':
		case 'q':
			open_file();
			break;*/
		}
	}
	cleardevice();
}
