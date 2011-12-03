
#include<Lindenmayer.hpp>

#include<fstream>
#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    ifstream ifile;
    ifile.open("in.l");

    while( !ifile.eof() ) //mientras el archivo no se ha acabado
    {
        string text1,text2;//son 2 porque puse la función para leer las condiciones de 2 argumentos... mala cosa
        if( text1 == "END" ) break;

        Lindenmayer curve;//creamos un objeto

        //rellenamos el objeto con la info necesaria
        ifile>>text1;
        if( text1 == "00" ) continue;//si se acaba un conjnto de condiciones en in.l vuelve al ppio del while
        if( text1 == "END" ) break; //control de error
        cout<<"Calculando trayectoria de "<<text1<<endl;
        curve.setFilename(text1);
        ifile>>text1;//reutilizamos la variable text1, no es legible pero ahorra
        curve.setInitialCondition(text1);
        ifile>>text1;
        ifile>>text2;
        curve.setRules(text1,text2);
        ifile>>text1;
        //toca pasarlo a float porque cuando lee a text1 éste es un string
        //Es más costoso que un hp porque toca incluir otra librería
        curve.setAngle(atof(text1.c_str()));
        ifile>>text1;
        curve.setIterationsNumber(atoi(text1.c_str()));//igual apra este, toca volverlo entero

        //esta función la definimos para que hiciera todo lo necesario
        curve.play();
        //cout<<curve.getCondition()<<endl;
    }

    ifile.close();//importate cerrar esta vaina siempre.

    return 0;
}

