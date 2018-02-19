#include"header.h"
void  sendMessage(int sockfd,char * message);

void store(int sockfd)
{
	char * 	message="5";
	sendMessage(sockfd,message);
}






int clientSocket(char * ipaddr)
{
	int sockfd;
	int newsockfd;
	struct sockaddr_in addr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr(ipaddr);
	addr.sin_port=htons(3339);
	newsockfd=connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if (newsockfd==-1)
	{
		perror("link fail");
		exit(1);
	}
	printf("link succeeded");
	printf("Welcome to student select subjects system!!\nhere you have 6 choice\n");
	return sockfd;
}











void clientOptions()
{
printf("\n\n\n1.show client's pending subjects\n2.show client is completed\n");
printf("3.show client's table\n4.show optional subject\n5.store\n6.exit\n\n");
printf("please input 1-6\n");
printf("which one do you chose:");
}
