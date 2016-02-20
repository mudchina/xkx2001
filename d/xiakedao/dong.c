//Cracked by Roath
// /xiakedao/Dong1.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

int do_study(string arg);

void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个不大的山洞，四周的墙上插着火把。靠里的墙壁(wall)上似
乎刻了些什麽。几个青年人正站在那凝神观看(look)。
LONG );

	set("exits", ([
		"south" : __DIR__"",
	]));

	set("item_desc",([
	    "wall" : "墙上刻了十几幅画，每一幅画都绘着不同人形飞跃的姿势。
你可以试着从画上学点基本轻功。(study wall) \n",

	]));
	

}
void init()
{
        ::init();

	add_action("do_study", "study");
}
int do_study(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "你想学什麽?\n");
	if ( arg != "wall" )
		return notify_fail( "老老实实 study wall 吧。\n");

	if (!(int)me->query_temp("mark/学1"))
	{	write("每次学习你的精就会少二十点，如果你的精太低精神就无法集中。\n");
		write("如果你的实战经验太低，(基本轻功^3 > 经验*10)，你就无法再学了。\n");
		me->set_temp("mark/学1", 1);
	}

	check = (int)me->query_skill("dodge",1)*(int)me->query_skill("dodge",1)*(int)me->query_skill("dodge",1);
	if (check < (int)me->query("combat_exp") * 10)
	{	write("你现在的实战经验不足，无法领悟基本轻功。\n");
	}
	else if ((int) me->query("jing") < 30)
	{	write("你精神无法集中。\n");
	}	
	else
	{	me->receive_damage("jing", 20, "心力交瘁死了");
	      me->improve_skill("dodge", (int)me->query_skill("literate")/5 + 1);
      	write("你领悟基本轻功方面的几个疑难。\n");
	}
	return 1;
}
