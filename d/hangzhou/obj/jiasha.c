//Cracked by Roath
// /d/hangzhou/obj/jiasha.c
// by aln 4 / 98

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("红衣袈裟", ({"jiasha", "jia", "sha"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件崭新的大红袈裟，精工制作而成。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
		  }

			if( !wizardp(this_player()) )
			{
				set("no_get", "这样东西不能离开那儿。\n");
				set("no_drop", "这样东西不能离开你。\n");
			}
		  setup();
}

void init()
{
		  add_action("do_quan", "quan");
}

int do_quan(string arg)
{
		  object ob, me = this_player();

		  if( me->query("family/family_name") != "少林派" )
					 return notify_fail("你不是少林佛门弟子，做不到以身饲虎。\n");

        if( (int)me->query_skill("buddhism", 1) < 160 )
                return notify_fail("你的佛学修为还不足于使你以身饲虎。\n");

        if( me->is_fighting() || me->is_busy() )
	        return notify_fail("你正忙着。\n");

        if( me->query_temp("sl_quan") )
                return notify_fail("你已经在劝服别人了。\n");

        if( !arg )
                return notify_fail("你要规劝谁？\n");

        if( !(ob = present(arg, environment(me))) )
                return notify_fail("这儿没有你要劝服的人。\n");

        if( ob->query("race") != "人类" )
                return notify_fail(ob->name() + "听不懂人话！\n");

        if( ob->query("shen") > -100000
        ||  (int)ob->query("combat_exp") < (int)me->query("combat_exp") )
                return notify_fail("这种小恶人，无需大师您操心了。\n");

        if( ob->is_fighting() || ob->is_busy() )
	        return notify_fail(ob->name() + "正忙着。\n");

		  if( userp(ob) )
					 return notify_fail("你劝不动玩家。\n");

		  message_vision("$N对$n规劝道，施主罪孽深重，还望早日回头是岸。\n", me, ob);

		  message_vision("$N冷笑道，别假慈悲了，接招！。\n", ob);

		  if( (int)ob->query("eff_qi")*10 < (int)ob->query("max_qi")*9 ) {
					 ob->kill_ob(me);
					 return 1;
		  }

		  me->set_temp("sl_quan", 1);
		  me->start_busy(1);

		  if( me->query_temp("armor/cloth") == this_object() )
					 call_out("hitby", 1, me, ob, 7 + random(5));
		  else    call_out("hitby", 1, me, ob, 20 + random(10));
		  return 1;
}

void hitby(object me, object ob, int period)
{
		  object weapon;
        int bonus,pot,exp,bud;

        if( environment(me) != environment(ob) ) {
                me->delete_temp("sl_quan");
                tell_object(me, "善哉，" + ob->name() + "已经走了。\n");
					 return;
		  }

		  if( me->is_fighting() ) {
					 me->delete_temp("sl_quan");
					 tell_object(me, "你自顾不遐，只得中止了规劝。\n");
					 return;
		  }

		  if( ob->is_fighting() ) {
					 me->delete_temp("sl_quan");
					 tell_object(me, ob->name() + "正忙着。\n");
					 return;
		  }

		  if( (int)ob->query("eff_qi")*10 < (int)ob->query("max_qi")*5 ) {
					 me->delete_temp("sl_quan");
					 ob->kill_ob(me);
					 return;
		  }

		  //me->add_temp("apply/parry", -400);
		  //me->add_temp("apply/denfense", -400);
		  me->set_temp("apply/parry",me->query_temp("apply/parry",1)-90);
		  me->set_temp("apply/defense",me->query_temp("apply/defense",1)-90);
		  ob->set_temp("apply/damage",ob->query_temp("apply/damage",1)+90);
		  //ob->add_temp("apply/damage", (int)ob->query_skill("force")/2);
		  if( weapon = ob->query_temp("weapon") )
					 COMBAT_D->do_attack(ob, me, weapon);
		  else    COMBAT_D->do_attack(ob, me);
		  ob->set_temp("apply/damage",ob->query_temp("apply/damage",1)-90);
		  me->set_temp("apply/parry",me->query_temp("apply/parry",1)+90);
		  me->set_temp("apply/defense",me->query_temp("apply/defense",1)+90);
		  //me->add_temp("apply/defense", 400);
		  //me->add_temp("apply/parry", 400);
        

        if( (int)me->query("qi")*10 < (int)me->query("max_qi")*2 
        ||  (int)me->query("eff_qi") * 10 < (int)me->query("max_qi")*3 ) {
                me->delete_temp("sl_quan");
                message_vision("$N哈哈大笑道，你还是少管闲事吧。\n", ob);
                return;
        }        

        period--;
        if( !period ) {
                me->delete_temp("sl_quan");
                message_vision("$N长跪谢罪道，我" + ob->query("name") + "忘恩负义，猪狗不如！\n", ob);
                message_vision("$N说完扬长而去。\n", ob);

                switch(ob->query("name")) {
		case "欧阳锋" : bonus = 5; break;
                case "丁春秋" : bonus = 5; break;
                case "金轮法王" : bonus = 3; break;
                case "鸠摩智" : bonus = 3; break;
                case "血刀老祖" : bonus = 3; break;
                case "洪安通" : bonus = 5; break;
                default : bonus = 1; break;
                }

                bonus *= (int)ob->query("combat_exp") / 50000;
				bud = bonus/4+random(bonus/4);
                me->improve_skill("buddhism", bud);

				bonus = bonus*2/3;

				if(bonus<240)bonus=240;
				if(bonus>450)bonus=450;

				pot = bonus/4+random(bonus/4);
				if( me->query("potential",1) + pot > me->query("max_potential",1) ) 
				{
					pot = me->query("max_potential",1) - me->query("potential",1);
				}

				me->add("potential", pot);
				
				exp = bonus/3+random(bonus/4);
                me->add("combat_exp", exp);

                write_file("/log/test/ShaolinQuan", sprintf("%s于%s时劝%s回头是岸得%s经验点和%s潜能and%sBuddhism\n", me->query("name"), ctime(time()), ob->query("name"), chinese_number(exp),chinese_number(pot),chinese_number(bud)));

                destruct(ob);
                return;
         }

         call_out("hitby", 1, me, ob, period);
}

                

