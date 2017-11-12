#include "Face3D.hpp"

Face3D::Face3D(){
    v_index = 0;
    n_index = 0;
    t_index = 0;
}
        
void Face3D::pushVertex(nUpla vertex){
    v.push_back(vertex);
}

void Face3D::pushTexture(nUpla text){
    vt.push_back(text);
}

void Face3D::pushNormal(nUpla norm){
    vn.push_back(norm);
}

bool Face3D::nextVertex(nUpla &vertex){
    vertex = v[v_index];
    v_index++;
    if(v_index <= v.size()){
        return true;
    } else {
        v_index = 0;
        return false;
    }
}

bool Face3D::nextNormal(nUpla &vertex){
    vertex = vn[n_index];
    n_index++;
    if(n_index <= vn.size()){
        return true;
    } else {
        n_index = 0;
        return false;
    }
}

bool Face3D::nextTexture(nUpla &vertex){
    vertex = vt[t_index];
    t_index++;
    if(t_index <= vt.size()){
        return true;
    } else {
        t_index = 0;
        return false;
    }
}

void Face3D::print(){
    cout << "Print Face" << endl;
    int cont = 0;
    nUpla v, n, t;
    while(nextVertex(v) && nextNormal(n) && nextTexture(t)){
        cout << "----------------vert " << cont++ << endl;
        v.print();
        n.print();
        t.print();
        cout << "------------------------------------" << endl;
    }
}

int Face3D::size(){
    return v.size();
}