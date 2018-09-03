#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SZIE 1024
#define OPSZ 4

int main(int argc, char *argv[]) {
    // int opnd_cnt, i;
    // char opmsg[BUF_SZIE] = {0};

    // fputs("Operand count: ", stdout);
    // scanf("%d", &opnd_cnt);
    // opmsg[0] = (char)opnd_cnt;

    // for (i = 0; i < opnd_cnt; ++i) {
    //     printf("Operand %d: ", i + 1);
    //     scanf("%d", (int*)&opmsg[i*OPSZ+1]);
    // }

    // fgetc(stdin);
    // fputs("Operator: ", stdout);
    // scanf("%c", &opmsg[opnd_cnt*OPSZ+1]);

    char opmsg[BUF_SZIE] = "hello world";
    printf("%s\n", opmsg);

    int opnd_cnt;
    fputs("Operand count: ", stdout);
    scanf("%d", &opnd_cnt);
    opmsg[0] = (char)opnd_cnt;
    printf("%d\n", opmsg[3]);

    return 0;
}
