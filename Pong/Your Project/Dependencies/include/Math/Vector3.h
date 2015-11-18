/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//File: Vector3.h
//Author: Andrew Miller
//Date Created: 10/22/2015
//Brief: This is the Vector3 header file. It contains the Templated Vector3 Class and its prototypes and definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

//Templates the Vector3 Class
template<typename T>
class Vector3
{

public:
	//Constructor
	Vector3<T>();
	//Overloaded Constructor
	Vector3<T>(T x, T y, T z);
	//Destructor
	~Vector3<T>();
	//Add Vectors
	Vector3 Add(Vector3 &a, Vector3 &b);
	//Subtract Vectors
	Vector3 Sub(Vector3 &a, Vector3 &b);
	//Multiply Vectors
	Vector3 Multiply(Vector3 &a, Vector3 &b);
	//Magnitude of Vectors
	float Mag(Vector3 &a);
	//Normalise Vectors
	Vector3 Normalise(Vector3 &a);
	//Dot Product Vector
	T Dot(Vector3 &a, Vector3 &b);
	//Cros Product Vector
	Vector3 Cross(Vector3 &a, Vector3 &b);

	//Variables for coordinates
	int x;
	int y;
	int z;
};




#endif _VECTOR3_H_

//Constructor
template<typename T>
Vector3<T>::Vector3()
{


}

//Overloaded Constructor
template<typename T>
Vector3<T>::Vector3(T X, T Y, T Z)
{//Initialize variables to passed in coordinates
	x = X;
	y = Y;
	z = Z;


}
//Destructor
template<typename T>
Vector3<T>::~Vector3()
{


}

//Add Vectors
template<typename T>
Vector3<T> Vector3<T>::Add(Vector3 &a, Vector3 &b)
{
	//New Vector variable
	Vector3 c;
	//Add each x coordinate of 2 passed in vectors then store value into x value of new vector
	c.x = a.x + b.x;
	//Add each y coordinate of 2 passed in vectors then store value into y value of new vector
	c.y = a.y + b.y;
	//Add each z coordinate of 2 passed in vectors then store value into z value of new vector
	c.z = a.z + b.z;
	//Return new vector
	return c;
}

//Subtract Vectors
template<typename T>
Vector3<T> Vector3<T>::Sub(Vector3 &a, Vector3 &b)
{
	//New Vector variable
	Vector3 c;
	//Subtract each x coordinate of 2 passed in vectors then store value into x value of new vector
	c.x = a.x - b.x;
	//Subtract each y coordinate of 2 passed in vectors then store value into y value of new vector
	c.y = a.y - b.y;
	//Subtract each z coordinate of 2 passed in vectors then store value into z value of new vector
	c.z = a.z - b.z;
	//Return new vector
	return c;
}

//Magnitude of Vectors
template<typename T>
float Vector3<T>::Mag(Vector3 &a)
{//Variable used to store squared values of passed in vector values
	T Asquared;
	//Variable to hold square root value
	float Asqrt;
	//Square each coordinate and all together then store into new variable
	Asquared = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
	//Get the square root of the variable and store into a new variable
	Asqrt = sqrt(Asquared);

	//Return Magnitude as a float to be more precise
	return Asqrt;

}

//Normalise Vector
template<typename T>
Vector3<T> Vector3<T>::Normalise(Vector3 &a)
{//New Vector variable
	Vector3 c;
	//Variable used to store squared values of passed in vector values
	T Asquared;
	//Variable to hold square root value
	float Asqrt;

	//Square each coordinate and all together then store into new variable
	Asquared = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);

	//Get the square root of the variable and store into a new variable
	Asqrt = sqrt(Asquared);
	//Divide passed in x value by the square root value and get the new value and store it into x of new vector
	c.x = (a.x / Asqrt);
	//Divide passed in y value by the square root value and get the new value and store it into y of new vector
	c.y = (a.y / Asqrt);
	//Divide passed in z value by the square root value and get the new value and store it into z of new vector
	c.z = (a.z / Asqrt);

	//Return the normalised vector
	return c;

}

//Multiply Vectors
template<typename T>
Vector3<T> Vector3<T>::Multiply(Vector3 &a, Vector3 &b)
{//New Vector variable
	Vector3 c;
	//Square each x coordinate of 2 passed in vectors then store value into x value of new vector
	c.x = a.x * b.x;
	//Square each y coordinate of 2 passed in vectors then store value into y value of new vector
	c.y = a.y * b.y;
	//Square each z coordinate of 2 passed in vectors then store value into z value of new vector
	c.z = a.z * b.z;
	//Return new vector
	return c;

}

//Dot Product Vector
template<typename T>
T Vector3<T>::Dot(Vector3 &a, Vector3 &b)
{//Multiply the passed in x values and the y values then add them together and return the product
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);

}

//Cross Product Vector
template<typename T>
Vector3<T> Vector3<T>::Cross(Vector3 &a, Vector3 &b)
{//Variable just used for temporary purposes
	Vector3 c;
	//Variable just used for temporary purposes
	Vector3 t;
	//Variable to store the Cross product 
	Vector3 Cross;
	//Multiply values then store in x values
	c.x = a.y * b.z;
	t.x = a.z * b.y;
	//Subtract the products and store new value in x of new vector
	Cross.x = c.x - t.x;
	//Multiply values then store in y values
	c.y = a.z * b.x;
	t.y = a.x * b.z;
	//Subtract the products and store new value in y of new vector
	Cross.y = c.y - t.y;
	//Multiply values then store in z values
	c.z = a.x * b.y;
	t.z = a.y * b.x;
	//Subtract the products and store new value in z of new vector
	Cross.z = c.z - t.z;
	//Return cross product
	return Cross;

}
