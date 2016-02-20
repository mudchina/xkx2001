//Cracked by Roath
// Room: /city/xidajie1.c
// xQin 6/00

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。北面的茶馆时时传来一片喧
哗之声，客人鱼贯般出入。朝南是有名的轩辕棋苑，不少文人雅士都喜欢到那高
谈阔论，以棋会友。东边是一个热闹的广场。      
LONG );
        set("outdoors", "city");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"guangchang",
                "south" : __DIR__"weiqi_qiyuan",
                "west"  : __DIR__"xidajie2",
                "north" : __DIR__"chaguan",
        ]));

        set("objects",([
                CLASS_D("mingjiao")+"/weiyixiao" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
