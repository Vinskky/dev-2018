#include <iostream>
#include <stdio.h>
#include "Vector3.h"



int main()
{
	//constructors
	std::cout << "constructors for 4 types of vectors" << std::endl;
	Vector3<float> vect1;
	Vector3<float> vect2(1.0f, 2.0f, 3.0f);
	Vector3<float> vect3(vect1);
	Vector3<float> vect4(4.0f, 3.0f, 2.0f);
	vect1.PrintVector();
	vect2.PrintVector();
	vect3.PrintVector();
	vect4.PrintVector();
	//operator +=
	std::cout << "vect2 += vect4" << std::endl;
	vect2 += vect4;
	vect2.PrintVector();
	//operator -=
	std::cout << "vect4 -= vect2" << std::endl;
	vect4 -= vect2;
	vect4.PrintVector();
	//operator ==
	std::cout << "operator == for vect1 and vect3" << std::endl;
	if (vect1 == vect3)
		std::cout << "vect1 & vect3 are equals" << std::endl;

	//operator +
	std::cout << "operator + with a new vector (4,5,2) " << std::endl;
	Vector3<float> a(4.0f, 5.0f, 2.0f);
	a = vect1 + vect2;
	a.PrintVector();
	std::cout << "vect4 normalized" << std::endl;
	a = vect4.IsNormalized();
	a.PrintVector();
	std::cout << "vect4 normalized set to 0" << std::endl;
	a.Zero();
	a.PrintVector();
	std::cout << "cheking if IsZero() method works" << std::endl;
	if (a.IsZero())
		std::cout << "vector a its (0,0,0)" << std::endl;
	std::cout << "distance between vect2 and vect4" << std::endl;
	double distance = vect2.distance(vect4);
	std::cout << distance << std::endl;




	getchar();
	return 0;
}