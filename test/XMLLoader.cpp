#include "XMLLoader.h"

XMLLoader::XMLLoader(string _path)
{
	LoadFile(_path);
}

void XMLLoader::LoadFile(string _path)
{
	pathSourceXmlFile = _path;
	ifstream in(pathSourceXmlFile, ios_base::in);
	if (!in.is_open())
	{
		exit(-3);
	}
	xmlFile.assign(
		(std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>()
	);
	in.close();
}

string XMLLoader::getContent() const
{
	return xmlFile;
}

string XMLLoader::getPathSourceXmlFile() const
{
	return pathSourceXmlFile;
}
