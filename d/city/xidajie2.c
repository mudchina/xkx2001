//Cracked by Roath
// Room: /city/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西大街是衙门所在，行人稀
少，静悄悄地很是冷清。东边是两个棋苑，有不少风雅之士聚集在那里。北边是
兵营，而南边就是衙门了。
LONG );
        set("outdoors", "city");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"xidajie1",
                "north" : __DIR__"bingyindamen",
                "west"  : __DIR__"xidajie3",
                "south" : __DIR__"yamen",
        ]));

        setup();
        replace_program(ROOM);
}

