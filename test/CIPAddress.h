class CIPAddress
{
public:
	int StartUp();
	int GetLocalHostName(char * sHostName);
	int GetIPAddress(const char * sHostName,char ** sIPAddress);
};