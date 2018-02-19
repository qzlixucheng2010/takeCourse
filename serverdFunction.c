#include<pthread.h>
#include"header.h"
struct studentdef
{
	int c_fd;
	char * number;
	char  subject[6][30];
	char  Table[9][5][30];
};

int  serverSocket()
{
int s_fd;
struct sockaddr_in addr;
s_fd=socket(AF_INET,SOCK_STREAM,0);
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=inet_addr(INADDR_ANY);
addr.sin_port=htonl(3339);
bind(s_fd,(struct sockaddr *)&addr,sizeof(addr));
listen(s_fd,10);
return s_fd;
}


void *  judgeClient(void * arg)
{
struct studentdef  student=*((struct studentdef *)arg);
char buf[256];
int count1=0,count2=0;
int found=0;
char sendmessage1[65535];
char * sendmessage2;
int i=0;
int count;
int c_fd=student.c_fd;
char  pendingSubject[65535];
memset(pendingSubject,0,65535);
memset(sendmessage1,0,65535);
while(1)
{
	if(!recv(c_fd,buf,256,0))
			continue;
	if(!strcmp(buf,"1"))
	{	
		for(count=0;count<6;count++)
			{
			strcat(pendingSubject,student.subject[count]);	
			strcat(pendingSubject,"\n");
			}
			send(c_fd,pendingSubject,strlen(pendingSubject),0);
		memset(pendingSubject,0,65535);	
	}
	if(!strcmp(buf,"2"))
	{
		for(count=0;count<6;count++)
				strcat(pendingSubject,student.subject[count]);	
		if(!strcmp(pendingSubject,""))
			send(c_fd,"\n\ncomplete\n\n",12,0);
		else
			send(c_fd,"\n\nnot complete\n\n",16,0);	
		memset(pendingSubject,0,65535);	
		
	}
	if(!strcmp(buf,"3"))
	{
		for(count=0;count<6;count++)
			{
			strcat(pendingSubject,student.subject[count]);	
			strcat(pendingSubject,",");
			}
			send(c_fd,pendingSubject,strlen(pendingSubject),0);
		memset(pendingSubject,0,65535);	
	
	}
	if(!strcmp(buf,"4"))
	{
		strcpy(pendingSubject,"yuwen,wuli,huaxue,shuxue,biohazard,yingyu");	
		send(c_fd,pendingSubject,strlen(pendingSubject),0);
		memset(pendingSubject,0,65535);	
		
	}
	//(buf=="5")
	//
	//printf(sendmessage2,"";	
//send(c_fd,sendmessage2,strlen(sendmessage2),0);
//sendmessage2="";	
//
	if(!strcmp(buf,"6"))
	{
	close(c_fd);
	break;
	}
	if(!strcmp(buf,"51"))
	{
		
		for(count1=0;count1<6;count1++)	
			{
			if(!strcmp(student.subject[count1],"yuwen"))
				{
				found=1;
				memset(student.subject[count1],0,30);
				sprintf(student.Table[1][1],"yuwen");
				sprintf(student.Table[2][1],"yuwen");
				sprintf(student.Table[3][3],"yuwen");
				sprintf(student.Table[4][3],"yuwen");
				send(c_fd,"\n\nchoose succeed!\n\n",20,0);
				}
			}
		if(found==0)
			send(c_fd,"\n\nerror\n\n",9,0);
	
	}
	if(!strcmp(buf,"52"))
	{
		for(count1=0;count1<6;count1++)
			if(!strcmp(student.subject[count1],"huaxue"))
				{
				found=1;
				memset(student.subject[count1],0,30);
				sprintf(student.Table[4][1],"huaxue");
				sprintf(student.Table[6][4],"huaxue");
				sprintf(student.Table[7][4],"huaxue");
				send(c_fd,"\n\nchoose succeed!\n\n",20,0);	
				}
				if(found==0)
				send(c_fd,"\n\nerror\n\n",9,0);
				
	}
	if(!strcmp(buf,"53"))
	{
		for(count1=0;count1<6;count1++)
			if(!strcmp(student.subject[count1],"shuxue"))
				{
				found=1;
				memset(student.subject[count1],0,30);
				sprintf(student.Table[6][1],"shuxue");
				sprintf(student.Table[7][1],"shuxue");
				send(c_fd,"\n\nchoose succeed!\n\n",20,0);
				
				}

			if(found==0)
				send(c_fd,"\n\nerror3\n\n",9,0);
				
	
	}
	if(!strcmp(buf,"54"))
	{
		for(count1=0;count1<6;count1++)
			if(!strcmp(student.subject[count1],"wuli"))
				{
				found=1;
				memset(student.subject[count1],0,30);
				sprintf(student.Table[1][2],"wuli");
				sprintf(student.Table[2][2],"wuli");
				sprintf(student.Table[3][4],"wuli");
				sprintf(student.Table[4][4],"wuli");
				send(c_fd,"\n\nchoose succeed!\n\n",20,0);
				
				}
				if(found==0)
				send(c_fd,"\n\nerror\n\n",9,0);
			
	}
	if(!strcmp(buf,"55"))
	{
		for(count1=0;count1<6;count1++)
			if(!strcmp(student.subject[count1],"biohazard"))
				{
				found=1;
				memset(student.subject[count1],0,30);
				sprintf(student.Table[6][2],"biohazard");
				sprintf(student.Table[7][2],"biohazard");
				sprintf(student.Table[1][5],"biohazard");
				sprintf(student.Table[2][5],"biohazard");
				send(c_fd,"\n\nchoose succeed!\n\n",20,0);
				
				}
				if(found==0)
				send(c_fd,"\n\nerror\n\n",9,0);
				
	}
	if(!strcmp(buf,"56"))
	{
		for(count1=0;count1<6;count1++)
			if(!strcmp(student.subject[count1],"yingyu"))
				{
				found=1;
				memset(student.subject[count1],0,30);
				sprintf(student.Table[1][3],"yingyu");
				sprintf(student.Table[2][3],"yingyu");
				sprintf(student.Table[3][5],"yingyu");
				sprintf(student.Table[4][5],"yingyu");
				send(c_fd,"\n\nchoose succeed!\n\n",20,0);
				
				}
				if(found==0)
				send(c_fd,"\n\nerror\n\n",9,0);
				
	}
	memset(buf,0,strlen(buf));
	found=0;
}
}



