#define MAX_ROWS 20		// ������������ ���������� ����� � ������ ��� ���������
#define MAX_LENGTH 100	// ������������ ������ ����� ������ � ������ ��� ���������
//#include <conio.h>
#include <string.h>
/*! 
	������� ������ ������ � ����������� � ������ ���������(������������� �����)
	\param[in] countString - ���������� ����� � ������
	\param[in|out] programmCode - ����� ��� ���������
	\return - ����� ���������� ����� � ������
*/
int remove�ommentsAndEmptyLines(int countString, char programmCode[MAX_ROWS][MAX_LENGTH]);
/*! 
	������� ������������ ����������� � ������ ���������(���� "//")
	\param[in] countString - ���������� ����� � ������
	\param[in|out] programmCode - ����� ��� ���������
	\return - ����� ���������� ����� � ������
*/
int removeSingleLinesComment(int countString, char programmCode[MAX_ROWS][MAX_LENGTH]);
/*! 
	������� ������������� ����������� � ������ ���������(���� "/ *...* /")
	\param[in] countString - ���������� ����� � ������
	\param[in|out] programmCode - ����� ��� ���������
	\return - ����� ���������� ����� � ������
*/
int removeMultiLines�omment(int countString, char programmCode[MAX_ROWS][MAX_LENGTH]);
/*!
	������� ������ ������ � ������ ���������
	\param[in] countString - ���������� ����� � ������
	\param[in|out] programmCode - ����� ��� ���������
	\return - ����� ���������� ����� � ������
*/
int removeEmptyLines(int countString, char programmCode[MAX_ROWS][MAX_LENGTH]);
/*!
	���������� ���� �� � ������ ������������� �����������
	\param[in] countString - ���������� ����� � ������
	\param[in] programmCode - ����� ��� ���������
	\return true ��� false - ���� �� � ������ ������������� ����������� ��� ���
*/
bool checkTextForMultiComment(int countString, const char programmCode[MAX_ROWS][MAX_LENGTH]);
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
int removeSymbolSequence(int countString, char text[MAX_ROWS][MAX_LENGTH], int startRow, int startPos, int endRow, int endPos);
/*! 
	���������� ��� ������������� ������ � �� ���������� �����
	\param[in] countString - ���������� ����� � ����������� ������
	\param[in] expectedCountString - ��������� ���������� ����� � ������������ ������
	\param[in] answer - ����� ��� ������������ ����������
	\param[in] expectedAnswer - ��������� �����
	\return -2, ���� ���������� ����� ��������; -1, ���� ����� ��������� � ���������; ����� ������ � ��������� [0, 20], ���� ������ ������������
*/
int text�omparison(int countString, int expectedCountString, char answer[MAX_ROWS][MAX_LENGTH], char expectedAnswer[MAX_ROWS][MAX_LENGTH]);