A simple utility to encrypt / decrypt NPPFTP passwords using the default key [NppFTP00]

Code is a partial fork of: https://github.com/ashkulz/NppFTP
I do not take credit for the Encryption and StringUtils classes



How to compile:
g++ -o npp_ed npp_ed.cpp -lssl -lcrypto

How to use:
./npp_ed [--e|--d] [password]
