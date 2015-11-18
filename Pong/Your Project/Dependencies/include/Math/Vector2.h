////////////////////////////////////////////////////////////////
//Austin Morrell//
//October 25th 2015//
//Templated Vector2//
///////////////////////////////////////////////////////////////

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

template<typename T>
class Vector2
{

public:
	Vector2<T>();
	Vector2<T>(T x, T y);
	~Vector2<T>();
	Vector2 Adding(Vector2 &a, Vector2 &b);
	Vector2 Subtracting(Vector2 &a, Vector2 &b);
	Vector2 Multiplication(Vector2 &a, Vector2 &b);
	float Magnitude(Vector2 &a);
	Vector2 Normalising(Vector2 &a);
	T DotProduct(Vector2 &a, Vector2 &b);

	T x;
	T y;
};
#endif _VECTOR2_H_

template<typename T>
Vector2<T>::Vector2() 
{

}

template<typename T>
Vector2<T>::Vector2(T X, T Y)
{
	x = X;
	y = Y;
}

template<typename T>
Vector2<T>::~Vector2()
{

}

//Adding
template<typename T>
Vector2<T> Vector2<T>::Adding(Vector2 &a, Vector2 &b)
{
	Vector2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

//Subtracting
template<typename T>
Vector2<T> Vector2<T>::Subtracting(Vector2 &a, Vector2 &b)
{
	Vector2 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

//Multiplication
template<typename T>
Vector2<T> Vector2<T>::Multiplication(Vector2 &a, Vector2 &b)
{
	Vector2 c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return c;

}

//Magnitude
template<typename T>
float Vector2<T>::Magnitude(Vector2 &a)
{
	T A;
	float Thesqrt;
	A = (a.x * a.x) + (a.y * a.y);
	Thesqrt = sqrt(A);
	return Thesqrt;
}

//Normalising
template<typename T>
Vector2<T> Vector2<T>::Normalising(Vector2 &a)
{
	Vector2 c;
	T A;
	float Thesqrt;
	A = (a.x * a.x) + (a.y * a.y);
	Thesqrt = sqrt(A);
	c.x = (a.x / Thesqrt);
	c.y = (a.y / Thesqrt);
	return c;
}

//Dot Product
template<typename T>
T Vector2<T>::DotProduct(Vector2 &a, Vector2 &b)
{
	T A;
	A = (a.x * b.x) + (a.y * b.y);
	return A;
}