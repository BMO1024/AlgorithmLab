CC = g++
VPATH = src

run: bb-subsetsum bt-subsetsum
	@echo "NOW RUNNING..."
	@rm -rf *.o
	@./bt-subsetsum
	@./bb-subsetsum
bt-subsetsum: bt-subsetsum.o
	$(CC) -o $@ bt-subsetsum.o
bb-subsetsum: bb-subsetsum.o
	$(CC) -o $@ bb-subsetsum.o
%.o:%.cpp
	$(CC) -c $<

.PHONY : clean
clean:
	@rm -rf *.o bt-subsetsum