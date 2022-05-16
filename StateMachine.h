#pragma once
#include "stdafx.h"
#include "State.h"

template <typename T>
class StateMachine
{
public:
	State<T>*	m_pCurrentState;
	T*			m_pOwner;
public:
	StateMachine(T* pOwner)
		:m_pOwner(pOwner)
		, m_pCurrentState(NULL)
	{}
	virtual ~StateMachine() {}
	virtual void Update()
	{
		m_pCurrentState->Execute();
	}
	virtual void ChangeState(State<T>* pState)
	{
		if (m_pCurrentState != pState)
		{
			m_pCurrentState->Exit();
			m_pCurrentState = pState;
			m_pCurrentState->Enter();
		}
	}
	State<T>*	GetCurrentState() { return m_pCurrentState; }
	void		SetCurrentState(State<T>* pState) { m_pCurrentState = pState; }
};