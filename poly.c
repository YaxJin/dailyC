#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node {  
  int cof;  
  int exp;      
  struct Node * next;  
}* poly = NULL;

void create() {
  struct Node * t, * last = NULL;  //temporary pointer, last pointer
  int num, i,intput_state;
  printf("Enter the number of terms:");
  scanf("%d", & num);
  printf("Enter each term with cof and exp\n");
  for (i = 0; i < num; i++) {     //loop
    t = (struct Node * ) malloc(sizeof(struct Node));  //create new node
    scanf("%d%d", &t->cof, &t->exp);                    //reading  2 data 
    t-> next = NULL;              //linking each node into linklist
    if (poly == NULL) {
      poly = last = t;
    } else {
      last -> next = t;
      last = t;
    }
  }
}

void Display(struct Node * p) {
  while (p) {
    if(!(p -> next))
        printf("%dx%d =", p -> cof, p -> exp);   //printing last node
    else
        printf("%dx%d + ", p -> cof, p -> exp);   //printing node
    p = p -> next;
  }
  printf("\n");
}

int inputNum(){
    int num, check;
    check = scanf( "%d", &num ) ;
    while( getchar() != '\n' ){
       // do nothing
    }
    
    if( check != 2 )
        printf("failure\n");
    else
    printf("valid integer followed by enter key\n");
    return num;
}

long Eval(struct Node * p, int x) {       //evalution
  long val = 0;
  while (p) {
    val += p -> cof * pow(x, p -> exp);
    p = p -> next;
  }
  return val;
}

int main() {
  create();
  Display(poly);
  printf("%ld\n", Eval(poly, 2));
  return 0;
}
