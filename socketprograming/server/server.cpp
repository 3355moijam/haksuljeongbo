// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;
void Error(char* msg);
void Log(char* msg);

char strServerIP[] = "127.0.0.1";
char strClientIP[] = "127.0.0.1";
char strPort[] = "12345";

void Server_Code();


int main()
{
	Server_Code();
    return 0;
}

void Error(char * msg)
{
	Log(msg);
	exit(1);
}

void Log(char * msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
}

void Server_Code()
{
	WSADATA wsaData;
	SOCKET serverSocket;
	vector<SOCKET> clientSocket;
	char msg[Buf_Size];
	int strLength, i;

	SOCKADDR_IN serverAddr, clientAddr;
	int clientAddrSize;
	
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup error");

	serverSocket = socket(PF_INET, SOCK_STREAM, 0); // PF_INET 은 IPv4, PF_INET6 은 IPv6, SOCK_STREAM 은 TCP, SOCK_DGRAM 은 UDP UDP는 전송 후 책임이 없음.
	if (serverSocket == INVALID_SOCKET)
		Error("socket() error");

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(atoi(strPort));

	if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		Error("bind() error");

	Log("bind() ok");

	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
		Error("listen() error");

	Log("listen() ok");

	clientAddrSize = sizeof(clientAddr);

	memset(msg, 0, sizeof(msg));
	for (int i = 0; i < SOMAXCONN; i++)
	{
		clientSocket.push_back(accept(serverSocket, (SOCKADDR*)&clientAddr, &clientAddrSize));
		Log("Accept()....");
		if (clientSocket[i] == SOCKET_ERROR)
			Error("Accept() error");
		else
			printf("Connected client %d \n", i + 1);

		while ((strLength = recv(clientSocket[i], msg, Buf_Size, 0)) != 0)
		{
			printf("%d client : %s", i + 1, msg);
			send(clientSocket[i], msg, strLength, 0);
			memset(msg, 0, sizeof(msg));
		}

		closesocket(clientSocket[i]);
	}
	closesocket(serverSocket);
	WSACleanup();
	Log("Finish ... ");
}
