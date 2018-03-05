#include <iostream>
#include <string>
using namespace std;

template <class T>
void SelectionSort(T numbers[], int numbersSize) {
	int i = 0;
	int j = 0;
	int indexSmallest = 0;
	T temp;  // Temporary variable for swap

	for (i = 0; i < numbersSize; ++i) {

		// Find index of smallest remaining element
		indexSmallest = i;
		for (j = i + 1; j < numbersSize; ++j) {

			if (numbers[j] < numbers[indexSmallest]) {
				indexSmallest = j;
			}
		}

		// Swap numbers[i] and numbers[indexSmallest]
		temp = numbers[i];
		numbers[i] = numbers[indexSmallest];
		numbers[indexSmallest] = temp;
	}
}

int main() {
	string strArr[] = { "jiffy", "zappy", "loopy", "bubbly", "catty", "daddy", "zany", "iffy", "snippy" };
	//cout << strArr << endl;
	int intArr[] = { 25,10,8,6,43,89,14, 32, 0 };
	double doubleArr[] = { 5.34, 1.11, 33.43, 2.45, 89.67, 77.051, 10.6, 9.3456, 100.21 };

	SelectionSort(strArr, 9);
	SelectionSort(intArr, 9);
	SelectionSort(doubleArr, 9);

	cout << "THIS USED SELCTION SORT: " << endl;

	cout << "{";
	for (int j = 0; j < 8; j++) {
		cout << strArr[j] << ",";
	}
	cout << strArr[8] << "}" << endl;


	cout << "{";
	for (int j = 0; j < 8; j++) {
		cout << intArr[j] << ",";
	}
	cout << intArr[8] << "}" << endl;


	cout << "{";
	for (int j = 0; j < 8; j++) {
		cout << doubleArr[j] << ",";
	}
	cout << doubleArr[8] << "}" << endl;

	return 0;
}
/*
THIS USED SELCTION SORT:
{bubbly,catty,daddy,iffy,jiffy,loopy,snippy,zany,zappy}
{0,6,8,10,14,25,32,43,89}
{1.11,2.45,5.34,9.3456,10.6,33.43,77.051,89.67,100.21}
*/