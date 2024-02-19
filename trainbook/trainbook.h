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

// 定义存储火车信息的结构体
struct train
{
	char num[10];
	char startcity[10];
	char reachcity[10];
	char takeofftime[10];   // 出发时间
	char receivetime[10];    // 到达时间
	int price;
	int ticketnum;
};

// 订票人的信息
struct man
{
	char num[10];
	char name[10];
	int bookNum;
};


// 定义火车信息链表的节点结构
typedef struct node
{
	struct train data;
	struct node* next;
} Node, * Link;

// 定义订票人链表的节点结构
typedef struct Man
{
	struct man data;
	struct Man* next;
}book, * bookLink;

// 初始化界面
void menu();

// 添加一个火车的信息
void Traininfo(Link linkhead);

// 打印火车票信息
void printheader();

void printdata(Node* q);


// 查询火车信息
void searchtrain(Link l);

// 订票子模块
void Bookticket(Link l, bookLink k);

// 修改火车信息
void Modify(Link l);

// 显示列车信息
void showtrain(Link l);

// 保存火车信息
void SaveTrainInfo(Link l);

// 保存订票人的信息
void SaveBookInfo(bookLink k);

