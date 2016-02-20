//Cracked by Roath
//化尸粉

inherit COMBINED_ITEM;

void create()
{

	set_name("化尸粉", ({ "huashi fen", "fen" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这是一包江湖中人闻而色变的化尸粉，发出荧荧的黄光。\n" );
		set("unit", "包");
		set("base_value", 1000);
		set("base_unit", "份");
		set("base_weight", 30);
		set("medicine", 1);
	}
	set_amount(1);
}

void init()
{
	add_action("do_pour", "pour");
	add_action("do_pour", "dao");
        add_action("do_cast", "cast");
        add_action("do_cast", "tu");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("命令格式: pour/dao <药> in <物品>\n");

	ob = present(what, environment(this_player()));
	if( !ob || ob->query("id") != "corpse")
		return notify_fail("你只能把化尸粉倒在你周围地上的尸体上。\n");
	message_vision("$N把一份化尸粉撒在$n上，片刻之间，$n化作一滩黄水，消失得无影无踪了。\n",
		this_player(), ob);
	destruct(ob);
	this_player()->add("potential",1);
	add_amount(-1);
	return 1;
}

int do_cast(string arg)
{
        string me, what;
        object ob;
        function f;

        if( !arg
        ||      sscanf(arg, "%s on %s", me, what)!=2
        ||      !id(me) )
                return notify_fail("命令格式: cast/tu <药> on <物品>\n");

        ob = present(what, this_player());
        if( !ob)
		return notify_fail("你身上没有这个东西。\n");
        if( ob->query("id") != "cloth piece")
                return notify_fail("化尸粉只能涂在布条上。\n");
	message_vision("$N将一些" + name() + "涂在" + ob->name()
		+ "上。\n", this_player());
	add_amount(-1);
	ob -> set("hsf",this_player()->query_skill("poison",1)
			+this_player()->query_skill("hamagong",1));
	ob ->set("long","这根布条有些异样，似乎特别的黄，且泛着荧光。\n");
	return 1;
}
