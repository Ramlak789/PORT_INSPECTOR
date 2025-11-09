/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    char ip[32];
    int port;

    printf("Enter target IP: ");
    scanf("%31s", ip);

    printf("Enter port number: ");
    scanf("%d", &port);

    int sock;
    struct sockaddr_in target;

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(ip);

    // try to connect
    if (connect(sock, (struct sockaddr*)&target, sizeof(target)) == 0) {
        printf("✅ Port %d is OPEN on %s\n", port, ip);
    } else {
        printf("❌ Port %d is CLOSED or FILTERED on %s\n", port, ip);
    }

    close(sock);
    return 0;
}