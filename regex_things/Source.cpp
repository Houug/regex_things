#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	fstream db;
	fstream ex;

	db.open("dt.txt");
	ex.open("ex.txt");

	db.seekg(ios::beg);
	ex.seekg(ios::beg);

	vector<string> vector_of_db;
	vector<string> vector_of_ex;
	string temp;
	

	while (!db.eof())
	{
		getline(db,temp);
		vector_of_db.push_back(temp);
	}

	while (!ex.eof())
	{
		getline(ex, temp);
		vector_of_ex.push_back(temp);
	}

	temp = "";

	for (string item : vector_of_ex)
	{
		temp = temp + item + " |";
	}

	regex r(temp);

	for (string item : vector_of_db)
	{
		cout << regex_replace(item,r,"") << endl;
	}
}