//
// Created by Giddeon on 10/7/2019.
//

#ifndef CS202HW2_HW1_H
#define CS202HW2_HW1_H

#include <iostream>     // for std::cout, std::endl, std::cin
#include <string>       // for std::string
#include <ostream>
#include <fstream>
#include <vector> 
using std::cout;
using std::string;

int getIdFromFile(const string&, std::istream&, std::ostream&);

void numberChase(const string&, std::ostream&);

//class hw1
//{
//public:
//
//	//int getIdFromFile(std::string, std::istream, std::ostream);
//	int getIdFromFile();
//
//private:
//
//	std::vector<string> _inputStorageNames;
//	std::vector<int> _inputStorageID;
//
//};

#endif //CS202HW2_HW1_H
