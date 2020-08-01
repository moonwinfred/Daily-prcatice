#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
typedef struct albookt {
	char name[20];
	int amount;/*��������Ʊ������*/
	int num;/*����λ��*/
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
void asking(airline* k);/*��Ʊ���ж��ں�ѡ����ѯ���Ƿ���ж�Ʊ*/
int main() {
	int k = 0;
	while (1) {
		printf("__________________________________________\n");
		printf("\n");
		printf("-------------���տ��˶�Ʊϵͳ-------------");
		printf("\n");
		printf("\n");
		printf("--------------1 ����Ա����----------------\n");
		printf("--------------2 �ǹ���Ա����--------------\n");
		printf("--------------0 �˳�ϵͳ------------------\n");
		printf("__________________________________________\n");
		printf("����������Ҫ����Ĳ˵�ѡ�\n");
		scanf("%d", &k);

		switch (k) {
		case 1:if (admini() == 0); break;
		case 2:if (unadmini() == 0); break;
		case 0:printf("�����˳���ϵͳ��лл��\n"); return 0;

		}
	}
}
int admini() {
	int n = 0;
	while (1) {
		printf("______________________________\n");
		printf("\n");
		printf("----------����Ա����----------\n");
		printf("\n");
		printf("---------1 �������-----------\n");
		printf("---------2 ����¼��-----------\n");
		printf("---------3 �������-----------\n");
		printf("---------0 �����ϼ��˵�-------\n");
		printf("______________________________\n");
		printf("����������ѡ�");
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
	printf("�����������ڽ��뺽��¼�����ҳ��\n");
	printf("\n");
	while (1) {
		printf("���ڿ�ʼ���к���¼�롣\n\n");
		printf("����������Ҫ����ĺ������������\n");
		scanf("%d", &n);/*������һ����������ȥ�������*/
		putchar('\n');
		printf("�������밴�Ҳ�˳���������뺽�����������:1 ���վ�� 2 �յ�վ�� 3 ����� 4 �ɻ��� 5 �������� 6 ��Ա���� \n");
		printf("<ÿ����Ϣ֮���Կո�Ϊ��� ��Enter��������һ�����������¼��>\n\n");
		printf("<���з��������밴xxxx��xx��xx������д,����2018��6��20��>\n\n");
		printf("���ڿ�ʼ���룺\n");
		for (int i = 0; i < n; i++) {
			scanf("%s%s%s%s%d��%d��%d��%d", &originplace1, &finishplace1, &linenumber1, &planenumber1, &year1,&month1,&data1, &quota1);
			airline* xt = head;
			while (xt != NULL) {
				if (strcmp(xt->linenumber, linenumber1) == 0) {
					int k;
					flag = 1;
					printf("�ú���ĺ�����ظ�����ѡ��������������������˴����롣\n");
					printf("1 �������� 2 �����˴�����\n");
					printf("����������ѡ��:");
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
		printf("��������Ϊ�������������룬���Ժ󡭡�\n");
		printf("\n");
		printf("������ȫ��¼����ɡ�\n\n");
		int k;
		printf("��ѡ���������¼�룬���߷����ϼ��˵���1 ����¼�� 0 �����ϼ��˵�\n");
		printf("������ѡ�\n");
		scanf("%d", &k);
		
		if (k == 0)return 0;

	}
	
}
int Delete(){
	
	printf("�����������ڽ��뺽�����ҳ��\n\n");
	
	printf("��ǰҳ��Ϊ�������ҳ�档\n\n");
	printf("��Ҫ�����뵱ǰ�����ڣ����������\n");
		printf("�����뵱ǰ������:\n");
		printf("<����ĸ�ʽΪxxxx��xx��xx�գ����磺2018��3��7��>\n");
		scanf("%d��%d��%d��", &nowyear, &nowmonth, &nowdata);
		airline* ptemp = head;
		airline* k = head;
		int count = 0;
		printf("����������ں������,���Ժ󡭡�����\n");
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
				printf("�������%d�����ں�������\n", count);
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
				printf("�������%d�����ں�������\n", count);

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



					printf("�������%d�����ں�������\n", count);
				}


			}
			else {
				ptemp = ptemp->next;
			}
		}


			printf("��ȫ�������ɣ�\n");
			printf("���ڷ����ϼ��˵�����\n");
			return 0;
			tofileairline();
}
int unadmini() {
	
	int n;
	while (1) {
		printf("__________________________________\n");
		printf("\n");
		printf("-----------�ǹ���Ա����-----------\n");
		printf("\n");
		printf("-----------1 ��ѯ����-------------\n");
		printf("-----------2 ��Ʊҵ��-------------\n");
		printf("-----------3 ��Ʊҵ��-------------\n");
		printf("-----------0 �����ϼ��˵�---------\n");
		printf("__________________________________\n");
		printf("����������ѡ�");
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
	printf("------------------------��ѯ����-------------------------\n");
	while (1) {
		printf("---------------------------------------------------------\n\n");
		printf("������������Ҫ��ѯ���ߵ����վ��<��Enter��������һ������>��");
		scanf("%s", &oringinplace0);
		printf("\n");
		printf("������������Ҫ��ѯ���ߵ��յ�վ��<��Enter��������һ������>��");
		scanf("%s", &finishplace0);
		printf("\n");
		printf("���ڲ��ҷ�����Ҫ��ĺ��ߡ���\n");
		printf("���Եȡ���\n");
		printf("\n");
		int flag = 0;
		airline* tag = NULL;
		int min = 32767;/*����ȷ������*/
		while (pt!=NULL) {
			
			if (strcmp(pt->originplace, oringinplace0) == 0 && strcmp(pt->finishplace, finishplace0) == 0) {
				if (flag == 0) {
					printf("��%s����%s�ĺ����У�\n",oringinplace0,finishplace0);
					printf("________________________________________________________________\n\n");
					printf("�����    �ɻ���       ��������        ���о�������     ��Ʊ�� \n");/*������Ҫһ��֪�����ڼ����е�һ�����㷽��*/
					printf("________________________________________________________________\n");
					printf("\n");
					flag = 1;
				}
			
					days = Day(pt->year, pt->month, pt->data);
					char c[7][4] = { "��","һ","��","��","��","��","��" };
					int week = days % 7;
					int gmin = abs(pt->year - nowyear) * 365 + abs(pt->month - nowmonth) * 30 + abs(pt->data - nowdata);
					printf("%s       %s         %d��%d��%d��          %s            %d\n", pt->linenumber, pt->planenumber, pt->year, pt->month, pt->data, c[week], pt->rest);
					if (gmin < min) {
						min = gmin;
						tag = pt;
					}
					
	
			}
			pt = pt->next;
		}
		if (flag == 0) {
			
			printf("�ܱ�Ǹ��δ���ҵ�������Ҫ��ѯ�ĺ��ߡ�\n");
		}
		else {
			printf("________________________________________________________________\n\n");
			printf("�������һ��ĺ���Ϊ�����%s,%d��%d��%d����ɣ���Ʊ��%d�š�\n", tag->linenumber, tag->year, tag->month, tag->data, tag->rest);
			printf("\n");
		}
		int k;
		printf("------------------------------------------------------------------\n");

		printf("��ѯ�ѽ�����\n��ѡ������һ���Ĳ���:1 ������ѯ 0 �����ϼ��˵�\n");
		printf("����������ѡ�");
		scanf("%d", &k);
		if (k == 0)return 0;
		
		
	}
}
int Day(int year, int month, int data) {
	int i;
	int r = 0;/*��������ĸ���*/
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
	printf("---------------------��Ʊҵ��----------------------\n");
	while (1) {
		int flag = 0;
		printf("---------------------------------------------------\n\n");
		printf("s������������Ҫ�Ķ�Ʊ�ĺ����<����Enter��������һ������>:");
		scanf("%s", &linenumber0);
		printf("������������Ҫ�Ķ�Ʊ����<����Enter��������һ������>:");
		scanf("%d", &num);
		printf("\n");
		printf("��������Ϊ��Ѱ�ҷ���Ҫ��ĺ��࡭��\n\n");
		printf("���Եȡ���\n");
		airline* pt = head;
		while (pt != NULL&&strcmp(pt->linenumber,linenumber0)!=0) {
			pt = pt->next;
		}
		if (pt == NULL) {
			int t;
			printf("������˼��û���ҵ��ú��������Ӧ�ĺ��ࡣ\n");
			printf("��ѡ��������һ��������1 �л�����Ŷ�Ʊ 0 �����ϼ��˵���\n");
			printf("����������ѡ� ");
			scanf("%d", &t);
			if (t == 0)return 0;
		}
		else {
			if (pt->rest >= num) {
				pt->rest -= num;/*��Ʊʱ���������Ҫ����*/
				int k;
				albookt* bt = (albookt*)malloc(sizeof(albookt));
				printf("�ú���������Ʊ����������Ϊ������Ʊ������\n");
				printf("---------------------------------------------------\n\n");
				printf("��������������<����Enter������һ������>��\n");
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
				printf("��Ʊ�ѳɹ������ڸú������λ��Ϊ��\n");
				for (int i = 0; i < num; i++) {
					if (i == num - 1) {
						printf(" %d\n",bt->num+i);
					}
					else {

						printf(" %d", bt->num + i);
					}
				}
				printf("��Ʊ����ɡ�\n��ѡ������һ��������1 ������Ʊ 0 �����ϼ��˵�\n");
				printf("����������ѡ��:");
				tofilebookt();
				scanf("%d", &k);
				if (k == 0)return 0;

			}
			else {
				char name[20];
				int n;
				int p;
				printf("�Բ������ڸú������Ʊ��С�����Ķ�Ʊ��޷���ɶ�Ʊ��\n");
				printf("����Ҫ�����ɵǼ��ŶӺ򲹡�\n");
				printf("��ѡ������һ��������1 �ŶӺ� 2 ��ѯ��������ú���Ŀ�ĵغ��� 3�л�����Ŷ�Ʊ 0 �����ϼ��˵�\n");
				scanf("%d", &n);
				if (n == 0)return 0;
				else if (n == 1) {
					printf("--------------�ŶӺ�--------------\n");
					printf("\n");
					printf("����Ϊ�������������\n");
					printf("------------------------------------\n");
					printf("����������������");
					scanf("%s", &name);
					printf("��������Ϊ����������������Ժ�\n\n");
				
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
				printf("���Ѿ���ɺ򲹵Ǽǡ�\n");
				printf("��ѡ��������һ��������1 ������Ʊ 0 �����ϼ��˵�\n");
				printf("����������ѡ�\n");
				tofilewait();
				scanf("%d", &p);
				if (p == 0)return 0;
				}
				else if (n == 2) {
					int f = 0;
					int flag = 0;
					printf("--------------------------------------------\n");
					printf("��������Ϊ��Ѱ�ҵ���ͬһĿ�ĵ�����Ʊ����������Ʊ���ĺ��࣬���Ժ�\n");
					printf("����ͬһĿ�ĵصĺ����У�\n");
					airline* k = head;
					while (k != NULL) {
						if (strcmp(k->finishplace, pt->finishplace) == 0&&k->rest>=num&&strcmp(k->linenumber,pt->linenumber)!=0) {
							if (flag == 0) {
								printf("________________________________________________________________\n\n");
								printf("�����    �ɻ���       ��������        ���о�������     ��Ʊ�� \n");/*������Ҫһ��֪�����ڼ����е�һ�����㷽��*/
								printf("________________________________________________________________\n");
								printf("\n");
								flag = 1;
							}
							
								days = Day(k->year, k->month, k->data);
								char c[7][4] = { "��","һ","��","��","��","��","��" };
								int week = days % 7;
							
								printf("%s       %s         %d��%d��%d��          %s            %d\n", k->linenumber, k->planenumber, k->year, k->month, k->data, c[week], k->rest);
								
						
						}
						k = k->next;
					}
					printf("��ѡ������һ���Ĳ�����1 ���������ṩ�ĺ��� 2 �л�����ż�����Ʊ 0 �����ϼ��˵���\n");
					scanf("%d", &f);
					if (f == 0) return 0;
					else if (f == 1) {
						char change[20];
						char name[20];
						k->rest -= num;/*��Ʊʱ���������Ҫ����*/
						int k;
						albookt* bt = (albookt*)malloc(sizeof(albookt));
						printf("--------------------------------------------------\n\n");
						printf("����Ϊ������Ʊ��������������Ҫ������ĺ����:");
						scanf("%s", &change);
						k = head;
						while (strcmp(k->linenumber, change) == 0) {
							k = k->next;
						}
						printf("\n");
						printf("�����붩Ʊ�˵�������");
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
						printf("��Ʊ�ѳɹ������ڸú������λ��Ϊ��\n");
						for (int i = 0; i < num; i++) {
							if (i == num - 1) {
								printf(" %d\n", bt->num + i);
							}
							else {

								printf(" %d", bt->num + i);
							}
						}
						printf("��Ʊ����ɡ�\n��ѡ������һ��������1 ������Ʊ 0 �����ϼ��˵�\n");
						printf("����������ѡ��:");
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
	printf("------------------------��Ʊҵ��----------------------\n");
	printf("------------------------------------------------------\n\n");
	int year0;
	int month0;
	int data0;
	char linenum[20];
	int k;
	while (1) {
		printf("������������Ҫ��Ʊ����ĺ�������<��xxxx��xx��xx�ո�ʽ��������>��");
		scanf("%d��%d��%d��", &year0, &month0, &data0);
		printf("������������Ҫ��Ʊ����ĺ���ţ�");
		scanf("%s", &linenum);
		printf("\n");
		printf("�������ڲ��Ҹú��࣬���Ժ󡭡�\n\n");
		airline* pt = head;
		while (pt != NULL && strcmp(pt->linenumber, linenum) != 0) {
			pt = pt->next;
		}
		if (pt == NULL) {
			printf("������˼��δ���ҵ��ú��࣬����ϸ�˶�һ�º�����Ƿ���д��ȷ��\n");
			printf("��ѡ�����������Ĳ����� 1 ������Ʊ 0 �����ϼ��˵�\n");
			printf("����������ѡ�");
			scanf("%d", &k);
			if (k == 0)return 0;

		}
		else if (pt->year != year0 || pt->month != month0 || pt->data != data0) {
			printf("������˼��δ���ҵ���ú���Ŷ�Ӧ�����ڣ�����ϸ�˶�һ�º�����Ƿ���д��ȷ��\n");
			printf("���������������Ĳ�����1 ������Ʊ 0 �����ϼ��˵�\n");
			printf("����������ѡ�");
			scanf("%d", &k);
			if (k == 0)return 0;
		}
		else {
			char name0[20];
			printf("------------------------------------------------------\n\n");
			printf("�ɹ��ҵ��ú��ࡣ\n");
			printf("����������Ҫ��Ʊ�Ŀͻ����֣�");
			scanf("%s", &name0);
			albookt* bt = pt->alhead;
			printf("���Եȣ��������ڲ�ѯ������Ϣ����\n");
			printf("\n");
			while (bt != NULL && strcmp(bt->name, name0) != 0) {
				bt = bt->next;
			}
			if (bt == NULL) {
				printf("������˼���ڸú���Ķ�Ʊ������δ���ҵ�������Ϣ.\n����ϸ�˶������Ƿ���ȷ��\n\n");
				printf("��ѡ�����������Ĳ�����1 ������Ʊ 0 �����ϼ��˵�\n");
				printf("����������ѡ�");
				scanf("%d", &k);
				if (k == 0)return 0;
			}
			else {
				int n;
				printf("�ѳɹ����ҵ�������Ϣ����������Ϊ����Ʊ�����Եȡ���\n");
				printf("\n");
				printf("---------------------------------------------------\n\n");
				printf("����������Ҫ��������");
				scanf("%d", &n);
				printf("\n");
				if (n > bt->amount) {
					printf("������˼��������Ʊ����������Ķ�Ʊ���\n");
					printf("����ϸ�˶�һ��������Ϣ���ٽ��н�һ��������\n");
					printf("��ѡ�����������Ĳ�����1 ������Ʊ 0 �����ϼ��˵�\n");
					printf("����������ѡ�");
					scanf("%d", &k);
					if (k == 0)return 0;

				}
				else {
					if (n < bt->amount) {
						pt->rest += n;
						bt->amount -= n;
						printf("���������Ʊ��\n");
					}
					else if (n == bt->amount) {
						pt->rest += bt->amount;/*��Ʊ��ú��������Ҫ����*/
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
						printf("���������Ʊ��\n");
					}
					printf("��ѡ�����������Ĳ�����1 ������Ʊ 0 �����ϼ��˵�\n");
					printf("����������ѡ�");
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
			printf("�װ���%s,���Ǽ��ŶӺ򲹵ĺ������ڵ���Ʊ���ܹ���������Ҫ���Ƿ���ҪΪ������Ʊ������\n",pt->name1);
			printf("����������ѡ���������1����������0����");
			scanf("%d", &p);
			if (p == 1) {/*��Ҫ���ж�Ʊ����˼*/
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
				printf("���Ѷ�Ʊ�ɹ���\n");
				/*��Ʊ�ɹ��󣬽��򲹵Ĳ���ɾ��*/
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
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	airline* pt = head;
	while (pt != NULL) {
		fprintf(fp, "%s %s %s %s %d��%d��%d�� %d\n", pt->originplace, pt->finishplace, pt->linenumber, pt->planenumber, pt->year, pt->month, pt->data, pt->quota);
		pt = pt->next;
	}
	if (fclose(fp)) {
		printf("�޷������ر��ļ���");
		exit(0);
	}
}
void toreadairline() {
	printf("--------------�������---------------\n");
	printf("-------------------------------------\n\n");
	printf("-------------�������ڽ��ļ��������ڴ��С�\n\n");
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
		fscanf(fp, "%s%s%s%s%d��%d��%d�� %d", originplace1, finishplace1, linenumber1, planenumber1, &year1, &month1, &data1, &quota1);
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
		printf("�޷������ر��ļ�!");
		exit(0);
	}
	printf("��ȫ��������ɡ����ڷ����ϼ��˵���\n");
}
void tofilebookt() {
	FILE* fp;
	if ((fp = fopen("D:\\bookt.txt", "w")) == NULL) {
		printf("���ļ�ʧ�ܣ�");
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
		printf("�޷������ر��ļ���");
		exit(0);
	}
}
void tofilewait() {
	FILE* fp;
	if ((fp = fopen("D:\\wait.txt", "w")) == NULL) {
		printf("���ļ�ʧ�ܣ�");
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
		printf("�޷������ر��ļ���");
		exit(0);
	}
}