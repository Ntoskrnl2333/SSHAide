#include "sshaide.h"

void RestartInNewTerminal(int argc,char **argv){
	string cmd;
	wchar_t path[STR_MAXSIZE];  // ���ڴ洢·��
	// ��ȡ��ǰ����ľ���·��
	GetModuleFileName(NULL, path, STR_MAXSIZE);
	char _path[STR_MAXSIZE];  // ���ڴ洢ת�����խ�ַ��ַ���
	// �����ַ��ַ���ת��Ϊ���ֽ��ַ��ַ�����UTF-8��
	int len = WideCharToMultiByte(	CP_UTF8,
									0,
									path,
									-1,
									_path,
									sizeof(_path),
									NULL,
									NULL);
	if (len <= 0) {
		PutString("Unknown Error!");
		exit(SA_ERROR_UNKNOWN);
	}
	
	cmd += _path;
	cmd += " ";
	for (int i = 1; i < argc; i++)
		cmd += argv[i], cmd += " ";
	cmd += " /ctetml!";

	system(cmd.c_str());
}

void Pause() {
	system("pause");
}