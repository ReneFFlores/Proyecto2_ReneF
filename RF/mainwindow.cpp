#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <ctime>
#include <sstream>
#include <string>
#include <vector>
#include "persona.h"
#include "donante.h"
#include "maleante.h"
#include "addplace.h"

using std::vector;
using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

//SALIR Y GUARDAR AL ARCHIVO
void MainWindow::on_salir_clicked(){
    //Guarda al archivo los valores iniciales
    //Salir

    ofstream set_stats("status.txt");

    set_stats << 25;
    set_stats << " ";
    set_stats << 80;
    set_stats << " ";
    set_stats << 1;
    set_stats.close();
    exit(0);
}

//FUNCION DE DESCANSAR
void MainWindow::on_rest_clicked(){
    srand(time(0));
    int puntos, resta_puntos, week, vida;
    ifstream stats("status.txt");

    stats >> vida;
    stats >> puntos;
    stats >> week;

    srand(time(0));

    resta_puntos = rand() % 10 + 2;
    week++;

    if((puntos-resta_puntos) < 1 || (vida+13) > 100){

        string aviso_descanso;//este dice porque no

        if(puntos-resta_puntos < 1){
            aviso_descanso = "Ha descansado demasiado y perdera todos sus puntos";
        }else{
            if((vida+13) > 100){
                aviso_descanso = "Ha alcanzado su 100 en vidas";
                vida = 100;
            }
        }

        QString temp = QString::fromStdString("No puede descansar, por esta semana");
        ui->bitacora->append(temp);
        temp = QString::fromStdString(aviso_descanso);
        ui->bitacora->append(temp);
        temp = QString::fromStdString("---------------------------------------");
        ui->bitacora->append(temp);
        week--;

    }else{
        puntos-=resta_puntos;
        vida+=13;

        stringstream ss_temp0, ss_temp1, ss_temp2, ss_temp3;

        ss_temp0 << "Semana: " << week-1;
        ss_temp1 << "Ha descansado, recuperó 13 vidas,";
        ss_temp2 << "pero ha perdido " << resta_puntos << " puntos";
        ss_temp3 << "Vida: " << vida << " Puntos actuales: " << puntos;

        string cad_ss0 = ss_temp0.str();
        string cad_ss1 = ss_temp1.str();
        string cad_ss2 = ss_temp2.str();
        string cad_ss3 = ss_temp3.str();

        QString cad = QString::fromStdString(cad_ss0);
        ui->bitacora->append(cad);
        cad = QString::fromStdString("Usted ha descansado por una semana");
        ui->bitacora->append(cad);
        cad = QString::fromStdString(cad_ss1);
        ui->bitacora->append(cad);
        cad = QString::fromStdString(cad_ss2);
        ui->bitacora->append(cad);
        cad = QString::fromStdString(cad_ss3);
        ui->bitacora->append(cad);
        cad = QString::fromStdString("---------------------------------------");
        ui->bitacora->append(cad);

        //Imprime puntuacion en archivo
        ofstream new_stats("status.txt");
        new_stats << vida;
        new_stats << " ";
        new_stats << puntos;
        new_stats << " ";
        new_stats << week;
        new_stats.close();
    }
}

//SALIR SIN GUARDAR ARCHIVOS
void MainWindow::on_pushButton_3_clicked(){
    exit(0);
}

//VER BITACORA DE VIAJES
void MainWindow::on_pushButton_4_clicked(){
    ifstream stats("status.txt");
    int week, puntos, vida;

    stats >> vida;
    stats >> puntos;
    stats >> week;

    QString titulo = "Bitácora";
    ui->bitacora->append(titulo);

    stringstream ss;
    ss << "Semana " << week << ", Vidas: " << vida << ", Puntos: " << puntos;
    ui->bitacora->append(QString::fromStdString(ss.str()));
    ui->bitacora->append("---------------------------------------");
}

