#include <stdio.h>
#include <unistd.h>

int main() {
    printf("This is ex1, about to call execl()...\n");

    execl("./ex2", "ex2", NULL);

    // This line executes only if execl() fails
    printf("This line printed AFTER execl() - meaning execl() failed!\n");

    return 0;
}