//Cracked by Roath
// Room: /d/dali/guandao.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
你走在一条青石官道上，这里已经是南诏境内了，路上时时可以看到各色各
样的商人来来往往，络驿不绝。路边站了几个衣饰华艳的摆夷女子，其中一个身
穿白衣的显得格外秀丽。此去向南即是大理国北关口太和城，沿官道向东北可达
中原。
LONG);
	set("objects", ([
		__DIR__"npc/baiyi" : 2,
		]));
	set("exits", ([
		"northeast" : __DIR__"guandao5",
		"southwest" : __DIR__"nanbei",
        "west" : __DIR__"chadao",
	]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
