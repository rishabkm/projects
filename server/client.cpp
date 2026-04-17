#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")

int main() {
    std::cout << "Starting Client...\n";

    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "WSAStartup failed. Error: " << WSAGetLastError() << std::endl;
        return 1;
    }

    // Create socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cout << "Socket creation failed. Error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Set up server address (localhost on port 5000)
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);

    // FIXED: Use inet_addr instead of inet_pton (works reliably with MinGW)
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cout << "Connect failed. Error: " << WSAGetLastError() 
                  << "\n→ Make sure the server is running first on port 5000!\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to server successfully!\n";

    // Send message
    const char* message = "Hello, server! This is from client.";
    int bytesSent = send(clientSocket, message, strlen(message), 0);
    if (bytesSent > 0) {
        std::cout << "Message sent successfully!\n";
    } else {
        std::cout << "Send failed.\n";
    }

    // Clean up
    closesocket(clientSocket);
    WSACleanup();

    std::cout << "Client finished.\n";
    return 0;
}