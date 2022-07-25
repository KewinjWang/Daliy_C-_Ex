test:date.o test.o
	g++ $^ -o $@ 
date.o:date.cpp
	g++ -c $< -o $@
test.o:test.cpp
	g++  -c $< -o $@
.PHONY:clean
clean:
	rm -f test *.o
