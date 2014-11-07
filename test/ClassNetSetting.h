#include <WinSock.h>
#include <SDKDDKVer.h>
#include <tchar.h>
enum Win32Type
{
	Unknow,
	Win32s,
	Windows9X,
	WinNT3,
	WinNT4orHighter
};

typedef struct tagASTAT
{
	ADAPTER_STATUS adapt;
	NAME_BUFFER NameBuff[30];
}ASTAT, *LPASTAT;

typedef struct tagMAC_ADDRESS
{
	BYTE b1,b2,b3,b4,b5,b6;
}MAC_ADDRESS,*LPMAC_ADDRESS;

typedef struct tagNET_CARD
{
	TCHAR szDescription[256];
	BYTE szMacAddr[6];
	TCHAR szGetWay[128];
	TCHAR szIpAddress[128];
	TCHAR szIpMask[128];
	TCHAR szDNSNameServer[128];
}NET_CARD, *LPNET_CARD;


class ClassNetSetting
{
public:
	void ProcessMultiString (LPTSTR lpszString, DWORD dwSize);
	UCHAR GetAddressByIndex (int lana_num, ASTAT& Adapter);
	BOOL GetSettingOfWinNt ();
	int GetMacAddress (int pMacAddr);
	BOOL GetSetting ();
	ClassNetSetting ();
	virtual ~ClassNetSetting ();

public:
	BOOL GetSettingOfWin9X ();
	Win32Type GetSystemType ();
	int m_TotalNetCards;  //系统的网卡数
	TCHAR m_szDomain[16]; //域名
	TCHAR m_szHostName[16]; //主机名
	int m_IPEnableRouter; //是否允许IP路由，0-不允许，1-允许，2-未知
	int m_EnableDNS;
	NET_CARD m_Cards[10];
	Win32Type m_SystemType;
	MAC_ADDRESS m_MacAddr[10];
};

