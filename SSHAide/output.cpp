#include "sshaide.h"

void ClearScreen() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD written, cells;

	// 获取控制台缓冲区信息
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}

	// 计算控制台中的字符数
	cells = csbi.dwSize.X * csbi.dwSize.Y;

	// 用空格填充整个控制台缓冲区
	FillConsoleOutputCharacter(hConsole, ' ', cells, { 0, 0 }, &written);

	// 设置字符属性
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cells, { 0, 0 }, &written);

	// 将光标位置设置回顶部
	SetConsoleCursorPosition(hConsole, { 0, 0 });
}

void PutChar(char c) {
	putchar(c);
}

void PutString(char *s) {
	printf("%s",s);
}

void PutString(string s) {
	printf("%s",s.c_str());
}