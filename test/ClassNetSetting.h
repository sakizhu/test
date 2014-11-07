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
	int m_TotalNetCards;  //ϵͳ��������
	TCHAR m_szDomain[16]; //����
	TCHAR m_szHostName[16]; //������
	int m_IPEnableRouter; //�Ƿ�����IP·�ɣ�0-������1-����2-δ֪
	int m_EnableDNS;
	NET_CARD m_Cards[10];
	Win32Type m_SystemType;
	MAC_ADDRESS m_MacAddr[10];
};

