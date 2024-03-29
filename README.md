# Informe TP3: Taller-Pages

- Alumno: Federico Elías

- Padrón: 96105

- Fecha de entrega: 13/11/2020

- Fecha de reentrega: 24/11/2020

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
		ya existe, el contenido anterior es reemplazado, en cambio,
		si no se agrega un recurso a depositar, devuelve error.

- Response:
		Clase que lee el mensaje recibido y, dependiendo cuál
		sea el método recibido, llama a una clase hija de la
		clase Method para crear la respuesta correspondiente.
		Sólo soporta los métodos GET y POST, para cualquier otro,
		devuelve METHOD NOT ALLOWED.

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

# Diagrama de delegación de clases:

![DiagramaTP3](https://github.com/nazar9318/taller1-2c2020-TP3/blob/master/assets/DiagramTP3.png)

# Correcciones

- En el constructor de ThreadClient, en la lista de inicializaciones,
se cambió la inicialización del peer del ThreadClient que era por asignación
a hacerse mediante un constructor por movimiento.

- En el constructor por movimiento, ya no se mueven los tipos nativos.
Además el file_descriptor del other ahora se setea a -1.

- Se agregó la clase MethodError, que encapsula la respuesta a métodos inválidos.

- En el método accept de la clase Socket, ya no se hace return de un move de Socket.

- El método close del Socket ahora llama al método nativo close.

- El destructor del Socket ahora chequea que el file descriptor no valga -1.

- El mensaje de salida del Server se imprimía por pantalla con tres std::cout,
ahora se arma un sólo string y se imprime sólo ese.

- El ThreadAccepter, en el método run, ahora cada vez que acepta un nuevo cliente
limpia la lista de clientes que ya no estén corriendo. También, cuando el hilo principal
le indica al Accepter que ya no va a recibir clientes, se limpian los clientes que falten.

- En las clases MethodGet y MethodPost, las respuestas se armaban concatenando
strings, ahora se declara un strinstream y se arma la respuesta usando el operador <<
y cuando ésta está completa, con el método str(), se hace un return de la misma

- Ahora, para recibir mensajes por socket, se declara un vector de 64 bytes
en el cual, en cada iteración, se lo carga de los bytes a recibir, luego se guarda
lo recibido en un stringstream, hasta que se reciben 0 bytes.

- En la clase Thread, en el método start(), ahora se encapsula la asignación
en un try/catch

- Se agregó una clase Impressor, que imprime el mensaje de salida del servidor.

- En la clase Resources, se cambió la sobrecarga del operador () por el operador [].

- En el método ejecutar() de la clase ServerUser, se corrigió un error de bucle infinito.

- Los métodos getBody() y getBodyFile() de la clase Protocol se cambiaron para
tener menos copias y líneas de código.
