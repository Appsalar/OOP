#pragma once


class Question
{
public:
	Question() {}
	virtual ~Question();

	virtual void ask() = 0;
	virtual double grade() const = 0;

protected:
	void release();
protected:
	char* description;
	double points;
	char* userAnswer;
};
