#ifndef DONANTE_H
#define DONANTE_H

#include <string>
#include <sstream>
#include "persona.h"

using std::stringstream;
using std::string;

class donante:public persona{
	string origen;
public:
    donante(string, string, string, int, string);
	donante(const donante&);

	string getOrigen();
	void setOrigen(string);
    string getApel();
    void setApel(string);

    virtual string Evento();
    virtual int Efecto();
};

#endif
