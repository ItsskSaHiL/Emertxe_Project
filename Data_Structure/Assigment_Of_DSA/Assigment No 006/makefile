OBJ:=$(patsubst %.o,%.c,$(wildcard *.c))
node.exe: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.exe *.o
