//Cracked by Roath
// xiaoxi.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "山麓小溪");
	set("long", @LONG
溪水在此转弯绕过一块高地，水边树木繁盛，山间挂著一片银
瀑，水声轰轰不绝，匹练有如自天而降，飞珠溅玉，顿成奇观。西
边是一片青松。
LONG
	);

	set("exits", ([
		"east" : __DIR__"luzhou2",
		"west" : __DIR__"lake2",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

