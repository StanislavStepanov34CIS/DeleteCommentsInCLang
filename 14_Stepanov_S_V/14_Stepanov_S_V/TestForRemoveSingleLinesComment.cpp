#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveSingleLinesComment : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//								Тесты для removeSingleLinesComment
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
			{"	int a;"},
			{"//	singleComment"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{""},
			{"}"}
		};
		countString = removeSingleLinesComment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Текст без однострочных комментариев
	void textWithoutSingleLineComment()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"}"}
		};
		// Получение результата
		countString = removeSingleLinesComment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Однострочный комментарий внутри многострочного
	void singleLineCommentInMultiLinesComment()
	{
		// Входные данные
		int countString=6;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	//singleComment"},
			{"*/"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=6;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	//singleComment"},
			{"*/"},
			{"}"}
		};
		// Получение результата
		countString = removeSingleLinesComment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Однострочный комментарий после многострочного
	void singleLineCommentAfterMultiLinesComment()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	a++;*///singleComment"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	a++;*/"},
			{"}"}
		};
		// Получение результата
		countString = removeSingleLinesComment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Однострочный комментарий между двумя многострочными
	void singleLineCommentBetweenMultiLinesComments()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	a++;*///singleComment/*multiComment*/"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	a++;*/"},
			{"}"}
		};
		// Получение результата
		countString = removeSingleLinesComment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Несколько однострочных комментариев в тексте
	void fewSingleLineComments()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	//int a;"},
			{"//	singleComment"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	"},
			{""},
			{"}"}
		};
		// Получение результата
		countString = removeSingleLinesComment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Однострочный комментарий до многострочного
	void singleLineCommentBeforeMultiLinesComment()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"//	singleComment/*multiLinesComment*/"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{""},
			{"}"}
		};
		// Получение результата
		countString = removeSingleLinesComment(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
};

CFIXCC_BEGIN_CLASS(TestForRemoveSingleLinesComment)
	CFIXCC_METHOD(TypicalTest)
	CFIXCC_METHOD(textWithoutSingleLineComment)
	CFIXCC_METHOD(singleLineCommentInMultiLinesComment)
	CFIXCC_METHOD(singleLineCommentAfterMultiLinesComment)
	CFIXCC_METHOD(singleLineCommentBetweenMultiLinesComments)
	CFIXCC_METHOD(fewSingleLineComments)
	CFIXCC_METHOD(singleLineCommentBeforeMultiLinesComment)
CFIXCC_END_CLASS()

