//-----------------------------------------------------------------------------
//
// Real-Time Networking
//----------------------------------------------------------------------------- 

#ifndef FISH_H
#define FISH_H

struct apple
{
	// big four
	apple() = default;
	apple(const apple &) = default;
	apple & operator = (const apple &) = default;
	~apple() = default;

	void serialize(char* const buffer) const;
	void deserialize(const char* const buffer);

	int a;
	int b;
	int c;
};

struct orange
{
	// big four
	orange() = default;
	orange(const orange &) = default;
	orange & operator = (const orange &) = default;
	~orange() = default;

	//serealizing-deserealizing for greater experience
	void serialize(char* const buffer) const;
	void deserialize(const char* const buffer);

	float	x;
	int		a;
	char	b;
	char	d;
};

class Fish
{
public:
	
	// constructors
	Fish();
	Fish( const apple &inApple, const orange &inOrange, int inX, char inA, float inY);
	Fish(const Fish &) = default;

	// destructor
	~Fish();

	// assignment
	Fish & operator = (const Fish &) = delete;

	// accessors 
	float getY() const;
	int   getX() const;
	char  getA() const ;
	const apple & getApple() const;
	const orange & getOrange() const;

	// Read from a buffer
	void deserialize( const char * const buffer );

	// Write object to a buffer
	void serialize( char * const buffer ) const;

private:
	// data to serialize
	orange* pOrange;
	apple* pApple;
	float    y;
	int      x;
	char     a;
};

#endif