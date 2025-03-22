#ifndef MOVIES_H
#define MOVIES_H

enum {GENRE_LEN = 50};

typedef struct {
	char name[GENRE_LEN];
} Genre;

typedef struct {
	int duration;
	char* title;
	Genre genre;
	int year;
} Movie;

Movie* createArrayOfMovies(int count);

void freeMoviesArray(Movie* movies, int count);

int getIntNumber();

char* inputString();

int my_strcmp(char* str1, char* str2);

void inputMovieFields(Movie* movie);

void printMovieFields(Movie* movie);

void inputMovies(Movie* movies, int count);

void printMovies(const Movie* movies, int count);

void findMovieByTitle(Movie* movies, int count);

void deleteMovieByDuration(Movie* movies, int* count);

void menu();

#endif
