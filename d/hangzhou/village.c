//Cracked by Roath
// /d/hangzhou/village.c   牛家村
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{        set("short", "牛家村");
         set("long", @LONG
钱塘江浩浩江水，日日夜夜无穷无休的从临安牛家村边绕过，东流入海。
江畔一排数十株乌柏树，叶子似火烧般红。村前村后的野草刚起始变黄，更增
了几分萧索。两株大松树下围着一堆村民，男男女女和十几个小孩，正自聚精
会神的听着一个瘦削的老者说话。村东头挑出一个破酒帘，似是酒店模样。
LONG	);

         set("exits", ([ /* sizeof() == 2 */
                   "northeast" : __DIR__"haidi",
                   "east" : __DIR__"jiudian",
                   "west" : __DIR__"road78",  
                 ])
         );

	 set("objects", ([
                __DIR__"npc/yang" : 1,
                __DIR__"npc/guo" : 1,
         ]));

	 set("cost", 1);
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}
