#pragma once

#include <stdlib.h>			// needed for rand, srand
#include <time.h>			// needed for time
#include <vector>
#include <algorithm>

using namespace std;

#define LEVEL_PROB		0.367879441
#define DEF_VALUE		1
#define MAX_LEVEL		11

template <class K, class V>
class SkipList {
private:
	struct SkipListNode {
		K				key;		// key for search purpose
		V				value;		// value of the item
		SkipListNode	**pNext;	// next item

		SkipListNode() { pNext=NULL; }
		virtual	~SkipListNode() { delete [] pNext; }
	};
	
public:
					SkipList();
	virtual			~SkipList();

	void			Add(const K &k);
	void			Add(const K &k, const V &v);
	void			AddSkipList(SkipList<K,V> &skip);
	void			Dump();
	void			Mean(const V &v);
	void			Normalize();
	V				Find(const K &k);
	bool			FindKey(const K &k);
	double			Similarity(SkipList<K,V> &skip2);
	void			Remove(const K &k);
	void			Multiply(const K &k,const V &v);
	void			RemoveDisjunctSkipList(SkipList<K,V> &skip);

	SkipListNode	*pFirst;			// first item
	unsigned int	nCount;				// item count
	unsigned int	currentLevel;		// current level of list
	unsigned int	nTotalElements;		// number of total elements
};

template <class K, class V> 
SkipList<K,V>::SkipList()
: currentLevel(0)
, nCount(0)
, nTotalElements(0)
{
	// let's start off with one level
	pFirst = new SkipListNode;
	pFirst->pNext = new SkipListNode *[MAX_LEVEL+1];
	
	for(int i=0;i<=MAX_LEVEL;i++) pFirst->pNext[i] = NULL;

	srand((unsigned)time(NULL));
}

template <class K, class V> 
SkipList<K,V>::~SkipList() {
	//RemoveAll();
	delete pFirst;
}

template <class K, class V>
void SkipList<K,V>::Add(const K &k, const V &v) {

	// increment our total elements counter
	nTotalElements += v;

	int nCpt;
	SkipListNode **pUpdateArray = new SkipListNode *[MAX_LEVEL+1];
	SkipListNode *pCurrent;

	//cout << "current level: " << currentLevel << endl;

	// find where to insert item
	for(pCurrent = pFirst,nCpt = currentLevel;nCpt >= 0;nCpt--) {
		while(pCurrent->pNext[nCpt] != NULL && pCurrent->pNext[nCpt]->key < k) pCurrent = pCurrent->pNext[nCpt];
		pUpdateArray[nCpt] = pCurrent;
	}

	pCurrent = pCurrent->pNext[0];

	// this item is already in list
	if(pCurrent != NULL && pCurrent->key == k) {
		pCurrent->value += v;
		delete [] pUpdateArray;
		return;
	}

	// get new list level
	unsigned int newLevel = 0;
	while(((rand() / (float)RAND_MAX) < LEVEL_PROB) && (newLevel <= currentLevel) && (newLevel < MAX_LEVEL)) newLevel++;

	if(newLevel > currentLevel) {
		for(nCpt = currentLevel+1;nCpt <= newLevel;nCpt++) pUpdateArray[nCpt] = pFirst;
		currentLevel = newLevel;
	}

	// create new item
	pCurrent = new SkipListNode;
	pCurrent->pNext = new SkipListNode *[newLevel+1];
	pCurrent->key = k;
	pCurrent->value = v;

	// update next items pointers
	for(nCpt = 0;nCpt <= newLevel;nCpt++) {
		pCurrent->pNext[nCpt] = pUpdateArray[nCpt]->pNext[nCpt];
		pUpdateArray[nCpt]->pNext[nCpt] = pCurrent;
	}

	delete [] pUpdateArray;

	nCount++;
}

