#ifndef MALEANTE_H
#define MALEANTE_H

#include <string>
#include <sstream>
#include "persona.h"

using std::stringstream;
using std::string;

class maleante:public persona{
    string descripcion;
public:
    maleante(string, string, string, int, string);
	maleante(const maleante&);

    string getDescripcion()const;
    void setDescripcion(string);

    virtual string Evento();
    virtual int Efecto();
};

#endif
