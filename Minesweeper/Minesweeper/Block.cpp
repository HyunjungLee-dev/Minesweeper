#include "Block.h"



Block::Block()
{
}


Block::~Block()
{
}

None::None()
{
	m_eblockType = BLOCKTYPE_NONE;
}

void None::DrawBlock()
{

	Bdraw.DrawPoint("¡à", m_ix+1, m_iy+1);
}

void None::SetBlock(int x, int y)
{
	m_ix = x;
	m_iy = y;
}


None::~None()
{
}


Flag::Flag()
{
	m_eblockType = BLOCKTYPE_FLAG;
}

void Flag::DrawBlock()
{
	Bdraw.ErasePoint(m_ix+1, m_iy+1);
	Bdraw.DrawPoint("¡Ú", m_ix+1, m_iy+1);
}

void Flag::SetBlock(int x, int y)
{
	m_ix = x;
	m_iy = y;
}


Flag::~Flag()
{
}



Qmark::Qmark()
{
	m_eblockType = BLOCKTYPE_QMARK;
}

void Qmark::DrawBlock()
{
	Bdraw.ErasePoint(m_ix+1, m_iy+1 );
	Bdraw.DrawPoint("£¿", m_ix+1, m_iy+1);
}

void Qmark::SetBlock(int x, int y)
{
	m_ix = x;
	m_iy = y;
}


Qmark::~Qmark()
{
}

Mine::Mine()
{
	m_eblockType = BLOCKTYPE_MINE;
}

void Mine::DrawBlock()
{
	Bdraw.ErasePoint(m_ix +1 , m_iy+1 );
	Bdraw.DrawPoint("¡Ý", m_ix+1 , m_iy+1 );
}

void Mine::SetBlock(int x, int y)
{
	m_ix = x;
	m_iy = y;
}

Mine::~Mine()
{
}





