#include "SkiResortsEasy.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class SkiResortsEasyTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    SkiResortsEasy solution;

    void testCase0() {
        int altitude_[] = {30, 20, 20, 10};
        vector<int> altitude(altitude_, altitude_ + (sizeof(altitude_) / sizeof(altitude_[0])));
		int expected_ = 0;
        assertEquals(0, expected_, solution.minCost(altitude));
    }

    void testCase1() {
        int altitude_[] = {5, 7, 3};
        vector<int> altitude(altitude_, altitude_ + (sizeof(altitude_) / sizeof(altitude_[0])));
		int expected_ = 2;
        assertEquals(1, expected_, solution.minCost(altitude));
    }

    void testCase2() {
        int altitude_[] = {6, 8, 5, 4, 7, 4, 2, 3, 1};
        vector<int> altitude(altitude_, altitude_ + (sizeof(altitude_) / sizeof(altitude_[0])));
		int expected_ = 6;
        assertEquals(2, expected_, solution.minCost(altitude));
    }

    void testCase3() {
        int altitude_[] = {749, 560, 921, 166, 757, 818, 228, 584, 366, 88};
        vector<int> altitude(altitude_, altitude_ + (sizeof(altitude_) / sizeof(altitude_[0])));
		int expected_ = 2284;
        assertEquals(3, expected_, solution.minCost(altitude));
    }

    void testCase4() {
        int altitude_[] = {712, 745, 230, 200, 648, 440, 115, 913, 627, 621, 186, 222, 741, 954, 581, 193, 266, 320, 798, 745};
        vector<int> altitude(altitude_, altitude_ + (sizeof(altitude_) / sizeof(altitude_[0])));
		int expected_ = 6393;
        assertEquals(4, expected_, solution.minCost(altitude));
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
        SkiResortsEasyTest test;
        test.runTest(i);
    }
}
