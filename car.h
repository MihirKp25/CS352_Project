#ifndef CAR_H
#define CAR_H

#include <GL/glut.h>

class CAR
{
   public:
   
    

    void WireFrame();
    void Paint();
    void Lights();
    void Wheels(float aw);
    void Tyre();
    void Cylinder();
    void CarSymbol();
    void ExhaustCylinder();
    void ExhaustPipes();

   void DrawCar(float a,float b,float c,float A,float Aw);

};

#endif

