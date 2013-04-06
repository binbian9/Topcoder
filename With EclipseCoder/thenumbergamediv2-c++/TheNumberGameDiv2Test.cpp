#include "TheNumberGameDiv2.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class TheNumberGameDiv2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    TheNumberGameDiv2 solution;

    void testCase0() {
		int A = 25;
		int B = 5;
		int expected_ = 2;
        assertEquals(0, expected_, solution.minimumMoves(A, B));
    }

    void testCase1() {
		int A = 5162;
		int B = 16;
		int expected_ = 4;
        assertEquals(1, expected_, solution.minimumMoves(A, B));
    }

    void testCase2() {
		int A = 334;
		int B = 12;
		int expected_ = -1;
        assertEquals(2, expected_, solution.minimumMoves(A, B));
    }

    void testCase3() {
		int A = 218181918;
		int B = 9181;
		int expected_ = 6;
        assertEquals(3, expected_, solution.minimumMoves(A, B));
    }

    void testCase4() {
		int A = 9798147;
		int B = 79817;
		int expected_ = -1;
        assertEquals(4, expected_, solution.minimumMoves(A, B));
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
        TheNumberGameDiv2Test test;
        test.runTest(i);
    }
}
