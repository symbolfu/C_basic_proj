#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>

#define HEADER1 " -------------------------------BOOK TICKET----------------------------------\n"
#define HEADER2 " |  number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n"
#define HEADER3 " |----------|----------|----------|-----------|-----------|-----|------------|\n"
#define FORMAT  " |%-10s|%-10s|%-10s|%-10s |%-10s |%5d|  %5d     |\n"
#define DATA p->data.num,p->data.startcity,p->data.reachcity,p->data.takeofftime,p->data.receivetime,p->data.price,p->data.ticketnum

int saveflag = 0;

// ����洢����Ϣ�Ľṹ��
struct train
{
	char num[10];
	char startcity[10];
	char reachcity[10];
	char takeofftime[10];   // ����ʱ��
	char receivetime[10];    // ����ʱ��
	int price;
	int ticketnum;
};

// ��Ʊ�˵���Ϣ
struct man
{
	char num[10];
	char name[10];
	int bookNum;
};


// �������Ϣ����Ľڵ�ṹ
typedef struct node
{
	struct train data;
	struct node* next;
} Node, * Link;

// ���嶩Ʊ������Ľڵ�ṹ
typedef struct Man
{
	struct man data;
	struct Man* next;
}book, * bookLink;

// ��ʼ������
void menu();

// ���һ���𳵵���Ϣ
void Traininfo(Link linkhead);

// ��ӡ��Ʊ��Ϣ
void printheader();

void printdata(Node* q);


// ��ѯ����Ϣ
void searchtrain(Link l);

// ��Ʊ��ģ��
void Bookticket(Link l, bookLink k);

// �޸Ļ���Ϣ
void Modify(Link l);

// ��ʾ�г���Ϣ
void showtrain(Link l);

// �������Ϣ
void SaveTrainInfo(Link l);

// ���涩Ʊ�˵���Ϣ
void SaveBookInfo(bookLink k);

