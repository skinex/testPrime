#pragma once
#include "stdafx.h"

class XMLLoader
{
private:
	string xmlFile; //data of xml file
	string pathSourceXmlFile; //path to xml file
public:
	XMLLoader() = default;
	XMLLoader(string _path);
	void LoadFile(string _path);
	string getContent() const;
	string getPathSourceXmlFile() const;
	~XMLLoader() = default;
};