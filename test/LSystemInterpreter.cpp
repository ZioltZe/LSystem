#include "catch2/catch.h"
#include "07_project/Production.h"
#include "07_project/LSystemInterpreter.h"

TEST_CASE("TestSystem1", "[LSystem()]")
{
    // >> Defining the productions, axiom and alphabet
    Production<char> production1('A', "AB");
    Production<char> production2('B', "A");

    vector<char> axiom = {'A','B','A'};
    unordered_set<char> alphabet = {'A', 'B'};

    // >> Putting the productions in an unordered set
    unordered_set<Production<char>> productionSet;
    productionSet.insert(production1);
    productionSet.insert(production2);

    // >> Creating the L System
    LSystemInterpreter<char> lSystem(axiom, productionSet, alphabet);

    // >> Generating a result
    vector<char> result;

    size_t n = 1;
    vector<vector<char>> v1(n);
    generate(v1.begin(), v1.end(), [&lSystem]() { return lSystem(); });
    result = v1.back();

    vector<char> expectedVector1 = {'A', 'B', 'A', 'A', 'B'};
    CHECK(result == expectedVector1);
}

TEST_CASE("TestSystem2", "[Reset()]")
{
    // >> Defining the productions, axiom and alphabet
    Production<char> production1('F', "F[+F]-F+F");
    Production<char> production2('+', "+");
    Production<char> production3('[', "[");
    Production<char> production4(']', "]");
    Production<char> production5('-', "-");

    vector<char> axiom = {'F'};
    unordered_set<char> alphabet = {'F', '+', '-', '[', ']'};

    // >> Putting the productions in an unordered set
    unordered_set<Production<char>> productionSet;
    productionSet.insert(production1);
    productionSet.insert(production2);
    productionSet.insert(production3);
    productionSet.insert(production4);
    productionSet.insert(production5);

    // >> Creating the L System
    LSystemInterpreter<char> lSystem(axiom, productionSet, alphabet);

    // >> Generating a result
    vector<char> result;

    size_t n = 1;
    vector<vector<char>> v1(n);
    generate(v1.begin(), v1.end(), [&lSystem]() { return lSystem(); });
    result = v1.back();

    vector<char> expectedVector1 = {'F','[','+','F',']','-','F','+','F'};
    CHECK(result == expectedVector1);

    // >> Resetting the L System
    lSystem.reset();

    // >> Regenerate a result
    size_t n2 = 2;
    vector<vector<char>> v2(n2);
    generate(v2.begin(), v2.end(), [&lSystem]() { return lSystem(); });
    result = v2.back();

    vector<char> expectedVector2 = {'F','[','+','F',']','-','F','+','F','[','+','F','[',
                                    '+','F',']','-','F','+','F',']','-','F','[','+','F',
                                    ']','-','F','+','F','+','F','[','+','F',']','-','F','+','F'};
    CHECK(result == expectedVector2);
}
