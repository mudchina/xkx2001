//Cracked by Roath
// Room: /d/beijing/gulou.c

inherit ROOM;

void create()
{
        set("short", "鼓楼");
        set("long", @LONG
京城鼓楼每到定更天时分便会开始打鼓，叫做“交更”，
平民百姓听见鼓楼鼓声，便知道时刻了。鼓楼西面就是出名
繁华的鼓楼大街，东边是热闹的东直门大街。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"dianmen",
        "west" : __DIR__"guloudajie_w",
        "north" : __DIR__"zhonglou",
        "east" : __DIR__"guloudajie_e",
        "up" : __DIR__"gulou2",
        ]));
        
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);

        setup();
        replace_program(ROOM);
}
