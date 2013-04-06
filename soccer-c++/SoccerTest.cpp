#include "Soccer.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class SoccerTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Soccer solution;

    void testCase0() {
        int wins_[] = {1, 4, 3, 0, 0};
        vector<int> wins(wins_, wins_ + (sizeof(wins_) / sizeof(wins_[0])));
        int ties_[] = {3, 1, 5, 3, 1};
        vector<int> ties(ties_, ties_ + (sizeof(ties_) / sizeof(ties_[0])));
		int expected_ = 14;
        assertEquals(0, expected_, solution.maxPoints(wins, ties));
    }

    void testCase1() {
        int wins_[] = {12, 45, 20, 17, 48, 0};
        vector<int> wins(wins_, wins_ + (sizeof(wins_) / sizeof(wins_[0])));
        int ties_[] = {48, 10, 53, 94, 0, 100};
        vector<int> ties(ties_, ties_ + (sizeof(ties_) / sizeof(ties_[0])));
		int expected_ = 145;
        assertEquals(1, expected_, solution.maxPoints(wins, ties));
    }

    void testCase2() {
        int wins_[] = {35, 0};
        vector<int> wins(wins_, wins_ + (sizeof(wins_) / sizeof(wins_[0])));
        int ties_[] = {0, 76};
        vector<int> ties(ties_, ties_ + (sizeof(ties_) / sizeof(ties_[0])));
		int expected_ = 105;
        assertEquals(2, expected_, solution.maxPoints(wins, ties));
    }

    void testCase3() {
        int wins_[] = {0, 0, 0, 0};
        vector<int> wins(wins_, wins_ + (sizeof(wins_) / sizeof(wins_[0])));
        int ties_[] = {0, 0, 0, 0};
        vector<int> ties(ties_, ties_ + (sizeof(ties_) / sizeof(ties_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.maxPoints(wins, ties));
    }

    void testCase4() {
        int wins_[] = {13, 79, 26, 73, 14, 89, 71, 37, 89, 71, 19, 59, 39};
        vector<int> wins(wins_, wins_ + (sizeof(wins_) / sizeof(wins_[0])));
        int ties_[] = {88, 27, 5, 70, 84, 94, 20, 50, 2, 11, 31, 22, 50};
        vector<int> ties(ties_, ties_ + (sizeof(ties_) / sizeof(ties_[0])));
		int expected_ = 361;
        assertEquals(4, expected_, solution.maxPoints(wins, ties));
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
        SoccerTest test;
        test.runTest(i);
    }
}
