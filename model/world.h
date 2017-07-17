//========================================================================
// world.h : The interface for work with cells
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

typedef unsigned char byte;

#ifndef World_H
#define World_H

class World
{
public:
    /* Constructor with parameters that defines Width and Height of world */
	World(int x, int y);

    /* Destructor, free allocated resources */
	~World();

    /* Acceptors */
	int getWidth() const;
	int getHeight() const;
    /* Returns cell value of world */
	byte at(int x, int y) const;

    /* Mutators*/
    /* Set up cell value */
	void set(int x,int y, byte c);
	
    /* Swap state of World */
	void swap(World* p_world);

private:
    int m_Width; // Width of World
    int m_Height; // Height of World
    byte* p_Cells; // Contain the values of cells
};
#endif
	
