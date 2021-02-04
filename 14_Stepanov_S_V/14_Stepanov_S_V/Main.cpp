#include "Functions.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "testing.h"
int main()
{
	//setlocale(LC_ALL, "Russian");	// Ставим русский язык для консоли
	char text[MAX_ROWS][MAX_LENGTH] = {0};	// Текст для обработки
	int M;									// Количество строк в тексте
	//puts("Введите число строк в программе");
	scanf("%d", &M);						// Получем количество строк в тексте
	// Если количество строк выходит за огранияения...
	if(M<1 || M>20)
	{						
		error_printf("Некорректное число строк");	// Выдаем ошибку
		WAIT_ANY_KEY;
		return 0;	// Завершаем работу
	}
	//puts("Введите строки программы");
	//WAIT_ANY_KEY;
	//getchar();
	// Для каждой строки текста...
	for (int i=-1; i<M; i++)
		gets(text[i]);	// Получем строку текста
	M=removeСommentsAndEmptyLines(M,text);// Удаляем все комментарии и пустые строки, получем новое количество строк
	//puts("Результат:");
	// Для каждой строки текста...
	for (int i=0; i<M; i++)
		puts(text[i]);	// Выводим строку на консоль
	WAIT_ANY_KEY;
	//getchar();
	return 0;	// Завершаем работу программы
}
/*! 
	Удаляет пустые строки и комментарии в тексте программы(многострочный текст)
	\param[in] countString - количество строк в тексте
	\param[in|out] programmCode - текст для обработки
	\return - новое количество строк в тексте
*/
int removeСommentsAndEmptyLines(int countString, char programmCode[MAX_ROWS][MAX_LENGTH])
{
	countString = removeMultiLinesСomment(countString,programmCode);	// Удаляем из текста многострочные комментарии
	countString = removeSingleLinesComment(countString,programmCode);	// Удаляем из текста однострочные комментарии
	countString = removeEmptyLines(countString,programmCode);			// Удаляем из текста пустые строки
	return countString; // Возвращаем количество строк в обработанном тексте
}
/*!
	Удаляет пустые строки в тексте
	\param[in] countString - количество строк в тексте
	\param[in|out] programmCode - текст для обработки
	\return - новое количество строк в тексте
*/
int removeEmptyLines(int countString, char programmCode[MAX_ROWS][MAX_LENGTH])
{
	// Для всех строк текста...
	for (int i = 0; i < countString; i++)
		// Если строка пустая...
		if (strlen(programmCode[i]) == 0)
		{
			// Для всех строк, начиная с "пустой"...
			for (int j = i; j < countString; j++)
				strcpy(programmCode[j], programmCode[j + 1]);	// Помещаем в строку следующую строку
			countString--;	// Декрементируем количество строк в тексте
			i--;	// Декрементируем индекс текущей строки
		}
		return countString;	// Возвращаем количество строк в обработанном тексте
}
/*! 
	Удаляет однострочные комментарии в тексте программы(типа "//")
	\param[in] countString - количество строк в тексте
	\param[in|out] programmCode - текст для обработки
	\return - новое количество строк в тексте
*/
int removeSingleLinesComment(int countString, char programmCode[MAX_ROWS][MAX_LENGTH])
{
	int index;		// Объявляем индекс начала однострочного комментария		
	bool strWithSingleComment;	// Есть ли в строке однострочные комментарии
	// Для всех строк текста...
	for (int i = 0; i <= countString; i++)
	{
		// Если в строке есть однострочный комментарий...
		if (strWithSingleComment = strstr(programmCode[i], "//"))
		{
			index = strstr(programmCode[i], "//") - programmCode[i];		// Находим начало однострочного комментария
			// Если в строке есть начало многострочного комментария...
			if (strstr(programmCode[i], "/*"))
			{
				int idxMultiComment = strstr(programmCode[i], "/*") - programmCode[i];	// Находим начало многострочного комментария
				// Если многострочный комментарий начинается раньше однострочного...
				if (index > idxMultiComment)
				{
					// Если в строке есть конец многострочного комментария...
					if (strstr(programmCode[i] + idxMultiComment, "*/"))
					{
						// Если многострочный комментарий заканчивается после начала однострочного...
						if (index < strstr(programmCode[i] + idxMultiComment, "*/") - programmCode[i])
							strWithSingleComment = false;	// Считаем, что в строке нет однострочного комментария
						// Иначе если однострочный комментарий начинается сразу после многосточного комментария..
						else if(strstr(programmCode[i], "*///"))
							index++;	// Инекрементируем индекс начала однострочного комментария
					}
					// Иначе..
					else
						strWithSingleComment = false;	// Считаем, что в строке нет однострочного комментария
				}
			}
			// Если в строке есть однострочный комментарий...
			if (strWithSingleComment)
			{
				countString = removeSymbolSequence(countString, programmCode, i, index, i, strlen(programmCode[i]));	// Удаляем однострочный комментарий
				i--;	// Декрементируем индекс текущей строки
			}
		}
	}
	return countString;	// Возвращаем количество строк в обработанном тексте	
}
/*! 
	Удаляет многострочные комментарии в тексте программы(типа "/ *...* /")
	\param[in] countString - количество строк в тексте
	\param[in|out] programmCode - текст для обработки
	\return - новое количество строк в тексте
*/
int removeMultiLinesСomment(int countString, char programmCode[MAX_ROWS][MAX_LENGTH])
{
	int indexStart;	// Индекс начала многострочного комментария
	int indexEnd;	// Индекс конца многострочного комментария
	int startRow;					// Индекс строки с началом многострочного комментария
	int	endRow;						// Индекс строки с концом многострочного комментария
	bool textWithMultiComment = false;	// Если текст без многострочных комментариев
	textWithMultiComment = checkTextForMultiComment(countString, programmCode);	// Определяем есть ли в тексте многострочный комментарий
	// Пока в тексте есть многострочные комментарии...
	while(textWithMultiComment)
	{
		startRow = 0;	// Начинаем с первой строки
		// Пока не конец текста...
		while(startRow <= countString)
		{
			// Если в строке есть начало многострочного комментария...
			if(strstr(programmCode[startRow], "/*"))
				// Если в строке есть начало однострочного комментария...
				if(strstr(programmCode[startRow], "//"))
				{
					// Многострочный комментарий начинается раньше однострочного...
					if(strstr(programmCode[startRow], "//") - programmCode[startRow] > strstr(programmCode[startRow], "/*") - programmCode[startRow])
						break;		// Перестаем искать начало многострочного комментария
				}
				// Иначе...
				else
					break;	// Перестаем искать начало многострочного комментария
			startRow++;	// Инкрементируем индекс текущей строки
		}
		// Если в строке есть начало многострочного комментария...
		if(strstr(programmCode[startRow], "/*"))
		{
			endRow = startRow;	// Начинаем искать конец многострочного комментария с начала однострочного
			indexStart = (strstr(programmCode[endRow], "/*") - programmCode[endRow]);	// Находим начало многострочного комментария в тексте
			// Пока в строке нет конца многострочного комментария...
			while(!strstr(programmCode[endRow], "*/"))
				endRow++;	// Инкрементируем индекс текущей строки в тексте
			indexEnd = (strstr(programmCode[endRow], "*/") - programmCode[endRow]) + 1;	// Находим индекс конца многострочного комментария
			countString = removeSymbolSequence(countString, programmCode, startRow, indexStart, endRow, indexEnd);	// Удаляем многострочный комментарий
			textWithMultiComment = checkTextForMultiComment(countString, programmCode);	// Определяем, есть ли ещё в тексте многострочный комментарий
		}
	}
	return countString;		// Возвращаем количество строк в обработанном тексте
}
/*!
	Определяет есть ли в тексте многострочные комментарии
	\param[in] countString - количество строк в тексте
	\param[in] programmCode - текст для обработки
	\return true или false - есть ли в тексте многострочный комментарий или нет
*/
bool checkTextForMultiComment(int countString, const char programmCode[MAX_ROWS][MAX_LENGTH])
{
	bool textWithMultiComment = false;	// Если текст без многострочных комментариев
	// Для всех строк текста...
	for(int i = 0;i < countString; i++)
		// Если в строке есть начало многострочного комментария...
		if(strstr(programmCode[i], "/*"))
			// Если в строке есть начало однострочного комментария...
			if(strstr(programmCode[i], "//"))
			{
				// Если многострочный комментарий начинается раньше однострочного комментария...
				if(strstr(programmCode[i], "//") - programmCode[i] > strstr(programmCode[i], "/*") - programmCode[i])
					textWithMultiComment = true;	// Текст с многострочным комментарием
			}
			// Иначе...
			else
				textWithMultiComment = true;	// Текст с многострочным комментарием
	return textWithMultiComment;	// Возвращаем есть ли в тексте многострочный комментарий
}
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
int removeSymbolSequence(int countString, char text[MAX_ROWS][MAX_LENGTH], int startRow, int startPos, int endRow, int endPos)
{
	char bufStr[MAX_LENGTH] = {0};	// Объявляем буферную строку
	// Если последовательность символов для удаления находится в пределах одной строки...
	if(startRow == endRow)
	{
		// Если последовательность символов для удаления начинается с начала строки...
		if(startPos == 0)
		{
			// Если последовательность символов для удаления заканчивается не в конце строки...
			if(strlen(text[startRow]) != endPos+1)
			{
				strcpy(bufStr,text[startRow]);
				strcpy(text[startRow],"");
				strcpy(text[startRow], bufStr + endPos+1);	// Копируем в строку всё, что после последовательности символов
			}
			// Иначе...
			else
			{
				strcpy(text[startRow], "");	// Очищаем строку
				text[startRow][0]= '\0';	// Ставим символ конца строки
			}
		}
		// Иначе...
		else
		{
			strcpy(bufStr, text[startRow]);					// Копируем в буфер текущую строку
			strncpy(text[startRow], text[startRow], startPos);	// Оставляем в строке только то, что до последовательности
			text[startRow][startPos] = '\0';				// Ставим символ конца строки
			strcat(text[startRow], bufStr + endPos + 1);			// Соединяем текст до последовательности символов и после неё
		}
	}
	// Иначе...
	else
	{
		// Если последовательность начинается не с начала строки...
		if(startPos != 0)
		{
			strncpy(text[startRow], text[startRow], startPos);	// Оставляем в строке только то, что до последовательности
			text[startRow][startPos] = '\0';					// Ставим символ конца строки
		}
		// Иначе...
		else 
		{
			strcpy(text[startRow], "");	// Очищаем строку
			text[startRow][0]= '\0';	// Ставим символ конца строки
		}
		// Если последовательность символов для удаления заканчивается не в конце строки...
		if(strlen(text[endRow]) - endPos != 0)			
			strcat(text[startRow], text[endRow] + endPos + 1);	// Соединяем строку до последовательности символов и после неё
		int shift = endRow - startRow;	// Вычисляем размер последовательности в строках
		// Для всего текста, после начала последовательности...
		for(int start = startRow + 1; start < countString; start++)
			strcpy(text[start], text[start + shift]);	// Сдвигаем каждую строку текста
		countString = countString - shift;	// Вычисляем новый размер текста
	}
	return countString;	// Возвращаем количество строк в обработанном тексте
}
/*! 
	Сравнивает два многострочных текста и их количество строк
	\param[in] countString - количество строк в обработаном тексте
	\param[in] expectedCountString - ожидаемое количество строк в обработанном тексте
	\param[in] answer - текст для обработанный программой
	\param[in] expectedAnswer - ожидаемый текст
	\return -2, если количество строк неверное; -1, если текст совпадает с ожидаемым; номер строки в диапозоне [0, 20], если строка неправильная
*/
int textСomparison(int countString, int expectedCountString, char answer[MAX_ROWS][MAX_LENGTH], char expectedAnswer[MAX_ROWS][MAX_LENGTH]) 
{ 
	// Если количество строк в ожидаемом и обработанном тексте различается...
	if (countString != expectedCountString)
		return -2;	// Возвращаем признак того, что различие в количестве строк
	// Иначе...
	else
		// Для каждой строки текста...
		for (int i = 0; i < countString; i++)
			// Если строка обработанного текста отличается от строки ожидаемого текста...
			if (strcmp(answer[i], expectedAnswer[i])!=0)
				return i;	// Возвращаем индекс неправильной строки
	return -1;	// Возвращаем признак того, что обработанный текст соответствует ожидаемому
}