#include "SpacetskE.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class SpacetskETest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    SpacetskE solution;

    void testCase0() {
		int L = 1;
		int H = 1;
		int K = 2;
		int expected_ = 4;
        assertEquals(0, expected_, solution.countsets(L, H, K));
    }

    void testCase1() {
		int L = 1;
		int H = 1;
		int K = 1;
		int expected_ = 4;
        assertEquals(1, expected_, solution.countsets(L, H, K));
    }

    void testCase2() {
		int L = 2;
		int H = 2;
		int K = 1;
		int expected_ = 9;
        assertEquals(2, expected_, solution.countsets(L, H, K));
    }

    void testCase3() {
		int L = 2;
		int H = 2;
		int K = 2;
		int expected_ = 23;
        assertEquals(3, expected_, solution.countsets(L, H, K));
    }

    void testCase4() {
		int L = 5;
		int H = 5;
		int K = 3;
		int expected_ = 202;
        assertEquals(4, expected_, solution.countsets(L, H, K));
    }

    void testCase5() {
		int L = 70;
		int H = 52;
		int K = 18;
		int expected_ = 296314116;
        assertEquals(5, expected_, solution.countsets(L, H, K));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 6; i++) {
        SpacetskETest test;
        test.runTest(i);
    }
}
