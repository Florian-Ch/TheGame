#pragma once
#include <iostream>
#include <string>
#include <sstream>
class Interface
{
public:
	Interface();
	~Interface();
	static void m_afficherLigne(std::string);
	static void m_afficherChar(char);
	static int m_getIntegeur(int, int);
	static char m_getChar(char*, int);
	static void m_messageErreur(std::string);
	static std::string m_getString();
	static std::string m_intToString(int);
};

