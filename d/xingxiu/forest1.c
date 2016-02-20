//Cracked by Roath
// wsky, 5/7/00
inherit ROOM;

#include <ansi.h>
#include "/d/REGIONS.h";
#include "xx_job.h";

void setup_npc(object me, object ob);

void create()
{
        set("short", "星宿密林");
        set("long", @LONG
这里是星宿海旁边的森林，高大的松树几乎把所有的光线都遮掩住了。
地上到处都是残枝败叶，每踏出一步都会发出吱吱的声响，远处不时传
来一阵阵枭鸣，使人毛骨悚然。
LONG);

        set("exits", ([ 	
             "north" : __DIR__"forest2",
	     "northwest" : __DIR__"forest3",
             "northeast" : __DIR__"forest4",   
	     "south" : __DIR__"xxh5",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        

}


