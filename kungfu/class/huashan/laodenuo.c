//Cracked by Roath
// laodenuo.c 劳德诺
// qfy July 4, 1996. 

inherit NPC;

void create()
{
	set_name("劳德诺", ({ "lao denuo", "lao", "denuo" }));
	set("long", 
"劳德诺是华山的二弟子，但年龄却是最大，这是由于他带艺投师\n"
"的缘故。劳德诺为人世故老练，华山事故都由他打点。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 26);
	set("con", 25);
	set("dex", 26);
	
	set("max_qi", 800);
	set("max_jing", 680);
	set("neili", 950);
	set("max_neili", 950);
	set("jiali", 40);
	set("combat_exp", 90000);
	set("score", 5000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("huashan-jianfa", 80);
	set_skill("strike", 70);
	set_skill("hunyuan-zhang", 70);
	set_skill("zixia-gong", 80);
	set_skill("huashan-shenfa", 80);
	set_skill("cuff", 70);
	set_skill("pishi-poyu", 70);
	set_skill("ziyin-yin", 60);
	set_skill("zhengqi-jue", 60);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");
	
	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu"); 

	create_family("华山派", 14, "弟子");

	set("inquiry", ([
	    "拜帖" : "请呈上拜帖让我为你通传。\n",
	    "岳不群" : "那正是家师。\n",
	    "宁中则" : "那是我师母。\n",
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	object *inv, obj, ob2, ob = this_player(), me = this_object();
	int i, found = 0, char = 0;

	::init();

	if ( interactive(ob) && living(me) && environment(me)->query("short")!="练武场" ) {
		message_vision("$N匆匆忙忙地离开了。\n", me);
		me->move("/d/huashan/square");
	}

	inv = all_inventory(ob);
	for (i=0; i<sizeof(inv); i++) {
		if ( inv[i]->is_container() && present("zixia book", inv[i]) ) found = 1;
		if ( inv[i]->is_character() ) {
			if ( present("zixia book", inv[i]) ) found = 1;
			if ( objectp(obj=present("bu dai", inv[i])) && present("zixia book", obj) ) found = 1;
			ob2 = inv[i];
			char = 1;
		}
	}

	if ( ( present("zixia book", ob) || found ) && living(me) ) {
		message_vision("劳德诺突然暴起然攻击$N。\n", ob);
		if ( char ) {
			message_vision("在劳德诺的猛攻之下，$N不得把$n放下。\n", ob, ob2);
			ob2->move(environment(me));
			me->kill_ob(ob2);
		}
		tell_object(ob,"劳德诺想抢紫霞秘笈！\n");
		me->kill_ob(ob);
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
	}
}

int checking(object me, object ob)
{
	int my_max_qi = me->query("max_qi");
	object obj1, obj2;

	if (me->is_fighting()) {
	   if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
		command("exert recover");
	   }

	   call_out("checking", 1, me, ob);
	   return 1;
	}

	if (ob->is_ghost()) {
	   obj1 = present("corpse", environment(me));
	   obj2 = present("zixia book", obj1);  
	   say("劳德诺弯下身来，由尸体里拿出紫霞秘笈！\n");
	   command("say 哈哈！"+obj2->name()+"终于落入我手中了！\n");
	   command("hehe");
	   destruct(obj2);      
	   remove_call_out("checking"); 
	   return 1;
	}

	if ( !present(ob, environment()) ) return 1;
}

int accept_object(object me, object obj)
{

	object ob = this_player();

	if ( obj->name() == "拜帖" && obj->query("id") == "bai tie" ) {
	   remove_call_out("say_dest");
	   call_out("say_dest", 1, obj, ob);

	   return 1;
	}

	command( "hmm" );
	command( "say 你给我这东西做什麽？" );
	   
	return 0;
}

int say_dest(object obj, object ob)
{
	if ( random(10) == 5 ) {
	   command( "say 这位"+RANK_D->query_respect(ob)+"请进大堂面见家师和师母。");
	   ob->set_temp("marks/帖", 1);
	}
	else {
	   command( "say 这位"+RANK_D->query_respect(ob)+"来得真不巧，家师和师母有要事不克分身相见，请改天再来。抱歉！" );
	}

	destruct(obj);

	return 1;
}