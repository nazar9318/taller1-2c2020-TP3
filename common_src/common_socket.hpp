#ifndef COMMON_SOCKET_H
#define COMMON_SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "socket_error.hpp"

class Socket {
	private:
		int fd;
		bool is_server;
		//Funcion: Acepta el socket con el que
		//se quiere comunicar, creando uno nuevo.
		Socket(const Socket& other) = delete;
		Socket& operator=(const Socket& other) = delete;
		Socket& operator=(Socket&& other);
		explicit Socket(int accepted);
		int bind(struct addrinfo* dir);
		int connect(struct addrinfo* dir);
		int bindConnect(struct addrinfo* dir);
		int setFileDesc(struct addrinfo *dirs);
		static struct addrinfo setAddressCriteria(bool es_server);
		struct addrinfo* setDirs(const char* host, const char* port, bool is);
	public:
		//Funcion: Crea un tipo de dato socket
		Socket(const char* host, const char* port, bool is);

		Socket(Socket&& other);

		Socket accept();

		//Funcion: Envia mensaje de tamaño size al
		//file_descriptor con el que está conectado.
		int send(unsigned char* msge, size_t size);

		//Funcion: El server recibe el mensaje del cliente
		int recv(unsigned char* msge, size_t size);

		//Funcion: Server recibe y acepta una conexion del cliente
		int listen();

		void close();

		//Funcion: Destruye el socket
		~Socket();
};

#endif
