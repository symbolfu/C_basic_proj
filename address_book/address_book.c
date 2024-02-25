#include "address_book.h"


// common api
void stringinput(char* t, int lens, char* notice)
{
	char n[50];

	do
	{
		printf("%s", notice);
		scanf("%s", &n);
		if(strlen(n)>lens)
			printf("\n exceed the required length! \n"); /*超过lens值重新输入*/
	} while (strlen(n)>lens);

	strcpy(t, n);
}

// input records
void enter(link l)
{
	Node* p, * q;
	q = l;

	while (1)
	{
		p = (Node*)malloc(sizeof(Node));
		if (!p)
		{
			printf("memory malloc fail\n");
			return;
		}

		stringinput(p->data.name, 15, "enter name:");
		if (strcmp(p->data.name, "0") == 0)/*检测输入的姓名是否为0*/
			break;
		stringinput(p->data.city, 10, "enter city:");/*输入城市*/
		stringinput(p->data.province, 10, "enter province:");/*输入省*/
		stringinput(p->data.state, 10, "enter state:");/*输入国家*/
		stringinput(p->data.tel, 15, "enter telephone:");/*输入电话号码*/

		p->next = NULL;
		q->next = p;
		q = p;
	}
}

// delete record
void del(link l)
{
	Node* p, * q;
	char s[20];

	q = l;
	p = q->next;

	printf("enter name:");
	scanf("%s", s);/*输入要删除的姓名*/

	while (p)
	{
		if (strcmp(s, p->data.name) == 0)
		{
			// delet node
			q->next = p->next;
			free(p);
			printf("delete successfully!");
			break;
		}
		else
		{
			// loop
			q = p;
			p = q->next;
		}
	}
	// getch();
	while (getchar() != '\n');
}

// node display info
void display(Node* p)
{
	printf("MESSAGE \n");
	printf("name:%15s\n", p->data.name);
	printf("city:    %10s\n", p->data.city);
	printf("province:%10s\n", p->data.province);
	printf("state:   %10s\n", p->data.state);
	printf("telphone:%15s\n", p->data.tel);
}

// search
void search(link l)
{
	char name[20];
	Node* p;
	p = l->next;

	printf("enter name to find:");
	scanf("%s", name);/*输入要查找的名字*/

	while (p)
	{
		if (strcmp(p->data.name, name) == 0)
		{
			display(p);
			//getch();
			while (getchar() != '\n');
			break;
		}
		else
			p = p->next;
	}
}


// link display info
void list(link l)
{
	Node* p;
	p = l->next;

	while (p != NULL)
	{
		display(p);
		p = p->next;
	}
	// getch();
	while (getchar() != '\n');
}

// save
void save(link l)
{
	Node* p;
	FILE* fp;

	p = l->next;
	if ((fp = fopen("./addresslist", "wb")) == NULL)
	{
		printf("can not open file\n");
		exit(1);
	}

	printf("\nSaving file\n");
	while (p)
	{
		fwrite(p, sizeof(Node), 1, fp);
		p = p->next;
	}

	fclose(fp);
	// getch();
	while (getchar() != '\n');
}


// load file
void load(link l)
{
	Node* p, * r;
	FILE* fp;
	l->next = NULL;
	r = l;

	if ((fp = fopen("./addresslist", "rb")) == NULL)
	{
		printf("can not open file\n");
		exit(1);
	}

	printf("\nloading file\n");
	while (!feof(fp))
	{
		p = (Node*)malloc(sizeof(Node));

		if (!p)
		{
			printf("memory malloc fail!");
			return;
		}

		if (fread(p, sizeof(Node), 1, fp) != 1)
			break;
		else
		{
			p->next = NULL;
			r->next = p;
			r = p;
		}

		fclose(fp);
		// getch();
		while (getchar() != '\n');
	}



}

// menu
int menu_select()
{
	int i;
	printf("\n\n\t *************************ADDRESS LIST*************************\n");
	printf("\t|*			1.input record			      *|\n");
	printf("\t|*			2.delete record			      *|\n");
	printf("\t|*			3.list record			      *|\n");
	printf("\t|*			4.search record			      *|\n");
	printf("\t|*			5.save record			      *|\n");
	printf("\t|*			6.load record			      *|\n");
	printf("\t|*			7.Quit                                *|\n");
	printf("\t **************************************************************\n");
	do
	{
		printf("\n\tEnter your choice:");
		scanf("%d", &i);
	} while (i < 0 || i>7);
	return i;
}


int main()
{
	link l;
	l = (Node*)malloc(sizeof(Node));

	if (!l)
	{
		printf("\n allocate memory failure "); /*如没有申请到，输出提示信息*/
		return 0;             /*返回主界面*/
	}
	l->next = NULL;
	system("cls");

	while (l)
	{
		system("cls");
		switch (menu_select())
		{
		case 1: enter(l); break;
		case 2: del(l); break;
		case 3: list(l); break;
		case 4: search(l); break;
		case 5: save(l); break;
		case 6: load(l); break;
		case 7: exit(0);
		}
		while (getchar() != '\n');
	}
}



