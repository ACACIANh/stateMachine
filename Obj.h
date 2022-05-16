#pragma once
class CObj
{
private:
	INFO	m_tInfo;
public:
	virtual void	Initialize()	=0;
	virtual void	Update()		=0;
	virtual void	Render()		=0;
	virtual void	Release()		=0;
public:
	CObj();
	virtual ~CObj();
};

