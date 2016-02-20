//Cracked by Roath
//by haowen 
//09/10/98
inherit ROOM;

void create()
{
	set("short", "田地");
	set("long", @LONG
这是一块田地。四周的田地整齐的排成一个个井字，在
这里放眼望去，满眼尽是绿地，中间几条笔直的小土垅交错
在一起，使人难辨东西。即已过来就顺着眼前的小土垅向前
走吧。
LONG
	);

	set("cost", 4);
	set("outdoors", "forest");

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
        if (last=="field")
		next="field1-2";
	else next="field";
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
		write("你踩着田间的小土垅，慢慢向前走去。\n");
		}
	if (dir == "west" )
		{
		write("你踩着田间的小土垅，慢慢向前走去。\n");
		me->set_temp("last_exit","west");
		}
	if (dir == "south" )
		{
		write("你踩着田间的小土垅，慢慢向前走去。\n");
		me->set_temp("last_exit","south");
		}
	if (dir == "north" )
		{
		write("你踩着田间的小土垅，慢慢向前走去。\n");	
		me->set_temp("last_exit","north");
		}
	return ::valid_leave(me,dir);
}
	
