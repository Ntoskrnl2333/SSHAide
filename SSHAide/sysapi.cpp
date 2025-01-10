#include "sshaide.h"

void RestartInNewTerminal(){
	string cmd;
	wchar_t path[MAX_PATH];  // 用于存储路径
	// 获取当前程序的绝对路径
	GetModuleFileName(NULL, path, MAX_PATH);
	
}