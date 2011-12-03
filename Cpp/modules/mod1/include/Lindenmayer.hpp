/*
   Sistemas de Lindenmayer
   dada uan condición inicial y unas reglas de reemplazo, se recorre la condición inicial n veces
   y en cada recorrido se aplican las condiciones de reemplazo, i.e.
   CI: x
   reglax: x -> y-x-y
   reglay: y -> x+y+x
   
   de la primera iteración resulta: y-x-y
   de la segunda: x+y+x-y-x-y-x+y+x
   
   cada letra significa avanzar 1 hacia adelante
   el signo + significa aumentar el ángulo y el - disminuirlo
   
   Este código crea varios archivos dependiendo de la cantidad de bloques en in.l
   
   cada bloque del archivo in.l debe estar en este formato:
   nombrearchivo
   CI
   reglax
   reglay
   ángulo
   número de iteraciones
   
   00 finaliza cada bloque y END finaliza el archivo
*/

#ifndef LINDENMAYER_HPP
#define LINDENMAYER_HPP

#include<string>
#include<fstream>

using std::ofstream;
typedef std::string string;
typedef unsigned int uint;

class Lindenmayer
{
public://a los elementos de aqui para abajo se peden acceder fuera de la clase
    Lindenmayer();//constructor, debe tener el mismo nombre de la clase
    Lindenmayer(int iNumberOfIteraions);//sobrecarga del constructor
    ~Lindenmayer();//el malo de las tortugas ninja

    void replace(const string &str);//reemplaza las ocurrencias de la letra por la reglas de transformación
    void play();//concentra todo llamando a replace 'iterations' veces y luego a turn
    void turn();//traduce el string en posiciones y llama a write
    void write();//escribe lo que está en la variable pos a un file

//ACCESORES Y MUTADORES
//para poder acceder y cambiar elementos privados de la clase
    void setRules(const string &sRule1, const string &sRule2);
    void setInitialCondition(const string &sCond);
    void setFilename(const string &sName);
    void setAngle(double dAngleI);
    void setIterationsNumber(int iIter);

//definiciones inline, es este caso se definen para depurar el código en el main
    string fileName() const;
    string rules() const;
    double angle() const;
    string condition() const;

private://a los elementos de aca para abajo solo se puede acceder desde la clase
    string _sCondition, _sRuley, _sRulex, _sFileName;
    double position[2], _dAngle, _dAngleInit;
    int _iIterations;
    ofstream * _file;

};//ojo con este ; es como las estructuras


inline string Lindenmayer::fileName() const
{
    return _sFileName;
}

inline string Lindenmayer::rules() const
{
    return _sRuley + " " + _sRulex;
}

inline double Lindenmayer::angle() const
{
    return _dAngleInit;
}

inline string Lindenmayer::condition() const
{
    return _sCondition;
}

#endif
