#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
//#define Space " "

//�ṹ��
typedef struct Student
{
	int  num;
	char id[20];
	char name[20];
	int examID; 
	char password[20];
	int  score;
	//struct Student*next;
}Stu;
Stu student[1000],student2[1000],*pa,*pb;
typedef struct question
{
	char num[20];
	char text[2000];
	char answer[100];
	struct question*next;
}question;
typedef struct mail
{
	int addressee;
	char addresseeName[20];
	int sender;
	char senderName[20];
	char text[10000];
	int read;
}Mail;
int m = 0; // ������ע���ѧ������  

//�˵�
void MainMenu()//���˵�
{
	printf("						��ѡ����ģ��\n");
	printf("				===================���˵�====================\n");
	printf("				*  		1.ѧ����½  		    *			  	\n");
	printf("				*		2.ѧ��ע��		    *				\n");
	printf("				*		3.��̨����		    *				 \n");
	printf("				*		0.�˳�ϵͳ		    *				 \n");
	printf("				=============================================\n");
}
//void Menu2()//ѧ��ע��˵�
//{
//	printf("1.ѧ��\n");
//	printf("2.����\n");
//	printf("3.����ȷ��\n");
//}
void MenuStudent(int t)//ѧ��2���˵�
{
	printf("===============ѧ��================\n");
	printf("1.����			2.��ѯ�ɼ�\n");
	printf("3.�ɼ�����		4.�޸�����\n");
	printf("5.���ز˵�                \n");
	printf("\n*%s ͬѧ���ã���ӭ��½������ϵͳ :)  ���ĵ�½IDΪ��%d\n", student[t].name, student[t].examID);

}
void MenuAdministrators()//����Ա2���˵�
{
	printf("				====================����̨��===================\n");
	printf("				*	1.������Ŀ	  2.ɾ����Ŀ        *		     \n");
	printf("				*	3.��д��Ŀ	  4.��ѯ��Ŀ        *			 \n");
	printf("				*	5.�鿴���	  6.�������        *			 \n");
	printf("				*	7.�����ʼ�        8.�����ʼ�        *	 \n");
	printf("				*	0.���沢�˳�                        *	 \n");
	printf("				=============================================\n");

}


//ѧ����


void exam(question *L,char num[],int t)
{
	question *s,*p=L->next;
	int flag=0;
	char jie[1000];	
	getchar();
	
	while(p->next)
	{
		if (strcmp(p->next->num,num)==0)//���ݱ�Ų�����Ŀ
		{
			printf("�������\n");
			scanf("%s",jie);
			if(strcmp(jie,p->next->answer)==0)
			{
				printf("��ȷ\n");
				student[t].score+=1;
				flag=1;
			}
			else
			{
				printf("����\n");
				flag=1;
			}
		}	
		p=p->next;
	}

}
void ScoreCount(int t)
{
	printf("%sͬѧ�����ĳɼ�Ϊ��%d��\n",student[t].name,student[t].score);

}

void passwordchange(int t)
{

	//int i;
	char password[20],new_p[20],decide_p[20],k[20]={0};
	b:
	printf("�����������ڵ�����\n");
	scanf("%s",password);
	if(strcmp(password,student[t].password)==0)
	{
		printf("������ȷ���������µ�����\n");
		scanf("%s",new_p);
		printf("��ȷ���µ�����\n");
		scanf("%s",decide_p);
		if(strcmp(new_p,decide_p)==0)
		{
			printf("ȷ��������ȷ\n");
			strcpy(student[t].password,k);
			strcpy(student[t].password,new_p);
		}
		else
		{
			printf("����������\n");
			goto b;
		}
	}
	else
	{
		printf("��������\n");
	}
}

void MenuStudent();
int Login(int p)//ѧ����½
{		
	int i;
	char id[20],password[20];
	getchar();
	printf("****ѧ���˵�½****\n");
	printf("�˺�:");
	scanf("%s",id);
	printf("����:");
	scanf("%s",password);
	getchar();

	for(i=0;i<1000;i++)
	{
		//if((strcmp(student[i].id,id)==0)&&(strcmp(student[i].password,password)==0))
		{
			printf("��½�ɹ���\n");
			//system("pause");
			p=0;
			break;
		
		}
		/*else
		{
			printf("��½ʧ�ܣ�\n");
			p=1;
			break;
		
		}*/
	
	}
	//MenuStudent();
	return p;
	
}


