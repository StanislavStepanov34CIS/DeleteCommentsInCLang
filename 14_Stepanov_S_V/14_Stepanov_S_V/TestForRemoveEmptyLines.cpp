#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveEmptyLines : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//									Тесты для removeEmptyLines
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
			{""},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// Получение результата
		countString = removeEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Текст без пустых строк
	void textWithoutEmptyLines()
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
		// Ожидаемые данные
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// Получение результата
		countString = removeEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Текст только из пустых строк
	void onlyEmptyLines()
	{
		// Входные данные
		int countString=3;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""},
			{""},
			{""}
		};
		// Ожидаемые данные
		int expectedCountString=0;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
		};
		// Получение результата
		countString = removeEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Текст с пустыми строками
	void textWithEmptyLines()
	{
		// Входные данные
		int countString=6;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{""},
			{"	int a;"},
			{""},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// Получение результата
		countString = removeEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Текст начинается с пустой строки
	void textStartWithEmptyLine()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""},
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// Получение результата
		countString = removeEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Текст заканчивается на пустую строку
	void textEndWithEmptyLine()
	{
		// Входные данные
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"},
			{""}
		};
		// Ожидаемые данные
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// Получение результата
		countString = removeEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
};

CFIXCC_BEGIN_CLASS(TestForRemoveEmptyLines)
	CFIXCC_METHOD(TypicalTest)
	CFIXCC_METHOD(textWithoutEmptyLines)
	CFIXCC_METHOD(onlyEmptyLines)
	CFIXCC_METHOD(textWithEmptyLines)
	CFIXCC_METHOD(textStartWithEmptyLine)
	CFIXCC_METHOD(textEndWithEmptyLine)
CFIXCC_END_CLASS()

