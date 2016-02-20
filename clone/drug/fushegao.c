//Cracked by Roath

// baihuafushegao.c 百花蝮蛇膏
// ywz 08/31/96

#include <ansi.h>

inherit ITEM;
inherit F_CLEAN_UP;

int do_use(string);

void init()
{
	add_action("do_use", "sa");
	add_action("do_eat", "eat");
}

void create()
{
	set_name(RED "百花腹蛇膏" NOR, ({"fushe gao", "gao"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块百花蝮蛇膏，看上去黑乎乎的，还透着红光，用来对付敌人最好了。\n");
		set("value", 10000);
		set("medicine", 1);
	}

	setup();
}

int do_use(string arg)
{
	object me, target, *ob,*enemy;
	int i, skill, damage,exp1,exp2;
	me = this_player();

	skill = me->query_skill("force");

//      if (!id(arg))
//              return notify_fail("你要用什么？\n");

	if (!me->is_fighting())
		return notify_fail("百花蝮蛇膏只能在战斗中使用!\n");

	message_vision(HIG "$N扬手洒开一些不知什么，愕 ？  啊...！ \n" NOR, me);

	enemy = this_player()->query_enemy();
	exp1  = this_player()->query("combat_exp");
//        exp2 = enemy->query("combat_exp");

//      if( enemy && living(enemy) )
//         enemy->die();

	i = sizeof(enemy);
	while(i--)
	{
//                exp2[i] *= enemy[i]->query("combat_exp");

		if( enemy[i] && living(enemy[i]) )

		{
//                   exp2[i] = enemy[i]->query("combat_exp");

			if (exp1 >= 800000 )
			{
			enemy[i]->unconcious();
			}
			if ((exp1 >= 500000) && (exp1 < 800000))
			{
			      if( random(2) == 1)
			      {
				 enemy[i]->unconcious();
			       }
			       else
			       {
				 this_player()->unconcious();
				}
			 }
			if ((exp1 >= 200000) && ( exp1 < 500000))
			{
			       if (random(3) == 1) 
			       {
				   enemy[i]->unconcious();
				}
			       else
			       {
				   this_player()->unconcious();
			       }
			}
			if  ((exp1 >= 100000) && (exp1 < 200000))
			{
				if (random(4) == 1)
				{
				   enemy[i]->unconcious();
				}
				else
				{
				    this_player()->unconcious();
				}
			}
			if ((exp1 >= 10000) && (exp1 < 100000))
			{
				if (random(10) == 1)
				{
				    enemy[i]->unconcious();
				    this_player()->unconcious();
				}
				else
				{
				   this_player()->unconcious();
				}
			 }
		       if (exp1 < 10000)
			{
				if (random(20) == 1)
				{
				    enemy[i]->unconcious();
				    this_player()->unconcious();
				}
				else
				{
				   this_player()->unconcious();
				}

			 }
//                        tell_object(enemy[i], "你觉得眼前一阵模糊，全身一下子象散了架！\n");
//                        enemy[i]->unconcious();
//                        }
//                        else {
//                        tell_object(enemy[i], "你觉得眼前一阵模糊，全身一下子象散了架！\n");
//                        tell_object(this_player(), "你觉得眼前一阵模糊，全身一下子象散了架！\n");

//                        enemy[i]->unconcious();
//                        this_player()->unconcious();
//                        }

//                      if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
//                      else enemy[i]->kill_ob(this_object());
		}
	}

/*
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
		{
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("int") * 2 ) continue;

//              damage = skill - ((int)ob[i]->query("max_neili") / 10);
//              if( damage > 0 )
//                      {
			tell_object(ob[i], "你觉得眼前一阵模糊，全身一下子象散了架！\n");
			ob[i]->unconcious();
//                      ob[i]->receive_damage("qi", damage);
//                      if( (int)ob[i]->query("neili") < skill * 2 )
//                              ob[i]->receive_wound("qi", damage);
//                      tell_object(ob[i], "你觉得眼前一阵模糊，全身一下子象散了架！\n");
//                      }
//              else
//                     {
//                     ob[i]->add("qi", damage);
//                     }

//              if( userp(ob[i]) ) ob[i]->fight_ob(me);
//              else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

//              command("chat 这下你们可着了我的道道了，哈哈 ！");

*/
		destruct(this_object());
		return 1;
//              }
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	return notify_fail("这东西不能这么吃。\n");

//      destruct(this_object());
	return 1;
}


