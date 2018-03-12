#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>

typedef struct   //定义一个汽车的结构体
{
	int num;
}car;

typedef struct
{
	car *top;
	car *boom;
	int length; //长度
}zhan;          //定义一个站，这个站是用于建立汽车堆栈的结构体

	zhan s;     //全局变量堆栈s

void initzhan()
{
	s.top =(car *)malloc(10*sizeof(car)); //申请了50个节点，这些节点的引用型是ZHAN *形式，此刻s.top里面存储的就是一个car型对象的地址，可通过（s.top）->num来引用。
	                                      //s.top就相当于一个指针，指向一个类int a,形式的car e结构体。
	s.boom=s.top ;
	s.length =50;
}

void in()
{
	
     void out();
	 car e;
	 car *t;
	 int i=1,a=s.top -s.boom ;
	 t=s.boom ;
	 printf("请输入车牌号:");
	 scanf("%d",&e.num );
	 if(a>=5)                             //用于当车停于便道等待时给用户选择是否等待的信息
	 {	 printf("    █████．\n    █田█田█．\n    █田█田█．\n    █田█田█．\n    █田█田█．\n    █████．\n  ◢██□██◣．\n抱歉您的车必须先停在便道等候，请问您是否愿意等待？\n");
	     printf("\n愿意请按1，离开请按2：");
		 scanf("%d",&i);
	 }
     if(i==1)
	 {
	 while(e.num !=(s.boom)->num  )                          //是用来判断该号车牌在车库中有没有
	 {
		 if(a ==0)                                           //判断是否是第一辆车，如果是第一辆的话就直接进，不判断
			 break;
		 if(s.boom ==s.top )
			 break;
		 s.boom ++;
	 }
	 if(a!=0)
	 { if(s.boom !=s.top )
	    {	
	         printf("该车已停在车库，请问您是想取车吗？1（yes） or 2（no）：");
			 char d=getchar();             //getchar 输入的是ASCII，比如输入1，对应是ASCII表中的‘1’，而非数字1
		 	 while(d==10) d=getchar();
			 char d1=getchar();
			 while(d1!=10) d1=getchar();
			 if(d=='1')
			 {
				 printf("但是现在我不能判断你是不是车主，所以抱歉我不能让你提车\n");
				 //out();
			 }
			 if(d=='2')               //这里判断用的是'2',而非2
                  ;
	          }
	 	 else
		 {
        	 *(s.top)= e;                                  //把e结构体的内容 赋给 s.top所指向的结构体
        	 s.top ++;
             printf("车牌号为%d的车辆已入库",e.num  );
	 }
	 }
	 else
	 {
	 *(s.top)= e;                                  //把e结构体的内容 赋给 s.top所指向的结构体
	 s.top ++;
     printf("车牌号为%d的车辆已入库",e.num  );
	 }
	 s.boom =t;
	 }
}

void out()
{
	int i;
	car *t;
	t=s.boom ;
	printf("请输入您要取车的车牌号:");
    scanf("%d",&i);
	while(i!=(s.boom)->num)                                //s.boom->num,与(s.boom)->num的区别
	{	if(s.boom ==s.top)
	   {
		printf("您没有停该辆车于此处，请核对后再拨");
		break;}
		else
		    s.boom ++;
	}
	if(s.boom !=s.top )
	{
		printf("车牌号为%d的车已由车主取出",i);
		while(s.boom!=s.top)
		{
		   *(s.boom) =*(s.boom +1);                       //前者指向结构体的内容整体赋给后一个结构体。
		   s.boom++;
		}
		s.top--;
		s.boom =t;
	}
}

void showstation()
{
	car *t;
	t=s.boom ;
	printf("以下是当前停车的情况：\n");
	while(s.boom !=s.top )
	{
		//printf("%d\n",s.boom);     //用来测试s.boom这个指针存储的结构体每次增加1时地址是否增加1；a=s.top -s.boom ;测试该句的正确性
   	    printf(" car : 【▆】 车牌号： %d\n",(s.boom++)->num);
	}
    s.boom =t;
    printf("您已查看所有车辆 OVER\n");
	printf("       continue?\n   1（yes） or 2（no）： ");
    char d=getchar();             //getchar 输入的是ASCII，比如输入1，对应是ASCII表中的‘1’，而非数字1
	while(d==10) d=getchar();
	char d1=getchar();
	while(d1!=10) d1=getchar();
	if(d=='2')               //这里判断用的是'2',而非2
		exit(0);              //直接退出整个程序
}

