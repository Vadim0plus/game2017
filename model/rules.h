//========================================================================
// rules.h : The interface for work with rules of game
//
// Part of the "GameCode2017"
//
// DESCRIPTION
//
// (c) Copyright 2017 Mendeleev University of Chemical Technology
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser GPL v3
// as published by the Free Software Foundation.
//
//========================================================================

#include <vector>
#include "world.h"

#ifndef Rule_H
#define Rule_H

class Rule {
public:
    /* Constructor ,The parameter pointer to world for bind with cells */
    Rule( World* p_World );

    /* Destructor, Free allocating resources */
    ~Rule();
    
    /* Predicate, Checks there are living cells in the world */
    bool hasLivingCells() const;

    /* Swaps new and old state of World */
    void swapWrds();
    
    /* Mutators :
     * Set up the rules for birth of cells and condition of stays( Not Death ) */
    void setRuleB( std::vector<int>& birth );
    void setRuleS( std::vector<int>& stay );
    
    /* Aplly Rules to the state of World */
    void applyRules();
    
private:
    /* Returns number of neighbors of given cell */
    int neighbours( int xx, int yy ) const;
    
    /* Acceptors: */
    bool inStay( int n ) const;
    bool inBirth( int n ) const;
    
private:
    int m_Width, m_Height;
    World *p_wrd, *p_wrdT;
    std::vector<int> m_Stay, m_Birth;
};

#endif
