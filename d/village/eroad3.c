//Cracked by Roath
// Room: /d/village/eroad3.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个宁静的小村子，稀稀落落的分布着几十间土坯泥房，看来村中人家不
多，而且大都生活很艰辛。这是一条东西向的碎石路，往西就是村子中心的打谷场
了，南面是一间铁匠铺子，北面是家杂货店。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shop",
  "south" : __DIR__"smithy1",
  "east"  : __DIR__"eroad2.c",
  "west"  : __DIR__"square",
]));
        set("objects", ([ __DIR__"npc/girl": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

