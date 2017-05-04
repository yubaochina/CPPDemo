
#include <stdio.h>
#include "UdpBaseBehaviour.h"


int main()
{
	Udp_base_behaviour *udpClient = new Udp_base_behaviour();
	udpClient->Winsock_init();
	udpClient->InitRemoteSocket_Addr_Port("127.0.0.1", 8888);

	char SendBuf[1024]="I am Client!";
	int BufLen = 1024;
	udpClient->SendUdpPacket(SendBuf, BufLen);

	return 0;
}
