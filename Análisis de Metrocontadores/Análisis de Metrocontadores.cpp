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

    //Llenar el arreglo
    for(int i=0;i<cantClientes;i++){
        for(int j=0;j<dias;j++){
            cout << "Digite el consumo del cliente: "<<i+1<<" en el dia: "<<j+1<< endl;
            cin>>arreglo[i][j];
        }
    }

    cout<<"\n"<<endl;
    //muestro el arreglo
    for(int i=0;i<cantClientes;i++){
        for(int j=0;j<dias;j++){
            cout<<arreglo[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    while(opcion!=0){
        cout<<"Digite la opcion deseada: "<<endl;
        cout<<" \n"<<endl;
        cout<<"1 Para saber el Total de kWh en el mes"<<endl;
        cout<<"2 para saber la cantidad de lecturas que sobrepasen los 100kWh y el porciento que representa "<<endl;
        cout<<"3 Para saber el Total de kWh en el mes"<<endl;
        cout<<"4 Para saber el dia de mayor consumo"<<endl;
        cout<<"5 Para saber el cliente de menor consumo"<<endl;
        cout<<"0 para salir"<<endl;
        cin>>opcion;
        switch(opcion){

            case 1:TotalkWh(arreglo,cantClientes,dias);break;

            case 2:Sobrepasan100kWh(arreglo,cantClientes,dias);break;

            case 3:pagototal= TotaldineroAPagar(arreglo,cantClientes,dias);
                cout<<"EL dinero total a pagar de todas las lecturas es de: "<<pagototal<<endl;
                break;

            case 4:DiaMayorConsumo(arreglo,cantClientes,dias);break;

            case 5:ClienteMenorConsumo(arreglo,cantClientes,dias);break;
        }
    }
    
    return 0;
}