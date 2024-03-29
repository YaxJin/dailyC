#include <stdio.h>

struct student
{
    int id;
    int score;
};

void input(struct student list[], int N)
{
    for (int i = 0; i < N; i++)
    {
        // printf("Enter data for Student #%d\n", i + 1);
        fprintf(stderr, "Enter ID & score:");
        scanf("%d %d", &list[i].id,  &list[i].score);
    } 
}

void display(struct student list[], int N)
{
    printf("\nID\tscore\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t%d\n", list[i].id, list[i].score);
    } 
}

void busort(struct student list[], int N) //bubble sort
{
    struct student temp;   
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < (N - 1-i); j++)
        {
            if (list[j].id > list[j + 1].id)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
        }
    }
}

int main()
{
    struct student data[40]; //student upperbound
    int n;

    fprintf(stderr, "Number of records you want to key in:");
    scanf("%d", &n);

    input(data, n);
    // printf("\nBefore sorting");
    // display(data, n);
    busort(data, n);
    // printf("\nAfter sorting");
    display(data, n);

    return 0;
}

