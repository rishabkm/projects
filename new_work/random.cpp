#include <iostream>
#include <winsock2.h> // Windows Socket Header 🪟

using namespace std;

// Links the Windows socket library
#pragma comment(lib, "ws2_32.lib")

int main() {
    // A. Initialize Windows Sockets
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Winsock initialization failed!" << endl;
        return 1;
    }

    // 1. Create the socket
    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        cerr << "Error creating socket!" << endl;
        WSACleanup();
        return 1;
    }

    // 2. Define the address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002); // Port number
    server_address.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        cerr << "Bind failed!" << endl;
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    // 4. Start listening
    listen(server_socket, 5);
    cout << "Server is waiting for connections on port 9002..." << endl;

    // 5. Accept a connection
    SOCKET client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == INVALID_SOCKET) {
        cerr << "Accept failed!" << endl;
    } else {
        cout << "Client connected!" << endl;

        // 6. Send a message
        const char* message = "Hello from the C++ Windows Server!";
        send(client_socket, message, strlen(message), 0);
        Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
    }

    // 7. Cleanup
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup(); // Finalize Winsock usage 🏁

    return 0;
}