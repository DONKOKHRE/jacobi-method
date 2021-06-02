#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define tolerancia 0.000001   //tolerancia 
using namespace std;
//Declaracion de variables
int i;
float x =0, y =0, a =0, b =0,c =0, d =0, anteriorMax = 0,maxFinal, error, x1 =0, x2=0, x3=0;

//Funciones 
void ImprimirCabeza(){
		cout<<"i"<<"\t"<<"X1"<<"\t"<<"X2"<<"\t"<<"X3"<<"\t"<<"Maximo"<<"\t"<<"Error"<<endl;
}

// funciones que tienen ecuaciones mostradas en la clase
 float funcionX(float x, float y){
 	return (-x-(2 * y)+9)/4;
 }
 float funcionA(float a, float b){
 	return (-(2*a)+b-5)/4;
 }
 float funcionC(float c, float d){
 	return (-c-d-9)/-3;
 }
 
 //funcion principal del metodo
 void MetodoJacobi(){
 
 do{
 	    //Llamada a las funciones para poder tener un valor en x1, x2, x3
 		x1 = funcionX(x, y);
 		x2 = funcionA(a, b);
 		x3 = funcionC(c,d);
 		
 	    //Llama a el metodo max, compara los 3x y escoge el numero mayor para que sea el MaxFinal
        maxFinal = max({x1, x2, x3});
        //operacion vista en clase, el abs es un valor absoluto
 		error = abs( (maxFinal - anteriorMax)/ maxFinal);	
		 //variable auxilia que toma el valor de maxFinal	
 		anteriorMax = maxFinal;
 		
 		//Manda a imprimir las varibles
 		cout<<setprecision(0)<<i<<"\t"<<fixed<<setprecision(4)<<x1<<"\t"<<x2<<"\t"<<x3<<"\t"<<" "<<maxFinal<<""<<"\t"<<"   "<<error<<endl;
 		
		 //igualaciones para que sea posible interacturar con las funciones
		 x = x2, y = x3; 
 		a = x1, b =x3;
 		c = x1, d = x2;
 		
 		i++;
 	
 } while(error > tolerancia); //condicion con la cual terminara el programa
}
 
 
 
 int main(){
 	cout<<"Metodo de Jacobi"<<endl;
 	cout<<endl;
 	ImprimirCabeza(); //Llama a la funcion 
 	MetodoJacobi(); //Llama a la funcion 
 	
 	system("pause");
 		
 }
