#pragma once

class TrackbarClass
{
private:
	int max = 0;
	int current = 0;

public:
	void setMax(int max);
	void setCurrent(int current);
	int* getMax();
	int* getCurrent();
};
