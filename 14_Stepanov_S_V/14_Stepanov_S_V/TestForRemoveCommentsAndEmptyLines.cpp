#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveCommentsAndEmptyLines : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//							Тесты для removeCommentsAndEmptyLines		
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
			{"/*	multiComment"},
			{"	*/"},
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
		countString = removeСommentsAndEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Пустой текст
	void emptyText()
	{
		// Входные данные
		int countString=2;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""},
			{""}
		};
		// Ожидаемые данные
		int expectedCountString=0;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
		};
		// Получение результата
		countString = removeСommentsAndEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Текст без комментариев
	void textWithoutComments()
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
		countString = removeСommentsAndEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Максимальное количество строк
	void maxSizeText()
	{
		// Входные данные
		int countString=20;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"#include <Functions.h>"},
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	int count;"},
			{"	count=0;"},
			{"	a++;"},
			{"	char b[10];"},
			{"	b++;"},
			{"	a=+b;"},
			{"	while(a!=1)"},
			{"	{"},
			{"		a--;"},
			{"		count++;"},
			{"	}"},
			{"	if(count==10)"},
			{"	{"},
			{"		b[1]=0;"},
			{"	}"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=20;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"#include <Functions.h>"},
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	int count;"},
			{"	count=0;"},
			{"	a++;"},
			{"	char b[10];"},
			{"	b++;"},
			{"	a=+b;"},
			{"	while(a!=1)"},
			{"	{"},
			{"		a--;"},
			{"		count++;"},
			{"	}"},
			{"	if(count==10)"},
			{"	{"},
			{"		b[1]=0;"},
			{"	}"},
			{"}"}
		};
		// Получение результата
		countString = removeСommentsAndEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Минимальное количество строк
	void minSizeText()
	{
		// Входные данные
		int countString=1;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int y;"},
		};
		// Ожидаемые данные
		int expectedCountString=1;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int y;"},
		};
		// Получение результата
		countString = removeСommentsAndEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Текст только из комментариев
	void textOnlyWithComments()
	{
		// Входные данные
		int countString=6;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"/*void main()"},
			{"{"},
			{"	int a;"},
			{"	multiComment"},
			{"	*/"},
			{"//}"}
		};
		// Ожидаемые данные
		int expectedCountString=0;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			
		};
		// Получение результата
		countString = removeСommentsAndEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// Комбинационный тест
	void comboTest()
	{
		// Входные данные
		int countString=13;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	multiComment"},
			{"	*/"},
			{"//	char mass[10];"},
			{"	if(!mass[0])"},
			{"/*	multiComment//single*/"},
			{"		a=0;"},
			{"	a++;/*multicomment*/"},
			{"	mass[1]=a;"},
			{"	mass[0]-=a;//singlecomment"},
			{"}"}
		};
		// Ожидаемые данные
		int expectedCountString=9;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	if(!mass[0])"},
			{"		a=0;"},
			{"	a++;"},
			{"	mass[1]=a;"},
			{"	mass[0]-=a;"},
			{"}"}
		};
		countString = removeСommentsAndEmptyLines(countString,answer);
		// Сравнение ожидаемого значения и ответа
		CFIXCC_ASSERT_EQUALS(textСomparison(countString, expectedCountString, answer, expected_answer), -1);
	}
};

CFIXCC_BEGIN_CLASS(TestForRemoveCommentsAndEmptyLines)
	CFIXCC_METHOD(TypicalTest)
	CFIXCC_METHOD(emptyText)
	CFIXCC_METHOD(textWithoutComments)
	CFIXCC_METHOD(maxSizeText)
	CFIXCC_METHOD(minSizeText)
	CFIXCC_METHOD(textOnlyWithComments)
	CFIXCC_METHOD(comboTest)
CFIXCC_END_CLASS()

