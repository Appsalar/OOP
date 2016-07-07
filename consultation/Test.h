#pragma once
#include "Question.h"

class Test
{
public:
	Test();
	~Test();

	void addQuestion(Question*);
	void doTest();
	double gradeTest() const;

private:
	void resize(size_t);
private:
	Question** arr;
	size_t size;
	size_t capacity;
};

