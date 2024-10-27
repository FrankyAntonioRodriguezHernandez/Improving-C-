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

void IT(int tarjetas[],int pines[],int opc){
    int tarjeta, PT=-1, pin;


    cout<<"Introduzca el numero de su tarjeta: "<<endl;
	cin>>tarjeta;
	for(int i=0;i<2; i++){
		if(tarjeta==tarjetas[i]){
		PT=i;
		}
	}
	if(PT<0){
		cout<<"Su tarjeta es incorrecta, introduzca su numero de tarjeta"<<endl;
		IT(tarjetas,pines,opc);
	}
		cout<<"\n";
	cout<<"Introduzca el pin de su tarjeta: ";cin>>pin;

	if(pin!=pines[PT]){
		for(int j=6; j>0; j--){

		cout<<"Su pin es incorrecto, introduzca su pin de nuevo(tiene "<<j<<" intentos mas): "<<endl;
		cin>>pin;
			if(pin==pines[PT]){
				break;
			}
		}
		cout<<"Su tarjeta ha sido bloqueada"<<endl;
            opc=0;
	}

}

void Anno(){
    int opcion, total=0;
    int a2020[12], a2021[12], a2022[12];
    int a=3000;

    for(int i=0;i<12;i++){
        a2020[i]= a;
        a+=500;
        a2021[i]= a;
        a+=500;
        a2022[i]= a;
        a+=500;
    }

    cout<<"Seleccione el a�o deseado para saber la cantidad de dinero substraido"<<endl;

    cout<<"1 para 2020"<<endl;
    cout<<"2 para 2021"<<endl;
    cout<<"3 para 2022"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1:
            for(int i=0;i<12;i++){
                total+=a2020[i];
            };break;
        case 2:
            for(int i=0;i<12;i++){
                total+=a2021[i];
            };break;
        case 3:
            for(int i=0;i<12;i++){
                total+=a2022[i];
            };break;
    }

    cout<<"La cantidad de dinero extraida ese a�o es: "<<total<<endl;

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