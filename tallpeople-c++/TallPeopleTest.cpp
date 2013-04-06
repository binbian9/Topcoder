#include "TallPeople.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class TallPeopleTest {

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

    TallPeople solution;

    void testCase0() {
        string people_[] = {"9 2 3", "4 8 7"};
        vector<string> people(people_, people_ + (sizeof(people_) / sizeof(people_[0])));
        int expected__[] = {4, 7};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.getPeople(people));
    }

    void testCase1() {
        string people_[] = {"1 2", "4 5", "3 6"};
        vector<string> people(people_, people_ + (sizeof(people_) / sizeof(people_[0])));
        int expected__[] = {4, 4};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.getPeople(people));
    }

    void testCase2() {
        string people_[] = {"1 1", "1 1"};
        vector<string> people(people_, people_ + (sizeof(people_) / sizeof(people_[0])));
        int expected__[] = {1, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.getPeople(people));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 3; i++) {
        TallPeopleTest test;
        test.runTest(i);
    }
}
