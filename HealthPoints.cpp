
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
	return m_Hp == hp;
}

bool HealthPoints::operator !=(const HealthPoints& hp)const
{
	if (m_Hp==hp)
		return false;
	return true;
}

bool HealthPoints::operator >(const HealthPoints& healthPoints)const
{
	return m_Hp > healthPoints;
}

bool HealthPoints::operator>=(const HealthPoints& healthPoints) const
{
	if (m_Hp > healthPoints || m_Hp == healthPoints)
		return true;
	return false;
}

bool HealthPoints::operator<(const HealthPoints& hp)const
{
	return m_Hp < hp;
}

bool HealthPoints::operator<=(const HealthPoints& hp)const
{
	if (m_Hp==hp||m_Hp<hp)
	{
		return true;
	}
	return false;
}

bool operator==(const int& num, const HealthPoints& health)
{
	if (health.m_Hp == num)
		return true;
	return false;
}

bool operator<(const int& num, const HealthPoints& health)
{
	if (num < health.m_Hp)
		return true;
	return false;
}

bool operator>(const int& num, const HealthPoints& health)
{
	if (num > health.m_Hp)
		return true;
	return false;
}

ostream& operator <<(ostream& os, const HealthPoints& hp)
{
	return os << hp.m_Hp << "(" << hp.m_maxHp << ")" << std::endl;
}


