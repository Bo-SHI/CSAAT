#include "apue.h"

#include <setjmp.h>

#define TOK_ADD 5

void do_line(char *);
void cmd_add(void);
int get_token(void);

jmp_buf jmpbuffer;

int main() {
    char line[MAXLINE];

    if (setjmp(jmpbuffer) != 0) {
        printf("error occur\n");
    }

    while(fgets(line, MAXLINE, stdin) != NULL) {
        do_line(line);
    }

    exit(0);
}

char *tok_ptr;

void doline(char *line) {
    int cmd;
    tok_ptr = line;
    while ((cmd = get_token()) > 0) {
        case TOK_ADD:
            cmd_add();
        // ... TODO
    }

    // ...TODO
}

int get_token() {
    // ... TODO

    return (int)TOK_ADD;
}

void cmd_add() {
    int token;
    token = get_token();
    if (token < 0) {
        longjmp(jmpbuffer, 1);
    }

    // ... TODO
}
