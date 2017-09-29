#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>
#include <thread>
#include <mutex>


using std::string;
using std::list;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ios_base;
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

//Class XMLWorker its a solution class using Singletone pattern
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
	static XMLWorker *set_instance;
	XMLWorker(); //private constructor for a singletone pattern
	bool checkPrimeNumber(int _number); //checking prime numbers
	void getIntervals(); 
public:
	//XMLWorker(string _path);
	static XMLWorker *get_instance();
	void loadXmlFromFile(string _path);
	void getIntervalsInThread();
	void calculatePrimeNumbers();
	void saveXmlToSourceFile();
	~XMLWorker();
};