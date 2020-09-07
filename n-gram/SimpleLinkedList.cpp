#include "StdAfx.h"
#include ".\simplelinkedlist.h"

CSimpleLinkedList::CSimpleLinkedList(std::string string, CSimpleLinkedList* next)
: m_next(next)
, m_string(string)
, m_length((int)string.length())
, m_lastChar(254)
{}

CSimpleLinkedList::~CSimpleLinkedList(void)
{}

void CSimpleLinkedList::Clear(void) {
	m_string.clear();
	m_length = 0;
}

bool CSimpleLinkedList::IsValidChar(char ch) {

	// capitalized normal latin characters
	if((ch >= 'A') && (ch <= 'Z')) return true;

	if((ch == ' ') && (m_lastChar != ' ')) return true;

	// capitalized extra european characters
	//if((ch >= 'À') && (ch <= 'ß')) return true;

	return false;
}

char CSimpleLinkedList::Capitalize(char ch) {

	// capitalize normal latin characters
	if((ch >= 'a') && (ch <= 'z')) return ch-32;

	// capitalize extra european characters
	//if((ch >= 'à') && (ch <= 'ÿ')) return ch-32;

	return ch;
}

int CSimpleLinkedList::AddChar(char ch) {
	
	char ch_caps = Capitalize(ch);

	if(IsValidChar(ch_caps)) {
		m_lastChar = ch_caps;
		m_string.append(1,ch_caps);
		m_length++;
	}
	
	return m_length;
}

unsigned int CSimpleLinkedList::GetHash(void) {

	char ch1 = GetCharCode(m_string[0]);
	char ch2 = GetCharCode(m_string[1]);
	char ch3 = GetCharCode(m_string[2]);
	char ch4 = GetCharCode(m_string[3]);
	char ch5 = GetCharCode(m_string[4]);

	return ch1 + 59*ch2 + 3481*ch3 + 205379*ch4 + 12117361*ch5;
}

char CSimpleLinkedList::GetCharCode(char ch) {

	// take care of the space
	if(ch == ' ') return 0;

	// normal latin characters
	if((ch >= 'A') && (ch <= 'Z')) return ch-64;

	// european characters
	//if((ch >= 'À') && (ch <= 'ß')) return ch-165;

	return 0;
}
