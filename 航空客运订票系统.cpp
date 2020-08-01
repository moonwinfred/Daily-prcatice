#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
typedef struct albookt {
	char name[20];
	int amount;/*其所订的票的数量*/
	int num;/*其座位号*/
	albookt* next;
};
typedef struct waitbookt {
	char name1[20];
	int rest1;
	waitbookt* next;
};
typedef struct airline {
	char originplace[20];
	char finishplace[20];
	char linenumber[30];
	char planenumber[30];
	int year;
	int month;
	int data;
	int quota;
	int rest;
	albookt* alclient;
	albookt* alhead;
	waitbookt* waithead;
	waitbookt* waitclient;
	airline* next;
};
airline* head = NULL;
airline* tail = NULL;
int nowyear=0;
int nowmonth=0;
int nowdata=0;
int admini();
void tofileairline();
void toreadairline();
int input();
int Delete();
int unadmini();
void tofilebookt();
void tofilewait();
int fine();
int Day(int year, int month, int data);
int book();
int deticket();
void asking(airline* k);/*退票当中对于候选的人询问是否进行订票*/
int main() {
	int k = 0;
	while (1) {
		printf("__________________________________________\n");
		printf("\n");
		printf("-------------航空客运订票系统-------------");
		printf("\n");
		printf("\n");
		printf("--------------1 管理员操作----------------\n");
		printf("--------------2 非管理员操作--------------\n");
		printf("--------------0 退出系统------------------\n");
		printf("__________________________________________\n");
		printf("请输入你所要进入的菜单选项：\n");
		scanf("%d", &k);

		switch (k) {
		case 1:if (admini() == 0); break;
		case 2:if (unadmini() == 0); break;
		case 0:printf("您已退出该系统，谢谢！\n"); return 0;

		}
	}
}
int admini() {
	int n = 0;
	while (1) {
		printf("______________________________\n");
		printf("\n");
		printf("----------管理员操作----------\n");
		printf("\n");
		printf("---------1 航班加载-----------\n");
		printf("---------2 航班录入-----------\n");
		printf("---------3 航班清除-----------\n");
		printf("---------0 返回上级菜单-------\n");
		printf("______________________________\n");
		printf("请输入您的选项：");
		scanf("%d", &n);
		
		switch (n) {
		case 1: toreadairline(); break;
		case 2:if (input() == 0); break;
		case 3:if (Delete() == 0); break;
		case 0:return 0; break;
		}
	}
}
int input() {
	char originplace1[20];
	char finishplace1[20];
	char linenumber1[30];
	char planenumber1[30];
	int year1;
	int month1;
	int data1;
	int quota1;
	int rest1;
	int n;
	printf("--------------------------------------------\n");
	printf("……现在正在进入航班录入操作页面\n");
	printf("\n");
	while (1) {
		printf("现在开始进行航班录入。\n\n");
		printf("请输入您需要导入的航班情况数量：\n");
		scanf("%d", &n);/*可以用一个批量方法去完成输入*/
		putchar('\n');
		printf("接下来请按右侧顺序依次输入航班情况的数据:1 起点站名 2 终点站名 3 航班号 4 飞机号 5 飞行日期 6 乘员定额 \n");
		printf("<每个信息之间以空格为间隔 按Enter键进入下一个航班情况的录入>\n\n");
		printf("<其中飞行日期请按xxxx年xx月xx日题填写,例：2018年6月20日>\n\n");
		printf("现在开始输入：\n");
		for (int i = 0; i < n; i++) {
			scanf("%s%s%s%s%d年%d月%d日%d", &originplace1, &finishplace1, &linenumber1, &planenumber1, &year1,&month1,&data1, &quota1);
			airline* xt = head;
			while (xt != NULL) {
				if (strcmp(xt->linenumber, linenumber1) == 0) {
					int k;
					flag = 1;
					printf("该航班的航班号重复，请选择重新输入或者是跳过此次输入。\n");
					printf("1 重新输入 2 跳过此次输入\n");
					printf("请输入您的选项:");
					scanf("%d", &k);
					if (k == 1) {
						i = i - 1;
						break;
					}
					xt = xt->next;

				}
			}
			if (flag == 1)continue;
			airline* pt = (airline*)malloc(sizeof(airline));
			strcpy(pt->originplace, originplace1);
			strcpy(pt->finishplace, finishplace1);
			strcpy(pt->linenumber, linenumber1);
			strcpy(pt->planenumber, planenumber1);
			pt->year = year1;
			pt->month = month1;
			pt->data = data1;
			pt->quota = quota1;
			pt->rest = quota1;
			pt->waitclient = NULL;
			pt->waithead = NULL;
			pt->alclient = NULL;
			pt->alhead = NULL;
			pt->next = NULL;
			if (head == NULL) {
				head = pt;
				tail = pt;
			}
			else {
				tail->next = pt;
				tail = pt;
			}
		}
		tofileairline();
		printf("现在正在为您进行数据输入，请稍后……\n");
		printf("\n");
		printf("数据已全部录入完成。\n\n");
		int k;
		printf("请选择继续进行录入，或者返回上级菜单：1 继续录入 0 返回上级菜单\n");
		printf("请输入选项：\n");
		scanf("%d", &k);
		
		if (k == 0)return 0;

	}
	
}
int Delete(){
	
	printf("……现在正在进入航班清除页面\n\n");
	
	printf("当前页面为航班清除页面。\n\n");
	printf("需要您输入当前的日期，进行清除。\n");
		printf("请输入当前的日期:\n");
		printf("<输入的格式为xxxx年xx月xx日，例如：2018年3月7日>\n");
		scanf("%d年%d月%d日", &nowyear, &nowmonth, &nowdata);
		airline* ptemp = head;
		airline* k = head;
		int count = 0;
		printf("正在清除过期航班情况,请稍后…………\n");
		while (ptemp != NULL) {
			if (ptemp->year < nowyear) {
				count++;
				if (ptemp == head) {
					airline* pt = head;
					ptemp = ptemp->next;
					head = head->next;
					free(pt);


				}
				else if (ptemp == tail) {
					airline* p = ptemp;
					while (k->next != ptemp) {
						k = k->next;
					}
					tail = k;
					ptemp == ptemp->next;
					free(p);

				}
				else {
					while (k->next != ptemp) {
						k = k->next;
					}
					airline* p = ptemp;
					k->next = ptemp->next;
					ptemp = ptemp->next;
					free(p);


				}
				printf("已清除第%d个过期航班数据\n", count);
			}
			else if (ptemp->year == nowyear && ptemp->month < nowmonth) {
				count++;
				if (ptemp == head) {
					airline* pt = head;
					ptemp = ptemp->next;
					head = head->next;
					free(pt);


				}
				else if (ptemp == tail) {
					airline* p = ptemp;
					while (k->next != ptemp) {
						k = k->next;
					}
					tail = k;
					ptemp = ptemp->next;
					free(p);

				}
				else {
					while (k->next != ptemp) {
						k = k->next;
					}
					airline* p = ptemp;
					k->next = ptemp->next;
					ptemp = ptemp->next;
					free(p);


				}
				printf("已清除第%d个过期航班数据\n", count);

			}
			else if (ptemp->year == nowyear && ptemp->month == nowmonth && ptemp->data < nowdata) {
				count++;
				if (ptemp == head) {
					airline* pt = head;
					ptemp = ptemp->next;
					head = head->next;
					free(pt);


				}
				else if (ptemp == tail) {
					airline* p = ptemp;
					while (k->next != ptemp) {
						k = k->next;
					}
					tail = k;
					ptemp == ptemp->next;
					free(p);

				}
				else {
					while (k->next != ptemp) {
						k = k->next;
					}
					airline* p = ptemp;
					k->next = ptemp->next;
					ptemp = ptemp->next;
					free(p);



					printf("已清除第%d个过期航班数据\n", count);
				}


			}
			else {
				ptemp = ptemp->next;
			}
		}


			printf("已全部清除完成！\n");
			printf("现在返回上级菜单……\n");
			return 0;
			tofileairline();
}
int unadmini() {
	
	int n;
	while (1) {
		printf("__________________________________\n");
		printf("\n");
		printf("-----------非管理员操作-----------\n");
		printf("\n");
		printf("-----------1 查询航线-------------\n");
		printf("-----------2 订票业务-------------\n");
		printf("-----------3 退票业务-------------\n");
		printf("-----------0 返回上级菜单---------\n");
		printf("__________________________________\n");
		printf("请输入您的选项：");
		scanf("%d", &n);
		if (n == 0)return 0;
		switch (n) {
		case 1:if (fine() == 0); break;
		case 2:if (book() == 0); break;
		case 3:if(deticket()==0); break;
		case 0:return 0;
		}
	}
}
int fine(){
	char oringinplace0[20];
	char finishplace0[20];
	airline *pt = head;
	int days;
	printf("------------------------查询航线-------------------------\n");
	while (1) {
		printf("---------------------------------------------------------\n\n");
		printf("请输入你所需要查询航线的起点站名<后按Enter键进入下一步操作>：");
		scanf("%s", &oringinplace0);
		printf("\n");
		printf("请输入你所需要查询航线的终点站名<后按Enter键进入下一步操作>：");
		scanf("%s", &finishplace0);
		printf("\n");
		printf("正在查找符合您要求的航线……\n");
		printf("请稍等……\n");
		printf("\n");
		int flag = 0;
		airline* tag = NULL;
		int min = 32767;/*用来确定日期*/
		while (pt!=NULL) {
			
			if (strcmp(pt->originplace, oringinplace0) == 0 && strcmp(pt->finishplace, finishplace0) == 0) {
				if (flag == 0) {
					printf("从%s飞往%s的航线有：\n",oringinplace0,finishplace0);
					printf("________________________________________________________________\n\n");
					printf("航班号    飞机号       飞信日期        飞行具体星期     余票额 \n");/*这里需要一个知道星期几飞行的一个计算方法*/
					printf("________________________________________________________________\n");
					printf("\n");
					flag = 1;
				}
			
					days = Day(pt->year, pt->month, pt->data);
					char c[7][4] = { "日","一","二","三","四","五","六" };
					int week = days % 7;
					int gmin = abs(pt->year - nowyear) * 365 + abs(pt->month - nowmonth) * 30 + abs(pt->data - nowdata);
					printf("%s       %s         %d年%d月%d日          %s            %d\n", pt->linenumber, pt->planenumber, pt->year, pt->month, pt->data, c[week], pt->rest);
					if (gmin < min) {
						min = gmin;
						tag = pt;
					}
					
	
			}
			pt = pt->next;
		}
		if (flag == 0) {
			
			printf("很抱歉，未查找到你所需要查询的航线。\n");
		}
		else {
			printf("________________________________________________________________\n\n");
			printf("其中最近一天的航班为航班号%s,%d年%d月%d日起飞，余票额%d张。\n", tag->linenumber, tag->year, tag->month, tag->data, tag->rest);
			printf("\n");
		}
		int k;
		printf("------------------------------------------------------------------\n");

		printf("查询已结束。\n请选择您进一步的操作:1 继续查询 0 返回上级菜单\n");
		printf("请输入您的选项：");
		scanf("%d", &k);
		if (k == 0)return 0;
		
		
	}
}
int Day(int year, int month, int data) {
	int i;
	int r = 0;/*储存闰年的个数*/
	int k[13] = { 31,28,31,30,31,30,31,31,30,31,30 };
	if (year >= 1900 && month > 0 && month < 13 && data>0 && data < 32) {
		for (i = 1900; i <= year; i++) {
			if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0) {
				r++;
			}
			for (i = 0; i < month - 1; i++) {
				data += k[i];
			}
			if ((year % 400 == 0 || year % 100 != 0 && year % 4 == 0) && month < 3)
				r--;
			return 365 * (year - 1900) + r + data;
		}
	}
	else
		return 0;
	
}
int book() {
	char linenumber0[20];
	int num = 0;
	char name[20];
	printf("---------------------订票业务----------------------\n");
	while (1) {
		int flag = 0;
		printf("---------------------------------------------------\n\n");
		printf("s请输入你所需要的订票的航班号<并按Enter键进入下一步操作>:");
		scanf("%s", &linenumber0);
		printf("请输入你所需要的订票数量<并按Enter键进入下一步操作>:");
		scanf("%d", &num);
		printf("\n");
		printf("现在正在为您寻找符合要求的航班……\n\n");
		printf("请稍等……\n");
		airline* pt = head;
		while (pt != NULL&&strcmp(pt->linenumber,linenumber0)!=0) {
			pt = pt->next;
		}
		if (pt == NULL) {
			int t;
			printf("不好意思，没有找到该航班号所对应的航班。\n");
			printf("请选择您的下一步操作：1 切换航班号订票 0 返回上级菜单。\n");
			printf("请输入您的选项： ");
			scanf("%d", &t);
			if (t == 0)return 0;
		}
		else {
			if (pt->rest >= num) {
				pt->rest -= num;/*订票时，其余额需要减少*/
				int k;
				albookt* bt = (albookt*)malloc(sizeof(albookt));
				printf("该航班尚有余票，现在正在为您办理订票手续。\n");
				printf("---------------------------------------------------\n\n");
				printf("请输入您的姓名<并按Enter进入下一步操作>：\n");
				scanf("%s", &name);
				printf("\n");
				strcpy(bt->name, name);
				bt->amount = num;
				bt->num = (pt->quota - pt->rest + 1);
				bt->next = NULL;
				if (pt->alclient == NULL) {
					pt->alclient = bt;
					pt->alhead = bt;
				}
				else {
					pt->alclient->next = bt;
					pt->alclient = bt;

				}
				printf("订票已成功。您在该航班的座位号为：\n");
				for (int i = 0; i < num; i++) {
					if (i == num - 1) {
						printf(" %d\n",bt->num+i);
					}
					else {

						printf(" %d", bt->num + i);
					}
				}
				printf("订票已完成。\n请选择您下一步操作：1 继续订票 0 返回上级菜单\n");
				printf("请输入您的选项:");
				tofilebookt();
				scanf("%d", &k);
				if (k == 0)return 0;

			}
			else {
				char name[20];
				int n;
				int p;
				printf("对不起，由于该航班的余票额小于您的订票额，无法完成订票。\n");
				printf("若需要，您可登记排队候补。\n");
				printf("请选择您下一步操作：1 排队候补 2 查询其他到达该航班目的地航线 3切换航班号订票 0 返回上级菜单\n");
				scanf("%d", &n);
				if (n == 0)return 0;
				else if (n == 1) {
					printf("--------------排队候补--------------\n");
					printf("\n");
					printf("现在为您办理候补手续。\n");
					printf("------------------------------------\n");
					printf("请输入您的姓名：");
					scanf("%s", &name);
					printf("……正在为您办理候补手续，请稍后。\n\n");
				
				waitbookt* ct = (waitbookt*)malloc(sizeof(waitbookt));
				strcpy(ct->name1, name);
				ct->rest1 = num;
				ct->next = NULL;
				if (pt->waitclient == NULL) {
					pt->waitclient = ct;
					pt->waithead = ct;
				}
				else {
					pt->waitclient->next = ct;
					pt->waitclient = ct;
				}
				printf("您已经完成候补登记。\n");
				printf("请选择您的下一步操作：1 继续订票 0 返回上级菜单\n");
				printf("请输入您的选项：\n");
				tofilewait();
				scanf("%d", &p);
				if (p == 0)return 0;
				}
				else if (n == 2) {
					int f = 0;
					int flag = 0;
					printf("--------------------------------------------\n");
					printf("……现在为您寻找到达同一目的地且余票量满足您订票量的航班，请稍后。\n");
					printf("到达同一目的地的航班有：\n");
					airline* k = head;
					while (k != NULL) {
						if (strcmp(k->finishplace, pt->finishplace) == 0&&k->rest>=num&&strcmp(k->linenumber,pt->linenumber)!=0) {
							if (flag == 0) {
								printf("________________________________________________________________\n\n");
								printf("航班号    飞机号       飞信日期        飞行具体星期     余票额 \n");/*这里需要一个知道星期几飞行的一个计算方法*/
								printf("________________________________________________________________\n");
								printf("\n");
								flag = 1;
							}
							
								days = Day(k->year, k->month, k->data);
								char c[7][4] = { "日","一","二","三","四","五","六" };
								int week = days % 7;
							
								printf("%s       %s         %d年%d月%d日          %s            %d\n", k->linenumber, k->planenumber, k->year, k->month, k->data, c[week], k->rest);
								
						
						}
						k = k->next;
					}
					printf("请选择您进一步的操作：1 订上述所提供的航班 2 切换航班号继续订票 0 返回上级菜单。\n");
					scanf("%d", &f);
					if (f == 0) return 0;
					else if (f == 1) {
						char change[20];
						char name[20];
						k->rest -= num;/*订票时，其余额需要减少*/
						int k;
						albookt* bt = (albookt*)malloc(sizeof(albookt));
						printf("--------------------------------------------------\n\n");
						printf("现在为您办理订票服务，请输入您所要订航班的航班号:");
						scanf("%s", &change);
						k = head;
						while (strcmp(k->linenumber, change) == 0) {
							k = k->next;
						}
						printf("\n");
						printf("请输入订票人的姓名：");
						scanf("%s", &name);
						printf("\n");
						strcpy(bt->name, name);
						bt->amount = num;
						bt->num = (k->quota - k->rest + 1);
						bt->next = NULL;
						if (k->alclient == NULL) {
							k->alclient = bt;
							k->alhead = bt;
						}
						else {
							k->alclient->next = bt;
							k->alclient = bt;

						}
						printf("订票已成功。您在该航班的座位号为：\n");
						for (int i = 0; i < num; i++) {
							if (i == num - 1) {
								printf(" %d\n", bt->num + i);
							}
							else {

								printf(" %d", bt->num + i);
							}
						}
						printf("订票已完成。\n请选择您下一步操作：1 继续订票 0 返回上级菜单\n");
						printf("请输入您的选项:");
						tofilebookt();
						scanf("%d", &k);
						if (k == 0)return 0;

					}
			}
				


			}
		}
	}
	
}
int deticket() {
	printf("------------------------退票业务----------------------\n");
	printf("------------------------------------------------------\n\n");
	int year0;
	int month0;
	int data0;
	char linenum[20];
	int k;
	while (1) {
		printf("请输入您所需要退票航班的航班日期<按xxxx年xx月xx日格式进行输入>：");
		scanf("%d年%d月%d日", &year0, &month0, &data0);
		printf("请输入您所需要退票航班的航班号：");
		scanf("%s", &linenum);
		printf("\n");
		printf("现在正在查找该航班，请稍后……\n\n");
		airline* pt = head;
		while (pt != NULL && strcmp(pt->linenumber, linenum) != 0) {
			pt = pt->next;
		}
		if (pt == NULL) {
			printf("不好意思，未查找到该航班，请仔细核对一下航班号是否填写正确。\n");
			printf("请选择您接下来的操作： 1 继续退票 0 返回上级菜单\n");
			printf("请输入您的选项：");
			scanf("%d", &k);
			if (k == 0)return 0;

		}
		else if (pt->year != year0 || pt->month != month0 || pt->data != data0) {
			printf("不好意思，未查找到与该航班号对应的日期，请仔细核对一下航班号是否填写正确。\n");
			printf("请输入您接下来的操作：1 继续退票 0 返回上级菜单\n");
			printf("请输入您的选项：");
			scanf("%d", &k);
			if (k == 0)return 0;
		}
		else {
			char name0[20];
			printf("------------------------------------------------------\n\n");
			printf("成功找到该航班。\n");
			printf("请输入您需要退票的客户名字：");
			scanf("%s", &name0);
			albookt* bt = pt->alhead;
			printf("请稍等，现在正在查询您的信息……\n");
			printf("\n");
			while (bt != NULL && strcmp(bt->name, name0) != 0) {
				bt = bt->next;
			}
			if (bt == NULL) {
				printf("不好意思，在该航班的订票名单中未查找到您的信息.\n请仔细核对输入是否正确。\n\n");
				printf("请选择您接下来的操作：1 继续退票 0 返回上级菜单\n");
				printf("请输入您的选项：");
				scanf("%d", &k);
				if (k == 0)return 0;
			}
			else {
				int n;
				printf("已成功查找到您的信息，现在正在为您退票，请稍等……\n");
				printf("\n");
				printf("---------------------------------------------------\n\n");
				printf("请输入您需要的数量：");
				scanf("%d", &n);
				printf("\n");
				if (n > bt->amount) {
					printf("不好意思，您的退票数额大于您的订票数额。\n");
					printf("请仔细核对一下您的信息。再进行进一步操作。\n");
					printf("请选择您接下来的操作：1 继续退票 0 返回上级菜单\n");
					printf("请输入您的选项：");
					scanf("%d", &k);
					if (k == 0)return 0;

				}
				else {
					if (n < bt->amount) {
						pt->rest += n;
						bt->amount -= n;
						printf("您已完成退票。\n");
					}
					else if (n == bt->amount) {
						pt->rest += bt->amount;/*退票则该航班余额需要增加*/
						if (bt == pt->alhead) {

							albookt* t = bt;
							pt->alhead = pt->alhead->next;
							bt = bt->next;
							free(t);
						}
						else {
							albookt* s = pt->alhead;
							while (s->next != bt) {
								s = s->next;
							}
							if (bt == pt->alclient) {
								pt->alclient = s;
								bt = NULL;
							}
							else {
								albookt* p = bt;
								s->next = bt->next;
								bt = bt->next;
								free(p);
							}


						}
						tofilebookt();
						printf("您已完成退票。\n");
					}
					printf("请选择您接下来的操作：1 继续退票 0 返回上级菜单\n");
					printf("请输入您的选项：");
					scanf("%d", &k);
					if (k == 0) {
						asking(pt);
						return 0;
					}

				}
			}
		}
	}
}
void asking(airline* k) {
	
	waitbookt* pt = k->waithead;
	while (pt!=NULL&&k->rest!=0) {
		int p = 0;
		if (k->rest >= pt->rest1) {
			printf("亲爱的%s,您登记排队候补的航班现在的退票额能够满足您的要求，是否需要为您办理订票手续？\n",pt->name1);
			printf("请输入您的选项（是请输入1，否请输入0）：");
			scanf("%d", &p);
			if (p == 1) {/*需要进行订票的意思*/
				albookt* bt = (albookt*)malloc(sizeof(albookt));
				bt->amount = pt->rest1;
				strcpy(bt->name, pt->name1);
				bt->num = (k->quota - k->rest) + 1;
				bt->next = NULL;
				k->rest -= pt->rest1;

				if (k->alhead == NULL) {
					k->alhead = bt;
					k->alclient = bt;
					
				}
				else {
					k->alclient->next = bt;
					k->alclient = bt;
				}
				printf("您已订票成功！\n");
				/*订票成功后，将候补的部分删除*/
				if (pt == k->waithead) {
					k->waithead = k->waithead->next;
					free(pt);
				}
				else {
					waitbookt* lp = k->waithead;
					while (lp->next != pt) {
						lp = lp->next;
					}
					if (pt == k->waitclient) {
						k->waitclient = lp;
						free(pt);
					}
					else {
						lp->next = pt->next;
						free(pt);
					}
				}
			
			}
			
		}
		pt = pt->next;
	}


}
void tofileairline() {
	FILE* fp;
	if ((fp = fopen("D:\\airline.txt", "w")) == NULL) {
		printf("打开文件失败！");
		exit(0);
	}
	airline* pt = head;
	while (pt != NULL) {
		fprintf(fp, "%s %s %s %s %d年%d月%d日 %d\n", pt->originplace, pt->finishplace, pt->linenumber, pt->planenumber, pt->year, pt->month, pt->data, pt->quota);
		pt = pt->next;
	}
	if (fclose(fp)) {
		printf("无法正常关闭文件！");
		exit(0);
	}
}
void toreadairline() {
	printf("--------------航班加载---------------\n");
	printf("-------------------------------------\n\n");
	printf("-------------现在正在将文件加载至内存中。\n\n");
	FILE* fp;
	char originplace1[20];
	char finishplace1[20];
	char linenumber1[30];
	char planenumber1[30];
	int year1;
	int month1;
	int data1;
	int quota1;
	int rest1;
	if ((fp = fopen("D:\\airline.txt", "r")) == NULL) {
		printf("Can not open the file!");
		exit(0);
	}
	while (!feof(fp)) {
		fscanf(fp, "%s%s%s%s%d年%d月%d日 %d", originplace1, finishplace1, linenumber1, planenumber1, &year1, &month1, &data1, &quota1);
		airline* pt = (airline*)malloc(sizeof(airline));
		strcpy(pt->originplace, originplace1);
		strcpy(pt->finishplace, finishplace1);
		strcpy(pt->linenumber, linenumber1);
		strcpy(pt->planenumber, planenumber1);
		pt->year = year1;
		pt->month = month1;
		pt->data = data1;
		pt->quota = quota1;
		pt->rest = quota1;
		pt->waitclient = NULL;
		pt->waithead = NULL;
		pt->alclient = NULL;
		pt->alhead = NULL;
		pt->next = NULL;
		if (head == NULL) {
			head = pt;
			tail = pt;
		}
		else {
			tail->next = pt;
			tail = pt;
		}
	}
	if (fclose(fp)) {
		printf("无法正常关闭文件!");
		exit(0);
	}
	printf("已全部加载完成。现在返回上级菜单。\n");
}
void tofilebookt() {
	FILE* fp;
	if ((fp = fopen("D:\\bookt.txt", "w")) == NULL) {
		printf("打开文件失败！");
		exit(0);
	}
	airline* pt = head;
	while (pt != NULL) {
		albookt* k = pt->alhead;
		while (k != NULL) {
			fprintf(fp,"%s %d ", k->name, k->amount);
			for (int i = 0; i < k->amount; i++) {
				if (i == k->amount - 1) {
					fprintf(fp, " %d\n", k->amount + i);
				}
				else {
					fprintf(fp, " %d", k->amount + i);
				}
			}
			k = k->next;
		}
		pt = pt->next;
	}
	if (fclose(fp)) {
		printf("无法正常关闭文件！");
		exit(0);
	}
}
void tofilewait() {
	FILE* fp;
	if ((fp = fopen("D:\\wait.txt", "w")) == NULL) {
		printf("打开文件失败！");
		exit(0);
	}
	airline* pt = head;
	while (pt != NULL) {
		waitbookt* k = pt->waithead;
		while (k != NULL) {
			fprintf(fp, "%s %d\n", k->name1, k->rest1);
			
			k = k->next;
		}
		pt = pt->next;
	}
	if (fclose(fp)) {
		printf("无法正常关闭文件！");
		exit(0);
	}
}