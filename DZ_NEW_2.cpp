#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;
// функции к заданию 
int mystrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    if (*(unsigned char*)str1 < *(unsigned char*)str2) {
        return -1;
    }
    if (*(unsigned char*)str1 > *(unsigned char*)str2) {
        return 1;
    }

    return 0;
}

int StringToNumber(const char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
        else {
            return 0;
        }
        i++;
    }
    return result * sign;
}

char* NumberToString(int number) {
    char* result = (char*)malloc(20); 
    printf(result, "%d", number);
    return result;
}

char* Uppercase(char* str) {
    char* result = _strdup(str); 
    for (int i = 0; i < strlen(result); i++) {
        result[i] = toupper(result[i]);
    }
    return result;
}

char* Lowercase(char* str) {
    char* result = _strdup(str); 
    for (int i = 0; i < strlen(result); i++) {
        result[i] = tolower(result[i]); 
    }
    return result;
}

char* mystrrev(char* str) {
    int len = strlen(str);
    char* result = (char*)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        result[i] = str[len - i - 1];
    }

    result[len] = '\0';
    return result;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    //реализация функций на примере
    const char* str1 = "Hello";
    const char* str2 = "World";
    int compare_result = mystrcmp(str1, str2);

    if (compare_result == 0) {
        printf("Строки равны\n");
    }
    else if (compare_result == 1) {
        printf("Первая строка больше второй\n");
    }
    else {
        printf("Вторая строка больше первой\n");
    }

    char* str_num = NumberToString(1);
    printf("Число как строка: %s\n", str_num);
    free(str_num);

    int num = StringToNumber("456");
    printf("Строка как число: %d\n", num);

    char upper_str[] = "Hello";
    char* uppercased = Uppercase(upper_str);
    printf("Строка в верхнем регистре: %s\n", uppercased);
    free(uppercased);

    char lower_str[] = "WORLD";
    char* lowercased = Lowercase(lower_str);
    printf("Строка в нижнем регистре: %s\n", lowercased);
    free(lowercased);

    char reversed_str[] = "Reverse";
    char* reversed = mystrrev(reversed_str);
    printf("Реверсированная строка: %s\n", reversed);
    free(reversed);


    return 0;
}
