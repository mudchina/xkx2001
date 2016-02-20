//Cracked by Roath
// wuyaling.c 乌鸦岭 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "乌鸦岭");
	set("long", @LONG
这是一狭长的脊岭，两侧悬削，一无所傍，但见白云朵朵，冉冉而过，山
风拂拂，阵阵袭来。数百只乌鸦正翱翔云际，黑白分明，蔚成奇观。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"langmei",
                "southup" : __DIR__"sanlaofeng",
	]));
        set("objects", ([
                __DIR__"npc/wuya" : 5,
        ]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

