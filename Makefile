CXX:= g++
CXXFLAGS:= -Wall -Wextra -pedantic  -std=c++17 -O0 -g
HEADERS := $(wildcard *.hh) $(wildcard *.h)

main: main.o parser.o
	$(CXX) $(CXXFLAGS) -o $@ $^

parser: parser.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test: main
	./main rle-0000.raw

%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f *.o					