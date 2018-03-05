#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class dogType {   // creates a public class

	public:   //creates public variables
		string color;
		string eyecolor;
		double height;
		double length;
		double weight;

		void sit() { // function to display output
			cout << "sit" << endl;
		}
		void layDown() { // function to display output
			cout << "Lay Down" << endl;
		}
		void shake() { // function to display output
			cout << "shake" << endl;
		}
		void come() { // function to display output
			cout << "come" << endl;
		}
};
int main() {
	dogType Rayne;
	Rayne.color = "Gray, White, and Black"; // assigns values to variables 
	Rayne.eyecolor = "Blue and Brown";
	Rayne.height = 18;
	Rayne.length = 36;
	Rayne.weight = 30;
	Rayne.come(); // calls function
	Rayne.layDown();
	Rayne.shake();
	Rayne.sit();
 }
/*
come
Lay Down
shake
sit
Press any key to continue . . .
*/


