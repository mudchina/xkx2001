//Cracked by Roath
// xiaoxi.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "大草原");
	set("long", @LONG
这是一大片青草平原，无边无际的延伸出去，与天相接，草地
上几百只白羊在奔跑吃草。草原西端一座高山参天而起，耸入云霄
，从山腰起全是皑皑白雪，山腰以下却生满苍翠树木。
LONG
	);

	set("exits", ([
		"east" : __DIR__"caoyuan2",
		"west" : __DIR__"caoyuan3",
		"north" : __DIR__"caoyuan4",
		"south" : __DIR__"caoyuan5",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

