#include "stdafx.h"
#include "PlayerStateMachine.h"
#include "PlayerState.h"

CPlayerStateMachine::CPlayerStateMachine(CPlayer* pPlayer)
	:StateMachine<CPlayer>(pPlayer)
{
	m_pPlayerIdle = new CPlayerState_IDLE(pPlayer);
	m_pPlayerRun = new CPlayerState_RUN(pPlayer);
	m_pPlayerRoll = new CPlayerState_ROLL(pPlayer);
	m_pPlayerJump = new CPlayerState_JUMP(pPlayer);
	m_pCurrentState = m_pPlayerIdle;
}

CPlayerStateMachine::~CPlayerStateMachine()
{
	Release();
}

void CPlayerStateMachine::Update()
{
	m_pCurrentState->Execute();
}

void CPlayerStateMachine::Release()
{
	delete m_pPlayerIdle;
	delete m_pPlayerRun;
	delete m_pPlayerRoll;
	delete m_pPlayerJump;
}

void CPlayerStateMachine::ChangeState(State<CPlayer>* state)
{
	if (m_pCurrentState != state)
	{
		m_pCurrentState->Exit();
		m_pCurrentState = state;
		m_pCurrentState->Enter();
	}
}