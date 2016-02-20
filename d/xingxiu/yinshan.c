//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "银山道");
	set("long", @LONG
这是托克逊与库米什之间的一个峡谷，又叫做干沟。干沟之名并
非虚传，除难得在大雨之後出现山洪，霎时涌来，霎时消失而外，平
时涓滴皆无。沟里气温更是酷热难熬，但是却连一棵可乘凉的小树也
没有。除非轻骑劲旅，趁早晚天凉，尽快通过，一般行旅通常是走别
的通道。
LONG
	);
	set("exits", ([
            "eastdown" : __DIR__"shankou",
//            "north" : __DIR__"tianroad2",
//            "westup" : __DIR__"tianroad3",
]));
	set("cost", 4);
	set("outdoors", "tianshan");

	setup();
//	replace_program(ROOM);
}
void init()
{	object room = this_object();
	object me = this_player();
	room->delete("exits/north");
	room->delete("exits/south");
	room->delete("exits/east");
	room->delete("exits/west");
	if (me->query_temp("last_exit") == "east")
			{
			set("exits/west",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}	
	else if (me->query_temp("last_exit") == "west")
			{
			set("exits/east",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}
			
	else if (me->query_temp("last_exit") == "north")
			{
			set("exits/south",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}
	else if (me->query_temp("last_exit") == "south")
			{
			set("exits/north",__DIR__"gangou1");
			me->delete_temp("last_exit");
			me->delete_temp("last_place");
			}	
	else
	{switch(random(3)) {
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
		me->set_temp("last_place","yinshan");
		write("你踩了踩干枯的河底，觉的很是平坦，放心的走了进去。\n");
		}
	if (dir == "west" )
		{
		me->set_temp("last_exit","west");
		me->set_temp("last_place","yinshan");
		write("你踩了踩干枯的河底，觉的很是平坦，放心的走了进去。\n");
		}
	if (dir == "south" )
		{
		me->set_temp("last_exit","south");
		me->set_temp("last_place","yinshan");
		write("你踩了踩干枯的河底，觉的很是平坦，放心的走了进去。\n");
		}
	if (dir == "north" )
		{
		me->set_temp("last_exit","north");
		me->set_temp("last_place","yinshan");
		write("你踩了踩干枯的河底，觉的很是平坦，放心的走了进去。\n");
		}
			
	return ::valid_leave(me,dir);
}
	