#include "XMLWorker.h"

int main()
{
	try
	{
		XMLWorker *xmlWorker = new XMLWorker();
		xmlWorker->loadXmlFromFile("scene.xml");
		xmlWorker->getIntervals();
		xmlWorker->calculatePrimeNumbers();
		xmlWorker->saveXmlToSourceFile();
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}