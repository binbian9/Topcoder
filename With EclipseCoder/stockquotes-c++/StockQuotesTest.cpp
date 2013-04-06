#include "StockQuotes.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class StockQuotesTest {

    static void writeTo(std::ostream& out, const vector<string>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << '"' << v[i] << '"';
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<string>& expected, const vector<string>& actual) {
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

    StockQuotes solution;

    void testCase0() {
        string quotes_[] = {"0 10 14", "1 9 16", "2 11 15", "0 11 13", "1 10 15", "2 12 14", "0 9 15", "2 8 20"};
        vector<string> quotes(quotes_, quotes_ + (sizeof(quotes_) / sizeof(quotes_[0])));
        string expected__[] = {"0 3 4.00", "1 2 6.00", "2 3 6.00", "10 6 2.83"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.report(quotes));
    }

    void testCase1() {
        string quotes_[] = {"8 931 944", "8 926 946", "8 926 951", "8 928 953", "8 929 954"};
        vector<string> quotes(quotes_, quotes_ + (sizeof(quotes_) / sizeof(quotes_[0])));
        string expected__[] = {"8 5 21.60", "10 5 21.60"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.report(quotes));
    }

    void testCase2() {
        string quotes_[] = {"2 711 730", "5 716 729", "7 711 734", "0 718 731", "5 713 731", "1 713 730"};
        vector<string> quotes(quotes_, quotes_ + (sizeof(quotes_) / sizeof(quotes_[0])));
        string expected__[] = {"0 1 13.00", "1 1 17.00", "2 1 19.00", "5 2 15.50", "7 1 23.00", "10 4 13.75"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.report(quotes));
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
    for (int i = 0; i < 3; i++)
    {
        StockQuotesTest test;
        test.runTest(i);
    }
}
