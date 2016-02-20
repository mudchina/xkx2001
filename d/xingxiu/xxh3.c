//Cracked by Roath
// Room: /d/xingxiu/xxh3.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
这里通向星宿海的深处。
LONG
        );
        set("objects", ([
                __DIR__"npc/gushou"  : 1,
        ]) );

        set("exits", ([
             "southwest" : __DIR__"xxh2",
             "northwest" : __DIR__"xxh5",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        replace_program(ROOM);

}