#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define OPSZ 4

void error_handling(char* message);
int calculate(int opnum, int opnds[], char oprator);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    char opinfo[BUF_SIZE];
    int result, i, opnd_cnt;
    int recv_cnt, recv_len;

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == serv_sock) {
        error_handling("socket() error");
    }
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = PF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if (-1 == bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))) {
        error_handling("bind() error");
    }
    if (-1 == listen(serv_sock, 5)) {
        error_handling("listen() error");
    }
    clnt_adr_sz = sizeof(clnt_sock);
    for (i = 0; i < 5; ++i) {
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        opnd_cnt = 0;
        read(clnt_sock, &opnd_cnt, 1);

        recv_len = 0;
        while ((opnd_cnt*OPSZ+1) > recv_len) {
            recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE-1);
            recv_len+=recv_cnt;
        }
        result = calculate(opnd_cnt, (int*)opinfo, opinfo[recv_len-1]);
        write(clnt_sock, (char*)&result, sizeof(result));
        close(clnt_sock);
    }

    close(serv_sock);
    return 0;
}

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int calculate(int opnum, int opnds[], char op) {
    int result = opnds[0], i;
    switch (op) {
        case '+' :
            for (i=1; i<opnum; ++i) {
                result += opnds[i];
            }
            break;
        case '-' :
            for (i=1; i<opnum; ++i) {
                result -= opnds[i];
            }
            break;
        case '*' :
            for (i=1; i<opnum; ++i) {
                result *= opnds[i];
            }
            break;
    }

    return result;
}
