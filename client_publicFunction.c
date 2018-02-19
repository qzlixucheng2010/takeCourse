#include"header.h" 
void sendMessage(int sockfd,char * message)
{
char rebuf[1024];
send(sockfd,message,strlen(message),0);
recv(sockfd,rebuf,1024,0);
printf("\n%s\n",rebuf);
memset(rebuf,0,strlen(rebuf));
}




void pendingSubject(int sockfd)
{
char * message="1";
sendMessage(sockfd,message);

}






void showComplete(int sockfd)
{
char * message="2";
sendMessage(sockfd,message);
}





/*void clientTable(int sockfd)
{
char table[9][5][30];
char * buf;
int i=0;
char * message="3";
buf=sendMessage(sockfd,message);
for(i=0;i<strlen(buf);i++)
	

}*/







void optionalSubject(int sockfd)
{
char * message="4";
sendMessage(sockfd,message);
}




