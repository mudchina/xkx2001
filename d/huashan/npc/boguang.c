//Cracked by Roath
// boguang.c 田伯光
// qfy July 21, 1996

inherit NPC;

void create()
{
	set_name("田伯光", ({ "tian boguang", "tian", "boguang" }));
	set("nickname", "万里独行");
	set("long", 
"田伯光昔年为江湖中臭名昭彰的采花贼，但结识华山令狐冲后已\n"
"改邪归正。一手快刀绝技，天下无双。轻功在武林中也是一等的。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 30);
	set("shen", 0);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("score", 5000);

	set_skill("force", 80);
	set_skill("dodge", 100);
	set_skill("parry", 80);
	set_skill("luan-blade", 100);
	set_skill("blade", 100);
	set_skill("unarmed", 80);
	set_skill("literate", 50);
	set_skill("ding-dodge", 100);
	set_skill("ding-force", 80);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("parry", "luan-blade");
	map_skill("blade", "luan-blade");
	set("inquiry", ([
		"令狐冲" : "令狐兄是我生平第一知己。\n",
		"风清扬" : "你打得过我，我自然会带你去见他。\n",
		"风前辈" : "你打得过我，我自然会带你去见他。\n",
		"风清扬前辈" : "你打得过我，我自然会带你去见他。\n",
	]));

	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init() 
{
	object ob, me = this_object();

	::init();
	if ( interactive(ob = this_player()) && !is_fighting() && !me->query_temp("said") ) {
	   me->set_temp("said", 1);
	   command( "say 想找风前辈？你可得胜过我的快刀再说。");
	   remove_call_out("climb_tree");
	   call_out("climb_tree", 45, me); 	
	}
}

int accept_fight(object ob)
{
        object me = this_object();

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi = me->query("max_qi");
	object weapon;

        if (me->is_fighting()) {
           if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
                command("exert recover");
           }

	   if ( !me->query_temp("attack_pending") 
	   && objectp(weapon = me->query_temp("weapon")) ) {
	   	me->set_temp("attack_pending", 1);
           	remove_call_out("fast_attack");
		call_out("fast_attack", 3, me, ob);
           }

	   if ( !me->query_temp("fought") ) {
		me->set_temp("fought", 1);
	   }

	   remove_call_out("climb_tree");
           call_out("checking", 1, me, ob);
           return 1;
        }

	if (!me->is_fighting()) {
		remove_call_out("fast_attack");
		remove_call_out("climb_tree");
                call_out("climb_tree", 30, me);
	}

	if (me->query("qi")*2 <= me->query("max_qi") 
	&& environment(me)->query("short") == "朝阳峰" ) {
             me->remove_enemy(ob);
	     ob->remove_enemy(me);
	     environment(me)->add("tian_count", 1);
	     command( "say "+RANK_D->query_respect(ob)+"果然高明，在下多有得罪。在下这便带你去见风前辈。");
	     message("vision", ob->name() + "随着田伯光走进荒山里。\n", environment(ob), ({ob}));
	     me->move("/d/huashan/yelin1");
	     ob->move("/d/huashan/yelin1");
	     tell_object(ob,"田伯光领你走过华山后山的一片荒山野林，你注意到那儿似乎有个山洞。\n");
	     me->move("/d/huashan/xiaojing1");
	     ob->move("/d/huashan/xiaojing1");
   	     tell_object(ob,"你跟着田伯光走了良久，来到一条小路。\n");
	     command( "bow" );
	     command( "say 风前辈住处由此路过去便是，在下失陪了。");
	     say("田伯光说完便头也不回地走了。\n");	
	     destruct(me);
	}

        if ( !present(ob, environment()) && me->query("attack_pending")==1 ) {
	   me->delete_temp("attack_pending");
           remove_call_out("fast_attack");
           return 1;
        }

        return 1;
}

int fast_attack(object me, object ob)
{
	int i, num;

	me->delete_temp("attack_pending");
	num = random(2)+3;

	message_vision("田伯光大喊一声，使出其快刀绝技疯狂般向$N连劈了"+chinese_number(num)+"刀。\n", ob);

	for (i=1; i<num+1; i++) {
	    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	}

	return 1;
}

int climb_tree(object me)
{
	if ( environment(me)->query("short") == "朝阳峰" ) {
	   if ( !me->query_temp("fought") ) {
	      environment(me)->add("tian_count", 1);	
	      message_vision("田伯光怒火大涨，泼口大骂道：“你既然无意拜见风前辈，干巴巴地叫老子下来干嘛？”\n", me);
	      message_vision("田伯光接着便爬回树上，拜见周公去了。\n", me);		
	   }
	   else {
	      message_vision("田伯光打了个呵欠。\n", me);
	      command("say 恕我不能奉陪。");
	      environment(me)->add("tian_count", 1);
	      message_vision("田伯光接着便爬回树上，拜见周公去了。\n", me);
	   }
	}
	else {
	   message_vision("田伯光匆匆忙忙地离开了。\n", me);
	}

	destruct(me);

	return 1;
} 
