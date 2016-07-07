#include "YNQuestion.h"
#include <iostream>


using namespace std;


YNQuestion::YNQuestion()
{
	description = NULL;
	userAnswer = NULL;
}

YNQuestion::YNQuestion(const char* descr, double newPoints, bool ans)
{
	description = new char[strlen(descr) + 1];
	strcpy(description, descr);
	points = newPoints;
	bAnswer = ans;
	userAnswer = NULL;
}

YNQuestion::YNQuestion(const YNQuestion & other)
{
	copy(other);
}

YNQuestion & YNQuestion::operator=(const YNQuestion & other)
{
	if (this != &other)
	{
		release();
		copy(other);
	}
	return *this;
}


YNQuestion::~YNQuestion()
{
}

void YNQuestion::ask()
{
	Question::ask();
	char buff[2048];
	delete[] userAnswer;
	cin.getline(buff, 2048);

	userAnswer = new char[strlen(buff) + 1];
	strcpy(userAnswer, buff);
}

double YNQuestion::grade() const
{
	if (strcmp(userAnswer, "yes") == 0 && bAnswer == true)
		return points;
	if (strcmp(userAnswer, "no") == 0 && bAnswer == false)
		return points;
	return 0.0;
}

void YNQuestion::release()
{
	Question::release();
}

void YNQuestion::copy(const YNQuestion & other)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
	points = other.points;
	bAnswer = other.bAnswer;
	userAnswer = new char[strlen(other.userAnswer) + 1];
	strcpy(userAnswer, other.userAnswer);
}
