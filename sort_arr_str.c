// (ex. 5.1.4) sort an array of strings - strlen ascending

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* i, const void* j);

int main()
{   
    const char *words[5] = {"abc", "ab", "abcd", "a", "abcde"};
    const char **Pwords = words;

    qsort(Pwords, 5, sizeof(char*), compare);
    for (size_t i = 0; i < 5; i++){
        printf("%s ", *(Pwords + i)); // print words[i]
    }
    return 0;
}

int compare(const void* i, const void* j)
{
    const char* str1 = *(const char**)i;
    const char* str2 = *(const char**)j;
    return (strlen(str1) - strlen(str2));
}