#pragma once

extern "C"
{
	char* _stdcall _strcpy(char*, char*);
	char* _stdcall _strcat(char*, char*);
	void _stdcall outstr(char*);
	void _stdcall outint(int);
	int _stdcall sqroot(int);
	int _stdcall _modint(int x, int y);
	//int _stdcall sqr(int);
	int _stdcall strnum(char* str);
}