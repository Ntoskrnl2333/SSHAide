#include "sshaide.h"

class __Settings {
public:
	bool cls = SA_CLEAR_SCREEN_ON_START;
	bool ctetml = SA_CREATE_ANOTHER_TERMINAL;
	bool nmap = SA_USE_NMAP_TO_SEARCH_SERVERS;
	bool ping = SA_PING_SERVER_BEFORE_CALL_SSH;
	bool pause = SA_PAUSE_AFTER_CALLING_SSH;
}Settings;

int main(int argc, char **argv) {
	AnalArgs(argc, argv);
	if (Settings.ctetml) {
		RestartInNewTerminal(argc,argv);
		exit(SA_ERROR_NOERROR);
	}
	if (Settings.cls)
		ClearScreen();

	/// <summary>
	///	TODO: nmap and ping support
	/// </summary>
	
	string IP = GetTargetServerIP();

	string Username = GetTargetUsername();

	CallExecutable("ssh.exe", Username+" "+IP);
	
	if (Settings.pause)
		Pause();
	return 0;
}

void AnalArgs(int argc, char** argv,__Settings &set) {
	for (int i = 0; i < argc; i++) {
		bool disable=false;
		string arg = argv[i];

		if (arg.back() == '!') {
			disable = true;
			arg.pop_back();
		}
		
		if (arg == "/cls")
			set.cls = !disable;
		if (arg == "/ctetml")
			set.ctetml = !disable;
		if (arg == "/nmap")
			set.nmap = !disable;
		if (arg == "/ping")
			set.ping = !disable;
		if (arg == "/pause")
			set.pause = !disable;
	}
}