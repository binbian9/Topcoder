
CXX		= g++
CXXFLAGS	= -O0 -ggdb -Wall

all: driver

run: all
	./driver

test: all
	./driver -exit_on_fail

driver.o: SymmetricPie.o

driver: driver.o
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f SymmetricPie.o driver.o driver

distclean: clean
	rm -f SymmetricPie

.PHONY: all run test clean distclean

