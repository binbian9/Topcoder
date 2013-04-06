#include "PolygonTraversal2.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class PolygonTraversal2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    PolygonTraversal2 solution;

    void testCase0() {
		int N = 5;
        int points_[] = {1, 3, 5};
        vector<int> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		int expected_ = 1;
        assertEquals(0, expected_, solution.count(N, points));
    }

    void testCase1() {
		int N = 6;
        int points_[] = {1, 4, 2};
        vector<int> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		int expected_ = 1;
        assertEquals(1, expected_, solution.count(N, points));
    }

    void testCase2() {
		int N = 7;
        int points_[] = {2, 4, 7};
        vector<int> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		int expected_ = 2;
        assertEquals(2, expected_, solution.count(N, points));
    }

    void testCase3() {
		int N = 7;
        int points_[] = {1, 2, 3, 4, 6, 5};
        vector<int> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.count(N, points));
    }

    void testCase4() {
		int N = 11;
        int points_[] = {1, 5, 10};
        vector<int> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		int expected_ = 1412;
        assertEquals(4, expected_, solution.count(N, points));
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
        PolygonTraversal2Test test;
        test.runTest(i);
    }
}
