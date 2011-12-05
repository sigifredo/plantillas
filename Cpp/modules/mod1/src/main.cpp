
#include<Lindenmayer.hpp>

#include<fstream>
#include<iostream>
#include<cstdlib>

using namespace std;

#define debug()		std::cout << __LINE__ << std::endl

void usage(char* szAppName);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Número de argumentos invalido" << std::endl;
        usage(argv[0]);
        return -1;
    }
    else
    {
        ifstream ifile;
        ifile.open(argv[1]);
    
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
debug();
            curve.setFileName(text1);
debug();
            ifile>>text1;//reutilizamos la variable text1, no es legible pero ahorra
debug();
            curve.setInitialCondition(text1);
debug();
            ifile>>text1;
debug();
            ifile>>text2;
debug();
            curve.setRules(text1,text2);
debug();
            ifile>>text1;
debug();
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
}

void usage(char * szAppName)
{
    std::cout << "Use:\n" << szAppName << " <input file>" << std::endl;
}
