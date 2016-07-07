#pragma once
#include "Question.h"
class YNQuestion :
	public Question
{
public:
	YNQuestion();
	YNQuestion(const char*, double, bool);
	YNQuestion(const YNQuestion&);
	YNQuestion& operator=(const YNQuestion&);
	~YNQuestion();

	void ask();
	double grade() const;
private:
	void release();
	void copy(const YNQuestion&);

	bool bAnswer;
};

