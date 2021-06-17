#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct data {
char name[10], gender[2];
int age;
char vote[2];
            };
char *party[] = {"BJP","CNG", "AAP","SVP"};
void calc();
int main()
{
    system("cls");
    int votes[]={0,0,0,0};
    int entry;
    int j;
    printf("Enter the number of entries:\n");
    scanf("%d", &entry);
    
    struct data *ptr;
    ptr = (struct data*)malloc(entry*sizeof(struct data));
    int i;
    for(i=0;i<entry;i++)
    {
        printf("The following parties are elligible to be voted to:\n");
        for(j=0;j<4;j++)
        {
        printf("%d %s\n", j+1, party[j]);
        }    
        printf("Enter the first inital of the abriviation, when asked for your vote.\n");
        printf("Enter your name: ");
        scanf("%s", (ptr+i)->name);
        printf("Enter your age: ");
        scanf("%d", &(ptr+i)->age);
        printf("Enter your Gender ie M or F: ");
        scanf("%s",(ptr +i)->gender);
        printf("The party you want to vote to: ");
        scanf("%s", (ptr+i)->vote);
        system("cls");
    }
    for(i=0;i<entry;i++)
    {
        if(*(ptr+i)->vote=='B'|| *(ptr+i)->vote=='b') votes[0]++;
        if(*(ptr+i)->vote=='C'|| *(ptr+i)->vote=='c') votes[1]++;
        if(*(ptr+i)->vote=='A'|| *(ptr+i)->vote=='a') votes[2]++;
        if(*(ptr+i)->vote=='S'|| *(ptr+i)->vote=='s') votes[3]++;
    }
    for(i=0;i<4;i++)
    {
        printf("%s : %d\n",party[i],votes[i]);
    }
    calc(votes, party);
    free(ptr);
    return 0;
}
void calc(int votes[],char *party[])
{
    int k,i,temp;
    float big,tot=0;
    big = votes[0];
    for(i=0;i<4;i++)
    {
        tot = tot + votes[i];
        if(big <= votes[i])
        {
            big=votes[i];
            k=i;
        }
    
    }
    printf("%s won with %.2f percentage.", party[k], 100*big/tot);
}