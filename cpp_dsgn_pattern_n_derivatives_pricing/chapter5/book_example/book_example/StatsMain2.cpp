//
//
//		StatsMain2.cpp
//
//       
/*
    uses source files
    
        ConvergenceTable.cpp
        MCStatistics.cpp
        Parameters.cpp,
        PayOff3.cpp, 
        PayOffBridge.cpp,
        Random1.cpp, 
        SimpleMC7.cpp 
        Vanilla3.cpp
*/
#include<SimpleMC7.h>
#include<iostream>
using namespace std;
#include<Vanilla3.h>
#include<MCStatistics.h>
#include<ConvergenceTable.h>

#include<Terminator.h>

int main()
{

	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nStrike\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n"; //test fat finger case. eg. 1 bn paths entered.
	cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);

    VanillaOption theOption(thePayOff, Expiry);

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;
	
    ConvergenceTable gathererTwo(gatherer);

	/*
	SimpleMonteCarlo5(theOption,
	Spot,
	VolParam,
	rParam,
	NumberOfPaths,
	gathererTwo);
	*/

	//exercise 5.4 use strategy pattern to add terminator class
	//exercise 5.5 add terminator class
	Terminator terminator(60,1000000); //1 min, 1mm max iter
   
	SimpleMonteCarlo51(theOption,Spot,  VolParam, rParam,NumberOfPaths, gathererTwo, terminator);

    vector<vector<double> > results =gathererTwo.GetResultsSoFar();
	cout <<"\nFor the call price the results are \n";

    for (unsigned long i=0; i < results.size(); i++)
    {
        for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";

        cout << "\n";
    }


    
    double tmp;
    cin >> tmp;

	return 0;

}

/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
*/

