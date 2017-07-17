//========================================================================
// cellular.h : The interface, contain methods for setup configurations,iterations,and display
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

#include "rules.h"
#include "world.h"

#ifndef Cellular_H
#define Cellular_H

class Cellular {
public:
    /* Constructor, defines world has Width and Height */
    Cellular( int w, int h );

    /* Destructor, free allocating resources  */
    ~Cellular();
    
    /* Set up the kind of configuration:
    1 - Conway,     2 - Amoeba
    3 - life34,     4 - maze  */
    void setup( int r );

    /* Generates the new state of world */
    void generation();

    /* Returns two-dimensial array with cell values */
    int** display_m();
    
private:
    Rule *p_Rule;
    World *p_World;
    int** image;
    int gen; 
};

#endif
