#pragma once
#include "Question.h"
class OpenQuestion :
	public Question
{
public:
	OpenQuestion();
	OpenQuestion(const char*, double);
	OpenQuestion(const OpenQuestion&);
	OpenQuestion& operator=(const OpenQuestion&);
	~OpenQuestion();

	void ask();
	double grade() const;
private:
	void release();
	void copy(const OpenQuestion&);
};

