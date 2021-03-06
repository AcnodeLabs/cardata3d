// pass1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

string extractvalue(string str, string pre, string post) {
	int a = str.find(pre); a += pre.size();
	int b = str.find(post);
	int count = (b - a);
	return str.substr(a, count);
}

void removeCharsFromString(string &str, const char* charsToRemove) {
	for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
		str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
	}
}

void on(string name, string value) {
	removeCharsFromString(value, " ,");
	static string year, mileage, price;//order is as per file
	if (name.find("year") != string::npos) year = value;
	if (name.find("mileage") != string::npos) mileage = value;
	if (name.find("price") != string::npos) {
		price = value;
		std::cout << year << "," << mileage << "," << price << "\n";
		year.clear();
		mileage.clear();
		price.clear();
	}
}

int main()
{
	FILE * f;
	fopen_s(&f, "output.txt", "r");
	char line[2048];
	if (f) {

		while (!feof(f)) {
			fgets(line, 2048, f);
			string lin(line);
			if (lin.find("<li><i class=\"icon pw-date\"></i>") != string::npos) {
				on("year", extractvalue(lin, "></i>", "</li>"));
			}
			if (lin.find("><span class='pkr'>PKR</span>") != string::npos) {
				on("price", extractvalue(lin, "span> ", " </strong"));
			}
			if (lin.find("<li><i class=\"icon pw-mileage\"></i>") != string::npos) {
				on("mileage", extractvalue(lin,"></i>", " km</li>"));
			}

			lin.clear();
		}
				
		fclose(f);
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
