#include "CIPAddress.h"
#include <WinSock.h>
#include <tchar.h>
#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"Netapi32.lib")
int CIPAddress::StartUp()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2,0);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return err;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 0)
	{
		WSACleanup();
		return WSAVERNOTSUPPORTED;
	}
	return 0;
}

int CIPAddress::GetLocalHostName(char* sHostName)
{
	char szHostName[256];
	int nRetCode;
	nRetCode = gethostname(szHostName, sizeof(szHostName));
	if (nRetCode != 0)
	{
		sHostName = "Not available";
		return WSAGetLastError();
	}
	strcpy(sHostName, szHostName);
	return 0;
}

int CIPAddress::GetIPAddress(const char* sHostName,char ** sIPAddress)
{
	struct hostent FAR *lpHostEnt = gethostbyname(sHostName);
	if (lpHostEnt == NULL)
	{
		*sIPAddress = "";
		return WSAGetLastError();
	}

	LPSTR lpAddr = lpHostEnt->h_addr_list[0];
	if (lpAddr)
	{
		struct in_addr inAddr;
		memmove(&inAddr, lpAddr, 4);
		*sIPAddress = inet_ntoa(inAddr);
		if (*sIPAddress == NULL)
			*sIPAddress = "Not available";
	}
	return 0;
}