#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using std::string;

class persona{
    string nom, apel, objeto;
    int vida;
public:
	//Constructores/desstructor
	persona();
    persona(string, string, string, int);
	persona(const persona&);
	virtual ~persona();

	//Getters
	string getNom();
    string getApel();
    string getObjeto();
    int getVida();

	//setters
	void setNom(string);
    void setApel(string);
    void setObjeto(string);
    void setVida(int);

	//virtuales
    virtual string Evento();//basicamente un toString
    virtual int Efecto();
};

#endif
