#include "XMLWorker.h"

bool XMLWorker::checkPrimeNumber(int _number)
{
	if (_number == 0 || _number == 1)
	{
		return false;
	}
	bool res = true;
	for (int i = 2; i < _number / 2; i++)
	{
		if (_number % i == 0)
		{
			res = false;
		}
	}
	return res;
}

XMLWorker::XMLWorker() : count(0)
{
}

XMLWorker * XMLWorker::get_instance()
{
	if (!set_instance)
	{
		set_instance = new XMLWorker;
	}
	return set_instance;
}

void XMLWorker::loadXmlFromFile(string _path)
{
	pathSourceXmlFile = _path;
	ifstream in(_path, ios_base::in);
	std::getline(in, myXml, '\0');
	in.close();
}

void XMLWorker::getIntervals()
{
	//Get Count Low Intervals
	size_t nPos = myXml.find("low", 0); // fist occurrence of low
	lowLocate.push_back(nPos);
	while (nPos < string::npos)
	{
		nPos = myXml.find("low", nPos + 4);
		if (nPos != string::npos)
		{
			lowLocate.push_back(nPos);
		}
		count++; //Its a count of all intervals / 2
	}
	//Get Count High Intervalse
	size_t nPosH = myXml.find("high", 0); // fist occurrence of high
	highLocate.push_back(nPosH);
	while (nPosH < string::npos)
	{
		nPosH = myXml.find("high", nPosH + 5);
		if (nPosH != string::npos)
		{
			highLocate.push_back(nPosH);
		}
	}
	//Input data intervals in vectors
	for (int i = 0; i < count; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			continue;
		}
		lows.push_back(myXml.substr(lowLocate[i] + 4, lowLocate[i + 1] - lowLocate[i] - 6));
		highs.push_back(myXml.substr(highLocate[i] + 5, highLocate[i + 1] - highLocate[i] - 7));
	}
	//Remove spaces in data
	for (int i = 0; i < lows.size(); i++)
	{
		lows[i].erase(remove_if(lows[i].begin(), lows[i].end(), isspace), lows[i].end());
		highs[i].erase(remove_if(highs[i].begin(), highs[i].end(), isspace), highs[i].end());
	}
	//Put intervals in vector of Interval
	for (int i = 0; i < lows.size(); i++)
	{
		myInterval.emplace_back(std::stoi(lows[i]), std::stoi(highs[i]));
	}
}

void XMLWorker::getIntervalsInThread()
{
	std::thread intervalThread(&XMLWorker::getIntervals, this);
	intervalThread.join();
}

void XMLWorker::calculatePrimeNumbers()
{
	//Calculate the prime numbers
	for (int i = 0; i < lows.size(); i++)
	{
		for (int j = myInterval[i].low; j < myInterval[i].high; j++)
		{
			if (checkPrimeNumber(j))
			{
				primeNumbers.push_back(j);
			}
		}
	}
}

void XMLWorker::saveXmlToSourceFile()
{
	ofstream out("scene.xml", ios_base::out | ios_base::trunc);
	myXml.insert(myXml.length() - 9, "\n <primes>");
	for (auto it = primeNumbers.begin(); it != primeNumbers.end(); it++)
	{
		myXml.insert(myXml.length() - 9, " " + std::to_string(*it) + " ");
	}
	myXml.insert(myXml.length() - 9, " </primes>");
	out << myXml;
	out.close();
}

XMLWorker::~XMLWorker()
{
}
