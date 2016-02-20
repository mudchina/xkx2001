//Cracked by Roath
// /d/huanghe/tcdating.c

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
转了个弯，你眼前突然大亮，竟是到了一间大厅之中，墙上插着无数
火把，照耀如同白昼，四周站满了手持铁叉的会众。和这些人恶毒凶狠的
目光相触之下，你不禁打了个冷颤。
LONG );

        set("exits", ([
		"south" : __DIR__"tctongdao",
        ]));

    	set("cost", 1);

        set("objects", ([
                __DIR__"npc/tc_you" : 1,
                __DIR__"npc/tc_hu" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
