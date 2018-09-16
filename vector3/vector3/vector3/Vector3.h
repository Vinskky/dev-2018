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
		Vector3<type>(const type &x, const type &y, const type &z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Vector3<type>(const Vector3<type> &vector)
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}
		Vector3<type>()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		//destructor
		~Vector3<type>(){}

		//operators
		Vector3<type> operator + (const Vector3 &vector) // vector1 + vector2
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;

			return (*this);
		}
		Vector3<type> operator - (const Vector3 &vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			return (*this);
		}
		Vector3<type> operator += (const Vector3 &vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;

			return (*this);
		}
		Vector3<type> operator -= (const Vector3 &vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			return (*this);
		}
		bool operator == (const Vector3 &vector)
		{
			return (x == vector.x && y == vector.y && z == vector.z);
		}

		//methods
		Vector3<type> Normalize()const
		{
			type absolute_value = (sqrt((x*x) + (y*y) + (z*z)));

			return (x / absolute_value, y / absolute_value, z / absolute_value);
		}
		Vector3<type> Zero()const
		{
			x = 0;
			y = 0;
			z = 0;
			return (*this);
		}
		bool IsZero()const
		{
			return (x == 0 && y == 0 && z == 0);
		}
		type distance(const Vector3 &vect1, const Vector3 &vect2)const
		{
			return (sqrt(((vect1.x - vect2.x)*(vect1.x - vect2.x)) + ((vect1.y - vect2.y)*(vect1.y - vect2.y)) + ((vect1.z - vect2.z)*(vect1.z - vect2.z))));
		}

};




#endif
