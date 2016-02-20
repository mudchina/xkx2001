//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;
string look_long();

void create()
{
	set("short", "通道");
	set("long", (: look_long :));

	set("exits", ([
		"north" : __DIR__"jaderoad5",
	]));
	set("item_desc", ([
	"door" : "石门上刀劈斧砍之痕累累，尽是四下骸骨生前拚命挣扎的遗迹。\n",
	]));
	set("cost", 1);
	setup();
}

string look_long()
{
	string desc;
	desc = 
	"一条仅可容身的狭长通道，刀剑四散，到处都是骸骨。\n";
	if(!query("exits/out"))
	desc += "尽处一道玉石巨门(door)上刀痕累累，斑驳凹凸。\n";
	else desc +="尽处有一道开着的玉石巨门。\n";
	return desc;
}


void init()
{
	add_action("do_push", "push");
	add_action("do_pull", "pull");
}

int do_push(string arg)
{
	object me, room;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "door") {
		if(query("exits/out")) {
			message_vision("$N双手撑门，用力推动玉石巨门。只听得叽叽之声，接着蓬的一声大响，石门关上了。\n", me );
			delete("exits/out");
			if( room = find_object(__DIR__"jaderoad3") ) {
			room->delete("exits/enter");
			message("vision", "只听得叽叽之声，接着蓬的一声大响，石门已从里面给人关上。\n", room );
			return 1;
			}
		}
		else {
			message_vision("$N双手撑门，用力向外推去，但是玉石巨门纹丝不动，反而双手骨头撑得甚痛。\n", me);
			me->receive_wound("qi", 200 +random(10), "被困在神峰中累死了");
			me->receive_damage("qi", 220 + random(10), "被困在神峰中累死了");
	return 1;
		}
	}
	else return 0;
}

int do_pull(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "door") {
	
		if(query("exits/out"))
			return notify_fail("玉石巨门已经是开着的了。\n");

	message_vision("$N想要把石门拉开，但是石门後全无着手之处。\n", me);
	return 1;
	}
	else return 0;
}
