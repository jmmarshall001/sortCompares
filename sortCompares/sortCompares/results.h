//**************************************************************************************************** 
// 
//            File:		         results.h
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
//						sortCompares.cpp - Driver file, contains sort functions.
//  
//****************************************************************************************************

#ifndef RESULTS_H
#define RESULTS_H

//****************************************************************************************************

struct Results
{
	int ordCompares;
	int unOrdCompares;
	int revOrdCompares;
	int avgCompares;
	int ordCopies;
	int unOrdCopies;
	int revOrdCopies;
	int avgCopies;
	Results();
};

//****************************************************************************************************

Results::Results()
{
	ordCompares = 0;
	unOrdCompares = 0;
	revOrdCompares = 0;
	avgCompares = 0;
	ordCopies = 0;
	unOrdCopies = 0;
	revOrdCopies = 0;
	avgCopies = 0;
}

//****************************************************************************************************

#endif