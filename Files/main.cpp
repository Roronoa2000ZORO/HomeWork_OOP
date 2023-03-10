
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
//#define HW_1_&_2
//#define HW_3
//#define HW_4

int main()
{
	setlocale(LC_ALL, "ru");
	
#ifdef HW_1_&_2
	ofstream fout;
	string nameFile;

	getline(cin, nameFile);

	if (nameFile.find(".txt") == nameFile.npos) {
		nameFile += ".txt";
	}
	fout.open(nameFile);

	fout.close();
#endif // HW_1_&_2

	
#ifdef HW_3
	ifstream fin("201 RAW.txt");
	if (!fin.is_open())
	{
		cerr << "Error: file not found" << endl;
		return 0;
	}

	string ip, mac;

	ofstream fout("201 ready.txt");
	while (!fin.eof())
	{
		fin >> ip >> mac;
		fout << mac << "        " << ip << endl;

	}

	fin.close();
	fout.close();
#endif // HW_3


#ifdef HW_4
	ifstream fin("201 RAW.txt");
	if (!fin.is_open())
	{
		cerr << "Error: file not found" << endl;
		return 0;
	}

	string ip, mac;
	int i = 1;
	ofstream fout("201.dhcpd");

	while (!fin.eof())
	{
		
		fin >> ip >> mac;
		fout << "host 201-" << i << "\n{\n"
			 << "hardware ethernet		" << mac << ";\n"
			 << "fixed-address			" << ip << ";\n}\n"
			 << endl;

		i++;
	}

	fin.close();
	fout.close();



#endif // HW_4


	return 0;
}