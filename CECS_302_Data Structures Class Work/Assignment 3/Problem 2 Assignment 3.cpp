//Christopher Bass
//CECS 302
//10/19/14

/*
3.6   
The Josephus problem is the following game: N people, numbered 1 to N, are sitting in
a circle.  Starting at person 1, a hot potato is passed.  After M passes, the person 
holding the hot potato is eliminated, the circle closes ranks, and the game continues 
with the person who was sitting after the eliminated person picking up the hot potato. 
The last remaining person wins.  Thus, if M=0 and N=5, players are eliminated in order, 
and player 5 wins.  If M=1 and N=5, the order of the elimination is 2, 4, 1, 5.
a.  Write a program to solve the Josephus problem for general values of M and N.
    Try to make your program as efficient as possible.  Make sure you dispose of cells.
b.  What is the running time of your program?
c.  If M=1, what is the running time of your program?  How is the actual speed affected
    by the delete routine for large values of N (N > 100,000)?
*/

#include<iostream>
#include<list>
#include <stdio.h>
#include <ctime>
#include <time.h>
using namespace std;

double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks)/CLOCKS_PER_SEC;
    return diffms;
} 

 

int main()
{
    clock_t begin=clock();
     
	int i, j, N, M;
    double time;
	list<int> Potato;
	list<int>::iterator itr;
	
	


	cout << "Enter the Number of People  ";
	cin >> N;
	cout << "Enter the number of passes before elimination:  ";
	cin >> M;
	cout << endl;
	
	for (i = 1; i <= N; i++)
	{
		Potato.push_back(i);
	}

	itr = Potato.begin();

	for (i = 0; i < N; i++)
	{
		

		if (M <= N / 2) 
		{
			for (j = 0; j < M; j++)
			{
				itr++;
				if (itr == Potato.end())
					itr = Potato.begin();
			}
		}
		else
		{ 
			for (j = 0; j < M; j++)
			{
				if (itr == Potato.begin())
					itr = --Potato.end();
				else
					itr--;
			}
		}
		
        cout << *itr << " ";
		
        itr = Potato.erase(itr);
		delete &itr;
		if (itr == Potato.end())
			itr = Potato.begin();
	}
	clock_t end=clock();
	cout<<"\n\nAbove are the numbers that were eliminated from frist to last with the last"<<endl; 
	cout<<"number being the winner."<<endl;
    cout << endl;
	
	
	cout<<"\nThe Program took "<<double(diffclock(end,begin))<<" Milliseconds to run."<<endl;
    system("pause");
	return 0;
}

