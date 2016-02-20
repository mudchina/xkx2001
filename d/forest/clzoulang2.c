//Cracked by Roath
// changle/clzoulang2.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这里往来的人少了些，西面不断传来阵阵吵闹之声，有时还夹杂
着怒骂和尖叫。空中弥漫着烟酒的气味。地上显得甚是肮脏，抛弃着
一些油腻的残羹剩菜。
LONG );

        set("exits", ([
		"south" : __DIR__"clzoulang1",
		"north" : __DIR__"clxiaoting",
		"east" :  __DIR__"clhuayuan",
		"west" :  __DIR__"clxiaowu",
        ]));

        set("cost", 0);

        setup();
        replace_program(ROOM);
}

