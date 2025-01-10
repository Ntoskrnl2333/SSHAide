#include "sshaide.h"

void ClearScreen() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD written, cells;

	// ��ȡ����̨��������Ϣ
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}

	// �������̨�е��ַ���
	cells = csbi.dwSize.X * csbi.dwSize.Y;

	// �ÿո������������̨������
	FillConsoleOutputCharacter(hConsole, ' ', cells, { 0, 0 }, &written);

	// �����ַ�����
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cells, { 0, 0 }, &written);

	// �����λ�����ûض���
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