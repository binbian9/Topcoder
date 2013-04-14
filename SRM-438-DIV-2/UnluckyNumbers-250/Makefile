
CXX		= g++
CXXFLAGS	= -O0 -ggdb -Wall

all: driver

run: all
	./driver

test: all
	./driver -exit_on_fail

driver.o: UnluckyNumbers.o

driver: driver.o
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f UnluckyNumbers.o driver.o driver

distclean: clean
	rm -f UnluckyNumbers

.PHONY: all run test clean distclean

