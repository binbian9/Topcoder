#include "NextOrPrev.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class NextOrPrevTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    NextOrPrev solution;

    void testCase0() {
		int nextCost = 5;
		int prevCost = 8;
		string start = "ae";
		string goal = "bc";
		int expected_ = 21;
        assertEquals(0, expected_, solution.getMinimum(nextCost, prevCost, start, goal));
    }

    void testCase1() {
		int nextCost = 5;
		int prevCost = 8;
		string start = "ae";
		string goal = "cb";
		int expected_ = -1;
        assertEquals(1, expected_, solution.getMinimum(nextCost, prevCost, start, goal));
    }

    void testCase2() {
		int nextCost = 1;
		int prevCost = 1;
		string start = "srm";
		string goal = "srm";
		int expected_ = 0;
        assertEquals(2, expected_, solution.getMinimum(nextCost, prevCost, start, goal));
    }

    void testCase3() {
		int nextCost = 10;
		int prevCost = 1;
		string start = "acb";
		string goal = "bdc";
		int expected_ = 30;
        assertEquals(3, expected_, solution.getMinimum(nextCost, prevCost, start, goal));
    }

    void testCase4() {
		int nextCost = 10;
		int prevCost = 1;
		string start = "zyxw";
		string goal = "vuts";
		int expected_ = 16;
        assertEquals(4, expected_, solution.getMinimum(nextCost, prevCost, start, goal));
    }

    void testCase5() {
		int nextCost = 563;
		int prevCost = 440;
		string start = "ptrbgcnlaizo";
		string goal = "rtscedkiahul";
		int expected_ = 10295;
        assertEquals(5, expected_, solution.getMinimum(nextCost, prevCost, start, goal));
    }

    void testCase6() {
		int nextCost = 126;
		int prevCost = 311;
		string start = "yovlkwpjgsna";
		string goal = "zpwnkytjisob";
		int expected_ = -1;
        assertEquals(6, expected_, solution.getMinimum(nextCost, prevCost, start, goal));
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
        NextOrPrevTest test;
        test.runTest(i);
    }
}
