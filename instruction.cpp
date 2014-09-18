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

int add(int ACC, int mailPos, vector<int> mailBox)
{
    return((ACC+mailBox.at(mailPos))%1000);
}

int sub(int ACC, int mailPos, vector<int> mailBox)
{
    return((ACC-mailBox.at(mailPos))%1000);
}

vector<int> sta(int ACC, int saveLoc, vector<int> mailBox)
{
    mailBox[saveLoc] = ACC;
    return(mailBox);
}

int lda(int ACC, int readLoc, vector<int> mailBox)
{
    return(mailBox.at(readLoc));
}

int bra(int runLoc)
{
    return(runLoc);
}

int brz(int ACC, int runLoc)
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

int brp(int ACC, int runLoc)
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

int inp()
{
    int ACC = 0;
    cin >> ACC;
    return(ACC);
}

void out(int ACC)
{
    cout << ACC << endl;
    return;
}

void hlt()
{
    exit(1);
    return;;
}
