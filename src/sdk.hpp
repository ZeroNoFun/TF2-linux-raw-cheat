#pragma once
///////
#include "ifs.hpp"
#include "AltVMT.hpp"
#include <math.h>

#define LocalPlayerIndex Interfaces::engine->GetLocalPlayer()

/*Vector*/
class Vector
{
public:
	Vector( void )
	{
		x = y = z = 0.0f;
	}

	Vector( float X, float Y, float Z )
	{
		x = X; y = Y; z = Z;
	}

	Vector( float* v )
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	Vector( const float* v )
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	Vector( const Vector& v )
	{
		x = v.x; y = v.y; z = v.z;
	}

	Vector& operator=( const Vector& v )
	{
		x = v.x; y = v.y; z = v.z; return *this;
	}

	float& operator[]( int i )
	{
		return ( ( float* )this )[i];
	}

	float operator[]( int i ) const
	{
		return ( ( float* )this )[i];
	}

	Vector& operator+=( const Vector& v )
	{
		x += v.x; y += v.y; z += v.z; return *this;
	}

	Vector& operator-=( const Vector& v )
	{
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	Vector& operator*=( const Vector& v )
	{
		x *= v.x; y *= v.y; z *= v.z; return *this;
	}

	Vector& operator/=( const Vector& v )
	{
		x /= v.x; y /= v.y; z /= v.z; return *this;
	}

	Vector& operator+=( float v )
	{
		x += v; y += v; z += v; return * this;
	}

	Vector& operator-=( float v )
	{
		x -= v; y -= v; z -= v; return *this;
	}

	Vector& operator*=( float v )
	{
		x *= v; y *= v; z *= v; return *this;
	}

	Vector& operator/=( float v )
	{
		x /= v; y /= v; z /= v; return *this;
	}

	Vector operator+( const Vector& v ) const
	{
		return Vector( x + v.x, y + v.y, z + v.z );
	}

	Vector operator-( const Vector& v ) const
	{
		return Vector( x - v.x, y - v.y, z - v.z );
	}

	Vector operator*( const Vector& v ) const
	{
		return Vector( x * v.x, y * v.y, z * v.z );
	}

	Vector operator/( const Vector& v ) const
	{
		return Vector( x / v.x, y / v.y, z / v.z );
	}

	Vector operator+( float v ) const
	{
		return Vector( x + v, y + v, z + v );
	}

	Vector operator-( float v ) const
	{
		return Vector( x - v, y - v, z - v );
	}

	Vector operator*( float v ) const
	{
		return Vector( x * v, y * v, z * v );
	}

	Vector operator/( float v ) const
	{
		return Vector( x / v, y / v, z / v );
	}

	void Set( float X = 0.0f, float Y = 0.0f, float Z = 0.0f )
	{
		x = X; y = Y; z = Z;
	}

	float Length( void ) const
	{
		return sqrtf( x * x + y * y + z * z );
	}

	float LengthSqr( void ) const
	{
		return ( x * x + y * y + z * z );
	}

	float Length2d( void ) const
	{
		return sqrtf( x * x + y * y );
	}

	float Length2dSqr( void ) const
	{
		return ( x * x + y * y );
	}

	float DistTo( const Vector& v ) const
	{
		return ( *this - v ).Length( );
	}

	float DistToSqr( const Vector& v ) const
	{
		return ( *this - v ).LengthSqr( );
	}

	float Dot( const Vector& v ) const
	{
		return ( x * v.x + y * v.y + z * v.z );
	}

	Vector Cross( const Vector& v ) const
	{
		return Vector( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x );
	}

	bool IsZero( void ) const
	{
		return ( x > -0.01f && x < 0.01f &&
			y > -0.01f && y < 0.01f &&
			z > -0.01f && z < 0.01f );
	}

	void Init(float _x = 0, float _y = 0, float _z = 0)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}

public:
	float x, y, z;
};


/*~Vector*/

/*Color*/

class Color
{
public:
	Color();
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha);


	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t alpha;
};

inline Color::Color()
{
	r = g = b = alpha = 0;
}

inline Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _alpha)
{
	r = _r;
	g = _g;
	b = _b;
	alpha = _alpha;
}

/*~Color*/

/*Hooks*/
namespace Hooks
{
	void hooked_paint_traverse(void* thisptr, unsigned int vgui_panel, bool force_repaint, bool allow_force);
	void hooked_create_move();

	void Init();
}
/*Hooks*/

/*Interfaces*/
namespace Interfaces
{
	extern IBaseClientDLL* client;
	extern IEntityList* entitylist;
	extern IVEngineClient* engine;
	extern ISurface* surface;
	extern IVPanel* panel;

	void Init();
}
/*Interfaces*/

/*Netvars*/
namespace Netvars
{
	void Init();
	int GetNetvar(const char* dt, const char* m);
}

class RecvProp;
class RecvTable;

class RecvProxyData
{
public:
	const RecvProp*	m_pRecvProp;
	int				m_iElement;
	int				m_ObjectID;
};

class RecvProp
{
public:
	char*		m_pVarName;
	int			m_RecvType;
	int			m_Flags;
	int			m_StringBufferSize;
	bool		m_bInsideArray;
	void*		m_pExtraData;
	RecvProp*	m_pArrayProp;
	void*		m_ArrayLengthProxy;
	void*		m_ProxyFn;
	void*		m_DataTableProxyFn;
	RecvTable*	m_pDataTable;
	int			m_Offset;
	int			m_ElementStride;
	int			m_nElements;
	const char*	m_pParentArrayPropName;
};

class RecvTable
{
public:
	RecvProp*	m_pProps;
	int			m_nProps;
	void*		m_pDecoder;
	char*		m_pNetTableName;
	bool		m_bInitialized;
	bool		m_bInMainList;
};

class ClientClass
{
public:
	char			header[8];
	const char*		m_pNetworkName;
	RecvTable*		m_pRecvTable;
	ClientClass*	m_pNext;
	int				m_ClassID;
};

/*~Netvars*/

/*Offsets*/
struct Offsets
{
	uint32_t m_iHealth;
	uint32_t m_vecOrigin;
	uint32_t m_iTeamNum;
	uint32_t m_lifeState;
};
extern Offsets offsets;
/*~Offsets*/

/*Drawing*/
namespace Drawings
{
	void DrawFilledRect(int x, int y, int w, int h, Color col);
	void DrawOutlinedRect(int x, int y, int w, int h, Color col);
}
/*~Drawing*/

/*Utils*/
namespace Utils
{
	extern int ScreenSizeW;
	extern int ScreenSizeH;

	bool WorldToScreen(Vector &vOrigin, Vector &vScreen);

	void GrabOffsets();
	void Init();
}
/*~Utils*/

/*Player*/
class CPlayer : public IClientEntity
{
    template<class T>
    inline T GetValue(int offset)
    {
        return *(T*)((uint32_t)this + offset);
    }

public:
	int GetHealth()
	{
		return GetValue<int>(offsets.m_iHealth);
	}

	Vector GetOrigin()
	{
		return GetValue<Vector>(offsets.m_vecOrigin);
	}

	int GetTeam()
	{
		return GetValue<int>(offsets.m_iTeamNum);
	}

	uint8_t GetLifeState()
	{
		return GetValue<uint8_t>(offsets.m_lifeState);
	}
};
/*~Player*/