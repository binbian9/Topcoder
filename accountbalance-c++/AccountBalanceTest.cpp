#include "AccountBalance.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class AccountBalanceTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    AccountBalance solution;

    void testCase0() {
		int startingBalance = 100;
        string transactions_[] = {"C 1000", "D 500", "D 350"};
        vector<string> transactions(transactions_, transactions_ + (sizeof(transactions_) / sizeof(transactions_[0])));
		int expected_ = 250;
        assertEquals(0, expected_, solution.processTransactions(startingBalance, transactions));
    }

    void testCase1() {
		int startingBalance = 100;
        vector<string> transactions;
		int expected_ = 100;
        assertEquals(1, expected_, solution.processTransactions(startingBalance, transactions));
    }

    void testCase2() {
		int startingBalance = 100;
        string transactions_[] = {"D 50", "D 20", "D 40"};
        vector<string> transactions(transactions_, transactions_ + (sizeof(transactions_) / sizeof(transactions_[0])));
		int expected_ = -10;
        assertEquals(2, expected_, solution.processTransactions(startingBalance, transactions));
    }

    void testCase3() {
		int startingBalance = 53874;
        string transactions_[] = {"D 1234", "C 987", "D 2345", "C 654", "D 6789", "D 34567"};
        vector<string> transactions(transactions_, transactions_ + (sizeof(transactions_) / sizeof(transactions_[0])));
		int expected_ = 10580;
        assertEquals(3, expected_, solution.processTransactions(startingBalance, transactions));
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
        AccountBalanceTest test;
        test.runTest(i);
    }
}
