//Cracked by Roath
// challenger.c 少林拦路人  

inherit NPC;
#include "/kungfu/class/shaolin/auto_perform.h"
int auto_perform();

void create() {
    set_name("游方僧人", ({ "sengren","seng" }) );
    set("gender", "男性");
    set("age", 25+random(25));
    set("long",
        "他是一位云游四方，随缘渡人的僧人。生得骨格不凡，风神迥异。\n");
    set("shen_type", 1);
    set("attitude", "peaceful");
    set("heart_beat", 1);
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: auto_perform :),
    }) );

    setup();

    carry_object("/clone/misc/cloth")->wear();
}

void init() {
    object opponent = this_player();
    object me = this_object();
    int my_exp, max_lvl, i;

	 if ( !me->query_temp("copied") ) {

		  my_exp = opponent->query("combat_exp") +
				(int) random(opponent->query("combat_exp")/10) * (random(2) + 1);
		  max_lvl = to_int(exp(log(my_exp*10)/3 )) + 1;

		  if ( max_lvl > 120 ) {
				me->set_skill("buddhism", 120);
		  }
		  else
				me->set_skill("buddhism", max_lvl);
		  me->set_skill("dodge", max_lvl);
		  me->set_skill("shaolin-shenfa", max_lvl);
		  me->map_skill("dodge", "shaolin-shenfa");
		  me->set_skill("finger", max_lvl);
		  me->set_skill("yizhi-chan", max_lvl);
		  me->set_skill("nianhua-zhi", max_lvl);
		  me->set_skill("strike", max_lvl);
		  me->set_skill("banruo-zhang", max_lvl);
		  me->set_skill("sanhua-zhang", max_lvl);
		  me->set_skill("parry", max_lvl);
		  me->map_skill("parry", "yizhi-chan");
		  if (max_lvl < 150) {
				me->map_skill("finger", "nianhua-zhi");
				me->map_skill("strike", "sanhua-zhang");
				me->prepare_skill("finger", "nianhua-zhi");
				me->prepare_skill("strike", "sanhua-zhang");
		  }
		  else {
				me->map_skill("finger", "yizhi-chan");
				me->map_skill("strike", "sanhua-zhang");
				me->prepare_skill("finger", "yizhi-chan");
				me->prepare_skill("strike", "sanhua-zhang");
		  }

		  me->set_skill("force", max_lvl);
		  me->set_skill("hunyuan-yiqi", max_lvl);

		  me->map_skill("force", "hunyuan-yiqi");
		  me->set("combat_exp", my_exp);
		  me->set("max_jing", opponent->query("max_jing"));
		  me->set("eff_jing", opponent->query("max_jing"));
		  me->set("jing", opponent->query("max_jing"));
		  me->set("max_jingli", opponent->query("max_jingli"));
		  me->set("eff_jingli", opponent->query("max_jingli"));
		  me->set("jingli", opponent->query("max_jingli"));
		  if (opponent->query("max_neili") > 500) {
			 me->set("max_neili", opponent->query("max_neili"));
		  }
		  else me->set("max_neili", 500);
		  me->set("neili", me->query("max_neili"));
		  me->set("jiali", 30) ;
		  //		(int) (me->query_skill("force", 1)/10 + me->query_skill("hunyuan-yiqi", 1)/10) );

		  me->set("max_qi",
				opponent->query("max_qi") + (int) random(opponent->query("max_qi")/10) * (random(3) - 1) );
		  me->set("qi", me->query("max_qi"));
		  me->set("eff_qi", me->query("max_qi"));

		  me->set_temp("copied", 1);
	 }

	 if ( !me->query_temp("said") ) {
		  message_vision("$N对$n合什为礼，说道：阿弭佗佛！" +
				RANK_D->query_respect(opponent) + "，贫僧这厢有礼了！\n", me, opponent);
		  command("say " + "久仰少林乃武学正宗，小僧诚心讨教，不知" + opponent->query("name") + "大师可否指点一二？\n");
		  me->set_temp("said", 1);
	 }

	 if ( !me->query_temp("opponent") ) {
		  me->set_temp("opponent", opponent);
	 }

}

