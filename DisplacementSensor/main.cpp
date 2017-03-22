
#include "DisplacementSensor.h"

int main()
{
	
	const char* port;
	double height;
	port = "COM3:";
	SensorMeasurement(port,&height);
	
	printf("°Å¸® : %lf mm\n",height);
	system("pause");
}