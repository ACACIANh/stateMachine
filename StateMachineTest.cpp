// StateMachineTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Player.h"

#include "KeyMgr.h"

int main()
{
	CPlayer tPlayer;
	tPlayer.Initialize();
	while (true)
	{
		if (CKeyMgr::Get_Instance()->KeyDown(VK_ESCAPE))
			break;
		tPlayer.Update();
	}
    return 0;
}

