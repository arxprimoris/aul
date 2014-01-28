#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hash.h"

#define SIZE 50000

char get_random_character(void) {
	int random_char_int;	
	random_char_int = (rand() % 75) + 48;
	if((random_char_int > 57 && random_char_int < 65) ||
		(random_char_int > 90 && random_char_int < 97 && random_char_int != 95) ||
		(random_char_int > 122)) {		
		return (char) get_random_character();
	}
	else
		return (char) random_char_int;
}

void make_random_strings(unsigned char *strings[]) {
	int strlength;
	int i;
	int j;
	int k;
	for(i = 0; i < SIZE; i++) {		
		strlength = (rand() % 25) + 1;
		strings[i] = (unsigned char *) malloc((strlength+1) * sizeof(char));	
		for(j = 0; j < strlength; j++) {
			strings[i][j] = get_random_character();
		}
		for(k=0; k<(i-1); k++) {
			if(strcmp((char *) strings[i], (char *) strings[k]) == 0) {	
				i--;
				break;
			} 
		}
	}	
}

int linear_array_search(int *array, int search, int size) {
	int i;
	for(i=0; i<size; i++) {		
		if (array[i] == search)
			return i;	
	}
	return -1;
}

int check_key_duplicates(unsigned int *keys) {
	int i;
	int j;	
	int duplicate_count = 0;
	unsigned int keysearch = 0;
	int duplicate_track[SIZE];	
	for(i=0; i < SIZE; i++) {
		if(linear_array_search(duplicate_track, i, duplicate_count-1) != -1)
			continue;
		keysearch = keys[i];				
		for(j=0; j < SIZE; j++) {
			if(keysearch == keys[j] && i != j) {
				duplicate_track[duplicate_count] = j;
				duplicate_count++;
			}
		}
	}
	return duplicate_count;
}

int main(void) {
	unsigned char *strings[SIZE];
	unsigned int keys[SIZE];

	srand(time(0));
	make_random_strings(strings);
	for(int i = 0; i < SIZE; i++) {
		keys[i] = Hash_fnv(strings[i], strlen(strings[i])) % 499979;
	}
	printf("%d\n", check_key_duplicates(keys));
	return 0;
}