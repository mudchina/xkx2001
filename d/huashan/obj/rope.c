//Cracked by Roath
// rope.c
// xbc added hanging on 11/2/98

inherit ITEM;

void init();
int do_hang(string);

void create()
{
		set_name("绳子", ({"sheng zi", "sheng", "rope" }));
		set_weight(200);
		if( clonep() )
				set_default_object(__FILE__);
		else {
		set("value", 30);
				set("unit", "捆");
				set("long", "一捆有几十丈长的绳索。\n");
				set("material", "cloth");
		}
	setup();
}

void init()
{
	add_action("do_hang", "hang");
	add_action("do_hang", "shangdiao");
}

int do_hang(string arg)
{
	object sheng = this_object(), me = this_player();

	if ( !arg || arg == "") return 0;

	if ( arg == "绳子" || arg == "rope" || arg == "sheng zi" || arg == "sheng") {
		tell_object(me, "你拿出一捆绳子来，挂在树枝上，打了一个结，把脖子套了上去。\n");
		message("vision", me->name()+"拿出一捆绳子来，挂在树枝上，打了一个结，把脖子套了上去。\n", 
			environment(me), ({me}));

   		if ( random((int)me->query("food")) > 200 ) {
			tell_object(me, "绳子「啪！」的一声断了，你重重地摔到地上。\n");
			message("vision", "绳子「啪！」的一声断了，"+me->name()+"重重地摔到地上。\n", 
				environment(me), ({me}));
			me->receive_damage("jing", (int)me->query("food"), "上吊未遂，摔死了");
			me->receive_damage("qi", (int)me->query("food"), "上吊未遂，摔死了");
		}
		else if ( random((int)me->query("food")) > 100 ) {
			tell_object(me, "绳子摇摇晃晃，你吓的晕了过去。\n");
			message("vision", "绳子摇摇晃晃，"+me->name()+"吓的晕了过去。。\n", 
				environment(me), ({me}));
			me->unconcious();
		}
		else {
			me->set_temp("last_damage_from", "上吊自尽了");
			me->die();
		}
	}
	return 1;
}

