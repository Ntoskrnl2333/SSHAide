#include "sshaide.h"

char KBNowHit() {
	return _kbhit() ? _getch() : '\0';
}

char KBWaitHit() {
	return _getch();
}

string KBGetNextLine() {
	char buf[STR_MAX_SIZE];
	char *p = buf, *end=buf+STR_MAX_SIZE;
	while (p != end) {
		*p = KBWaitHit();

		if (*p == '\b')
			PutString("\b \b");
		else if (*p == '\n' || *p == '\r'){
			PutChar('\n');
			break;
		}
		else
			PutChar(*p);

		p++;
	}
	*p = '\0';
	return buf;
}