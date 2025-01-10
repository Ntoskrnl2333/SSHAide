#include "sshaide.h"

char KBNowHit() {
	return kbhit() ? getch() : '\0';
}

char KBWaitHit() {
	return getch();
}

string KBGetNextString() {
	char buf[STR_MAX_SIZE];

}