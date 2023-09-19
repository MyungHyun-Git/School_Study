#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 9000

char buffer[100] = "서버왔습니당 \n";
char buffer2[100];
char buffer3[100] = "안녕하세요 만나서 반가워요\n";


int main()
{
    int c_socket, s_socket;
    struct sockaddr_in s_addr, c_addr;
    int len;
    int n,c;
    //서버소켓 생성 (클라이언트의 접속요청을 처리하는 소켓)
    s_socket = socket(PF_INET, SOCK_STREAM, 0);
   

    //서버소켓의 주소값 설정
    memset(&s_addr, 0, sizeof(s_addr)); //s_addr의 값을 모두0으로 초기화
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
     //host to network long : host 에서 network로 long형 데이터를 보낼때 바이트 오더로 바꿔주는(?)  함수
    s_addr.sin_family=AF_INET;
    s_addr.sin_port = htons(PORT);
    //host to network short

    //서버소켓 바인딩 : 바인드 = 전화기를 사고 전화기선을 통신사에 꽂는 느낌
    if(bind(s_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1)
    	{
        printf("바인드 실패에욧 \n");
        return -1;
    	}



    //서버소켓 listen : 통신사에 연결된 선으로 핸드폰 개통하는 느낌
    if(listen(s_socket, 5)==-1)
    	{
        printf("개통실패에요\n");
        return -1;
    	}
   


    //클라이언트 요청 처리해주는것
    while(1)
	    {
		len=sizeof(c_addr);
		printf("클라이언트의 접속을 기다리는중..\n");
		c_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len);
		//서버소켓으로 클라이언트의 요청이 오면 허용해주고, 통신할수 있도록 클라이언트 소켓을 반환해줌
	       
		printf("클라이언트 연결됌\n");
	       

		n=strlen(buffer);
		write(c_socket, buffer, n); // 클라이언트 소켓으로 buffer에 저장된 내용 전송

		while(1)
		{
			
			c=read(c_socket, buffer2, sizeof(buffer2));
			buffer2[c]='\0';
			printf("클라에서 이런메세지가 : %s \n",buffer2);
			

			if(strncasecmp(buffer2, "안녕하세요", 15)==0)
		      		  {
					write(c_socket, buffer3, strlen(buffer3));

		    		  }
		

			
		}
		break;
	close(c_socket);
    close(s_socket);
    return 0;

	}


} 

