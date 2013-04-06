#include "EllysReversals.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class EllysReversalsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    EllysReversals solution;

    void testCase0() {
        string words_[] = {"esprit", "god", "redotopc", "odcpoter", "dog"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		int expected_ = 3;
        assertEquals(0, expected_, solution.getMin(words));
    }

    void testCase1() {
        string words_[] = {"no", "zaphod", "just", "very", "improbable"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		int expected_ = 5;
        assertEquals(1, expected_, solution.getMin(words));
    }

    void testCase2() {
        string words_[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		int expected_ = 0;
        assertEquals(2, expected_, solution.getMin(words));
    }

    void testCase3() {
        string words_[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		int expected_ = 1;
        assertEquals(3, expected_, solution.getMin(words));
    }

    void testCase4() {
        string words_[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt", "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux", "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut", "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda", "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		int expected_ = 16;
        assertEquals(4, expected_, solution.getMin(words));
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
        EllysReversalsTest test;
        test.runTest(i);
    }
}
