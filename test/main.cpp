#include "XMLWorker.h"

XMLWorker *XMLWorker::set_instance = 0;

int main()
{
	std::thread intervalThread;
	try
	{
		XMLWorker::get_instance()->loadXmlFromFile("scene.xml");
		XMLWorker::get_instance()->getIntervalsInThread();
		XMLWorker::get_instance()->calculatePrimeNumbers();
		XMLWorker::get_instance()->saveXmlToSourceFile();
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}