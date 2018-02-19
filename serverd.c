#include"header.h"
#include<pthread.h>
int serverSocket(int s_fd);
struct studentdef
{
	int c_fd;
	char * number;
        char  subject[6][30];	
	char Table[9][5][30];
};
struct subjectdef
{
char * name;
char * teacher;
char *** timeTable;
 };
void *  judgeClient(void * students);
int main() 
{
int b=0;
int s_fd;
struct sockaddr_in addr1;
char  rebuf[256];
int rec=0;
int i;
int ok=0;
int jishu=0;
pthread_t mythread[1000];
struct studentdef students[3]={{0,"xiaoming",{"yuwen","huaxue","shuxue","wuli","biohazard","yingyu"},0},{0,"daming",{"yuwen","huaxue","shuxue","wuli","biohazard","yingyu"},0},{0,"mingming",{"yuwen","huaxue","shuxue","wuli","biohazard","yingyu"},0}};
struct subjectdef subjects[6]={{"yuwen","dagang",0},{"huaxue","laogang",0},{"suxue","zhonggang",0},{"wuli","shagang",0},{"biohazard","ganggang",0},{"yinyu","xiaoxiao",0}};
int studentCount=0;
int subjectCount=0;
int c_fd;
char *	addr;
struct sockaddr_in c_addr;
int c_len;
c_len=sizeof(c_addr);
//subjects[0].timeTable[1][1]="yuwen";
//subjects[0].timeTable[2][1]="yuwen";
//subjects[0].timeTable[3][3]="yuwen";
//subject:s[0].timeTable[4][3]="yuwen";
//subjects[1].timeTable[3][1]="huaxue";
//subjects[1].timeTable[4][1]="huaxue";
//subjects[1].timeTable[6][4]="huaxue";
//subjects[1].timeTable[7][4]="huaxue";
//subjects[2].timeTable[6][1]="suxue";
//subjects[2].timeTable[7][1]="suxue";
//subjects[3].timeTable[1][2]="wuli";
//subjects[3].timeTable[2][2]="wuli";
//subjects[3].timeTable[3][4]="wuli";
//subjects[3].timeTable[4][4]="wuli";
//subjects[4].timeTable[6][2]="biohazard";
//subjects[4].timeTable[7][2]="biohazard";
//subjects[4].timeTable[1][5]="biohazard";
//subjects[4].timeTable[2][5]="biohazard";
//subjects[5].timeTable[1][3]="yingyu";
//subjects[5].timeTable[2][3]="yingyu";
//subjects[5].timeTable[3][5]="yingyu";
//subjects[5].timeTable[4][5]="yingyu";


pid_t pid=fork();
	if(pid<0)
		return 1;
	if(pid>0)
		{
		return 0;
		}	

chdir("/");
umask(0);
s_fd=socket(AF_INET,SOCK_STREAM,0);
addr1.sin_family=AF_INET;
addr1.sin_addr.s_addr=inet_addr("127.0.0.1");
addr1.sin_port=htons(3339);
bind(s_fd,(struct sockaddr *)&addr1,sizeof(addr1));
listen(s_fd,10);
memset(rebuf,0,256);
	while(1)
	{
		c_fd=accept(s_fd,(struct sockaddr*)&c_addr,&c_len);
				recv(c_fd,rebuf,256,0);
				if(!strcmp(rebuf,"xiaoming"))
					{
					send(c_fd,"login successful",16,0);
					students[0].c_fd=c_fd;
					rec=pthread_create(&mythread[b],NULL,judgeClient,(void *)&students[0]);
					b++;
					if(b==999)
						b=0;
					}
				else if(!strcmp(rebuf,"daming"))
					{
					send(c_fd,"login successful",16,0);
					students[1].c_fd=c_fd;
					rec=pthread_create(&mythread[b],NULL,judgeClient,(void *)&students[1]);
				b++;
				if(b==999)
					b=0;
					}
					else if(!strcmp(rebuf,"mingming"))
					{		
					send(c_fd,"login successful",16,0);
					students[2].c_fd=c_fd;
					rec=pthread_create(&mythread[b],NULL,judgeClient,(void *)&students[2]);
				b++;
				if(b==999)
					b=0;
					}
					else 
					{
					send(c_fd,"error1",6,0);
					close(c_fd);
					continue;
					}
		
		
	}
return 0;
} 
