#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
using namespace std;

template <typename C>
void mergeSort(vector<C>& v);

template <typename C>
void mergeSort(vector<C>& v, vector<C>& tmp, int left, int right);

template <typename C>
void merge(vector<C>& v, vector<C>& tmp, int leftPos, int rightPos, int rightEnd);

/*
* Mergesort algorithm (driver)
*/
template <typename C>
void mergeSort(vector<C>& v)
{
	vector<C> tmp(v.size());
	mergeSort(v, tmp, 0, v.size() - 1);
}

/**
* Internal method that makes recursive calls.
* v is a vector of Comparable items.
* tmp is a vector to place the merged results.
* left is the leftmost index of the subvector
* right is the rightmost index of the subvector
*/
template <typename C>
void mergeSort(vector<C>& v, vector<C>& tmp, int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(v, tmp, left, center);
		mergeSort(v, tmp, center + 1, right);
		merge(v, tmp, left, center + 1, right);
	}
}

/**
* Internal method that merges two sorted halves of a subvector
* v is a vector of Comparable items.
* tmp is a vector to place the merged results.
* leftPos is the left-most index of the subvector
* rightPos is the index of the start of the second half.
* rightEnd if the right-most index of the subvector.
*/

template <typename C>
void merge(vector<C>& v, vector<C>& tmp, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (v[ leftPos ] <= v[ rightPos ])
			tmp[ tmpPos++ ] = v[ leftPos++ ];
		else
			tmp[ tmpPos++ ] = v[ rightPos++ ];
	}

	while (leftPos <= leftEnd) // Copy the rest of first half
	{
		tmp[ tmpPos++ ] = v[ leftPos++ ];
	}

	while (rightPos <= rightEnd) // copy the rest if second half
	{
		tmp[ tmpPos++ ] = v[ rightPos++ ] ;
	}

	// copy tmp back
	for (int i = 0; i < numElements; ++i, --rightEnd)
	{
		v[ rightEnd ] = tmp[ rightEnd ];
	}
}

#endif
