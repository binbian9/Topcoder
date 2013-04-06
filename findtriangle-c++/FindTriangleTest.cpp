#include "FindTriangle.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class FindTriangleTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    FindTriangle solution;

    void testCase0() {
        string points_[] = {"R 0 0 0", "R 0 4 0", "R 0 0 3", "G 92 14 7", "G 12 16 8"};
        vector<string> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		double expected_ = 6.0;
        assertEquals(0, expected_, solution.largestArea(points));
    }

    void testCase1() {
        string points_[] = {"R 0 0 0", "R 0 4 0", "R 0 0 3", "G 0 5 0", "B 0 0 12"};
        vector<string> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		double expected_ = 30.0;
        assertEquals(1, expected_, solution.largestArea(points));
    }

    void testCase2() {
        string points_[] = {"R 0 0 0", "R 0 4 0", "R 0 0 3", "R 90 0 3", "G 2 14 7", "G 2 18 7", "G 29 14 3", "B 12 16 8"};
        vector<string> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		double expected_ = 225.0;
        assertEquals(2, expected_, solution.largestArea(points));
    }

    void testCase3() {
        string points_[] = {"R 0 0 0", "R 1 1 0", "R 4 4 0", "G 10 10 10", "G 0 1 2"};
        vector<string> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
		double expected_ = 0.0;
        assertEquals(3, expected_, solution.largestArea(points));
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
        FindTriangleTest test;
        test.runTest(i);
    }
}
