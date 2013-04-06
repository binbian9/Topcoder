#include "TheKnights.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class TheKnightsTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    TheKnights solution;

    void testCase0() {
		int n = 2;
		int a = 1;
		int b = 1;
		double expected_ = 3.3333333333333335;
        assertEquals(0, expected_, solution.find(n, a, b));
    }

    void testCase1() {
		int n = 47;
		int a = 7;
		int b = 74;
		double expected_ = 2.0;
        assertEquals(1, expected_, solution.find(n, a, b));
    }

    void testCase2() {
		int n = 3;
		int a = 2;
		int b = 1;
		double expected_ = 4.888888888888889;
        assertEquals(2, expected_, solution.find(n, a, b));
    }

    void testCase3() {
		int n = 9999;
		int a = 999;
		int b = 99;
		double expected_ = 16.25885103191273;
        assertEquals(3, expected_, solution.find(n, a, b));
    }

    void testCase4() {
		int n = 10;
		int a = 1;
		int b = 6;
		double expected_ = 7.636363636363637;
        assertEquals(4, expected_, solution.find(n, a, b));
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
        TheKnightsTest test;
        test.runTest(i);
    }
}
