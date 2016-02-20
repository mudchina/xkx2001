//Cracked by Roath
// 楼外楼
// Dong  11/03/1996.

//  NTA : Need to add npc here and food.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", HIR"楼外楼"NOR);
    set("long", @LONG
提起“楼外楼”方圆百里无人不知。这里各式名菜是杭州一绝。
来游湖的人们都一定会来这里尝尝。整个大堂闹哄哄的挤满了各式人
等。店小儿跑来跑去，忙着招呼客人。墙上挂着价格牌子(paizi)。
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                   "west" : __DIR__"road21", 
                 ])
       );
	set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
	]));
   set("item_desc", 
    	   ([
      	"paizi" : 
		"本店出售杭州名菜名点\n"
		"  东坡肉(pork)\n"
		"  西湖醋鱼(fish)\n"
		"  龙井虾仁(shrimp)\n"
		"  叫化童鸡(chicken)\n"
		"  桂花鲜栗羹(soup)\n"
		"  百果油包(baozi)\n"
   	   ])
	);

	set("cost", 0);
    setup();
    replace_program(ROOM);
}
