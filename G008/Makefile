CC = g++
VPATH = src

run: bb-subsetsum bt-subsetsum dp-subsetsum
	@echo "NOW RUNNING..."
	@rm -rf *.o
	@./dp-subsetsum
	@./bt-subsetsum
	@./bb-subsetsum
dp-subsetsum: dp-subsetsum.o
	$(CC) -o $@ dp-subsetsum.o
bt-subsetsum: bt-subsetsum.o
	$(CC) -o $@ bt-subsetsum.o
bb-subsetsum: bb-subsetsum.o
	$(CC) -o $@ bb-subsetsum.o
%.o:%.cpp
	$(CC) -c $<

.PHONY : clean
clean:
	@rm -rf *.o bt-subsetsum bb-subsetsum