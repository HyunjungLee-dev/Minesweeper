#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<vector>
using namespace std;


#define DEFULTMINE 99
#define HEIGHT 16
#define WIDTH 30

struct POS
{
	float m_fX;
	float m_fY;
};


enum MOUSE
{
	LBUTTONDOWN,
	RBUTTONDOWN
};

//BitmapManager

enum IMG
{
	IMG_START,

	IMG_BACK = 0,
	IMG_BLOCK,
	IMG_BLOCK_CLICK,
	IMG_BLOCK_START = 2,
	IMG_BLOCK1,
	IMG_BLOCK2,
	IMG_BLOCK3,
	IMG_BLOCK4,
	IMG_BLOCK5,
	IMG_BLOCK6,
	IMG_BLOCK7,
	IMG_BLOCK8,
	IMG_FLAG,
	IMG_MINE,

	IMG_END = 13,
};
