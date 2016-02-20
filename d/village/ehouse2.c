//Cracked by Roath
// Room: /d/village/ehouse2.c

inherit ROOM;

void create()
{
        set("short", "民宅");
        set("long", @LONG
这是一间很结实的房子，虽然也是间土坯房，但看的出建造的比村里其他的土
坯房要好很多。墙上挂着、地下摆着一些农具。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" :__DIR__"eroad2",
]));
        set("objects", ([
                __DIR__"npc/dibao": 1 ]) );
        set("no_clean_up", 0);

        set("cost", 0);
        setup();
        replace_program(ROOM);
}

