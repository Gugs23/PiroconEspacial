#include "ObjParser.hpp"

ObjParser::ObjParser(string &objFile){

    fstream file(objFile.c_str());

    if(file.fail()){
        cout << "Erro leitura arquivo" << endl;
        throw 1;
    }

    string input;

    double x, y, z;

    int a, b, c;

    char aux;

    while(file >> input){
        if(input == "v"){
            file >> x >> y >> z;

            vertices.push_back(nUpla(x, y, z));
        } else if (input == "vn"){
            file >> x >> y >> z;

            normais.push_back(nUpla(x, y, z));
        } else if (input == "vt"){
            file >> x >> y;

            texts.push_back(nUpla(x, y));
        } else if (input == "f"){
            while(aux = file.get()){
                if(aux == ' '){
                    continue;
                }
                if(aux >= '0' and aux <= '9'){
                    file.unget();
                    file >> input;
                    int match = sscanf(input.c_str(), "%d/%d/%d", &a, &b, &c);
                    if(match == 3){
                        vIndex.push_back(a);
                        tIndex.push_back(b);
                        nIndex.push_back(c);
                    } else {
                        sscanf(input.c_str(), "%d//%d", &a, &c);
                        vIndex.push_back(a);
                        nIndex.push_back(c);
                    }
                } else {
                    file.unget();
                    Face3D nova;
                    for(int i = 0; i < vIndex.size(); i++){
                        nova.pushVertex(vertices[vIndex[i] - 1]);
                    }
                    for(int i = 0; i < nIndex.size(); i++){
                        nova.pushNormal(normais[nIndex[i] - 1]);
                    }
                    for(int i = 0; i < tIndex.size(); i++){
                        nova.pushTexture(texts[tIndex[i] - 1]);
                    }
                    vIndex.clear();
                    nIndex.clear();
                    tIndex.clear();
                    object.push_back(nova);
                    break;
                }
            }
        }
    }

    vertices.clear();
    normais.clear();
    texts.clear();
    vIndex.clear();
    nIndex.clear();
    tIndex.clear();
    file.close();
}

vector<Face3D> ObjParser::getObject(){
    return object;
}

double ObjParser::strtod(string s){
    stringstream ss;
    double aux;
    ss << s;
    ss >> aux;
    return aux;
}

int ObjParser::strtoi(string s){
    stringstream ss;
    int aux;
    ss << s;
    ss >> aux;
    return aux;
}