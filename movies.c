#include "movies.h"
#include <stdio.h>
#include <limits.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int getIntNumber()
{
    int n;
    while (1) {
        if (scanf_s("%d", &n) != 0) {
            if ((getchar()) != '\n' || n > INT_MAX || n < INT_MIN) {
                printf("Error: enter the correct number!\n");
                while ((getchar()) != '\n')
                    continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Error: enter the correct number!\n");
            while ((getchar()) != '\n')
                continue;
        }
    }
    return n;
}

char* inputString() {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 

    int length = strlen(buffer);

    char* str = (char*)malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        puts("Error!");
        return 0;
    }

    strncpy(str, buffer, length);
    str[length] = '\0';
    return str;
}

int my_strcmp(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (char)*str1 - (char)*str2;
        }
        str1++;
        str2++;
    }
    return (char)*str1 - (char)*str2;
}

Movie* createArrayOfMovies(int count) {
    Movie* movies = (Movie*)malloc(count * sizeof(Movie));
    if (!movies) {
        puts("Error!");
        exit(1);
    }
    return movies;
}

void freeMoviesArray(Movie* movies, int count) {
    for (int i = 0; i < count; i++) {
        free(movies[i].title);
    }
    free(movies);
}

void inputMovieFields(Movie* movie) {
    puts("Enter duration of movie (in minutes):");
    movie->duration = getIntNumber();
    puts("Enter title of movie");
    movie->title = inputString();
}

void printMovieFields(Movie* movie) {
    printf("Duration: %d min, Title: %s\n", movie->duration, movie->title);
}

void inputMovies(Movie* movies, int count) {
    if (!movies) puts("Error");
    for (int i = 0; i < count; i++) {
        puts("Enter information about movie:");
        printf("\nEnter duration: ");
        movies[i].duration = getIntNumber();
        printf("\nEnter title: ");
        movies[i].title = inputString();
        printf("\nEnter genre: ");
        strncpy(movies[i].genre.name, inputString(), GENRE_LEN - 1);
        movies[i].genre.name[GENRE_LEN - 1] = '\0';
        printf("\nEnter year: ");
        movies[i].year = getIntNumber();
    }
}

void printMovies(Movie* movies, int count) {
    printf("\nList of movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Duration: %d min, Genre: %s, Year: %d\n",
            movies[i].title, movies[i].duration, movies[i].genre.name, movies[i].year);
    }
}

void findMovieByTitle(Movie* movies, int count) {
    puts("Enter title of searched movie:");
    char* searchedTitle = inputString();
    puts("Result of search:");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (my_strcmp(movies[i].title, searchedTitle) == 0) {
            printMovieFields(&movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Movie is not found.\n");
    }
    free(searchedTitle);
}

void deleteMovieByDuration(Movie** movies, int* count) {
    puts("Enter maximum duration of movie (in minutes):");
    int maxDuration = getIntNumber();
    int newCount = 0;

    Movie* tempMovies = (Movie*)malloc(*count * sizeof(Movie));
    if (!tempMovies) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    for (int i = 0; i < *count; i++) {
        if ((*movies)[i].duration <= maxDuration) {
            tempMovies[newCount++] = (*movies)[i];
        }
        else {
            free((*movies)[i].title);
        }
    }

    free(*movies);

    *movies = (Movie*)realloc(tempMovies, newCount * sizeof(Movie));
    if (newCount > 0 && !*movies) {
        printf("Memory reallocation error!\n");
        exit(1);
    }

    *count = newCount;
}