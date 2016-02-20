//Cracked by Roath
// donglang1.c 东厢走廊
// xQin 11/00

inherit ROOM;

void create()
{
        set("short", "东厢走廊");
        set("long", @LONG
你走在一条幽静的走廊上，东边可通往茶室和武当弟子的休息室。往北
便是武当弟子的练功房。
LONG );
        set("exits", ([
                "east" : __DIR__"donglang2",
                "west" : __DIR__"hd_zoulang",
                "north": __DIR__"liangongfang",
        ]));
 
        setup();
        replace_program(ROOM);
}

