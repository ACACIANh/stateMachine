#pragma once

//3�� ������

template <typename T>
class State
{
public:
	virtual void	Enter() = 0;
	virtual void	Execute() = 0;
	virtual void	Exit() = 0;
	virtual ~State() {};
protected:
	//T*				m_pObj;
};
