#include "stdafx.h"
#include "Player.h"
#include "PlayerState.h"
#include "KeyMgr.h"
#include "PlayerStateMachine.h"
#include "StateMachine.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}


void CPlayer::Initialize()
{
	m_pMachine = new CPlayerStateMachine(this);
	//m_pMachine->SetCurrentState(static_cast<CPlayerStateMachine*>(m_pMachine)->GetIdleState());
}

void CPlayer::Update()
{
	m_pMachine->Update();
	CKeyMgr::Get_Instance()->UpdateKeyState();
}

void CPlayer::Render()
{
}

void CPlayer::Release()
{
	CKeyMgr::Destroy_Instance();
	delete m_pMachine;
}
