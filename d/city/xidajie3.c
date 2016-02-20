//Cracked by Roath
// Room: /city/xidajie3.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
你走在西大街上，这里的街面要比别处的干净、整洁。因为靠近衙门、兵营
可受保护，富人们都喜欢住在这里。东边静悄悄地没有几个行人，西边是西城门
通往郊外。往南走是林远图创办的“福威镖局”，在北边是一所富丽堂皇的大宅
院。
LONG );
        set("outdoors", "city");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"xidajie2",
                "south" : __DIR__"biaoju",
                "west"  : __DIR__"ximen",
                "north" : __DIR__"caizhu",
        ]));

        set("objects", ([
                "/d/quanzhen/npc/youfang": 1,
        ]));

        setup();
        replace_program(ROOM);
}
