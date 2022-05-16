// StateMachineTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

