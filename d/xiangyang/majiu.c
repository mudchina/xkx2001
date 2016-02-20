//Cracked by Roath
// Room: /d/xiangyang/majiu.c 马厩
//xQin 2/00

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", YEL"马厩"NOR);
        set("long",@LONG
这里是襄阳城内唯一一家车马行。你可花钱租辆马车到各个地方去，能节约不少体
力。近来因为郭夫人----黄蓉正在组织人力四处搜集防城材料，马夫积极响应，免费提供
推车来运送各种防城材料。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
LONG);
        set("no_clean_up", 0);
        set("coordinates", ([ "x" : 4, "y" : 1 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian",
  "southwest" : __DIR__"dongjie2",
]));
        set("item_desc", ([
                "paizi": @TEXT
良种好马有售。

TEXT]));

        set("objects", ([
                "/clone/obj/car" : 2,
                "/d/shaolin/npc/ma-fu" : 1,
                "/clone/horse/xiaoma" : 2,
                "/clone/horse/huangma" : 1,
                "/clone/horse/qingma" : 1,
                "/d/shaolin/obj/caoliao" : 2,
        ]));


        set("outdoors", "xiangyang");
        set("resource/water",1);

	setup();
        replace_program(ROOM);
}
