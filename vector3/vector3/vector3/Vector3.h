#ifndef _VECTOR3_H_
#define _VECTOR3_H_
#include <math.h>

template<class type>
class Vector3
{
	private:
		type x, y, z = 0;

	public:
		//constructors
		Vector3<type>(const type &_x, const type &_y, const type &_z): x(_x), y(_y), z(_z) {}
		Vector3<type>(const Vector3<type> &vector): x(vector.x), y(vector.y), z(vector.z)  {}
		Vector3<type>(): x(0),y(0),z(0){}

		//destructor
		~Vector3<type>(){}

		//Getters
		type GetVectX()const
		{
			return x;
		}

		type GetVectY()const
		{
			return y;
		}

		type GetVectZ()const
		{
			return x;
		}


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
		Vector3<type> Normalize()const
		{
			type absolute_value = (sqrt((x*x) + (y*y) + (z*z)));

			return (Vector3(x / absolute_value, y / absolute_value, z / absolute_value));
		}
		void Zero()
		{			
			x = 0;
			y = 0;
			z = 0;
		}
		bool IsZero()const
		{
			return (x == 0 && y == 0 && z == 0);
		}
		type distance(const Vector3 &vect1)const
		{
			return (sqrt(((x - vect1.x)*(x - vect1.x)) + ((y - vect1.y)*(y - vect1.y)) + ((z - vect1.z)*(z - vect1.z))));
		}


		//Utils

		void PrintVector()
		{
			std::cout << x <<","<<  y <<","<<  z << std::endl;
		}
};




#endif
