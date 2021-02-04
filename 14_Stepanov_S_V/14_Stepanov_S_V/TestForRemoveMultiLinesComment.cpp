#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveMultiLinesComment : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//								����� ��� removeMultiLines�omment
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
			{"/*multiComment"},
			{"int a;	*/"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{""},
			{"}"}
		};
		// ��������� ����������
		countString = removeMultiLines�omment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������������� ����������� �� ��������� �����
	void multiLinesCommentOnFewLines()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{/*"},
			{"multiComment"},
			{"int a;	*/"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=3;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"}"}
		};
		// ��������� ����������
		countString = removeMultiLines�omment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������������� ����������� � ����� ������
	void multiLinesCommentInOneLine()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"/*multiComment*/"},
			{"	int a;"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{""},
			{"	int a;"},
			{"}"}
		};
		// ��������� ����������
		countString = removeMultiLines�omment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������������� ����������� ����� �������������
	void multiLinesCommentAfterSingleLineComment()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"///*multiComment*/"},
			{"	int a;"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"///*multiComment*/"},
			{"	int a;"},
			{"}"}
		};
		// ��������� ����������
		countString = removeMultiLines�omment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ��������� ������������� ������������ � ����� ������
	void fewMultiLinesCommentsInOneString()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"/*multiComment*/	char b[0];/*multiComment*/"},
			{"	int a;"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	char b[0];"},
			{"	int a;"},
			{"}"}
		};
		// ��������� ����������
		countString = removeMultiLines�omment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ��������� ������������� ������������ � ������
	void fewMultiLinesCommentsInText()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"/*multiComment*/"},
			{"/*	int a;*/"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{""},
			{""},
			{"}"}
		};
		// ��������� ����������
		countString = removeMultiLines�omment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
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

