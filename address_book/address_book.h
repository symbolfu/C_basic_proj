#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <string.h>


/*
	通讯录管理系统：
		1、通讯录录入；
		2、通讯录查询；
		3、通讯录删除；
		4、通讯录列表显示；
		5、通讯录数据保存；
		6、通讯录数据加载；
		7、退出系统；

*/

struct Info
{
	char name[15];
	char city[10];
	char province[10];
	char state[10];
	char tel[15];
};

// 链表
typedef struct node
{
	struct Info data;
	struct node* next;
} Node, * link;



void stringinput(char* t, int lens, char* notice);

// input records
void enter(link l);

// delete record
void del(link l);

// node display info
void display(Node* p);

// search
void search(link l);


// link display info
void list(link l);

// save
void save(link l);


// load file
void load(link l);

// menu
int menu_select();







