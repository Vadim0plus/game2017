#include "world.h"
#include <cstring>

World::World( int x, int y ) : m_Width( x ), m_Height( y ) {
        int s = m_Width * m_Height;
        p_Cells = new byte[s];
        memset( p_Cells, 0, s );
    }
    
World::~World() {
        delete [] p_Cells;
    }
    
int World::getWidth() const {
        return m_Width;
    }
    
int World::getHeight() const {
        return m_Height;
    }
    
byte World::at( int x, int y ) const {
        return p_Cells[ x + y * m_Width ];
    }
    
void World::set( int x, int y, byte c ) {
        p_Cells[ x + y * m_Width ] = c;
    }
    
void World::swap( World* p_World ) {
        memcpy( p_Cells, p_World->p_Cells, m_Width * m_Height * sizeof( byte ) );
    }
