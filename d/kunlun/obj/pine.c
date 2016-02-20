//Cracked by Roath
// pine.c 松树

inherit ITEM;

int shaking();
int collapse(object);
int do_chop(string);

void create()
{
        set_name("松树", ({ "pine", "song shu", "tree" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一棵密林里常见的松树。\n");
                set("unit", "棵");
		set("no_get", 1);
		set("tree_str", 100);

        }

}

void init()
{
	add_action("do_chop","chop");
}

int do_chop(string arg)
{
	object me=this_player();
	object weapon;
	int str;

	if (!arg) return 0;

	if (me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");
	
	if (arg != "tree" && arg != "pine")
		return notify_fail("你要砍什么？\n");
	
	if (!objectp(weapon = me->query_temp("weapon")) || 
		(string)weapon->query("id") != "axe")
		return notify_fail("你需要一把大斧子。\n");

	if (me->query("neili") < 30)
		return notify_fail("你的力气不够了。\n");

	message_vision("$N挥动大斧，狠狠地朝松树干砍了下去。\n",me);
	me->add("neili",-30);
	me->add("jingli",-50);
	me->start_busy(3);
	str = me->query_str();
	add("tree_str",-random(str)/2);
	if (query("tree_str") <=0)
	{
		remove_call_out("collape");
		call_out("collapse",1,me);
	}
	else if (query("tree_str") <= 50)
	{
		remove_call_out("shaking");
		call_out("shaking",1);
	}
	return 1;
}

int shaking()
{
	message_vision("松树已经摇晃的很厉害了。\n",this_object());
	return 1;
}

int collapse(object me)
{
	object ob=this_object();
	object shugan;
	message_vision("只听喀嚓一声，松树从根处折断，紧接着轰隆一声巨响，倒了下来。\n",ob);
	shugan=new(__DIR__"shugan");
	shugan->move(environment(ob));
	shugan->set("owner",me->query("id"));
	destruct(ob);
	return 1;
}