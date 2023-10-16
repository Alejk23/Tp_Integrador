#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>

//SOLO UTILIZAR "[]" CUANDDO ARMAMOS LA FUNCIÓN, NO PARA INVOCARLA EN EL MAIN.

void cargarVectorAleatorio(int vec[], int tam);
void ordenarVector(int v[], int tam);
void mostrarVector(int vec[],int tam);
int maximoVector(int v[], int tam);
int puntostirada(int vec[],int tam);
int Combinaciones(int vec[],int tam);

void cargarVectorAleatorio(int vec[], int tam) {
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        vec[i] = rand() % 6+1;


}
}

void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

void mostrarVector(int vec[],int tam){
       cout << "Lanzando dados..." <<endl;
   cout<<endl; cout<<"Los dados cayeron con los siguientes valores o caras:"<<endl;
cout<<endl; for(int i=0;i<tam;i++){
cout<<vec[i]<<endl;
}
}

int maximoVector(int v[], int tam){
    int vecAux[tam];
    int h,j,i,q,pos,cont,maxx,maxx2;
    int mpos;

   for(h=0;h<tam;h++){
        vecAux[h]=0;
    }


    for(j=0;j<tam;j++){

        for(i=0;i<tam;i++){
            if(v[j]==i+1){vecAux[i]=vecAux[i]+1;}
        }
    }

    pos=0;
    for(q=0;q<tam;q++){
            pos++;
        if(q==0){maxx=vecAux[q];mpos=pos;}else if(vecAux[q]>maxx){maxx=vecAux[q];mpos=pos;}
    }
    cont=0;
    if(v[0]==v[1]&&v[1]==v[2]){cont++;if(v[3]==v[4]&&v[4]==v[5]){cont++;}}
    if(cont==2){maxx2=v[0];if(v[3]>maxx2){maxx2=v[3];}mpos=maxx2;}


  return mpos;
    }

int puntostirada(int vec[],int tam){

    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=vec[i];
    }
return suma;
}

int Combinaciones(int vec[],int tam){
    int cont=0;
    if (vec[0]==vec[1]&&vec[1]==vec[2]){
        cont++;
    }
    if (vec[1]==vec[2]&&vec[2]==vec[3]){
        cont++;
    }
    if (vec[2]==vec[3]&&vec[3]==vec[4]){
        cont++;
    }
    if (vec[3]==vec[4]&&vec[4]==vec[5]){
        cont++;
    }
  int ptosLanzamiento=0, Total=0;
  switch(cont){
    case 0:
      if (vec[0]==1&&vec[1]==2&&vec[2]==3&&vec[3]==4&&vec[4]==5&&vec[5]==6){
     cout<<endl; cout<<"Escalera.";
     return Total=500;
      }
      else{cout<<endl; cout<<"COMBINACION: Suma de dados."<<endl;;
     ptosLanzamiento=puntostirada(vec, tam);
     cout<<endl; cout<<"----------------------------------------------------------"<<endl;
     cout<<"Los puntos obtenidos en este lanzamiento son: "<<ptosLanzamiento<<endl;
     Total=Total+ptosLanzamiento;
     return Total;
      }
        break;
    case 1:
       cout<<endl; cout<<"COMBINACION: Trio de: "<<maximoVector(vec, tam)<<endl;
       ptosLanzamiento=maximoVector(vec, tam)*10;
       cout<<endl; cout<<"----------------------------------------------------------"<<endl;
        cout<<"Los puntos obtenidos en este lanzamiento son: "<<ptosLanzamiento<<endl;
      Total=Total+ptosLanzamiento;
       return Total;
        break;
    case 2:
       cout<<endl; cout<<"COMBINACION: Cuarteto de: "<<maximoVector(vec, tam)<<endl;
       ptosLanzamiento=maximoVector(vec, tam)*10;
       cout<<endl; cout<<"----------------------------------------------------------"<<endl;
       cout<<"Los puntos obtenidos en este lanzamiento son: "<<ptosLanzamiento<<endl;
       Total=Total+ptosLanzamiento;
       return Total;
        break;
    case 3:
      cout<<endl;  cout<<"COMBINACION: Quinteto de: "<<maximoVector(vec, tam)<<endl;
       ptosLanzamiento=maximoVector(vec, tam)*10;
       cout<<endl; cout<<"----------------------------------------------------------"<<endl;
        cout<<"Los puntos obtenidos en este lanzamiento son: "<<ptosLanzamiento<<endl;
       Total=Total+ptosLanzamiento;
       return Total;
        break;
    case 4:
        if(vec[0]==6){
    cout<<endl; cout<<"----------------------------------------------------------"<<endl;
    cout<<endl; cout<<"COMBINACION: Seis 6, pierdes todos los puntos."<<endl;
    Total=Total*0;
    return Total;}

    else{cout<<endl;  cout<<"COMBINACION: Sexteto de: "<<maximoVector(vec, tam)<<endl;
    ptosLanzamiento=maximoVector(vec, tam)*50;
    cout<<endl; cout<<"----------------------------------------------------------"<<endl;
    cout<<"Los puntos obtenidos en este lanzamiento son: "<<ptosLanzamiento<<endl;
    Total=Total+ptosLanzamiento;
    return Total;}

        break;
    default:
        break;
        }
}
#endif // FUNCIONES_H_INCLUDED
