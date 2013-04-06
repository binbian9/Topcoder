#include "SpeedTyper.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class SpeedTyperTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    SpeedTyper solution;

    void testCase0() {
		string letters = "dcab";
        int times_[] = {250, 300, 400, 800};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		string expected_ = "db";
        assertEquals(0, expected_, solution.lettersToPractice(letters, times));
    }

    void testCase1() {
		string letters = "keyboard";
        int times_[] = {100, 200, 300, 500, 600, 800, 900, 1200};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		string expected_ = "bad";
        assertEquals(1, expected_, solution.lettersToPractice(letters, times));
    }

    void testCase2() {
		string letters = "rewq";
        int times_[] = {500, 1000, 1500, 4000};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		string expected_ = "q";
        assertEquals(2, expected_, solution.lettersToPractice(letters, times));
    }

    void testCase3() {
		string letters = "abc";
        int times_[] = {2000, 4000, 6000};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		string expected_ = "";
        assertEquals(3, expected_, solution.lettersToPractice(letters, times));
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
        SpeedTyperTest test;
        test.runTest(i);
    }
}
