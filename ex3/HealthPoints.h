#include<iostream>
using std::ostream;

class HealthPoints
{
public :
	HealthPoints(int maxHp=100);
	~HealthPoints() = default;
	HealthPoints(const HealthPoints&) = default;
	HealthPoints& operator=(const HealthPoints&) = default;
	HealthPoints& operator+=(const int&);
	HealthPoints& operator-=(const int&);
	HealthPoints& operator-(const int&)const;
	HealthPoints& operator+(const int&) const;
	class InvalidArgument {};
	bool operator ==(const HealthPoints& hp)const;
	bool operator !=(const HealthPoints& hp)const;
	bool operator >(const HealthPoints& healthPoints)const;
	bool operator >=(const HealthPoints& healthPoints)const;
	bool operator <(const HealthPoints& hp)const;
	bool operator <=(const HealthPoints& hp)const;

	friend ostream& operator <<(ostream& os, const HealthPoints& hp);
	friend bool operator ==(const int&, const HealthPoints&);
	friend bool operator<(const int& num, const HealthPoints& health);
	friend bool operator>(const int& num, const HealthPoints& health);

private:
	int m_maxHp;
	int m_Hp;
};
