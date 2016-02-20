//Cracked by Roath
// room: road1.c

inherit ROOM;

void create()
{
        set("short", "青石路");
        set("long", @LONG
你的眼前出现一条长长的青石路，直通往广场。两旁是郁郁葱葱
的树林，不时传来几声鸟叫，叫人顿时心情舒畅。青石表面已被磨的
甚是光滑，看来年代颇久。
LONG );

        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"damen",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
