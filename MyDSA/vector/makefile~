# https://blog.csdn.net/qq_41748900/article/details/82316662
# out:main.o test.o
# 	g++ main.o test.o -o out
# main.o:main.cpp
# 	g++ -c main.cpp
# test.o:test.cpp
# 	g++ -c test.cpp
# .PHONY clean:
# 	rm -f *.o

# https://blog.csdn.net/zhaocuit/article/details/74782789
CC=g++
SRCS=main.cpp \
	test.cpp
OBJS=$(SRCS:.cpp=.o)
EXE=out

start:$(OBJS)
	$(CC) -o $(EXE) $(OBJS)

.cpp.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)
