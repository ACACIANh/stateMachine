#pragma once
#define VK_MAX 0xff
class CKeyMgr
{
public:
	bool KeyPressing(int iKey);
	bool KeyDown(int iKey);
	bool KeyUp(int iKey);
	void UpdateKeyState();
public:
	static CKeyMgr* Get_Instance() { 
		if (m_pInstance == nullptr) 
			m_pInstance = new CKeyMgr; 
		return m_pInstance;
	}
	static void Destroy_Instance() {
		if (m_pInstance)
			delete m_pInstance;
		m_pInstance = nullptr;
	}
private:
	static CKeyMgr*	m_pInstance;
	bool			m_bKeyState[VK_MAX];
private:
	CKeyMgr() { ZeroMemory(m_bKeyState, sizeof(m_bKeyState)); }
	CKeyMgr(CKeyMgr& _rVal) {}
	void operator=(CKeyMgr& _rVal) {}
	~CKeyMgr() {}
};

