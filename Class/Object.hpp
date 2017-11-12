#ifndef OBJECT_H
#define OBJECT_H

#include <GL/gl.h>
#include <GL/glut.h>

#include <cmath>
#include <vector>
#include <string>
using std::string;
using std::vector;
#include "Face3D.hpp"
#include "ObjParser.hpp"

class Object{
    public:
        Object(string &s, double = 0, double = 0, double = 0, double = 1, double = 0, double = 0, double = 1);

        void setX(double);

        double getX();

        void setY(double);

        double getY();

        void setZ(double);

        double getZ();

        double getVX();

        double getVY();

        double getVZ();

        void rotation(double, double, double);

        void setSpeed(double);

        double getSpeed();

        void draw();

        double calcAngle();

        double getNorm();

        nUpla getCamPos(int);

        void setCamPos(nUpla, nUpla);

        double getFactor();

        void setFactor(double);

    private:

        double factor;

        nUpla cam1, cam2;

        static ObjParser * parser;

        vector<Face3D> vertex;

        double x, y, z;

        double vx, vy, vz;

        double speed;

        void move();
};

#endif