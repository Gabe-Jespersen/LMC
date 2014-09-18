/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  main file for little man computer
 *
 *        Version:  1.0
 *        Created:  09/14/2014 09:27:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <iostream>

#include "control.h"
#include "parse.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<int> toRun;
    vector<int> settings;
    vector<vector <int> > curState;

    toRun    = toRunParse(argc,argv); //setting the array of commands to run  
    settings = flagsParse(argc,argv); //getting settings, currently only debug
        //reading flag settings
        int printVariables = settings.at(0);


    //horrible code 101
    curState = {{0},{0},{0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0}};//this is exactly 100 0s, for
                                               //why this is done, see: main.cpp:37


    while(curState.at(0).at(0) < toRun.size())//while there is commands
    {
        if(printVariables != 0) //if -d was given
        {
            //prints current instructions, line #, and all memory
            cout << curState.at(0).at(0) << ',' << curState.at(1).at(0) << ',' << toRun.at(curState.at(0).at(0)) << endl;
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    cout << curState.at(2).at((i*10)+j);
                }
                cout << endl;
            }
        }
        //runs the next command
        curState = command(toRun.at(curState.at(0).at(0)),curState.at(1).at(0),curState.at(2),curState.at(0).at(0));
    }
    return 1;
}
