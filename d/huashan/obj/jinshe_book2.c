//Cracked by Roath
// jinshe_book2.c 金蛇秘笈

inherit ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("金蛇秘笈", ({ "jinshe miji", "miji", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", 
		"这是金蛇郎君遗下的《金蛇秘籍》。载有武功绝学，地图，\n"
		"兵刃和机关图样。\n");
		set("iden", "1");
		set("value", 10000000);
		set("material", "paper");
		set("no_drop","这样东西不能离开你。\n");
	}
	::create();
}

void init()
{
	if ( !environment(this_object())->query("jinshe") ) 
		call_out("switch_it", 1, this_object());

	add_action("do_read", "study");
        add_action("do_read", "du");
}

int switch_it(object obj)
{
	object obj1;

	obj1 = new(__DIR__"jinshe_book1");
        obj1->move(environment(this_object()));
	destruct(obj);

	return 1;
}

int do_read(string arg)
{
        object me = this_player();
	int level, check, shen;
	
	if (!arg || arg=="") 
		return notify_fail("你想读那项武功？剑法(jianfa)，锥法(zhuifa)，还是掌法(zhangfa)？\n");

	if ( me->query_skill("literate", 1) < 20 
	&& (me->query_skill("youshe-zhang", 1) > 10
	|| me->query_skill("jinshe-jianfa", 1) > 10
	|| me->query_skill("jinshe-zhuifa", 1) > 10 ) )
		return notify_fail("你识的字不多，再也不懂书上的讲解。\n");

	if ( arg == "zhangfa" ) {
		level = (int)me->query_skill("youshen-zhang", 1);
        	check = level*level*level;
		shen = (int)me->query("shen");
		if ( check >= shen * 10)
	        return notify_fail("你正神太少，不能屏弃邪念，驾驭学习金蛇秘籍上诡异招式的心法。\n");

		if ( level < 100 && check < (int)me->query("combat_exp")*10 ) {
			me->improve_skill("youshen-zhang", me->query("int"));
			me->receive_damage("jing", 30, "心力绞瘁死了");
			message_vision("$N正专心的阅读金蛇秘籍上的金蛇游身掌。\n", me);

			return 1;
		}
		else {
			write("你阅读良久，但仍然不能领悟秘籍所载的金蛇游身掌招式。\n");

			return 1;
		}
	}

	if ( arg == "jianfa" ) {
		level = (int)me->query_skill("jinshe-jianfa", 1);
                check = level*level*level;
		shen = (int)me->query("shen");
		if ( check >= shen * 10)
			return notify_fail("你正神太少，不能屏弃邪念，驾驭学习金蛇秘籍上诡异招式的心法。\n");
		
                if ( level < 100 && check < (int)me->query("combat_exp")*10 ) {
                        me->improve_skill("jinshe-jianfa", me->query("int"));
			me->receive_damage("jing", 30, "心力绞瘁死了");
                        message_vision("$N正专心的阅读金蛇秘籍上的金蛇剑法。\n", me);

			return 1;
                }
                else {
                        write("你阅读良久，但仍然不能领悟秘籍所载的金蛇剑法招式。\n");

			return 1;
                }
	}

	if ( arg == "zhuifa" ) {
		level = (int)me->query_skill("jinshe-zhuifa", 1);
                check = level*level*level;
		shen = (int)me->query("shen");
		if ( check >= shen * 10)
       		return notify_fail("你正神太少，不能屏弃邪念，驾驭学习金蛇秘籍上诡异招式的心法。\n");

                if ( level < 100 && check < (int)me->query("combat_exp")*10 ) {
                        me->improve_skill("jinshe-zhuifa", me->query("int"));
			me->receive_damage("jing", 30, "心力绞瘁死了");
                        message_vision("$N正专心的阅读金蛇秘籍上的金蛇锥法。\n", me);

                	return 1;
        	}
        	else {
                	write("你阅读良久，但仍然不能领悟秘籍所载的金蛇锥法招式。\n");

			return 1;
                }
	}

	write("你想读那项武功？剑法(jianfa)，锥法(zhuifa)，还是掌法(zhangfa)？\n");

	return 1;
}
