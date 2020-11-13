# Informe TP3: Taller-Pages

- Alumno: Federico Elías

- Padrón: 96105

- Fecha de entrega: 13/11/2020

# División de responsabilidades

- ServerUser:
		Implementa el hilo principal del server, hasta
		que el usuario introduce el comando de salida 'q'

- ClientUser:
		Implementa el cliente, recibe el mensaje a mandar
		al servidor e imprime la respuesta por pantalla.

- Socket:
		Implementa un Socket TCP, distinguiendo
		si es un servidor o cliente.

- Thread:
		Implementa la API de Thread vista en clase.

- ThreadAccepter:
		Hilo encargado de implementar la aceptación
		de clientes del servidor, cada vez que acepta un cliente
		lo apila en un vector de ThreadClients y lo lanza.

- ThreadClient:
		Hilo que implementa la recepción del mensaje mandado
		por el cliente, luego le envía la respuesta.

- Method:
		Clase madre de la respuesta a cada método
		recibido, dependiendo cuál sea recibido.
		Contiene una referencia a los recursos
		de los petitorios, que también la tienen sus hijas.

- MethodGet:
		Clase que crea la respuesta correspondiente al método
		GET, busca el recurso solicitado en el repositorio
		de los recursos y, de encontrarlo, devuelve el contenido,
		en caso contrario devuelve NOT FOUND.

- MethodPost:
		Clase que crea una respuesta cuando el método es POST.
		Deposita el contenido del recurso solicitado, si el recurso
		ya existe, el contenido anterior es reemplazado.

- Response:
		Clase que lee el mensaje recibido y, dependiendo cuál
		sea el método recibido, llama a una clase hija de la
		clase Method para crear la respuesta correspondiente

- Resource:
		Clase que encapsula los recursos depositados por los petitorios.
		Cada vez que se le solicita un recurso realiza un bloqueo con su mutex.

- Protocol:
		Clase que lee los petitorios, puede identificar el método,
		recurso, protocolo, y body de cada uno.

- Lock:
		Permite implementar la protección de recursos respetando el RAII,
		su constructor recibe una referencia a un mutex, y en el mismo
		llama al método lock() del mutex, luego su destructor implementa el unlock()
