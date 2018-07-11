/*

The goal of this is to reverse a string without using a buffer.

*/

bool reverseString(char * str){
  char * end = str;
  char tmp;

  if (str){
    while(*end){
      end++;
    }
    end--;

    while(str<end){
      tmp = *str;
      *str++ = *end;
      *end-- = tmp;
    }
  }
  return str;
}

int main(){
  // reverseString();
  return 0;
}
