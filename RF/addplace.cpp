#include "addplace.h"
#include "ui_addplace.h"
#include <fstream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

addplace::addplace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addplace)
{
    ui->setupUi(this);
}

addplace::~addplace()
{
    delete ui;
}

void addplace::on_buttonBox_accepted(){

    //abre archivo y variables
    ifstream lugares("lugares.txt");
    int num;
    vector<string> places_city;
    vector<string> places_country;
    string ciudad, pais;

    lugares >> num;

    for(int i = 0; i < num; i++){
        //lee archivos
        lugares >> ciudad;
        lugares >> pais;

        //quita los '_'
        replace(ciudad.begin(), ciudad.end(), '_', ' ');
        replace(pais.begin(), pais.end(), '_', ' ');

        //los envia al vector
        places_city.push_back(ciudad);
        places_country.push_back(pais);

    }

    //agrega nuevo lugar al vector
    places_city.push_back(ui->city->text().toStdString());
    places_country.push_back(ui->country->text().toStdString());
    num++;

    //imprime al archivo, numero
    ofstream lugar_agregado("lugares.txt");
    lugar_agregado << num;
    lugar_agregado << " ";

    //imprime al archivo, lugares
    for(int i = 0; i < num; i++){
        //variables temporales
        string temp_ciudad, temp_pais;

        //declaraciones y replace
        temp_ciudad = places_city.at(i);
        temp_pais = places_country.at(i);
        replace(temp_ciudad.begin(), temp_ciudad.end(), ' ', '_');
        replace(temp_pais.begin(), temp_pais.end(), ' ', '_');

        //agregan al archivo
        lugar_agregado << temp_ciudad;
        lugar_agregado << " ";
        lugar_agregado << temp_pais;
        lugar_agregado << " ";
    }

    //cierra el archivo
    lugar_agregado.close();

    //setea los archivos a ""
    ui->city->setText("");
    ui->country->setText("");

    //vuelve al menu principal
    this->close();

}
