#include <cfixcc.h>
#include "Functions.h"
class TestForCheckTextForMultiComment : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//								Тесты для checkTextForMultiComment
	//-------------------------------------------------------------------------------------
	// Типовой тест
	void TypicalTest()
	{
		// Входные данные
		int countString=6;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	/*multiComment"},
			{"	*/"},
			{"}"}
		};
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), true);
	}
	// Текст с многострочным комментарием на часть одной строки
	void textWithMultiCommentPartOneLine()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	a++;/*multiComment*/"},
			{"}"}
		};
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), true);
	}
	// Текст без многострочного комментария
	void textWithoutMultiComment()
	{
		// Входные данные
		int countString=4;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), false);
	}
	// Перед многострочным комментарием идет однострочный
	void singleCommentBeforeMultiComment()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	//a++;/*multiComment*/"},
			{"}"}
		};
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), false);
	}
	// Пустой текст
	void emptyText()
	{
		// Входные данные
		int countString=3;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""},
			{""},
			{""}
		};
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), false);
	}
	// Несколько многострочных в тексте
	void fewMultiComments()
	{
		// Входные данные
		int countString=6;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	/*int a;*/"},
			{"	/*multiComment"},
			{"	*/"},
			{"}"}
		};
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), true);
	}
	// Весь текст в многострочном комментарии
	void allTextInComment()
	{
		// Входные данные
		int countString=4;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"/*void main()"},
			{"{"},
			{"	int a;"},
			{"}*/"}
		};
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), true);
	}
};

CFIXCC_BEGIN_CLASS(TestForCheckTextForMultiComment)
	CFIXCC_METHOD(TypicalTest)
	CFIXCC_METHOD(textWithMultiCommentPartOneLine)
	CFIXCC_METHOD(textWithoutMultiComment)
	CFIXCC_METHOD(singleCommentBeforeMultiComment)
	CFIXCC_METHOD(emptyText)
	CFIXCC_METHOD(fewMultiComments)
	CFIXCC_METHOD(allTextInComment)
CFIXCC_END_CLASS()

