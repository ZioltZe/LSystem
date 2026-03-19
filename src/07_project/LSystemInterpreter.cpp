#include "07_project/LSystemInterpreter.h"

// Constructor
template<typename SymbolType>
LSystemInterpreter<SymbolType>::LSystemInterpreter(const vector<SymbolType> &axiom,
                                                   const unordered_set<Production<SymbolType>> &productions,
                                                   const unordered_set<SymbolType> &alphabet):
                                                   axiom(axiom), productions(productions), alphabet(alphabet)
{
    unordered_set<SymbolType> allPredecessors;
    for (const auto &production : productions)
    {
        // ! CHECK IF PRODUCTION IS VALID
        if(!isValidProduction(production, alphabet))
            throw invalid_argument("ERROR : Productions are not valid");

        // ! CHECK IF PREDECESSORS ARE UNIQUE
        if(allPredecessors.find(production.getPredecessor()) != allPredecessors.end())
            throw invalid_argument("ERROR : Predecessors are not unique");

        allPredecessors.insert(production.getPredecessor());    // Get all the predecessors in an unordered set
    }

    // ! CHECK IF ALL SYMBOLS IN ALPHABET HAVE A PRODUCTION
    for (const auto &symbol : alphabet)
    {
        if(allPredecessors.find(symbol) == allPredecessors.end())
            throw invalid_argument("ERROR : Not all symbols have a production");
    }

    currentState = axiom;       // Set the current state of the system to the axiom when the system is created
}

// Explicit instantiation for char type
template class LSystemInterpreter<char>;

// Reset method
template<typename SymbolType>
void LSystemInterpreter<SymbolType>::reset(){ currentState = axiom; }

// Single Iteration method
template<typename SymbolType>
vector<SymbolType> LSystemInterpreter<SymbolType>::operator()() const
{
    vector<SymbolType> resultVector;

    for (const auto &symbol : currentState)         // Symbol by Symbol
    {
        for(const auto &production : productions)   // Search for the production of that symbol
        {
            if(production.getPredecessor() == symbol)
            {
                string successor = production.getSuccessor();                               // Get the successor of that production
                copy(successor.begin(), successor.end(), back_inserter(resultVector));      // Copy the successor at the end of the result vector
            }
        }
    }

    currentState = resultVector;                    // Save the result as the current state

    return resultVector;
}

