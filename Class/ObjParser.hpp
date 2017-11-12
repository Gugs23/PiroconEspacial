#ifndef OBJPARSER_H
#define OBJPARSER_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
using std::pair;
using std::stringstream;
using std::fstream;
using std::string;
using std::vector;

#include "Face3D.hpp"

class ObjParser{
    public:
        ObjParser(string &);

        vector<Face3D> getObject();

    private:
        double strtod(string);

        int strtoi(string);

        vector<nUpla> vertices, normais, texts;

        vector<int> vIndex, nIndex, tIndex;

        vector<Face3D> object;
};

#endif