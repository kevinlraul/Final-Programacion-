
//TDD
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <set>

class Habilidades
{
    char habilidad1[15];
    char habilidad2[15];
};

class Empleado
{
public:
    virtual void imprime_cargo()
    {
        cout << "Cargo no definido" << endl;
    }
};

class Directivo:public Empleado
{
    Habilidades uno;
    void imprime_cargo()
    {
        cout << "Es un directivo" << endl;
    }
};

class Operario:public Empleado
{
    Habilidades dos;
    void imprime_cargo()
    {
        cout << "Es un operario" << endl;
    }
};

class Oficial:public Operario
{
    Habilidades tres;
    void imprime_cargo()
    {
        cout << "Es un operario oficial" << endl;
    }
};

class Tecnico:public Operario
{
    Habilidades cuatro;
    void imprime_cargo()
    {
        cout << "Es un operario tecnico" << endl;
    }
};

class Medico :public Empleado
{

    list<Medico> med_list;
    list<Medico>::iterator iter_list;
    set<Medico *> setmed;//Para set
    set<Medico *>::iterator sit,send;//Para set
public:
    Habilidades cinco;
    string nombre;
    int matricula;
    void ingresarMedico(string n, int m)
    {

        //list
        Medico med;
        med.setnombre(n);
        med.setmatricula(m);
        this->med_list.push_back(med);

        //set
        Medico * medset=new Medico();
        medset->setnombre(n);
        medset->setmatricula(m);
        setmed.insert(medset);
    }
    void imprime_cargo()
    {
        cout << "Es un Medico" << endl;
    }
    //funciones
    int getmatricula()
    {
        return this->matricula;
    }

    string getnombre()
    {
        return this->nombre;
    }
    // Funciones setter
    void setnombre(string nom)
    {
        this->nombre=nom;
    }
    void setmatricula(int mat)
    {
        this->matricula=mat;
    }
    void mostrar()
    {
        cout<<"Datos cargados en la lista: "<<endl;


        cout<<"Datos de Medicos: "<<endl;
        for(iter_list=med_list.begin();
                iter_list!=med_list.end(); iter_list++)
        {
            cout<<"Numero de matricula: "<<iter_list->getmatricula()<<" Nombre: "<<iter_list->getnombre()<<endl;
        }


        cout<<endl<<"Datos cargados en Set: "<<endl;
        sit=(setmed.begin());
        send=(setmed.end());

        for(; sit!=send; sit++)
        {
            cout << "Numero de Matricula: "   <<(*sit)->getmatricula() << "  ";
            cout << "Nombre: " <<(*sit)->getnombre() << "  ";
            cout << endl;
        }
        system("PAUSE");

    }
     void eliminarMedico()
    {
        cout<<endl<<endl<<"Se borra a Damian en list: "<<endl;
        this->med_list.pop_back();
        cout<<endl<<"Se borra a Cosme en Set: "<<endl<<endl;
        sit=(setmed.begin());
        send=(setmed.end());

        for(; sit!=send; sit++) //Para set
        {
            if ((*sit)->getnombre() == "Cosme")//Para set
            {
                this->setmed.erase(sit);//Para set
            }
        }
    }
    bool testList(string n, int m)
    {
        for(iter_list=med_list.begin();
                iter_list!=med_list.end(); iter_list++)
        {
            if(m == iter_list->getmatricula() && n ==iter_list->getnombre() )
            {
                return true;
            }
        }
        return false;
    }
     bool testSet(string n, int m)
    {
         sit=(setmed.begin());
        send=(setmed.end());
       for(; sit!=send; sit++) //Para set
        {
            if ((*sit)->getmatricula() == m && (*sit)->getnombre() == n  )//Para set
            {
                return true;
            }
        }
        return false;
    }
    void limpiar()
    {
        med_list.clear();
        setmed.clear();
    }
};

void imprimir(Empleado &i)
{
    i.imprime_cargo();
}

main()
{
    Oficial Rafael ;
    Tecnico Miguel;
    Directivo Gabriel;
    Medico med;
    cout << "Rafael" << endl;
    imprimir(Rafael);
    cout << "Gabriel" << endl;
    imprimir(Gabriel);
    cout << "Miguel" << endl;
    imprimir(Miguel);

    med.ingresarMedico("Cosme", 1234567);
    med.ingresarMedico("Damian", 1233337);
    med.mostrar();
    med.eliminarMedico();
    med.mostrar();
    med.limpiar();
    cout<<endl<<endl<<"Se han limpiado los List y Set: "<<endl<<endl;
    med.mostrar();
    cout<<endl<<endl<<"Fin."<<endl<<endl;

}

/*
TEST_CASE()
{
    Oficial Rafael ;
    Tecnico Miguel;
    Directivo Gabriel;
    Medico med;
    med.ingresarMedico("Cosme", 1234567);
    REQUIRE(med.testList("Cosme", 1234567));
    REQUIRE(med.testSet("Cosme", 1234567));
    med.ingresarMedico("Damian", 1233337);
    med.mostrar();

}
*/

