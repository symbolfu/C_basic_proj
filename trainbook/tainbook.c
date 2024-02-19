#include "trainbook.h"


// ��ʼ������
void menu()
{
	puts("\n\n");
	puts("\t\t|------------------------------------------------------|");
	puts("\t\t|                   Booking Tickets                    |");
	puts("\t\t|------------------------------------------------------|");
	puts("\t\t|       0:quit the system                              |");
	puts("\t\t|       1:Insert a train information                   |");
	puts("\t\t|       2:Search a train information                   |");
	puts("\t\t|       3:Book a train ticket                          |");
	puts("\t\t|       4:Modify the train information                 |");
	puts("\t\t|       5:Show the train information                   |");
	puts("\t\t|       6:save information to file                     |");
	puts("\t\t|------------------------------------------------------|");
}

// ���һ���𳵵���Ϣ
void Traininfo(Link linkhead)
{
	struct node* p, * r, * s;
	char num[10];
	r = linkhead;
	s = linkhead->next;

	// find tail
	while (r->next != NULL)
	{
		r = r->next;
	}

	while (1)
	{
		printf("please input the number of the train(0-return)");
		scanf("%s", num);

		if (strcmp(num, "0") == 0)
			break;

		while (s)
		{
			if (strcmp(s->data.num, num) == 0)
			{
				printf("the train '%s'is existing!\n", num);
				return;
			}
			s = s->next;
		}

		p = (struct node*)malloc(sizeof(struct node));
		strcpy(p->data.num, num);

		printf("Input the city where the train will start:");
		scanf("%s", p->data.startcity);/*�����������*/

		printf("Input the city where the train will reach:");
		scanf("%s", p->data.reachcity);/*���뵽վ����*/

		printf("Input the time which the train take off:");
		scanf("%s", p->data.takeofftime);/*�������ʱ��*/

		printf("Input the time which the train receive:");
		scanf("%s", &p->data.receivetime);/*���뵽վʱ��*/

		printf("Input the price of ticket:");
		scanf("%d", &p->data.price);/*�����Ʊ��*/

		printf("Input the number of booked tickets:");
		scanf("%d", &p->data.ticketnum);/*����Ԥ��Ʊ��*/

		p->next = NULL;
		r->next = p;
		r = p;
		saveflag = 1;

	}
}

// ��ӡ��Ʊ��Ϣ
void printheader()
{
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}

void printdata(Node *q)
{
	Node* p;
	p = q;
	printf(FORMAT, DATA);
}


// ��ѯ����Ϣ
void searchtrain(Link l)
{
	Node* s[10], * r;
	int sel, k, i = 1;
	char str1[5], str2[10];

	if (!l->next)
	{
		printf("There is not any record !");
		return;
	}

	printf("Choose the way:\n1:according to the number of train;\n2:according to the city:\n");
	scanf("%d", &sel);/*����ѡ������*/
	
	if (sel == 1)
	{
		printf("input the number of train: ");
		scanf("%s", str1);
		r = l->next;
		while (r != NULL)
		{
			if (strcmp(r->data.num, str1) == 0)
			{
				s[i] = r;
				i++;
				break;
			}
			else
			{
				r = r->next;
			}
		}
		if (i == 0)
			printf("can not find!");
	}
	else if (sel == 2)
	{
		printf("Input the city  you want to go:");
		scanf("%s", str2);
		r = l->next;
		while (r != NULL)
		{
			if (strcmp(r->data.reachcity, str2) == 0)
			{
				s[i] = r;
				i++;
				r = r->next;
			}
			else
			{
				r = r->next;
			}
		}
	}

	// show info
	if (i == 0)
		printf("can not find!");
	else
	{
		printheader();
		for (k = 0; k < i; k++)
			printdata(s[k]);
	}
}

