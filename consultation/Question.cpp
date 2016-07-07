#include "Question.h"
#include <iostream>


using namespace std;

Question::~Question()
{
	release();
}

void Question::ask()
{
	{
		cout << description << endl;
	}
}

void Question::release()
{
	delete[] description;
	delete[] userAnswer;
	description = NULL;
	userAnswer = NULL;
}

