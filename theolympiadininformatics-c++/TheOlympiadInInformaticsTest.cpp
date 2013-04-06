#include "TheOlympiadInInformatics.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class TheOlympiadInInformaticsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    TheOlympiadInInformatics solution;

    void testCase0() {
        int sums_[] = {4, 7, 0, 5};
        vector<int> sums(sums_, sums_ + (sizeof(sums_) / sizeof(sums_[0])));
		int k = 0;
		int expected_ = 7;
        assertEquals(0, expected_, solution.find(sums, k));
    }

    void testCase1() {
        int sums_[] = {4, 7};
        vector<int> sums(sums_, sums_ + (sizeof(sums_) / sizeof(sums_[0])));
		int k = 2;
		int expected_ = 3;
        assertEquals(1, expected_, solution.find(sums, k));
    }

    void testCase2() {
        int sums_[] = {999999999};
        vector<int> sums(sums_, sums_ + (sizeof(sums_) / sizeof(sums_[0])));
		int k = 1000000000;
		int expected_ = 0;
        assertEquals(2, expected_, solution.find(sums, k));
    }

    void testCase3() {
        int sums_[] = {95, 23, 87, 23, 82, 78, 59, 44, 12};
        vector<int> sums(sums_, sums_ + (sizeof(sums_) / sizeof(sums_[0])));
		int k = 70;
		int expected_ = 6;
        assertEquals(3, expected_, solution.find(sums, k));
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
        TheOlympiadInInformaticsTest test;
        test.runTest(i);
    }
}
