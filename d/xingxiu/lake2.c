//Cracked by Roath
// xiaoxi.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "大湖");
	set("long", @LONG
这里到处是参天青松，眼前一片大湖，湖的南端是一条大瀑布
，水花四溅，湖周花树参差，杂花红白相间，倒映在碧绿的湖水之
中，奇丽莫名。只听树上小鸟鸣啾，湖中冰块撞击，与瀑布声交织
成一片乐音。西北边是一片辽阔的草原。
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaoxi",
		"northwest" : __DIR__"caoyuan1",
	]));

	set("resource/water",1);
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

