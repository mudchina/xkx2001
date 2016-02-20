//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "出云洞");
        set("long", 
"龙泉观往上便是出云洞，洞内清寒幽深，深不可测，每逢
凌晨，黄昏时分，和阴雨天气，洞口雾气吞吐，白云出入，便
是远近闻名的“白云灵穴”。\n"
        );
        set("exits", ([
                "westdown"  : __DIR__"longquanguan",
                "northup"  : __DIR__"hufengkou",
]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

