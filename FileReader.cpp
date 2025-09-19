#include <stdio.h>


void TextParser (const char* file_name, void* buffer, long long* file_size, long long* strokes) {
    FILE* file = fopen(file_name, "r");

    struct stat file_info;
    fstat(fileno(file), &file_info);            //считываем размер файла
    long long*  file_size = file_info.st_size;

    void* buffer = calloc(file_size + 1, sizeof(char));


}



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

