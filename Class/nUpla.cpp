#include "nUpla.hpp"

nUpla::nUpla(double a, double b, double c, double d) : x(a), y(b), z(c), w(d){
    
}

void nUpla::print(){
    cout << "[" << x << " " << y << " " << z << " " << w << "]" << endl;
}

nUpla nUpla::operator + (nUpla outro){
    nUpla ret(x + outro.x, y + outro.y, z + outro.z);
    return ret;
}

nUpla nUpla::operator - (nUpla outro){
    nUpla ret(x - outro.x, y - outro.y, z - outro.z);
    return ret;
}