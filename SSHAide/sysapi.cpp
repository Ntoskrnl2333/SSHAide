#include "sshaide.h"

void RestartInNewTerminal(int argc,char **argv){
	string arg;
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
	// �����������ַ�������ִ���ļ�·�� + ������
	std::string commandLine = path + " " + args;

	// ��ʼ��STARTUPINFO��PROCESS_INFORMATION�ṹ
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);

	ZeroMemory(&pi, sizeof(pi));

	// ����CreateProcess�����ӽ���
	BOOL result = CreateProcessA(
		NULL,					// ��ִ���ļ���·������NULL�����������Ѿ���commandLine�
		&commandLine[0],		 // �����У��ַ�����ʽ��
		NULL,					// ���̰�ȫ����
		NULL,					// �̰߳�ȫ����
		FALSE,				   // ���̳о��
		flag,					   // Ĭ�ϴ�����־
		NULL,					// ��������
		NULL,					// ��ǰ����Ŀ¼
		&si,					 // ������Ϣ
		&pi					  // ������Ϣ
	);

	if (result) {
		// �ȴ��ӽ���ִ�����
		WaitForSingleObject(pi.hProcess, INFINITE);

		DWORD exitCode;
		if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
			return exitCode;
		}
		else {
			return SA_ERROR_UNKNOWN;
		}

		// �رվ��
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else {
		DWORD dwError = GetLastError();
		return dwError;
	}
}
