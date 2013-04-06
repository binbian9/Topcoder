#include "Predicting.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class PredictingTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Predicting solution;

    void testCase0() {
        double data_[] = {10.0, 10.0, 10.0, 10.0, 10.0, 10.0};
        vector<double> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
		double expected_ = 0.0;
        assertEquals(0, expected_, solution.avgError(data));
    }

    void testCase1() {
        double data_[] = {50.0, 10.0, 50.0, 10.0, 50.0, 10.0, 50.0, 10.0, 50.0, 10.0, 50.0, 10.0};
        vector<double> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
		double expected_ = 0.0;
        assertEquals(1, expected_, solution.avgError(data));
    }

    void testCase2() {
        double data_[] = {50.0, 60.0, 50.0, 60.0, 50.0, 60.0, 60.0};
        vector<double> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
		double expected_ = 5.0;
        assertEquals(2, expected_, solution.avgError(data));
    }

    void testCase3() {
        double data_[] = {82.9102, 70.6848, 21.503, 61.4588, 54.7789, 48.9889, 57.6766, 91.1859, 26.3674, 55.4601, 53.9357, 87.2005, 78.4771, 65.0102, 18.619, 90.296, 26.3894, 53.8588, 91.8369, 58.8028, 74.0577, 28.2406, 65.609, 59.4867, 27.7544, 54.6992, 69.2428, 22.6264, 87.0083, 58.5116, 60.286, 20.4318, 65.6475, 11.8348, 36.3488, 92.8092, 60.7392, 98.124, 48.1292, 39.5459, 52.2657, 34.3519, 38.9279, 93.0152, 11.3157};
        vector<double> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
		double expected_ = 22.0175905;
        assertEquals(3, expected_, solution.avgError(data));
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
        PredictingTest test;
        test.runTest(i);
    }
}
