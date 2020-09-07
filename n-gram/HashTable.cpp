#include "StdAfx.h"
#include ".\hashtable.h"

// for our centroid constructor
CHashTable::CHashTable(void)
: m_simplelist(NULL)
, m_numhashes(0)
, m_skiplist()
{
	m_filename = "centroid";
}

CHashTable::CHashTable(std::string filename) 
: m_skiplist()
{
	m_filename = filename;

	printf("Processing file: %s\n",filename.c_str());
	
	Clear();
	m_simplelist = BuildCircularList();
	CSimpleLinkedList* ptr = m_simplelist;

	filename.insert(0,"..\\..\\Documents\\");

	std::ifstream textfile(filename.c_str());
	
	if(!textfile) {
		printf("ERROR: Cannot read %s\n",filename.c_str());
		exit(1);
	}

	int j = 1;
	char ch;

	while(textfile.get(ch)) {
		for(int i=0;i<NGRAM_LENGTH;i++) {
			if(j > i) {
				if(ptr->AddChar(ch) == NGRAM_LENGTH) {
					AddHash(ptr->GetHash());
					ptr->Clear();
				}
			}

			ptr = ptr->m_next;
		}
		
		j++;
	}

	textfile.close();
}

CHashTable::~CHashTable(void)
{}

CSimpleLinkedList* CHashTable::BuildCircularList(void) {
	CSimpleLinkedList* first = new CSimpleLinkedList("",NULL);
	CSimpleLinkedList* ptr = first;

	for(int i=1;i<NGRAM_LENGTH;i++) {
		CSimpleLinkedList* newList = new CSimpleLinkedList("",NULL);
		ptr->m_next = newList;
		ptr = newList;
	}

	ptr->m_next = first;

	return first;
}

void CHashTable::Clear(void) {
	m_numhashes = 0;
}

void CHashTable::AddHash(unsigned int hash) {
	m_skiplist.Add(hash);
	m_numhashes++;
}

void CHashTable::ShowStats(void) {
	cout << "Hashes in document:         " << m_numhashes << endl;
	cout << "Unique hashes in skip list: " << m_skiplist.nCount << endl;
	cout << "Levels in skip list:        " << m_skiplist.currentLevel << endl;
}
