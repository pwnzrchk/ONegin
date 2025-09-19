#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "COUNT.H"
#include "FILLING.H"
#include "SORT.H"

int main() {

    const char* file_name = "thriller.txt";
    FILE* file = fopen(file_name, "r");
    struct stat file_info;
    fstat(fileno(file), &file_info);                                                //Ну я нахуй сразу убираю обьявление дескриптора
    long long file_size = file_info.st_size;                                        // заебашьит в функцию

    printf("Размер файла: %lld\n", file_size);      // Убрать

    void* BUFFR = calloc(file_size + 1, sizeof(char));

    if (fread(BUFFR, sizeof(char), file_size, file) < file_size) {
        printf("Прочитано меньше символов, чем в файле\n");
        return 0;
    }

    size_t str_count = countSymb((char*)BUFFR, '\n', file_size + 1) + 1;            // зарефакторить strcount
    char** TEXT_PTR = (char**)calloc(str_count, sizeof(char**));                    // сбита нумерация строк на 1: i - строк,
    printf("Strcount: %zu\n\n", str_count);                                         //убрать нах                 i - 1  '\n''ов

    size_t strokesFilled = StrksToPtrs((char*)BUFFR, TEXT_PTR, str_count);
    if (strokesFilled < str_count) {
        printf("Прочитано %zu строк из %zu\n", strokesFilled, str_count);           //убрать гахуй
    }
    printf("Adress of rndm str: %p\n\n", TEXT_PTR[str_count-1]);                    //тоже сбита нумерация: по той же причине и функция подсчета
                                                                                    // уюрать гнахуй
                                                                                    

    BubleSort(TEXT_PTR, str_count-1);

    const char* FileOutName = "out.txt"; //FIXME - ёбни норма имя
    FILE* FileOut = fopen(FileOutName, "w");
    /*if (!FileOut) {
        perror("Не удалось открыть файл");
        return;
    }*/

    for (size_t i = 0; i < str_count - 1; i++) {
        fprintf(FileOut, "%s\n", TEXT_PTR[i]);
    }
    fclose(FileOut);

    return 0;

}
