all: dir.o
	gcc -o dirtest dir.o

dir.o: dir.c
	gcc -c dir.c

run: dirtest
	./dirtest

clean:
	rm ./dirtest
	rm *~