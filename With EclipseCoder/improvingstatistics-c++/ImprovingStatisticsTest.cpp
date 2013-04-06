#include "ImprovingStatistics.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class ImprovingStatisticsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ImprovingStatistics solution;

    void testCase0() {
		int played = 10;
		int won = 8;
		int expected_ = 1;
        assertEquals(0, expected_, solution.howManyGames(played, won));
    }

    void testCase1() {
		int played = 100;
		int won = 80;
		int expected_ = 6;
        assertEquals(1, expected_, solution.howManyGames(played, won));
    }

    void testCase2() {
		int played = 47;
		int won = 47;
		int expected_ = -1;
        assertEquals(2, expected_, solution.howManyGames(played, won));
    }

    void testCase3() {
		int played = 99000;
		int won = 0;
		int expected_ = 1000;
        assertEquals(3, expected_, solution.howManyGames(played, won));
    }

    void testCase4() {
		int played = 1000000000;
		int won = 470000000;
		int expected_ = 19230770;
        assertEquals(4, expected_, solution.howManyGames(played, won));
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
        ImprovingStatisticsTest test;
        test.runTest(i);
    }
}
