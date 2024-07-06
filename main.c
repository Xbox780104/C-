#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
//#define Space " "

//结构体
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
int m = 0; // 跟踪已注册的学生数量  

//菜单
void MainMenu()//主菜单
{
	printf("						请选择功能模块\n");
	printf("				===================主菜单====================\n");
	printf("				*  		1.学生登陆  		    *			  	\n");
	printf("				*		2.学生注册		    *				\n");
	printf("				*		3.后台管理		    *				 \n");
	printf("				*		0.退出系统		    *				 \n");
	printf("				=============================================\n");
}
//void Menu2()//学生注册菜单
//{
//	printf("1.学号\n");
//	printf("2.密码\n");
//	printf("3.密码确认\n");
//}
void MenuStudent(int t)//学生2级菜单
{
	printf("===============学生================\n");
	printf("1.考试			2.查询成绩\n");
	printf("3.成绩排名		4.修改密码\n");
	printf("5.返回菜单                \n");
	printf("\n*%s 同学您好，欢迎登陆本答题系统 :)  您的登陆ID为：%d\n", student[t].name, student[t].examID);

}
void MenuAdministrators()//管理员2级菜单
{
	printf("				====================·后台·===================\n");
	printf("				*	1.增加题目	  2.删除题目        *		     \n");
	printf("				*	3.改写题目	  4.查询题目        *			 \n");
	printf("				*	5.查看题库	  6.排序题库        *			 \n");
	printf("				*	7.发送邮件        8.查收邮件        *	 \n");
	printf("				*	0.保存并退出                        *	 \n");
	printf("				=============================================\n");

}


//学生端


void exam(question *L,char num[],int t)
{
	question *s,*p=L->next;
	int flag=0;
	char jie[1000];	
	getchar();
	
	while(p->next)
	{
		if (strcmp(p->next->num,num)==0)//根据编号查找题目
		{
			printf("请输入答案\n");
			scanf("%s",jie);
			if(strcmp(jie,p->next->answer)==0)
			{
				printf("正确\n");
				student[t].score+=1;
				flag=1;
			}
			else
			{
				printf("错误\n");
				flag=1;
			}
		}	
		p=p->next;
	}

}
void ScoreCount(int t)
{
	printf("%s同学，您的成绩为：%d分\n",student[t].name,student[t].score);

}

void passwordchange(int t)
{

	//int i;
	char password[20],new_p[20],decide_p[20],k[20]={0};
	b:
	printf("请输入您现在的密码\n");
	scanf("%s",password);
	if(strcmp(password,student[t].password)==0)
	{
		printf("密码正确，请输入新的密码\n");
		scanf("%s",new_p);
		printf("请确认新的密码\n");
		scanf("%s",decide_p);
		if(strcmp(new_p,decide_p)==0)
		{
			printf("确认密码正确\n");
			strcpy(student[t].password,k);
			strcpy(student[t].password,new_p);
		}
		else
		{
			printf("新密码有误\n");
			goto b;
		}
	}
	else
	{
		printf("密码有误\n");
	}
}

void MenuStudent();
int Login(int p)//学生登陆
{		
	int i;
	char id[20],password[20];
	getchar();
	printf("****学生端登陆****\n");
	printf("账号:");
	scanf("%s",id);
	printf("密码:");
	scanf("%s",password);
	getchar();

	for(i=0;i<1000;i++)
	{
		//if((strcmp(student[i].id,id)==0)&&(strcmp(student[i].password,password)==0))
		{
			printf("登陆成功！\n");
			//system("pause");
			p=0;
			break;
		
		}
		/*else
		{
			printf("登陆失败！\n");
			p=1;
			break;
		
		}*/
	
	}
	//MenuStudent();
	return p;
	
}


void Registers() //注册
{  
    char t[20];
	FILE*tp;
	pa=student;
	pb=student2;
    printf("\n============学生注册==========\n");  
    if (m >= 1000)
	{  
        printf("已达到最大注册数量！\n");  
        return;  
    }  
	tp=fopen("student.txt","a+");
	printf("姓名:");
    scanf("%s",student[m].name);  
	printf("学号:");
    scanf("%s",student[m].id); 
	printf("密码:");
    scanf("%s",student[m].password);  
	printf("请确认密码:");
    scanf("%s",t);  
    if (strcmp(student[m].password, t) == 0)
	{  
		student[m].examID=m+1000;
		getchar();
        printf("注册成功\n");  
		printf("您的考试id为：%d",student[m].examID);
        m++; 
		//getchar();
		//MainMenu();
		// 更新已注册学生数量  
        // ... 可能是返回主菜单或执行其他操作  
    } 
	else {  
        printf("密码不匹配，注册失败\n");  
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
		printf("排名：%d 姓名：%s 学号：%s 得分：%d\n",z,student[i].name,student[i].id,student[i].score);
		z++;
	}
}

void Exit()
{
	printf("程序结束！\n");
	exit(0);
}



