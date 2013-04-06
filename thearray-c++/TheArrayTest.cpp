#include "TheArray.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class TheArrayTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    TheArray solution;

    void testCase0() {
		int n = 3;
		int d = 5;
		int first = 2;
		int last = 4;
		int expected_ = 7;
        assertEquals(0, expected_, solution.find(n, d, first, last));
    }

    void testCase1() {
		int n = 10;
		int d = 100;
		int first = 999;
		int last = 100;
		int expected_ = 999;
        assertEquals(1, expected_, solution.find(n, d, first, last));
    }

    void testCase2() {
		int n = 1000000;
		int d = 0;
		int first = 474;
		int last = 474;
		int expected_ = 474;
        assertEquals(2, expected_, solution.find(n, d, first, last));
    }

    void testCase3() {
		int n = 97;
		int d = 53;
		int first = -92;
		int last = 441;
		int expected_ = 2717;
        assertEquals(3, expected_, solution.find(n, d, first, last));
    }

    void testCase4() {
		int n = 99;
		int d = 3;
		int first = -743;
		int last = -619;
		int expected_ = -535;
        assertEquals(4, expected_, solution.find(n, d, first, last));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 5; i++) {
        TheArrayTest test;
        test.runTest(i);
    }
}
