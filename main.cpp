#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>

typedef struct   //����һ�������Ľṹ��
{
	int num;
}car;

typedef struct
{
	car *top;
	car *boom;
	int length; //����
}zhan;          //����һ��վ�����վ�����ڽ���������ջ�Ľṹ��

	zhan s;     //ȫ�ֱ�����ջs

void initzhan()
{
	s.top =(car *)malloc(10*sizeof(car)); //������50���ڵ㣬��Щ�ڵ����������ZHAN *��ʽ���˿�s.top����洢�ľ���һ��car�Ͷ���ĵ�ַ����ͨ����s.top��->num�����á�
	                                      //s.top���൱��һ��ָ�룬ָ��һ����int a,��ʽ��car e�ṹ�塣
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
	 printf("�����복�ƺ�:");
	 scanf("%d",&e.num );
	 if(a>=5)                             //���ڵ���ͣ�ڱ���ȴ�ʱ���û�ѡ���Ƿ�ȴ�����Ϣ
	 {	 printf("    ������������\n    ���切�切��\n    ���切�切��\n    ���切�切��\n    ���切�切��\n    ������������\n  ����������������\n��Ǹ���ĳ�������ͣ�ڱ���Ⱥ��������Ƿ�Ը��ȴ���\n");
	     printf("\nԸ���밴1���뿪�밴2��");
		 scanf("%d",&i);
	 }
     if(i==1)
	 {
	 while(e.num !=(s.boom)->num  )                          //�������жϸúų����ڳ�������û��
	 {
		 if(a ==0)                                           //�ж��Ƿ��ǵ�һ����������ǵ�һ���Ļ���ֱ�ӽ������ж�
			 break;
		 if(s.boom ==s.top )
			 break;
		 s.boom ++;
	 }
	 if(a!=0)
	 { if(s.boom !=s.top )
	    {	
	         printf("�ó���ͣ�ڳ��⣬����������ȡ����1��yes�� or 2��no����");
			 char d=getchar();             //getchar �������ASCII����������1����Ӧ��ASCII���еġ�1������������1
		 	 while(d==10) d=getchar();
			 char d1=getchar();
			 while(d1!=10) d1=getchar();
			 if(d=='1')
			 {
				 printf("���������Ҳ����ж����ǲ��ǳ��������Ա�Ǹ�Ҳ��������ᳵ\n");
				 //out();
			 }
			 if(d=='2')               //�����ж��õ���'2',����2
                  ;
	          }
	 	 else
		 {
        	 *(s.top)= e;                                  //��e�ṹ������� ���� s.top��ָ��Ľṹ��
        	 s.top ++;
             printf("���ƺ�Ϊ%d�ĳ��������",e.num  );
	 }
	 }
	 else
	 {
	 *(s.top)= e;                                  //��e�ṹ������� ���� s.top��ָ��Ľṹ��
	 s.top ++;
     printf("���ƺ�Ϊ%d�ĳ��������",e.num  );
	 }
	 s.boom =t;
	 }
}

