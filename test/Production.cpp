#define CATCH_CONFIG_MAIN
#include "catch2/catch.h"
#include "07_project/Production.h"

TEST_CASE("TestProduction1", "[isValidProduction]")
{
    Production production1('A', "A[+F]-B");

    unordered_set<char> alphabet1 = {'F', '+', '-', '[', ']', 'A', 'B'};

    CHECK(isValidProduction(production1, alphabet1));
}

TEST_CASE("TestProduction2", "[isValidProduction]")
{
    Production production1('F', "F[+F]-F");
    Production production2('+', "+F[F]-F");
    Production production3('A', "F[+F]-F");
    Production production4('F', "F[+B]-F");

    unordered_set<char> alphabet1 = {'F', '+', '-', '[', ']'};
    unordered_set<char> alphabet2 = {'F', '+', '-', '[', ']', 'A'};
    unordered_set<char> alphabet3 = {'F', '+', '-', '[', ']', 'B'};
    unordered_set<char> alphabet4 = {'F', '-', '[', ']'};

    CHECK(isValidProduction(production1, alphabet1));
    CHECK(isValidProduction(production1, alphabet2));
    CHECK(isValidProduction(production1, alphabet3));
    CHECK(!isValidProduction(production1, alphabet4));  // NOT VALID

    CHECK(isValidProduction(production2, alphabet1));
    CHECK(isValidProduction(production2, alphabet2));
    CHECK(isValidProduction(production2, alphabet3));
    CHECK(!isValidProduction(production2, alphabet4));  // NOT VALID

    CHECK(!isValidProduction(production3, alphabet1));  // NOT VALID
    CHECK(isValidProduction(production3, alphabet2));
    CHECK(!isValidProduction(production3, alphabet3));  // NOT VALID
    CHECK(!isValidProduction(production3, alphabet4));  // NOT VALID

    CHECK(!isValidProduction(production4, alphabet1));  // NOT VALID
    CHECK(!isValidProduction(production4, alphabet2));  // NOT VALID
    CHECK(isValidProduction(production4, alphabet3));
    CHECK(!isValidProduction(production4, alphabet4));  // NOT VALID
}
