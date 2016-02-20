//Cracked by Roath
// Room: /beijing/chaguan
// Ssy

inherit ROOM;

void create()
{
	set("short", "茶馆");
	set("long", @LONG
京城茶馆。
LONG
	);

	set("exits", ([
		"out" : __DIR__"tianqiao",
	]));

	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));

	set("cost", 0);
	set("day_shop", 1);
	setup();
}
void init()
{
	add_action("do_fill", "fill");
}
int do_fill(string arg)
{
	object ob, obj, me = this_player();

	if (!objectp(obj = present("qu san", environment(me))))
	{	write("掌柜的不在！\n");
		return 1;
	}

	if (!living(obj)){
		write("你还是等掌柜的醒过来再说吧。\n");
		return 1;
	}

	if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("你要把酒装在哪儿？\n");
		return 1;
	}

	switch (MONEY_D->player_pay(this_player(), 20)) {
        case 0: {
		write("穷光蛋，一边呆着去！\n");
		return 1;
		}
        case 2: {
                write("您的零钱不够了，银票又没人找得开。\n");
		return 1;
		}
	}

        if( ob->query("liquid/remaining") )
                message_vision("$N将" + ob->name() + "里剩下的" + ob->query("liquid/name") + 
		"倒掉。\n", this_player());
        message_vision("$N给曲三二十文铜板。\n曲三给$N的"+ob->name()+"装满烧酒。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "alcohol");
        ob->set("liquid/name", "烧酒");
        ob->set("liquid/remaining", query("max_liquid"));
        ob->set("liquid/drink_func", 0);
	ob->set("liquid/drunk_apply", 4);
	return 1;
}





