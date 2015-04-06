all:
	g++ -c Point.hpp Point.cpp
	g++ -c Line.hpp Line.cpp
	g++ -c Polygon.hpp Polygon.cpp
	g++ -c Circle.hpp Circle.cpp
	g++ -c FrameBuffer.cpp
	g++ -o gg FrameBuffer.o Point.o Line.o Polygon.o Circle.o mainthick.cpp

main:
	g++ -o gg Point.o Line.o Polygon.o Circle.o mainthick.cpp

run:
	./gg

clean:
	rm *.o
	rm *.gch
	rm gg
