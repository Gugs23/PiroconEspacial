#ifndef CAMERA_H
#define CAMERA_H

#include "Object.hpp"
#include "nUpla.hpp"

#define FACTOR 10
#define FACTOR2 7.5

class Camera{
    public:
        Camera(Object * &);

        void setObject(Object * &);

        double getX();

        double getY();

        double getZ();

        double viewX();

        double viewY();

        double viewZ();

        void attVision();

        void _switch();
    
    private:
        int camType;

        nUpla position;

        nUpla vision;

        Object * ship;
};

#endif