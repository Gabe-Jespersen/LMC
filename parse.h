/*
 * =====================================================================================
 *
 *       Filename:  parse.h
 *
 *    Description:  parse.cpp header file
 *
 *        Version:  1.0
 *        Created:  09/15/2014 06:44:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>

#ifndef PARSE_H
#define PARSE_H

std::vector<int> toRunParse(int,char**);
std::vector<int> flagsParse(int,char**);
void helpMenu();

#endif
