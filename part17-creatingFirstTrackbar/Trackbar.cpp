#include "Trackbar.h"

void TrackbarClass::setMax(int max)
{
	this->max = max;
}

void TrackbarClass::setCurrent(int current)
{
	this->current = current;
}

int* TrackbarClass::getMax()
{
	return &max;
}

int* TrackbarClass::getCurrent()
{
	return &current;
}
