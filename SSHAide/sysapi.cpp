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

int _cdecl CallExecutable(string path, string args){
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
		0,					   // Ĭ�ϴ�����־
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
