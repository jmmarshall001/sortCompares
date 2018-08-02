//**************************************************************************************************** 
// 
//            File:		         sortCompares.cpp
//
//            Student:           John Malcolm Marshall
//
//            Assignment:        Program  # 13
//
//            Course Name:       Data Structures II
//
//            Course Number:     COSC 3100 - 01 
// 
// 
//            This program compares a variety of sort functions.
// 
//            Other files required: 
//						results.h - Stores results values.
//  
//****************************************************************************************************

#include<iostream>
#include<iomanip>
#include<utility>
#include<fstream>
using namespace std;
#include "results.h"

//****************************************************************************************************

void getData(int list[], int size, char filename[]);

//****************************************************************************************************

void insertSort(int list[], int & comp, int & cpy, int size);

//****************************************************************************************************

void selectionSort(int list[], int & comp, int & cpy, int size);

//****************************************************************************************************

void bubbleSort(int list[], int & comp, int & cpy, int size);

//****************************************************************************************************

void shellSort(int list[], int & comp, int & cpy, int size);

//****************************************************************************************************

void heapSort(int list[], int & comp, int & cpy, int size);

//****************************************************************************************************

void _siftUp(int list[], int child, int & comp, int & cpy);

//****************************************************************************************************

void _siftDown(int list[], int parent, int size, int & comp, int & cpy);

//****************************************************************************************************

void quickSort(int list[], int & comp, int & cpy, int size);

//****************************************************************************************************

void quickS(int list[], int low, int high, int & comp, int & cpy);

//****************************************************************************************************

void putMedLeft(int list[], int low, int high, int & comp, int & cpy);

//****************************************************************************************************

int partition(int list[], int low, int high, int & comp, int & cpy);

//****************************************************************************************************

void calcResults(Results & result);

//****************************************************************************************************

void displayResults(Results iResults, Results bResults, Results sResults, Results shResults,
	Results hResults, Results qResults);

//****************************************************************************************************

