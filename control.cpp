/*
 * =====================================================================================
 *
 *       Filename:  instruction.cpp
 *
 *    Description:  running and scheduling instructions
 *
 *        Version:  1.0
 *        Created:  09/15/2014 01:51:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>
#include <cstdlib>

#include "instruction.h"

using namespace std;

vector<vector <int> > command(int input, int ACC, vector<int> mailBox, int runLoc)
{
    bool runLocEdited = false;
    vector<vector <int> > toReturn;
    if(input < 0||input > 999)
    {
        toReturn = {{runLoc+1},{ACC},mailBox};//+1 to go to next instruction
        return(toReturn);
    }
    else
    {
        if(input < 100)
        {
            if(input == 0)
                hlt();   //not doing anything else, can't find what to do
                         //if it is 0xx
        }
        
        else if(input < 200)
        {
            ACC = add(ACC, input%100, mailBox);
        }
        else if(input < 300)
        {
            ACC = sub(ACC, input%100, mailBox);
        }
        else if(input < 400)
        {
            mailBox = sta(ACC, input%100, mailBox);
        }
        else if(input < 600)
        {
            if(input > 499)
            {
                ACC = lda(ACC, input%100, mailBox);
            }
            //no defined behavior for 4xx
        }
        else if(input < 700)
        {
            runLoc = bra(input%100);
            runLocEdited = true;
        }
        else if(input < 800)
        {
            runLoc = brz(ACC, input%100);
            runLocEdited = true;
        }
        else if(input < 900)
        {
            runLoc = brp(ACC, input%100);
            runLocEdited = true;
        }
        else if(input == 901)
        {
            ACC = inp();
        }
        else if(input == 902)
        {
            out(ACC);
        }
    }
    if(!runLocEdited)
    {
        runLoc++;
    }
    toReturn = {{runLoc},{ACC},mailBox};
    return(toReturn);
}
