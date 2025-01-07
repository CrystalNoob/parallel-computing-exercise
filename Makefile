CC = clang
CFLAGS = -fopenmp -O

run: all
	./a.exe
all: build
build:
	@$(CC) $(CFLAGS) pi.c
clean:
	rm *.exe