int accept_fight(object fighter) {
	 object me = this_object();

	 if ( me->query_temp("opponent") != fighter )
		  return 0;

    if ( me->is_busy() || me->is_fighting() )
        return 0;

    if ( !me->query_temp("count") ) me->set_temp("count", 1);
    if ( !me->query_temp("fought") ) me->set_temp("fought", 1);

    return 1;

}

int accept_kill(object killer) {
	object me = this_object();

    if ( !(me->query_temp("opponent") == killer) && 
       killer->query("combat_exp") > me->query("combat_exp") ) {
        call_out("destruct_me", 1, me, killer, 0);
    }
    else {
        command("hmm");
        me->kill_ob(killer);
    }

	return 1;
}

int chat() {
    object me = this_object();
    object ob = me->query_temp("opponent");
    int me_max_qi, ob_max_qi;
    int counter, arg_bonus, bonus;

    if ( !me->query_temp("count") ) me->set_temp("count", 1);
    if ( me->query_temp("destructed") ) return ::chat();

    if ( !objectp(ob) ) {
        me->set_temp("destructed", 1);
        call_out("destruct_me", 1, me, me, 1);
        return ::chat();
    }

    if ( !present(ob, environment()) ) {
        me->set_temp("destructed", 1);
        call_out("destruct_me", 1, me, me, 1);
        return ::chat();
    }

    me_max_qi = me->query("max_qi");
    ob_max_qi = ob->query("max_qi");

    if ( me->is_fighting() ) {
        me->set_temp("count", 1);
        return ::chat();
    }

    counter = me->query_temp("count");
    counter++;
    me->set_temp("count", counter);

    if ( ( me->query("qi")*100 / me_max_qi) <= 50 && counter > 3 && me->query_temp("fought") == 1 ) { 
       /* If my_exp < ob_exp, no bonus at all.
          Since it's pretty hard for ppl, should pay high bonus for winning high exp npc. */ 

        if ( ob->query("combat_exp") < me->query("combat_exp") ) {
            bonus = (int) ( (me->query("combat_exp") - ob->query("combat_exp"))
                             * 1000 / ob->query("combat_exp") );
            if ( !(ob->query_temp("argued")) ) {
                arg_bonus = ob->query_temp("argued");
                if (arg_bonus > 3) arg_bonus = 3;
                bonus = bonus + arg_bonus * random(5); /* This argue bonus for winning low dizi indeed. */
            }
            if (bonus < 10) bonus = 10;
            ob->add("combat_exp", bonus);
            ob->add("potential", bonus/2);
            if ( ob->query("potential",1) > ob->query("max_potential",1) )
                ob->set("potential", ob->query("max_potential",1) );
           // write_file("/log/test/sl_shanmen", 
           //     sprintf("%s于%s时得%d经验\n", ob->query("name"), ctime(time()), bonus));
        }

        me->set_temp("destructed", 1);
        call_out("destruct_me", 1, me, ob, 2);
        ob->delete_temp("challenged");
        ob->delete_temp("challenger");
        ob->delete_temp("argued");
        return ::chat();
    }

    else if ( ( ob->query("qi")*100 / ob_max_qi) < 50 && counter > 3 && me->query_temp("fought") == 1 ) {
        me->set_temp("destructed", 1);
        call_out("destruct_me", 1, me, ob, 3);
        ob->delete_temp("challenged");
        ob->delete_temp("challenger");
        ob->delete_temp("argued");
        return ::chat();

    }

    return ::chat();
}

void destruct_me(object me, object ob, int status) {
    switch (status) {
    case 0:
        command("halt");
        command("say " + "少林弟子原来是以多取胜！咱们后会有期！\n");
        message_vision("$N一纵身跳出圈外，扬长而去。\n", me);
        me->remove_all_enemy();
        killer->remove_all_enemy();
        break;
    case 1:
        command("say " + "少林的和尚怎么一转眼就不见了？\n");
        command("crazy");
        break;
    case 2:
        command("admire " + ob->query("id"));
        command("say " + "小僧今日就此别过，日后当来再次讨教！\n");
        message_vision("$N双手一拱，恭敬地离开了。\n", me);
        break;
    case 3:
        command("haha " + ob->query("id"));
        command("say " + "少林寺的和尚就会油嘴滑舌，看来没有什么真功夫！\n");
        message_vision("$N大笑三声，扬长而去。\n", me);
        break;
    default:
    }

    destruct(me);
}
