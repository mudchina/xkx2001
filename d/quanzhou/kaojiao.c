//Cracked by Roath
// kaojiao.c 考教场
// qfy July 30, 1996.

inherit ROOM;

void create()
{
        set("short", "考教场");
	set("long", @LONG
这里是武馆的考教场，面积甚大。有许多武馆子弟在此习武，拳打脚踢，
舞刀弄剑，耍枪挥棒的好不热闹。穿过考教场便是武馆的前厅。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"qianting",
            "east" : __DIR__"wgdamen",
        ]));

	set("objects", ([
	    __DIR__"npc/xuetu" : 3,	
	]));

        set("no_clean_up", 0);
        set("outdoors", "city" );

	set("cost", 1);
        setup();
        //replace_program(ROOM);
}
