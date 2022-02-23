#pragma once
#include <iostream>

/**
* @file Voice.h
* @author Adrian Paez
* @version 0.1
*/

using namespace std;

class Voice
{

private:
public:
	void voiceGen(string, string);

};

void Voice::voiceGen(string word, string word2)
{
	string command = "espeak -v es+m3 \ " + word + "\"";
	const char* a = command.c_str();

	system(a);

	string command2 = "espeak -v en+m3 \ " + word2 + "\"";
	const char* b = command2.c_str();

	system(b);
}