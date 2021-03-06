#include <iostream>
#include <fstream>
//#include <cstring>
using namespace std;

int main(void) {
	ifstream f;
	const char fileName[] = "input.csv";
	
	//f.open(fileName, ios::in);
	f.open(fileName);

	if (f.good()) {
		const int n = 1024;
		char buf[n];
		char* p = NULL;
		char* context = NULL;

		while (!f.eof()) {
			//f.getline(buf, n, '\n');
			f.getline(buf, n);
			cout << buf << endl;
			p = strtok_s(buf, ";", &context);

			while (p) {
				cout << p << endl;
				p = strtok_s(NULL, ";", &context);
			}
			cout << endl;
		}

		p = NULL;
		context = NULL;
		f.close();
	}
	else {
		cout << "Blad podczas otwarcia pliku" << endl;
	}

	return 0;
}