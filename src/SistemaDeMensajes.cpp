#include "SistemaDeMensajes.h"
#include "ConexionJugador.h"
// Completar...
SistemaDeMensajes::SistemaDeMensajes(): _conns() {
    _conns[0]= nullptr;
    _conns[1]= nullptr;
    _conns[2]= nullptr;
    _conns[3]= nullptr;
};

SistemaDeMensajes::~SistemaDeMensajes() {
    for(ConexionJugador* i:_conns) {
        if(i!= nullptr) {
            delete i;
        }
    }
    for(Proxy* j:_proxy){
        if(j != nullptr){
            delete j;
        }
    }

}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(_conns[id]!= nullptr) {
        delete _conns[id];
        _conns[id] = new ConexionJugador(ip);
    }else{
        _conns[id] = new ConexionJugador(ip);
    }
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id]!= nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    (*_conns[id]).enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return (*_conns[id]).ip();
}

void SistemaDeMensajes::desregistrarJugador(int id){
    delete _conns[id];
    _conns[id] = nullptr;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id){
    return new Proxy(_conns[id]);


}
