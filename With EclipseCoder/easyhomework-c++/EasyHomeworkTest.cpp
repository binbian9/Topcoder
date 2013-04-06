#include "EasyHomework.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class EasyHomeworkTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    EasyHomework solution;

    void testCase0() {
        int A_[] = {5, 7, 2};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		string expected_ = "POSITIVE";
        assertEquals(0, expected_, solution.determineSign(A));
    }

    void testCase1() {
        int A_[] = {-5, 7, 2};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		string expected_ = "NEGATIVE";
        assertEquals(1, expected_, solution.determineSign(A));
    }

    void testCase2() {
        int A_[] = {5, 7, 2, 0};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		string expected_ = "ZERO";
        assertEquals(2, expected_, solution.determineSign(A));
    }

    void testCase3() {
        int A_[] = {3, -14, 159, -26};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		string expected_ = "POSITIVE";
        assertEquals(3, expected_, solution.determineSign(A));
    }

    void testCase4() {
        int A_[] = {-1000000000};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		string expected_ = "NEGATIVE";
        assertEquals(4, expected_, solution.determineSign(A));
    }

    void testCase5() {
        int A_[] = {123, -456, 789, -101112, 131415, 161718, 192021, 222324, 252627, 282930, 313233, 343536, 373839, 404142, 434445, 464748, 495051, 525354, 555657};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
		string expected_ = "POSITIVE";
        assertEquals(5, expected_, solution.determineSign(A));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 6; i++) {
        EasyHomeworkTest test;
        test.runTest(i);
    }
}
