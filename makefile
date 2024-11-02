main: matrix.cpp
	g++ -std=c++11 matrix.cpp -o matrix
clean:
	rm -f *.o matrix