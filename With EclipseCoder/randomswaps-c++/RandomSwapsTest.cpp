#include "RandomSwaps.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class RandomSwapsTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    RandomSwaps solution;

    void testCase0() {
		int arrayLength = 5;
		int swapCount = 1;
		int a = 0;
		int b = 0;
		double expected_ = 0.6;
        assertEquals(0, expected_, solution.getProbability(arrayLength, swapCount, a, b));
    }

    void testCase1() {
		int arrayLength = 5;
		int swapCount = 1;
		int a = 0;
		int b = 3;
		double expected_ = 0.1;
        assertEquals(1, expected_, solution.getProbability(arrayLength, swapCount, a, b));
    }

    void testCase2() {
		int arrayLength = 5;
		int swapCount = 2;
		int a = 0;
		int b = 0;
		double expected_ = 0.4;
        assertEquals(2, expected_, solution.getProbability(arrayLength, swapCount, a, b));
    }

    void testCase3() {
		int arrayLength = 100;
		int swapCount = 500;
		int a = 3;
		int b = 3;
		double expected_ = 0.010036635745123007;
        assertEquals(3, expected_, solution.getProbability(arrayLength, swapCount, a, b));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 4; i++) {
        RandomSwapsTest test;
        test.runTest(i);
    }
}
