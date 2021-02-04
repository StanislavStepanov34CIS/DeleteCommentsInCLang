#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveCommentsAndEmptyLines : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//							����� ��� removeCommentsAndEmptyLines		
	//-------------------------------------------------------------------------------------
	// ������� ����
	void TypicalTest()
	{
		// ������� ������
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
		// ��������� ������
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		countString = remove�ommentsAndEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������ �����
	void emptyText()
	{
		// ������� ������
		int countString=2;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""},
			{""}
		};
		// ��������� ������
		int expectedCountString=0;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
		};
		// ��������� ����������
		countString = remove�ommentsAndEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����� ��� ������������
	void textWithoutComments()
	{
		// ������� ������
		int countString=4;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"}
		};
		// ��������� ����������
		countString = remove�ommentsAndEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������������ ���������� �����
	void maxSizeText()
	{
		// ������� ������
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
		// ��������� ������
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
		// ��������� ����������
		countString = remove�ommentsAndEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����������� ���������� �����
	void minSizeText()
	{
		// ������� ������
		int countString=1;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int y;"},
		};
		// ��������� ������
		int expectedCountString=1;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int y;"},
		};
		// ��������� ����������
		countString = remove�ommentsAndEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����� ������ �� ������������
	void textOnlyWithComments()
	{
		// ������� ������
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
		// ��������� ������
		int expectedCountString=0;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			
		};
		// ��������� ����������
		countString = remove�ommentsAndEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// �������������� ����
	void comboTest()
	{
		// ������� ������
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
		// ��������� ������
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
		countString = remove�ommentsAndEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
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

