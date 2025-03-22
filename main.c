//Вариант 4
//1. Определить знак числа, не выполняя сравнение с 0.
//2. Структура содержит информацию о фильмах : длительность в минутах(число), название(указатель), вложенную структуру – жанр(строка фиксированной длины) и год выпуска.Найти фильмы с заданным названием.Удалить фильмы с длительностью больше заданной.
//
//
//
//Романчук Георгий Александрович
//22.03.2025


#include <stdio.h>
#include "sign_utils.h"
#include "movies.h"
#include <conio.h>

int main() {

    int num = getNumber();
    if (getSign) puts("Number is positive");
    else puts("Number is negative");
    puts(" ");

    printf("Enter number of movies: ");
    int count = getIntNumber();
    Movie* movies = createArrayOfMovies(count);
    if (!movies) puts("Error");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter array of Movies\n");
        printf("2. Print list of Movies\n");
        printf("3. Find Movie By Title\n");
        printf("4. Delete Movies Longer Than Your Duration\n");
        printf("0. Exit\n");
        printf("Choose action: ");

        char ch = _getch();
        if (ch == '1') {
            inputMovies(movies, count);
        }
        else if (ch == '2') {
            printMovies(movies, count);
        }
        else if (ch == '3') {
            findMovieByTitle(movies, count);
        }
        else if (ch == '4') {
            deleteMovieByDuration(&movies, &count);
        }
        else if (ch == '0') {
            break;
        }
    }

    freeMoviesArray(movies, count);

	return 0;
}
