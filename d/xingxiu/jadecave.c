//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;
string look_stone();

void create()
{
	set("short", "白玉峰山壁");
	set("long", @LONG
这是白玉峰壁上的山洞，向内下去到地有十七八丈高，峰内
地面远比外面的为低。洞旁有许多凹凸不平的山岩(stone)。
LONG
	);

	set("exits", ([
		"down" : __DIR__"jaderoom1",
	]));

	set("item_desc", ([
	"stone" : (: look_stone :),
	]));
	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_tie", "tie");
}

int do_climb(string arg)
{
	object me, room;

	room = load_object("/d/xingxiu/jaderoom1");
	me = this_player();
	
	if( !query("tied_stone") )  return 0;

	if( !arg || arg=="" ) return 0;

	if( arg == "up")
		return notify_fail("绳子往下垂，你却想往上爬，能这麽想也算是个天才。\n");
	if( arg == "down" )
	{

		if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你正忙着呢。\n");

		if(me->query("rided"))
		return notify_fail("你骑着马，不能这麽干！\n");

		message_vision("$N沿着绳子溜了下去。\n", me);
		tell_object(room, me->name()+"沿着绳子溜了下来。\n" );
		me->move(room);

		me->start_busy(1);
		return 1;

	}
	else return notify_fail("你要往哪里爬？\n");
}	

int valid_leave(object me, string dir)
{
	object room;
	room = find_object("/d/xingxiu/jaderoom1");
	
	if(dir == "down") return notify_fail("这里离地太高，直接跳下去跟找死没两样，找条绳子什麽的攀下去吧。\n");
	return ::valid_leave(me, dir);
}

int do_tie(string arg)
{
	object me, ob;
	me = this_player();

	if ( !arg || arg == "" ) return 0;
	
	if ( !objectp(ob = present("sheng zi", me)) ) return 0;

	if ( arg == "stone" ) {
		message_vision("$N把绳子一端在山石上缚牢。\n", me);
		set("tied_stone", 1);
		destruct(ob);
		}
		return 1;
	return 0;
}

string look_stone()
{
	if( !this_object()->query("tied_stone") ) return "凹凸不平的山岩，上面光秃秃的什麽也没有。\n";
	else return "凹凸不平的山岩，上面绑了一条绳子，也许可以利用它爬下(climb)山壁。\n";
}
