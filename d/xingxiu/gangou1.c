//Cracked by Roath
//by haowen 
//09/10/98
inherit ROOM;

void create()
{
	set("short", "干沟");
	set("long", @LONG
这是托克逊与库米什之间的一个峡谷。干沟就是干枯的河
床，除难得在大雨之後出现山洪，霎时涌来，霎时消失而外，
平时涓滴皆无。沟里俱是板结的土块，虽可以行走但却不大
容易辨清方位，即已过来就顺着眼前的依稀可辨的土路向前
走吧。
LONG
	);

	set("cost", 4);
	set("outdoors", "tianshan");

	setup();
//	replace_program(ROOM);
}
void init()
{
	object room = this_object();
	object me = this_player();
	string last,next;
	room->delete("exits/north");
	room->delete("exits/south");
	room->delete("exits/east");
	room->delete("exits/west");
	last=me->query_temp("last_place");
	if (last=="yinshan")
		next="gangou2";
	else next="yinshan";
	switch(random(3)) {
	case(0):
		if (me->query_temp("last_exit") != "west" )
 			set("exits/east",__DIR__+next);
		else 	
			set("exits/west",__DIR__+next);
		break;
	case(1):
		if (me->query_temp("last_exit") != "east" )
 			set("exits/west",__DIR__+next);
		else 
			set("exits/east",__DIR__+next);
		break;
	case(2):
		if (me->query_temp("last_exit") != "north" )
 			set("exits/south",__DIR__+next);
		else 	
			set("exits/north",__DIR__+next);
		break;
	case(3):
		if (me->query_temp("last_exit") != "south" )
 			set("exits/north",__DIR__+next);
		else 	
			set("exits/south",__DIR__+next);
		break;
		}
	if (me->query_temp("last_exit") == "east")
		set("exits/west",__DIR__+me->query_temp("last_place"));
	if (me->query_temp("last_exit") == "west")
		set("exits/east",__DIR__+me->query_temp("last_place"));
	if (me->query_temp("last_exit") == "north")
		set("exits/south",__DIR__+me->query_temp("last_place"));
	if (me->query_temp("last_exit") == "south")
		set("exits/north",__DIR__+me->query_temp("last_place"));

}
int valid_leave(object me,string dir)
{
	if (dir == "east" )
		{
		me->set_temp("last_exit","east");
		write("你踩着干枯的河底，快布向前走去。\n");
		}
	if (dir == "west" )
		{
		write("你踩着干枯的河底，快布向前走去。\n");
		me->set_temp("last_exit","west");
		}
	if (dir == "south" )
		{
		write("你踩着干枯的河底，快布向前走去。\n");
		me->set_temp("last_exit","south");
		}
	if (dir == "north" )
		{
		write("你踩着干枯的河底，快布向前走去。\n");	
		me->set_temp("last_exit","north");
		}
	return ::valid_leave(me,dir);
}
	