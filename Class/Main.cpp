#include <iostream>
#include <vector>
#include "ObjParser.hpp"
#include "Face3D.hpp"
#include "nUpla.hpp"

using namespace std;

int main(){
    string inn;
    cin >> inn;

    ObjParser o(inn);
    vector<Face3D> oo = o.getObject();
/* 
    for(int i = 0; i < oo.size(); i++){
        oo[i].print();
    } */

    cout << "Sucesso" << endl;
    return 0;

}