.PHONY:clean all
CC=g++
VPATH=src

fortest:sum_of_subset.o test.o
	$(CC) -o fortest sum_of_subset.o test.o
sum_of_subset.o:sum_of_subset.cpp
	$(CC) -c $(VPATH)/sum_of_subset.cpp
test.o:test.cpp
	$(CC) -c $(VPATH)/test.cpp

.PHONY : clean
clean:
	-rm *.o fortest