//Cracked by Roath
// Room: /d/village/eroad2.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个宁静的小村子，稀稀落落的分布着几十间土坯泥房，看来村中人家不
多，而且大都生活很艰辛。这是一条东西向的碎石路，北面是间结实的民宅。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east"  : __DIR__"eroad1",
  "west"  : __DIR__"eroad3",
  "north" : __DIR__"ehouse2",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

