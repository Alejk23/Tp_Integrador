using namespace std;
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "funciones.h"
#include "rlutil.h"

int main()
{
    const int TAM=6;
    int rondas;
//VECTORES
    char nom1[15];
    char nom2[15];
    int v[TAM];

    int y=0;//OPCIONES
    //DISEÑO GENERAL
    rlutil::setBackgroundColor(rlutil::WHITE);

    rlutil::setColor(rlutil::BLACK);
    rlutil::cls();


// JUEGO SOLITARIO - ok
// MULTIJUGADOR - ok
// CREDITOS - ok
// SALIR - ok

    while(true)  //MENU DE INICIO
    {


        rlutil::locate(25,1);
        cout<<"----------------ESCALERA----------------";


        rlutil::locate(40,7);
        cout<< "JUGAR"<<endl;
        rlutil::locate(40,8);
        cout<< "MULTIJUGADOR"<<endl;
        rlutil::locate(40,9);
        cout<< "CREDITOS"<<endl;
        rlutil::locate(40,10);
        cout<< "SALIR"<<endl;


        rlutil::hidecursor();

        rlutil::locate(38, 7 + y);
        cout<< ">" <<endl;

        rlutil::locate(53, 7 + y);
        cout<< "<" <<endl;


        switch (rlutil::getkey())
        {
        case 14: //ARRIBA

            rlutil::locate(38, 7 + y);
            cout<< " " <<endl;
            rlutil::locate(53, 7 + y);
            cout<< " " <<endl;

            y--;
            if(y<0)
            {
                y=0;
            }
            break;
        case 15:  //ABAJO

            rlutil::locate(38, 7 + y);
            cout<< " " <<endl;
            rlutil::locate(53, 7 + y);
            cout<< " " <<endl;

            y++;
            if(y>3)
            {
                y=3;
            }
            break;

        case 1:  //ENTER


            int Total=0,Total2=0,k=0,n=0;
            switch(y)
            {
            case 0: //SOLITARIO-------------------------
                rlutil::cls();

                cout<<"Jugando en solitario..."<<endl<<endl<<endl;

                cout<<"Ingrese nombre del jugador: ";
                cin>>nom1;

                cout<<endl<<endl;

                cout<<"ingrese cantidad de rondas: ";
                cin>>rondas;

                cout<<"Inicio de la ronda, tienes 3 lanzamientos."<<endl;


                for (int i=1; i<=rondas; i++)
                {

                    for (int j=0; j<3; j++)
                    {
                        rlutil::cls();
                        cout<<"RONDA Nro "<<i<<endl;
                        cout<<"TURNO DE: "<<nom1<<endl;
                        cout<<"LANZAMIENTO Nro: "<<j+1<<endl;
                        cout<<"----------------------------------------------------------"<<endl;
                        cargarVectorAleatorio(v,TAM);
                        ordenarVector(v, TAM );
                        mostrarVector(v, TAM);


                        if(v[0]==6&&v[1]==6&&v[2]==6&&v[3]==6&&v[4]==6&&v[5]==6)
                        {
                            Total=0;
                        }
                        Total=Total+Combinaciones(v, TAM);

                        cout<<endl;
                        cout<<"SUS PUNTOS TOTALES SON: "<<Total<<endl;
                        cout<<endl;
                        cout<<"Presione tecla Enter para volver a tirar"<<endl;

                        rlutil::anykey();

                        if(Total>=500)
                        {
                            rlutil::cls();
                            cout<<"-----FELICIDADES "<<nom1;
                            cout<<" HAS GANADO LA PARTIDA!-----"<<endl;
                            j=3;
                            rondas=rondas;
                            rlutil::anykey();

                        }
                    }
                }
                Total=0;
                rlutil::cls();

                break;

            case 1: //MULTIJUGADOR----------------------
                rlutil::cls();

                cout<<"Jugando en multijugador..."<<endl<<endl<<endl;

                cout<<"Ingrese nombre del jugador 1:";
                cin>>nom1;
                cout<<endl;
                cout<<"Ingrese nombre del jugador 2:";
                cin>>nom2;
                cout<<endl;

                cout<<endl<<endl;

                cout<<"Ingrese cantidad de rondas: ";
                cin>>rondas;
                rlutil::cls();
                cout<<endl;
                rlutil::locate(15, 1);
                cout<<"---------------------------------------------------------------------------------------------"<<endl;
                rlutil::locate(47, 2);
                cout<<" Inicio del juego";
                rlutil::locate(40,3);
                cout<<"presione ENTER para lanzar los dados"<<endl;
                rlutil::locate(15,4);
                cout<<"---------------------------------------------------------------------------------------------"<<endl;
                cout<<endl;

                rlutil::anykey();
                rlutil::cls();

                for (int i=1; i<=rondas; i++)
                {
                    k=0;
                    n=0;// "k" y "n" es solo visual para las tiradas del Player 1 y Player 2, porque si usamos la variable controladora del for, va a mostrar lazamiento 4,5 y 6.
                    for (int j=1; j<=6; j++)
                    {
                        if(!(j%2==0))
                        {

                            n++;
                            cout<<endl;
                            cout<<"----------------------------------------------------------"<<endl;
                            cout<<"RONDA Nro "<<i<<endl;
                            cout<<"TURNO DE: "<<nom1<<endl;
                            cout<<"LAZAMIENTIO Nro: "<<n<<endl;
                            cout<<"----------------------------------------------------------"<<endl;
                            cargarVectorAleatorio(v,TAM);
                            ordenarVector(v, TAM );
                            mostrarVector(v, TAM);
                            if(v[0]==6&&v[1]==6&&v[2]==6&&v[3]==6&&v[4]==6&&v[5]==6)
                            {
                                Total=0;
                            }
                            Total=Total+Combinaciones(v, TAM);
                            cout<<"----------------------------------------------------------"<<endl;
                            cout<<endl;
                            cout<<nom1;
                            cout<<": "<<Total <<" puntos"<<endl;
                            cout<<endl;
                            cout<<nom2;
                            cout<<": "<<Total2<<" puntos"<<endl<<endl;
                            cout<<"----------------------------------------------------------"<<endl;
                            cout<<"SIGUIENTE TURNO: "<<nom2<<endl;

                            if(Total>=500)
                            {
                                rlutil::cls();
                                cout<<"-----FELICIDADES "<<nom1<<" HAS HECHO ESCALERA!-----"<<endl;
                                j=6;
                                rondas=rondas;
                            }
                            else if (Total==500&&Total2==500)
                            {
                                cout<<"EMPATE AMBOS JUGADORES LLEGARON A 500!"<<endl;
                                j=6;
                                rondas=rondas;
                            }


                        }
                        else
                        {
                            k++;
                            cout<<endl;
                            cout<<"----------------------------------------------------------"<<endl;
                            cout<<"RONDA Nro "<<i<<endl;
                            cout<<"TURNO DE: "<<nom2<<endl;
                            cout<<"LANZAMIENTO Nro: "<<k<<endl;
                            cout<<"----------------------------------------------------------"<<endl;
                            cargarVectorAleatorio(v,TAM);
                            ordenarVector(v, TAM );
                            mostrarVector(v, TAM);
                            if(v[0]==6&&v[1]==6&&v[2]==6&&v[3]==6&&v[4]==6&&v[5]==6)
                            {
                                Total2=0;
                            }
                            Total2=Total2+Combinaciones(v, TAM);
                            cout<<"----------------------------------------------------------"<<endl;
                            cout<<endl;
                            cout<<nom1;
                            cout<<": "<<Total<<" puntos"<<endl;
                            cout<<endl;
                            cout<<nom2;
                            cout<<": "<<Total2<<" puntos"<<endl<<endl;
                            cout<<"----------------------------------------------------------"<<endl;
                            cout<<"SIGUIENTE TURNO: "<<nom1<<endl;

                            if(Total2>=500)
                            {
                                rlutil::cls();
                                cout<<"-----FELICIDADES "<<nom2<<" HAS HECHO ESCALERA!-----"<<endl;
                                j=6;
                                rondas=rondas;
                            }
                            else if (Total==500&&Total2==500)
                            {
                                cout<<"EMPATE AMBOS JUGADORES LLEGARON A 500!"<<endl;
                                j=6;
                                rondas=rondas;
                            }
                        }

                        rlutil::anykey();
                        rlutil::cls();

                    }
                }
                if(Total==Total2)
                {
                    rlutil::cls();
                    cout<<endl;
                    rlutil::locate(25,2);
                    cout<<"---------------------------------------------------"<<endl;
                    rlutil::locate(25,3);
                    cout<<"--------------EMPATE CON "<<Total;
                    cout<<" PUNTOS!---------------"<<endl;
                    rlutil::locate(25,4);
                    cout<<"---------------------------------------------------"<<endl;
                    rlutil::anykey();
                }

                else if(Total>Total2)
                {
                    cout<<endl;
                    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
                    rlutil::locate(25,3);
                    cout<<"Felicidades "<<nom1;
                    cout<<" has ganado la partida con: "<<Total;
                    cout<<" de puntos!!!"<<endl;
                    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
                    rlutil::locate(45,5);
                    cout<<"GRACIAS POR JUGAR"<<endl;
                    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<endl;
                    rlutil::anykey();
                    rondas=rondas;
                }
                else
                {
                    cout<<endl;
                    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
                    rlutil::locate(25,3);
                    cout<<"Felicidades "<<nom2;
                    cout<<" has ganado la partida con: "<<Total2;
                    cout<<" de puntos!!!"<<endl;
                    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
                    rlutil::locate(45,5);
                    cout<<"GRACIAS POR JUGAR"<<endl;
                    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<endl;
                    rlutil::anykey();
                    rondas=rondas;
                }

                rlutil::cls();
                break;

            case 2: //CREDITOS----------------------
                rlutil::cls();
                rlutil::locate(42,5);
                cout<<"ALVAREZ ALEJO"<<endl;
                rlutil::locate(40,7);
                cout<<"BAUTISTA DE FAVERI"<<endl;
                rlutil::locate(48,9);
                cout<<":)";

                rlutil::anykey();
                rlutil::cls();
                break;


            case 3: //SALIR-------------------------
                rlutil::cls();

                cout<<"adios basura, no vuelvas...    :'("<<endl;

                return 1;

                rlutil::cls();
                break;


            }
        }
    }
}
