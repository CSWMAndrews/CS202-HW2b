//
// Created by Matt Andrews on 10/7/2019.
//

#include "hw1.h"

#include <iostream>     // for std::cout, std::endl, std::cin
#include <string>       // for std::string
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector> 
using std::cout;
using std::endl;
using std::string;


/*int hw1::getIdFromFile()
{
	cout << "Boing" << endl;

	int _id = 1;

	std::ifstream ifile("users.txt");
	string sBoing;

	while (ifile)
	{
		ifile >> sBoing;
		_inputStorageNames.push_back(sBoing);
		ifile >> sBoing;
		std::stringstream temp(sBoing);
		int x = 0;
		temp >> x;
		_inputStorageID.push_back(x);
		//cout << sBoing << " " << endl;
	}

	for (int n = 0; n < _inputStorageNames.size(); ++n)
	{
		cout << _inputStorageNames.at(n) << " " << endl;
		cout << _inputStorageID.at(n) << " " << endl;
	}

	return _id;
}*/

int getIdFromFile(const string & fileBoing, std::istream & iBoing, std::ostream & oBoing)
{
	std::vector<string> _inputStorageNames;
	std::vector<int> _inputStorageID;

	//Load
	std::ifstream ifile(fileBoing);
	if (!ifile)
	{
		return -1;
	}

	string sBoing;

	while (ifile)
	{
		ifile >> sBoing;
		_inputStorageNames.push_back(sBoing);
		ifile >> sBoing;
		std::stringstream temp(sBoing);
		int x = 0;
		temp >> x;
		_inputStorageID.push_back(x);
		//cout << sBoing << " " << endl;
	}

	while (!iBoing.eof())
	{
		
		//Pull name to find
		//cout << "getIdFromFile has been called" << endl;
		string inRef;
		iBoing >> inRef;
		//cout << inRef << "<- I got that from the istream!" << endl;
		if (inRef.size()<=0)
		{
			
			break;
		}

		//Search
		bool found = false;
		for (int n = 0; n < _inputStorageNames.size(); ++n)
		{
			//cout << _inputStorageNames.at(n) << " " << endl;
			//cout << _inputStorageID.at(n) << " " << endl;

			if (_inputStorageNames[n] == inRef)
			{
				found = true;
				oBoing << _inputStorageID[n] << endl;
				//cout << _inputStorageNames[n] << endl;
			}
		}
		if (!found)
		{
			//cout << "I failed to find "<< inRef << endl;
			oBoing << "error\n";
		}
	}
	int _id = 0;
	return _id;
}

void numberChase(const string& fileBoing, std::ostream& oBoing)
{

	cout << "I received " << fileBoing << endl;
	std::ifstream ifile(fileBoing, std::ios::binary);

	if (!ifile)
	{
		cout << " BAD PC! " << endl;
	}

	int r;
	while (ifile)
	{
		ifile.read(reinterpret_cast<char*>(&r), sizeof(r));
		cout << r << endl;
	}

	ifile.close();
	ifile.open(fileBoing, std::ios::binary);

	int i = 0;
	int j = 0;
	while (i >= 0 && j < 400)
	{
		ifile.seekg(i * sizeof(int));
		ifile.read(reinterpret_cast<char*>(&i), sizeof(i));
		oBoing << i << endl;
		j++;
	}

}