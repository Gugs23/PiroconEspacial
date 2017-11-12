#ifndef NUPLA_H
#define NUPLA_H

#include <iostream>
using std::cout;
using std::endl;

class nUpla{
    public:
        nUpla(double = 0, double = 0, double = 0, double = 0);

        void print();

        double x, y, z, w;

        nUpla operator + (nUpla );

        nUpla operator - (nUpla);
};

#endif