//Christopher Bass
//CECS 302
//Problem 1.16
//9/17/14

#include <iostream>    
#include <vector>
#include <conio.h>
#include <functional>
using namespace std;  

template <typename Object>
class matrix
{
	public:
	matrix( int rows, int cols ) : array( rows )
	{
        for( int i = 0; i < rows; i++ )
            array[ i ].resize( cols );
	}

	const vector<Object> & operator[]( int row ) const
	{ 
		return array[ row ]; 
	}
	
	vector<Object> & operator[]( int row )
	{ 
		return array[ row ]; 
	}

	int numrows( ) const
	{ 
		return array.size( ); 
	}
	
	int numcols( ) const
	{ 
		return numrows( ) ? array[ 0 ].size( ) : 0; 
	}
	
//-----------------------------------------------------------------
matrix resize(int rows, int cols)
	{
	return matrix(rows,cols); //resize member function
	}
	matrix()
	{
		//zero-parameter constructor
    }
//-----------------------------------------------------------------
	private:
		vector< vector<Object> > array;
};


int main()
{
    matrix <int> num1(4,4);
	num1 = num1.resize(3,2);
	
    getch();
	return 0;
}
	
