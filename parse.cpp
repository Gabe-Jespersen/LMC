/*
 * =====================================================================================
 *
 *       Filename:  parse.cpp
 *
 *    Description:  parsing file, mainly to find the code to run
 *
 *        Version:  1.0
 *        Created:  09/15/2014 06:20:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>

#include "parse.h"

using namespace std;


vector<int> toRunParse(int argc, char **argv)
{
    if(argc < 2)//if there just isn't enough instructions to find code to run
    {
        cout << "Error: code not found\n";
        helpMenu();
        exit(1);
    }
    else
    {
        for(int i = 1; i < argc; i++)//starting at 1, argv[0] will just be ./LMC
        {
            if(!strcmp(argv[i],"-f") && argc > i)//file flag
            {
                ifstream file(argv[i+1], ios::in | ios::binary);//initialize file
                if(file)
                {
                    string toReturn;
                    file.seekg(0, ios::end);
                    toReturn.resize(file.tellg());
                    file.seekg(0, ios::beg);
                    file.read(&toReturn[0], toReturn.size());
                    file.close();

                    //setting a string vector to the file
                    stringstream stream(toReturn);
                    vector<string> lines;
                    while(true)
                    {
                        string line;
                        getline(stream,line);
                        if(!stream.good())
                            break;
                        lines.push_back(line);
                    }

                    //setting toRun by each input in the file, read via atoi
                    vector<int> instructions;
                    for(int i = 0; i < lines.size(); i++)
                    {
                        instructions.push_back(atoi(lines.at(i).c_str()));
                    }

                    for(int i = 0; i < instructions.size(); i++)//checking for invalid commands
                    {
                        if((instructions.at(i) < 100 && !(instructions.at(i) == 0)) || instructions.at(i) > 999)
                        {
                            cout << "Error: " << instructions.at(i) << " is not a valid instruction\n";
                            helpMenu();
                            exit(1);
                        }
                    }
                    return instructions;
                }
                else
                {
                    helpMenu();
                    exit(1);
                }
            }
            else if((!strcmp(argv[i],"-s")||!strcmp(argv[i],"-l")) && argc > i)
            //if string flag was given, read all of the inputs after and set to toRun
            {
                vector<int> instructions;
                for(int j = 1; j < (argc-i); j++)
                {
                    instructions.push_back(atoi(argv[i+j]));
                }


                for(int i = 0; i < instructions.size(); i++)
                {
                    if((instructions.at(i) < 100 && !(instructions.at(i) == 0)) || instructions.at(i) > 999)
                    {
                        cout << "Error: " << instructions.at(i) << " is not a valid instruction\n";
                        helpMenu();
                        exit(1);
                    }
                }
                return(instructions);
            }
            else
            {
                cout << "Error: could not find program to execute\n";
                helpMenu();
                exit(1);
            }
        }
    }
}

vector<int> flagsParse(int argc, char **argv)
{
    //defaults
    int debug = 0;//no debug
    //defaults


    for(int i = 1; i < argc; i++)//start at 1 because 1st flag is ./LMC
    {
        if(!strcmp(argv[i],"-d"))//if debug flag was given
        {
            debug = 1;//set to debug
        }
    }

    vector<int> toReturn = {debug};//nothing else right now
    return(toReturn);
}

void helpMenu()
{
    cout << "This program is an implementation of the Little Man Calculator(See https://en.wikipedia.org/wiki/Little_man_computer for more info)\n" <<
            "To use this, run:\n\t./executable [flags]\nWhere executable is the name of the file, defaulting to LMC.\nFlags available are:\n\t-f: file," <<
            " name of the file should be the next flag\n\t-s: string, list the commands, program assumes that you will continue commands until the last" <<
            "flag\n\t-l: same as -s\n\n\t-d: debug, prints memory every cycle\n\n";
    return;
}
