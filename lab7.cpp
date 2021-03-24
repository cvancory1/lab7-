/*

Chloe VanCory
lab7

Goals:  studying hash functions
        familiarity with list-concepts and memory management in c++


*/


#include <iostream>
#include <stdio.h>
#include <chrono>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include<unistd.h>
#include<cmath>
#include <string>

// #define W 32 // , smaller than the word size of the machine
// #define P 20 // smaller than W but not too small
// // #define A 5463458053 //10 digit prime number
// #define A 4 // prime num 





using namespace std;


//     x << y gives value of x * 2^y
//     x >> y gives value of x / 2^y
//returns ⌊(ax mod 2w)/2w−p⌋ by using the shift operator .. works on the bit level 
size_t Hash (  size_t key){
        

  size_t p = 10;// smaller than W but not too small
  size_t w = 32;// , smaller than the word size of the machine
  double A = 0.61803398; // prime num 

  size_t one = 1; // get 1 as a size_t
  printf ( "A=%lu\n",A);

  size_t s = A*size_t(one << w); //A* (1*2^W) // turn A into W bits long
  printf ( "s=%lu\n",s);

  size_t prod = key*s; // then multiply A * KEY *2^w for real with both being of the correct size
  printf ( "prod=%lu\n",prod);

  // End goal:k * A*2^w  then extract p most sig of w least sig looks like ie looks like wwwwwpppwww -> 00000000pp
   
  // restrict k to be only w least sig same as "masking" k with 1111..1 (w 1's in a row aka 2^w-1)

  size_t mask = (one<<w) - one;  // same as taking the modulus/ taking the signigicant bits
  printf ( "mask=%lu\n",mask);


  // all non-zeros after w least sig will
  // now be 0.
  size_t masked_key = prod & mask; // 
  printf ( "masked_key=%lu\n",masked_key);


  // get rid of the w-p rightmost
  size_t res = masked_key >> (w-p);
  printf ( "res=%lu\n",res);

  

  // return the p bits that are left
  return res;

}
size_t text2int(char* str){
  /*
   * One way: take each character as an ASCII
   * value, but then interpret the string as a
   * number in base-128. Because ASCII characters
   * have numerical value 0-127.
   *
   * e.g. for word "hello"
   * the value would be
   *
   * 'h'*pow(128,4) + 'e'*pow(128,3) + 'l'*pow(128,2) 
   *                + 'l'*pow(128,1) + 'o'*pow(128,0)
   *
   * Obviously longer strings will overflow the max
   * size_t value, but that's okay for now.
   */
  size_t sum = 0;
  int n = strlen(str);
  for(int i = 0; i<n; i++){
    // want: str[i] * 128^(n-1)
    // same as str[i] * 2^(7*(n-1))
    // same as str[i] << 7*(n-1)
    // make sure we convert to avoid prematurely overflowing
    //printf("Adding %c (%d)\n", str[i], str[i]);
    sum += size_t(str[i]) << 7*(n-i-1);
  }
  return sum;
}

size_t strToInt( char * str){
    srand(time(0));
    
    // makes 10 digits long 
    // 
   

  int length = strlen(str);
  size_t randomLetter= rand()%128;
//   char *str2 = strcat(str, )

// do something backwards
// and make eveerything a standard length of 32
  for(int i = strlen(str); i > 0; i--){
        cout<< "start of print"<<endl;
        cout<<str[i]+10<<endl;
  }



//   for(int i = 0; i<strlen(str2); i++){
//         cout<< "start of print"<<endl;
//       cout<<str2[i]<<endl;
//   }

//   return str2;
        
}

int main(){
//   char * str ={"C"};
//   cout<< "str to int"<<text2int(str)<<endl;
//   cout<<endl;
 
//   Hash(4112);

  char * str2= strToInt("H");
//   for(int i = 0; i<strlen(str2); i++){
//       cout<<str2[i]<<endl;
//   }


}