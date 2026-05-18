#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int id;
    char name[30];
    float marks;
}student;
/*Function Prototypes*/
void inputRecord(int n,student s[]);
void storeRecord(int n,student s[],char* filename);
void displayMthRecord(int m,char* filename);
void deleteRecord(int del,char* filename);

int main()
{
    int n,m,del;
    printf("Enter the number of record: ");
    scanf("%d",&n);
    student s[n];
    inputRecord(n,s);
    storeRecord(n,s,"record.dat");
    printf("\nEnter the record to be displayed: ");
    scanf("%d",&m);
    displayMthRecord(m,"record.dat");
    printf("Enter the ID of student to be deleted:");
    scanf("%d",&del);
    deleteRecord(del,"record.dat");
    return 0;
}
void inputRecord(int n,student s[])
{
    printf("Enter the students record:\n");
    for(int i=0;i<n;i++)
    {
        printf("ID: ");
        scanf("%d",&s[i].id);

        printf("Name: ");
        scanf("%s",s[i].name);

        printf("Marks: ");
        scanf("%f",&s[i].marks);
    }
}
void storeRecord(int n,student s[],char* filename)
{
    FILE* fp;
    fp=fopen(filename,"wb");
    if(fp==NULL)
    {
        printf("Fiile cannot be opened");
        return;
    }
    fwrite(s,sizeof(student),n,fp);
    fclose(fp);
}
void displayMthRecord(int m,char* filename)
{
    FILE* f;
    student d;
    f=fopen(filename,"rb");
    if(f==NULL)
    {
        printf("File cannot be opened");
        return;
    }
    fseek(f,(m-1)*sizeof(student),SEEK_SET);
    fread(&d,sizeof(student),1,f);
    printf("ID: %d\n",d.id);
    printf("Name: %s\n",d.name);
    printf("Marks: %f\n",d.marks);
    fclose(f);
}
void deleteRecord(int del,char* filename)
{
    FILE *p,*temp;
    student r;
    p=fopen(filename,"rb");
    temp=fopen("temp.dat","wb");
    if(p==NULL || temp==NULL)
    {
        printf("File cannot be opened");
        return;
    }
    while(fread(&r,sizeof(student),1,p))
    {
        if(r.id != del)
        {
            fwrite(&r,sizeof(student),1,temp);
        }
    }
    fclose(p);
    fclose(temp);
    remove("remove.dat");
    rename("temp.dat","record.dat");
    printf("/nRecord deleted successfully/n");
}