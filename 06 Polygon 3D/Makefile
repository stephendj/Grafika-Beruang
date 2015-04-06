all:
	g++ -c Point.hpp Point.cpp
	g++ -c Line.hpp Line.cpp
	g++ -c Polygon.hpp Polygon.cpp
	g++ -c FrameBuffer.cpp
	g++ -c Window.hpp Window.cpp
	g++ -c View.hpp View.cpp
	g++ -c Polygon3D.hpp Polygon3D.cpp
	g++ -o gg FrameBuffer.o Point.o Line.o Polygon.o Window.o View.o Polygon3D.o main2.cpp

thread:
	g++ -c Point.hpp Point.cpp
	g++ -c Line.hpp Line.cpp
	g++ -c Polygon.hpp Polygon.cpp
	g++ -c FrameBuffer.cpp
	g++ -c Window.hpp Window.cpp
	g++ -c View.hpp View.cpp
	g++ -o gg FrameBuffer.o Point.o Line.o Polygon.o Window.o View.o main.cpp -pthread

run:
	./gg

clean:
	rm *.o
	rm *.gch
	rm gg
