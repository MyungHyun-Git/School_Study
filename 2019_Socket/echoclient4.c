#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 9000
#define IPADDR "127.0.0.1"
#define BUFSIZE 100


int main()
{
    int c_socket;
    struct sockaddr_in c_addr;
    int n, k, cp;
    char rcvbuffer[BUFSIZE]={0}; // 서버에서 온메세지 저장할 배열
    char rcv2buffer[BUFSIZE]={0}; // 서버에 보내줄 메세지를 저장할 배열
	char compare[BUFSIZE]={0};


    //클라이언트 소켓 생성
    c_socket = socket(PF_INET, SOCK_STREAM, 0); //서버와 동일한 환경

    //소켓정보 초기화
    memset(&c_addr, 0, sizeof(c_addr));
    c_addr.sin_addr.s_addr=inet_addr(IPADDR); //접속 IP는 내꺼
    c_addr.sin_family=AF_INET;
    c_addr.sin_port = htons(PORT);


    //서버에 접속
    if(connect(c_socket, (struct sockaddr *)&c_addr, sizeof(c_addr))==-1)
    {
        printf("서버 접속에 실패했음\n");
        return -1;
    }



 
    //읽기 실패시
    if(n<0)
    {
        printf("읽기 실패!\n");
        return -1;
    }




    while(1)
	{

	   	//서버에서 보낸 메세지 읽기
	    n=read(c_socket, rcvbuffer, sizeof(rcvbuffer)); //메세지 배열에 저장후 배열의 길이를 리턴
	    rcvbuffer[n]='\0'; //문자열 깨짐방지
	    printf("받은 메세지 : %s \n",rcvbuffer);


		while(1)
		{
			printf("서버에 보내고싶은 말을 입력해보세요: \n");
			fgets(rcv2buffer,sizeof(rcv2buffer), stdin);

			write(c_socket, rcv2buffer, strlen(rcv2buffer));
			k=sizeof(rcv2buffer);
			rcv2buffer[k]='\0';
			printf("\n");	
			
			if(strncasecmp(rcv2buffer, "strcmp ", 7) == 0)
			{
				read(c_socket, compare, sizeof(compare));
				cp=strlen(compare);
				compare[cp]='\0';
				printf("서버에서 메세지가 왔습니다 :\n : %s \n", compare);
				strcpy(compare,"\0");

			}
			
	


		}
		

	}

	close(c_socket);
	return 0;
	   
} 

