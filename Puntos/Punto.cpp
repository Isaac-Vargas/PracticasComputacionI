#include<cmath>
#include <iostream>
#include "Punto.h"
#define pi 3.1416 

using namespace std;


void Punto2D::SetPosicion(double X, double Y) {
    x = X;
    y = Y;
}

void Punto2D::Trasladar(float temp1, float temp2) {
    x = x + (temp1);
    y = y + (temp2);

}

void Punto2D::Rotar(float temp1) {
    temp1 = temp1 * pi / 180;
    float x2 = x;
    x = (x * cos(temp1)) - (y * sin(temp1));
    y = (y * cos(temp1)) + (x2 * sin(temp1));

}

void Punto2D::Escalar(float temp1, float temp2) {
    x = x * temp1;
    y = y * temp2;

}

float Punto2D::GetX() const {
    return x;
}
float Punto2D::GetY() const {
    return y;
}