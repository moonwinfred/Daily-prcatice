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


int main() {/*主菜单部分*/
	int n;
	Toread();
	
	while (1) {
		printf("________________________________________\n");
		putchar('\n');
		printf("            职工工资管理系统\n");
		printf("________________________________________\n");
		putchar('\n');
		printf("**************1、数据维护***************\n");
		printf("________________________________________\n");
		putchar('\n');
		printf("**************2、统计数据***************\n");
		printf("________________________________________\n");
		putchar('\n');
		printf("**************3、综合数据***************\n");
		printf("________________________________________\n");
		putchar('\n');
		printf("**************4、退出系统***************\n");
		printf("________________________________________\n");
		printf("请输入选项：");
		scanf("%d", &n);
		switch (n) {
		case 1:if(menu1()==0); break;
		case 2:if (menu2() == 0);  break;
		case 3:if(menu3() == 0); break;
		case 4:putchar('\n'); printf("您已退出系统，谢谢！\n"); return 0;
		}
	}
	
}
int menu1() {/*数据维护部分菜单*/
	int n;
	int flag = 0;
	for(int i=0;;i++) {
		printf("__________________________________\n");
		putchar('\n');
		printf("            数据维护\n");
		printf("__________________________________\n");
		putchar('\n');
		printf("----------1、数据添加-------------\n");
		printf("----------2、数据修改-------------\n");
		printf("----------3、数据删除-------------\n");
		printf("----------4、数据查询-------------\n");
		printf("----------0、返回上级菜单---------\n");
		printf("__________________________________\n");
	
		printf("请输入选项：");
		
		
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
	printf("            数据添加\n");
	
	printf("请输入您需要导入的职工基本数据的数量：");
	scanf("%d", &N);
	putchar('\n');
	printf("接下来请按右侧顺序依次输入职工信息:①ID姓名②部门③基本工资④职务工资⑤津贴⑥保险⑦奖金⑧公积金\n");
	printf("<每个信息以空格为间隔 按Enter键输入下一个员工信息。>\n");
	putchar('\n');
	printf("现在开始进行输入：\n");
	int flag,plag;
	for (int i = 0; i < N; i++) {
		scanf("%s%s%s%lf%lf%lf%lf%lf%lf", id0, name0, department0, &wagebsc0, &wagepsn0, &allwance0, &insurance0, &bonus0, &fund0);
		flag = 0;
		struct worker* pt = head;
		while (pt != NULL) {
			if (strcmp(pt->id,id0)==0) {/*用于判断是否有重复的ID号*/
				char k;
				flag = 1;
				printf("该职工ID号已重复，请选择重新输入或者是跳过该次输入。\n");
				printf("A重新输入 B跳过该次输入\n");
				getchar();
				k = getchar();
				if (k == 'A')i=i-1;/*即循环仍为原来的数值*/
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
		ptemp->fund = fund0;/*总工资直接在输入的时候直接计算*/
		ptemp->sum = wagebsc0 + wagepsn0 + allwance0 + insurance0 + bonus0 + fund0;
		ptemp->next = NULL;
		if (head == NULL) {
			head = ptemp;
			tail = ptemp;
	}
		else {
			tail->next = ptemp;/*利用尾插入的方法*/
			tail = ptemp; 
		}

	}
	printf("记录输入完成！\n");
	printf("......现在保存进文件中。\n");
	Tofile();/*保存进文件当中*/
	printf("文件保存成功！现在返回上级菜单。\n");


}
int modify() {
	printf("            数据修改\n");
	int k;
	while(1){
		printf("请输入您需要修改的员工ID号或者是姓名：");

		char id1[5];
		scanf("%s", id1);
		putchar('\n');
		printf("稍等一下，现在为您在系统中查找该员工信息。\n");
		printf("...........................................\n");

		struct worker* ptemp = head;
		while (ptemp != NULL) {/*判断是否在系统中存在*/
			if (strcmp(ptemp->id, id1) == 0 || strcmp(ptemp->name, id1) == 0) {
				break;
			}
			ptemp = ptemp->next;
		}
		if (ptemp == NULL) {
		printf("对不起，系统中无该员工ID的记录。\n");
		printf("如需直接返回上级菜单停止操作，请输入0。\n");
		printf("需要重新操作，则输入1，谢谢！\n");
		
		scanf("%d", &k);
		if (k == 0)return 0;
		else continue;
	}
	else {
			printf("成功找到该员工记录！该员工信息如下\n");
			printf("ID：%s\n", ptemp->id);
			printf("姓名：%s\n", ptemp->name);
			printf("基本工资：%g\n", ptemp->wagebsc);
			printf("职务工资：%g\n", ptemp->wagepsn);
			printf("津贴：%g\n", ptemp->allwance);
			printf("医疗保险：%g\n", ptemp->insurance);
			printf("公积金： %g\n", ptemp->bonus);
			printf("奖金：%g\n", ptemp->fund);
			printf("能够修改的内容如下：\n");
		printf("A 姓名B 部门 C 基本工资 D 职务工资 E 津贴 F 医疗保险 G 公积金 H 奖金\n");
		printf("请输入需要修改的内容(用上述大写字母表示）：");
		getchar();
		char p;
		p = getchar();
		putchar('\n');
		if (p == 'A' || p == 'B') {/*对字符串类型和整数类型进行区分*/
			char xb[10];
			printf("请输入修改后的内容：");
			scanf("%s", xb);
			printf("现在正在修改中，请稍等。\n");
			printf("........................\n");
			switch (p) {
			case 'A':strcpy(ptemp->name, xb); break;
			case 'B':strcpy(ptemp->department, xb); break;
			}
		}
		else {/*对字符串类型和浮点数类型进行区分*/
			int gz;
			printf("请输入修改后的内容：");
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
		printf("修改已完成！这是修改以后的数据：\n");
		printf("ID：%s\n", ptemp->id);
		printf("姓名：%s\n", ptemp->name);
		printf("基本工资：%g\n", ptemp->wagebsc);
		printf("职务工资：%g\n", ptemp->wagepsn);
		printf("津贴：%g\n", ptemp->allwance);
		printf("医疗保险：%g\n", ptemp->insurance);
		printf("公积金： %g\n", ptemp->bonus);
		printf("奖金：%g\n", ptemp->fund);

		printf("......现在保存进文件中。\n");
		Tofile();
		printf("文件保存成功！\n");
		putchar('\n');
		printf("如需直接返回上级菜单停止操作，请输入0。\n");
		printf("需要重新操作，则输入1，谢谢！\n");
		printf("请输入您的选项：");
		scanf("%d", &k);
		if (k == 0)return 0;
		else continue;
	}
	}
}
int Delete() {
	int k;
	printf("            数据删除\n");
	while (1) {
		printf("请输入需要删除记录的员工ID号或者姓名：");
		char id1[5];
		scanf("%s", id1);
		struct worker* ptemp = head;/*判断系统是否有该数据*/
		while (ptemp != NULL) {
			if (strcmp(ptemp->id, id1) == 0 || strcmp(ptemp->name, id1) == 0) {
				break;
			}
			ptemp = ptemp->next;
		}
		if (ptemp == NULL) {
			printf("对不起，该系统无该员工ID的记录。无法进行删除\n");
			printf("如需返回上级菜单停止删除，请输入0。\n");
			printf("如还要重新输入则输入1，谢谢！\n");
			printf("请输入您的选项：");
			scanf("%d", &k);
			if (k == 0)return 0;
			else continue;
		}
		else {/*数据删除需要分类*/
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
			printf("已删除该员工记录。\n");
			printf("......现在将删除后的记录重新保存进文件中。\n");
			Tofile();
			printf("文件保存成功!\n");
			printf("如需返回上级菜单，请输入0。\n");
			printf("如还需要继续删除，请输入1，谢谢！\n");
			printf("请输入您的选项：");
			scanf("%d", &k);
			if (k == 0)return 0;
			else continue;

		}
	}
}
int search() {
	int k;
	printf("            数据查找\n");
	while (1) {
		printf("请输入您需要查找的员工ID号或者姓名：");
		char id1[5];
		scanf("%s", id1);
		printf("现在正在查找，请稍等。\n");
		printf("........................\n");
		struct worker* ptemp = head;
		while (ptemp != NULL) {
			if (strcmp(ptemp->id, id1) == 0||strcmp(ptemp->name,id1)==0) {
				break;
			}
			ptemp = ptemp->next;
		}
		if (ptemp == NULL) {
			printf("对不起，该系统无该员工ID的记录。\n");
			printf("如需返回上级菜单停止查找，请输入0。\n");
			printf("如需重新输入进行查找，请输入1。\n");
			printf("请输入您的选项：");
			scanf("%d", &k);
			if (k == 0)return 0;
			else continue;
		}
		else {
			printf("成功查找到该员工信息!该员工信息如下：\n");
			
			printf("ID：%s\n", ptemp->id);
			printf("姓名：%s\n", ptemp->name);
			printf("基本工资：%g\n", ptemp->wagebsc);
			printf("职务工资：%g\n", ptemp->wagepsn);
			printf("津贴：%g\n", ptemp->allwance);
			printf("医疗保险：%g\n", ptemp->insurance);
			printf("公积金： %g\n", ptemp->bonus);
			printf("奖金：%g\n", ptemp->fund);
			putchar('\n');
			printf("数据查询完毕！\n");
			printf("如需返回上级菜单停止查找，请输入0。\n");
			printf("如需再次进行查找，则输入1，谢谢！\n");
			printf("请输入您的选项：");
			scanf("%d", &k);
			if (k == 0)return 0;
			else continue;

		}
		
	}
}
int menu2() {
	int n;
	if (head == NULL) {
		printf("不好意思！该系统无记录数据，无法进行统计！");
		return 0;
	}
	for (int i = 0;; i++) {
		printf("_____________________________________________________\n");
		putchar('\n');
		printf("                   统计数据\n");
		printf("_____________________________________________________\n");
		putchar('\n');
		printf("----------  1、各项的平均工资及总工资----------------\n");
		printf("----------  2、符合指定条件内职工人数占总职工百分比--\n");
		printf("------------3、各部门工资总额，平均工资及最高工资----\n");
		printf("------------0、返回上级菜单--------------------------\n");
		printf("_____________________________________________________\n");

		printf("请输入选项：");
		scanf("%d", &n);

		if (n == 0) return 0;
		switch (n) {
		case 1:Print1(); break;
		case 2:Print2(); break;
		case 3:print2(); break;
		case 4:printf("输入数值有误！无法显示表格！\n");
		}
	}
}
void calpaverage() {/*计算各项的平均工资*/
	int count = 0;/*需要实时去计算系统的总数据*/
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
		ptemp = ptemp->next;/*一直进行累加*/
	}
	paverage->wagebsc /= (count * 1.0);
	paverage->wagepsn /= (count * 1.0);
	paverage->allwance /= (count * 1.0);
	paverage->insurance /= (count * 1.0);
	paverage->bonus /= (count * 1.0);
	paverage->fund /= (count * 1.0);
	paverage->sum = (paverage->wagebsc) + (paverage->wagepsn) + (paverage->insurance)
		+ (paverage->bonus) + (paverage->fund);
	/*需要把数字转化成和表格一样 如果小数点有零则直接不显示 若有则显示出来*/
	/*去掉小数后多余的0 输出的时候用%g */


}
void caldepartment() {
	int acount, fcount, scount;/*计算部门的信息*/
	acount = fcount = scount = 0;
	administr.sum = administr.average = administr.max = administr.min = 0;
	finance.sum = finance.average = finance.max = finance.min = 0;
	sale.sum = sale.average = sale.max = sale.min = 0;
	char a[10] = { "行政" };
	char b[10] = { "财务" };
	char c[10] = { "销售" };
	struct worker* ptemp = head;
	while (ptemp != NULL) {
		if (strcmp(ptemp->department, a) == 0) {
			acount++;
			if (acount == 1) {/*将第一个进来的记录 当做最大值和最小值 用于比较*/
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
	a1 = a2 = a3 = 0;/*用于计算百分比*/
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
	printf("            各项平均工资及总工资\n");
	printf("________________________________________________\n");
	putchar('\n');
	printf("基本工资：         %g\n", paverage->wagebsc);
	printf("________________________________________________\n");
	putchar('\n');
	printf("职务工资：         %g\n", paverage->wagepsn);
	printf("________________________________________________\n");
	putchar('\n');
	printf("津贴：             %g\n", paverage->allwance);
	printf("________________________________________________\n");
	putchar('\n');
	printf("医疗保险：         %g\n", paverage->insurance);
	printf("________________________________________________\n");
	putchar('\n');
	printf("公积金：           %g\n", paverage->bonus);
	printf("________________________________________________\n");
	putchar('\n');
	printf("奖金:              %g\n", paverage->fund);
	printf("________________________________________________\n");
	putchar('\n');
	printf("总工资：           %g\n", paverage->sum);
	printf("________________________________________________\n");
	putchar('\n');


}
void Print2() {
	calpercentage();
	printf("___________________________________________________________________\n");
	putchar('\n');
	printf("            符合指定条件内职工人数占总职工百分比\n");
	printf("___________________________________________________________________\n");
	putchar('\n');
	printf("前三项之和三千以上：       %g%%\n", a1*100);
	printf("___________________________________________________________________\n");
	putchar('\n');
	printf("前三项之和两千到三千：     %g%%\n", a2*100);
	printf("___________________________________________________________________\n");
	putchar('\n');
	printf("前三项之和一千到两千：     %g%%\n", a3*100);
	printf("___________________________________________________________________\n");
	putchar('\n');



}
int menu3() {
	int n;
	if (head == NULL) {
		printf("不好意思！该系统无记录数据，无法打印表格！");
		return 0;
	}
	for (int i = 0;; i++) {
		printf("___________________________________________\n");
		putchar('\n');
		printf("               综合数据\n");
		printf("____________________________________________\n");
		putchar('\n');
		printf("----------  1、职工工资信息表----------------\n");
		printf("----------  2、各部门职工工资信息表及平均工资\n");
		printf("------------0、返回上级菜单------------------\n");
		printf("_____________________________________________\n");
		putchar('\n');

		printf("请输入选项：");
		scanf("%d", &n);
		
		if (n == 0) return 0;
		switch (n) {
		case 1:print1(); break;
		case 2:print2(); break;
		default:printf("输入数值有误！无法显示表格！\n");break;
		}
	}
}

void print1() {
	calpaverage();
	printf("                               职工工资信息表\n");
	printf("_____________________________________________________________________________________\n");
	putchar('\n');
	printf("ID号   姓名    部门  基本工资   职务工资   津贴  医疗保险  公积金    奖金    总工资\n");
	printf("_____________________________________________________________________________________\n");
	putchar('\n');
	
	struct worker* pt = head;
	while (pt != NULL) {
	printf("%-7s%-8s%-7s%-11g%-10g%-7g%-10g%-10g%-8g%g\n", pt->id, pt->name, pt->department, pt->wagebsc, pt->wagepsn, pt->allwance, pt->insurance, pt->bonus, pt->fund,pt->sum);
	pt = pt->next;
	}
	printf("各项平均工资          %-11g%-10g%-7g%-10g%-10g%-8g%g\n", paverage->wagebsc, paverage->wagepsn, paverage->allwance, paverage->insurance, paverage->bonus, paverage->fund,paverage->sum);
	printf("_____________________________________________________________________________________\n");
	putchar('\n');
	


}
void print2() {
	caldepartment();
	printf("                  各部门职工工资信息表及平均工资\n");
	printf("_____________________________________________________________________\n");
	putchar('\n');
	printf("部门   工资总额  平均工资  最高工资  最低工资\n");
	printf("_____________________________________________________________________\n");
	putchar('\n');
	printf("行政     %-9d%-11d%-10d%d\n", administr.sum, administr.average, administr.max, administr.min);
	printf("财务     %-9d%-11d%-10d%d\n", finance.sum, finance.average, finance.max, finance.min);
	printf("销售     %-9d%-11d%-10d%d\n", sale.sum, sale.average, sale.max, sale.min);
	printf("_____________________________________________________________________\n");
	putchar('\n');
}
void Tofile() {
	FILE* fp;
	if ((fp = fopen("D:\\WAGE.txt", "w")) == NULL) {
		printf("打开文件失败！");
		exit(0);
	}
	struct worker * ptemp = head;
	while (ptemp != NULL) {
		fprintf(fp, "%s %s %s %g %g %g %g %g %g\n", ptemp->id, ptemp->name, ptemp->department, ptemp->wagebsc, ptemp->wagepsn, ptemp->allwance, ptemp->insurance, ptemp->bonus, ptemp->fund);
		ptemp = ptemp->next;
	}
	if (fclose(fp)) {
		printf("无法正常关闭文件！");
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
		ptemp->fund = fund0;/*总工资直接在输入的时候直接计算*/
		ptemp->sum = wagebsc0 + wagepsn0 + allwance0 + insurance0 + bonus0 + fund0;
		ptemp->next = NULL;
		if (head == NULL) {
			head = ptemp;
			tail = ptemp;
		}
		else {
			tail->next = ptemp;/*利用尾插入的方法*/
			tail = ptemp;
		}
	}
	if (fclose(fp)) {
		printf("无法正常关闭文件！");
		exit(0);
	}
}