#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
///TEST DRIVEN DEVELOPMENT
using namespace std;

template <class type1>///type1 = int
class Jugador
{
    type1 puntaje1;
    public:
    Jugador() {
        puntaje1  = 0 ;
    }
    ~Jugador () {

    }
    void setPuntaje1 ( type1 Puntaje1 ) {
        this->puntaje1 = Puntaje1;
    };
    type1 getPuntaje1 () {
        return puntaje1;
    }
};
int TesteoDeClases( int a )
{
return a;
}
float TesteoDeClases( float a )
{
return a;
}
bool TesteoDeClases( bool a )
{
    if( a == true )
    {
        return true;
    }
    else if( a == false )
    {
        return false;
    }
}
TEST_CASE( "Test de clase Jugador - [Getters y Setters]" )
{
    int JugadoresTest;
    int Testeo;
    Jugador<int> Jugadores;

    ///SETTER DE CLASE JUGADOR. VARIABLE ESCOJIDA ALEATORIAMENTE. CASO PUNTAJE1
    Jugadores.setPuntaje1(13);
    JugadoresTest = Jugadores.getPuntaje1();
    Testeo = TesteoDeClases( JugadoresTest );

    REQUIRE( JugadoresTest == 13 );
    REQUIRE( Testeo == Jugadores.getPuntaje1() );
}

/*

class Pelota
{
    type2 velocidadX;
public:
    ~Pelota ()
    {

    }

    void setVelX ( type2 velocidadX )
    {
        this->velocidadX = velocidadX;
    }


    type2 getVelX ()
    {
        return velocidadX;
    }
}

template <class type1,class type2>///type1 = int - type2 = bool
class Pelota
{
    type2 velocidadX;
public:
    void setVelX ( type2 velocidadX )
    {
        this->velocidadX = velocidadX;
    }
    type2 getVelX ()
    {
        return velocidadX;
    }
};