// ��Ʊ��ģ��
void Bookticket(Link l, bookLink k)
{
	Node* r[10], * p;
	char ch[2], tnum[10], str[10], str1[10], str2[10];
	book* q, * h;
	int i = 0, t = 0, flag = 0, dnum;
	q = k;

	while (q->next != NULL)
	{
		q = q->next;
	}

	printf("Input the city you want to go: ");
	scanf("%s", &str);/*����Ҫ����ĳ���*/

	// ����ƥ��Ļ���Ϣ
	p = l->next;
	while (p != NULL)
	{
		if (strcmp(p->data.reachcity, str) == 0)
		{
			r[i] = p;
			i++;
		}
		p = p->next;
	}

	printf("\n\nthe number of record have %d\n", i);
	printheader();
	for (t = 0; t < i; t++)
		printdata(r[t]);

	if (i == 0)
	{
		printf("\nSorry!Can't find the train for you!\n");
	}
	else
	{
		printf("\ndo you want to book it?<y/n>\n");
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
		{
			h = (book*)malloc(sizeof(book));
			printf("Input your name: ");
			scanf("%s", &str1);
			strcpy(h->data.name, str1);

			printf("Input your id: ");
			scanf("%s", &str2);
			strcpy(h->data.num, str2);

			printf("please input the number of the train:");
			scanf("%s", tnum);

			for ( t = 0; t < i; t++)
			{
				if (strcmp(r[t]->data.num, tnum) == 0)
				{
					if (r[t]->data.ticketnum < 1)
					{
						printf("sorry,no ticket!");
						//sleep(2);
						return;
					}
					printf("remain %d tickets\n", r[t]->data.ticketnum);
					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				printf("input error");
				//sleep(2);
				return;
			}
			printf("Input your bookNum: ");
			scanf("%d", &dnum);
			r[t]->data.ticketnum = r[t]->data.ticketnum - dnum;/*��Ʊ�ɹ���ɹ�����Ʊ����Ӧ����*/
			h->data.bookNum = dnum;
			h->next = NULL;
			q->next = h;
			q = h;
			printf("\nLucky!you have booked a ticket!");
			while (getchar != '\n');
			saveflag = 1;
		}
	}
}

// �޸Ļ���Ϣ

void Modify(Link l)
{
	Node* p;
	char tnum[10], ch;
	p = l->next;
	if (!p)
	{
		printf("\nthere isn't record for you to modify!\n");
		return;
	}
	else
	{
		printf("\nDo you want to modify it?(y/n)\n");
		getchar();
		scanf("%c", &ch);
		if (ch == 'y' || ch == 'Y')
		{
			printf("\nInput the number of the train:");
			scanf("%s", tnum);

			while (p != NULL)
			{
				if (strcmp(p->data.num, tnum) == 0)
					break;
				else
					p = p->next;
			}

			if (p)
			{
				printf("Input new number of train:");
				scanf("%s", &p->data.num);

				printf("Input new city the train will start:");
				scanf("%s", &p->data.startcity);

				printf("Input new city the train will reach:");
				scanf("%s", &p->data.reachcity);

				printf("Input new time the train take off");
				scanf("%s", &p->data.takeofftime);

				printf("Input new time the train reach:");
				scanf("%s", &p->data.receivetime);

				printf("Input new price of the ticket::");
				scanf("%d", &p->data.price);

				printf("Input new number of people who have booked ticket:");
				scanf("%d", &p->data.ticketnum);

				printf("\nmodifying record is sucessful!\n");
				saveflag = 1;
			}
			else
				printf("\tcan't find the record!");

		}
	}
}

// ��ʾ�г���Ϣ
void showtrain(Link l)
{
	Node* p;
	p = l->next;
	printheader();
	if (l->next == NULL)
		printf("no records!");
	else
		while (p != NULL)
		{
			printdata(p);
			p = p->next;
		}
}

// �������Ϣ
void SaveTrainInfo(Link l)
{
	FILE* fp;
	Node* p;
	int count = 0, flag = 1;
	fp = fopen("./train.txt", "wb");

	if (fp == NULL)
	{
		printf("the file can't be opened!");
		return;
	}

	p = l->next;
	while (p)
	{
		if (fwrite(p, sizeof(Node), 1, fp) == 1)
		{
			p = p->next;
			count++;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	
	if (flag)
	{
		printf(" saved %d train records\n", count);
		saveflag = 0;
	}
	fclose(fp);
}

// ���涩Ʊ�˵���Ϣ
void SaveBookInfo(bookLink k)
{
	FILE* fp;
	book* p;
	int count = 0, flag = 1;
	fp = fopen("./man.txt", "wb");

	if (fp == NULL)
	{
		printf("the file can't be opened!");
		return;
	}

	p = k->next;
	while (p)
	{
		if (fwrite(p, sizeof(book), 1, fp) == 1)
		{
			p = p->next;
			count++;
		}
		else
		{
			flag = 0;
			break;
		}
	}

	if (flag)
	{
		printf(" saved %d booking records\n", count);
		saveflag = 0;
	}
	fclose(fp);
}


// �������
main()
{
	FILE* fp1, * fp2;
	Node* p, * r;
	char ch1, ch2;
	Link l;
	bookLink k;
	book* t, * h;
	int sel;

	// ��������header
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	r = l;
	
	k = (book*)malloc(sizeof(book));
	k->next = NULL;
	h = k;

	fp1 = fopen(".\\train.txt", "ab+");
	if (fp1 == NULL)
	{
		printf("can't open the file!");
		return 0;
	}

	while (!feof(fp1))
	{
		p = (Node*)malloc(sizeof(Node));
		if (fread(p, sizeof(Node), 1, fp1) == 1)
		{   
			// ��������
			p->next = NULL;
			r->next = p;
			r = p;
		}
	}
	fclose(fp1);

	fp2 = fopen("./man.txt", "ab+");
	if ((fp2 == NULL))
	{
		printf("can't open the file!");
		return 0;
	}

	while (!feof(fp2))
	{
		t = (book*)malloc(sizeof(book));
		if (fread(t, sizeof(book), 1, fp2) == 1)
		{
			// ��������
			t->next = NULL;
			h->next = t;
			h = t;
		}
	}
	fclose(fp2);
	
	// ���ܳ���
	while (1)
	{
		system("CLS");
		menu();
		printf("\tplease choose (0~6):  ");
		scanf("%d", &sel);
		system("CLS");

		if (sel == 0)
		{
			if (saveflag == 1)
			{
				getchar();
				printf("\nthe file have been changed!do you want to save it(y/n)?\n");
				scanf("%c", &ch1);
				if (ch1 == 'y' || ch1 == 'Y')
				{
					SaveBookInfo(k);
					SaveTrainInfo(l);
				}
			}
			printf("\nThank you!!You are welcome too\n");
			break;
		}
		switch (sel)
		{
		case 1: Traininfo(l); break;
		case 2: searchtrain(l); break;
		case 3: Bookticket(l, k); break;
		case 4: Modify(l); break;
		case 5: showtrain(l); break;
		case 6: SaveTrainInfo(l); SaveBookInfo(k); break;
		default:return;
		}
		printf("\nplease press any key to continue.......");
		while (getchar != '\n');
	}


}









