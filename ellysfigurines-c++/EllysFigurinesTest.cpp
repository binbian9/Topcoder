#include "EllysFigurines.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class EllysFigurinesTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    EllysFigurines solution;

    void testCase0() {
        string board_[] = {".X.X.", "XX..X", ".XXX.", "...X.", ".X.XX"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int R = 1;
		int C = 2;
		int expected_ = 3;
        assertEquals(0, expected_, solution.getMoves(board, R, C));
    }

    void testCase1() {
        string board_[] = {".X.X.", "XX..X", ".X.X.", "...X.", ".X.XX"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int R = 2;
		int C = 2;
		int expected_ = 2;
        assertEquals(1, expected_, solution.getMoves(board, R, C));
    }

    void testCase2() {
        string board_[] = {"XXXXXXX"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int R = 2;
		int C = 3;
		int expected_ = 1;
        assertEquals(2, expected_, solution.getMoves(board, R, C));
    }

    void testCase3() {
        string board_[] = {"XXXXX", "X....", "XXX..", "X....", "XXXXX"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int R = 1;
		int C = 1;
		int expected_ = 4;
        assertEquals(3, expected_, solution.getMoves(board, R, C));
    }

    void testCase4() {
        string board_[] = {"XXX..XXX..XXX.", ".X..X....X...X", ".X..X....X...X", ".X..X....X...X", ".X...XXX..XXX.", "..............", "...XX...XXX...", "....X......X..", "....X....XXX..", "....X......X..", "...XXX..XXX..."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int R = 1;
		int C = 2;
		int expected_ = 7;
        assertEquals(4, expected_, solution.getMoves(board, R, C));
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
        EllysFigurinesTest test;
        test.runTest(i);
    }
}
