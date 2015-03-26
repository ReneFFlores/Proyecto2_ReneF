#include "persona.h"
#include "maleante.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

maleante::maleante(string nom, string apel, string objeto, int vida, string descripcion):
        persona(nom, apel, objeto, vida){

}

maleante::maleante(const maleante& other):persona(other){

}

string maleante::getDescripcion()const{
    return descripcion;
}

void maleante::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

string maleante::Evento(){
	stringstream ss;
    ss << persona::Evento() << ", es maleante, y lo ataco con " << persona::getObjeto();
    return ss.str();
}

int maleante::Efecto(){
    return -persona::Efecto();
}
