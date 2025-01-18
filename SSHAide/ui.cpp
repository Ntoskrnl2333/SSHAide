#include "sshaide.h"

string GetTargetServerIP() {
	PutString("Input the IP of the server:\n>> ");
	return KBGetNextLine();
}

string GetTargetUsername(){
	PutString("Input the username:\n>> ");
	return KBGetNextLine();
}
