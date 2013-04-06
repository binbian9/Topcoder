#include "ANDEquation.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class ANDEquationTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ANDEquation solution;

    void testCase0() {
        int A_[] = {1, 3, 5};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		int expected_ = 1;
        assertEquals(0, expected_, solution.restoreY(A));
    }

    void testCase1() {
        int A_[] = {31, 7};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		int expected_ = -1;
        assertEquals(1, expected_, solution.restoreY(A));
    }

    void testCase2() {
        int A_[] = {31, 7, 7};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		int expected_ = 7;
        assertEquals(2, expected_, solution.restoreY(A));
    }

    void testCase3() {
        int A_[] = {1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.restoreY(A));
    }

    void testCase4() {
        int A_[] = {191411, 256951, 191411, 191411, 191411, 256951, 195507, 191411, 192435, 191411, 191411, 195511, 191419, 191411, 256947, 191415, 191475, 195579, 191415, 191411, 191483, 191411, 191419, 191475, 256947, 191411, 191411, 191411, 191419, 256947, 191411, 191411, 191411};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		int expected_ = 191411;
        assertEquals(4, expected_, solution.restoreY(A));
    }

    void testCase5() {
        int A_[] = {1362, 1066, 1659, 2010, 1912, 1720, 1851, 1593, 1799, 1805, 1139, 1493, 1141, 1163, 1211};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		int expected_ = -1;
        assertEquals(5, expected_, solution.restoreY(A));
    }

    void testCase6() {
        int A_[] = {2, 3, 7, 19};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		int expected_ = -1;
        assertEquals(6, expected_, solution.restoreY(A));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            case (6): testCase6(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 7; i++) {
        ANDEquationTest test;
        test.runTest(i);
    }
}
