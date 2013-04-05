
CXX		= g++
CXXFLAGS	= -O0 -ggdb -Wall

all: driver

run: all
	./driver

test: all
	./driver -exit_on_fail

driver.o: UnluckyIntervals.o

driver: driver.o
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f UnluckyIntervals.o driver.o driver

distclean: clean
	rm -f UnluckyIntervals

.PHONY: all run test clean distclean

