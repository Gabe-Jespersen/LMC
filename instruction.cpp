/*
 * =====================================================================================
 *
 *       Filename:  instruction.cpp
 *
 *    Description:  instruction execution
 *
 *        Version:  1.0
 *        Created:  09/15/2014 04:22:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int add(int ACC, int mailPos, vector<int> mailBox)//adding
{
    return((ACC+mailBox.at(mailPos))%1000);
}

int sub(int ACC, int mailPos, vector<int> mailBox)//subtracting
{
    return((ACC-mailBox.at(mailPos))%1000);
}

vector<int> sta(int ACC, int saveLoc, vector<int> mailBox)//storing in memory
{
    mailBox[saveLoc] = ACC;
    return(mailBox);
}

int lda(int ACC, int readLoc, vector<int> mailBox)//loading from memory
{
    return(mailBox.at(readLoc));
}

int bra(int runLoc)//break, go to different line than current+1
{
    return(runLoc);
}

int brz(int ACC, int runLoc)//break if accumulator is 0
{
    if(ACC == 0)
    {
        return(runLoc);
    }
    else
    {
        return(-1);
    }
}

int brp(int ACC, int runLoc)//break if accumulator is greater than or equal to 0
{
    if(ACC >= 0)
    {
        return(runLoc);
    }
    else
    {
        return(-1);
    }
}

int inp()//take input, set to accumulator
{
    int ACC = 0;
    cin >> ACC;
    return(ACC);
}

void out(int ACC)//output accumulator
{
    cout << ACC << endl;
    return;
}

void hlt()//halt, ran if 000 is given
{
    exit(2);
    return;;
}
