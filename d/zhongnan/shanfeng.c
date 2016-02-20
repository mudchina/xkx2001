//Cracked by Roath

// road: /zhongnan/shanfeng.c

inherit ROOM;

void create()
{
        set("short","终南山主峰");

		  set("long",@LONG
此时你已身在终南山主峰，视野更为广阔。往低望去，群山尽皆匍匐
在脚下。重阳宫的翠绿琉瓦在山腰处，晶莹生辉。只见不少殿宇散布於山
坳间，景色颇为美妙。一块巨石(shi)立在一旁，似乎刻了什麽东西。往西
和南各是一条山路。
LONG);

        set("item_desc",(["shi" : "

		於人妄矫重异要佐子
		今传迹矫阳人伴汉房
		终入复英起与赤开志
		南道知雄全异松鸿亡
		山初非姿真书游举秦
		，，，，，，，，，
		殿二收乘高造功屹曾
		阁仙心时视物成然进
		凌此活或仍不拂天桥
		烟相死割阔轻衣一下
		雾遇墓据步付去柱履
		。。。。。。。。。

\n",]));

        set("exits",([ "westdown" : __DIR__"shanlu11",
                        "southdown" : __DIR__"shanlu12",
                      ])
           );
	  set("cost",3);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
