#include<graphics.h>
#include<stdio.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
struct point {
	int x;
	int y;
};
IMAGE img[20], img_Big[20];
void InitImg()
{
	char buf[128];
	for (int i = 0; i < 20; i++)
	{
		sprintf(buf, "images\\%d.jpg", i + 1);
		loadimage(&img[i], buf, 40, 40);
		loadimage(&img_Big[i], buf, 310, 200);
	}
}
int main()
{
	mciSendString("open x.mp3", 0, 0, 0);
	mciSendString("play x.mp3", 0, 0, 0);
	HWND hwnd = initgraph(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
	SetWindowPos(hwnd, HWND_TOPMOST, 250, -50, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
	LONG WindLong = (GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetWindowLong(hwnd, GWL_EXSTYLE, WindLong);
	SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

	point arr[46] = {
		{ 395,268 },
		{ 406,222 },
		{ 416,193 },
		{ 441,162 },
		{ 468,133 },
		{ 500,117 },
		{ 537,105 },
		{ 577,107 },
		{ 617,120 },
		{ 649,146 },
		{ 666,173 },
		{ 680,211 },
		{ 683,247 },
		{ 680,293 },
		{ 675,338 },
		{ 660,385 },
		{ 640,440 },
		{ 616,484 },
		{ 588,529 },
		{ 557,573 },
		{ 530,610 },
		{ 493,645 },
		{ 460,675 },
		{ 422,696 },
		{ 381,676 },
		{ 350,654 },
		{ 320,626 },
		{ 292,606 },
		{ 257,570 },
		{ 230,540 },
		{ 200,500 },
		{ 180,470 },
		{ 160,430 },
		{ 140,390 },
		{ 126,342 },
		{ 117,293 },
		{ 120,250 },
		{ 133,203 },
		{ 160,170 },
		{ 200,140 },
		{ 240,130 },
		{ 280,135 },
		{ 312,146 },
		{ 340,170 },
		{ 360,195 },
		{ 375,230 }
	};

	srand((unsigned)time(NULL));
	InitImg();
	for (int i = 0; i<46; i++) {
		//settextcolor(RGB(rand()%256, rand() % 256, rand() % 256 ));
		//outtextxy(arr[i].x, arr[i].y, "Hello World");
		putimage(arr[i].x, arr[i].y, &img[i % 20]);
		Sleep(100);
	}
	int add = 0;
	while (1)
	{
		cleardevice();
		for(int i = 0; i < 46; i++)
		{
			putimage(arr[i].x, arr[i].y, &img[(i + add) % 20]);

		}
		putimage(270, 320, &img_Big[add % 20]);
		add++;
		Sleep(1000);
	}
	//outtextxy(50, 50, "Hello World");
	//system("pause");
	return 0;
}