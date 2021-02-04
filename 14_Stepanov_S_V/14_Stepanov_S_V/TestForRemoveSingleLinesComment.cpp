#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveSingleLinesComment : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//								����� ��� removeSingleLinesComment
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
			{"//	singleComment"},
			{"}"}
		};
		// ��������� ������
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
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ����� ��� ������������ ������������
	void textWithoutSingleLineComment()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	a++;"},
			{"}"}
		};
		// ��������� ����������
		countString = removeSingleLinesComment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������������ ����������� ������ ��������������
	void singleLineCommentInMultiLinesComment()
	{
		// ������� ������
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
		// ��������� ������
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
		// ��������� ����������
		countString = removeSingleLinesComment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������������ ����������� ����� ��������������
	void singleLineCommentAfterMultiLinesComment()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	a++;*///singleComment"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	a++;*/"},
			{"}"}
		};
		// ��������� ����������
		countString = removeSingleLinesComment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������������ ����������� ����� ����� ��������������
	void singleLineCommentBetweenMultiLinesComments()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	a++;*///singleComment/*multiComment*/"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"/*	a++;*/"},
			{"}"}
		};
		// ��������� ����������
		countString = removeSingleLinesComment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ��������� ������������ ������������ � ������
	void fewSingleLineComments()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	//int a;"},
			{"//	singleComment"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	"},
			{""},
			{"}"}
		};
		// ��������� ����������
		countString = removeSingleLinesComment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������������ ����������� �� ��������������
	void singleLineCommentBeforeMultiLinesComment()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"//	singleComment/*multiLinesComment*/"},
			{"}"}
		};
		// ��������� ������
		int expectedCountString=5;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{""},
			{"}"}
		};
		// ��������� ����������
		countString = removeSingleLinesComment(countString,answer);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
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

