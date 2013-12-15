#include <stdio.h>
#include <windows.h>
#include <TLHELP32.H>
#include <conio.h>
#include "forcelib.h"
DWORD RemoteLoadLibrary(DWORD dwPID, LPSTR lpszModuleName)
{
	PROCESS_INFORMATION pinfo;
	DWORD dwModuleBase = 0;
	pinfo.dwProcessId = dwPID;
	pinfo.dwThreadId = 0;
	pinfo.hProcess = OpenProcess(PROCESS_ALL_ACCESS , FALSE, dwPID);
	if(pinfo.hProcess == NULL) pinfo.hProcess = OpenProcess(PROCESS_VM_WRITE|PROCESS_CREATE_THREAD|PROCESS_VM_READ|PROCESS_QUERY_INFORMATION|PROCESS_VM_OPERATION , FALSE, dwPID);
	if(pinfo.hProcess == NULL) printf("OpenProcess failed!\n");
    if(pinfo.hProcess != NULL)
	{
		dwModuleBase = ForceLibrary(lpszModuleName, &pinfo );
		CloseHandle(pinfo.hProcess);
	}
    return dwModuleBase;
}
void lowercase(char string[])
{
   int  i = 0;

   while ( string[i] )
   {
      string[i] = tolower(string[i]);
      i++;
   }

   return;
}
void main()
{
	char szDir[512];
	char szDir2[512];
	printf("Syndicate DEV Mode unlocker\nSupported OS: Windows XP x86/x64, Windows Vista x86/x64, Windows 7 x86/x64\nCode: Reaver\nUses \"ForceLibrary\" by yoda\n\n");
	GetCurrentDirectoryA(400, szDir);
	sprintf_s(szDir2, "%s\\TeknoSyn.dll", szDir);
	while(1)
	{
		printf("Press CTRL+C to close\nRescanning all processes\n");
		char bla[256];
		HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hProcessSnap == (HANDLE)-1) 
			return;

		PROCESSENTRY32 pe32 = {0};
		pe32.dwSize = sizeof(PROCESSENTRY32);

		BOOL bContinue = ::Process32First(hProcessSnap, &pe32);
		while (bContinue)
		{
			sprintf_s(bla, "%s", pe32.szExeFile);
			bool found = false;
			LPSTR Game = "";
			lowercase(bla);
			if(!strcmp(bla, "syndicate.exe"))
			{
				found = true;
				Game = "Syndicate";
			}
			if(found == true)
			{
				printf("%s found, injecting\n", Game);
				DWORD base = (DWORD)RemoteLoadLibrary(pe32.th32ProcessID, szDir2);
				if(base == 0) 
				{
					printf("Injection failed, make sure the dll is in same dir as this program.\n");
				}
				else
				{
					printf("Injected to base 0x%08x, have fun!\n", base);
					_getch();
					exit(0);
				}
			}
			bContinue = ::Process32Next(hProcessSnap, &pe32);
		}
		::CloseHandle(hProcessSnap);
		printf("Nothing found, rescanning in 10seconds\n");
		Sleep(10000);
	}
}