/*
 * =====================================================================================
 *
 *       Filename:  instruction.h
 *
 *    Description:  instruction.cpp header file
 *
 *        Version:  1.0
 *        Created:  09/15/2014 04:38:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

int add(int,int,std::vector<int>);
int sub(int,int,std::vector<int>);
std::vector<int> sta(int,int,std::vector<int>);
int lda(int,int, std::vector<int>);
int bra(int);
int brz(int,int);
int brp(int,int);
int inp();
void out(int);
void hlt();

#endif
