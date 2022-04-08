/********************************************************************************************************
    Descripcion:
        Creacion de un programa que realice el conteo de los caracteres (), [], {} y <> desde un
        archivo de texto.
    Autores:
        Hernandez Lopez Bryan
        Martinez Islas Armando Samir
    Fecha de creacion:
        05/04/2022
    Version: 1.0
********************************************************************************************************/

//Librerias
#include<bits/stdc++.h> //Libreria de cabecera.
using namespace std;

//Prototipos de las funciones.
void leer();
int comprobar(int,int);
void contador(string,int&,int&,int&,int&,int&,int&,int&,int&);
void mostrar(int,int,int,int,int,int,int,int);

//Funcion principal.
int main(){
    leer();
    return 0;
}

//Funcion de lectura del archivo .txt que contiene las cadenas de caracteres.
void leer(){
    ifstream archivo;
    string contenido;
    int p1=0,p2=0,c1=0,c2=0,ll1=0,ll2=0,t1=0,t2=0;  //Variables con las que almacenaremos la cantidad de caracteres.

    archivo.open("caracteres.txt",ios::in);  //Abrimos el archivo en lectura.
    if(archivo.fail()){
        cout<<"\t NO SE PUDO ABRIR EL ARCHIVO."<<endl;  //Mensaje en caso de no lograr encontrar o abrir el .txt
        exit(1);
    }
    cout<<"\n   -> Contenido del archivo de texto: "<<endl;
    while(!archivo.eof()){  //Recorremos el archivo hasta llegar al final.
        getline(archivo,contenido); //Copiamos el contenido del archivo .txt a una variable tipo string.
        cout<<"\t"<<contenido<<endl;    //Mostramos en pantalla el contenido del archivo .txt.
        contador(contenido,p1,p2,c1,c2,ll1,ll2,t1,t2);  //Recorremos la cadena y contamos los caracteres buscados.
    }
    archivo.close();    //Cerramos el archivo.
    mostrar(p1,p2,c1,c2,ll1,ll2,t1,t2); //Mostramos los resultaos obtenidos.
}

//Funcion que realiza el conteo de cada caracter
void contador(string a, int& p1, int& p2, int& c1, int& c2, int& ll1, int& ll2, int& t1, int& t2){
    for(int i=0;i<a.length();i++){  //Recorremos y contamos cada caracter.
        if(a[i]=='('){
            p1++;
        }else if(a[i]==')'){
            p2++;
        }else if(a[i]=='['){
            c1++;
        }else if(a[i]==']'){
            c2++;
        }else if(a[i]=='{'){
            ll1++;
        }else if(a[i]=='}'){
            ll2++;
        }else if(a[i]=='<'){
            t1++;
        }else if(a[i]=='>'){
            t2++;
        }
    }
}

//Funcion que muestra los resultados obtenidos por el programa
void mostrar(int p1, int p2, int c1, int c2, int ll1, int ll2, int t1, int t2){
    //Mostramos los resultados Individuales.
        cout<<"\n   -> Parentesis '(', hay "<<p1<<"."<<endl;
        cout<<"   -> Parentesis ')', hay "<<p2<<"."<<endl;
        cout<<"   -> Corchete '[', hay "<<c1<<"."<<endl;
        cout<<"   -> Corchete ']', hay "<<c2<<"."<<endl;
        cout<<"   -> Llave '{', hay "<<ll1<<"."<<endl;
        cout<<"   -> Llave '}', hay "<<ll2<<"."<<endl;
        cout<<"   -> Parentesis Trinagular '<', hay "<<t1<<"."<<endl;
        cout<<"   -> Parentesis Trinagular'>', hay "<<t2<<".\n"<<endl;

    //Mostramos los resultados por pares.
        cout<<"\n   -> Parentesis (), hay "<<comprobar(p1,p2)<<" pares."<<endl;
        cout<<"   -> Corchetes [], hay "<<comprobar(c1,c2)<<" pares."<<endl;
        cout<<"   -> Llaves {}, hay "<<comprobar(ll1,ll2)<<" pares."<<endl;
        cout<<"   -> Parentesis Trinagulares <>, hay "<<comprobar(t1,t2)<<" pares.\n"<<endl;
}

//Funcion que comprueba cuantos caracteres son pares.
int comprobar(int a, int b){
    if(a==b){
       //En caso de ser iguales regresa el primer valor.
       return a;  
    }else if(a<b){
        //En caso de que el primer caracater sea menor, no se cumple la cantidad par, por lo que retorna el valor menor.
        return a;   
    }else if(b<a){
        //En caso de que el segundo caracater sea menor, no se cumple la cantidad par, por lo que retorna el valor menor.
        return b; 
    }
    return 0;   //Fin de la funcion.
} 
