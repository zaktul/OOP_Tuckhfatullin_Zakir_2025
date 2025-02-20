#include <iostream> 
using namespace std;
const float PI = 3.14159F;

float circarea(float);

int main()
{
	float radius;

	cout << "Enter radius of the circle: "; 
	cin >> radius;
	float area = circarea(radius);
	cout << "Squere of cirecle = " << area << endl;
	return 0;
}

float circarea(float radius) {
	float area = PI * radius * radius;
	return area;
}


