#pragma once

class Sort
{
protected:
	int Reshuffle;
	int *mas;
	int count;

public:
	Sort()
	{
		Reshuffle = 0;
	};

	int GetReshuffle()
	{
		return Reshuffle;
	}

	int* GetMas()
	{
		return mas;
	}

	virtual void sort() = 0;
};