void Registers() //ע��
{  
    char t[20];
	FILE*tp;
	pa=student;
	pb=student2;
    printf("\n============ѧ��ע��==========\n");  
    if (m >= 1000)
	{  
        printf("�Ѵﵽ���ע��������\n");  
        return;  
    }  
	tp=fopen("student.txt","a+");
	printf("����:");
    scanf("%s",student[m].name);  
	printf("ѧ��:");
    scanf("%s",student[m].id); 
	printf("����:");
    scanf("%s",student[m].password);  
	printf("��ȷ������:");
    scanf("%s",t);  
    if (strcmp(student[m].password, t) == 0)
	{  
		student[m].examID=m+1000;
		getchar();
        printf("ע��ɹ�\n");  
		printf("���Ŀ���idΪ��%d",student[m].examID);
        m++; 
		//getchar();
		//MainMenu();
		// ������ע��ѧ������  
        // ... �����Ƿ������˵���ִ����������  
    } 
	else {  
        printf("���벻ƥ�䣬ע��ʧ��\n");  
    }
	//system("pause");
	printf("\n");
}
void rank()
{
	int i,j,tnum,z=1;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000-i-1;j++)
		if(student[j].score<student[j+1].score)
		{
			tnum=student[j].score;
			student[j].score=student[j+1].score;
			student[j+1].score=tnum;
		}
	}
	for(i=0;student[i].score!=0;i++)
	{
		printf("������%d ������%s ѧ�ţ�%s �÷֣�%d\n",z,student[i].name,student[i].id,student[i].score);
		z++;
	}
}

void Exit()
{
	printf("���������\n");
	exit(0);
}



