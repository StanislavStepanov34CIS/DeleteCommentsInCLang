#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveMultiLinesComment : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//								Тесты для removeMultiLinesСomment
	//-------------------------------------------------------------------------------------
	// Типовой тест
	void TypicalTest()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"/*multiComment"},
			{"int a;	*/"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{""},
			{"}"}
		};
		// Получение результата
		countString = removeMultiLinesСomment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Многострочный комментарий на несколько строк
	void multiLinesCommentOnFewLines()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{/*"},
			{"multiComment"},
			{"int a;	*/"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=3;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"}"}
		};
		// Получение результата
		countString = removeMultiLinesСomment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Многострочный комментарий в одной строке
	void multiLinesCommentInOneLine()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"/*multiComment*/"},
			{"	int a;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{""},
			{"	int a;"},
			{"}"}
		};
		// Получение результата
		countString = removeMultiLinesСomment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Многострочный комментарий после однострочного
	void multiLinesCommentAfterSingleLineComment()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"///*multiComment*/"},
			{"	int a;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"///*multiComment*/"},
			{"	int a;"},
			{"}"}
		};
		// Получение результата
		countString = removeMultiLinesСomment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Несколько многострочных комментариев в одной строке
	void fewMultiLinesCommentsInOneString()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"/*multiComment*/	char b[0];/*multiComment*/"},
			{"	int a;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	char b[0];"},
			{"	int a;"},
			{"}"}
		};
		// Получение результата
		countString = removeMultiLinesСomment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Несколько многострочных комментариев в тексте
	void fewMultiLinesCommentsInText()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"/*multiComment*/"},
			{"/*	int a;*/"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{""},
			{""},
			{"}"}
		};
		// Получение результата
		countString = removeMultiLinesСomment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
};

CFIXCC_BEGIN_CLASS(TestForRemoveMultiLinesComment)
	CFIXCC_METHOD(TypicalTest)
	CFIXCC_METHOD(multiLinesCommentOnFewLines)
	CFIXCC_METHOD(multiLinesCommentInOneLine)
	CFIXCC_METHOD(multiLinesCommentAfterSingleLineComment)
	CFIXCC_METHOD(fewMultiLinesCommentsInOneString)
	CFIXCC_METHOD(fewMultiLinesCommentsInText)
CFIXCC_END_CLASS()

