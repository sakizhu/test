#include <stdio.h>
#include "CIPAddress.h"


int main()
{
	CIPAddress cIPAddr;
	cIPAddr.StartUp();
	char hostName[256];
	cIPAddr.GetLocalHostName(hostName);
	printf("%s\n",hostName);
	char *ipAddr = new char[256];
	cIPAddr.GetIPAddress(hostName, &ipAddr);
	printf("%s",ipAddr);
	return 0;
}