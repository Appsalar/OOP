#include "OpenQuestion.h"
#include <iostream>


using namespace std;


OpenQuestion::OpenQuestion()
{
	description = NULL;
	userAnswer = NULL;
}

OpenQuestion::OpenQuestion(const char *descr, double pts)
{
	description = new char[strlen(descr) + 1];
	strcpy(description, descr);
	points = pts;
	userAnswer = NULL;
}

OpenQuestion::OpenQuestion(const OpenQuestion & other)
{
	copy(other);
}

OpenQuestion & OpenQuestion::operator=(const OpenQuestion &other)
{
	if (this != &other)
	{
		release();
		copy(other);
	}
	return *this;
}


OpenQuestion::~OpenQuestion()
{
}

void OpenQuestion::ask()
{
	Question::ask();
	char buff[2048];
	delete[] userAnswer;
	cin.getline(buff, 2048);

	userAnswer = new char[strlen(buff) + 1];
	strcpy(userAnswer, buff);
}

double OpenQuestion::grade() const
{
	double perc = atof(userAnswer)/100;

	return perc * points;
}

void OpenQuestion::release()
{
	Question::release();
}

void OpenQuestion::copy(const OpenQuestion & other)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
	points = other.points;
	userAnswer = new char[strlen(other.userAnswer) + 1];
	strcpy(userAnswer, other.userAnswer);
}
