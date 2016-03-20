//Christopher Bass
//CECS 302
//Problem 1.15
//9/17/14

#include <iostream>    
#include <vector>
#include <conio.h>
#include <functional>
using namespace std;  

class Rectangle
      {
      public:
             Rectangle (int l=0, int w=0) :length(l), width(w){}
             int getLength(){return length;}
             int getWidth(){return width;}
             void  setLength(int L){length=L;}
             void  SetWidth(int W){width=W;}

 private:
              int length;
              int width;
      
      
      };

//------------------------------------------------------------------------------

//this is the standard findMax using the "<" symbol
template <typename Comparable>
const Comparable & findMax( const vector<Comparable> & a )
{
    int maxIndex = 0;

    for( unsigned i = 1; i < a.size( ); i++ )
        if( a[ maxIndex ] < a[ i ] )
            maxIndex = i;

    return a[ maxIndex ];
}

// Generic findMax, with a function object.
// Precondition: a.size( ) > 0.
template <class Object, class Comparator>
const Object & findMax( const vector<Object> & a, Comparator isLessThan )
{
    int maxIndex = 0;
	
    for( int i = 1; i < a.size( ); i++ )
        if( isLessThan( a[ maxIndex ], a[ i ] ) )
            maxIndex = i;

    return a[ maxIndex ];
}

//------------------------------------------------------------------------------      
     


int main(){
    
vector<Rectangle>rect(4);
vector<int>area(4), perim(4);
 
 rect[1]=Rectangle(3,4);
 rect[2]=Rectangle(4,8);
 rect[3]=Rectangle(5,10);
 rect[4]=Rectangle(3,6);
 
 for (int i=0; i<4; ++i){
     area[i]=rect[i].getLength( )*rect[i].getWidth( );
	 perim[i]=2*rect[i].getLength( )+2*rect[i].getWidth( );
     }
    	
 for (int j=1; j<5; ++j){//Prints out the 4 rectangles
     cout<<"Rectangle #"<<j<<": "<<rect[j].getLength( )<<", "<<rect[j].getWidth( )<<endl;
     
     }
     
        cout <<"\nLargest area: "<<findMax(area)<< endl;//Prints out largest area
		cout <<"Largest perimeter: " <<findMax(perim) << endl;//Prints out largest perimeter
    
 getch();
 return 0; 
}
