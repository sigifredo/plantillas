
#include<Lindenmayer.hpp>

#include<iostream>//cout ppalmente para depuración
#include<cmath>//las funciones seno y coseno
#include<fstream>//para manejo de archivos
#include<cstdlib>//para poder transformar ascii(char) a float o enteros

using std::ofstream;

Lindenmayer::Lindenmayer()
{
    position[0] = position[1] = 0.0;
    _dAngle = 0.0;
_pFile = new ofstream;
}

Lindenmayer::Lindenmayer(int iNumberOfIterations)
{
    position[0] = position[1] = 0.0;
    _dAngle = 0.0;
    _iIterations = iNumberOfIterations;
}

Lindenmayer::~Lindenmayer()
//este se invoca cuando una isntancia de una clase (objeto) se va a borrar, o cuando el programa sale
//si ud define muchos vectores, por favor, hágales un delete en una función como esta
{
    _pFile->close();
    delete _pFile;
}

void Lindenmayer::replace(const string &str)
//reemplaza las ocurrencias de y y x por las reglas respectivas en la condicion inicial
{
    string temp;

    for(uint i = 0U; i < str.length(); i++)
    {
        if(str[i] == 'y') temp = temp + _sRuley;
        else if(str[i] == 'x') temp = temp + _sRulex;
        else temp = temp + str[i];
    }
    _sCondition = temp;
}

void Lindenmayer::turn()
//traduce el string en posiciones y las escribe en el archivo
{
    write();
    for(uint i=0U; i<_sCondition.length(); i++)
    {
        if(_sCondition[i]=='+') _dAngle+=_dAngleInit;//aumenta el ángulo en _dAngleInit
        else if(_sCondition[i]=='-') _dAngle-=_dAngleInit;//lo disminuye
        else
        {
            //cada línea o posición se distancia en 1 de la anterior
            position[0]+=cos(_dAngle);
            position[1]+=sin(_dAngle);
            write();
        }
    }
}

void Lindenmayer::play()
{
    for(int i=0; i<_iIterations; i++) replace(_sCondition);
    turn();
}

void Lindenmayer::write()
{
    (*_pFile) << position[0] << " " << position[1] << "\n";
}

//MUTADORES
void Lindenmayer::setRules(const string &rule1, const string &rule2)
{
    _sRulex=rule1;
    _sRuley=rule2;
}

void Lindenmayer::setInitialCondition(const string &cond)
{
    _sCondition=cond;
}

void Lindenmayer::setFileName(const string &name)
{
    _sFileName = name;
    _pFile->open(name.c_str());
}

void Lindenmayer::setAngle(double _dAngleI)
{
    _dAngleInit=(_dAngleI*M_PI)/180;//esta función recibe radianes
}

void Lindenmayer::setIterationsNumber(int iter)
{
    _iIterations=iter;
}

