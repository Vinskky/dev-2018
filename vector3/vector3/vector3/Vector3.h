#ifndef _VECTOR3_H_
#define _VECTOR3_H_
#include <math.h>

template<class TYPE>
class Vector3
{
	public:
		
		TYPE x, y, z = 0.0f;
		//constructors
		Vector3(const TYPE &_x, const TYPE &_y, const TYPE &_z): x(_x), y(_y), z(_z) {}
		Vector3(const Vector3 &vector): x(vector.x), y(vector.y), z(vector.z)  {}
		Vector3(){}

		//destructor
		~Vector3(){}

		//operators
		Vector3 operator + (const Vector3 &vector) const 
		{
			return (Vector3(x + vector.x, y + vector.y, z + vector.z));
		}
		Vector3 operator - (const Vector3 &vector)const
		{
			return (Vector3(x - vector.x, y - vector.y, z - vector.z));
		}
		void operator += (const Vector3 &vector)
		{
			x += vector.x;	
			y += vector.y;	
			z += vector.z;
		}
		void operator -= (const Vector3 &vector)
		{
			x -= vector.x;	
			y -= vector.y;	
			z -= vector.z;
		}
		bool operator == (const Vector3 &vector)const
		{
			return (x == vector.x && y == vector.y && z == vector.z);
		}

		//methods
		Vector3 IsNormalized()const
		{
			TYPE absolute_value = (sqrt((x*x) + (y*y) + (z*z)));
			return (Vector3(x / absolute_value, y / absolute_value, z / absolute_value));
		}
		void Normalize()
		{
			TYPE absolute_value = (sqrt((x*x) + (y*y) + (z*z)));
			x =/ absolute_value;
			y =/ absolute_value;
			z =/ absolute_value;
		}
		void Zero()
		{			
			x = y = z = 0.0f;
		}
		bool IsZero()const
		{
			return (x == 0.0f && y == 0.0f && z == 0.0f);
		}
		TYPE distance(const Vector3 &vect1)const
		{
			return (sqrt(((x - vect1.x)*(x - vect1.x)) + ((y - vect1.y)*(y - vect1.y)) + ((z - vect1.z)*(z - vect1.z))));
		}

		Vector3 distance_squared(const Vector3 &vect)const
		{

		}

		//Utils

		void PrintVector()const
		{
			std::cout << x <<","<<  y <<","<<  z << std::endl;
		}
};




#endif
