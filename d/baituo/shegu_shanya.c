//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "蛇谷山崖");
	set("long", @LONG
这是蛇谷高处的断崖，周遭既无树木，也无杂草，一派荒凉景象
，唯有风声猎猎，不断从耳边呼啸而过。居高临下，极目而望，可以
远眺(view)四面八方，看尽山峦形势。
LONG
	);

	set("exits", ([ 
	    "southdown" : __DIR__"shegu19",
	]));

	set("objects", ([
	    "/d/xueshan/npc/tuying" : 2,
	]));

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	add_action("do_view","view");
	add_action("do_view","tiaowang");
}

int do_view(string arg)
{
	object me = this_player(), room;
	string msg;

	if( !arg || arg=="" ) 
		return notify_fail( "你要往哪个方向眺望？可以从平面八个方位中选择。\n");

	switch (arg) {
	case "north" :
	case "n" :
	msg = "你往北方远眺，尽是一片崇山峻岭。\n";
		break;

	case "south" :
	case "s" :
	msg = "你往南方远眺，蛇谷地势尽在眼前，可以遥遥望见谷口。\n";

	room = load_object("/d/baituo/shegu1");
	if( room->query("defense") ) 
	msg += RED"谷口弥漫着血红色的毒雾，与外隔绝。\n"NOR;
	else msg += HIW"原本红雾密布的谷口，这时却豁然开朗，所有的雾气都无影无踪了。\n"NOR;
		break;

	case "east" :
	case "e" :
	msg = "你往东方远眺，在越过一片胡杨林後，便是黄沙莽莽的大漠。\n";
		break;

	case "west" :
	case "w" :
	msg = "你往西方远眺，所见尽是蛇谷林木。\n";
		break;

	case "northeast" :
	case "ne" :
	msg = "你往东北远眺，尽是一片崇山峻岭。\n";
		break;

	case "northwest" :
	case "nw" :
	msg = "你往西北远眺，望见远方山沟间云杉茂密，白杨参天，一座大瀑布奔腾而下，景象壮观。\n";

	room = load_object("/d/baituo/shegu27");
	if( present("ling zhi", room) ) 
	msg += HIW"一眼望去，你觉得彼端山中，似有股难以描述的灵气。\n"NOR;
	else if( present("pusiqu she", room) ) 
	msg += HIR"你遥望山中景色，忽然觉得有些心惊肉跳，再定神望去，越看越觉得不对劲。\n"NOR;
	else msg += "你悠闲地观赏着山景，觉得心情轻松了不少。\n";
		break;

	case "southeast" :
	case "se" :
	msg = "你往东南远眺，在越过一片胡杨林後，便是黄沙莽莽的大漠。\n";
		break;

	case "southwest" :
	case "sw" :
	write("你往西南远眺，正可望见蛇谷密林深处的魔鬼滩地带……\n\n");
	room = load_object("/d/baituo/shegu32");
	COMMAND_DIR"std/look"->look_room(me, room);
	msg = "……距离虽远，但是居高临下，倒还看得清楚。\n";
		break;

	default:
		return notify_fail( "你要往哪个方向眺望？可以从平面八个方位中选择。\n");
	}
	write(msg);
	return 1;
}
