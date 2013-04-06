#include "CombinationLock.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class CombinationLockTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    CombinationLock solution;

    void testCase0() {
        int combo_[] = {10, 20, 30};
        vector<int> combo(combo_, combo_ + (sizeof(combo_) / sizeof(combo_[0])));
		int size = 40;
		int start = 6;
		double expected_ = 2556.0;
        assertEquals(0, expected_, solution.degreesTurned(combo, size, start));
    }

    void testCase1() {
        int combo_[] = {0, 50, 99};
        vector<int> combo(combo_, combo_ + (sizeof(combo_) / sizeof(combo_[0])));
		int size = 100;
		int start = 65;
		double expected_ = 2642.4;
        assertEquals(1, expected_, solution.degreesTurned(combo, size, start));
    }

    void testCase2() {
        int combo_[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> combo(combo_, combo_ + (sizeof(combo_) / sizeof(combo_[0])));
		int size = 10;
		int start = 5;
		double expected_ = 79344.0;
        assertEquals(2, expected_, solution.degreesTurned(combo, size, start));
    }

    void testCase3() {
        int combo_[] = {64, 93, 87, 3, 22, 53, 64, 53, 11, 90, 11, 59, 30, 6, 11, 17, 72, 0, 38, 55};
        vector<int> combo(combo_, combo_ + (sizeof(combo_) / sizeof(combo_[0])));
		int size = 97;
		int start = 26;
		double expected_ = 79166.59793814432;
        assertEquals(3, expected_, solution.degreesTurned(combo, size, start));
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
        CombinationLockTest test;
        test.runTest(i);
    }
}
