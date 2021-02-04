#include <cfixcc.h>
#include "Functions.h"
class TestForCheckTextForMultiComment : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//								����� ��� checkTextForMultiComment
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
			{"	/*multiComment"},
			{"	*/"},
			{"}"}
		};
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), true);
	}
	// ����� � ������������� ������������ �� ����� ����� ������
	void textWithMultiCommentPartOneLine()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	a++;/*multiComment*/"},
			{"}"}
		};
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), true);
	}
	// ����� ��� �������������� �����������
	void textWithoutMultiComment()
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
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), false);
	}
	// ����� ������������� ������������ ���� ������������
	void singleCommentBeforeMultiComment()
	{
		// ������� ������
		int countString=5;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"void main()"},
			{"{"},
			{"	int a;"},
			{"	//a++;/*multiComment*/"},
			{"}"}
		};
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), false);
	}
	// ������ �����
	void emptyText()
	{
		// ������� ������
		int countString=3;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""},
			{""},
			{""}
		};
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), false);
	}
	// ��������� ������������� � ������
	void fewMultiComments()
	{
		// ������� ������
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
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(checkTextForMultiComment(countString, answer), true);
	}
	// ���� ����� � ������������� �����������
	void allTextInComment()
	{
		// ������� ������
		int countString=4;
		char answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"/*void main()"},
			{"{"},
			{"	int a;"},
			{"}*/"}
		};
		// ��������� ���������� �������� � ������
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

