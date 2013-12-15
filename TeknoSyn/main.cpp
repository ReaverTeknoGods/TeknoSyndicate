#include <windows.h>
	char        szAppPath[MAX_PATH] = "";
	char		path[MAX_PATH] = "";
	char patchbuf[512];
	DWORD len = 0;
	DWORD DowStart = 0;
	DWORD Xlive = 0;
	HANDLE threadi;
#define RoundBy1000(a) (a / 0x1000 + ((a % 0x1000) > 0 ? 1 : 0)) * 0x1000
#define DLL __declspec(dllexport)
extern "C" void __declspec() DLL _x();
int main();
void main2();
DWORD WINAPI TehThread(__in  LPVOID lpParameter);
DWORD WINAPI Thredi(__in  LPVOID lpParameter);
void lowercase(char string[]);
bool IsSyndicate = false;
DWORD returnmessage = 0;

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
			return main();
            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

int main()
{
	memset(patchbuf,512,0xFA);
	main2();
	return returnmessage;
}
void main2()
{
	len = GetModuleFileName(0, szAppPath, MAX_PATH);
	lowercase(szAppPath);
	for(int i = 0; i < 260; i++)
	{
		if(szAppPath[i] == 0)
		{
			if(strcmp(szAppPath+i-13,"syndicate.exe") == 0)
			{
				IsSyndicate = true;
				break;
			}
			else { returnmessage = 0; return; }
		}
	}
	DWORD MyCheck = (DWORD)GetProcAddress(GetModuleHandle("TeknoSyn.dll"), "_x");
	if(MyCheck == NULL || MyCheck == -1) ExitProcess(0);
	else CreateThread(0,0,TehThread,0,0,0);
	CreateThread(0,0,Thredi,0,0,0);
	returnmessage = 1;
}
void __declspec(naked) _x()
{


}

DWORD WINAPI Thredi(__in  LPVOID lpParameter)
{
   //DWORD func;
   //func = 0x004A7450;
   //__asm
   //{
	  // call func
   //}
   return 1;
}

