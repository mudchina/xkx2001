//Cracked by Roath
// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);
	object ob;
	string zhao_name;
	mapping skill;
	int my_skill, cost;

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");

        if (where->query("sleep_room"))
                return notify_fail("在睡房里不能读书，这会影响他人。\n");

	if (where->query("no_fight"))
					 return notify_fail("这里不是读书的地方。\n");

	if (me->query_temp("cursed", 1))
                return notify_fail("什么？\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("你要读什么？\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你无法从这样东西学到任何东西。\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");


	if( ob->query("id") == "jiuying zhenjing" && me->query("9yin") != "granted" ){
		message_vision("$N搅尽脑汁也看不明白这本$n。\n",me,ob);
		return 1;
	}

	message("vision", me->name() + "正专心地研读" + ob->name()
		+ "。\n", environment(me), me);

	if( (int)me->query("combat_exp") < skill["exp_required"] ) {
		write("你的实战经验不足，再怎么读也没用。\n");
		return 1;
	}

	notify_fail("以你目前的能力，还没有办法学这个技能。\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["jing_cost"] + skill["jing_cost"] 
		* (skill["difficulty"] - (int)me->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
		return 1;
	}

	if( !me->query_skill(skill["name"], 1) ) me->set_skill(skill["name"], 0);

	my_skill = me->query_skill(skill["name"], 1);

	if( (int)me->query("jing") > cost ) {
		if( (string)SKILL_D(skill["name"])->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是缺乏实战经验，你对%s上面所说的东西总是无法领会。\n", ob->name());
		} else {
			if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
				printf("你研读有关%s的技巧，对「%s」这一招似乎有些心得。\n", 
					to_chinese(skill["name"]), zhao_name);
			else
				printf("你研读有关%s的技巧，似乎有点心得。\n", to_chinese(skill["name"]));
			me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);
		}
	} else {
		cost = me->query("jing");
		if (cost < 0) cost = 0;
		write("你现在过于疲倦，无法专心下来研读新知。\n");
	}

	me->receive_damage("jing", cost, "心力绞瘁死了");

	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: study|du <物品名称>

这个指令使你可以通过阅读秘笈或其他物品自学某些技巧,
但前提是: 你不能是个『文盲』。

see also : learn
HELP
   );
   return 1;
}
