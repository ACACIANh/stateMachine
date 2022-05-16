#include "stdafx.h"
#include "KeyMgr.h"
#include "PlayerState.h"
#include "Player.h"
#include "PlayerStateMachine.h"

void CPlayerState_IDLE::Enter()
{
}

void CPlayerState_IDLE::Execute()
{
	if (CKeyMgr::Get_Instance()->KeyDown(VK_RIGHT))
	{
		m_pPlayer->GetMachine()->ChangeState(static_cast<CPlayerStateMachine*>(m_pPlayer->GetMachine())->GetRunState());
	}
	if (CKeyMgr::Get_Instance()->KeyDown(VK_SPACE))
	{
		m_pPlayer->GetMachine()->ChangeState(static_cast<CPlayerStateMachine*>(m_pPlayer->GetMachine())->GetRollState());
	}
	if (CKeyMgr::Get_Instance()->KeyDown(VK_UP))
	{
		m_pPlayer->GetMachine()->ChangeState(static_cast<CPlayerStateMachine*>(m_pPlayer->GetMachine())->GetJumpState());
	}
}

void CPlayerState_IDLE::Exit()
{
}

void CPlayerState_RUN::Enter()
{
	cout << "달립니다." << endl;
}

void CPlayerState_RUN::Execute()
{
	if (CKeyMgr::Get_Instance()->KeyDown(VK_RIGHT))
	{
		cout << "달립니다." << endl;
	}
	if (CKeyMgr::Get_Instance()->KeyDown(VK_SPACE))
	{
		m_pPlayer->GetMachine()->ChangeState(static_cast<CPlayerStateMachine*>(m_pPlayer->GetMachine())->GetRollState());
	}
	if (CKeyMgr::Get_Instance()->KeyDown(VK_UP))
	{
		m_pPlayer->GetMachine()->ChangeState(static_cast<CPlayerStateMachine*>(m_pPlayer->GetMachine())->GetJumpState());
	}
}

void CPlayerState_RUN::Exit()
{
}


void CPlayerState_ROLL::Enter()
{
	dwTime = GetTickCount();
	cout << "구르기 시작합니다" << endl;
}

void CPlayerState_ROLL::Execute()
{
	if (dwTime + 1000 < GetTickCount())
	{
		cout << "다 굴렀습니다." << endl;
		dwTime = GetTickCount();
		m_pPlayer->GetMachine()->ChangeState(static_cast<CPlayerStateMachine*>(m_pPlayer->GetMachine())->GetIdleState());
	}
}

void CPlayerState_ROLL::Exit()
{
}


void CPlayerState_JUMP::Enter()
{
	cout << "점프를 시작합니다." << endl;
	dwTime = GetTickCount();
}

void CPlayerState_JUMP::Execute()
{
	if (dwTime + 1000 < GetTickCount())
	{
		cout << "점프가 끝났습니다." << endl;
		dwTime = GetTickCount();
		m_pPlayer->GetMachine()->ChangeState(static_cast<CPlayerStateMachine*>(m_pPlayer->GetMachine())->GetIdleState());
	}
}

void CPlayerState_JUMP::Exit()
{
}
