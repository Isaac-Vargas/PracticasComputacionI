#pragma once
#include <iostream>
#include <stdlib.h>
#ifndef PUNTO_2D
#define PUNTO_2D 


class Punto2D {


public:

	void SetPosicion(double X, double Y); 
	void Trasladar(float temp1, float temp2);
	void Rotar(float temp1); 
	void Escalar(float temp1, float temp2); 
	float GetX() const; 
	float GetY() const; 
   
private:

	float x = 0;
	float y = 0;

};

#endif