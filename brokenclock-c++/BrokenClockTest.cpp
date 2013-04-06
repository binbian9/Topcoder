#include "BrokenClock.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class BrokenClockTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BrokenClock solution;

    void testCase0() {
		string clockTime = "03:12";
		string currentTime = "04:15";
		int expected_ = 3;
        assertEquals(0, expected_, solution.fewestClicks(clockTime, currentTime));
    }

    void testCase1() {
		string clockTime = "07:07";
		string currentTime = "13:21";
		int expected_ = 14;
        assertEquals(1, expected_, solution.fewestClicks(clockTime, currentTime));
    }

    void testCase2() {
		string clockTime = "14:55";
		string currentTime = "14:05";
		int expected_ = 10;
        assertEquals(2, expected_, solution.fewestClicks(clockTime, currentTime));
    }

    void testCase3() {
		string clockTime = "23:14";
		string currentTime = "00:20";
		int expected_ = 6;
        assertEquals(3, expected_, solution.fewestClicks(clockTime, currentTime));
    }

    void testCase4() {
		string clockTime = "18:43";
		string currentTime = "18:43";
		int expected_ = 0;
        assertEquals(4, expected_, solution.fewestClicks(clockTime, currentTime));
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
        BrokenClockTest test;
        test.runTest(i);
    }
}
