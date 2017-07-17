//========================================================================
// cellular.cpp : The interface implementation,
//                contain methods for setup configurations,iterations,and display
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

#include "cellular.h"
#include <vector>
#include <stdlib.h>

Cellular::Cellular( int w, int h ) : p_Rule( 0 )
{
        p_World = new World( w, h );
        
        int m_Width = p_World->getWidth();
        int m_Height = p_World->getHeight();
        image = new int*[m_Height];
        for(int i = 0; i < m_Height; i++)
            image[i] = new int[m_Width];
}

Cellular::~Cellular() 
{
		
        for(int i = 0; i < (p_World->getHeight() ); ++i)
    		delete [] image[i];
		delete [] image;
		
		if( p_Rule ) delete p_Rule;
        delete p_World;
}

void Cellular::setup( int r ) 
{
        p_Rule = new Rule( p_World );
        gen = 1;
        std::vector<int> t;
        switch( r ) {
            case 1: // conway
                t.push_back( 2 ); t.push_back( 3 ); p_Rule->setRuleS( t );
                t.clear(); t.push_back( 3 ); p_Rule->setRuleB( t );
                break;
            case 2: // amoeba
                t.push_back( 1 ); t.push_back( 3 ); t.push_back( 5 ); t.push_back( 8 ); p_Rule->setRuleS( t );
                t.clear(); t.push_back( 3 ); t.push_back( 5 ); t.push_back( 7 ); p_Rule->setRuleB( t );
                break;
            case 3: // life34
                t.push_back( 3 ); t.push_back( 4 ); p_Rule->setRuleS( t );
                p_Rule->setRuleB( t );
                break;
            case 4: // maze
                t.push_back( 1 ); t.push_back( 2 ); t.push_back( 3 ); t.push_back( 4 ); t.push_back( 5 ); p_Rule->setRuleS( t );
                t.clear(); t.push_back( 3 ); p_Rule->setRuleB( t );
                break;
        }
 
        /* just for test - shoud read from a file */
        /* GLIDER */
        p_World->set( 6, 1, 1 ); p_World->set( 7, 2, 1 );
        p_World->set( 5, 3, 1 ); p_World->set( 6, 3, 1 );
        p_World->set( 7, 3, 1 );
        /* BLINKER */
        p_World->set( 1, 3, 1 ); p_World->set( 2, 3, 1 );
        p_World->set( 3, 3, 1 );
        /******************************************/
}
/*
void Cellular::display() 
{
        system( "cls" );
        int m_Width = p_World->getWidth();
        int m_Height = p_World->getHeight();
        
        std::cout << "+" << std::string( m_Width, '-' ) << "+\n";
        for( int y = 0; y < m_Height; y++ ) {
            std::cout << "|";
            for( int x = 0; x < m_Width; x++ ) {
                if( p_World->at( x, y ) ) std::cout << "#";
                else std::cout << ".";
            }
            std::cout << "|\n";
        }
        std::cout << "+" << std::string( m_Width, '-' ) << "+\n";
        std::cout << "Generation: " << gen << "\n\nPress [RETURN] for the next generation...";
        std::cin.get();
}*/

int** Cellular::display_m()
{
        int m_Width = p_World->getWidth();
        int m_Height = p_World->getHeight();
        for( int y = 0; y < m_Height; y++ )
            for( int x = 0; x < m_Width; x++ )
                if( p_World->at( x, y ) )
                    image[y][x] = 1;
                else
                    image[y][x] = 0;
        return image;

}
    
void Cellular::generation() 
{
            p_Rule->applyRules();
            p_Rule->swapWrds();
            gen++;
}
