#ifndef FACE3D_H
#define FACE3D_H

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

#include "nUpla.hpp"


class Face3D{
    public:
        Face3D();
        
        void pushVertex(nUpla);

        void pushTexture(nUpla);

        void pushNormal(nUpla);

        bool nextVertex(nUpla &);
        
        bool nextNormal(nUpla &);
        
        bool nextTexture(nUpla &);

        void print();

        int size();

    private:

        int v_index, n_index, t_index;

        vector<nUpla> v;

        vector<nUpla> vn;

        vector<nUpla> vt;
    
};
#endif