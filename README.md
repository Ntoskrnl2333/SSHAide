# SSHAide
A Win32 console tool to **help connect a remote SSH server**

## Features
- Use  **terminal** or **Windows shortcuts** to call it.
- Use **nmap** to find all the SSH servers on your local network.
- Use **mouse** or **keyboard** to input.

## Source Files Description
### shhaide.h
Main head file. Every cpp source file should include it.
### defines.h
Include settings of the current build.
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