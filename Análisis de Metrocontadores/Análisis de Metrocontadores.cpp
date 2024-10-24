#include <iostream>

using namespace std;

void TotalkWh(float arreglo[][30],int cantClientes, int dias);
void Sobrepasan100kWh(float arreglo[][30],int cantClientes, int dias);
float TotaldineroAPagar(float arreglo[][30],int cantClientes, int dias);
void DiaMayorConsumo(float arreglo[][30],int cantClientes, int dias);
void ClienteMenorConsumo(float arreglo[][30],int cantClientes, int dias);

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

void TotalkWh(float arreglo[][30],int cantClientes, int dias){
    float total=0.0;

    for(int i=0;i<cantClientes;i++){
        for(int j=0;j<dias;j++){
            total+=arreglo[i][j];
        }
    }

    cout<<"La cantidad total de kWh en el mes es de: "<<total<<endl;
}

void Sobrepasan100kWh(float arreglo[][30],int cantClientes, int dias){
    int total=0;
    int contador=0;

    for(int i=0;i<cantClientes;i++){
        for(int j=0;j<dias;j++){
            total++;
            if(arreglo[i][j]>100){
                contador++;
            }
        }
    }

    cout<<"La cantidad de lecturas que sobrepasan los 100kWh es de: "<<contador<<endl;
    cout<<"y representa el "<<(contador*100)/total<<" %"<<endl;
}

float TotaldineroAPagar(float arreglo[][30],int cantClientes, int dias){
    float total=0.0;
    float pagototal=0.0;
    float aux =0.0;

    for(int i=0;i<cantClientes;i++){

        for(int j=0;j<dias;j++){
            total+=arreglo[i][j];

            if(total<=100){
                aux= total*0.09;
                pagototal+=aux;
            }
            else if(total>100 && total<=300){
                aux=(total-100)*0.2 +9;
                pagototal+=aux;
            }
            else if(total>300){
                aux=(total-300)*0.3 +49;
                pagototal+=aux;
            }

            total=0.0;
            aux =0.0;
        }
    }
    return pagototal;
}