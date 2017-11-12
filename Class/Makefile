DEPN = ObjParser.o Face3D.o nUpla.o Object.o Camera.o
OPT = -g
GLUT = -lglut -lGL -lGLU

Compile: Exib

Exib: Exib.cpp $(DEPN)
	$(CXX) $(OPT) -o Exib Exib.cpp $(DEPN) $(GLUT)

%.o: %.cpp %.hpp
	$(CXX) $(OPT) -c $<

clear:
	rm *.o Main