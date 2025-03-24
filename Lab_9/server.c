#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char temp_c[BUFFER_SIZE];

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    // Bind socket to IP and PORT
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
 
    // configure server address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
    
    // Bind the socket to the specified port
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
 
    printf("Server is running...\n");
 
    // Listen for incoming connections with a backlog of 3
    listen(server_fd, 3);
 
    // Accept a client connection
    client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
 
    printf("Connected to client.\n");
 
    // Receive the temperature (in Fahrenheit) from the client
    int bytesRead = read(client_fd, buffer, BUFFER_SIZE);
     
    // Convert received string to a floating-point value
    float tempF = atof(buffer);
    printf("Received temperature (F): %.2f\n", tempF);
 
    // Convert Fahrenheit to Celsius
    float tempC = (tempF - 32) * 5 / 9;
 
    // Format the Celsius value to two decimal places
    snprintf(temp_c, sizeof(temp_c), "%.2f", tempC);
    printf("Converted temperature (C): %s\n", temp_c);
 
    // Send the formatted Celsius temperature back to the client
    send(client_fd, temp_c, strlen(temp_c), 0);
    printf("Sent converted temperature to client.\n");
 
    // Close the connections
    close(client_fd);
    close(server_fd);
 
    return 0;
}
