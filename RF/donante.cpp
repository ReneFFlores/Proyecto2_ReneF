#include "persona.h"
#include "donante.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

donante::donante(string nom, string apel, string objeto, int vida, string origen)
		:persona(nom, apel, objeto, vida){

}

donante::donante(const donante& other):persona(other), origen(other.origen){

}

string donante::getOrigen(){
    return origen;
}

void donante::setOrigen(string origen){
    this->origen = origen;
}

string donante::Evento(){
	stringstream ss;
    ss << persona::Evento() << " " << persona::getApel() << ", es donante, y le dara " << persona::getObjeto();
    return ss.str();
}

int donante::Efecto(){
	return persona::Efecto();
}
