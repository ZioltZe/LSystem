#pragma once

#include <iostream>
#include <unordered_set>

using namespace std;

template <typename  SymbolType>
class Production
{
public:
    // Constructor
    Production(SymbolType predecessor, const std::string &successor);
    // Getters
    SymbolType getPredecessor() const;
    const string &getSuccessor() const;
    // Hash function for Production
    static size_t hash(const Production<SymbolType>& production);
    // Equality comparison for Production
    static bool equal(const Production<SymbolType>& lhs, const Production<SymbolType>& rhs);

private:
    SymbolType predecessor;
    string successor;
};

// checking if productions are valid method
template <typename  SymbolType>
bool isValidProduction(const Production<SymbolType>& production, const unordered_set<SymbolType> & alphabet);

// To use unordered_set : insert method
namespace std
{
    // Hash specialization for Production
    template<typename SymbolType>
    struct hash<Production <SymbolType>>
    {
        size_t operator()(const Production<SymbolType>& production) const
        {
            return Production<SymbolType>::hash(production);
        }
    };

    // Equality comparison for Production
    template<typename SymbolType>
    struct equal_to<Production <SymbolType>>
    {
        bool operator()(const Production<SymbolType>& lhs, const Production<SymbolType>& rhs) const
        {
            return Production<SymbolType>::equal(lhs, rhs);
        }
    };
}