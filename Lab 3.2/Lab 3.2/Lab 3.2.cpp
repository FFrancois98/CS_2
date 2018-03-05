// Program Numbers sends numbers to the output stream in // specified formats. 
#include <iostream> 
#include <iomanip>
using namespace std;

const int num_1 = 1066;
const int num_2 = 1492;
const int num_3 = 512;
const int num_4 = 1;
const int num_5 = -23;

int main()
{
	cout << fixed << showpoint;
	cout << setw(6) << num_1 << endl;
	cout << setw(6) << num_2 << endl;
	cout << setw(6) << num_3 << endl;
	cout << setw(6) << num_4 << endl;
	cout << setw(6) << num_5 << endl;
	return 0;
}

/*
1066
1492
512
1
-23
Press any key to continue . . .

*/