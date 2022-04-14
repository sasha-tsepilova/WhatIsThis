//-----------------------------------------------------------------------------
//
// Real-Time Networking
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <string.h>
#include "Unused.h"
#include "Fish.h"

// constructor
Fish::Fish()
: x(0),a(0),y(0.0f),pApple(0),pOrange(0)
{

}

Fish::Fish( const apple &inApple, const orange &inOrange, int inX, char inA, float inY)
{
	this->pApple = new apple(inApple);
	this->pOrange = new orange(inOrange);
	this->x = inX;
	this->a = inA;
	this->y = inY;
}


// destructor
Fish::~Fish()
{
	//printf("fish destructor\n");
	delete this->pApple;
	delete this->pOrange;
}


float Fish::getY() const
{
	return this->y;
}

int Fish::getX() const
{
	return this->x;
}

char Fish::getA() const 
{
	return this->a;
}

const apple &Fish::getApple() const 
{
	return *(this->pApple);
}

const orange &Fish::getOrange() const
{
	return *(this->pOrange);
}

// Read from a buffer
void Fish::deserialize( const char * const buffer ) 
{
	this->pOrange = new orange();
	memcpy(this->pOrange, buffer, sizeof(orange));
	this->pApple = new apple();
	memcpy(this->pApple, buffer + sizeof(orange), sizeof(apple));
	memcpy(&(this->y), buffer + sizeof(orange) + sizeof(apple), sizeof(float));
	memcpy(&(this->x), buffer + sizeof(orange) + sizeof(apple) + sizeof(float), sizeof(int));
	memcpy(&(this->a), buffer + sizeof(orange) + sizeof(apple) + sizeof(float) + sizeof(int), sizeof(char));
}

// Write object to a buffer
void Fish::serialize( char * const buffer ) const
{
	this->getOrange().serialize(buffer);
	this->getApple().serialize(buffer + sizeof(orange));
	memcpy(buffer + sizeof(orange) + sizeof(apple), &(this->y), sizeof(float));
	memcpy(buffer + sizeof(orange) + sizeof(apple) + sizeof(float), &(this->x), sizeof(int));
	memcpy(buffer + sizeof(orange) + sizeof(apple) + sizeof(float)+sizeof(int), &(this->a), sizeof(char));
}

void apple::serialize(char* const buffer) const {
	memcpy(buffer, this, sizeof(apple));
}

void apple::deserialize(const char* const buffer) {
	memcpy(this, buffer, sizeof(apple));
}

void orange::serialize(char* const buffer) const {
	memcpy(buffer, this, sizeof(orange));
}

void orange::deserialize(const char* const buffer)  {
	memcpy(this, buffer, sizeof(orange));
}
