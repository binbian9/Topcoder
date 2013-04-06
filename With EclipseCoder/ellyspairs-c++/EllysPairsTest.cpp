#include "EllysPairs.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class EllysPairsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    EllysPairs solution;

    void testCase0() {
        int knowledge_[] = {2, 6, 4, 3};
        vector<int> knowledge(knowledge_, knowledge_ + (sizeof(knowledge_) / sizeof(knowledge_[0])));
		int expected_ = 1;
        assertEquals(0, expected_, solution.getDifference(knowledge));
    }

    void testCase1() {
        int knowledge_[] = {1, 1, 1, 1, 1, 1};
        vector<int> knowledge(knowledge_, knowledge_ + (sizeof(knowledge_) / sizeof(knowledge_[0])));
		int expected_ = 0;
        assertEquals(1, expected_, solution.getDifference(knowledge));
    }

    void testCase2() {
        int knowledge_[] = {4, 2, 4, 2, 1, 3, 3, 7};
        vector<int> knowledge(knowledge_, knowledge_ + (sizeof(knowledge_) / sizeof(knowledge_[0])));
		int expected_ = 2;
        assertEquals(2, expected_, solution.getDifference(knowledge));
    }

    void testCase3() {
        int knowledge_[] = {5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4};
        vector<int> knowledge(knowledge_, knowledge_ + (sizeof(knowledge_) / sizeof(knowledge_[0])));
		int expected_ = 3;
        assertEquals(3, expected_, solution.getDifference(knowledge));
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
        EllysPairsTest test;
        test.runTest(i);
    }
}
