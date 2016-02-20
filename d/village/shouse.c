//Cracked by Roath
// Room: /d/village/shouse.c

inherit ROOM;

void create()
{
        set("short", "小土房");
	set("long", @LONG
这是一间用土坯搭成的房屋，屋里只有几件残破的家俱。在靠门口的墙角有
一只空空的笼子，大概曾经用来养过鸡、鸭之类的家禽。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"sroad2",
]));
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/oldwoman": 1 ]) );

	set("cost", 0);
        setup();
        replace_program(ROOM);
}
 