//SIMULADOR DE VIAJE
void MainWindow::on_pushButton_2_clicked(){
    srand(time(0));
    vector<persona*>* buenos = new vector<persona*>;
    vector<persona*>* malos = new vector<persona*>;
    vector<string> places_city;
    vector<string> places_country;

    //variables
    double vida_player, vida;
    int puntos, week, tam_vector_gente, efecto_puntos;
    string nom, apel, objeto, origen, descripcion;
    string city, country;

    ifstream stats("status.txt");
    ifstream don("donantes.txt");
    ifstream mal("malvados.txt");
    ifstream places("lugares.txt");

    //variables del vector
    int tam_vector_places;
    places >> tam_vector_places;

    //recorrido lugaares agrega
    for(int i = 0; i < tam_vector_places; i++){
        places >> city;
        places >> country;

        //quita los '_'
        replace(city.begin(), city.end(), '_', ' ');
        replace(country.begin(), country.end(), '_', ' ');

        //los envia al vector
        places_city.push_back(city);
        places_country.push_back(country);
    }

    don >> tam_vector_gente;

    //lee donantes
    for(int i = 0; i < tam_vector_gente; i++){
        don >> nom;
        don >> apel;
        don >> objeto;
        don >> vida;
        don >> origen;

        replace(nom.begin(), nom.end(),'_',' ');
        replace(apel.begin(), apel.end(),'_',' ');
        replace(origen.begin(), origen.end(),'_',' ');
        replace(objeto.begin(), objeto.end(),'_',' ');
        persona* person = new donante(nom, apel, objeto, vida, origen);
        buenos->push_back(person);
    }

    //lee maleantes
    mal >> tam_vector_gente;
    for(int i = 0; i < tam_vector_gente; i++){
        mal >> nom;
        mal >> apel;
        mal >> objeto;
        mal >> vida;
        mal >> descripcion;

        replace(nom.begin(), nom.end(),'_',' ');
        replace(apel.begin(), apel.end(),'_',' ');
        replace(descripcion.begin(), descripcion.end(),'_',' ');
        replace(objeto.begin(), objeto.end(),'_',' ');
        persona* person2 = new maleante(nom, apel, objeto, vida, descripcion);
        malos->push_back(person2);
    }

    //lee estatus del jugador
    stats >> vida_player;
    stats >> puntos;
    stats >> week;

    //puntaje
    efecto_puntos = rand() % 10 + 2;
    puntos+=efecto_puntos;

    //determinar si es bueno o malo
    int pos = rand() % 10;

    //RANDOMLY a donde ir
    int donde_ir_pos = rand() % tam_vector_places;

    if(pos%2 == 0){
        //Personas donantes
        pos = random() % buenos->size();
        stringstream ss_temp0, ss_temp1, ss_temp2, ss_temp3;


        vida = buenos->at(pos)->getVida();
        efecto_puntos = rand() % 10;

        week++;

        if(vida_player+vida > 100){
            vida_player = 100;
        }else{
            vida_player+=vida;
        }

        ss_temp0 << "Semana: " << week-1;
        ss_temp1 << "Usted ha viajado a " << places_city.at(donde_ir_pos) << ", " << places_country.at(donde_ir_pos);
        ss_temp2 << buenos->at(pos)->Evento().c_str();
        ss_temp3 << "esto tiene efecto de +" << buenos->at(pos)->getVida() << " a su vida!";

        string cad_ss0 = ss_temp0.str();
        string cad_ss1 = ss_temp1.str();
        string cad_ss2 = ss_temp2.str();
        string cad_ss3 = ss_temp3.str();

        QString cad0 = QString::fromStdString(cad_ss0);
        ui->bitacora->append(cad0);
        QString cad1 = QString::fromStdString(cad_ss1);
        ui->bitacora->append(cad1);
        QString cad2 = QString::fromStdString(cad_ss2);
        ui->bitacora->append(cad2);
        QString cad3 = QString::fromStdString(cad_ss3);
        ui->bitacora->append(cad3);
        QString cad4 = QString::fromStdString("---------------------------------------");
        ui->bitacora->append(cad4);

        //Imprime nuevos resultados
        ofstream new_stats("status.txt");
        new_stats << vida_player;
        new_stats << " ";
        new_stats << puntos;
        new_stats << " ";
        new_stats << week;
        new_stats.close();
    }else{
        //Personas maleantes
        pos = random() % malos->size();
        stringstream ss_temp0, ss_temp1, ss_temp2, ss_temp3;

        vida = malos->at(pos)->getVida();
        efecto_puntos = rand() % 10;

        week++;

        if((vida_player-vida) < 0){
            vida_player = 0;
            QString salida = QString::fromStdString("Vida en cero, ya perdió");
            ui->bitacora->append(salida);
            ui->pushButton->setEnabled(false);
            ui->pushButton_2->setEnabled(false);
            ui->pushButton_3->setEnabled(false);
            ui->pushButton_4->setEnabled(false);
            ui->pushButton_5->setEnabled(false);
        }else{
            vida_player-=vida;

            ss_temp0 << "Semana: " << week-1;
            ss_temp1 << "Usted ha viajado a " << places_city.at(donde_ir_pos) << ", " << places_country.at(donde_ir_pos);
            ss_temp2 << malos->at(pos)->Evento().c_str();
            ss_temp3 << "esto tiene efecto de " << malos->at(pos)->Efecto() << " a su vida!";

            string cad_ss0 = ss_temp0.str();
            string cad_ss1 = ss_temp1.str();
            string cad_ss2 = ss_temp2.str();
            string cad_ss3 = ss_temp3.str();

            QString cad0 = QString::fromStdString(cad_ss0);
            ui->bitacora->append(cad0);
            QString cad1 = QString::fromStdString(cad_ss1);
            ui->bitacora->append(cad1);
            QString cad2 = QString::fromStdString(cad_ss2);
            ui->bitacora->append(cad2);
            QString cad3 = QString::fromStdString(cad_ss3);
            ui->bitacora->append(cad3);
            QString cad4 = QString::fromStdString("---------------------------------------");
            ui->bitacora->append(cad4);

            //Imprime nuevos resultados
            ofstream new_stats("status.txt");
            new_stats << vida_player;
            new_stats << " ";
            new_stats << puntos;
            new_stats << " ";
            new_stats << week;
            new_stats.close();
        }
    }
}

