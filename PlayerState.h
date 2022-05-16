#pragma once
#include "State.h"

class CPlayer;

class CPlayerState_IDLE : public State<CPlayer>
{
private:
	CPlayer* m_pPlayer;
public:
	CPlayerState_IDLE(CPlayer* player) : m_pPlayer(player){ }

public:
	virtual void Enter() ;
	virtual void Execute() ;
	virtual void Exit() ;
};

class CPlayerState_RUN : public State<CPlayer>
{
private:
	CPlayer* m_pPlayer;
public:
	CPlayerState_RUN(CPlayer* player) : m_pPlayer(player) { }

public:
	virtual void Enter() ;
	virtual void Execute() ;
	virtual void Exit() ;
};

class CPlayerState_ROLL : public State<CPlayer>
{
private:
	CPlayer* m_pPlayer;
public:
	CPlayerState_ROLL(CPlayer* player) : m_pPlayer(player) { }

	DWORD	dwTime;
public:
	virtual void Enter() ;
	virtual void Execute() ;
	virtual void Exit() ;
};

class CPlayerState_JUMP : public State<CPlayer>
{
private:
	CPlayer* m_pPlayer;
public:
	CPlayerState_JUMP(CPlayer* player) : m_pPlayer(player) { }

	DWORD	dwTime;
public:
	virtual void Enter();
	virtual void Execute();
	virtual void Exit();
};

