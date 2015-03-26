#include "persona.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

persona::persona(string nom, string apel, string objeto, int vida){
	this->nom = nom,
	this->apel = apel;
	this->objeto = objeto;
	this->vida = vida;
}

persona::persona(const persona& other)
		:nom(other.nom), apel(other.apel), objeto(other.objeto), vida(other.vida){

}

persona::~persona(){

}

string persona::getNom(){
	return nom;
}

string persona::getApel(){
	return apel;
}

string persona::getObjeto(){
	return objeto;
}

int persona::getVida(){
	return vida;
}

void persona::setNom(string nom){
	this->nom = nom;
}

void persona::setApel(string apel){
	this->apel = apel;
}

void persona::setObjeto(string objeto){
	this->objeto = objeto;
}

void persona::setVida(int vida){
	this->vida = vida;
}

string persona::Evento(){
	stringstream ss;
    ss << "Usted se encontró a " << nom;
	return ss.str();
}

int persona::Efecto(){
	return vida;
}
