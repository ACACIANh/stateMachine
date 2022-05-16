#pragma once

#include "StateMachine.h"

class CPlayer;

class CPlayerStateMachine : public StateMachine<CPlayer>
{

public:
	CPlayerStateMachine(CPlayer* pPlayer);
	virtual ~CPlayerStateMachine();

public:
	virtual void Update();
	virtual void Release();

public:
	//State<CPlayer>*	GetCurrentState() { return m_pCurrentState; }
	void					ChangeState(State<CPlayer>* state);

public:
	State<CPlayer>*			GetIdleState() { return m_pPlayerIdle; }
	State<CPlayer>*			GetRunState() { return m_pPlayerRun; }
	State<CPlayer>*			GetRollState() { return m_pPlayerRoll; }
	State<CPlayer>*			GetJumpState() { return m_pPlayerJump; }

private:
	State<CPlayer>*			m_pPlayerIdle;
	State<CPlayer>*			m_pPlayerRun;
	State<CPlayer>*			m_pPlayerRoll;
	State<CPlayer>*			m_pPlayerJump;
};

