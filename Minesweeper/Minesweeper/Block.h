#pragma once
#include"Draw.h"

enum BLOCKTYPE
{
	BLOCKTYPE_NONE,
	BLOCKTYPE_FLAG,
	BLOCKTYPE_QMARK,
	BLOCKTYPE_MINE,
};

// ���� ���->���丮 üũ		, Block/Map/ ���丮 �ƴϾ �׷� ������� 
// �� ��� �޴� ���, �÷���, ����ǥ, ��ź �� ���� �����
// �� ��� �߰��صΰ�, Ŭ���� ���� �ϳ� ���� ����Ʈ�� ���� �ֱ�
// ���丮�� ���� Ŭ�������� �������� ���� �Ҵ� �޴°ɷ� �ϰ�

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

