//Cracked by Roath
// /d/emei/tomb2.c
// xbc 97/02/05

#include <ansi.h>
inherit ROOM;

// int do_open(string);

void create()
{
	set("short", "墓室");
	set("long", @LONG
这里是郭襄墓下的墓室。墓室不大，正面是一具白玉石棺，旁边放着一盏长明
灯。石棺一尘不染，看来经常有人进来打扫。
LONG
	);

	set("objects",  ([__DIR__"obj/coffin1" : 1,]) );
	set("item_desc", ([
		"coffin" : "这是一具白玉石雕成的石棺。\n",
	]));

	set("invalid_startroom", 1);

	set("arrow_count", 3);
//	set("rwj_count", 1);

	set("cost", 0);
	setup();
}

void init()
{
//	add_action("do_open", "open");
	add_action("do_move", "move");
}

int shoot_arrow(object me)
{
	if ((int)query("arrow_count") < 1 ) return 0;

	switch ((int)query("arrow_count")) {
	case 3:
		message_vision(HIY"忽然间几支短箭从棺后一个机关里射出来，直射向$N的面门！\n"NOR, me);
		break;
	case 2:
		message_vision(HIY"忽然间几支短箭从棺后一个机关里射出来，直射向$N的咽喉！\n"NOR, me);
		break;
	case 1:
		message_vision(HIY"忽然间几支短箭从棺后一个机关里射出来，直射向$N的前胸！\n"NOR, me);
		break;
	default:
		message_vision(HIY"忽然间几支短箭从棺后一个机关里射出来，直射向$N的面门！\n"NOR, me);
		break;
	}
	add("arrow_count", -1);

	if ( (int)me->query_dex() > (22+random(8))) {
		message_vision("$N头一低，避开短箭，跳到一旁。\n", me);
		return 1;
	}

	else if ( (int)me->query_dex() > (20+random(4))) {
		message_vision("$N欲闪身避开，却被其中一支短箭射中右肩，晕死过去。\n", me);
		me->add("qi", -50);
		me->unconcious();
		return 1;
	}

	else {
		message_vision("$N躲避不及，被短箭射个正好，倒在地上。\n", me);
		me->receive_damage("qi", 50, "被毒箭射死了");
		me->die();
		return 1;
	}
	return 0;
}
*/

int do_move(string arg)
{
        object me;
	object room = load_object(__DIR__"secret_path1");

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg =="coffin" || arg =="guan" ) {
		if ( !query_temp("secret_trigger") ) {
			set_temp("secret_trigger", 1);
                	message_vision("$N用力去移石棺，不知碰到了什么机关，墓室一角忽然开了一道小门。\n", me); 
			set("exits/down", __DIR__"secret_path1");
                       	room->set("exits/up", __FILE__);
                       	message("vision", "头顶上的暗门忽然被人打开，墓室中传来微弱的灯光。\n",room );
			remove_call_out("close_door");
			call_out("close_door", 30, me);
                	return 1;
        	}
       		else
        		return notify_fail("你用力去移石棺，累得满头大汗。\n");
	}
	return 0;
}

void close_door()
{
	object room = load_object(__DIR__"secret_path1");

	if( !query("secret_trigger") ) return;

	message("vision", "过了一会儿，暗门轻轻地关上了，一切又恢复到从前的样子。\n", this_object() );
	delete("exits/down");
	room->delete("exits/up");
	tell_room(room, "过了一会儿，暗门轻轻地关上了。\n");
	delete("secret_trigger");
}



