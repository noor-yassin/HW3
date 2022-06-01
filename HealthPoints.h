#include<iostream>
using std::ostream;

class HealthPoints
{
public :
    /**
     * Construct a new HealthPoints object 
	 * with two variables
     * @param maxHp - a value for the variables of the object
	 * if the constructor doenst recieve any value it 
	 * assigns the value to the deafult one defined.
     */
	HealthPoints(int maxHp=100);

	/**
	 * @brief Destroy the Health Points object
	 * 
	 */
	~HealthPoints() = default;
	/**
	 * @brief Copy constructor - creates a copy of an existing object
	 * @param Healthpoints&- an existing object that we want to make a copy of
	 */

	HealthPoints(const HealthPoints&) = default;
	
	/**
	 * @brief assignment operator, assigns a value from an existing object
	 * to an another existing one
	 * 
	 * @return HealthPoints&- the object with the new value we assigned to it
	 */
	HealthPoints& operator=(const HealthPoints&) = default;

	/**
	 * @brief adds the value that it recieves to an object  and assigns it to it
	 * @param int&- a value that we want to add to the object
	 * (to the health points of the object) 
	 * @return HealthPoints&- the object with the new value
	 */
	
	HealthPoints& operator+=(const int&);

	/**
	 * @brief subtracts the value that it recieves from an object and assigns it to it
	 * @param int&- a value that we want to subtract from the object
	 * (to the health points of the object) 
	 * @return HealthPoints&- the object with the new value
	 */

	HealthPoints& operator-=(const int&);
	
	/**
	 * @brief an operator to subtract a value from an object,
	 * without assigning the new value to it.
	 * @param int&- the value we want to subtract
	 * @return HealthPoints- a copy of the object after subtracting.
	 */
	
	HealthPoints operator-(const int&)const;
	
	/**
	 * @brief an operator to add a value to an object,
	 * without assigning the new value to it.
	 * @param int&- the value we want to add
	 * @return HealthPoints- a copy of the object after adding.
	 */
	HealthPoints operator+(const int&) const;

	class InvalidArgument {};
	
	/**
	 * @brief compares two objects- checks if they're equal.
	 * 
	 * @param hp - the object we want to compare the current one with.
	 * @return true- if the objects are equal
	 * @return false - if the objects are not equal
	 */
	bool operator ==(const HealthPoints& hp)const;
	
	/**
	 * @brief compares two objects-checks if they're not equal.
	 * 
	 * @param hp -the object we want to compare the current one with.
	 * @return true- if the objects are'nt equal.
	 * @return false - if the objects are equal.
	 */
	bool operator !=(const HealthPoints& hp)const;

	/**
	 * @brief checks if the current object is bigger than the recieved one.
	 * 
	 * @param healthPoints - the object we want to campare the current one with.
	 * @return true - if the current object is bigger.
	 * @return false - if the current object is smaller.
	 */
	bool operator >(const HealthPoints& healthPoints)const;

	/**
	 * @brief checks if the current object is bigger or equal to the recieved one.
	 * 
	 * @param healthPoints - the object we want to campare the current one with.
	 * @return true - if the current object is bigger or equal to hp.
	 * @return false - if the current object is smaller.
	 */
	bool operator >=(const HealthPoints& healthPoints)const;

	/**
	 * @brief checks if the current object is smaller than the recieved one.
	 * 
	 * @param healthPoints - the object we want to campare the current one with.
	 * @return true - if the current object is smaller.
	 * @return false - if the current object is bigger.
	 */
	bool operator <(const HealthPoints& hp)const;

	/**
	 * @brief checks if the current object is smaller or equal to the recieved one.
	 * 
	 * @param healthPoints - the object we want to campare the current one with.
	 * @return true - if the current object is smaller or equal to hp.
	 * @return false - if the current object is bigger.
	 */
	bool operator <=(const HealthPoints& hp)const;
    
	/**
	 * @brief insert the vslue of an object to a file.
	 * 
	 * @param os- the file we want to print the value to.
	 * @param hp - the object we want to print its value.
	 * @return ostream& - the file after inserting the value to it.
	 */
	friend ostream& operator <<(ostream& os, const HealthPoints& hp);

    /**
     * @brief compares an integer with an object
     * @param int&- the integer we want to compare with.
	 * @param Healthpoints&- the object we want to compare with.
     * @return true - if the two comparison elements are equal.
     * @return false - if they're not equal.
     */
	friend bool operator ==(const int&, const HealthPoints&);

	/**
	 * @brief checks if an integer is smaller than an object
	 * 
	 * @param num - the integer we want to check.
	 * @param health - the object we want to compare with.
	 * @return true - if the integer is smaller than the object.
	 * @return false - if the integer is bigger than the object.
	 */
	friend bool operator<(const int& num, const HealthPoints& health);
	/**
	 * @brief checks if an integer is bigger than an object
	 * 
	 * @param num - the integer we want to check.
	 * @param health - the object we want to compare with.
	 * @return true - if the integer is bigger than the object.
	 * @return false - if the integer is smaller than the object.
	 */
	friend bool operator>(const int& num, const HealthPoints& health);

	/**
	 * @brief adds an integer to an object
	 * 
	 * @param num - the integer we want to add.
	 * @param health - the object we want to add to.
	 * @return HealthPoints- the object after adding. 
	 */
    friend HealthPoints operator+(const int& num, const HealthPoints& health);

private:
	int m_maxHp;
	int m_Hp;
};
