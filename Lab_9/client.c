#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    if (argc != 2) {
        printf("Usage: %s <temperature in Fahrenheit>\n", argv[0]);
        return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    printf("Client socket initalized!\n");

    // Set up server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("Connection established\n");

    // Send Fahrenheit value to server
    snprintf(buffer, BUFFER_SIZE, "%.2f", atof(argv[1]));
    send(sock, buffer, strlen(buffer), 0);
    printf("Temperature in Fahrenheit sent: %s\n", buffer);

    memset(buffer, 0, sizeof(buffer));

    // Receive Celsius value from server
    read(sock, buffer, BUFFER_SIZE);
    printf("Temperature in Celsius received: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}
