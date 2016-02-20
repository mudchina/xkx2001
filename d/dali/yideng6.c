//Cracked by Roath
// yideng6.c
// acep , mantian , mantian

inherit ROOM;

int do_exert(string);
int do_pian(string);

void create()
{
	set("short", "巨石下");
	set("long", @LONG
你呆呆地使出全力顶起巨石，生怕一松手砸死了自己，农夫冷冷地站在一旁
袖手旁观，一点相助的意思也没有。     
LONG);
	set("cost", 2);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("outdoor","dali");
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
    setup();
}

void init()
{
	object me;
	int i,j,k;
	i=5; k=0;
	me=this_player();
	while (i<85 && k<=me->query("jingli"))
	{
		j=10+random(40);
		k=k+j;
		call_out("dropjingli", i, me, j);
		i=i+5;
	}
	remove_call_out("moveout");
	call_out("moveout", 90, me);
	add_action("do_exert", "exert");
	add_action("do_exert", "yun");
	add_action("do_pian", "pian");
}
void dropjingli(object me, int losejl)
{
	if (environment(me)==find_object("/d/dali/yideng6.c"))
	{
		message_vision("$N托得久了，只觉得两臂发麻，眼前一阵金星乱冒！\n",me);
		me->receive_damage("jingli", losejl,"精力透支过度而死了");
		return;
	}
}

void moveout(object me)
{
	if (environment(me)==find_object("/d/dali/yideng6.c"))
	{
		message_vision("$N眼前一阵发黑，终于坚持不住了，手一松，“轰隆”！ ... ...\n",me);
		me->unconcious();
		me->move("/d/dali/droad2.c");
		return;
	}
}

int do_exert(string arg)
{
	tell_object(this_player(), "你正托着大石头呢，怎么运气？！\n");
	return 1;
}

int do_pian(string arg)
{
	object me;
	me=this_player();
	if (arg=="nong" || arg=="wu santong" || arg=="farmer" || arg=="wu")
	{
		message_vision("$N情急生智，大喊道：“大叔，我怀里有一封洪老爷子给段皇爷的信！”\n",me);
		message_vision("“你来暂托一下，待我取出给你。”\n",me);
		message_vision("等到农夫托起大石，$N身形一纵，从他身边掠过，冲向后山！\n\n",me);
		me->move("/d/dali/yideng7.c");
		return 1;
	}
	return 1;
}
