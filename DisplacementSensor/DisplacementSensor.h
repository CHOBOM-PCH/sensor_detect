#include "RF60x.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#pragma comment(lib,"RF60x.lib")

void SensorMeasurement(const char *Port, double *distance);