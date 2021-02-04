#define MAX_ROWS 20		// максимальное количество строк в тексте для обработки
#define MAX_LENGTH 100	// максимальное длинна одной строки в тексте для обработки
//#include <conio.h>
#include <string.h>
/*! 
	Удаляет пустые строки и комментарии в тексте программы(многострочный текст)
	\param[in] countString - количество строк в тексте
	\param[in|out] programmCode - текст для обработки
	\return - новое количество строк в тексте
*/
int removeСommentsAndEmptyLines(int countString, char programmCode[MAX_ROWS][MAX_LENGTH]);
/*! 
	Удаляет однострочные комментарии в тексте программы(типа "//")
	\param[in] countString - количество строк в тексте
	\param[in|out] programmCode - текст для обработки
	\return - новое количество строк в тексте
*/
int removeSingleLinesComment(int countString, char programmCode[MAX_ROWS][MAX_LENGTH]);
/*! 
	Удаляет многострочные комментарии в тексте программы(типа "/ *...* /")
	\param[in] countString - количество строк в тексте
	\param[in|out] programmCode - текст для обработки
	\return - новое количество строк в тексте
*/
int removeMultiLinesСomment(int countString, char programmCode[MAX_ROWS][MAX_LENGTH]);
/*!
	Удаляет пустые строки в тексте программы
	\param[in] countString - количество строк в тексте
	\param[in|out] programmCode - текст для обработки
	\return - новое количество строк в тексте
*/
int removeEmptyLines(int countString, char programmCode[MAX_ROWS][MAX_LENGTH]);
/*!
	Определяет есть ли в тексте многострочные комментарии
	\param[in] countString - количество строк в тексте
	\param[in] programmCode - текст для обработки
	\return true или false - есть ли в тексте многострочный комментарий или нет
*/
bool checkTextForMultiComment(int countString, const char programmCode[MAX_ROWS][MAX_LENGTH]);
/*!
	Удаляет последовательность символов в тексте
	\param[in] countString - количество строк в тексте
	\param[in|out] text - текст для обработки
	\param[in] startRow - начальная строка для удаления
	\param[in] startPos - позиция для начала удаления в строке
	\param[in] endRow - конечная строка для удаления
	\param[in] endPos - последний удаляемый символ
	\return - новое количество строк в тексте
*/
int removeSymbolSequence(int countString, char text[MAX_ROWS][MAX_LENGTH], int startRow, int startPos, int endRow, int endPos);
/*! 
	Сравнивает два многострочных текста и их количество строк
	\param[in] countString - количество строк в обработаном тексте
	\param[in] expectedCountString - ожидаемое количество строк в обработанном тексте
	\param[in] answer - текст для обработанный программой
	\param[in] expectedAnswer - ожидаемый текст
	\return -2, если количество строк неверное; -1, если текст совпадает с ожидаемым; номер строки в диапозоне [0, 20], если строка неправильная
*/
int textСomparison(int countString, int expectedCountString, char answer[MAX_ROWS][MAX_LENGTH], char expectedAnswer[MAX_ROWS][MAX_LENGTH]);