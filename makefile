CC = g++
FLAGS = -std=c++11
COMPILE_FLAGS = $(FLAGS) -c

main: main.o Library.o person.o document.o student.o professor.o book.o refrence.o magazine.o
	$(CC) main.o Library.o person.o document.o student.o professor.o book.o refrence.o magazine.o $(FLAGS) -o main

main.o: main.cpp Library.hpp student.hpp professor.hpp person.hpp book.hpp refrence.hpp magazine.hpp document.hpp
	$(CC) $(COMPILE_FLAGS) main.cpp

Library.o: Library.hpp Library.cpp student.hpp professor.hpp person.hpp book.hpp refrence.hpp magazine.hpp document.hpp
	$(CC) $(COMPILE_FLAGS) Library.cpp

student.o: student.hpp student.cpp person.hpp book.hpp refrence.hpp magazine.hpp document.hpp
	$(CC) $(COMPILE_FLAGS) student.cpp

professor.o: professor.hpp professor.cpp person.hpp book.hpp refrence.hpp magazine.hpp document.hpp
	$(CC) $(COMPILE_FLAGS) professor.cpp

book.o: book.hpp book.cpp document.hpp
	$(CC) $(COMPILE_FLAGS) book.cpp

refrence.o: refrence.hpp refrence.cpp document.hpp
	$(CC) $(COMPILE_FLAGS) refrence.cpp

magazine.o: magazine.hpp magazine.cpp document.hpp
	$(CC) $(COMPILE_FLAGS) magazine.cpp

person.o: person.hpp person.cpp book.hpp refrence.hpp magazine.hpp document.hpp
	$(CC) $(COMPILE_FLAGS) person.cpp

document.o: document.hpp document.cpp
	$(CC) $(COMPILE_FLAGS) document.cpp


.PHONY: clean

clean:
	rm *.o