//CALCULADORA
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
int opcion;
float primer,segundo, resultado;
int x, y;

 printf("LA CALCULADORA MAS CHIPOCLUDA \n");

 printf("Venga el primer numero?");
	scanf("%f",&primer);


 printf("  1. Pushale aqui si quieres sumar  \n");
 printf("  2. Aqui si quieres restar  \n");
 printf("  3. Tal vez multiplicar  \n");
 printf("  4. Dividir?  \n");
 printf("  5. Nadie sabe que es un modulo pero si quieres averiguarlo picale aqui \n");
 
 printf("Elige que quieres hacer");
 scanf("%d",&opcion);
 
	printf("venga el segundo numero?");
	scanf("%f",&segundo);

if (opcion==1)
resultado= primer+segundo;

if (opcion==2)
resultado= primer-segundo;

if (opcion==3)
resultado= primer*segundo;

if (opcion==4)
resultado= primer/segundo;

if (opcion==5)
resultado= y % x;


printf("el resultado es = %f", resultado);
    return 0;
}
