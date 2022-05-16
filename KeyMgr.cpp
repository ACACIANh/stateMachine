#include "stdafx.h"
#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInstance = NULL;
bool CKeyMgr::KeyPressing(int iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000)
		return true;
	return false;
}

bool CKeyMgr::KeyDown(int iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000 && !m_bKeyState[iKey])
	{
		m_bKeyState[iKey] = !m_bKeyState[iKey];
		return true;
	}
	return false;
}

bool CKeyMgr::KeyUp(int iKey)
{
	if (!(GetAsyncKeyState(iKey) & 0x8000) && m_bKeyState[iKey])
	{
		m_bKeyState[iKey] = !m_bKeyState[iKey];
		return true;
	}
	return false;
}

void CKeyMgr::UpdateKeyState()
{
	for (int i = 0; i < VK_MAX; ++i)
	{
		if (GetAsyncKeyState(i) & 0x8000 && !m_bKeyState[i])
			m_bKeyState[i] = !m_bKeyState[i];
		if (!(GetAsyncKeyState(i) & 0x8000) && m_bKeyState[i])
			m_bKeyState[i] = !m_bKeyState[i];
	}
}
