#pragma once

#include "07_project/Production.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename SymbolType>
class LSystemInterpreter
{
    public:
        // Constructor
        LSystemInterpreter(const vector<SymbolType>& axiom,
                           const unordered_set<Production<SymbolType>>& productions,
                           const unordered_set<SymbolType>& alphabet);
        // Reset method
        void reset();
        // Single Iteration method
        vector<SymbolType> operator() () const;

    private:
        const   vector<SymbolType>& axiom;
        const   unordered_set<Production<SymbolType>>& productions;
        const   unordered_set<SymbolType>& alphabet;
        mutable vector<SymbolType> currentState;
};

