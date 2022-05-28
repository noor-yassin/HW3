#include "HealthPoints.h"
#include "Queue.h"

static bool isEven(int n)
{
	return (n % 2) == 0;
}

int main()
{
	HealthPoints healthPoints1; /* has 100 points out of 100 */
	HealthPoints healthPoints(150); /* has 150 points out of 150 */
	try {
		HealthPoints healthPoints3(-100);
	}
	catch (HealthPoints::InvalidArgument& e) {
		std::cout << "bad number" << std::endl;
	}
	bool comparisonResult;
	HealthPoints healthPoints2 = 100; /* 100 points out of 100 */
	comparisonResult = (healthPoints1 == healthPoints2); /* returns true */
	std::cout << comparisonResult<<std::endl;
	healthPoints2 = HealthPoints(150); /* has 150 points out of 150 */
	comparisonResult = (healthPoints1 == healthPoints2); /* returns false */
	std::cout << comparisonResult << std::endl;
	healthPoints2 -= 50; /* now has 100 points out of 150 */
	comparisonResult = (100 == healthPoints2); /* returns true */
	std::cout << comparisonResult << std::endl;
	comparisonResult = (healthPoints1 < healthPoints2); /* returns false */
	std::cout << comparisonResult << std::endl;
	healthPoints1 -= 50; /* now has 50 points out of 100 */
	comparisonResult = (healthPoints1 < healthPoints2); /* returns true */
	std::cout << comparisonResult << std::endl;
	std::cout << healthPoints1 << ", " << healthPoints2;

	std::cout << "Queue test    ****" << std::endl;
	Queue<int> queue1;
	queue1.pushBack(1);
	queue1.pushBack(2);
	int front1 = queue1.front(); /* front1 equals 1 as its the first value */
	std::cout <<front1<< std::endl;
	queue1.front() = 3; /* queue1 content is: 3, 2 (left to right) */
	front1 = queue1.front(); /* front1 now equals 3 */
	std::cout <<front1<< std::endl;
	queue1.popFront();
	std::cout << queue1.front() << std::endl;
	Queue<int> queue3;
	for (int i = 1; i <= 10; i++) {
		queue3.pushBack(i);
	}
	Queue<int> queue4 = filter(queue3, isEven);
	return 0;
}