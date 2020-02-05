#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
struct worker {
	char name[20];
	char id[5];
	char department[10];
	double wagebsc;
	double wagepsn;
	double allwance;
	double insurance;
	double bonus;
	double fund;
	double sum;
	struct worker* next;
};
struct worker* head = NULL;
struct worker* tail = NULL;
struct worker* paverage;
double a1, a2, a3;
struct department {
	int sum;
	int average;
	int wagebsc;
	int max;
	int min;
}administr,finance,sale;
int menu1();
void input();
int modify();
int Delete();
int search();
int menu2();
void Print1();
void Print2();
int menu3();
void calpaverage();
void caldepartment();
void calpercentage();
void print1();
void print2();
void Tofile();
void Toread();


int main() {/*���˵�����*/
	int n;
	Toread();
	
	while (1) {
		printf("________________________________________\n");
		putchar('\n');
		printf("            ְ�����ʹ���ϵͳ\n");
		printf("________________________________________\n");
		putchar('\n');
		printf("**************1������ά��***************\n");
		printf("________________________________________\n");
		putchar('\n');
		printf("**************2��ͳ������***************\n");
		printf("________________________________________\n");
		putchar('\n');
		printf("**************3���ۺ�����***************\n");
		printf("________________________________________\n");
		putchar('\n');
		printf("**************4���˳�ϵͳ***************\n");
		printf("________________________________________\n");
		printf("������ѡ�");
		scanf("%d", &n);
		switch (n) {
		case 1:if(menu1()==0); break;
		case 2:if (menu2() == 0);  break;
		case 3:if(menu3() == 0); break;
		case 4:putchar('\n'); printf("�����˳�ϵͳ��лл��\n"); return 0;
		}
	}
	
}
int menu1() {/*����ά�����ֲ˵�*/
	int n;
	int flag = 0;
	for(int i=0;;i++) {
		printf("__________________________________\n");
		putchar('\n');
		printf("            ����ά��\n");
		printf("__________________________________\n");
		putchar('\n');
		printf("----------1���������-------------\n");
		printf("----------2�������޸�-------------\n");
		printf("----------3������ɾ��-------------\n");
		printf("----------4�����ݲ�ѯ-------------\n");
		printf("----------0�������ϼ��˵�---------\n");
		printf("__________________________________\n");
	
		printf("������ѡ�");
		
		
		scanf("%d", &n);
		if (n == 0)return 0;
		
	switch(n){
	case 1:input(); break;
	case 2:if(modify()==0)break;
	case 3:if(Delete()==0); break;
	case 4:if(search()==0); break;
			
		}
	}
	return 0;
}
void input() {
	int N;
	char name0[20];
	char id0[5];
	char department0[10];
	double wagebsc0;
	double wagepsn0;
	double allwance0;
	double insurance0;
	double bonus0;
	double fund0;
	printf("            �������\n");
	
	printf("����������Ҫ�����ְ���������ݵ�������");
	scanf("%d", &N);
	putchar('\n');
	printf("�������밴�Ҳ�˳����������ְ����Ϣ:��ID�����ڲ��Ţۻ������ʢ�ְ���ʢݽ����ޱ��բ߽���๫����\n");
	printf("<ÿ����Ϣ�Կո�Ϊ��� ��Enter��������һ��Ա����Ϣ��>\n");
	putchar('\n');
	printf("���ڿ�ʼ�������룺\n");
	int flag,plag;
	for (int i = 0; i < N; i++) {
		scanf("%s%s%s%lf%lf%lf%lf%lf%lf", id0, name0, department0, &wagebsc0, &wagepsn0, &allwance0, &insurance0, &bonus0, &fund0);
		flag = 0;
		struct worker* pt = head;
		while (pt != NULL) {
			if (strcmp(pt->id,id0)==0) {/*�����ж��Ƿ����ظ���ID��*/
				char k;
				flag = 1;
				printf("��ְ��ID�����ظ�����ѡ��������������������ô����롣\n");
				printf("A�������� B�����ô�����\n");
				getchar();
				k = getchar();
				if (k == 'A')i=i-1;/*��ѭ����Ϊԭ������ֵ*/
				break;
			}
			pt = pt->next;
		}
		if (flag == 1)continue;
		struct worker* ptemp = (struct worker*)malloc(sizeof(struct worker));
		strcpy(ptemp->id, id0);
		strcpy(ptemp->name, name0);
		strcpy(ptemp->department, department0);
		ptemp->wagebsc = wagebsc0;
		ptemp->wagepsn = wagepsn0;
		ptemp->allwance = allwance0;
		ptemp->insurance = insurance0;
		ptemp->bonus = bonus0;
		ptemp->fund = fund0;/*�ܹ���ֱ���������ʱ��ֱ�Ӽ���*/
		ptemp->sum = wagebsc0 + wagepsn0 + allwance0 + insurance0 + bonus0 + fund0;
		ptemp->next = NULL;
		if (head == NULL) {
			head = ptemp;
			tail = ptemp;
	}
		else {
			tail->next = ptemp;/*����β����ķ���*/
			tail = ptemp; 
		}

	}
	printf("��¼������ɣ�\n");
	printf("......���ڱ�����ļ��С�\n");
	Tofile();/*������ļ�����*/
	printf("�ļ�����ɹ������ڷ����ϼ��˵���\n");


}
int modify() {
	printf("            �����޸�\n");
	int k;
	while(1){
		printf("����������Ҫ�޸ĵ�Ա��ID�Ż�����������");

		char id1[5];
		scanf("%s", id1);
		putchar('\n');
		printf("�Ե�һ�£�����Ϊ����ϵͳ�в��Ҹ�Ա����Ϣ��\n");
		printf("...........................................\n");

		struct worker* ptemp = head;
		while (ptemp != NULL) {/*�ж��Ƿ���ϵͳ�д���*/
			if (strcmp(ptemp->id, id1) == 0 || strcmp(ptemp->name, id1) == 0) {
				break;
			}
			ptemp = ptemp->next;
		}
		if (ptemp == NULL) {
		printf("�Բ���ϵͳ���޸�Ա��ID�ļ�¼��\n");
		printf("����ֱ�ӷ����ϼ��˵�ֹͣ������������0��\n");
		printf("��Ҫ���²�����������1��лл��\n");
		
		scanf("%d", &k);
		if (k == 0)return 0;
		else continue;
	}
	else {
			printf("�ɹ��ҵ���Ա����¼����Ա����Ϣ����\n");
			printf("ID��%s\n", ptemp->id);
			printf("������%s\n", ptemp->name);
			printf("�������ʣ�%g\n", ptemp->wagebsc);
			printf("ְ���ʣ�%g\n", ptemp->wagepsn);
			printf("������%g\n", ptemp->allwance);
			printf("ҽ�Ʊ��գ�%g\n", ptemp->insurance);
			printf("������ %g\n", ptemp->bonus);
			printf("����%g\n", ptemp->fund);
			printf("�ܹ��޸ĵ��������£�\n");
		printf("A ����B ���� C �������� D ְ���� E ���� F ҽ�Ʊ��� G ������ H ����\n");
		printf("��������Ҫ�޸ĵ�����(��������д��ĸ��ʾ����");
		getchar();
		char p;
		p = getchar();
		putchar('\n');
		if (p == 'A' || p == 'B') {/*���ַ������ͺ��������ͽ�������*/
			char xb[10];
			printf("�������޸ĺ�����ݣ�");
			scanf("%s", xb);
			printf("���������޸��У����Եȡ�\n");
			printf("........................\n");
			switch (p) {
			case 'A':strcpy(ptemp->name, xb); break;
			case 'B':strcpy(ptemp->department, xb); break;
			}
		}
		else {/*���ַ������ͺ͸��������ͽ�������*/
			int gz;
			printf("�������޸ĺ�����ݣ�");
			scanf("%d", &gz);
			switch (p) {
			case 'C':ptemp->wagebsc = gz; break;
			case 'D':ptemp->wagepsn = gz; break;
			case 'E':ptemp->allwance = gz; break;
			case 'F':ptemp->insurance = gz; break;
			case 'G':ptemp->bonus = gz; break;
			case 'H':ptemp->fund = gz; break;

			}

		}
		printf("�޸�����ɣ������޸��Ժ�����ݣ�\n");
		printf("ID��%s\n", ptemp->id);
		printf("������%s\n", ptemp->name);
		printf("�������ʣ�%g\n", ptemp->wagebsc);
		printf("ְ���ʣ�%g\n", ptemp->wagepsn);
		printf("������%g\n", ptemp->allwance);
		printf("ҽ�Ʊ��գ�%g\n", ptemp->insurance);
		printf("������ %g\n", ptemp->bonus);
		printf("����%g\n", ptemp->fund);

		printf("......���ڱ�����ļ��С�\n");
		Tofile();
		printf("�ļ�����ɹ���\n");
		putchar('\n');
		printf("����ֱ�ӷ����ϼ��˵�ֹͣ������������0��\n");
		printf("��Ҫ���²�����������1��лл��\n");
		printf("����������ѡ�");
		scanf("%d", &k);
		if (k == 0)return 0;
		else continue;
	}
	}
}
int Delete() {
	int k;
	printf("            ����ɾ��\n");
	while (1) {
		printf("��������Ҫɾ����¼��Ա��ID�Ż���������");
		char id1[5];
		scanf("%s", id1);
		struct worker* ptemp = head;/*�ж�ϵͳ�Ƿ��и�����*/
		while (ptemp != NULL) {
			if (strcmp(ptemp->id, id1) == 0 || strcmp(ptemp->name, id1) == 0) {
				break;
			}
			ptemp = ptemp->next;
		}
		if (ptemp == NULL) {
			printf("�Բ��𣬸�ϵͳ�޸�Ա��ID�ļ�¼���޷�����ɾ��\n");
			printf("���践���ϼ��˵�ֹͣɾ����������0��\n");
			printf("�绹Ҫ��������������1��лл��\n");
			printf("����������ѡ�");
			scanf("%d", &k);
			if (k == 0)return 0;
			else continue;
		}
		else {/*����ɾ����Ҫ����*/
			struct worker* pt = head;
			if (ptemp == head) {

				head = head->next;
				free(pt);
			}
			else if (ptemp == tail) {
				while (pt->next != tail) {
					pt = pt->next;
				}
				free(tail);
				tail = pt;
				pt->next = NULL;
			}else{

				while (pt->next != ptemp) {
					pt = pt->next;
				}
				pt->next = ptemp->next;
				free(ptemp);

			}
			printf("��ɾ����Ա����¼��\n");
			printf("......���ڽ�ɾ����ļ�¼���±�����ļ��С�\n");
			Tofile();
			printf("�ļ�����ɹ�!\n");
			printf("���践���ϼ��˵���������0��\n");
			printf("�绹��Ҫ����ɾ����������1��лл��\n");
			printf("����������ѡ�");
			scanf("%d", &k);
			if (k == 0)return 0;
			else continue;

		}
	}
}
int search() {
	int k;
	printf("            ���ݲ���\n");
	while (1) {
		printf("����������Ҫ���ҵ�Ա��ID�Ż���������");
		char id1[5];
		scanf("%s", id1);
		printf("�������ڲ��ң����Եȡ�\n");
		printf("........................\n");
		struct worker* ptemp = head;
		while (ptemp != NULL) {
			if (strcmp(ptemp->id, id1) == 0||strcmp(ptemp->name,id1)==0) {
				break;
			}
			ptemp = ptemp->next;
		}
		if (ptemp == NULL) {
			printf("�Բ��𣬸�ϵͳ�޸�Ա��ID�ļ�¼��\n");
			printf("���践���ϼ��˵�ֹͣ���ң�������0��\n");
			printf("��������������в��ң�������1��\n");
			printf("����������ѡ�");
			scanf("%d", &k);
			if (k == 0)return 0;
			else continue;
		}
		else {
			printf("�ɹ����ҵ���Ա����Ϣ!��Ա����Ϣ���£�\n");
			
			printf("ID��%s\n", ptemp->id);
			printf("������%s\n", ptemp->name);
			printf("�������ʣ�%g\n", ptemp->wagebsc);
			printf("ְ���ʣ�%g\n", ptemp->wagepsn);
			printf("������%g\n", ptemp->allwance);
			printf("ҽ�Ʊ��գ�%g\n", ptemp->insurance);
			printf("������ %g\n", ptemp->bonus);
			printf("����%g\n", ptemp->fund);
			putchar('\n');
			printf("���ݲ�ѯ��ϣ�\n");
			printf("���践���ϼ��˵�ֹͣ���ң�������0��\n");
			printf("�����ٴν��в��ң�������1��лл��\n");
			printf("����������ѡ�");
			scanf("%d", &k);
			if (k == 0)return 0;
			else continue;

		}
		
	}
}
int menu2() {
	int n;
	if (head == NULL) {
		printf("������˼����ϵͳ�޼�¼���ݣ��޷�����ͳ�ƣ�");
		return 0;
	}
	for (int i = 0;; i++) {
		printf("_____________________________________________________\n");
		putchar('\n');
		printf("                   ͳ������\n");
		printf("_____________________________________________________\n");
		putchar('\n');
		printf("----------  1�������ƽ�����ʼ��ܹ���----------------\n");
		printf("----------  2������ָ��������ְ������ռ��ְ���ٷֱ�--\n");
		printf("------------3�������Ź����ܶƽ�����ʼ���߹���----\n");
		printf("------------0�������ϼ��˵�--------------------------\n");
		printf("_____________________________________________________\n");

		printf("������ѡ�");
		scanf("%d", &n);

		if (n == 0) return 0;
		switch (n) {
		case 1:Print1(); break;
		case 2:Print2(); break;
		case 3:print2(); break;
		case 4:printf("������ֵ�����޷���ʾ���\n");
		}
	}
}
void calpaverage() {/*��������ƽ������*/
	int count = 0;/*��Ҫʵʱȥ����ϵͳ��������*/
	paverage = (struct worker*)malloc(sizeof(struct worker));
	paverage->wagebsc = 0;
	paverage->wagepsn = 0;
	paverage->allwance = 0;
	paverage->insurance = 0;
	paverage->bonus = 0;
	paverage->fund = 0;
	paverage->sum = 0;
	paverage->next = NULL;
	struct worker* ptemp = head;
	while (ptemp != NULL) {
		count++;
		paverage->wagebsc += ptemp->wagebsc;
		paverage->wagepsn += ptemp->wagepsn;
		paverage->insurance += ptemp->insurance;
		paverage->bonus += ptemp->bonus;
		paverage->allwance += ptemp->allwance;
		paverage->fund += ptemp->fund;
		ptemp = ptemp->next;/*һֱ�����ۼ�*/
	}
	paverage->wagebsc /= (count * 1.0);
	paverage->wagepsn /= (count * 1.0);
	paverage->allwance /= (count * 1.0);
	paverage->insurance /= (count * 1.0);
	paverage->bonus /= (count * 1.0);
	paverage->fund /= (count * 1.0);
	paverage->sum = (paverage->wagebsc) + (paverage->wagepsn) + (paverage->insurance)
		+ (paverage->bonus) + (paverage->fund);
	/*��Ҫ������ת���ɺͱ��һ�� ���С����������ֱ�Ӳ���ʾ ��������ʾ����*/
	/*ȥ��С��������0 �����ʱ����%g */


}
void caldepartment() {
	int acount, fcount, scount;/*���㲿�ŵ���Ϣ*/
	acount = fcount = scount = 0;
	administr.sum = administr.average = administr.max = administr.min = 0;
	finance.sum = finance.average = finance.max = finance.min = 0;
	sale.sum = sale.average = sale.max = sale.min = 0;
	char a[10] = { "����" };
	char b[10] = { "����" };
	char c[10] = { "����" };
	struct worker* ptemp = head;
	while (ptemp != NULL) {
		if (strcmp(ptemp->department, a) == 0) {
			acount++;
			if (acount == 1) {/*����һ�������ļ�¼ �������ֵ����Сֵ ���ڱȽ�*/
				administr.max = ptemp->sum;
				administr.min = ptemp->sum;
			}
			administr.sum += ptemp->sum;
			if (ptemp->sum > administr.max)administr.max = ptemp->sum;
			if (ptemp->sum < administr.min)administr.min = ptemp->sum;

		}
		else if (strcmp(ptemp->department, b) == 0) {
			fcount++;
			if (fcount == 1) {
				finance.max = ptemp->sum;
				finance.min = ptemp->sum;
			}
			finance.sum += ptemp->sum;
			if (ptemp->sum > finance.max)finance.max = ptemp->sum;
			if (ptemp->sum < finance.min)finance.min = ptemp->sum;
		}
		else if (strcmp(ptemp->department, c) == 0) {
			scount++;
			if (scount == 1) {
				sale.max = ptemp->sum;
				sale.min = ptemp->sum;
			}
			sale.sum += ptemp->sum;
			if (ptemp->sum > sale.max)sale.max = ptemp->sum;
			if (ptemp->sum < sale.min)sale.min = ptemp->sum;
		}
		ptemp = ptemp->next;
	}
	administr.average = administr.sum / acount;
	finance.average = finance.sum / fcount;
	sale.average = sale.sum / scount;
}
void calpercentage() {
	a1 = a2 = a3 = 0;/*���ڼ���ٷֱ�*/
	int count = 0;
	double firstthree;
	struct worker* ptemp = head;
	while (ptemp != NULL) {
		count++;
		firstthree = ptemp->wagebsc + ptemp->wagepsn + ptemp->allwance;
		if (firstthree > 3000) {
			a1++;
		}
		else if (firstthree > 2000) {
			a2++;
		}
		else if (firstthree > 1000) {
			a3++;
		}
		ptemp = ptemp->next;
	}
	a1 = a1 / count * 1.0;
	a2 = a2 / count * 1.0;
	a3 = a3 / count * 1.0;
}
void Print1() {
	calpaverage();
	printf("________________________________________________\n");
	putchar('\n');
	printf("            ����ƽ�����ʼ��ܹ���\n");
	printf("________________________________________________\n");
	putchar('\n');
	printf("�������ʣ�         %g\n", paverage->wagebsc);
	printf("________________________________________________\n");
	putchar('\n');
	printf("ְ���ʣ�         %g\n", paverage->wagepsn);
	printf("________________________________________________\n");
	putchar('\n');
	printf("������             %g\n", paverage->allwance);
	printf("________________________________________________\n");
	putchar('\n');
	printf("ҽ�Ʊ��գ�         %g\n", paverage->insurance);
	printf("________________________________________________\n");
	putchar('\n');
	printf("������           %g\n", paverage->bonus);
	printf("________________________________________________\n");
	putchar('\n');
	printf("����:              %g\n", paverage->fund);
	printf("________________________________________________\n");
	putchar('\n');
	printf("�ܹ��ʣ�           %g\n", paverage->sum);
	printf("________________________________________________\n");
	putchar('\n');


}
void Print2() {
	calpercentage();
	printf("___________________________________________________________________\n");
	putchar('\n');
	printf("            ����ָ��������ְ������ռ��ְ���ٷֱ�\n");
	printf("___________________________________________________________________\n");
	putchar('\n');
	printf("ǰ����֮����ǧ���ϣ�       %g%%\n", a1*100);
	printf("___________________________________________________________________\n");
	putchar('\n');
	printf("ǰ����֮����ǧ����ǧ��     %g%%\n", a2*100);
	printf("___________________________________________________________________\n");
	putchar('\n');
	printf("ǰ����֮��һǧ����ǧ��     %g%%\n", a3*100);
	printf("___________________________________________________________________\n");
	putchar('\n');



}
int menu3() {
	int n;
	if (head == NULL) {
		printf("������˼����ϵͳ�޼�¼���ݣ��޷���ӡ���");
		return 0;
	}
	for (int i = 0;; i++) {
		printf("___________________________________________\n");
		putchar('\n');
		printf("               �ۺ�����\n");
		printf("____________________________________________\n");
		putchar('\n');
		printf("----------  1��ְ��������Ϣ��----------------\n");
		printf("----------  2��������ְ��������Ϣ��ƽ������\n");
		printf("------------0�������ϼ��˵�------------------\n");
		printf("_____________________________________________\n");
		putchar('\n');

		printf("������ѡ�");
		scanf("%d", &n);
		
		if (n == 0) return 0;
		switch (n) {
		case 1:print1(); break;
		case 2:print2(); break;
		default:printf("������ֵ�����޷���ʾ���\n");break;
		}
	}
}

