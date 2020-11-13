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
		
		//Borramos la asignación de referencia
		Socket& operator=(const Socket& other) = delete;
		
		//Función: constructor por asignación de file_descriptor
		explicit Socket(int accepted);
		
		//Función: llama a la función bind para el socket
		int bind(struct addrinfo* dir);
		
		//Función: llama a la función connect para el socket
		int connect(struct addrinfo* dir);
		
		//Función: si el socket es servidor llama a bind,
		//si no llama a connect
		int bindConnect(struct addrinfo* dir);
		
		//Función: recorre la lista de direcciones para intentar
		//conectar o enlazar el socket
		int setFileDesc(struct addrinfo *dirs);
		
		//Función: setea los criterios de conexión
		//según sea un servidor o un cliente
		static struct addrinfo setAddressCriteria(bool es_server);

		//Funcion: Crea las direcciones con las que el server va a intentar conectarse
		//Pre condicion: Puerto debe ser existente.
		//Post condicion: Si getaddrinfo falla se libera la memoria, pero en caso 
		//de tener exito debe ser el llamador el que libere la memoria reservada.
		struct addrinfo* setDirs(const char* host, const char* port, bool is);
	public:
		//Funcion: Crea un tipo de dato socket
		Socket(const char* host, const char* port, bool is);

		//Función: constructor por movimiento
		Socket(Socket&& other);

		Socket accept();

		//Funcion: Envia mensaje de tamaño size al
		//file_descriptor con el que está conectado.
		int send(unsigned char* msge, size_t size);

		//Funcion: El server recibe el mensaje del cliente
		int recv(unsigned char* msge, size_t size);

		//Funcion: Server recibe y acepta una conexion del cliente
		int listen();
		
		//Función: cierra el socket
		void close();

		//Funcion: Destruye el socket
		~Socket();
};

#endif
