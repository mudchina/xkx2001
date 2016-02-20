//Cracked by Roath
// 飞来峰
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "翠微亭");
    set("long", @LONG
翠微亭建在飞来峰的半山间，是名将韩世忠为纪念岳飞而建的。
岳飞有“经年尘土满征衣，特特寻芳上翠微”的诗句，故亭名“翠微”。
西边是下山的路。
LONG);
    set("exits", ([ /* sizeof() == 1 */ 
        "westdown" : __DIR__"feilai4", 
                 ])
       );
	set("cost", 1);
    setup();
    replace_program(ROOM);
}