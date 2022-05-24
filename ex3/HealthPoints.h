#include <iostream>
#define MAX_HP 100
#include <string>
#include <ostream>
using std::ostream;

class HealthPoints
{
public :
	HealthPoints(int maxHp=MAX_HP);
	~HealthPoints() = default;
	HealthPoints(const HealthPoints&) = default;
	HealthPoints& operator=(const HealthPoints&) = default;
	HealthPoints& operator+=(const int&);
	HealthPoints& operator-=(const int&);
	HealthPoints& operator-(const int&)const;
	HealthPoints& operator+(const int&) const;
	bool operator==(const HealthPoints& hp)const;
        bool operator !=(const HealthPoints& hp)const;
        bool operator >(const HealthPoints& healthPoints)const;
        bool operator >=(const HealthPoints& healthPoints)const;
        bool operator <(const HealthPoints& hp)const;
        bool operator <=(const HealthPoints& hp)const;
	
        friend ostream& operator <<(ostream& os,const HealthPoints& hp);

	class InvalidArgument {};
private:
	int m_maxHp;
	@@ -36,5 +20,4 @@ class HealthPoints::InvalidArgument
{
public :
	InvalidArgument() {}
