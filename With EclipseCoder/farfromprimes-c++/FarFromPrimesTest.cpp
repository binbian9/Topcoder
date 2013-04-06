#include "FarFromPrimes.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class FarFromPrimesTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    FarFromPrimes solution;

    void testCase0() {
		int A = 3328;
		int B = 4100;
		int expected_ = 4;
        assertEquals(0, expected_, solution.count(A, B));
    }

    void testCase1() {
		int A = 10;
		int B = 1000;
		int expected_ = 0;
        assertEquals(1, expected_, solution.count(A, B));
    }

    void testCase2() {
		int A = 19240;
		int B = 19710;
		int expected_ = 53;
        assertEquals(2, expected_, solution.count(A, B));
    }

    void testCase3() {
		int A = 23659;
		int B = 24065;
		int expected_ = 20;
        assertEquals(3, expected_, solution.count(A, B));
    }

    void testCase4() {
		int A = 97001;
		int B = 97691;
		int expected_ = 89;
        assertEquals(4, expected_, solution.count(A, B));
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
        FarFromPrimesTest test;
        test.runTest(i);
    }
}
