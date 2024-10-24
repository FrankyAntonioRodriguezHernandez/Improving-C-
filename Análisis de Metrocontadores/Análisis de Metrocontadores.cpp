#include <iostream>

using namespace std;


int main()
{
    int cantClientes, dias=30;
    float pagototal=0.0;
    //creo la variable opcion en -1 para evitar errores
    int opcion=-1;

    cout<<"Bienvenido al programa de analisis de Metrocontadores"<<endl;
    cout<<"\n"<<endl;

    cout<<"Digite la cantidad de Clientes"<<endl;
    cin>>cantClientes;
    cout<<"\n"<<endl;

    //creo el arreglo
    float arreglo[cantClientes][30];

    //aqui hago que todas las posiciones del arreglo sean 0
    for(int i=0;i<cantClientes;i++){
        for(int j=0;j<dias;j++){
            arreglo[i][j]=0;
        }
    }


    
    return 0;
}