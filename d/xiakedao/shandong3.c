//Cracked by Roath
// /xiakedao/Dong4.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个不大的山洞，四周的墙上插着火把。一伙年青人正围着
一位老人。这位老人是侠客岛的大管家(guanjia)，人称'兵器通'。
LONG );

	set("exits", ([
		"south" : __DIR__"",
	]));

	set("item_desc",([
	    "guanjia" :	"木桩的下半身牢牢的埋在地下，上半身装了两根木枝。\n"
			"你可以试着用拳去打其中一根木桩学点基本。(hit zhuang) \n",

	]));
	
        setup();
}

void init()
{
        ::init();

	add_action("do_xue", "xue");
}

int do_xue(string arg)
{
 	object me = this_player();
	int check;

	if ( !arg )
		return notify_fail( "你想学什麽?\n");
	if ( arg != "zhuang" )
		return notify_fail( "老老实实 study zhuang 吧。\n");

	if (!(int)me->query_temp("mark/学1"))
	{	write("每次学习你的精就会少二十点，如果你的精太低精神就无法集中。\n");
		write("如果你的实战经验太低，(基本拳法^3 > 经验*10)，你就无发再学了。\n");
		me->set_temp("mark/学1", 1);
	}

	check = (int)me->query_skill("cuff",1)*(int)me->query_skill("cuff",1)*(int)me->query_skill("cuff",1);
	if (check < (int)me->query("combat_exp") * 10)
	{	write("你现在的实战经验不足，无法领悟基本拳法。\n");
	}
	else if ((int) me->query("jing") < 30)
	{	write("你精神无法集中。\n");
	}	
	else
	{	me->receive_damage("jing", 20, "心力交瘁死了");
	      me->improve_skill("cuff", (int)me->query_skill("literate")/5 + 1);
      	write("你领悟基本拳法方面的几个疑难。\n");
	}
	return 1;
}
