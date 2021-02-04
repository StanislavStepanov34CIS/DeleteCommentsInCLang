#include "Functions.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "testing.h"
int main()
{
	//setlocale(LC_ALL, "Russian");	// ������ ������� ���� ��� �������
	char text[MAX_ROWS][MAX_LENGTH] = {0};	// ����� ��� ���������
	int M;									// ���������� ����� � ������
	//puts("������� ����� ����� � ���������");
	scanf("%d", &M);						// ������� ���������� ����� � ������
	// ���� ���������� ����� ������� �� �����������...
	if(M<1 || M>20)
	{						
		error_printf("������������ ����� �����");	// ������ ������
		WAIT_ANY_KEY;
		return 0;	// ��������� ������
	}
	//puts("������� ������ ���������");
	//WAIT_ANY_KEY;
	//getchar();
	// ��� ������ ������ ������...
	for (int i=-1; i<M; i++)
		gets(text[i]);	// ������� ������ ������
	M=remove�ommentsAndEmptyLines(M,text);// ������� ��� ����������� � ������ ������, ������� ����� ���������� �����
	//puts("���������:");
	// ��� ������ ������ ������...
	for (int i=0; i<M; i++)
		puts(text[i]);	// ������� ������ �� �������
	WAIT_ANY_KEY;
	//getchar();
	return 0;	// ��������� ������ ���������
}
/*! 
	������� ������ ������ � ����������� � ������ ���������(������������� �����)
	\param[in] countString - ���������� ����� � ������
	\param[in|out] programmCode - ����� ��� ���������
	\return - ����� ���������� ����� � ������
*/
int remove�ommentsAndEmptyLines(int countString, char programmCode[MAX_ROWS][MAX_LENGTH])
{
	countString = removeMultiLines�omment(countString,programmCode);	// ������� �� ������ ������������� �����������
	countString = removeSingleLinesComment(countString,programmCode);	// ������� �� ������ ������������ �����������
	countString = removeEmptyLines(countString,programmCode);			// ������� �� ������ ������ ������
	return countString; // ���������� ���������� ����� � ������������ ������
}
/*!
	������� ������ ������ � ������
	\param[in] countString - ���������� ����� � ������
	\param[in|out] programmCode - ����� ��� ���������
	\return - ����� ���������� ����� � ������
*/
int removeEmptyLines(int countString, char programmCode[MAX_ROWS][MAX_LENGTH])
{
	// ��� ���� ����� ������...
	for (int i = 0; i < countString; i++)
		// ���� ������ ������...
		if (strlen(programmCode[i]) == 0)
		{
			// ��� ���� �����, ������� � "������"...
			for (int j = i; j < countString; j++)
				strcpy(programmCode[j], programmCode[j + 1]);	// �������� � ������ ��������� ������
			countString--;	// �������������� ���������� ����� � ������
			i--;	// �������������� ������ ������� ������
		}
		return countString;	// ���������� ���������� ����� � ������������ ������
}
/*! 
	������� ������������ ����������� � ������ ���������(���� "//")
	\param[in] countString - ���������� ����� � ������
	\param[in|out] programmCode - ����� ��� ���������
	\return - ����� ���������� ����� � ������
*/
int removeSingleLinesComment(int countString, char programmCode[MAX_ROWS][MAX_LENGTH])
{
	int index;		// ��������� ������ ������ ������������� �����������		
	bool strWithSingleComment;	// ���� �� � ������ ������������ �����������
	// ��� ���� ����� ������...
	for (int i = 0; i <= countString; i++)
	{
		// ���� � ������ ���� ������������ �����������...
		if (strWithSingleComment = strstr(programmCode[i], "//"))
		{
			index = strstr(programmCode[i], "//") - programmCode[i];		// ������� ������ ������������� �����������
			// ���� � ������ ���� ������ �������������� �����������...
			if (strstr(programmCode[i], "/*"))
			{
				int idxMultiComment = strstr(programmCode[i], "/*") - programmCode[i];	// ������� ������ �������������� �����������
				// ���� ������������� ����������� ���������� ������ �������������...
				if (index > idxMultiComment)
				{
					// ���� � ������ ���� ����� �������������� �����������...
					if (strstr(programmCode[i] + idxMultiComment, "*/"))
					{
						// ���� ������������� ����������� ������������� ����� ������ �������������...
						if (index < strstr(programmCode[i] + idxMultiComment, "*/") - programmCode[i])
							strWithSingleComment = false;	// �������, ��� � ������ ��� ������������� �����������
						// ����� ���� ������������ ����������� ���������� ����� ����� ������������� �����������..
						else if(strstr(programmCode[i], "*///"))
							index++;	// ��������������� ������ ������ ������������� �����������
					}
					// �����..
					else
						strWithSingleComment = false;	// �������, ��� � ������ ��� ������������� �����������
				}
			}
			// ���� � ������ ���� ������������ �����������...
			if (strWithSingleComment)
			{
				countString = removeSymbolSequence(countString, programmCode, i, index, i, strlen(programmCode[i]));	// ������� ������������ �����������
				i--;	// �������������� ������ ������� ������
			}
		}
	}
	return countString;	// ���������� ���������� ����� � ������������ ������	
}
/*! 
	������� ������������� ����������� � ������ ���������(���� "/ *...* /")
	\param[in] countString - ���������� ����� � ������
	\param[in|out] programmCode - ����� ��� ���������
	\return - ����� ���������� ����� � ������
*/
int removeMultiLines�omment(int countString, char programmCode[MAX_ROWS][MAX_LENGTH])
{
	int indexStart;	// ������ ������ �������������� �����������
	int indexEnd;	// ������ ����� �������������� �����������
	int startRow;					// ������ ������ � ������� �������������� �����������
	int	endRow;						// ������ ������ � ������ �������������� �����������
	bool textWithMultiComment = false;	// ���� ����� ��� ������������� ������������
	textWithMultiComment = checkTextForMultiComment(countString, programmCode);	// ���������� ���� �� � ������ ������������� �����������
	// ���� � ������ ���� ������������� �����������...
	while(textWithMultiComment)
	{
		startRow = 0;	// �������� � ������ ������
		// ���� �� ����� ������...
		while(startRow <= countString)
		{
			// ���� � ������ ���� ������ �������������� �����������...
			if(strstr(programmCode[startRow], "/*"))
				// ���� � ������ ���� ������ ������������� �����������...
				if(strstr(programmCode[startRow], "//"))
				{
					// ������������� ����������� ���������� ������ �������������...
					if(strstr(programmCode[startRow], "//") - programmCode[startRow] > strstr(programmCode[startRow], "/*") - programmCode[startRow])
						break;		// ��������� ������ ������ �������������� �����������
				}
				// �����...
				else
					break;	// ��������� ������ ������ �������������� �����������
			startRow++;	// �������������� ������ ������� ������
		}
		// ���� � ������ ���� ������ �������������� �����������...
		if(strstr(programmCode[startRow], "/*"))
		{
			endRow = startRow;	// �������� ������ ����� �������������� ����������� � ������ �������������
			indexStart = (strstr(programmCode[endRow], "/*") - programmCode[endRow]);	// ������� ������ �������������� ����������� � ������
			// ���� � ������ ��� ����� �������������� �����������...
			while(!strstr(programmCode[endRow], "*/"))
				endRow++;	// �������������� ������ ������� ������ � ������
			indexEnd = (strstr(programmCode[endRow], "*/") - programmCode[endRow]) + 1;	// ������� ������ ����� �������������� �����������
			countString = removeSymbolSequence(countString, programmCode, startRow, indexStart, endRow, indexEnd);	// ������� ������������� �����������
			textWithMultiComment = checkTextForMultiComment(countString, programmCode);	// ����������, ���� �� ��� � ������ ������������� �����������
		}
	}
	return countString;		// ���������� ���������� ����� � ������������ ������
}
/*!
	���������� ���� �� � ������ ������������� �����������
	\param[in] countString - ���������� ����� � ������
	\param[in] programmCode - ����� ��� ���������
	\return true ��� false - ���� �� � ������ ������������� ����������� ��� ���
*/
bool checkTextForMultiComment(int countString, const char programmCode[MAX_ROWS][MAX_LENGTH])
{
	bool textWithMultiComment = false;	// ���� ����� ��� ������������� ������������
	// ��� ���� ����� ������...
	for(int i = 0;i < countString; i++)
		// ���� � ������ ���� ������ �������������� �����������...
		if(strstr(programmCode[i], "/*"))
			// ���� � ������ ���� ������ ������������� �����������...
			if(strstr(programmCode[i], "//"))
			{
				// ���� ������������� ����������� ���������� ������ ������������� �����������...
				if(strstr(programmCode[i], "//") - programmCode[i] > strstr(programmCode[i], "/*") - programmCode[i])
					textWithMultiComment = true;	// ����� � ������������� ������������
			}
			// �����...
			else
				textWithMultiComment = true;	// ����� � ������������� ������������
	return textWithMultiComment;	// ���������� ���� �� � ������ ������������� �����������
}
/*!
	������� ������������������ �������� � ������
	\param[in] countString - ���������� ����� � ������
	\param[in|out] text - ����� ��� ���������
	\param[in] startRow - ��������� ������ ��� ��������
	\param[in] startPos - ������� ��� ������ �������� � ������
	\param[in] endRow - �������� ������ ��� ��������
	\param[in] endPos - ��������� ��������� ������
	\return - ����� ���������� ����� � ������
*/
int removeSymbolSequence(int countString, char text[MAX_ROWS][MAX_LENGTH], int startRow, int startPos, int endRow, int endPos)
{
	char bufStr[MAX_LENGTH] = {0};	// ��������� �������� ������
	// ���� ������������������ �������� ��� �������� ��������� � �������� ����� ������...
	if(startRow == endRow)
	{
		// ���� ������������������ �������� ��� �������� ���������� � ������ ������...
		if(startPos == 0)
		{
			// ���� ������������������ �������� ��� �������� ������������� �� � ����� ������...
			if(strlen(text[startRow]) != endPos+1)
			{
				strcpy(bufStr,text[startRow]);
				strcpy(text[startRow],"");
				strcpy(text[startRow], bufStr + endPos+1);	// �������� � ������ ��, ��� ����� ������������������ ��������
			}
			// �����...
			else
			{
				strcpy(text[startRow], "");	// ������� ������
				text[startRow][0]= '\0';	// ������ ������ ����� ������
			}
		}
		// �����...
		else
		{
			strcpy(bufStr, text[startRow]);					// �������� � ����� ������� ������
			strncpy(text[startRow], text[startRow], startPos);	// ��������� � ������ ������ ��, ��� �� ������������������
			text[startRow][startPos] = '\0';				// ������ ������ ����� ������
			strcat(text[startRow], bufStr + endPos + 1);			// ��������� ����� �� ������������������ �������� � ����� ��
		}
	}
	// �����...
	else
	{
		// ���� ������������������ ���������� �� � ������ ������...
		if(startPos != 0)
		{
			strncpy(text[startRow], text[startRow], startPos);	// ��������� � ������ ������ ��, ��� �� ������������������
			text[startRow][startPos] = '\0';					// ������ ������ ����� ������
		}
		// �����...
		else 
		{
			strcpy(text[startRow], "");	// ������� ������
			text[startRow][0]= '\0';	// ������ ������ ����� ������
		}
		// ���� ������������������ �������� ��� �������� ������������� �� � ����� ������...
		if(strlen(text[endRow]) - endPos != 0)			
			strcat(text[startRow], text[endRow] + endPos + 1);	// ��������� ������ �� ������������������ �������� � ����� ��
		int shift = endRow - startRow;	// ��������� ������ ������������������ � �������
		// ��� ����� ������, ����� ������ ������������������...
		for(int start = startRow + 1; start < countString; start++)
			strcpy(text[start], text[start + shift]);	// �������� ������ ������ ������
		countString = countString - shift;	// ��������� ����� ������ ������
	}
	return countString;	// ���������� ���������� ����� � ������������ ������
}
/*! 
	���������� ��� ������������� ������ � �� ���������� �����
	\param[in] countString - ���������� ����� � ����������� ������
	\param[in] expectedCountString - ��������� ���������� ����� � ������������ ������
	\param[in] answer - ����� ��� ������������ ����������
	\param[in] expectedAnswer - ��������� �����
	\return -2, ���� ���������� ����� ��������; -1, ���� ����� ��������� � ���������; ����� ������ � ��������� [0, 20], ���� ������ ������������
*/
int text�omparison(int countString, int expectedCountString, char answer[MAX_ROWS][MAX_LENGTH], char expectedAnswer[MAX_ROWS][MAX_LENGTH]) 
{ 
	// ���� ���������� ����� � ��������� � ������������ ������ �����������...
	if (countString != expectedCountString)
		return -2;	// ���������� ������� ����, ��� �������� � ���������� �����
	// �����...
	else
		// ��� ������ ������ ������...
		for (int i = 0; i < countString; i++)
			// ���� ������ ������������� ������ ���������� �� ������ ���������� ������...
			if (strcmp(answer[i], expectedAnswer[i])!=0)
				return i;	// ���������� ������ ������������ ������
	return -1;	// ���������� ������� ����, ��� ������������ ����� ������������� ����������
}