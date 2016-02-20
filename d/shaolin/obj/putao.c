//Cracked by Roath
// putao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("葡萄", ({"putao"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗水灵灵的葡萄。\n");
		set("unit", "颗");
		set("food_remaining", 1);
		set("food_supplay", 5);
	}
}

void init()
{
	::init();
	if( this_player() == environment() )
		add_action("do_dream", "dream");
}

int do_dream(string arg)
{
	object me;

	if ( !arg )
	{
		return notify_fail("什么？\n");
	}

	me = this_player();

	if ( arg == "neili" )
	{
		write("你在梦中和葡萄讨论练功方法，内力有所提高。\n");
		me->add("neili", 10);
		me->add("max_neili", 10);
	}

	else if ( arg == "jingli" )
	{
		write("你在梦中和葡萄讨论法术，精力更加旺盛了。\n");
		me->add("jingli", 10);
		me->add("max_jingli", 10);
	}

	else if ( arg == "exp" )
	{
		mapping mine;
		
		mine = me->query_entire_dbase();
		write("你在梦中和葡萄大战三百回合，经验大增。\n");
		mine["combat_exp"] += 100;
	}

	else if ( arg == "potential" )
	{
		mapping mine;
		
		mine = me->query_entire_dbase();
		write("你在梦中和葡萄大战三百回合，浅能增加不少。\n");
		mine["potential"] = 100;
	}

	else if (
		arg == "literate" ||
		arg == "buddhism" ||
		arg == "force" ||
		arg == "unarmed" ||
		arg == "dodge" ||
		arg == "parry" ||
		arg == "magic" ||
		arg == "stealing" ||
		arg == "banruo-zhang" ||
		arg == "bashi-shentong" ||
		arg == "cibei-dao" ||
		arg == "damo-jian" ||
		arg == "fengyun-shou" ||
		arg == "fumo-jian" ||
		arg == "jingang-quan" ||
		arg == "longzhua-gong" ||
		arg == "luohan-quan" ||
		arg == "nianhua-zhi" ||
		arg == "pudu-zhang" ||
		arg == "qianye-shou" ||
		arg == "hunyuan-yiqi" ||
		arg == "sanhua-zhang" ||
		arg == "shaolin-shenfa" ||
		arg == "weituo-gun" ||
		arg == "wuchang-zhang" ||
		arg == "xiuluo-dao" ||
		arg == "yingzhua-gong" ||
		arg == "yizhi-chan" ||
		arg == "zui-gun" ||
		arg == "sword"
		)
	{
		write("你梦见葡萄给你讲解" + to_chinese(arg) + "的诀窍，获益非浅。\n");
		me->improve_skill(arg, random(10*me->query("int")));
	}
	else
		return notify_fail("什么？\n");

	destruct(this_object());

	return 1;
}
