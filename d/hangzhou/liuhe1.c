//Cracked by Roath
// 六和塔
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "六和塔");
    set("long", @LONG
爬上月轮山，便来到了六和塔之前。六和塔亦名六合塔，“六和”
之名来之佛家的六种规约，“六合”就是“天，地，四方”的意思。
这座八角塔有十三层，在它的飞檐翘角上括有一百零四只大铁铃。
LONG	);

    set("exits", ([ /* sizeof() == 1 */ 
                   "eastdown" : __DIR__"road78", 
                 ])
       );
	set("cost", 3);
    setup();
    replace_program(ROOM);
}