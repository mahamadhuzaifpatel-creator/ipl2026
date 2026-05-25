#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int id;
    char name[100];
    float marks;
}student;
/*function prototypes*/
void input(student s[],int n);
void storeRecords(char filename[], student s[], int n);
int createIndex(char filename[], long pos[]);
void displayRecord(char filename[], long position);
int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid number of stubents:");
        return 0;
    }
    long pos[n];
    student s[n];
    input(s,n);
    storeRecords("student.txt",s,n);
    int index=createIndex("student.txt",pos);
    for(int i=0;i<index;i++)
    {
        printf("Record %d starts at %ld\n",i+1,pos[i]);
    }
    int req;
    printf("Enter record number to display:");
    scanf("%d",&req);
    if(req>=1 && req<=index)
    {
        displayRecord("student.txt",pos[req-1]);
    }
    else
    {
        printf("Invalid record number");
    }
    return 0;
}
void input(student s[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the ID: ");
        scanf("%d",&s[i].id);
        printf("Enter the name: ");
        scanf("%s",s[i].name);
        printf("Enter the marks: ");
        scanf("%f",&s[i].marks);
    }
}
void storeRecords(char filename[], student s[], int n)
{
    FILE *fp;
    fp=fopen(filename,"w");
    for(int i=0;i<n;i++)
    {
        fprintf(fp, "%d %s %.2f\n",s[i].id,s[i].name,s[i].marks);
    }
    fclose(fp);
}
int createIndex(char filename[], long pos[])
{
    FILE* f;
    student temp;
    int i=0;
    f=fopen(filename,"r");
    if(f==NULL)
    {
        printf("Unable to open the file");
        exit(1);
    }
    while(1)
    {
        pos[i]=ftell(f);
        if(fscanf(f,"%d %s %f",&temp.id,temp.name,&temp.marks)!=3)
        {
            break;
        }
        i++;
    }
    fclose(f);
    return i;
    
}
void displayRecord(char filename[], long position)
{
    FILE *f;
    student temp;
    f=fopen(filename,"r");
    if(f==NULL)
    {
        printf("File cannot be opened");
        exit (1);
    }
    fseek(f,position,SEEK_SET);
    fscanf(f,"%d %s %f",&temp.id,temp.name,&temp.marks);
    printf("Record found\n");
    printf("ID          : %d\n", temp.id);

    printf("Name        : %s\n", temp.name);

    printf("Marks       : %.2f\n", temp.marks);

    fclose(f);
}