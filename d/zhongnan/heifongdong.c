//Cracked by Roath
// road: /zhongnan/heifongdong.c

inherit ROOM;

void create()
{
        set("short","黑凤洞");

        set("long",@LONG
此处位於终南山脉东部的太阳山上。只见山峰直上直下，像刀切般的
陡峭，只山腰上有一个碾盘子粗的石洞，不时冒出一股黑气，怪可怕的。
往西是一片树林。
LONG);

		  set("exits",([ "westup" : __DIR__"shulin3",
							 ])
			  );
	  set("cost",3);
	  set("outdoors", "zhongnan");

		  setup();

        replace_program(ROOM);
}
