#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveEmptyLines : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//									����� ��� removeEmptyLines
	//-------------------------------------------------------------------------------------
	// ������� ����
	void TypicalTest()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{""},
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
		countString = removeEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����� ��� ������ �����
	void textWithoutEmptyLines()
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
		countString = removeEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����� ������ �� ������ �����
	void onlyEmptyLines()
	{
		// ������� ������
		int countString=3;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""},
			{""},
			{""}
		};
		// ��������� ������
		int expectedCountString=0;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
		};
		// ��������� ����������
		countString = removeEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����� � ������� ��������
	void textWithEmptyLines()
	{
		// ������� ������
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
		countString = removeEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����� ���������� � ������ ������
	void textStartWithEmptyLine()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""},
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
		countString = removeEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����� ������������� �� ������ ������
	void textEndWithEmptyLine()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"}"},
			{""}
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
		countString = removeEmptyLines(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
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