void show()
{
	int i=15,a,c=0;char d;
	a=s.top -s.boom ;        //看有多少辆车
	for(;i>0;i--)
	    printf("==");        //上停车导引线
	printf("\n");            //换行停车
	i=a+1;
	for(;a>0;a--,c++)
	{	if(c==5)
			printf(" |  | ");//停车区与等候区分界线
		printf("【▉】");    //车的模型
	}
	for(;i<6;++i)
		printf("   %d  ",i); //剩余车位的车位号显示
	printf("\n");
	for(i=15;i>0;i--)
	    printf("==");        //下停车导引线
	printf("\n");            //换行，以便一下行进行标示
	for(i=13;i>0;i--)
		printf(" ");
	printf("停车区");        //停车区标示
	for(i=13;i>0;i--)
		printf(" ");
	printf("||");            //停车区标示与非停车区标示分割线
	for(i=3;i>0;i--)
		printf(" ");
	printf("待进入车辆等候区");//等候区标示
	printf("\n");
	printf("       continue?\n   1（yes） or 2（no）： ");
	d=getchar();             //getchar 输入的是ASCII，比如输入1，对应是ASCII表中的‘1’，而非数字1
	while(d==10) d=getchar();
	char d1=getchar();
	while(d1!=10) d1=getchar();
	if(d=='2')               //这里判断用的是'2',而非2
		exit(0);              //直接退出整个程序
}

void welcome()
{
    printf("                  请开始你的表演\n");
 	printf("\n");     
	printf("				             ☆☆ ☆☆  ☆☆ ☆☆\n");
	printf("1:进站  		                    ★★      ★       ★★\n");
	printf(" 				 	   ☆☆   祝你快乐！    ☆☆\n");
	printf("2:出站    			            ★★               ★★\n");
	printf(" 				             ☆☆             ☆☆\n");
	printf("3:查看车站停车车牌情况	                       ★★         ★★\n");
	printf(" 					         ☆☆     ☆☆\n");
	printf("4:查看车站分布情况    	      	                   ★★  ★★\n");
	printf("                                                      ☆☆\n");
	printf("5:结束系统 \n");           
	printf("//*****************************************************************//\n");
}

void delay(int a)
{
	int b=1000,c=0;
	while(a--)
	{
		b=1000;
		while(b--)
		{
			c=450;
			while(c--);
		}
	}
}

//这里存数据为.dat文件，和相应的读取.dat文件时的问题。存文件时出现问题，导致并没有执行相应程序，所以，装载时，总是和固有数据对不上
//存档和读时数据类型必须对应。
void savescore()
{//存储此次库中车辆
    FILE *f;car *t=s.boom;int i=s.top-s.boom;
    if((f=fopen("score1.dat","wb"))==NULL)return;
   	fwrite(&i,sizeof(int),1,f);                         //fwrite(指针，类型长度，几次，文件指针)
	//向文件f中写出入‘一个’‘int型’的数据i
	while(s.boom!=s.top)  
        fwrite(s.boom++,sizeof(car),1,f);               //指针是，比如你要存一个数据，你必须通过指针引用才能存档。类型长度，就是这个数据的类型。几次，就是存几个数据。             
	//向文件中写入一个’‘car’型数据s.boom。while是循环写
	s.boom=t;
    fclose(f);
}
void loadscore()
{//读取上一次存的库中车辆
    int a;
    FILE *f;
    if((f=fopen("score1.dat","rb"))==NULL)return;
    fread(&a,sizeof(int),1,f);        
	for(;a>0;a--)
		fread(s.top++,sizeof(car),1,f);
     fclose(f);  
}

void main()
{
	int qw=0,we=0,a[5]={0},b[5]={1,2,3,4,5},i=0;
	initzhan();
	loadscore();
	while(qw==0)
	{
		welcome();
	char i=getchar();
	while(i==10) i=getchar();                      //如果是enter，就重新输入。知道得到一个确定的char值
	char a=getchar();                              //用以清除多余的输入
	while(a!=10) a=getchar();                            
	switch(i)
	{
	case '1':in();break;
	case '2':out();break;
	case '3':showstation();break;
	case '4':show();break;
	case '5':qw=1;break;
	default:printf("     输入有误，你到底有没有认真读说明书，简直醉了……\n");
			printf("           输错了，还继续输入吗?\n   1（yes） or 2（no）： ");
			char d=getchar();             //getchar 输入的是ASCII，比如输入1，对应是ASCII表中的‘1’，而非数字1
			while(d==10) d=getchar();
			char d1=getchar();
			while(d1!=10) d1=getchar();
			if(d=='2')               //这里判断用的是'2',而非2
				exit(0);              //直接退出整个程序
			break;
	}
	printf("\n//*************************************************************//\n");
	}
	savescore();
	free(s.boom );
	
}