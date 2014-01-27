#include <iostream>
#include <cstring>

using namespace std;

template <typename T> class ListItem {
	private:
		T item;
		ListItem *next;

	public:
		ListItem() {
			memset(&item, 0, sizeof(item));
		}

		~ListItem( ) {
		}

		T& get_item() {
			return item;
		}

		void set_item(T* new_item) {
			memcpy((void*)&item, (void*)new_item, sizeof(item));
		}

		void update_next(ListItem *next_item) {
			next = next_item;
		}

		ListItem* get_next() {
			return next;
		}
};




int main()
{
	ListItem<int> *pi=NULL;		// pointer to class template type <int>
	ListItem<double> *pd=NULL;	// pointer to class template type <double>

// Initialise the linked list components
// template type is <int>
	for(int i=0; i<10; i++)	{
		ListItem<int> *itemi = new ListItem<int>;
		itemi->update_next(pi);
		pi = itemi;
		int data = 100+i;	// dummy data
		itemi->set_item(&data);
	}

	cout << endl << endl << "template type is <int>" << endl;
	for(int i=0; i<10; i++)	{
		cout << "item " << i << ". is " << pi->get_item() << endl;
		pi = pi->get_next();
	}


// Initialise the linked list components
// template type is <double>
	for(int i=0; i<10; i++)	{
		ListItem<double> *item = new ListItem<double>;
		item->update_next(pd);
		pd = item;
		double data = (double)i/10;	// dummy data
		item->set_item(&data);
	}

	cout << endl << endl << "template type is <double>" << endl;

	for(int i=0; i<10; i++)	{
		cout << "item " << i << ". is " << pd->get_item() << endl;
		pd = pd->get_next();
	}

}

