#include "stdafx.h"
#include <winsock2.h>
#include <cstring>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int app12(int argc, char *argv[])
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
		return -1;

	while (true)
	{
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sclient == INVALID_SOCKET)
			return 0;

		sockaddr_in sin;
		sin.sin_family = AF_INET;
		sin.sin_port = htons(8000);
		sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		
		if (connect(sclient, (sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR)
		{
			closesocket(sclient);
			return -1;
		}

		char data[255];
		cin >> data;
		const char* senddata;
		senddata = data;
		send(sclient, senddata, strlen(senddata), 0);
		
		char recvdata[255];
		int ret = recv(sclient, recvdata, 255, 0);
		if (ret> 0)
		{
			recvdata[ret] = 0x00;
			cout << recvdata << " ";
		}
		closesocket(sclient);
	}
	return 0;
}