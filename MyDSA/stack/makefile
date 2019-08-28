CC=clang++
SRCS=test.cpp
OBJS=$(SRCS:.cpp=.o)
EXE=out

start:$(OBJS)
	$(CC) -std=c++11 -o $(EXE) $(OBJS)

.cpp.o:
	$(CC) -std=c++11 -o $@ -c $<

clean:
	rm -f $(OBJS)
