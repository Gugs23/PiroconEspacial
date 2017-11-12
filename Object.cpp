#include "Object.hpp"

ObjParser * Object::parser;

Object::Object(string &s, double px, double py, double pz, double xx, double yy, double zz, double ss) : x(px), y(py), z(pz), vx(xx), vy(yy), vz(zz), speed(ss){
    parser = new ObjParser(s);
    vertex = parser->getObject();
    delete parser;
}

void Object::setX(double xx){
    x = xx;
}

double Object::getX(){
    return x;
}

void Object::setY(double yy){
    y = yy;
}

double Object::getY(){
    return y;
}

void Object::setZ(double zz){
    z = zz;
}

double Object::getZ(){
    return z;
}

double Object::getSpeed(){
    return speed;
}

void Object::rotation(double dx, double dy, double dz){
    vx += dx;
    vy += dy;
    vz += dz;
}

void Object::move(){
    double n = getNorm();
    vx /= n;
    vy /= n;
    vz /= n;

    x += (vx * speed);
    y += (vy * speed);
    z += (vz * speed);
}

double Object::getNorm(){
    return (sqrt(vx * vx + vy * vy + vz * vz));
}

void Object::setSpeed(double s){
    speed = s;
}

double Object::getVX(){
    return vx;
}

double Object::getVY(){
    return vy;
}

double Object::getVZ(){
    return vz;
}

nUpla Object::getCamPos(int type){
    if(type == 1){
        return cam1 + nUpla(x, y, z);
    } else {
        return cam2 + nUpla(x, y, z);
    }
}

void Object::setCamPos(nUpla c1, nUpla c2){
    cam1 = c1 - nUpla(x, y, z);
    cam2 = c2 - nUpla(x, y, z);
}

double Object::calcAngle(){
    return acos(vz / getNorm());
}

void Object::draw(){
    glColor3f(1, 0, 0.5);
    nUpla ponto;
    glRotatef(calcAngle(), x, y, z);
    for(int i = 0; i < vertex.size(); i++){
        glBegin(GL_POLYGON);
        while(vertex[i].nextVertex(ponto)){
            glVertex3f(x + ponto.x, y + ponto.y, z + ponto.z);
        }
        glEnd();
    }
    glRotatef(-calcAngle(), x, y, z);

    move();
}

double Object::getFactor(){
    return factor;
}

void Object::setFactor(double f){
    factor = f;
}