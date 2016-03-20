//Christopher Bass
//CECS 302
//9/29/2014

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <complex>
#include <ctime>
#include <time.h>


using namespace std;

double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks*1000)/CLOCKS_PER_SEC;
    return diffms;
}


int main(){
    int sum, n=1000, i, j, k;

    cout<<"n= "<<n<<endl;

    clock_t begin=clock();
    // 1)
    sum = 0;
    clock_t t;
    for( i = 0; i < n; ++i )
       {  ++sum;}
    clock_t end=clock();


    cout<<"1.) "<<sum<<" Time Elasped: "<<double(diffclock(end,begin))<<" ms"<<endl;

    //(2)
    sum = 0;
    begin=clock();
    for( i = 0; i < n; ++i )
         for( j = 0; j < n; ++j )
         ++sum;
    end=clock();
    cout<<"2.) "<<sum<<" Time Elasped: "<<double(diffclock(end,begin))<<" ms"<<endl;

    //(3)
    sum = 0;
    begin=clock();
    for( i = 0; i < n; ++i )
         for( j = 0; j < n * n; ++j )
         ++sum;
    end=clock();
    cout<<"3.) "<<sum<<" Time Elasped: "<<double(diffclock(end,begin))<<" ms"<<endl;

    //(4)
    sum = 0;
    begin=clock();
    for( i = 0; i < n; ++i )
         for( j = 0; j < i; ++j )
         ++sum;
    end=clock();
         cout<<"4.) "<<sum<<" Time Elasped: "<<double(diffclock(end,begin))<<" ms"<<endl;

    //(5)
    sum = 0;
    begin=clock();
    for( i = 0; i < n; ++i )
         for( j = 0; j < i * i; ++j )
              for( k = 0; k < j; ++k )
              ++sum;
    end=clock();
              cout<<"5.) "<<sum<<" Time Elasped: "<<double(diffclock(end,begin))<<" ms"<<endl;

     //(6)
     sum = 0;
     begin=clock();
     for( i = 1; i < n; ++i )
          for( j = 1; j < i * i; ++j )
               if( j % i == 0 )
                   for( k = 0; k < j; ++k )
                   ++sum;
                   end=clock();
                   cout<<"6.) "<<sum<<" Time Elasped: "<<double(diffclock(end,begin))<<" ms"<<endl;

 getch();
 return 0;
}