void out()
{
	int i;
	car *t;
	t=s.boom ;
	printf("��������Ҫȡ���ĳ��ƺ�:");
    scanf("%d",&i);
	while(i!=(s.boom)->num)                                //s.boom->num,��(s.boom)->num������
	{	if(s.boom ==s.top)
	   {
		printf("��û��ͣ�������ڴ˴�����˶Ժ��ٲ�");
		break;}
		else
		    s.boom ++;
	}
	if(s.boom !=s.top )
	{
		printf("���ƺ�Ϊ%d�ĳ����ɳ���ȡ��",i);
		while(s.boom!=s.top)
		{
		   *(s.boom) =*(s.boom +1);                       //ǰ��ָ��ṹ����������帳����һ���ṹ�塣
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
	printf("�����ǵ�ǰͣ���������\n");
	while(s.boom !=s.top )
	{
		//printf("%d\n",s.boom);     //��������s.boom���ָ��洢�Ľṹ��ÿ������1ʱ��ַ�Ƿ�����1��a=s.top -s.boom ;���Ըþ����ȷ��
   	    printf(" car : ���}�� ���ƺţ� %d\n",(s.boom++)->num);
	}
    s.boom =t;
    printf("���Ѳ鿴���г��� OVER\n");
	printf("       continue?\n   1��yes�� or 2��no���� ");
    char d=getchar();             //getchar �������ASCII����������1����Ӧ��ASCII���еġ�1������������1
	while(d==10) d=getchar();
	char d1=getchar();
	while(d1!=10) d1=getchar();
	if(d=='2')               //�����ж��õ���'2',����2
		exit(0);              //ֱ���˳���������
}

void show()
{
	int i=15,a,c=0;char d;
	a=s.top -s.boom ;        //���ж�������
	for(;i>0;i--)
	    printf("==");        //��ͣ��������
	printf("\n");            //����ͣ��
	i=a+1;
	for(;a>0;a--,c++)
	{	if(c==5)
			printf(" |  | ");//ͣ������Ⱥ����ֽ���
		printf("������");    //����ģ��
	}
	for(;i<6;++i)
		printf("   %d  ",i); //ʣ�೵λ�ĳ�λ����ʾ
	printf("\n");
	for(i=15;i>0;i--)
	    printf("==");        //��ͣ��������
	printf("\n");            //���У��Ա�һ���н��б�ʾ
	for(i=13;i>0;i--)
		printf(" ");
	printf("ͣ����");        //ͣ������ʾ
	for(i=13;i>0;i--)
		printf(" ");
	printf("||");            //ͣ������ʾ���ͣ������ʾ�ָ���
	for(i=3;i>0;i--)
		printf(" ");
	printf("�����복���Ⱥ���");//�Ⱥ�����ʾ
	printf("\n");
	printf("       continue?\n   1��yes�� or 2��no���� ");
	d=getchar();             //getchar �������ASCII����������1����Ӧ��ASCII���еġ�1������������1
	while(d==10) d=getchar();
	char d1=getchar();
	while(d1!=10) d1=getchar();
	if(d=='2')               //�����ж��õ���'2',����2
		exit(0);              //ֱ���˳���������
}

void welcome()
{
    printf("                  �뿪ʼ��ı���\n");
 	printf("\n");     
	printf("				             ��� ���  ��� ���\n");
	printf("1:��վ  		                    ���      ��       ���\n");
	printf(" 				 	   ���   ף����֣�    ���\n");
	printf("2:��վ    			            ���               ���\n");
	printf(" 				             ���             ���\n");
	printf("3:�鿴��վͣ���������	                       ���         ���\n");
	printf(" 					         ���     ���\n");
	printf("4:�鿴��վ�ֲ����    	      	                   ���  ���\n");
	printf("                                                      ���\n");
	printf("5:����ϵͳ \n");           
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

//���������Ϊ.dat�ļ�������Ӧ�Ķ�ȡ.dat�ļ�ʱ�����⡣���ļ�ʱ�������⣬���²�û��ִ����Ӧ�������ԣ�װ��ʱ�����Ǻ͹������ݶԲ���
//�浵�Ͷ�ʱ�������ͱ����Ӧ��
void savescore()
{//�洢�˴ο��г���
    FILE *f;car *t=s.boom;int i=s.top-s.boom;
    if((f=fopen("score1.dat","wb"))==NULL)return;
   	fwrite(&i,sizeof(int),1,f);                         //fwrite(ָ�룬���ͳ��ȣ����Σ��ļ�ָ��)
	//���ļ�f��д���롮һ������int�͡�������i
	while(s.boom!=s.top)  
        fwrite(s.boom++,sizeof(car),1,f);               //ָ���ǣ�������Ҫ��һ�����ݣ������ͨ��ָ�����ò��ܴ浵�����ͳ��ȣ�����������ݵ����͡����Σ����Ǵ漸�����ݡ�             
	//���ļ���д��һ������car��������s.boom��while��ѭ��д
	s.boom=t;
    fclose(f);
}
void loadscore()
{//��ȡ��һ�δ�Ŀ��г���
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
	while(i==10) i=getchar();                      //�����enter�����������롣֪���õ�һ��ȷ����charֵ
	char a=getchar();                              //����������������
	while(a!=10) a=getchar();                            
	switch(i)
	{
	case '1':in();break;
	case '2':out();break;
	case '3':showstation();break;
	case '4':show();break;
	case '5':qw=1;break;
	default:printf("     ���������㵽����û�������˵���飬��ֱ���ˡ���\n");
			printf("           ����ˣ�������������?\n   1��yes�� or 2��no���� ");
			char d=getchar();             //getchar �������ASCII����������1����Ӧ��ASCII���еġ�1������������1
			while(d==10) d=getchar();
			char d1=getchar();
			while(d1!=10) d1=getchar();
			if(d=='2')               //�����ж��õ���'2',����2
				exit(0);              //ֱ���˳���������
			break;
	}
	printf("\n//*************************************************************//\n");
	}
	savescore();
	free(s.boom );
	
}