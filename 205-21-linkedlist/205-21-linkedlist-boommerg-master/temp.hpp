#ifndef temp_hpp
#define temp_hpp
#include <iostream>
using namespace std;

struct litem {
	int value;
	litem* next;
	litem(int value, litem* next);
};

class list {
	private:
		litem* head;
		litem* tail;
	public: 
		list();
		list(const list& other);
		list& operator=(const list& other);
		void pushback(int value);
		int length();
		void bubbleSort();
		void deleteItems(const int value);
		void clear();
		friend istream &operator>>(istream& input, list& unit);
	    friend ostream &operator<<(ostream& output, list& unit);
		~list();
};
#endif