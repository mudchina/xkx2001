//Cracked by Roath
// /xiakedao/Dong3.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个不大的山洞，四周的墙上插着火把。靠里的墙边放着一张石桌。
桌上放着一本线装书(book)。
LONG );

	set("exits", ([
		"south" : __DIR__"",
	]));

	set("item_desc",([
	    "book" : 	"这是一本看上去很旧的书，封面上写着五个大字：易筋经残篇。\n"
			"你可以试着读书(du book)去学点基本内功。 \n",
	]));

	setup();
}

void init()
{
        ::init();

	add_action("do_du", "du");
}

int do_du(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "你想学什麽?\n");
	if ( arg != "book" )
		return notify_fail( "老老实实 du book 吧。\n");

	if (!(int)me->query_temp("mark/学1"))
	{	write("每次学习你的精就会少二十点，如果你的精太低精神就无法集中。\n");
		write("如果你的实战经验太低，(基本内功^3 > 经验*10)，你就无发再学了。\n");
		me->set_temp("mark/学1", 1);
	}

	check = (int)me->query_skill("force",1)*(int)me->query_skill("force",1)*(int)me->query_skill("force",1);
	if (check < (int)me->query("combat_exp") * 10)
	{	write("你现在的实战经验不足，无法领悟基本内功。\n");
	}
	else if ((int) me->query("jing") < 30)
	{	write("你精神无法集中。\n");
	}	
	else
	{	me->receive_damage("jing", 20, "心力交瘁死了");
	      me->improve_skill("force", (int)me->query_skill("literate")/5 + 1);
      	write("你领悟基本内功方面的几个疑难。\n");
	}
	return 1;
}
