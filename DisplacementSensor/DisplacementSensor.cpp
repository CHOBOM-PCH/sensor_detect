
#include "RF60x.h"

void SensorMeasurement(const char *Port, double *distance)
{
	HANDLE hRF60x = INVALID_HANDLE_VALUE;
	DWORD dwValue;
	USHORT usMeasured;
	RF60xHELLOANSWER hlans;

	memset(&hlans, 0x00, sizeof(RF60xHELLOANSWER));

	RF60x_OpenPort(Port, CBR_9600, &hRF60x);
	if (RF60x_HelloCmd( hRF60x, 1, &hlans ))
	{
		//printf("Dev modify\t: %d\r\nDev type\t: %d\r\nDev max dist\t: %d\r\nDev range\t: %d\r\nDev serial\t: %d\r\n",		
		//	hlans.bDeviceModificaton, 
		//	hlans.bDeviceType, 
		//	hlans.wDeviceMaxDistance, 
		//	hlans.wDeviceRange, 
		//	hlans.wDeviceSerial
		//	);
		RF60x_Measure( hRF60x, 1, &usMeasured);

		//printf("Measure	\t: %d\r\n", usMeasured);
		double x = 0;
		double s = hlans.wDeviceRange;
		int m = usMeasured;
		x = (double)(s*m/16384);//x(mm)�����Ÿ��� ������ �ִ�� ��� �ִ� �Ÿ� s�� ������ m�� 4000h(16384)�� �������� ��
		*distance = x;
		
		//printf("Length : %lf mm\r\n",x);
	}else printf("rs232 error!\r\n");

}