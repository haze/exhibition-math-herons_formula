COMPILER?=clang++
SRCS=$(wildcard src/*.cpp)
HDRS=$(wildcard src/*.hpp)
OBJS=$(patsubst %.c,%.o,$(SRC))

comp:
		clang++ -std=c++14 -stdlib=libc++ -O2 -o herons-formula $(SRCS)

run:
		./herons-formula

clean:
		rm herons-formula


