#include "TeamContestEasy.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class TeamContestEasyTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    TeamContestEasy solution;

    void testCase0() {
        int strength_[] = {5, 7, 3, 5, 7, 3, 5, 7, 3};
        vector<int> strength(strength_, strength_ + (sizeof(strength_) / sizeof(strength_[0])));
		int expected_ = 2;
        assertEquals(0, expected_, solution.worstRank(strength));
    }

    void testCase1() {
        int strength_[] = {5, 7, 3};
        vector<int> strength(strength_, strength_ + (sizeof(strength_) / sizeof(strength_[0])));
		int expected_ = 1;
        assertEquals(1, expected_, solution.worstRank(strength));
    }

    void testCase2() {
        int strength_[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector<int> strength(strength_, strength_ + (sizeof(strength_) / sizeof(strength_[0])));
		int expected_ = 1;
        assertEquals(2, expected_, solution.worstRank(strength));
    }

    void testCase3() {
        int strength_[] = {2, 2, 1, 1, 3, 1, 3, 2, 1, 3, 1, 2, 1, 2, 1};
        vector<int> strength(strength_, strength_ + (sizeof(strength_) / sizeof(strength_[0])));
		int expected_ = 4;
        assertEquals(3, expected_, solution.worstRank(strength));
    }

    void testCase4() {
        int strength_[] = {45, 72, 10, 42, 67, 51, 33, 21, 8, 51, 17, 72};
        vector<int> strength(strength_, strength_ + (sizeof(strength_) / sizeof(strength_[0])));
		int expected_ = 3;
        assertEquals(4, expected_, solution.worstRank(strength));
    }

    void testCase5() {
        int strength_[] = {570466, 958327, 816467, 17, 403, 953808, 734850, 5824, 917784, 921731, 161921, 1734, 823437, 3218, 81, 932681, 2704, 981643, 1232, 475, 873323, 6558, 45660, 1813, 4714, 224, 32301, 28081, 6728, 17055, 561, 15146, 842613, 5559, 1860, 783, 989, 2811, 20664, 112531, 1933, 866794, 805528, 53821, 2465, 137385, 39, 2007};
        vector<int> strength(strength_, strength_ + (sizeof(strength_) / sizeof(strength_[0])));
		int expected_ = 6;
        assertEquals(5, expected_, solution.worstRank(strength));
    }

    void testCase6() {
        int strength_[] = {610297, 849870, 523999, 6557, 976530, 731458, 7404, 795100, 147040, 110947, 159692, 40785, 4949, 2903, 1688, 37278, 620703, 28156, 16823, 1159, 12132, 971379, 5916, 1159, 988589, 12215, 133, 1490, 911360, 920059, 544070, 40249, 514852, 852, 745070, 1105, 715897, 714696, 589133, 698317, 5683, 631612, 16453, 101000, 764881, 101, 2053, 754661};
        vector<int> strength(strength_, strength_ + (sizeof(strength_) / sizeof(strength_[0])));
		int expected_ = 10;
        assertEquals(6, expected_, solution.worstRank(strength));
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
        TeamContestEasyTest test;
        test.runTest(i);
    }
}
