//Cracked by Roath
// Room: /d/village/sroad2.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个宁静的小村子，稀稀落落的分布着几十间土坯泥房，看来村中人家
不多，而且大都生活很艰辛。这是一条南北向的碎石路，东面是一间小土房。西
边有一所私塾，传出学童们朗朗读书声。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sroad3",
  "south" : __DIR__"sroad1",
  "east"  : __DIR__"shouse",
  "west"  : __DIR__"sishu",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}


