#include <iostream>
using namespace std;

void IT(int tarjetas[],int pines[],int opc);//lo declaro primero porque lo utilizo en el subprograma ING y me da error si no lo declaro

int EX(int saldo){
    int S;
	cout<<"El saldo de su tarjeta es de: "<<saldo<<endl;
	cout<<"Cantidad de dinero a extraer: "<<endl;
	cin>>S;
	if(saldo>S){
		saldo-=S;
		cout<<"El saldo de su tarjeta ahora es de: "<<saldo<<endl;
    }
    else if(saldo<S){
		cout<<"OPERACION DENEGADA"<<endl;
		cout<<"Su saldo es insuficiente";
	}
	return saldo;
}

int ING(int saldo,int tarjetas[],int pines[], int opc){
    int I;

        IT(tarjetas,pines,opc);
		cout<<"El saldo de su tarjeta es de: "<<saldo<<endl;
		cout<<"Cantidad de dinero a ingresar: "<<endl;
		cin>>I;
		saldo=saldo+I;
		cout<<"El saldo de su tarjeta ahora es de: "<<saldo<<endl;
		return saldo;

}


int main(){

    int tarjetas[]={(12345678),(87654321)};
	int pines[]={(1234),(4321)};
	int opc=-1,saldo=4000;

	cout<<"BIENVENIDO A SU CAJERO AUTOMATICO"<<endl;
	cout<<"\n";
    IT(tarjetas,pines,opc);

    while(opc!=0){
	    cout<<"Elija la operacion que desea realizar: "<<endl;
		cout<<"\n";
        cout<<"1. Consultar saldo."<<endl;
        cout<<"2. Extraer dinero de cuenta."<<endl;
        cout<<"3. Depositar dinero en cuenta."<<endl;
        cout<<"4. Dinero extraido anualmente."<<endl;
        cout<<"0. Para salir"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                cout<<"El saldo de su tarjeta es de: "<<saldo<<endl;break;

            case 2:
                saldo = EX(saldo);break;
            case 3:
                saldo = ING(saldo, tarjetas,pines, opc);break;
            case 4:
                Anno();break;

            case 0:
                cout<<"Gracias por preferirnos"<<endl;break;
        }
    }

    return 0;
}