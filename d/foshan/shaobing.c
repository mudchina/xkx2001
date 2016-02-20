//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "烧饼油条铺");
        set("long", @LONG
这家烧饼油条铺是新开张的。铺面不大，正中央摆了一个大炸
锅和一个烤炉。
LONG
        );
        set("exits", ([
		"south" : __DIR__"street3",
	]));

	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	setup();
        replace_program(ROOM);
}
