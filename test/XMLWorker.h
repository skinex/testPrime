#pragma once
#include "XMLLoader.h"

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

//Class XMLWorker its a solution class using Singletone pattern
class XMLWorker
{
private:
	//private members
	string myXml;
	XMLLoader load;
	vector<Interval> myInterval; //Vector with intervals
	vector<string> lows; //Vector of lows data
	vector<string> highs; //Vector of highs data
	list<int> primeNumbers; //List of primeNumbers
	static XMLWorker *instance; //instance for singletone

public:
	//public methods
	static XMLWorker *get_instance();
	void getIntervals(); //get intervals
	void calculatePrimeNumbers();
	void saveXmlToSourceFile();
	~XMLWorker();

private:
	//private methods
	XMLWorker(); //private constructor for a singletone pattern
	bool checkPrimeNumber(int _number); //checking prime numbers
	void parseXmlFile(string _tag, vector<string> &_buffer); //search value by specified tag
};