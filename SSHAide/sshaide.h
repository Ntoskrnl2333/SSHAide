#pragma once

#include "defines.h"

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <cstring>
#include <string>
#include <conio.h>

using namespace std;

//Constants
enum {
	SA_ERROR_NOERROR,
	SA_ERROR_UNKNOWN,
};
#define STR_MAX_SIZE 4096

//Classes
extern class __Settings;
extern __Settings Settings;

//Main
extern int main(int argc,char **argv);
extern void AnalArgs(int argc,char **argv,__Settings &set=Settings);

//SysApi
extern void RestartInNewTerminal(int argc, char** argv);
extern void Pause();
extern int CallExecutable(string path,string args);

//Output
extern void ClearScreen();
extern void PutChar(char c);
extern void PutString(char* s);
extern void PutString(string s);

//Keyboard
extern char KBNowHit();
extern char KBWaitHit();
extern string KBGetNextLine();

//Mouse

//UI
extern string GetTargetServerIP();
extern string GetTargetUsername();
extern string GetTargetPassword(); //Unused