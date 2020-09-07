#pragma once

#define NGRAM_LENGTH 5

class CSimpleLinkedList
{
public:
	CSimpleLinkedList(std::string string, CSimpleLinkedList* next);
	~CSimpleLinkedList(void);
	
	CSimpleLinkedList* m_next;
	std::string m_string;
	int m_length;

	void Clear(void);
	int AddChar(char ch);
	unsigned int GetHash(void);
private:
	char Capitalize(char ch);
	char GetCharCode(char ch);
	bool IsValidChar(char ch);
	char m_lastChar;
};
