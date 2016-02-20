//Cracked by Roath
// 花港观鱼
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   
   	set("short", RED"花港观鱼"NOR);
   	set("long", @LONG
只见湖中有一小岛，一座曲桥横跨湖面。曲桥上人群熙攘，倚栏
投饵。桥下红鱼，争食欢跳。谢觉哉游园时曾作诗一首“鱼国群粼乐
有余，观鱼才觉我非鱼。虞诈两忘欣共处，鱼犹如此况人乎。”
LONG        );

   	set("exits", ([ /* sizeof() == 1 */ 
                  "east" : __DIR__"suti6", 
                ])
       	);
	set("cost", 2);
        set("outdoors", "hangzhou");
   	setup();
//   replace_program(ROOM);
}

void init()
{
        add_action("do_dig", "dig");
}

int do_dig(string arg)
{
	object ni = new("d/gaibang/obj/mud");
	object me = this_player();

	if ( !arg || arg == "" ) 
		return 0;

	if ( arg != "泥" || arg != "mud" ) {
		message_vision("$N从湖底挖了一些湿泥上来。\n", me);
		ni->move(me);
		return 1;
	}	

	tell_object( me, "你要挖什么？\n" );
        return 1;
}