int main()
{
	int ordered[1000],
		unOrdered[1000],
		reversed[1000];

	Results iResults,
		sResults,
		bResults,
		shResults,
		hResults,
		qResults;

	getData(ordered, 1000, "ordered.txt");
	getData(unOrdered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");

	insertSort(ordered, iResults.ordCompares, iResults.ordCopies, 1000);
	insertSort(unOrdered, iResults.unOrdCompares, iResults.unOrdCopies, 1000);
	insertSort(reversed, iResults.revOrdCompares, iResults.revOrdCopies, 1000);

	calcResults(iResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unOrdered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");

	selectionSort(ordered, sResults.ordCompares, sResults.ordCopies, 1000);
	selectionSort(unOrdered, sResults.unOrdCompares, sResults.unOrdCopies, 1000);
	selectionSort(reversed, sResults.revOrdCompares, sResults.revOrdCopies, 1000);

	calcResults(sResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unOrdered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");

	bubbleSort(ordered, bResults.ordCompares, bResults.ordCopies, 1000);
	bubbleSort(unOrdered, bResults.unOrdCompares, bResults.unOrdCopies, 1000);
	bubbleSort(reversed, bResults.revOrdCompares, bResults.revOrdCopies, 1000);

	calcResults(bResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unOrdered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");

	shellSort(ordered, shResults.ordCompares, shResults.ordCopies, 1000);
	shellSort(unOrdered, shResults.unOrdCompares, shResults.unOrdCopies, 1000);
	shellSort(reversed, shResults.revOrdCompares, shResults.revOrdCopies, 1000);

	calcResults(shResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unOrdered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");

	heapSort(ordered, hResults.ordCompares, hResults.ordCopies, 1000);
	heapSort(unOrdered, hResults.unOrdCompares, hResults.unOrdCopies, 1000);
	heapSort(reversed, hResults.revOrdCompares, hResults.revOrdCopies, 1000);

	calcResults(hResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unOrdered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");

	quickSort(ordered, qResults.ordCompares, qResults.ordCopies, 1000);
	quickSort(unOrdered, qResults.unOrdCompares, qResults.unOrdCopies, 1000);
	quickSort(reversed, qResults.revOrdCompares, qResults.revOrdCopies, 1000);

	calcResults(qResults);

	displayResults(iResults, bResults, sResults, shResults, hResults, qResults);
}

//****************************************************************************************************

void getData(int list[], int size, char filename[])
{
	ifstream iFile(filename);

	for (int i = 0; i < size; i++)
	{
		iFile >> list[i];
	}
}

//****************************************************************************************************

void insertSort(int list[], int & comp, int & cpy, int size)
{
	int hold,
		x;

	for (int pass = 1; pass < size; pass++)
	{
		hold = list[pass];
		cpy++;

		for (x = (pass - 1); (x >= 0) && (++comp) && (list[x] > hold); x--)
		{
			list[x + 1] = list[x];
			cpy++;
		}

		list[x + 1] = hold;
		cpy++;
	}
}

//****************************************************************************************************

void selectionSort(int list[], int & comp, int & cpy, int size)
{
	int min;

	for (int i = 0; i < (size - 1); i++)
	{
		min = i;

		for (int n = (i + 1); n < size; n++)
		{
			if ((++comp) && (list[n] < list[min]))
			{
				min = n;
			}
		}

		swap(list[i], list[min]);
		cpy = cpy + 3;
	}
}

//****************************************************************************************************

void bubbleSort(int list[], int & comp, int & cpy, int size)
{
	bool notSorted = true;

	for (int pass = 0; (notSorted) && (pass < size); pass++)
	{
		notSorted = false;

		for (int i = (size - 1); i > pass; i--)
		{
			if ((++comp) && (list[i] < list[i - 1]))
			{
				swap(list[i], list[i - 1]);
				cpy = cpy + 3;
				notSorted = true;
			}
		}
	}
}

//****************************************************************************************************

void shellSort(int list[], int & comp, int & cpy, int size)
{
	int hold,
		i;

	for (int gap = (size / 2); gap >= 10; gap = (gap / 2))
	{
		if ((gap % 2) == 0)
		{
			gap++;
		}

		for (int pass = gap; pass < size; pass++)
		{
			hold = list[pass];
			cpy++;

			for (i = (pass - gap); (i >= 0) && (++comp) && (list[i] > hold); i = (i - gap))
			{
				list[i + gap] = list[i];
				cpy++;
			}

			list[i + gap] = hold;
			cpy++;
		}
	}

	insertSort(list, comp, cpy, size);
}

//****************************************************************************************************

void heapSort(int list[], int & comp, int & cpy, int size)
{
	int hold;

	for (int n = 1; n < size; n++)
	{
		_siftUp(list, n, comp, cpy);
	}

	for (int pass = size - 1; pass > 0; pass--)
	{
		hold = list[pass];
		cpy++;
		list[pass] = list[0];
		cpy++;
		list[0] = hold;
		cpy++;
		_siftDown(list, 0, pass, comp, cpy);
	}
}

//****************************************************************************************************

void _siftUp(int list[], int child, int & comp, int & cpy)
{
	int parent;

	if (child > 0)
	{
		parent = ((child - 1) / 2);

		if ((++comp) && (list[child] > list[parent]))
		{
			swap(list[child], list[parent]);
			cpy = cpy + 3;
			_siftUp(list, parent, comp, cpy);
		}
	}
}

//****************************************************************************************************

void _siftDown(int list[], int parent, int size, int & comp, int & cpy)
{
	int child = ((2 * parent) + 1);

	if (child < size)
	{
		if (((child + 1) < size) && (++comp) && (list[child] < list[child + 1]))
		{
			child++;
		}

		if ((++comp) && (list[child] > list[parent]))
		{
			swap(list[child], list[parent]);
			cpy = cpy + 3;
			_siftDown(list, child, size, comp, cpy);
		}
	}
}

//****************************************************************************************************

void quickSort(int list[], int & comp, int & cpy, int size)
{
	quickS(list, 0, (size - 1), comp, cpy);
	insertSort(list, comp, cpy, size);
}

//****************************************************************************************************

void quickS(int list[], int low, int high, int & comp, int & cpy)
{
	int pivotLoc;

	if (((high - low) +1) > 10)
	{
		putMedLeft(list, low, high, comp, cpy);
		pivotLoc = partition(list, low, high, comp, cpy);
		quickS(list, low, (pivotLoc - 1), comp, cpy);
		quickS(list, (pivotLoc + 1), high, comp, cpy);
	}
}

//****************************************************************************************************

void putMedLeft(int list[], int low, int high, int & comp, int & cpy)
{
	int mid = (low + high) / 2;

	if ((++comp) && (list[low] < list[mid]))
	{
		swap(list[low], list[mid]);
		cpy = cpy + 3;
	}

	if ((++comp) && (list[high] < list[mid]))
	{
		swap(list[high], list[mid]);
		cpy = cpy + 3;
	}

	if ((++comp) && (list[high] < list[low]))
	{
		swap(list[high], list[low]);
		cpy = cpy + 3;
	}
}
//****************************************************************************************************

int partition(int list[], int low, int high, int & comp, int & cpy)
{
	int lte = low,
		gt = high;

	while (lte < gt)
	{
		while ((++comp) && (list[++lte] <= list[low]));

		while ((++comp) && (list[--gt] > list[low]));

		if (lte < gt)
		{
			swap(list[lte], list[gt]);
			cpy = cpy + 3;
		}
	}

	swap(list[low], list[gt]);
	cpy = cpy + 3;

	return gt;
}

//****************************************************************************************************

void calcResults(Results & results)
{
	results.avgCompares = (results.ordCompares + results.revOrdCompares + results.unOrdCompares) / 3;
	results.avgCopies = (results.ordCopies + results.revOrdCopies + results.unOrdCopies) / 3;
}

//****************************************************************************************************

void displayResults(Results iResults, Results bResults, Results sResults, Results shResults,
	Results hResults, Results qResults)
{
	cout << setw(30) << " " << "Compares/Copies" << endl << endl;

	cout << setw(10) << left << "Sorts:" << setw(15) << "Ordered List" << setw(15)
		<< "UnOrdered List" << setw(15) << "Reversed List" << setw(15) << "Average" << endl << endl;
	
	cout << setw(10) << "Insertion" << iResults.ordCompares << "/" << iResults.ordCopies << setw(7)
		<< " " <<	iResults.unOrdCompares << "/" << iResults.unOrdCopies << setw(2) << " " <<
		iResults.revOrdCompares << "/" << iResults.revOrdCopies << setw(2) << " " 
		<< iResults.avgCompares << "/" << iResults.avgCopies << endl << endl;

	cout << setw(10) << "Selection" << sResults.ordCompares << "/" << sResults.ordCopies << setw(4)
		<< " " << sResults.unOrdCompares << "/" << sResults.unOrdCopies << setw(4) << " " <<
		sResults.revOrdCompares << "/" << sResults.revOrdCopies << setw(4) << " "
		<< sResults.avgCompares << "/" << sResults.avgCopies << endl << endl;

	cout << setw(10) << "Bubble" << bResults.ordCompares << "/" << bResults.ordCopies << setw(10)
		<< " " << bResults.unOrdCompares << "/" << bResults.unOrdCopies << setw(2) << " " <<
		bResults.revOrdCompares << "/" << bResults.revOrdCopies << setw(1) << " "
		<< bResults.avgCompares << "/" << bResults.avgCopies << endl << endl;

	cout << setw(10) << "Shell" << shResults.ordCompares << "/" << shResults.ordCopies << setw(5)
		<< " " << shResults.unOrdCompares << "/" << shResults.unOrdCopies << setw(4) << " " <<
		shResults.revOrdCompares << "/" << shResults.revOrdCopies << setw(4) << " "
		<< shResults.avgCompares << "/" << shResults.avgCopies << endl << endl;

	cout << setw(10) << "Heap" << hResults.ordCompares << "/" << hResults.ordCopies << setw(4)
		<< " " << hResults.unOrdCompares << "/" << hResults.unOrdCopies << setw(4) << " " <<
		hResults.revOrdCompares << "/" << hResults.revOrdCopies << setw(4) << " "
		<< hResults.avgCompares << "/" << hResults.avgCopies << endl << endl;

	cout << setw(10) << "Quick" << qResults.ordCompares << "/" << qResults.ordCopies << setw(6)
		<< " " << qResults.unOrdCompares << "/" << qResults.unOrdCopies << setw(5) << " " <<
		qResults.revOrdCompares << "/" << qResults.revOrdCopies << setw(6) << " "
		<< qResults.avgCompares << "/" << qResults.avgCopies << endl << endl;
}

//****************************************************************************************************
