#include <stdio.h>

#include <string.h>
//str~~ , mem~~ 등등의 함수를 사용하게 해준다.
#include <netinet/in.h>
//인터넷 주소 관련 함수 설정
#include <sys/socket.h>
//소켓연결에 필요한 구조체, 함수(bind listen accept 등등)이 들어있다
#include <stdlib.h>
#include <signal.h>





#define PORT 10000
#define BUFSIZE 10000


char buffer[BUFSIZE] = "Hi, I'm server.\n";
// sizeof(buffer) => 100 (배열의 크기)
// strlen(buffer) => 15 (buffer에 저장된 문자열의 길이)
char rcvBuffer[BUFSIZE];

void do_service(int c_socket);
void sig_handler(int signo);

int n;
int numclient=0;


int main(){
	int c_socket, s_socket;
	struct sockaddr_in s_addr, c_addr;
	int len;
	int pid;

	signal(SIGCHLD, sig_handler);
	
	// 1. 서버 소켓 생성
	//서버 소켓 = 클라이언트의 접속 요청을 처리(허용)해 주기 위한 소켓
	s_socket = socket(PF_INET, SOCK_STREAM, 0); 
	//TCP/IP 통신을 위한 서버 소켓 생성   
	//PF_INET : ipv4 인터넷 프로토콜을 사용하겠다.
	//SOCK_STREAM : 연결지향형 소켓을 사용하겠다  TCP를 사용할때는 꼭 연결형 소켓을 사용해야함
	// 프로토콜 결정. ( 0은 디폴트 프로토콜을 의미. TCP를 사용한다.)
	//현재 s_socket 에는 TCP소켓에 대한 정보가 들어있다.
	
	//2. 서버 소켓 주소 설정
	memset(&s_addr, 0, sizeof(s_addr)); 
	//s_addr의 값을 모두 0으로  초기화
	//s_addr 구조체에 있는 변수 모두 0으로 초기화
	// 구조체의 사이즈는 각 변수들 크기의 합인데, 그걸 포함하는 가장큰 변수의 바이트크기의 배수로 정한다.

	s_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	//IP 주소 설정
	//INADDR_ANY : 컴퓨터의 ip 주소를 자동으로 찾아서 대입해주는 함수. ip주소가 32bit의 값으로 온다.
	// 네트워크에서 쓰는 바이트 오더에 맞추기위해 hton을 사용 (32비트의 값을 바이트 오더로 바꿔준다.)
	// htonl이 아니라 inet_addr()은 string "123.123.123.123" 이런걸 바이트 오더로 바꿔주는것)
	// host to network 타입. 즉, 네트워크로 바이트오더를 특정 형태로 보내주는것.
	s_addr.sin_family = AF_INET;
	//AF_INET : ipv4의 주소체계 설정
	s_addr.sin_port = htons(PORT); 

	//3. 서버 소켓바인딩
	if(bind(s_socket,(struct sockaddr *) &s_addr, sizeof(s_addr)) == -1){ 
		//바인딩 작업 실패 시, Cannot Bind 메시지 출력 후 프로그램 종료
		printf("Cannot Bind\n"); //다른파일이 지정 프로토콜에 들어와있을때
		return -1;
	}

	//bind() 지정 소켓에 주소를 부여해준다 생각하면된다. (인터넷 선 연결작업.)
	// 첫번째 인자 : 지정 소켓.
	// 두번째 인자 : 연결 요구를 기다리는 포트번호가 있는 구조체의 주소
	// 세번째 인자 : 주소 구조체의 크기.
	// 성공시 : 0 리턴
	// 실패시 : -1 리턴

	
	//4.listen() 함수 실행
	if(listen(s_socket, 5) == -1){
		printf("listen Fail\n");
		return -1;
	}
	//listen()은  포트에 연결 후 클라이언트의 접속을 기다린다.
	//연결을 기다리기만 하는거지 직접 연결해주는게 아니다. 연결요청을 기다리는거다.
	//첫번째 인자 : 사용할 소켓
	//두번째 인자 : 연결 갯수 최댓값.

	
	

	//5. 클라이언트 요청 처리
	// 요청을 허용한 후, Hello World 메세지를 전송함
	while(1){ //무한 루프
		len = sizeof(c_addr);
		printf("클라이언트 접속을 기다리는 중....\n");
		c_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len); 
		//클라이언트의 요청이 오면 허용(accept)해 주고, 해당 클라이언트와 통신할 수 있도록 클라이언트 소켓(c_socket)을 반환함.
		//요청이 들어오면 연결할 소켓 하나를 새로 가져온다.
		//첫번째 인자 : 새로가져온 소켓과 연결할 소켓
		// 두번째 인자 : 새로 가져온 소켓이 가져야할 주소 목적지
		//세번째 인자 : 크기



		printf("/client is connected\n");
		numclient++;
		printf("now=[%d] : 클라이언트 접속 허용\n",numclient);

		if( (pid = fork()) > 0)
		{
			continue;
		}
		else if(pid==0)
		{
			do_service(c_socket);
			exit(0);
		}
		else
		{
			printf("Fail to Fork()");
			exit(0);
		}
		

		
		
	}
	close(s_socket);
	return 0;	
}








