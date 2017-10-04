#include "XMLWorker.h"

XMLWorker *XMLWorker::instance = 0;

int main()
{
	try
	{
		XMLWorker::get_instance();
		XMLWorker::get_instance()->getIntervals();
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
