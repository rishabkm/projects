#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")   // For MSVC, optional with g++

int main() {
    std::cout << "Starting Server...\n";

    // 1. Initialize Winsock (very important on Windows)
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "WSAStartup failed. Error: " << WSAGetLastError() << std::endl;
        return 1;
    }

    // 2. Create socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cout << "Socket creation failed. Error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // 3. Set up address (use port 5000 to avoid conflicts)
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);           // ← Change port here if needed
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Optional: Allow reuse of port quickly
    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));

    // 4. Bind
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cout << "Bind failed on port 5000. Error: " << WSAGetLastError() 
                  << "\nTip: Change port or close other programs using it.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 5. Listen
    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        std::cout << "Listen failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on port 5000... Waiting for client...\n";

    // 6. Accept client
    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET) {
        std::cout << "Accept failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Client connected!\n";

    // 7. Receive message
    char buffer[1024] = {0};
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        std::cout << "Message from client: " << buffer << std::endl;
    } else {
        std::cout << "No message received or connection closed.\n";
    }

    // 8. Clean up
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    std::cout << "Server finished.\n";
    return 0;
}