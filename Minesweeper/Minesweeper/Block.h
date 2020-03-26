#pragma once
#include"Draw.h"


// ���� ���->���丮 üũ		, Block/Map/ ���丮 �ƴϾ �׷� ������� 
// �� ��� �޴� ���, �÷���, ����ǥ, ��ź �� ���� �����
// �� ��� �߰��صΰ�, Ŭ���� ���� �ϳ� ���� ����Ʈ�� ���� �ֱ�
// ���丮�� ���� Ŭ�������� �������� ���� �Ҵ� �޴°ɷ� �ϰ�

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


