#include "XMLWorker.h"

bool XMLWorker::checkPrimeNumber(int _number)
{
	int i;
	if (_number == 2)
		return 1;
	if (_number == 0 ||_number == 1 || _number % 2 == 0)
		return 0;
	for (i = 3; i*i <= _number && _number % i; i += 2)
		;
	return i*i > _number;
}

XMLWorker::XMLWorker()
{
	load.LoadFile("scene.xml");
	myXml = load.getContent();
}

XMLWorker * XMLWorker::get_instance()
{
	if (!instance)
	{
		instance = new XMLWorker;
	}
	return instance;
}

void XMLWorker::parseXmlFile(string _tag, vector<string>& _buffer)
{
	size_t posBegin = 0;
	size_t posEnd = 0;
	string openTag = "<" + _tag + ">";
	string closeTag = "</" + _tag + ">";

	while (true)
	{
		posBegin = myXml.find(openTag, posBegin); //find open tag in xml file
		if (posBegin == string::npos)
		{
			break;
		}
		posBegin += openTag.length();
		
		posEnd = myXml.find(closeTag, posBegin); //find close tag in xml file
		if (posEnd == string::npos)
		{
			cout << "Close tag not found" << endl;
			exit(-1);
		}
		string value = myXml.substr(posBegin, posEnd - posBegin); //get value this tag
		value.erase(remove_if(value.begin(), value.end(), isspace), value.end()); //remove spaces from string
		if (value.length() == 0)
		{
			cout << "empty string" << endl;
			exit(-4);
		}
		_buffer.push_back(value);
		posBegin = posEnd;
	}
}

void XMLWorker::getIntervals()
{
	parseXmlFile("low", lows);
	parseXmlFile("high", highs);
	for (int i = 0; i < lows.size(); i++)
	{
		myInterval.emplace_back(std::stoi(lows[i]), std::stoi(highs[i]));
	}
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
	ofstream out(load.getPathSourceXmlFile(), ios_base::out | ios_base::trunc);
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
	if (instance != nullptr)
	{
		delete instance;
	}
}
