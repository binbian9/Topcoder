#include "TemplateMatching.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class TemplateMatchingTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    TemplateMatching solution;

    void testCase0() {
		string text = "something";
		string prefix = "awesome";
		string suffix = "ingenious";
		string expected_ = "something";
        assertEquals(0, expected_, solution.bestMatch(text, prefix, suffix));
    }

    void testCase1() {
		string text = "havka";
		string prefix = "eto";
		string suffix = "papstvo";
		string expected_ = "a";
        assertEquals(1, expected_, solution.bestMatch(text, prefix, suffix));
    }

    void testCase2() {
		string text = "abracadabra";
		string prefix = "habrahabr";
		string suffix = "bracket";
		string expected_ = "abrac";
        assertEquals(2, expected_, solution.bestMatch(text, prefix, suffix));
    }

    void testCase3() {
		string text = "mississippi";
		string prefix = "promise";
		string suffix = "piccolo";
		string expected_ = "ippi";
        assertEquals(3, expected_, solution.bestMatch(text, prefix, suffix));
    }

    void testCase4() {
		string text = "a a a a a a";
		string prefix = "a a";
		string suffix = "a";
		string expected_ = "a a";
        assertEquals(4, expected_, solution.bestMatch(text, prefix, suffix));
    }

    void testCase5() {
		string text = "ab";
		string prefix = "b";
		string suffix = "a";
		string expected_ = "b";
        assertEquals(5, expected_, solution.bestMatch(text, prefix, suffix));
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
        TemplateMatchingTest test;
        test.runTest(i);
    }
}
