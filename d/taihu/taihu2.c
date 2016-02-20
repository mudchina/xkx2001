//Cracked by Roath
//maco

inherit ROOM;

void check_trigger();
void on_board(object room);
//void arrive(object room);
//void close_passage(object room);


void create()
{
	set("short", "湖滨");
	set("long", @LONG
这里是太湖湖滨，极目望去，但见烟波浩渺，远水接天。附近
祗有寥寥几户人家，湖滨泊着一排渔船。
LONG
	);
	 set("exits", ([
		"west" : __DIR__"taihu",
	]));
	set("cost", 2);
	set("outdoors", "guiyun");
	
	set("water_name", "湖");
	set("boat", __DIR__"duchuan2");
	set("opposite", __DIR__"matou2");


	set("objects", ([
		"/d/city/obj/stone" : 1,
	]));

	setup();
}

void setup()
{
	object room;

	::setup();

	if( room = find_object(this_object()->query("boat")) )
	room->delete("yell_trigger");
}

#include "ferry.h"
