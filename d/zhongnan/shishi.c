//Cracked by Roath
// road: /zhongnan/shishi.c

inherit ROOM;

void create()
{
        set("short", "石室");

        set("long",@LONG
石室中放着五具石棺(guan)，其中两具石棺棺盖以密密盖着。据说放
的是历代前辈的遗体。另外三其的棺盖却只推上一半，也不知其中有无尸
体，怪吓人的。
LONG);

		  set("item_desc",(["guan" : "
这石棺半开半掩着，也不知有没有尸体在里面，没什麽好看的。
\n",]));

		  set("exits",([ "east" : __DIR__"zoudao4",
								"down" : __DIR__"midao1",

							 ])
			  );
	  set("cost",1);
	  set("outdoors", "zhongnan");

		  setup();
		  replace_program(ROOM);
}

