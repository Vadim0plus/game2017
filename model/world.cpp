//========================================================================
// world.cpp : Implementation of interface for work with cells
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

#include "world.h"
#include <cstring>

World::World( int x, int y ) : m_Width( x ), m_Height( y )
{
        int s = m_Width * m_Height * sizeof( byte );
        p_Cells = new byte[s];
        memset( p_Cells, 0, s );
}
    
World::~World()
{
        delete [] p_Cells;
}
    
int World::getWidth() const
{
        return m_Width;
}
    
int World::getHeight() const
{
        return m_Height;
}
    
byte World::at( int x, int y ) const
{
        return p_Cells[ x + y * m_Width ];
}
    
void World::set( int x, int y, byte c )
{
        p_Cells[ x + y * m_Width ] = c;
}
    
void World::swap( World* p_World )
{
        memcpy( p_Cells, p_World->p_Cells, m_Width * m_Height * sizeof( byte ) );
}
