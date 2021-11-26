CC = g++
CFLAGS = -I./include
VPATH = src
OBJ = sum_of_subset.o backtrack.o

run: sum_of_subset
	@echo "NOW RUNNING..."
	@rm -rf *.o
	@./sum_of_subset
sum_of_subset: $(OBJ)
	$(CC) -o $@ $^
%.o:%.cpp
	$(CC) -c $< $(CFLAGS)

.PHONY : clean
clean:
	@rm -rf *.o sum_of_subset