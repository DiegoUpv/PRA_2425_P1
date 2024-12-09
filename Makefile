bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h List.h Node.h

Circle.o: Circle.cpp Circle.h
	g++ -c Circle.cpp


Square.o: Square.cpp Square.h
	g++ -c Square.cpp

Drawing.o: Drawing.cpp Drawing.h
	g++ -c Drawing.cpp


	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

clean:
	rm -r *.o *.gch bin
