#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class studentType {
	public:
		string name;
		char classification;
		string hometown;
		int id;
		void show_public_info() {
			cout << name << endl;
			cout << classification << endl;
			cout << hometown << endl;
			cout << id << endl;
		}
	private:
		float gpa;
};