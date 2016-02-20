//Cracked by Roath
// fengding.c 峰顶
// qfy Dec 4, 1996.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "峰顶");
	set("long", @LONG
峰顶西面有一处绝壁(cliff)。这绝壁一面较斜，尚可攀援；另一面
却如一大堵平墙，毫无可容手足之处。峰顶上有着几株古松(tree)。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
		"westdown" : __DIR__"canglong",
	]));

	set("item_desc", ([
		"tree" : "古松树干粗大，形态古拙，怕已不下几百年松龄。\n",
		"cliff": "绝壁下浮云飘飘，不能见底，不知有多深。\n",
	])  ) ;

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 4);
	setup();
//      replace_program(ROOM);
}
 
void init()
{
	object me = this_player();

   	if ( interactive(me) && me->query("huashan/job_pending") ) {
		me->set_temp("hz_job/fengding", 1);
   	}

	add_action("do_tie", "tie");
	add_action("do_tie", "bang");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object *inv, me = this_player();
	int i;

	if ( !arg || arg == "" ) return 0;

	if ( arg == "cliff" ) {
		inv = all_inventory(me);

		message_vision("$N纵身往绝壁跳下！\n", me);
		me->move(__DIR__"cliff");
		message("vision", me->name()+"由峰顶上直坠下来!\n", environment(me), ({me}) );
		me->receive_wound("qi", me->query("max_qi")+100, "跳下绝壁摔得粉身碎骨了");
		call_out("destroy_corpse", 1);

		for (i=0; i<sizeof(inv); i++) {
			if (inv[i]->is_character()) inv[i]->receive_wound("qi", inv[i]->query("max_qi")+100, "摔下绝壁跌得粉身碎骨了");
		}

		return 1;
	}

	return 0;
}

int do_tie(string arg)
{
	object me = this_player();

	if ( !arg || arg == "" ) return 0;

	if ( arg == "tree" ) {
		if ( !present("sheng zi", me) )
			write("你拿什么来绑树啊？\n");
		else {
			message_vision("$N将绳子仔细地在松树上捆绑好。\n", me);
			me->set_temp("tied", 1);
		}

		return 1;
	}

	return 0;
}

int do_climb(string arg)
{
	object me = this_player();

	if ( arg && arg != "down" )
		return notify_fail("什么？\n");

	if(me->query_encumbrance() * 10 / me->query_max_encumbrance() > 10/100)
		return notify_fail("你负重太多，身子腾挪不开。\n");

	if ( !me->query_temp("tied") )
		return notify_fail("没东西支撑你怎么爬呀？\n");

	message_vision("$N拉着绳子开始往下爬。\n", me);
	message("vision", me->name()+"一会儿便消失在云气里了。\n", environment(me), ({me}) );
	tell_object(me, "你向下一望，只见脚下雾气一团团的随风飘过却看不见地，不由得心惊胆跳！\n");

	if ( !me->query("jinshe") && me->query("str") <= 15 
	&& me->query("con") >= 25 && me->query_skill("dodge") > 50 ) {
		me->move(__DIR__"cliff");
		message("vision", me->name()+"由峰顶爬了下来。\n", environment(me), ({me}) );
	}
	else if ( me->query("jinshe") ) {
		me->move(__DIR__"cliff");
		message("vision", me->name()+"由峰顶爬了下来。\n", environment(me), ({me}) );
	}
	else {
		tell_object(me, HIR"突然间绳子“啪”地一声断了，你发出一连串凄历的惨嚎，身不由主地往绝壁下坠落！\n"NOR);
		me->delete_temp("tied");
		me->move(__DIR__"cliff");
		message("vision", me->name()+"由峰顶上直坠下来!\n", environment(me), ({me}) );
		me->receive_wound("qi", me->query("max_qi")+100, "跌下绝壁摔死了");
		call_out("destroy_corpse", 1);
	}

	return 1;
}

int destroy_corpse()
{
	object obj, room;

	if ( !( room = find_object(__DIR__"cliff") ) )
		room = load_object(__DIR__"cliff");

	if ( obj = present("corpse", room) ) destruct(obj);

	return 1;
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("tied") && dir == "westdown" )
		me->delete_temp("tied");

	if ( me->query_temp("exit") && dir == "westdown" )
		me->delete_temp("exit");

	return ::valid_leave(me, dir);
}
