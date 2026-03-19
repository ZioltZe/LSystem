#include "07_project/Production.h"

// Constructor
template<typename SymbolType>
Production<SymbolType>::Production(SymbolType predecessor, const string &successor):predecessor(predecessor),
                                                                                    successor(successor){}
// Explicit instantiation for char type
template class Production<char>;

// checking if productions are valid method with a time complexity of O(N), where N = total number of symbols (successor + predecessor)
template<typename SymbolType>
bool isValidProduction(const Production<SymbolType> &production, const unordered_set<SymbolType> &alphabet)
{
    string allSymbols = production.getSuccessor() + production.getPredecessor();    // Getting all symbols
    for (char & allSymbol : allSymbols)
    {
        if(alphabet.find(allSymbol)==alphabet.end())                                // Check if the symbol is not in the given alphabet
            return false;                                                           // Return false if it's not in the alphabet
    }
    return true;                                                                    // Return true when all the symbols are in the alphabet
}

// Explicit instantiation for isValidProduction
template bool isValidProduction(const Production<char> &production, const unordered_set<char> &alphabet);

// Predecessor getter
template<typename SymbolType>
SymbolType Production<SymbolType>::getPredecessor() const { return predecessor; }

// Successor getter
template<typename SymbolType>
const string &Production<SymbolType>::getSuccessor() const { return successor; }

// Hash function definition
template<typename SymbolType>
size_t Production<SymbolType>::hash(const Production<SymbolType>& production)
{
    return std::hash<SymbolType>{}(production.getPredecessor()) ^ (std::hash<string>{}(production.getSuccessor()) << 1);
}

// Equality comparison definition
template<typename SymbolType>
bool Production<SymbolType>::equal(const Production<SymbolType>& lhs, const Production<SymbolType>& rhs)
{
    return lhs.getPredecessor() == rhs.getPredecessor() && lhs.getSuccessor() == rhs.getSuccessor();
}
