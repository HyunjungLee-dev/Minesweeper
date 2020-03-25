#pragma once
#include"Draw.h"

enum BLOCKTYPE
{
	BLOCKTYPE_NONE,
	BLOCKTYPE_FLAG,
	BLOCKTYPE_QMARK,
	BLOCKTYPE_MINE,
};

// 개별 블록->팩토리 체크		, Block/Map/ 팩토리 아니어도 그런 방식으로 
// 블럭 상속 받는 깃발, 플래그, 물음표, 폭탄 을 각각 만들고
// 각 기능 추가해두고, 클래스 따로 하나 만들어서 리스트로 집어 넣기
// 팩토리로 게임 클래스에서 랜덤으로 각각 할당 받는걸로 하고

class Block		  
{
private:
	BLOCKTYPE m_eBlock;
	string m_strBlock;
	int m_ix;
	int m_iy;
public:
	//void DrawBlock();
	//void SetBlock();

	Block();
	~Block();
};

