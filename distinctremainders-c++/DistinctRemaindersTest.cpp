#include "DistinctRemainders.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class DistinctRemaindersTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    DistinctRemainders solution;

    void testCase0() {
		long long N = 3LL;
		int M = 2;
		int expected_ = 5;
        assertEquals(0, expected_, solution.howMany(N, M));
    }

    void testCase1() {
		long long N = 3LL;
		int M = 3;
		int expected_ = 9;
        assertEquals(1, expected_, solution.howMany(N, M));
    }

    void testCase2() {
		long long N = 58LL;
		int M = 1;
		int expected_ = 1;
        assertEquals(2, expected_, solution.howMany(N, M));
    }

    void testCase3() {
		long long N = 572LL;
		int M = 7;
		int expected_ = 922572833;
        assertEquals(3, expected_, solution.howMany(N, M));
    }

    void testCase4() {
		long long N = 1000000000000000000LL;
		int M = 20;
		int expected_ = 240297629;
        assertEquals(4, expected_, solution.howMany(N, M));
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
        DistinctRemaindersTest test;
        test.runTest(i);
    }
}
