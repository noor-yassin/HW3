#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxHp)
{
	m_maxHp = maxHp;
	m_Hp = m_maxHp;
}
HealthPoints& HealthPoints::operator+=(const int& health)
{
	m_Hp += health;
	if (m_Hp > m_maxHp)
	{
		m_Hp = m_maxHp;
	}
	if (m_Hp < 0)
	{
		m_Hp = 0;
	}
	return *this;
}
HealthPoints& HealthPoints::operator-=(const int& health)
{
	if (health <= 0)
		throw InvalidArgument();
	m_Hp -= health;
	if (m_Hp > m_maxHp)
	{
		m_Hp = m_maxHp;
	}
	if (m_Hp < 0)
	{
		m_Hp = 0;
	}
	return *this;
}
HealthPoints& HealthPoints::operator+(const int& health)const
{
	HealthPoints result =*this;
	return(result += health);
}
HealthPoints& HealthPoints::operator-(const int& health)const
{
	HealthPoints result = *this;
	return(result -= health);
}
bool HealthPoints::operator==(const HealthPoints& hp)const
{
    return m_HP==hp.m_HP;
}

bool HealthPoints::operator !=(const HealthPoints& hp)const
{
    if(!(m_HP==hp.m_HP))
    {
        return true;
    }
    return false;
}

bool HealthPoints::operator >(const HealthPoints& healthPoints)const
{
    return(m_HP>healthPoints.m_HP);
} 

bool HealthPoints::operator<(const HealthPoints& hp)const
{
    return(m_HP>=hp.m_HP);
} 

bool HealthPoints::operator<=(const HealthPoints& hp)const
{
    if(hp.m_HP>=m_HP)
    {
        return true;
    }
    return false;
}
