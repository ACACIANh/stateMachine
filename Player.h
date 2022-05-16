#pragma once
#include "Obj.h"
#include "StateMachine.h"

class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
		

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	StateMachine<CPlayer>* GetMachine() { return m_pMachine; }

private:
	StateMachine<CPlayer>*	m_pMachine;
};

