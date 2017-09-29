#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>


using std::string;
using std::list;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::cin;
using std::cout;
using std::endl;

//Struct for save intervals in vector
struct Interval
{
	int low;
	int high;
	Interval(int _low, int _high)
	{
		low = _low;
		high = _high;
	}
};

//Class XMLWorker its a solution class
class XMLWorker
{
private:
	string myXml; //for read xml from file
	string pathSourceXmlFile;
	vector<Interval> myInterval; //Vector with intervals
	vector<int> lowLocate; //Locate position of low data
	vector<int> highLocate; //Locate position of high data
	vector<string> lows; //Vector of lows data
	vector<string> highs; //Vector of highs data
	list<int> primeNumbers; //List of primeNumbers
	int count; // count of intervals
	bool checkPrimeNumber(int _number); //checking prime numbers
public:
	XMLWorker();
	XMLWorker(string _path);
	void loadXmlFromFile(string _path);
	void getIntervals();
	void calculatePrimeNumbers();
	void saveXmlToSourceFile();
	~XMLWorker();
};