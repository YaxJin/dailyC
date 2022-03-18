#include<stdio.h>
#include<stdlib.h>
// #include<ctype.h>
#include<math.h>

struct Node {  
  int cof;  
  int exp;      
  struct Node * next;  
}* poly = NULL;

int inputNum(char *msg){
    int num;
    while(1){
        printf("%s", msg);
        scanf("%d", &num);
        if(num>0)
            return num;
        else
            printf("The number must more than 0!\n");
    }
    return num;
}

void create() {
  struct Node * t, * last = NULL;  //temporary pointer, last pointer
  int num, i;
//   printf("Enter the number of terms:");
  num = inputNum("Enter the number of terms:");
    //   scanf("%d", & num);
  printf("Enter each term with cof and exp\n");
  for (i = 0; i < num; i++) {
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
  //while();//TODO endless change X valus 
  printf("%ld\n", Eval(poly, 2));
  return 0;
}
