#include <iostream> 
using namespace std;

struct Distance
{
	int feet;
	float inches;
};

Distance biggerDistance(Distance, Distance); 

int main()
{
	Distance d1, d2, d3;
	cout << "First distance:" << endl;
	cout << "Enter number of feets: "; cin >> d1.feet;
	cout << "Enter number of inches "; cin >> d1.inches;

	cout << endl << "Second distance:" << endl;
	cout << "Enter number of feets: "; cin >> d2.feet;
	cout << "Enter number of inches: "; cin >> d2.inches;
	d3 = biggerDistance(d1, d2);

	cout << "Feets = " << d3.feet << endl;
	cout << "Inches = " << d3.inches << endl;

	return 0;
}

Distance biggerDistance(Distance dd1, Distance dd2)
{
	Distance dd3;

	dd1.inches = dd1.inches + dd1.feet * 12;
	dd1.feet = 0;

	dd2.inches = dd2.inches + dd2.feet * 12;
	dd2.feet = 0;

	if (dd1.inches > dd2.inches)
	{
		cout << "First distance is bigger" << endl;
		dd3 = dd1;
	}
	else if (dd1.inches < dd2.inches) {
		cout << "Second distance is bigger" << endl;
		dd3 = dd2;
	}
	else {
		cout << "Distance are equal" << endl;
		dd3 = dd1;
	}

	while (dd3.inches > 12.0) {
		dd3.feet += 1;
		dd3.inches -= 12.0;
	}

	return dd3;
}