//VER LUGARES PARA IR
void MainWindow::on_pushButton_5_clicked(){
    vector<string> lugares;

    ifstream getplace("lugares.txt");
    string city, country, temp;
    int total_lugares;

    getplace >> total_lugares;

    QString titulo = QString::fromStdString("Lugares visitables:");
    ui->bitacora->append(titulo);

    for(int i = 0; i < total_lugares; i++){
        getplace >> city;
        getplace >> country;
        replace(city.begin(), city.end(), '_', ' ');
        replace(country.begin(), country.end(), '_', ' ');
        temp = "";
        temp+=city;
        temp+=", ";
        temp+=country;
        //lugares.push_back(temp);
        QString cad = QString::fromStdString(temp);
        ui->bitacora->append(cad);
    }

    QString separador = QString::fromStdString("---------------------------------------");
    ui->bitacora->append(separador);
}

//AGREGAR LUGAR
void MainWindow::on_pushButton_clicked(){
    addplace ap;
    ap.exec();
}

//VER INSTRUCCIONES
void MainWindow::on_pushButton_6_clicked(){
    string instrucciones = "¡Bienvenido Mochilero! :D\n";
    instrucciones+= "He aca las instrucciones:\n";
    instrucciones+= "1.- Revisar Bitácora\n";
    instrucciones+= "     Podrá ver sus puntos de vida y de experiencia\n";
    instrucciones+= "2.- Instrucciones\n";
    instrucciones+= "     Ver instrucciones\n";
    instrucciones+= "3.- Agregar Lugar\n";
    instrucciones+= "     Podrá agregar un lugar, siempre y cuando sepa como se llame :)\n";
    instrucciones+= "4.- Viajar\n";
    instrucciones+= "     Si al perder un vuelo la aereolinea vende su boleto mas barato...\n";
    instrucciones+= "     ¿a donde iria la persona que lo compre? ¡Averguelo!\n";
    instrucciones+= "5. -Descansar\n";
    instrucciones+= "     Ha sido atacado y le queda poca vida? Descanse...\n";
    instrucciones+= "6.- Lugares visitables\n";
    instrucciones+= "     donde puede llevarlo la aereolinea que use\n";
    instrucciones+= "7.- Guardar y Salir\n";
    instrucciones+= "     ¿Está cansad@? Puede salir y volver a jugar con su progreso\n";
    instrucciones+= "8.- Guardar sin salir\n";
    instrucciones+= "     Desea incializarse en cero? ¡Oprima Aca!";

    QString separador = QString::fromStdString(instrucciones);
    ui->bitacora->append(separador);
    separador = QString::fromStdString("---------------------------------------");
    ui->bitacora->append(separador);
}
