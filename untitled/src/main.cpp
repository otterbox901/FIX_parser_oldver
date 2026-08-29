

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "../include/decoder.h"
#include "../include/message components/4.4 Tags.h"
#include "../include/message components/Application Messages.h"


int main() {
    int sock= socket(AF_INET,SOCK_STREAM,0);
    if (sock<0) {
        std::cerr<<"Failed to Create Socket :("<<'\n';
        return 1;
    }
    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    if (inet_pton(AF_INET,"127.0.0.1",&server.sin_addr)<=0) {
        std::cerr << "invalid address"<<'\n';
        return -1;
    }

    if (connect(sock,(struct sockaddr*)&server,sizeof(server))<0) {
        std::cerr<<"Connect error \n";
        return -1;
    }
    std::cout<<"Connected successfully"<<'\n';


    std::vector<char>buffer(4096);
    std::string incomplete_message;
    while (true)
    {
        ssize_t bytes_read= recv(sock,buffer.data(),buffer.size(),0);
        if (bytes_read>0) {
            incomplete_message= decoder(buffer, tags44, fix44MsgTypes, incomplete_message);
        }
        else if (bytes_read==0) {
            std::cout<<"Connection closed\n";
            break;
        }
        else {
            std::cerr<<"Receive failed \n";
            return -1;
        }
    }
    close(sock);
    return 0;
}
