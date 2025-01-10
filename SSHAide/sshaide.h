#pragma once

#include "defines.h"

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <cstring>
#include <string>
#include <conio.h>

using namespace std;

enum {
	SA_ERROR_NOERROR,
	SA_ERROR_UNKNOWN,
};

extern class __Settings;
extern __Settings Settings;

extern int main(int argc,char **argv);
extern void AnalArgs(int argc,char **argv,__Settings &set=Settings);

extern void RestartInNewTerminal(int argc, char** argv);
extern void Pause();

extern void ClearScreen();
extern void PutChar(char c);
extern void PutString(char* s);
extern void PutString(string s);

extern char KBNowHit();
extern char KBWaitHit();
extern string KBGetNextString();

extern string GetIP();