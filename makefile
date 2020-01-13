project2: main.o zoo.o limitedInputValidation.o animal.o continue.o penguin.o tiger.o turtle.o
	g++ main.o zoo.o limitedInputValidation.o animal.o continue.o penguin.o tiger.o turtle.o -o project2

main.o: main.cpp
	g++ -c main.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -c zoo.cpp

limitedInputValidation.o: limitedInputValidation.cpp limitedInputValidation.hpp
	g++ -c limitedInputValidation.cpp

animal.o: animal.cpp animal.hpp
	g++ -c animal.cpp

continue.o: continue.cpp continue.hpp
	g++ -c continue.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -c penguin.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -c tiger.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -c turtle.cpp

clean:
	rm *.o project2
