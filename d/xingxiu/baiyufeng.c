//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;
string look_cave();

void close_cave();

void create()
{
	set("short", HIW"白玉峰山壁"NOR);
	set("long", @LONG
这是白玉峰的山壁上一处凸岩，山壁上似乎有个洞口(cave)。
LONG
	);

	set("exits", ([ ]));
	set("item_desc", ([
	"cave" : (: look_cave :),
	]));

	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
}


void init()
{
	add_action("do_dig", "dig");
	add_action("do_jump", "jump");
}

int do_dig(string arg)
{
	object me, room;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "cave" && !query("exits/enter")) {

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你正忙着呢。\n");

	message_vision("$N左手紧抓峰壁上一块凸出的玉岩，右手拨去沙子，将洞旁碎块玉石一块块抽出来，抛向下面。\n不多一刻，抽空的洞口已可容身。\n", me);

	me->add("jingli", -50);

	set("exits/enter", __DIR__"jadecave");
		if( room = find_object(__DIR__"jadecave") ) {
			room->set("exits/out", __FILE__);
			message("vision", "一阵悉悉簌簌的声音传来，有人从外面把洞口挖开了。\n",room );
		}
	remove_call_out("close_cave");
	call_out("close_cave", 10);
	return 1;
	}
	else return 0;
}

void close_cave()
{
	object room;

	if( !query("exits/enter") ) return;
	message("vision", "祗听得轰隆、轰隆几声，洞口又崩塌了。\n", this_object() );
		delete("exits/enter");
	if( room = find_object(__DIR__"jadecave") ) {
		room->delete("exits/out");
		message("vision", "你觉得脚下微微震动，听得轰隆、轰隆几声，洞口又崩塌了。\n", room );
	}
}

int do_jump(string arg)
{
	object me, weapon;
	string msg, type;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="down" )
	{
		if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你正忙着呢。\n");

		if(me->query("rided"))
		return notify_fail("你骑着马，不能这麽干！\n");

		message_vision("$N纵身往白玉峰山脚跳了下去。\n", me);
		me->move("/d/xingxiu/gucheng5");
		message("vision", me->name() + "从山上跳了下来。\n", environment(me), ({me}) );

		if( me->query_skill("dodge") < 200 ) {
		message_vision("祗听“砰”地一声，$N摔了个七荤八素。\n", me);
		me->receive_damage("qi", 50+random(20), "跳下白玉峰摔死了");
		}

		me->start_busy(1);
		return 1;

	}
	else return 0;
}	

string look_cave()
{
	if( !query("exits/enter") ) return "山壁上洞口的痕迹很是明显，只是年深月久，洞口已被沙子堵塞，看来得先挖开(dig)这些砂石。\n";
	else return "山洞内黑沉沉的，甚么也瞧不见。\n";
}
