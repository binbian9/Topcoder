#include "PlayingCubes.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class PlayingCubesTest {

    static void writeTo(std::ostream& out, const vector<int>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << v[i];
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<int>& expected, const vector<int>& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <";
            writeTo(cout, expected);
            cout << "> but was: <";
            writeTo(cout, actual);
            cout << '>' << endl;
        }
    }

    PlayingCubes solution;

    void testCase0() {
        string cubes_[] = {"ABCDEF", "DEFGHI", "OPQRST", "ZZZZZZ", "YYYYYY"};
        vector<string> cubes(cubes_, cubes_ + (sizeof(cubes_) / sizeof(cubes_[0])));
        string words_[] = {"CAT", "DOG", "PIZZA"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
        int expected__[] = {1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.composeWords(cubes, words));
    }

    void testCase1() {
        string cubes_[] = {"ABCDEF", "DEFGHI", "OPQRST", "MNZLSA", "QEIOGH", "IARJGS"};
        vector<string> cubes(cubes_, cubes_ + (sizeof(cubes_) / sizeof(cubes_[0])));
        string words_[] = {"DOG", "CAT", "MOUSE", "BIRD", "CHICKEN", "PIG", "ANIMAL"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
        int expected__[] = {0, 1, 3, 5};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.composeWords(cubes, words));
    }

    void testCase2() {
        string cubes_[] = {"AAAAAA", "AAAAAA", "AAAAAA", "AAAAAA"};
        vector<string> cubes(cubes_, cubes_ + (sizeof(cubes_) / sizeof(cubes_[0])));
        string words_[] = {"AA", "AAA", "AAAA", "AAAAA", "AAAAAA"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
        int expected__[] = {0, 1, 2};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.composeWords(cubes, words));
    }

    void testCase3() {
        string cubes_[] = {"ABCDEF", "DEFGHI", "OPQRST", "ZZZZZZ", "ZZZZZZ"};
        vector<string> cubes(cubes_, cubes_ + (sizeof(cubes_) / sizeof(cubes_[0])));
        string words_[] = {"CAT", "DOG", "PIZZA"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
        int expected__[] = {1, 2};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.composeWords(cubes, words));
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
        PlayingCubesTest test;
        test.runTest(i);
    }
}
