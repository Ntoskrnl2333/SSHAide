#pragma once

#include "defines.h"

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <cstring>
#include <string>

using namespace std;

extern class __Settings;
extern __Settings Settings;

extern int main(int argc,char **argv);
extern void AnalArgs(int argc,char **argv,__Settings &set=Settings);

extern void RestartInNewTerminal();

extern void ClearScreen();
extern void PutChar(char c);
extern void PutString(char* s);
extern void PutString(string s);