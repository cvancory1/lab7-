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
#include <string.h>
#include <iomanip>


using namespace std;


//     x << y gives value of x * 2^y
//     x >> y gives value of x / 2^y
//returns ⌊(ax mod 2w)/2w−p⌋ by using the shift operator .. works on the bit level 
size_t Hash ( size_t key){
        

  size_t p = 10;// smaller than W but not too small
  size_t w = 32;// , smaller than the word size of the machine
  double A = 0.5463458053; // prime num 

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
size_t text2int(  char* str){
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



size_t myHash1( const char * str){
    
  size_t fact = 7*6*5*4*3;
  int length = strlen(str);

  if(length ==1 ){
    return (str[0] * fact) %1299;

  }else if (length>=20){
    length =20;
  }

  size_t hashVal=1;
  size_t one = 1;
  for(int i = 0 ; i <length-2 ; i++){
    size_t ch = str[i];
    size_t next = str[i+1];

    hashVal+=  (ch+next)^1;
  
  }

  return hashVal;
        
}

size_t myHash2( const char * str){
  size_t hashVal=1.0;

  int length = strlen(str);

  if(length >= 20 ){
    char prefix[10];
    for(int i = 0 ; i <10 ; i++){
      prefix[i]=  str[i];
    } 

    char suffix[10];
    for(int i = length-11,  j=0; i <length ; i++, j++){
      suffix[j] =  str[i];
    } 

    hashVal = myHash1(prefix);
    hashVal += myHash1(suffix);

    return hashVal % 100000;


  }else if(length==1){
    hashVal = str[0] * 17; 
  }

  for(int i = 0 ; i <length ; i++){
    hashVal *=  str[i];
  }  
  hashVal= hashVal<< 3;

  return hashVal% 100000;
  
   
}

void printHex( size_t num){

}


int main(int argc, char** argv){


 size_t hashedVal= myHash1("A");
  cout<<hex<<hashedVal<<endl;

  hashedVal= myHash1("B");
  cout<<hex<<hashedVal<<endl;

   hashedVal= myHash1("C");
  cout<<hex<<hashedVal<<endl;

   hashedVal= myHash1("dog");
  cout<<hex<<hashedVal<<endl;

   hashedVal= myHash1("DOG");
  cout<<hex<<hashedVal<<endl;

   hashedVal= myHash1("god");
  cout<<"hashedVal<<"<<hashedVal<<endl; 
  
  hashedVal= myHash1("GOD");
  cout<<hex<<hashedVal<<endl;


  hashedVal= myHash1("abbbasbadzasdfadsfadsads");
  cout<<"hashedVal<<"<<hashedVal<<endl; 
  
  hashedVal= myHash1("bumble bee");
  cout<<hex<<hashedVal<<endl;

  hashedVal= myHash1("zzzzzzzzzzzzzzzzzzz");
  cout<<hex<<hashedVal<<endl;
 
  cout<<"---------Testing second hash---------"<<endl;

  // hashedVal= myHash2("A");
  // cout<<hex<<hashedVal<<endl;

  // hashedVal= myHash2("B");
  // cout<<hex<<hashedVal<<endl;

  // hashedVal= myHash2("C");
  // cout<<hex<<hashedVal<<endl;

  // hashedVal= myHash2("dog");
  // cout<<hex<<hashedVal<<endl;

  // hashedVal= myHash2("DOG");
  // cout<<hex<<hashedVal<<endl;

  // hashedVal= myHash2("god");
  // cout<<"hashedVal<<"<<hashedVal<<endl; 

  // hashedVal= myHash2("GOD");
  // cout<<hex<<hashedVal<<endl;


  // hashedVal= myHash2("abbbasbadzasdfadsfadsads");
  // cout<<"hashedVal<<"<<hashedVal<<endl; 

  // hashedVal= myHash2("bumble bee");
  // cout<<hex<<hashedVal<<endl;

  hashedVal= myHash2("zzzzzzzzzzzzzzzzzzzz");
  cout<<hex<<hashedVal<<endl;

  // char * str = argv[1];
  // printf("String in base-128 is: %lu...\n", text2int(str));

  //   printf("Hash result: %lu\n", Hash(text2int(str)));


  cout<<hex<<1500<<"\nhere\n"<<endl;

  return 0;


}