template <class K, class V>
void SkipList<K,V>::Add(const K &k) {

	// increment our total elements counter
	nTotalElements++;

	int nCpt;
	SkipListNode **pUpdateArray = new SkipListNode *[MAX_LEVEL+1];
	SkipListNode *pCurrent;

	//cout << "current level: " << currentLevel << endl;

	// find where to insert item
	for(pCurrent = pFirst,nCpt = currentLevel;nCpt >= 0;nCpt--) {
		while(pCurrent->pNext[nCpt] != NULL && pCurrent->pNext[nCpt]->key < k) pCurrent = pCurrent->pNext[nCpt];
		pUpdateArray[nCpt] = pCurrent;
	}

	pCurrent = pCurrent->pNext[0];

	// this item is already in list
	if(pCurrent != NULL && pCurrent->key == k) {
		pCurrent->value++;
		delete [] pUpdateArray;
		return;
	}

	// get new list level
	unsigned int newLevel = 0;
	while(((rand() / (float)RAND_MAX) < LEVEL_PROB) && (newLevel <= currentLevel) && (newLevel < MAX_LEVEL)) newLevel++;

	if(newLevel > currentLevel) {
		for(nCpt = currentLevel+1;nCpt <= newLevel;nCpt++) pUpdateArray[nCpt] = pFirst;
		currentLevel = newLevel;
	}

	// create new item
	pCurrent = new SkipListNode;
	pCurrent->pNext = new SkipListNode *[newLevel+1];
	pCurrent->key = k;
	pCurrent->value = DEF_VALUE;

	// update next items pointers
	for(nCpt = 0;nCpt <= newLevel;nCpt++) {
		pCurrent->pNext[nCpt] = pUpdateArray[nCpt]->pNext[nCpt];
		pUpdateArray[nCpt]->pNext[nCpt] = pCurrent;
	}

	delete [] pUpdateArray;

	nCount++;
}

template <class K, class V>
void SkipList<K,V>::Multiply(const K &k,const V &v) {

	int nCpt;
	SkipListNode *pCurrent;

	// find where to insert item
	for(pCurrent = pFirst,nCpt = currentLevel;nCpt >= 0;nCpt--) {
		while(pCurrent->pNext[nCpt] != NULL && pCurrent->pNext[nCpt]->key < k) pCurrent = pCurrent->pNext[nCpt];
	}

	pCurrent = pCurrent->pNext[0];

	// this item is in the list
	if(pCurrent != NULL && pCurrent->key == k) pCurrent->value *= v;
}

template <class K, class V>
bool SkipList<K,V>::FindKey(const K &k) {

	int nCpt;
	SkipListNode *pCurrent;

	// find where to insert item
	for(pCurrent = pFirst,nCpt = currentLevel;nCpt >= 0;nCpt--) {
		while(pCurrent->pNext[nCpt] != NULL && pCurrent->pNext[nCpt]->key < k) pCurrent = pCurrent->pNext[nCpt];
	}

	pCurrent = pCurrent->pNext[0];

	// this item is in the list
	if(pCurrent != NULL && pCurrent->key == k) return true;

	return false;
}

template <class K, class V> 
void SkipList<K,V>::Remove(const K &k) {
	int				nCpt;
	SkipListNode	**pUpdateArray = new SkipListNode *[MAX_LEVEL+1];
	SkipListNode	*pCurrent;

	// search item to remove
	for(pCurrent=pFirst,nCpt=currentLevel;nCpt>=0;nCpt--) {
		while(pCurrent->pNext[nCpt] != NULL && pCurrent->pNext[nCpt]->key < k) pCurrent=pCurrent->pNext[nCpt];
		pUpdateArray[nCpt]=pCurrent;
	}

	pCurrent = pCurrent->pNext[0];

	// reorder list without this item
	if(pCurrent != NULL && pCurrent->key == k) {
		for(nCpt=0;nCpt<=currentLevel;nCpt++)
			if(pUpdateArray[nCpt]->pNext[nCpt] == pCurrent) pUpdateArray[nCpt]->pNext[nCpt] = pCurrent->pNext[nCpt];
		
		delete pCurrent;
		nCount--;

		// correct list level
		while(currentLevel>0 && pFirst->pNext[currentLevel] == NULL) currentLevel--;
	}

	delete [] pUpdateArray;
}

template <class K, class V>
void SkipList<K,V>::Dump() {
	SkipListNode *pCurrent = pFirst->pNext[0];
	while(pCurrent != NULL) {
		cout << pCurrent->key << " : " << pCurrent->value << endl;
		pCurrent = pCurrent->pNext[0];
	}
}

template <class K, class V>
void SkipList<K,V>::Normalize() {
	//cout << "Normalizing document vector." << endl;
	SkipListNode *pCurrent = pFirst->pNext[0];
	while(pCurrent != NULL) {
		pCurrent->value /= (double)nTotalElements;
		pCurrent = pCurrent->pNext[0];
	}
}

