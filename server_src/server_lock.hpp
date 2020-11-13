#ifndef SERVER_LOCK_H
#define SERVER_LOCK_H

#include <mutex>

class Lock {
    private:
        std::mutex &mutex;

        //Borramos el constructor de referencia
        Lock(const Lock&) = delete;
        
        //Borramos el constructor por asignación
        Lock& operator=(const Lock&) = delete;

        //Borramos el constructor de doble referencia
        Lock(Lock&&) = delete;

        //Borramos el constructor por asignación
        Lock& operator=(const Lock&&) = delete;

    public:
        //Función: constructor de Lock,
        //llama al metodo lock del mutex
        explicit Lock(std::mutex &mutex);

        //Función: destructor de Lock,
        //llama al metodo unlock del mutex
        ~Lock();
};

#endif
