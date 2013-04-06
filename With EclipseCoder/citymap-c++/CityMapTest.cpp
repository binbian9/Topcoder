#include "CityMap.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class CityMapTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    CityMap solution;

    void testCase0() {
        string cityMap_[] = {"M....M", "...R.M", "R..R.R"};
        vector<string> cityMap(cityMap_, cityMap_ + (sizeof(cityMap_) / sizeof(cityMap_[0])));
        int POIs_[] = {3, 4};
        vector<int> POIs(POIs_, POIs_ + (sizeof(POIs_) / sizeof(POIs_[0])));
		string expected_ = "MR";
        assertEquals(0, expected_, solution.getLegend(cityMap, POIs));
    }

    void testCase1() {
        string cityMap_[] = {"XXXXXXXZXYYY"};
        vector<string> cityMap(cityMap_, cityMap_ + (sizeof(cityMap_) / sizeof(cityMap_[0])));
        int POIs_[] = {1, 8, 3};
        vector<int> POIs(POIs_, POIs_ + (sizeof(POIs_) / sizeof(POIs_[0])));
		string expected_ = "ZXY";
        assertEquals(1, expected_, solution.getLegend(cityMap, POIs));
    }

    void testCase2() {
        string cityMap_[] = {"...........", "...........", "...........", "..........T"};
        vector<string> cityMap(cityMap_, cityMap_ + (sizeof(cityMap_) / sizeof(cityMap_[0])));
        int POIs_[] = {1};
        vector<int> POIs(POIs_, POIs_ + (sizeof(POIs_) / sizeof(POIs_[0])));
		string expected_ = "T";
        assertEquals(2, expected_, solution.getLegend(cityMap, POIs));
    }

    void testCase3() {
        string cityMap_[] = {"AIAAARRI.......GOAI.", ".O..AIIGI.OAAAGI.A.I", ".A.IAAAARI..AI.AAGR.", "....IAI..AOIGA.GAIA.", "I.AIIIAG...GAR.IIAGA", "IA.AOA....I....I.GAA", "IOIGRAAAO.AI.AA.RAAA", "AI.AAA.AIR.AGRIAAG..", "AAAAIAAAI...AAG.RGRA", ".J.IA...G.A.AA.II.AA"};
        vector<string> cityMap(cityMap_, cityMap_ + (sizeof(cityMap_) / sizeof(cityMap_[0])));
        int POIs_[] = {16, 7, 1, 35, 11, 66};
        vector<int> POIs(POIs_, POIs_ + (sizeof(POIs_) / sizeof(POIs_[0])));
		string expected_ = "GOJIRA";
        assertEquals(3, expected_, solution.getLegend(cityMap, POIs));
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
        CityMapTest test;
        test.runTest(i);
    }
}
