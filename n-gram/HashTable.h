#pragma once

#include <fstream>
#include <math.h>
#include "SkipList.h"
#include "SimpleLinkedList.h"

using namespace std;

class CHashTable {
public:
	CHashTable(void);
	CHashTable(std::string filename);
	CHashTable(CHashTable* hashtable);
	~CHashTable(void);

	void AddHash(unsigned int hash);
	CSimpleLinkedList* BuildCircularList(void);
	void Clear(void);

	string m_filename;
	CSimpleLinkedList* m_simplelist;
	SkipList<unsigned int,double> m_skiplist;
	int m_numhashes;
	void ShowStats(void);
};
