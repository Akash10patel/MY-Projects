#include<stdio.h>
#include<string.h>

struct student
{int rollNo;
char name[35];
char gender; 
};

void addStudent()
{FILE *f;
struct student t,g;
int rollNo;
char name[35];
char gender,m;
printf("Student add module\n");
printf("Enter roll to add :");
scanf("%d",&rollNo);
fflush(stdin);
if(rollNo<=0)
{printf("Invalid RollNo.\n");
return ;}
f=fopen("student.sss","rb");
if(f!=NULL)
{while(1)
{fread(&t,sizeof(struct student),1,f);
if(feof(f))break;
if(rollNo==t.rollNo)
{printf("Roll number already assigned\n");
return ;}
}
fclose(f);}
printf("Enter Name of Student to add :");
fgets(name,36,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter gender of Student(M/F):");
gender=getchar();
fflush(stdin);
if(gender!='M'&&gender!='m'&&gender!='f'&&gender!='F')
{printf("Invalid input for Gender\n");
return ;}
printf("Save Details(Y/N):");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='Y')
{printf("Student not Added\n");
return ;}
g.rollNo=rollNo;
g.gender=gender;
strcpy(g.name,name);
f=fopen("student.sss","ab");
fwrite(&g,sizeof(struct student),1,f);
fclose(f);
printf("Student Added successfully...Press enter to continue..\n");
getchar();
fflush(stdin);
}

void removeStudent()
{printf("Student remove module\n");
FILE *f1,*f2;
int rollNo,found;
struct student t;
char m;
printf("Enter aroll number of student to remove :");
scanf("%d",&rollNo);
fflush(stdin);
if(rollNo<=0)
{printf("INvalid roll number\n");
return ;}
f1=fopen("student.sss","rb");
if(f1==NULL)
{printf("No student added yet\n");
return ;}
found=0;
while(1)
{fread(&t,sizeof(struct student),1,f1);
if(feof(f1)) break ;
if(t.rollNo==rollNo)
{found++;
break ;}
}
fclose(f1);
if(found==0)
{printf("Invalid roll number\n");
return ;}
printf("Student details \n");
printf("Name :%s\n",t.name);
if(t.gender=='m'||t.gender=='M')printf("Gender :Male\n");
if(t.gender=='f'||t.gender=='F')printf("Gender :Female\n");
printf("Do you to remove student from list(Y/M) :");
m=getchar();
if(m!='Y'&&m!='y')
{printf("Student not deleted\n");
return ;}
f1=fopen("student.sss","rb");
f2=fopen("tmp.ttt","wb");
while(1)
{fread(&t,sizeof(struct student),1,f1);
if(feof(f1)) break ;
if(t.rollNo!=rollNo)
{fwrite(&t,sizeof(struct student),1,f2);}
}
fclose(f1);
fclose(f2);
f1=fopen("student.sss","wb");
f2=fopen("tmp.ttt","rb");
while(1)
{fread(&t,sizeof(struct student),1,f2);
if(feof(f2))break ;
fwrite(&t,sizeof(struct student),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.ttt","w");
fclose(f2);
printf("Student removed successfully......\n");
printf("\n");
}


void searchStudent()
{printf("Student search Module\n");
FILE *f;
int rollNo,found;
struct student t;
printf("Enter a roll number to search student :");
scanf("%d",&rollNo);
fflush(stdin);
f=fopen("student.sss","rb");
if(f==NULL)
{printf("Invalid input\n");
return ;}
found=0;
while(1)
{fread(&t,sizeof(struct student),1,f);
if(feof(f))break;
if(rollNo==t.rollNo)
{found++;
break;}
}
fclose(f);
if(found==0)
{printf("Invalid roll number.....no student found for this roll number\n");
return ;}
printf("Student's Name %s\n",t.name);
if(t.gender=='m'||t.gender=='M')
{printf("Gender : Male\n");}
else
{printf("Gender : Female\n");}
printf("Press enter to continue.....\n");
getchar();
fflush(stdin);
}

void editStudent()
{ FILE *f,*f1;
int rollNo,found;
struct student t;
char m,name[35],gender;
printf("Student edit Module\n");
printf("Enter roll number to edit student details :");
scanf("%d",&rollNo);
fflush(stdin);
if(rollNo<0)
{printf("Invalid roll number\n");
return ;}
f=fopen("student.sss","rb");
if(f==NULL)
{printf("No student in List\n");
return ;}
found=0;
while(1)
{fread(&t,sizeof(struct student),1,f);
if(feof(f))break ;
if(t.rollNo==rollNo)
{found++;
break ;}
}
fclose(f);
if(found==0)
{printf("Invalid roll number\n");
return ;}
printf("Student details \n");
printf("Name :%s\n",t.name);
if(t.gender=='m'||t.gender=='M')printf("Gender :Male\n");
if(t.gender=='f'||t.gender=='F')printf("Gender :Female\n");
printf("Do you want to edit (Y/N) :");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='Y')
{printf("Student not edited\n");
return ;}
printf("Enter new details\n");
printf("Enter a name of student :");
fgets(name,35,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Write gender of student(M/F) :");
scanf("%c",&gender);
fflush(stdin);
f=fopen("student.sss","rb");
f1=fopen("tmp.ttt","wb");
while(1)
{
fread(&t,sizeof(struct student),1,f);
if(feof(f)) break;
if(t.rollNo==rollNo)
{strcpy(t.name,name);
 t.gender=gender;
}
 fwrite(&t,sizeof(struct student),1,f1);  
}
fclose(f);
fclose(f1);

f=fopen("student.sss","wb");
f1=fopen("tmp.ttt","rb");
while(1)
{fread(&t,sizeof(struct student),1,f1);
if(feof(f1)) break;
fwrite(&t,sizeof(struct student),1,f);
}
fclose(f);
fclose(f1);
f=fopen("tmp.ttt","w");
fclose(f1);
printf("Student edited successfully..press enter to continue...\n");
getchar();
fflush(stdin);
}

void drawLine()
{int x=0;
while(x<55)
{printf("-");
x++;}
printf("\n");
printf("S.No    ROLL NUMBER          NAME               GENDER  ");
printf("\n");
x=0;
while(x<55)
{printf("-");
x++;}
printf("\n");
}

void endLine()
{int x=0;
while(x<55)
{printf("-");
x++;}
printf("\n");
}

void displayList()
{
int x;
FILE *f;
struct student t;
f=fopen("student.sss","rb");
if(f==NULL)
{printf("NO student in list\n");
return ;}
printf("Studdents list\n");
drawLine();
x=1;
while(1)
{fread(&t,sizeof(struct student),1,f);
if(feof(f))break ;
printf("%3d %7d %22s",x,t.rollNo,t.name);
if(t.gender=='m'||t.gender=='M')printf("%20s\n","MALE");
else printf("%21s\n","FEMALE");
x++;}
fclose(f);
endLine();
printf("Press enter to continue......\n");
getchar();
fflush(stdin);
}


int main()
{int ch;
while(1)
{printf("Well come to students module\n");
printf("1.Add student\n");
printf("2.Remove Student\n");
printf("3.Search student\n");
printf("4.Edit student details\n");
printf("5.Display list of students\n");
printf("6.Exit\n");
printf("Enter your choice :");
scanf("%d",&ch);
fflush(stdin);
if(ch<1||ch>6)
{printf("Invalid input\n");}
else if(ch==1)addStudent();
else if(ch==2)removeStudent();
else if(ch==3)searchStudent();
else if(ch==4)editStudent();
else if(ch==5)displayList();
else if(ch==6)break;
}
return 0;}