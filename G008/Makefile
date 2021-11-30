CC = g++
VPATH = src
OBJ = bt-subsetsum.o

run: bt-subsetsum
	@echo "NOW RUNNING..."
	@rm -rf *.o
	@./bt-subsetsum
bt-subsetsum: $(OBJ)
	$(CC) -o $@ $^
%.o:%.cpp
	$(CC) -c $<

.PHONY : clean
clean:
	@rm -rf *.o bt-subsetsum