#ifndef PLAYLIST_H
#define PLAYLIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct playlist {
    struct song *first;
};

struct song {
    char title[100];
    char artist[100];
    int duration;
    struct song *next;
};

void addSong(struct playlist *playlist, const char *title, const char *artist, int duration);

void removeSong(struct playlist *playlist, const char *key);

struct song* findsong(struct playlist *playlist, const char *key);

void printPlaylist(struct playlist *playlist);

void freePlaylist(struct playlist *playlist);

#endif