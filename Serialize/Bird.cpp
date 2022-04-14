//-----------------------------------------------------------------------------
// Real-Time Networking
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <string.h>
#include "Unused.h"
#include "Bird.h"

// constructor
Bird::Bird()
: x(0), y(0), s(0)
{
}

// destructor
Bird::~Bird()
{
	//printf("Bird destructor\n");
	delete this->s;
}


// specialized constructor
Bird::Bird( int _x, short _y)
	: x(_x), y(_y)
{
	this->s = new char[55]; // don't assume fixed size value...
 	const char *refText = "This is a test to have a very long string to Serialize";
	strcpy_s( this->s, 55, refText );
}

// accessor
int Bird::getX() const
{
	return this->x;
};

short Bird::getY() const
{
	return this->y;
};

// return a const read pointer to the string
const char *Bird::getS() const
{
	return this->s;
};

// Read from a buffer
void Bird::deserialize(const char* const buffer){
	size_t lenRef;
	memcpy(&lenRef, buffer, sizeof(size_t));
	this->s = new char [lenRef+1];
	for (int i = 0; i < lenRef + 1; i++) {
		(this->s)[i] = buffer[i + sizeof(size_t)];
	}
	memcpy(&(this->x), buffer + lenRef + 1 + sizeof(size_t), sizeof(int));
	memcpy(&(this->y), buffer + lenRef + 1 + sizeof(size_t) + sizeof(int), sizeof(int));
}

// Wri
void Bird::serialize( char * const buffer ) const
{
	size_t lenRef = strlen(s);
	memcpy(buffer, &lenRef, sizeof(size_t));

	for (size_t i = 0; i < lenRef+1; i++) {
		buffer[i+sizeof(size_t)] = s[i];
	}                

   memcpy(buffer+lenRef+1+sizeof(size_t), &(this->x), sizeof(int));
   memcpy(buffer + lenRef + 1 + sizeof(size_t)+sizeof(int), &(this->y), sizeof(int));
}

