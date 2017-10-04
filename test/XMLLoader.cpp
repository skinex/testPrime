#include "XMLLoader.h"

XMLLoader::XMLLoader(string _path)
{
	setXmlFile(_path);
}

void XMLLoader::setXmlFile(string _path)
{
	pathSourceXmlFile = _path;
	ifstream in(pathSourceXmlFile, ios_base::in);
	xmlFile.assign(
		(std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>()
	);
	in.close();
}

string XMLLoader::getXmlFile() const
{
	return xmlFile;
}

string XMLLoader::getPathSourceXmlFile() const
{
	return pathSourceXmlFile;
}
