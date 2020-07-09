#include <stdio.h>

void print(int c){

    if (c < 0) {
        return;
    }

    printf("%d ", c);
    c--;
    print(c);

    c++;

    printf("%d ", c);

}

int main() {
   int c = 5;
   print(c);
   return 0;
}
/*How many numbers of 6 digits are possible with the property that the sum of their digits is 5?

/*1, 1, 4, 25, 196, __ , 17424
