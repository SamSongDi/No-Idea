void Timer0Cofig(void)																			   	
{
	TMOD = 0x01;     //定时器0选择工作方式1
    TH0  = 0x3C;	 //设置初始值,定时50MS
    TL0  = 0xB0; 
    EA   = 1;	     //打开总中断
    ET0  = 1;		 //打开定时器0中断
    TR0  = 1;		 //启动定时器0
    time50ms=0;
}				

void Timer0() interrupt 1   
{
	TH0	=	0x3C;
	TL0	=	0xB0; 重新置数
	time50ms++;
}

int Speed_Refresh() interrupt 0
{
	int th1,th2,t1;
	do
	{
		th1=TH0;
		t1=TL0;
		th2=TH0;
	}while(th1!=th2)						//飞读计数器
	T_period = time50ms*50000+th1*256+t1;      //时间以微秒为单位 12MHz为晶振频率
	Timer0Config()							//系统误差在10个us左右
}