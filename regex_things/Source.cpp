#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	fstream db;
	fstream ex;

	db.open("dt.txt");
	ex.open("ex.txt");

	db.seekg(ios::beg);
	ex.seekg(ios::beg);

	vector<string> vector_of_db;
	vector<string> vector_of_ex;

	regex ex1(" не ");
	regex ex2(" или ");
	regex ex3(" и ");
	regex ex4("[.,!?]");
	regex ex5("(^[ |+])");

	smatch m;
	string temp;
	

	while (!db.eof())
	{
		getline(db,temp);
		vector_of_db.push_back(" " + temp);
	}

	while (!ex.eof())
	{
		getline(ex, temp);
		vector_of_ex.push_back(temp);
	}

	temp = " ";

	for (string item : vector_of_ex)
	{
		temp = temp + item + " | ";
	}
	temp.pop_back();
	temp.pop_back();

	regex r(temp);

	for (string item : vector_of_db)
	{
		temp = item;
		do
		{
			temp = regex_replace(regex_replace(regex_replace(regex_replace(regex_replace(temp, ex4, ""), ex1, " ~~"), ex2, "|"), ex3, "+"), r, " ");
		} while (
					regex_search(temp, m, r)	||
					regex_search(temp, m, ex1)	||
					regex_search(temp, m, ex2)	||
					regex_search(temp, m, ex3)	||
					regex_search(temp, m, ex4)
				);
		while (regex_search(temp, m, ex5))
		{
			temp = regex_replace(temp, ex5, "");
		}
		cout << temp << endl;
	}
}