void print1() {
	calpaverage();
	printf("                               ְ��������Ϣ��\n");
	printf("_____________________________________________________________________________________\n");
	putchar('\n');
	printf("ID��   ����    ����  ��������   ְ����   ����  ҽ�Ʊ���  ������    ����    �ܹ���\n");
	printf("_____________________________________________________________________________________\n");
	putchar('\n');
	
	struct worker* pt = head;
	while (pt != NULL) {
	printf("%-7s%-8s%-7s%-11g%-10g%-7g%-10g%-10g%-8g%g\n", pt->id, pt->name, pt->department, pt->wagebsc, pt->wagepsn, pt->allwance, pt->insurance, pt->bonus, pt->fund,pt->sum);
	pt = pt->next;
	}
	printf("����ƽ������          %-11g%-10g%-7g%-10g%-10g%-8g%g\n", paverage->wagebsc, paverage->wagepsn, paverage->allwance, paverage->insurance, paverage->bonus, paverage->fund,paverage->sum);
	printf("_____________________________________________________________________________________\n");
	putchar('\n');
	


}
void print2() {
	caldepartment();
	printf("                  ������ְ��������Ϣ��ƽ������\n");
	printf("_____________________________________________________________________\n");
	putchar('\n');
	printf("����   �����ܶ�  ƽ������  ��߹���  ��͹���\n");
	printf("_____________________________________________________________________\n");
	putchar('\n');
	printf("����     %-9d%-11d%-10d%d\n", administr.sum, administr.average, administr.max, administr.min);
	printf("����     %-9d%-11d%-10d%d\n", finance.sum, finance.average, finance.max, finance.min);
	printf("����     %-9d%-11d%-10d%d\n", sale.sum, sale.average, sale.max, sale.min);
	printf("_____________________________________________________________________\n");
	putchar('\n');
}
void Tofile() {
	FILE* fp;
	if ((fp = fopen("D:\\WAGE.txt", "w")) == NULL) {
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	struct worker * ptemp = head;
	while (ptemp != NULL) {
		fprintf(fp, "%s %s %s %g %g %g %g %g %g\n", ptemp->id, ptemp->name, ptemp->department, ptemp->wagebsc, ptemp->wagepsn, ptemp->allwance, ptemp->insurance, ptemp->bonus, ptemp->fund);
		ptemp = ptemp->next;
	}
	if (fclose(fp)) {
		printf("�޷������ر��ļ���");
		exit(0);
	}
	

}
void Toread() {
	FILE* fp;
	int N;
	char name0[20];
	char id0[5];
	char department0[10];
	double wagebsc0;
	double wagepsn0;
	double allwance0;
	double insurance0;
	double bonus0;
	double fund0;
	
	if ((fp = fopen("D:\\WAGE.txt", "r"))==NULL) {
		printf("Can not open the file!");
		exit(0);
	}
	while (!feof(fp)) {
		fscanf(fp," %s%s%s%lf %lf %lf %lf %lf %lf", id0, name0, department0, &wagebsc0, &wagepsn0, &allwance0, &insurance0, &bonus0, &fund0);
		struct worker* ptemp = (struct worker*)malloc(sizeof(struct worker));
		strcpy(ptemp->id, id0);
		strcpy(ptemp->name, name0);
		strcpy(ptemp->department, department0);
		ptemp->wagebsc = wagebsc0;
		ptemp->wagepsn = wagepsn0;
		ptemp->allwance = allwance0;
		ptemp->insurance = insurance0;
		ptemp->bonus = bonus0;
		ptemp->fund = fund0;/*�ܹ���ֱ���������ʱ��ֱ�Ӽ���*/
		ptemp->sum = wagebsc0 + wagepsn0 + allwance0 + insurance0 + bonus0 + fund0;
		ptemp->next = NULL;
		if (head == NULL) {
			head = ptemp;
			tail = ptemp;
		}
		else {
			tail->next = ptemp;/*����β����ķ���*/
			tail = ptemp;
		}
	}
	if (fclose(fp)) {
		printf("�޷������ر��ļ���");
		exit(0);
	}
}