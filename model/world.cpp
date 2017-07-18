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
        int s = m_Width * m_Height;
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

void WorldTest::TestGetWidth()
{
    World worldtest = new World(10,10);
    int ans1 = 10;
    int ans2 = worldtest.getWidth();
    if ( ans1 == ans2)
        std::cout << "TestGetWidth:OK\n"
    else
                     std::cout << "TestGetWidth:FALSE\n"

}

void WorldTest::TestGetHeight();
    {
        World worldtest = new World(15,10);
        int ans3=10;
        int ans4=worldtest.getHeight();
        if (ans3 == ans4)
            std::cout << "TestGetHeight:OK\n"
else
                         std::cout << "TestGetHeight:FALSE\n"

    }

 void WorldTest::TestAt();
        {
        World worldtest = new World(15,10);
        p_wtestorld->set( 6, 1, 1 ); p_World->set( 7, 2, 1 );
        p_worldtest->set( 5, 3, 1 ); p_World->set( 6, 3, 1 );
        p_worldtest->set( 7, 3, 1 );
        int ans1=1;
        int ans2=WorldTest.at();
        if (ans1 == ans2)
            std::cout << "TestAt:OK\n"
else
                         std::cout << "TestAt:FALSE\n"

        }

void WorldTest::TestSet();
        {
            World worldtest = new World(10,10);
            WorldTest.set(1,1,1);
           int ans1=1;
           int ans2=worldtest.at(1,1)

           if (ans1 == ans2)
               std::cout << "TestSet:OK\n"
else
                            std::cout <<"TestSet:FALSE\n"

        }

