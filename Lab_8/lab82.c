#include<stdio.h>
#include<stdlib.h>
#include<ifaddrs.h>
#include<sys/socket.h>
#include<netdb.h>
int main()
{
    struct ifaddrs *addresses, *addr;
    if (getifaddrs(&addresses) == -1)
    {
         printf("Error getting network info\n");
    }
    struct ifaddrs *address = addresses;
    while (address)
    {
        char name[100];
        int family = address->ifa_addr->sa_family;
        printf("Family: %d\n", family);
        int size = sizeof(struct sockaddr_in);
        getnameinfo(address->ifa_addr, size, name, sizeof(name), 0, 0, 0);
        printf("Interface Name: %s\n", name);
        address = address->ifa_next; // adress += 1
    }
    printf("************************************code starts here*********************\n");

    //we do the same thing as before but pring only if ipv4 or ipv6
    address = addresses;
    while (address != NULL) {


            int family = address->ifa_addr->sa_family;

            // check if ipv4 or 6
            if (family == AF_INET || family == AF_INET6) {
                
                if (family == AF_INET){
                    printf("IPv4 Interface: %s\n", address->ifa_name);
                }

                else if (family == AF_INET6){
                    printf("IPv6 Interface: %s\n", address->ifa_name);
                }
        }
        address = address->ifa_next;
    }

    freeifaddrs(addresses);
    return 0;
}