void do_service(int c_socket){
	while(1){
			n = read(c_socket, rcvBuffer, sizeof(rcvBuffer));
			printf("rcvBuffer: %s\n", rcvBuffer);
			rcvBuffer[n-1] = '\0'; //개행 문자 삭제

			if(strncasecmp(rcvBuffer, "quit", 4) == 0 || strncasecmp(rcvBuffer, "kill server", 11) == 0)
				break;
			else if (!strncasecmp(rcvBuffer, "안녕하세요", strlen("안녕하세요")))
				strcpy(buffer, "안녕하세요. 만나서 반가워요.");
			else if (!strncasecmp(rcvBuffer, "이름이 머야?", strlen("이름이 머야?")))
				strcpy(buffer, "내 이름은 박홍규야.");
			else if (!strncasecmp(rcvBuffer, "몇 살이야?", strlen("몇 살이야?")))
				strcpy(buffer, "나는 32살이야");
			else if (!strncasecmp(rcvBuffer, "strlen ", strlen("strlen ")))
				//문자열의 길이는 XX입니다.
				sprintf(buffer, "문자열의 길이는 %d입니다.", strlen(rcvBuffer)-7);
			else if (!strncasecmp(rcvBuffer, "strcmp ", strlen("strcmp "))){
				char *token;
				char *str[3];
				int idx = 0;
				token = strtok(rcvBuffer, " ");
				while(token != NULL){
					str[idx] = token;
					printf("str[%d] = %s\n", idx, str[idx]);
					idx++;
					token = strtok(NULL, " ");
				}
				if(idx < 3)
					strcpy(buffer, "문자열 비교를 위해서는 두 문자열이 필요합니다.");
				else if(!strcmp(str[1], str[2])) //같은 문자열이면
					sprintf(buffer, "%s와 %s는 같은 문자열입니다.",  str[1], str[2]);
				else
					sprintf(buffer, "%s와 %s는 다른 문자열입니다.",  str[1], str[2]);
				
			}else if (!strncasecmp(rcvBuffer, "readfile ", strlen("readfile "))) {
				char *token;
				char *str[10];
				int cnt = 0;
				token = strtok(rcvBuffer, " "); //token = readfile
				while(token != NULL){
					str[cnt] = token; //str[0] = readfile, str[1] = <파일명> ,.....
					cnt++;
					token = strtok(NULL, " "); //token = <파일명>
				}
				if(cnt < 2){
					strcpy(buffer, "파일명을 입력해주세요");
				}else{
					FILE *fp = fopen(str[1], "r");
					if(fp){ //정상적으로 파일이 오픈되었다면,
						char tempStr[BUFSIZE];//파일 내용을 저장할 변수
						memset(buffer, 0, BUFSIZE); //buffer 초기화
						while(fgets(tempStr, BUFSIZE, (FILE *)fp)){
							strcat(buffer, tempStr); //여러 줄의내용을하나의 buffer에저장하기위해 strcat()함수 사용 
						}
						fclose(fp);
					} else { //해당 파일이 없는 경우, 
						strcpy(buffer, "해당 파일은 존재하지 않습니다.");
					}
				}
			}else if(!strncasecmp(rcvBuffer, "exec ", 5)){
				char *command;
				char *token;
				token = strtok(rcvBuffer, " ");//token = exec
				command = strtok(NULL, "\0"); //exec 뒤에 있는 모든 문자열을 command로 저장
				printf("command:%s\n", command);
				int result = system(command); //command가 정상 실행되면 0을 리턴, 그렇지 않으면 0이 아닌 에러코드 리턴
				if(!result) //성공한 경우,
					sprintf(buffer, "[%s] 명령어가 성공했습니다.", command);
				else
					sprintf(buffer, "[%s] 명령어가 실패했습니다.", command);
				
			}else
				strcpy(buffer, "무슨 말인지 모르겠습니다.");
				
			write(c_socket, buffer, strlen(buffer)); //클라이언트에게 buffer의 내용을 전송함
		}
}




void sig_handler(int signo){

	int pid;
	int status;
	pid = wait(&status);
	printf("pid [%d] is terminated.status = %d\n", pid, status);
	numclient--;
	printf("now connect client number : %d\n", numclient);

}
