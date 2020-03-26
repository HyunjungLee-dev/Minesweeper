#pragma once
#include"Draw.h"


// 개별 블록->팩토리 체크		, Block/Map/ 팩토리 아니어도 그런 방식으로 
// 블럭 상속 받는 깃발, 플래그, 물음표, 폭탄 을 각각 만들고
// 각 기능 추가해두고, 클래스 따로 하나 만들어서 리스트로 집어 넣기
// 팩토리로 게임 클래스에서 랜덤으로 각각 할당 받는걸로 하고

enum BLOCKTYPE
{
	BLOCKTYPE_NONE,
	BLOCKTYPE_FLAG,
	BLOCKTYPE_QMARK,
	BLOCKTYPE_MINE,
};

class Block		  
{
protected:
	Draw Bdraw;
public:
   virtual void DrawBlock()= 0;
	virtual void SetBlock(int x, int y) =0;
	virtual inline BLOCKTYPE GetType() = 0;

	Block();
	virtual ~Block();
};

class None : public Block
{
private:
	int m_ix;
	int m_iy;
	BLOCKTYPE m_eblockType;
public:
	virtual void DrawBlock();
	virtual void SetBlock(int x, int y);
	virtual inline BLOCKTYPE GetType() {	return m_eblockType;	}

	None();
	virtual ~None();
};

class Flag : public Block
{
private:
	int m_ix; 
	int m_iy;
	BLOCKTYPE m_eblockType;
public:
	virtual void DrawBlock();
	virtual void SetBlock(int x, int y);
	virtual inline BLOCKTYPE GetType() { return m_eblockType; }

	Flag();
	virtual ~Flag();
};


class Qmark: public Block
{
private:
	int m_ix; 
	int m_iy;
	BLOCKTYPE m_eblockType;
public:
	virtual void DrawBlock();
	virtual void SetBlock(int x, int y);
	virtual inline BLOCKTYPE GetType() { return m_eblockType; }

	Qmark();
	virtual ~Qmark();
};

class Mine : public Block
{
private:
	int m_ix;
	int m_iy;
	BLOCKTYPE m_eblockType;
public:
	virtual void DrawBlock();
	virtual void SetBlock(int x, int y);
	virtual inline BLOCKTYPE GetType() { return m_eblockType; }

	Mine();
	virtual ~Mine();
};


