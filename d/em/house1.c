//Cracked by Roath
// Room: /d/emei/house1.c 小土屋
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "小土屋");
	set("long", @LONG
这是一间小土屋，看样子是一户农家的房子。屋里简单地摆着些家具，墙
角里堆着些农具。炕上坐着一个老婆婆和一个小孩，见有人冲进来，都神色紧
张地望着你。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "north" :__DIR__"emroad6",
]));
        set("objects", ([
                __DIR__"npc/oldwoman": 1,
		"/d/village/npc/kid": 1,
]) );
        set("no_clean_up", 0);

	set("cost", 0);
        setup();
        replace_program(ROOM);
}
 
