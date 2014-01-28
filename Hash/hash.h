// The FNV hash, short for Fowler/Noll/Vo in honor of the creators, is a very powerful 
// algorithm that, not surprisingly, follows the same lines as Bernstein's modified hash 
// with carefully chosen constants. This algorithm has been used in many applications with 
// wonderful results, and for its simplicity, the FNV hash should be one of the first hashes 
// tried in an application. It is also recommended that the FNV website be visited for useful 
// descriptions of how to modify the algorithm for various uses.
// All code and comments were copied from: 
// http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
// Variable names were changed in certain places.
unsigned int Hash_fnv ( void* key, int length );

// Bob Jenkins is a well known authority on designing hash functions for table lookup. In 
// fact, another one of his hashes is considered state of the art for lookup. A considerably
// simpler algorithm of his design is the One-at-a-Time hash.
// All code and comments were copied from: 
// http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
// Variable names were changed in certain places.
unsigned int Hash_oat ( void* key, int length );

// The ELF hash function has been around for a while, and it is believed to be one of the 
// better algorithms out there. In my experience, this is true, though ELF hash does not 
// perform sufficiently better than most of the other algorithms presented in this tutorial 
// to justify its slightly more complicated implementation. It should be on your list of first
// functions to test in a new lookup implementation.
// All code and comments were copied from: 
// http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
// Variable names were changed in certain places.
unsigned int Hash_elf ( void* key, int length );