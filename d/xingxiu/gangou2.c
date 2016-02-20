//Cracked by Roath
// by haowen
// 09/10/98

inherit ROOM;

void create()
{
	set("short", "干沟");
	set("long", @LONG
这是托克逊与库米什之间的一个峡谷。干沟就是干枯的河
床，除难得在大雨之後出现山洪，霎时涌来，霎时消失而外，
平时涓滴皆无。现时沟底尽是板结的土块，正适合行人通过。
LONG
	);
	set("exits", ([
//            "eastdown" : __DIR__"shankou",
            "northup" : __DIR__"tianroad2",
            "westup" : __DIR__"tianroad3",
]));
	set("cost", 4);
	set("outdoors", "tianshan");

	setup();
//	replace_program(ROOM);
}
void init()
{
	object room = this_object();
	object me = this_player();
	room->delete("exits/north");
	room->delete("exits/south");
	room->delete("exits/east");
	room->delete("exits/west");
	
	if (me->query_temp("last_exit") == "east")
			{
			set("exits/west",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("lase_place");
			}	
	else if (me->query_temp("last_exit") == "west")
			{
			set("exits/east",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("lase_place");
			}	
	else if (me->query_temp("last_exit") == "north")
			{
			set("exits/south",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("lase_place");
			}
	else if (me->query_temp("last_exit") == "south")
			{
			set("exits/north",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("lase_place");
			}
	
	else{
	switch(random(3)) {
	case(0):
		set("exits/east",__DIR__"gangou1");
		break;
	case(1):
		set("exits/west",__DIR__"gangou1");
		break;
	case(2):
		set("exits/north",__DIR__"gangou1");
		break;
	case(3):
		set("exits/south",__DIR__"gangou1");
		break;
		}
	      }	
}
int valid_leave(object me,string dir)
{
	if (dir == "east" )
		{
		me->set_temp("last_exit","east");
		me->set_temp("last_place","gangou2");
		write("你踩了踩干枯的河底，觉的很是平坦，放心的走了进去。\n");
		}
	if (dir == "west" )
		{
		me->set_temp("last_exit","west");
		me->set_temp("last_place","gangou2");
		write("你踩了踩干枯的河底，觉的很是平坦，放心的走了进去。\n");
		}
	if (dir == "south" )
		{
		me->set_temp("last_exit","south");
		me->set_temp("last_place","gangou2");
		write("你踩了踩干枯的河底，觉的很是平坦，放心的走了进去。\n");
		}
	if (dir == "north" )
		{
		me->set_temp("last_exit","north");
		me->set_temp("last_place","gangou2");
		write("你踩了踩干枯的河底，觉的很是平坦，放心的走了进去。\n");
		}
	return ::valid_leave(me,dir);
}
	