
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
private:
	int m_maxHp;
	int m_Hp;
};
class HealthPoints::InvalidArgument
{
public :
	InvalidArgument() {}
};
