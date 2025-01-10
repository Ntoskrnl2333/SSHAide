# SSHAide
A Win32 console tool to **help connect a remote SSH server**

## Features
- Use  **terminal** or **Windows shortcuts** to call it.
- Use **nmap** to find all the SSH servers on your local network.
- Use **mouse** or **keyboard** to input.

## Parameters
** *Add "!" means disable and the following parameters of the same item will overwrite the previous ones.* **
### /cls*(!)*
Clear screen on start.
### /ctetml*(!)*
Create another terminal on start.
### /nmap*(!)*
Use nmap to search SSH servers on local network.
### /ping*(!)*
Ping the server before calling SSH.
### /pause*(!)*
Pause after calling SSH.

## Source Files Description
### shhaide.h
Main head file. Every cpp source file should include it.
### defines.h
Include the default settings of the current build.
### main.cpp
Main cpp source file. Implemented the main program logic.
### mouse.cpp
Provides mouse input support.
### keyboard.cpp
Provides keyboard input support.
### output.cpp
Provides output support.
### sysapi.cpp
Provides system APIs support.