//����Ա��
void SendEmail()
{
	char id[20];
	char text[2000];
	printf("����ID\n");
	scanf("%s",id);
	printf("������Ϣ\n");
	scanf("%s",text);
	printf("�Ѿ��ɹ���IDΪ%s��ѧ��������Ϣ!",id);
}
void AcceptEmail()
{
	printf("***Ŀǰ��0����Ϣδ����***");
}
question * InputData(FILE*fp)//��������
{
	int i,n;
	question *r,*p,*head;
	head=(question*)malloc(sizeof(question));
	head->next=NULL;
	r=head;
	printf("����������ݸ���");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(question*)malloc(sizeof(question));//������ʱ�ڵ�
		scanf("%s %s %s",p->num,p->text,p->answer);
		fwrite(p,sizeof(question),1,fp);//д������
		r->next=p;
		r=p;
	}
	printf("������ӽ���");
	fclose(fp);
	r->next=NULL;
	return head;
}
question * ReadData(FILE*fp)//��ȡ����
{
    int w,i;
    question *p,*head,*r;//����ָ�� ��ͷ�ڵ�
    head=(question*)malloc(sizeof(question));//�������ռ�
    head->next=NULL;
    r=head;
    fseek(fp,0,2);
    w=ftell(fp);
    rewind(fp);
    while(w!=ftell(fp))
    {
        p=(question*)malloc(sizeof(question));//��ʱ�ڵ��ַ
        fread(p,sizeof(question),1,fp);//��ȡ����
        r->next=p;
        r=p;
    }
    r->next=NULL;
    return head;
}
int Delete(question *L,char num[])//ɾ������
{
	question *s,*p=L->next;
	int delflag=0;
	while (p->next)
	{
		if (strcmp(p->next->num,num)==0)//���ݱ��ɾ��
		{
			s=p->next;
            p->next=s->next;
            free(s);
			delflag=1;
			break;
		}
		p=p->next;
	}
	return delflag;//�������1����ʾ��ɾ�����ݣ��������0����ʾɾ��ʧ�ܣ�û����Ҫɾ���ĳɼ����������ϵ�����
}
void SearchData(question *L,int type,char num[],char text[],char answer[])//��������
{
	question *s,*p=L->next;
	int flag=0;
	while(p->next)
	{
		if ((type==1)&&strcmp(p->next->num,num)==0)//���ݱ�Ų�����Ŀ
		{
			flag=1;
			printf("��ѯ���Ϊ:\n%s %s %s\n",p->next->num,p->next->text,p->next->answer);
		
		}
		if ((type==2)&&strcmp(p->next->text,text)==0)//�������ݲ�����Ŀ
		{
			flag=1;
			printf("��ѯ���Ϊ:\n%s %s %s\n",p->next->num,p->next->text,p->next->answer);
		}
		p=p->next;
	}
}
int XiugaiData(question *L,char num[]) //�޸�����
{
    question *p=L->next;
    int flag=0;
    while (p!=NULL) 
	{
        if(strcmp(p->num,num)==0)
		{
            printf("�������޸ĺ�����ݣ��Ծ��� ��� ���� �𰸣���\n");
            scanf("%s %s %s",p->num,p->text,p->answer); 
            flag = 1;
            break;
        }
        p = p->next;
    }
    if(!flag) 
	{
        printf("û���ҵ���������������,�޷��޸ġ�\n");
    }
    return flag;
}
void ShowList2(question*head)//��ʾ����
{
    question*p=head->next;
    while(p)
    {
        printf("%s %s\n",p->num,p->text);
        p=p->next;
    }
}
void ShowList(question*head)//��ʾ����
{
    question*p=head->next;
    while(p)
    {
        printf("%s %s %s\n",p->num,p->text,p->answer);
        p=p->next;
    }
}
void InsertData(question *L)//�������
{
	char k[2];
	question *r,*p,*s=L->next;
	while(s->next)
		s=s->next;
	r=s;
	//β�巨����
	do
	{
	p=(question*)malloc(sizeof(question));
	scanf("%s %s %s",p->num,p->text,p->answer);
	r->next=p;
	r=p;
	
	printf("��Ҫ������������������y����Ҫֹͣ����������n��");
	scanf("%s",&k);
	}while(strcmp(k,"y")==0);
	//if(strcmp(k,"y")==0)
	r->next=NULL;
	//InsertData(r);
}
int SaveList(question *L)//��������
{
	question *p=L->next;
	FILE*fp=NULL;
	if((fp=fopen("Exam.txt","w"))==NULL)
		return 0;
	while(p)
	{
		fwrite(p,sizeof(question),1,fp); 
		p=p->next;
	}
	fclose(fp);
	return 1;
}

void SortData(question*L,int flag)//�������
{
	question *p,*p1;
	char snum[20];
	char stext[2000];
	char sanswer[100];
	if(flag==0)
	{
	for(p=L->next;p!=NULL;p=p->next)
	{
		for(p1=p->next;p1!=NULL;p1=p1->next)
		{
			if(strcmp(p->num,p1->num)>=0)
			{
				strcpy(snum,p->num);
				strcpy(p->num,p1->num);
				strcpy(p1->num,snum);

				strcpy(stext,p->text);
				strcpy(p->text,p1->text);
				strcpy(p1->text,stext);

				strcpy(sanswer,p->answer);
				strcpy(p->answer,p1->answer);
				strcpy(p1->answer,sanswer);
			}

		}
	}
	}
	if(flag==1)
	{
	for(p=L->next;p!=NULL;p=p->next)
	{
		for(p1=p->next;p1!=NULL;p1=p1->next)
		{
			if(strcmp(p->num,p1->num)<=0)
			{
				strcpy(snum,p->num);
				strcpy(p->num,p1->num);
				strcpy(p1->num,snum);

				strcpy(stext,p->text);
				strcpy(p->text,p1->text);
				strcpy(p1->text,stext);

				strcpy(sanswer,p->answer);
				strcpy(p->answer,p1->answer);
				strcpy(p1->answer,sanswer);
			}
			
		}
	}
	}
}


