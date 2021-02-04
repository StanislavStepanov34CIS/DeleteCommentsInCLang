#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveSymbolSequence : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//							Тесты для removeSymbolSequence
	//-------------------------------------------------------------------------------------
	// Типовой тест
	void typicalTest()
	{
		// Входные данные
		int countString = 6;
		int startRow = 0;
		int startPos = 4;
		int endRow = 3;
		int endPos = 0;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"	return 0;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=3;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int a++;"},
			{"	return 0;"},
			{"}"}
		};
		// Получение результата
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Удаления начинается с начала текста
	void startString()
	{
		// Входные данные
		int countString = 6;
		int startRow = 0;
		int startPos = 0;
		int endRow = 2;
		int endPos = 4;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"	return 0;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"a;"},
			{"	a++;"},
			{"	return 0;"},
			{"}"}
		};
		// Получение результата
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Начало и конец последовательности символов для удаления на одной строке
	void singleString()
	{
		// Входные данные
		int countString = 6;
		int startRow = 2;
		int startPos = 1;
		int endRow = 2;
		int endPos = 4;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"	return 0;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=6;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int main()"},
			{"{"},
			{"	a;"},
			{"	a++;"},
			{"	return 0;"},
			{"}"}
		};
		// Получение результата
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Удаляет полность одну строку
	void removeString()
	{
		// Входные данные
		int countString = 6;
		int startRow = 3;
		int startPos = 0;
		int endRow = 3;
		int endPos = 4;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"	return 0;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=6;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int main()"},
			{"{"},
			{"	int a;"},
			{""},
			{"	return 0;"},
			{"}"}
		};
		// Получение результата
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Удаляет полность весь текст
	void removeAllText()
	{
		// Входные данные
		int countString = 6;
		int startRow = 0;
		int startPos = 0;
		int endRow = 5;
		int endPos = 0;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"	return 0;"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=1;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""}
		};
		// Получение результата
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
};

CFIXCC_BEGIN_CLASS(TestForRemoveSymbolSequence)
	CFIXCC_METHOD(typicalTest)
	CFIXCC_METHOD(startString)
	CFIXCC_METHOD(singleString)
	CFIXCC_METHOD(removeString)
	CFIXCC_METHOD(removeAllText)
CFIXCC_END_CLASS()

