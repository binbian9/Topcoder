#include "CakeParty.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class CakePartyTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    CakeParty solution;

    void testCase0() {
        int pieces_[] = {47};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		string expected_ = "CAKE 0 PIECES 47";
        assertEquals(0, expected_, solution.makeMove(pieces));
    }

    void testCase1() {
        int pieces_[] = {3, 3};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		string expected_ = "CAKE 0 PIECES 1";
        assertEquals(1, expected_, solution.makeMove(pieces));
    }

    void testCase2() {
        int pieces_[] = {3, 5};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		string expected_ = "CAKE 1 PIECES 2";
        assertEquals(2, expected_, solution.makeMove(pieces));
    }

    void testCase3() {
        int pieces_[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		string expected_ = "CAKE 0 PIECES 1";
        assertEquals(3, expected_, solution.makeMove(pieces));
    }

    void testCase4() {
        int pieces_[] = {3, 3, 112};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		string expected_ = "CAKE 2 PIECES 110";
        assertEquals(4, expected_, solution.makeMove(pieces));
    }

    void testCase5() {
        int pieces_[] = {3, 3, 1};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		string expected_ = "CAKE 0 PIECES 1";
        assertEquals(5, expected_, solution.makeMove(pieces));
    }

    void testCase6() {
        int pieces_[] = {4, 7, 4, 7, 4, 7, 4, 7, 47, 47, 47, 47};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		string expected_ = "CAKE 10 PIECES 1";
        assertEquals(6, expected_, solution.makeMove(pieces));
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
        CakePartyTest test;
        test.runTest(i);
    }
}
