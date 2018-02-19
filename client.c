#include"header.h"
void pendingSubject(int sockfd);
void showComplete(int sockfd);
void clientTable(int sockfd);
void optionalSubject(int sockfd);
void store(int sockfd);
int  clientSocket(char * string);
void ServerOptions(char * ipaddr);
void sendMessage(int sockfd,char * message);
void clientOptions();

int main(int argc,char * argv[])
{
int ok=0;
int sockfd;
char  rebuf[256];
char table[9][5][30];
char choice[256];
memset(rebuf,0,256);
memset(choice,0,256);
char name[50];
	if(argc<3)
	{
		printf("Usage:client ipaddr/n");
		exit(1);
	}
sockfd=clientSocket(argv[1]);
ok=send(sockfd,argv[2],strlen(argv[2]),0);
if(ok>0)
	printf("\n%s\n",argv[2]);
recv(sockfd,rebuf,16,0);
printf("\n\n%s\n\n",rebuf);
	while(1)
	{
		clientOptions();
		scanf("%s",&choice);
		if(!strcmp(choice,"1"))
		{
			pendingSubject(sockfd);
		}
		else if(!strcmp(choice,"2"))
		{
			showComplete(sockfd);
		}
		else if(!strcmp(choice,"3"))
		{
		//	clientTable(sockfd);
		continue;
		}
		else if(!strcmp(choice,"4"))
		{
			optionalSubject(sockfd);
		}
		else if(!strcmp(choice,"6"))
		{
			close(sockfd);
			return 0;
		}
		else if(!strcmp(choice,"51"))
		{
			sendMessage(sockfd,"51");	
		}
		else if(!strcmp(choice,"52"))
		{
			sendMessage(sockfd,"52");
		}
		else if(!strcmp(choice,"53"))
		{
			sendMessage(sockfd,"53");	
		}
		else if(!strcmp(choice,"54"))
		{
			sendMessage(sockfd,"54");	
		}
		else if(!strcmp(choice,"55"))
		{
			sendMessage(sockfd,"55");	
		}
		else if(!strcmp(choice,"56"))
		{
			sendMessage(sockfd,"56");
		}
		else 
			{
			printf("please input 1-6!!!!!\n");
			printf("\nif you want to input 5,please input 51 or 52 or  53 or 54 or 55 or 56\n");
			}
		}
	close(sockfd);
	return 0;
}










 
