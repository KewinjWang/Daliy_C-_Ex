#include "date.h"
int main()
{
	Date d1(2022,4,2);
	Date d2(2022,3,28);
	cout << (d1 - d2) << endl;
	d1.Print();
	d2.Print();
	return 0;
}
