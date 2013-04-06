#include "CubeNets.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class CubeNetsTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    CubeNets solution;

    void testCase0() {
        string figure_[] = {"..#.", "####", "..#."};
        vector<string> figure(figure_, figure_ + (sizeof(figure_) / sizeof(figure_[0])));
		string expected_ = "YES";
        assertEquals(0, expected_, solution.isCubeNet(figure));
    }

    void testCase1() {
        string figure_[] = {"###", "###"};
        vector<string> figure(figure_, figure_ + (sizeof(figure_) / sizeof(figure_[0])));
		string expected_ = "NO";
        assertEquals(1, expected_, solution.isCubeNet(figure));
    }

    void testCase2() {
        string figure_[] = {"..#.", "####", ".#.."};
        vector<string> figure(figure_, figure_ + (sizeof(figure_) / sizeof(figure_[0])));
		string expected_ = "YES";
        assertEquals(2, expected_, solution.isCubeNet(figure));
    }

    void testCase3() {
        string figure_[] = {"##..", ".##.", "..##"};
        vector<string> figure(figure_, figure_ + (sizeof(figure_) / sizeof(figure_[0])));
		string expected_ = "YES";
        assertEquals(3, expected_, solution.isCubeNet(figure));
    }

    void testCase4() {
        string figure_[] = {"####", "...#", "...#"};
        vector<string> figure(figure_, figure_ + (sizeof(figure_) / sizeof(figure_[0])));
		string expected_ = "NO";
        assertEquals(4, expected_, solution.isCubeNet(figure));
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
        CubeNetsTest test;
        test.runTest(i);
    }
}
