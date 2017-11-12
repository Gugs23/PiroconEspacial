#include "Camera.hpp"

Camera::Camera(Object * &s){
    setObject(s);
    camType = 3;
    position = s->getCamPos(camType);
}

void Camera::setObject(Object *&s){
    ship = s;
}

double Camera::getX(){
    return position.x;
}

double Camera::getY(){
    return position.y;
}

double Camera::getZ(){
    return position.z;
}

void Camera::attVision(){
    position = ship->getCamPos(camType);
    double n = ship->getNorm();
    double dx = ship->getVX();
    double dy = ship->getVY();
    double dz = ship->getVZ();
    double f = ship->getFactor();

    dx /= n;
    dy /= n;
    dz /= n;

    vision = position;

    if(camType == 1){
        vision.x += dx * FACTOR;
        vision.y += dy * FACTOR;
        vision.z += dz * FACTOR;
    } else {
        vision.x = ship->getX() + dx * f;
        vision.y = ship->getY() + dy * f;
        vision.z = ship->getZ() + dz * f;
    }
    cout << "Nave pos " << ship->getX() << " " << ship->getY() << " " << ship->getZ() << endl;
    cout << "Cam pos " << position.x << " " << position.y << " " << position.z << endl;
    cout << "Look at " << vision.x << " " << vision.y << " " << vision.z << endl;

}

double Camera::viewX(){
    return vision.x;
}

double Camera::viewY(){
    return vision.y;
}

double Camera::viewZ(){
    return vision.z;
}

void Camera::_switch(){
    if(camType == 1){
        camType = 3;
    } else {
        camType = 1;
    }
}