template <class K, class V>
double SkipList<K,V>::Similarity(SkipList<K,V> &skip2) {
	//cout << "Calculating similarity score." << endl;

	V value, value2;
	V squaresum = 0, squaresum2 = 0;
	V sum = 0;

	SkipListNode *pCurrent = pFirst->pNext[0];
	while(pCurrent != NULL) {
		value  = pCurrent->value;
		value2 = skip2.Find(pCurrent->key);

		if(value > 0) squaresum += value * value;	

		if(value2 > 0) squaresum2 += value2 * value2;	

		if((value > 0) && (value2 > 0)) sum += value * value2;

		pCurrent = pCurrent->pNext[0];
	}

	return sum / sqrt(squaresum*squaresum2);
}

template <class K, class V>
V SkipList<K,V>::Find(const K &k) {
	int				nCpt;
	SkipListNode	*pCurrent;

	// search item
	for(pCurrent=pFirst, nCpt=currentLevel; nCpt>=0; nCpt--) {
		while(pCurrent->pNext[nCpt] != NULL && pCurrent->pNext[nCpt]->key < k) pCurrent = pCurrent->pNext[nCpt];
	}

	pCurrent = pCurrent->pNext[0];

	// this item is not in list
	if(pCurrent == NULL || pCurrent->key != k) return 0;

	return pCurrent->value;
}

template <class K, class V>
void SkipList<K,V>::AddSkipList(SkipList<K,V> &skip) {
	SkipListNode *pCurrent = skip.pFirst->pNext[0];

	while(pCurrent != NULL) {
		Add(pCurrent->key,pCurrent->value);
		pCurrent = pCurrent->pNext[0];
	}
}

template <class K, class V>
void SkipList<K,V>::RemoveDisjunctSkipList(SkipList<K,V> &skip) {
	SkipListNode *pCurrent = skip.pFirst->pNext[0];

	while(pCurrent != NULL) {
		// search in current skip list for keys in other skip list
		if(FindKey(pCurrent->key)) Multiply(pCurrent->key,pCurrent->value);
		pCurrent = pCurrent->pNext[0];
	}

	pCurrent = pFirst->pNext[0];
	SkipListNode *pErase;

	vector<V> reducedList;
	SkipList<V,K> reverseSkip;

	while(pCurrent != NULL) {
		// search in current skip list for keys in other skip list
		if(!skip.FindKey(pCurrent->key)) {
			pErase = pCurrent;
			pCurrent = pCurrent->pNext[0];
			Remove(pErase->key);
		} else {
			reducedList.push_back(pCurrent->value);
			reverseSkip.Add(pCurrent->value,pCurrent->key);
			pCurrent = pCurrent->pNext[0];
		}
	}

	sort(reducedList.begin(),reducedList.end());
	vector<V> keyList;

	for(int i=reducedList.size()-10;i<reducedList.size();i++) {
		cout << reducedList[i] << " : " << reverseSkip.Find(reducedList[i]) << endl;
	}

	/*
vector<int> vec;
vec.push_back (10);
vec.push_back (3);
vec.push_back (7);

sort(vec.begin(), vec.end());

	// build a key and value queue and hold the 10 largest elements
	queue<K> keyQueue;
	queue<V> valueQueue;

	V maximum = 0;

	pCurrent = pFirst->pNext[0];

	while(pCurrent != NULL) {
		cout << pCurrent->value << endl;

		if(pCurrent->value > maximum) {
			maximum = pCurrent->value;
			keyQueue.push(pCurrent->key);
			valueQueue.push(pCurrent->value);	
			
			if(keyQueue.size() > 10) {
				cout << "popping extra queue entries." << endl;
				keyQueue.pop();
				valueQueue.pop();
			}
		}

		pCurrent = pCurrent->pNext[0];
	}

	for(int i=0;i<keyQueue.size();i++) {
		cout << keyQueue.front() << " : " << valueQueue.front() << endl;
		keyQueue.pop();
		valueQueue.pop();
	}

	cout << "Maximum: " << maximum << endl;
*/
}

template <class K, class V>
void SkipList<K,V>::Mean(const V &v) {
	SkipListNode *pCurrent = pFirst->pNext[0];

	while(pCurrent != NULL) {
		pCurrent->value /= v;
		pCurrent = pCurrent->pNext[0];
	}
}