//管理员端
void SendEmail()
{
	char id[20];
	char text[2000];
	printf("发送ID\n");
	scanf("%s",id);
	printf("发送消息\n");
	scanf("%s",text);
	printf("已经成功向ID为%s的学生发送消息!",id);
}
void AcceptEmail()
{
	printf("***目前有0条消息未读！***");
}
question * InputData(FILE*fp)//输入数据
{
	int i,n;
	question *r,*p,*head;
	head=(question*)malloc(sizeof(question));
	head->next=NULL;
	r=head;
	printf("输入加入数据个数");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(question*)malloc(sizeof(question));//创建临时节点
		scanf("%s %s %s",p->num,p->text,p->answer);
		fwrite(p,sizeof(question),1,fp);//写入数据
		r->next=p;
		r=p;
	}
	printf("数据添加结束");
	fclose(fp);
	r->next=NULL;
	return head;
}
question * ReadData(FILE*fp)//读取数据
{
    int w,i;
    question *p,*head,*r;//三个指针 带头节点
    head=(question*)malloc(sizeof(question));//额外分配空间
    head->next=NULL;
    r=head;
    fseek(fp,0,2);
    w=ftell(fp);
    rewind(fp);
    while(w!=ftell(fp))
    {
        p=(question*)malloc(sizeof(question));//临时节点地址
        fread(p,sizeof(question),1,fp);//读取数据
        r->next=p;
        r=p;
    }
    r->next=NULL;
    return head;
}
int Delete(question *L,char num[])//删除数据
{
	question *s,*p=L->next;
	int delflag=0;
	while (p->next)
	{
		if (strcmp(p->next->num,num)==0)//根据编号删除
		{
			s=p->next;
            p->next=s->next;
            free(s);
			delflag=1;
			break;
		}
		p=p->next;
	}
	return delflag;//如果返回1，表示已删除数据；如果返回0，表示删除失败，没有与要删除的成绩或姓名符合的数据
}
void SearchData(question *L,int type,char num[],char text[],char answer[])//查找数据
{
	question *s,*p=L->next;
	int flag=0;
	while(p->next)
	{
		if ((type==1)&&strcmp(p->next->num,num)==0)//根据编号查找题目
		{
			flag=1;
			printf("查询结果为:\n%s %s %s\n",p->next->num,p->next->text,p->next->answer);
		
		}
		if ((type==2)&&strcmp(p->next->text,text)==0)//根据内容查找题目
		{
			flag=1;
			printf("查询结果为:\n%s %s %s\n",p->next->num,p->next->text,p->next->answer);
		}
		p=p->next;
	}
}
int XiugaiData(question *L,char num[]) //修改数据
{
    question *p=L->next;
    int flag=0;
    while (p!=NULL) 
	{
        if(strcmp(p->num,num)==0)
		{
            printf("请输入修改后的数据（试卷编号 题号 内容 答案）：\n");
            scanf("%s %s %s",p->num,p->text,p->answer); 
            flag = 1;
            break;
        }
        p = p->next;
    }
    if(!flag) 
	{
        printf("没有找到符合条件的数据,无法修改。\n");
    }
    return flag;
}
void ShowList2(question*head)//显示数据
{
    question*p=head->next;
    while(p)
    {
        printf("%s %s\n",p->num,p->text);
        p=p->next;
    }
}
void ShowList(question*head)//显示数据
{
    question*p=head->next;
    while(p)
    {
        printf("%s %s %s\n",p->num,p->text,p->answer);
        p=p->next;
    }
}
void InsertData(question *L)//添加数据
{
	char k[2];
	question *r,*p,*s=L->next;
	while(s->next)
		s=s->next;
	r=s;
	//尾插法插入
	do
	{
	p=(question*)malloc(sizeof(question));
	scanf("%s %s %s",p->num,p->text,p->answer);
	r->next=p;
	r=p;
	
	printf("若要继续输入数据请输入y，若要停止输入请输入n：");
	scanf("%s",&k);
	}while(strcmp(k,"y")==0);
	//if(strcmp(k,"y")==0)
	r->next=NULL;
	//InsertData(r);
}
int SaveList(question *L)//保存数据
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

void SortData(question*L,int flag)//题库排序
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
        printf("打开文件失败，请输入数据\n");
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
		printf("输入删除题号\n");
		scanf("%s",kv);
		Delete(head,kv);
		break;
	case 3:
		{
		printf("修改数据 题号");
		scanf("%s",kv);
		if(XiugaiData(head,kv))
		{
			printf("修改成功");
		}
		else 
		{
            printf("没有找到符合条件的数据\n");
        }
		break;
		}
	case 4:
		{
			printf("1根据题号查找 2.根据内容查找 \n");
			scanf("%d",&i);
			getchar();
			if(i==1)
			{
				printf("输入题号");
				scanf("%s",kv);
				SearchData(head,i,kv,NULL,NULL);
			}
			if(i==2)
			{
				printf("输入内容");
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
		printf("1.正序 2.逆序\n");
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
			printf("保存成功！\n");
		}
		else
		{
			printf("保存失败！\n");
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
			printf("	***管理员端登陆***\n");
			while(flag)
			{
				getchar();
				printf("账号:");
				gets(id);
				printf("密码:");
				gets(password);
				if(strcmp(id,"admin")==0&&strcmp(password,"1234")==0)  
				{  
					flag=0;
					MenuAdministrators();  
					AS();
				}  
				else
				{
					printf("请重新输入");
				}
			}
			break;
		
		case 0:
			Exit();
			break;

	}
	
	system("cls");
	printf("请输入考试id\n");
	scanf("%d",&t);     
	t=t-1000;
	while(1)
	{
		MenuStudent(t);
		b:
		printf("请选择你要输入的功能\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			fp=fopen("Exam.txt","r");
			head=ReadData(fp);
			getchar();
			ShowList2(head);
			
			printf("\n开始考试\n");
			while(1)
			{
			printf("请输入题号:");
			scanf("%s",kv);
			exam(head,kv,t);
			printf("继续按Enter，返回上级目录按ESC\n");
			ch=getch();
			if(ch==27)
			{
				break;
			}
			}
			break;
		case 2:
			ScoreCount(t);
			printf("继续按Enter，返回上级目录按ESC\n");
			ch=getch();
			if(ch==27)
			{
				break;
			}
		
			break;
		case 3:
			rank();
			printf("继续按Enter，返回上级目录按ESC\n");
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