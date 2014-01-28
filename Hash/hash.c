#include "hash.h"

unsigned int Hash_fnv ( void* key, int length ) {
	unsigned char *keyByteArray = key;
	unsigned int hash = 2166136261;
	unsigned int seed = 16777619;

	for ( int i = 0; i < length; i++ ) {
		hash = ( hash * seed ) ^ keyByteArray[i];
	}
	return ( hash );
}

unsigned int Hash_oat ( void* key, int length ) {
	unsigned char *keyByteArray = key;
	unsigned hash = 0;

	for ( int i = 0; i < length; i++ ) {
		hash += keyByteArray[i];
		hash += ( hash << 10 );
		hash ^= ( hash >> 6 );
	}
	hash += ( hash << 3 );
	hash ^= ( hash >> 11 );
	hash += ( hash << 15 );

	return ( hash );
}

unsigned int Hash_elf ( void* key, int length ) {
	unsigned char* keyByteArray = key;
	unsigned int hash = 0;
	unsigned int seed = 0;
	
	for ( int i = 0; i < length; i++ ) {
		hash = ( hash << 4 ) + keyByteArray[i];
		seed = hash & 0xf0000000L;

		if ( seed != 0 ) {
			hash ^= seed >> 24;
		}
		hash &= ~seed;
	}
	return ( hash );
}