void AS()
{
	int n,i,wflag=0,flag=1,k,type,stype,sflag;
	char kstr[100],kv[100];
    FILE *fp;
	question *head;
    //question *head=(question*)malloc(sizeof(question));

    if((fp=fopen("Exam.txt","r"))==NULL)
    {
        printf("���ļ�ʧ�ܣ�����������\n");
        if((fp=fopen("Exam.txt","w"))!=NULL)
        {
            wflag=1;
        }
    }
    if (wflag)
	{
        head=InputData(fp);
	}
    else
	{
        head=ReadData(fp);
	}
	while(flag)
	{
	scanf("%d",&stype);
	switch(stype)
	{
	case 1:
		{
		InsertData(head);
		break;
		}
	case 2:
		printf("����ɾ�����\n");
		scanf("%s",kv);
		Delete(head,kv);
		break;
	case 3:
		{
		printf("�޸����� ���");
		scanf("%s",kv);
		if(XiugaiData(head,kv))
		{
			printf("�޸ĳɹ�");
		}
		else 
		{
            printf("û���ҵ���������������\n");
        }
		break;
		}
	case 4:
		{
			printf("1������Ų��� 2.�������ݲ��� \n");
			scanf("%d",&i);
			getchar();
			if(i==1)
			{
				printf("�������");
				scanf("%s",kv);
				SearchData(head,i,kv,NULL,NULL);
			}
			if(i==2)
			{
				printf("��������");
				scanf("%s",kv);
				SearchData(head,i,NULL,kv,NULL);
			}
		}
		break;
	case 5:
		getchar();
		ShowList(head);
		break;
	case 6:
		printf("1.���� 2.����\n");
		scanf("%d",&i);
		if(i==1)
			SortData(head,0);
		if(i==2)
			SortData(head,1);
		break;
	case 7:
		SendEmail();
		break;
	case 8:
		AcceptEmail();
		break;
	case 0:
		sflag=SaveList(head);
		if(sflag==1)
		{
			printf("����ɹ���\n");
		}
		else
		{
			printf("����ʧ�ܣ�\n");
		}	
		Exit();
	 }
	}
}
int main()
{
	int n,flag=1,p=0,t,i,wflag=0,type,stype,sflag;
	char id[20],password[20],kstr[100],kv[100],ch;
	FILE*fp;
	question *head=(question*)malloc(sizeof(question));
	Stu *L=(Stu*)malloc(sizeof(Stu));
	for(i=0;i<1000;i++)
	{
		student[i].score=0;
	}
	a:
	MainMenu();
	scanf("%d",&n);
	switch(n)
	{
		case 1:

			p=Login(p);
			if(p==1)
				goto a;
			if(p==0)
				break;
			
		case 2:
			Registers();
			goto a;
			
			break;

		case 3:  
			printf("	***����Ա�˵�½***\n");
			while(flag)
			{
				getchar();
				printf("�˺�:");
				gets(id);
				printf("����:");
				gets(password);
				if(strcmp(id,"admin")==0&&strcmp(password,"1234")==0)  
				{  
					flag=0;
					MenuAdministrators();  
					AS();
				}  
				else
				{
					printf("����������");
				}
			}
			break;
		
		case 0:
			Exit();
			break;

	}
	
	system("cls");
	printf("�����뿼��id\n");
	scanf("%d",&t);     
	t=t-1000;
	while(1)
	{
		MenuStudent(t);
		b:
		printf("��ѡ����Ҫ����Ĺ���\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			fp=fopen("Exam.txt","r");
			head=ReadData(fp);
			getchar();
			ShowList2(head);
			
			printf("\n��ʼ����\n");
			while(1)
			{
			printf("���������:");
			scanf("%s",kv);
			exam(head,kv,t);
			printf("������Enter�������ϼ�Ŀ¼��ESC\n");
			ch=getch();
			if(ch==27)
			{
				break;
			}
			}
			break;
		case 2:
			ScoreCount(t);
			printf("������Enter�������ϼ�Ŀ¼��ESC\n");
			ch=getch();
			if(ch==27)
			{
				break;
			}
		
			break;
		case 3:
			rank();
			printf("������Enter�������ϼ�Ŀ¼��ESC\n");
			ch=getch();
			if(ch==27)
			{
				break;
			}
			break;
		case 4:
			passwordchange(t);
			break;
		case 5:
			goto a;
			break;

		
		}
	
	}
	
}