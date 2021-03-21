#include "stdafx.h"
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int app11(int argc, char *argv[])
{
	WORD scokVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(scokVersion, &wsaData) != 0)
		return 0;

	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
		return 0;


	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8000);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
		return -1;

	if (listen(slisten, 5) == SOCKET_ERROR)
		return -1;

	SOCKET sclient;
	sockaddr_in remoteaddr;
	int addrlen = sizeof(remoteaddr);
	char recvdata[255];
	while (true)
	{
		printf("connect...");
		sclient = accept(slisten, (SOCKADDR *)&remoteaddr, &addrlen);
		if (sclient == INVALID_SOCKET)
			continue;

		int ret = recv(sclient, recvdata, 25, 0);
		if(ret > 0)
			recvdata[ret] = 0x00;

		const char *senddata = "ÄãºÃsocket\n";
		send(sclient, senddata,  strlen(senddata), 0);
		closesocket(sclient);
	}
	closesocket(slisten); 	
	WSACleanup();
	return 0;	
}