DWORD WINAPI TehThread(__in  LPVOID lpParameter)
{
	DWORD loc1;
	loc1 = 0x00492180;
	DWORD loc2;
	loc2 = 0x006708B8;
	DWORD point;
	point = (DWORD)patchbuf;
	patchbuf[0] = 0x6F;
	patchbuf[1] = 0x73;
	patchbuf[2] = 0x5F;
	patchbuf[3] = 0x73;
	patchbuf[4] = 0x76;
	patchbuf[5] = 0x5F;
	patchbuf[6] = 0x73;
	patchbuf[7] = 0x65;
	patchbuf[8] = 0x74;
	patchbuf[9] = 0x6C;
	patchbuf[10] = 0x61;
	patchbuf[11] = 0x6E;
	patchbuf[12] = 0x28;
	patchbuf[13] = 0x31;
	patchbuf[14] = 0x29;
	patchbuf[15] = 0x3B;
	patchbuf[16] = 0x63;
	patchbuf[17] = 0x67;
	patchbuf[18] = 0x5F;
	patchbuf[19] = 0x73;
	patchbuf[20] = 0x75;
	patchbuf[21] = 0x62;
	patchbuf[22] = 0x6D;
	patchbuf[23] = 0x65;
	patchbuf[24] = 0x6E;
	patchbuf[25] = 0x75;
	patchbuf[26] = 0x28;
	patchbuf[27] = 0x22;
	patchbuf[28] = 0x4D;
	patchbuf[29] = 0x50;
	patchbuf[30] = 0x5F;
	patchbuf[31] = 0x4C;
	patchbuf[32] = 0x41;
	patchbuf[33] = 0x4E;
	patchbuf[34] = 0x22;
	patchbuf[35] = 0x29;
	patchbuf[36] = 0x3B;
	patchbuf[37] = 0x00;
	patchbuf[38] = 0x00;
	patchbuf[39] = 0x00;
	while(1)
	{
		DWORD MyCheck1 = (DWORD)GetModuleHandle("msystem.dll");
		DWORD MyCheck2 = (DWORD)GetModuleHandle("GameWorld_Win32_x86_Release.dll");
		DWORD MyCheck3 = (DWORD)GetModuleHandle("GameClasses_Win32_x86_Release.dll");
		DWORD MyCheck4 = (DWORD)GetModuleHandle("mxr.dll");
		if(MyCheck1 != 0 && MyCheck2 != 0 && MyCheck3 != 0)
		{
			// Get MSys base+size
			DWORD msys = MyCheck1;
			DWORD msysPE = msys + 0x3C;
			msysPE = *(DWORD *)msysPE;
			msysPE += msys + 0x100;
			DWORD msysTextSize = RoundBy1000(*(DWORD *)msysPE);
			msysPE+= 4;
			DWORD msysTextStart = msys + *(DWORD *)msysPE;

			// Get GameWorld base+size
			DWORD gw = MyCheck2;
			DWORD gwPE = gw + 0x3C;
			gwPE = *(DWORD *)gwPE;
			gwPE += gw + 0x100;
			DWORD gwTextSize = RoundBy1000(*(DWORD *)gwPE);
			gwPE+= 4;
			DWORD gwTextStart = gw + *(DWORD *)gwPE;

			// Get GameClasses base+size
			DWORD gc = MyCheck3;
			DWORD gcPE = gc + 0x3C;
			gcPE = *(DWORD *)gcPE;
			gcPE += gc + 0x100;
			DWORD gcTextSize = RoundBy1000(*(DWORD *)gcPE);
			gcPE+= 4;
			DWORD gcTextStart = gc + *(DWORD *)gcPE;

			// Get GameClasses base+size
			DWORD mxr = MyCheck3;
			DWORD mxrPE = mxr + 0x3C;
			mxrPE = *(DWORD *)mxrPE;
			mxrPE += mxr + 0x100;
			DWORD mxrTextSize = RoundBy1000(*(DWORD *)mxrPE);
			mxrPE+= 4;
			DWORD mxrTextStart = mxr + *(DWORD *)mxrPE;

			for(int i = 0; i < msysTextSize; i++)
			{
				if(*(DWORD *)(msysTextStart + i) == 0x0018A164)
					if(*(DWORD *)(msysTextStart + i + 4) == 0x408B0000)
						if(*(DWORD *)(msysTextStart +i + 8) == 0x89088B30)
						{
							DWORD oldie = 0;
							DWORD oldie2 = 0;
							VirtualProtect((LPVOID)msysTextStart,msysTextSize,0x40, &oldie);
							*(DWORD *)(msysTextStart + i) = 0x010000B9;
							*(DWORD *)(msysTextStart + i + 4) = 0x90909000;
							*(WORD *)(msysTextStart + i + 8) = 0x9090;
							*(BYTE *)(msysTextStart + i + 10) = 0x90;
							VirtualProtect((LPVOID)msysTextStart,msysTextSize, oldie, &oldie2);
						}
			}
			for(int i = 0; i < gcTextSize; i++)
			{
				if(*(DWORD *)(gcTextStart + i) == 0x0018A164)
					if(*(DWORD *)(gcTextStart + i + 4) == 0x408B0000)
						if(*(DWORD *)(gcTextStart + i + 8) == 0x89088B30)
						{
							DWORD oldie = 0;
							DWORD oldie2 = 0;
							VirtualProtect((LPVOID)gcTextStart,gcTextSize,0x40, &oldie);
							*(DWORD *)(gcTextStart + i) = 0x010000B9;
							*(DWORD *)(gcTextStart + i + 4) = 0x90909000;
							*(WORD *)(gcTextStart + i + 8) = 0x9090;
							*(BYTE *)(gcTextStart + i + 10) = 0x90;
							VirtualProtect((LPVOID)gcTextStart,gcTextSize, oldie, &oldie2);
						}
			}
			for(int i = 0; i < gwTextSize; i++)
			{
				if(*(DWORD *)(gwTextStart + i) == 0x0018A164)
					if(*(DWORD *)(gwTextStart +i + 4) == 0x408B0000)
						if(*(DWORD *)(gwTextStart +i + 8) == 0x89088B30)
						{
							DWORD oldie = 0;
							DWORD oldie2 = 0;
							VirtualProtect((LPVOID)gwTextStart,gwTextSize,0x40, &oldie);
							*(DWORD *)(gwTextStart + i) = 0x010000B9;
							*(DWORD *)(gwTextStart + i + 4) = 0x90909000;
							*(WORD *)(gwTextStart + i + 8) = 0x9090;
							*(BYTE *)(gwTextStart + i + 10) = 0x90;
							VirtualProtect((LPVOID)gwTextStart,gwTextSize, oldie, &oldie2);
						}
			}

			for(int i = 0; i < mxrTextSize; i++)
			{
				if(*(DWORD *)(mxrTextStart + i) == 0x0018A164)
					if(*(DWORD *)(mxrTextStart + i + 4) == 0x408B0000)
						if(*(DWORD *)(mxrTextStart + i + 8) == 0x89088B30)
						{
							DWORD oldie = 0;
							DWORD oldie2 = 0;
							VirtualProtect((LPVOID)mxrTextStart,mxrTextSize,0x40, &oldie);
							*(DWORD *)(mxrTextStart + i) = 0x010000B9;
							*(DWORD *)(mxrTextStart + i + 4) = 0x90909000;
							*(WORD *)(mxrTextStart + i + 8) = 0x9090;
							*(WORD *)(mxrTextStart + i + 10) = 0x90;
							VirtualProtect((LPVOID)mxrTextStart,mxrTextSize, oldie, &oldie2);
						}
			}
			break;
		}
		Sleep(1000);
	}
	while(1)
	{
			if(GetAsyncKeyState(VK_F12) < 0)
			{
				__asm
				{
					PUSH 0x0
					PUSH 0x18F267C
					SUB ESP, 0x8
					MOV ECX, ESP
					PUSH point
					CALL loc1
					CALL loc2
					ADD ESP, 0x10
				}
			}
			Sleep(300);
	}
	return 1;
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