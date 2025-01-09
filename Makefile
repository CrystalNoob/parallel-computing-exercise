CC = clang
CFLAGS = -fopenmp -O

run: all
	./a.exe
all: build
build:
	@$(CC) $(CFLAGS) pi_crit.c
clean:
	rm *.exe
