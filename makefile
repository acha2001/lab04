runProgram: main.o heapSort.o
	g++ main.o heapSort.o

main.o: main.cpp 
	g++ -c main.cpp

heapSort.o: heapSort.cpp
	g++ -c heapSort.cpp

clean: 
	rm main.o heapSort.o a.out
