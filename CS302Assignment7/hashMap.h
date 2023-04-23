#pragma once

#include <iostream>
#include <string>

template <typename t1, typename t2>
class hashMap
{
public:
	struct hashPair
	{
		t1 key;
		t2 value;
		hashPair* link;
	};
	struct iteratorPair
	{
		t1* key;
		t2* value;
		iteratorPair* link;
	};
	class iterator
	{
	public:
		friend class hashMap;
		iterator();
		const iterator& operator ++(int);
		bool operator ==(const iterator&) const;
		bool operator !=(const iterator&) const;
		t1 first();
		t2 second();
	private:
		iterator(iteratorPair*);
		iteratorPair* element;
	};
	hashMap();
	~hashMap();
	t2& operator [](t1);
	iterator begin() const;
	iterator end() const;
private:
	void resize();
	int h(std::string) const;
	int items;
	int size;
	hashPair** table;
	iteratorPair* head;
};

// HASHMAP
template <typename t1, typename t2>
hashMap<t1, t2>::hashMap()
{
	size = 5;
	items = 0;

	head = NULL;

	table = new hashPair* [size];
	
	for (int i : table)
	{
		table[i] = NULL;
	}
}

template <typename t1, typename t2>
hashMap<t1, t2>::~hashMap()
{

}

template <typename t1, typename t2>
t2& hashMap<t1, t2>::operator[](t1 key)
{

}

template <typename t1, typename t2>
typename hashMap<t1, t2>::iterator hashMap<t1, t2>::begin() const
{

}

template <typename t1, typename t2>
typename hashMap<t1, t2>::iterator hashMap<t1, t2>::end() const
{

}

template <typename t1, typename t2>
void hashMap<t1, t2>::resize()
{

}

template <typename t1, typename t2>
int hashMap<t1, t2>::h(std::string key) const
{

}



// ITERATOR

template <typename t1, typename t2>
hashMap<t1, t2>::iterator::iterator()
{
	element = NULL;
}

template <typename t1, typename t2>
hashMap<t1, t2>::iterator::iterator(iteratorPair* p)
{
	element = *p;
}

template <typename t1, typename t2>
const typename hashMap<t1, t2>::iterator& hashMap<t1, t2>::iterator::operator++(int)
{

}

template <typename t1, typename t2>
bool hashMap<t1, t2>::iterator::operator==(const hashMap<t1, t2>::iterator& rhs) const
{

}

template <typename t1, typename t2>
bool hashMap<t1, t2>::iterator::operator!=(const hashMap<t1, t2>::iterator& rhs) const
{

}

template <typename t1, typename t2>
t1 hashMap<t1, t2>::iterator::first()
{
	return *(element->key);
}

template <typename t1, typename t2>
t2 hashMap<t1, t2>::iterator::second()
{
	return *(element->value);
}