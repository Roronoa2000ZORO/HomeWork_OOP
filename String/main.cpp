﻿#include"string.hpp"


int main() {
	
    setlocale(LC_ALL, "ru");

	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3 = str1 + str2;
	cout << str3 << endl;
	
	String str4 = String();
	cout << str4 << endl;

	str1 += str2;
	cout << str1 << endl;
	
    return 0;
}