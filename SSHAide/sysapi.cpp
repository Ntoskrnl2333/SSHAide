#include "sshaide.h"

void RestartInNewTerminal(int argc,char **argv){
	string cmd;
	wchar_t path[STR_MAXSIZE];  // 用于存储路径
	// 获取当前程序的绝对路径
	GetModuleFileName(NULL, path, STR_MAXSIZE);
	char _path[STR_MAXSIZE];  // 用于存储转换后的窄字符字符串
	// 将宽字符字符串转换为多字节字符字符串（UTF-8）
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