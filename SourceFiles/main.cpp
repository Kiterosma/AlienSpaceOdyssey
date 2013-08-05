#include "application.h"
#include "menu.h"
//#include "vld.h"

using namespace sf;
using namespace std;

int main()
{
	//VLDEnable();
	//int* i = new int(1); //get rid of this statement after memory leak checker is working
	
	Application* application = new Application();

	if(application->initialize(new Menu(application)))
		application->run();
	else while(true);

	delete application;
	application=NULL;

	//VLDReportLeaks();

    return 0;
}