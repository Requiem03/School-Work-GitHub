//Christopher Bass
//CECS 302
//10/19/14
/*
4.) Starting with my code for a single linked list defined in SLList.h and implemented in SLList.cpp, do the following:
	1.) Write an additional method called push_back (type someItem) that will add 	
        someItem to the end of the list.
	2.) Write your own main that demonstrates the use of every public method.
	3.) Compare append with push_back for large number of points and try to obtain some 	
        empirical estimates using the timing functions I discussed in chapter 2 in MaxSubSum example which is posted on blackboard.

*/

#include<iostream>
#include <assert.h>
#include <conio.h>
#include <iostream>

#ifndef SLLIST_H_
#define SLLIST_H_
using namespace std;
typedef int Type;

enum Boolean
{
	False = 0, True
};

class Item
{
		friend class SLList;

	public:
		Type getVal()
		{
			return val;
		}

	//private:
		Item(Type value, Item *item = 0)
		{
			val = value;
			next = item;
		}

		Type val;
		Item *next;
};

class SLList
{
	public:

		class Const_Iterator
		{
				friend class SLList;
			public:
				Item *current;
				Const_Iterator() :
					current(NULL)
				{
				}

				const Item & operator*() const
				{
					return *this->current;
				}

				Const_Iterator operator++()
				{
					current = current->next;
					return *this;
				}

				Const_Iterator operator++(int)
				{
					Const_Iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const Const_Iterator & rhs)
				{
					return current == rhs.current;
				}
				bool operator!=(const Const_Iterator & rhs)
				{
					return !(*this == rhs);
				}

				Item retrieve() const
				{
					return current->val;
				}

				Const_Iterator(Item *p) :
					current(p)
				{
				}

		};

		class Iterator
		{
				friend class SLList;
			public:
				Item *current;
				Iterator() :
					current(NULL)
				{
				}

				const Item & operator*() const
				{
					return *this->current;
				}

				Iterator operator++()
				{
					current = current->next;
					return *this;
				}

				Iterator operator++(int)
				{
					Iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const Iterator & rhs) const
				{
					return current == rhs.current;
				}
				bool operator!=(const Iterator & rhs)
				{
					return !(*this == rhs);
				}

				Item retrieve()
				{
					return current->val;
				}

				Iterator(Item *p) :
					current(p)
				{
				}
		};

		SLList()
		{
			list = 0;
		}
		~SLList()
		{
			remove();
		}

        void push_back(Type someItem);
		void insert(Type someItem);
		void append(Type someItem);
		int remove(Type someItem);
		void remove();

		Item *atEnd();
		Item *head();
		Item *tail();
        
		Boolean isPresent(Type someItem);
		Boolean isEmpty();
		void display();

	private:
		Iterator iterator;
		Item *list;
		Item *atEndItem;
};
#endif /* SLLIST_H_ */

main() {//Start of Main
SLList mylist;



mylist.insert(4); cout<<"Using Insert"<<endl;
mylist.display();
mylist.insert(5); cout<<"Using Insert"<<endl;
mylist.display();
mylist.remove(5); cout<<"Using Remove"<<endl;
mylist.display();
mylist.insert(7); cout<<"Using Insert"<<endl;
mylist.display();

mylist.append(8); cout<<"Using Append"<<endl;

mylist.display();
mylist.remove();cout<<"Using Remove for entire list"<<endl;
mylist.display();
mylist.push_back(10); cout<<"Using push_back"<<endl;
mylist.display();
mylist.push_back(45); cout<<"Using push_back"<<endl;
mylist.display();
mylist.push_back(50); cout<<"Using push_back"<<endl;
mylist.display();



system("pause");

}//End of Main

//-------------------------------------------------
//Adds a node to the end of the list.
void SLList::push_back(Type someItem)
{
    Item *ptr = new Item(someItem);
	if (list == 0)
	{
		list = ptr;
	}
	else
	{
		atEndItem->next = ptr;
	}
	atEndItem = ptr;
}

//-------------------------------------------------

Boolean SLList::isEmpty()
{
	return list == 0 ? True : False;
}

void SLList::insert(Type val)
{
	Item *pt = new Item(val, list); // create new item put it in front of list
	assert(pt != 0);
	if (list == 0)
	{
		atEndItem = pt;
	}
	list = pt; // and point next top the list
}

Item *SLList::atEnd()
{
	if (list == 0)
	{
		return 0;
	}

	Item *prev, *curr;
	prev = curr = list;

	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}

Item *SLList::tail()
{
	if (list == 0)
	{
		return 0;
	}

	Item *prev, *curr;
	prev = curr = list;

	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}

Item *SLList::head()
{
	if (list == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	else
	{
		return list;
	} // end if
	return list;
}

void SLList::append(Type val)
{
	Item *pt = new Item(val);
	assert(pt != 0);
	if (list == 0)
	{
		list = pt;
	}
	else
	{
		atEndItem->next = pt;
	}
	atEndItem = pt;
}

void SLList::display()
{
	cout << "(";
	for (Item *pt = list; pt; pt = pt->next)
	{
		cout << pt->val << " ";
	} // end for
	cout << ")" << endl;
}

void SLList::remove()
{
	Item *pt = list;
	while (pt)
	{
		Item *temp = pt;
		pt = pt->next;
		delete temp;
	} // end while
	list = atEndItem = 0;
}

Boolean SLList::isPresent(Type item)
{
	Boolean rc = False;
	if (list != 0)
	{
		if (list->val == item || atEndItem->val == item)
		{
			rc = True;
		}
		else
		{
			Item *pt = list->next;
			for (; pt != atEndItem; pt = pt->next)
			{
				if (pt->val == item)
				{
					rc = True;
				} // end if
			} // end for
		} // end if
	} // end if
	return rc;
}
int SLList::remove(Type val)
{
	Item *pt = list;
	int cnt = 0;

	while (pt && pt->val == val)
	{
		Item *tmp = pt->next;
		delete pt;
		cnt++;
		pt = tmp;
	} // end while

	if ((list = pt) == 0)
	{
		atEndItem = 0;
		return cnt;
	} // end if

	Item *prv = pt;
	pt = pt->next;

	while (pt)
	{
		if (pt->val == val)
		{
			prv->next = pt->next;
			if (atEndItem == pt)
			{
				atEndItem = prv;
			} // end if
			delete pt;
			++cnt;
			pt = prv->next;
		}
		else
		{
			prv = pt;
			pt = pt->next;
		} // end if else
	} // end while
	return cnt;
}
