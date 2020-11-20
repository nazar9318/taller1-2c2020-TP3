#define _POSIX_C_SOURCE 200112L
#include "common_socket.hpp"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <utility>

//Funcion: Enlaza al socket con la direccion pasada por parametro
//Pre condicion: Ninguna.
//Post condicion: Si falla al enlazar cierra el file descriptor
int Socket::bind(struct addrinfo* dir) {
	return ::bind(this->fd, dir->ai_addr, dir->ai_addrlen);
}

//Funcion: Conecta al socket con la direccion pasada por parametro
//Pre condicion: Ninguna.
//Post condicion: Si falla al enlazar cierra el file descriptor
int Socket::connect(struct addrinfo* dir) {
	return ::connect(this->fd, dir->ai_addr, dir->ai_addrlen);
}

int Socket::bindConnect(struct addrinfo* dir) {
	return this->is_server ? this->bind(dir) : this->connect(dir);
}

//Funcion: crea el socket usando las direcciones pasadas por parametro.
//Pre condicion: Ninguna.
//Post condicion: En caso de fallar devuelve NULL
int Socket::setFileDesc(struct addrinfo *dirs) {
	struct addrinfo *count = dirs;
	while (count != NULL) {
		this->fd = socket(count->ai_family,count->ai_socktype,count->ai_protocol);
		if (this->bindConnect(count) == -1) {
			::close(this->fd);
			count = count->ai_next;
		} else {
			return 0;
		}
	}
	return -1;
}

struct addrinfo Socket::setAddressCriteria(bool es_server) {
	struct addrinfo criteria;
	memset(&criteria, 0, sizeof(struct addrinfo));
	criteria.ai_family = AF_INET;		//Permite IPv4
	criteria.ai_socktype = SOCK_STREAM;	//Protocolo TCP
	criteria.ai_flags = es_server ? AI_PASSIVE : 0;
	return criteria;
}

struct addrinfo* Socket::setDirs(const char* host, const char* port, bool is) {
	struct addrinfo criteria = Socket::setAddressCriteria(is);
	struct addrinfo *direcciones;
	if (getaddrinfo(host, port, &criteria, &direcciones) == 0) {
		return direcciones;
	}
	throw SocketError("getaddrinfo devolvió %d en linea: %d\n", errno, __LINE__);
}

Socket::Socket(const char* host, const char* port, bool is) {
	this->is_server = is;
	struct addrinfo *direcciones = this->setDirs(host, port, this->is_server);
	if (this->setFileDesc(direcciones) == -1) {
		if (this->is_server) {
			throw SocketError("fallo al enlazar socket con las direcciones creadas\n");
		} else {
			throw SocketError("fallo al conectar socket con las direcciones creadas\n");
		}
	}
	freeaddrinfo(direcciones);
}

int Socket::send(uint8_t* msge, size_t size) {
	int sent = 0;
	size_t total = 0;
	do {
		sent = ::send(this->fd, msge + total, size - total, MSG_NOSIGNAL);
		if (sent < 0) {
			throw SocketError("fallo al enviar mensaje: %d\n", sent, __LINE__);
		}
		total += sent;
	} while (sent == (int)(size-total));
	return total;
}

int Socket::recv(uint8_t* msge, size_t size) {
	int received = 0;
	size_t total = 0;
	do {
		received = ::recv(this->fd, msge + total, size - total, 0);
		if (received < 0) {
			throw SocketError("fallo al recibir mensaje: %d\n", received, __LINE__);
		}
		total += received;
	} while (received == (int)(size-total));
	return total;
}

Socket::Socket(Socket&& other) {
	if (this != &other) {
		this->fd = std::move(other.fd);
		this->is_server = std::move(other.is_server);
		other.fd = -1;
	}
}

Socket::Socket(int accepted) {
	if (accepted == -1) {
		throw SocketError("Recibido file descriptor: %d\n", accepted, __LINE__);
	}
	this->fd = accepted;
	this->is_server = false;
}

Socket Socket::accept() {
	int fd = ::accept(this->fd, NULL, NULL);
	return Socket(fd);
}

int Socket::listen() {
	if (::listen(fd, 10) == -1) {
		throw SocketError("listen del socket devolvió -1\n");
		return -1;
	}
	return 0;
}

void Socket::stopSending() {
	shutdown(this->fd, SHUT_WR);
}

void Socket::stopReceiving() {
	shutdown(this->fd, SHUT_RD);
}

void Socket::close() {
	shutdown(this->fd, SHUT_RDWR);
	::close(this->fd);
	this->fd = -1;
}

Socket::~Socket() {
	if (this->fd != -1) {
		::close(this->fd);
	}
}

