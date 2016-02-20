//Cracked by Roath
// poison_dust.c

inherit COMBINED_ITEM;

void create()
{

	set_name("蒙汗药", ({ "menghan yao", "yao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这是极普通的蒙汗药\n" );
		set("unit", "些");
		set("base_value", 1000);
		set("base_unit", "包");
		set("base_weight", 30);
		set("medicine", 1);
	}
	set_amount(1);
}

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("命令格式: pour <药> in <物品>。\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上没有" + what + "这样东西。\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "里什么也没有，先装些酒水才能溶化药粉\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->add("liquid/slumber_effect", 100);
	message_vision("$N将一些" + name() + "倒进" + ob->name() 
		+ "摇晃了几下。\n", this_player());
	add_amount(-1);
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("slumber_drug",
		(int)this_player()->query_condition("slumber_drug") 
		+ (int)ob->query("liquid/slumber_effect") );
	return 0;
}
