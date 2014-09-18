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
    bool runLocEdited = false; //if it hasn't been edited, it will just return
                               //current command #+1
    vector<vector <int> > toReturn; //initializing values to return

    //don't need to check for invalid command #s, done in parse now

    else
    {
        if(input < 100)
        {
            if(input == 0)
                hlt();   //not doing anything else, can't find what to do
                         //if it is 0xx
        }
        
        else if(input < 200)//add
        {
            ACC = add(ACC, input%100, mailBox);
        }
        else if(input < 300)//subtract
        {
            ACC = sub(ACC, input%100, mailBox);
        }
        else if(input < 400)//store in memory
        {
            mailBox = sta(ACC, input%100, mailBox);
        }
        else if(input < 600)//load from memory
        {
            if(input > 499)
            {
                ACC = lda(ACC, input%100, mailBox);
            }
            //no defined behavior for 4xx
        }
        else if(input < 700)//break
        {
            runLoc = bra(input%100);
            runLocEdited = true;
        }
        else if(input < 800)//break if zero
        {
            runLoc = brz(ACC, input%100);
            runLocEdited = true;
        }
        else if(input < 900)//break if positive
        {
            runLoc = brp(ACC, input%100);
            runLocEdited = true;
        }
        else if(input == 901)//take input
        {
            ACC = inp();
        }
        else if(input == 902)//output accumulator
        {
            out(ACC);
        }
    }
    if(!runLocEdited)
    {
        runLoc++;//if there hasn't been a break
    }
    toReturn = {{runLoc},{ACC},mailBox};
    return(toReturn);
}
