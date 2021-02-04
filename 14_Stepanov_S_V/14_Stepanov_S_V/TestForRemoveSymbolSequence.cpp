#include <cfixcc.h>
#include "Functions.h"
class TestForRemoveSymbolSequence : public cfixcc::TestFixture
{
private:

public:
	//-------------------------------------------------------------------------------------
	//							����� ��� removeSymbolSequence
	//-------------------------------------------------------------------------------------
	// ������� ����
	void typicalTest()
	{
		// ������� ������
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
		// ��������� ������
		int expectedCountString=3;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"int a++;"},
			{"	return 0;"},
			{"}"}
		};
		// ��������� ����������
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// �������� ���������� � ������ ������
	void startString()
	{
		// ������� ������
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
		// ��������� ������
		int expectedCountString=4;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{"a;"},
			{"	a++;"},
			{"	return 0;"},
			{"}"}
		};
		// ��������� ����������
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������ � ����� ������������������ �������� ��� �������� �� ����� ������
	void singleString()
	{
		// ������� ������
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
		// ��������� ������
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
		// ��������� ����������
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������� �������� ���� ������
	void removeString()
	{
		// ������� ������
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
		// ��������� ������
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
		// ��������� ����������
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
	// ������� �������� ���� �����
	void removeAllText()
	{
		// ������� ������
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
		// ��������� ������
		int expectedCountString=1;
		char expected_answer[MAX_ROWS][MAX_LENGTH] =	
		{
			{""}
		};
		// ��������� ����������
		countString = removeSymbolSequence(countString, answer, startRow, startPos, endRow, endPos);
		// ��������� ���������� �������� � ������
		CFIXCC_ASSERT_EQUALS(text�omparison(countString, expectedCountString, answer, expected_answer), -1);
	}
};

CFIXCC_BEGIN_CLASS(TestForRemoveSymbolSequence)
	CFIXCC_METHOD(typicalTest)
	CFIXCC_METHOD(startString)
	CFIXCC_METHOD(singleString)
	CFIXCC_METHOD(removeString)
	CFIXCC_METHOD(removeAllText)
CFIXCC_END_CLASS()

