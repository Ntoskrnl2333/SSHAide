#include "sshaide.h"

void RestartInNewTerminal(int argc,char **argv){
	string arg;
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
	
	arg += " ";
	for (int i = 1; i < argc; i++)
		arg += argv[i], arg += " ";
	arg += " /ctetml!";

	//system(arg.c_str());
	CallExecutable(_path, arg, 0x10);
}

void Pause() {
	system("pause");
}

int CallExecutable(string path, string args,uint flag){
	// 创建命令行字符串（可执行文件路径 + 参数）
	std::string commandLine = path + " " + args;

	// 初始化STARTUPINFO和PROCESS_INFORMATION结构
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);

	ZeroMemory(&pi, sizeof(pi));

	// 调用CreateProcess启动子进程
	BOOL result = CreateProcessA(
		NULL,					// 可执行文件的路径（传NULL代表命令行已经在commandLine里）
		&commandLine[0],		 // 命令行（字符串形式）
		NULL,					// 进程安全属性
		NULL,					// 线程安全属性
		FALSE,				   // 不继承句柄
		flag,					   // 默认创建标志
		NULL,					// 环境变量
		NULL,					// 当前工作目录
		&si,					 // 启动信息
		&pi					  // 进程信息
	);

	if (result) {
		// 等待子进程执行完毕
		WaitForSingleObject(pi.hProcess, INFINITE);

		DWORD exitCode;
		if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
			return exitCode;
		}
		else {
			return SA_ERROR_UNKNOWN;
		}

		// 关闭句柄
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else {
		DWORD dwError = GetLastError();
		return dwError;
	}
}
