//Cracked by Roath
// zhutong.c

inherit ITEM;
inherit F_LIQUID;

int do_empty(string);

void create()
{
	set_name("竹筒", ({ "zhu tong", "tong" }) );
	set_weight(500);
	set_max_encumbrance(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "这是一支竹筒，是用一个竹节做成的，可以用来装水或食物。\n");
		set("value", 10);
		set("material", "bamboo");
		set("max_liquid", 10);
        set("liquid", ([
			"type": "water",
			"name": "清水",
			"remaining": 0,
			"drunk_supply": 0,
			]));
	}
	setup();
}

void init()
{
	::init();

	add_action("do_empty","dao");
}

int is_container() { return 1; }

int reject(object ob) 
{
	if (this_object()->query("liquid/remaining")) {
		notify_fail("竹筒里现在有水，不能往里放东西。\n");
		return 1;
	}
   	if (!ob) return 1;  // what does it mean by ob==null?

	/*
	 * it is supposed to hold food and water only, so we check if the 
	 * object has food_remaining.
	 *
	 * -Chu
	 */
	if (ob->query("food_remaining")<1) {
 	    notify_fail("竹筒里又湿又油腻，放这个恐怕不合适吧。\n");
	    return 1;
        }

	if (sizeof(all_inventory(this_object()))<5) return 0;
	notify_fail("这支竹筒已经装满了，再也放不下任何东西了。\n");
	return 1;
}

int do_empty(string arg)
{
	object ob, me=this_player();

	if (!arg || (arg!="tong" && arg!="zhu tong")) return 0;

	if (query("liquid/remaining")) {
		message_vision("$N把竹筒里装的"+query("liquid/name")+"倒掉。\n",me);
		set("liquid/remaining", 0);
	}
	else tell_object(me,"这支竹筒里并没有装需要倒掉的东西。\n");
	return 1;
}

int do_fill(string arg)
{
	if (!this_object()->id(arg)) return 0;
	if (this_player()->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if (!environment(this_player())->query("resource/water"))
		return notify_fail("这里没有地方可以装水。\n");

	if (sizeof(all_inventory(this_object()))>0)
		return notify_fail("你还是先把竹筒里面的东西取出来再装水吧。\n");

	if (query("liquid/remaining"))
		message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", this_player());
	message_vision("$N将" + name() + "装满清水。\n", this_player());

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	set("liquid/type", "water");
	set("liquid/name", "清水");
	set("liquid/remaining", this_object()->query("max_liquid"));
	set("liquid/drink_func", 0);

	return 1;
}
