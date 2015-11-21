#define D_Round 0.2  //定义轮子转动一周所走过的路程
int k
void Timer1Config(int k)																			   	
{
	TMOD = 0x05;     //定时器0选择工作方式1
	int TH10[5];
	int TL10[5];
	TH1	 = TH10[k];
	TL1	 = TL10[k];
    EA   = 1;	     //打开总中断
    ET1  = 1;		 //打开定时器0中断
    TR1  = 1;		 //启动定时器0
    time_di=0;
}						//16位的计数器容量大约是10公里

void Timer1(void) interrupt 3 //几乎用不到中断 可以想想办法用来干其它事情
{

	Timer1Config(k);
	if(k==5) 
		k=0;
	else
		k++;

							//这里加图案函数
}