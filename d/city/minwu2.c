//Cracked by Roath
// Room: /city/minwu1.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "民屋");
	set("long", @LONG
这是一个尚有一点钱的老百姓家，与别的民屋不同的是这间房屋较为宽敞，
家里的家具也较新，屋里的一位妇人看见你来了笑眯眯地向你迎来。西边是一条
小土路，几个小孩正在那玩耍。向南可以看到一间破旧的小庙宇。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaomiao",
		"west" : __DIR__"xiaotulu",
	]));

	set("objects", ([
		__DIR__"npc/woman" : 1,
		__DIR__"npc/girl" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

