//Cracked by Roath
// huijin 慧金

inherit NPC;

string ask_me();

void create()
{
	set_name("慧金尊者", ({ "hui jin", "hui", "jin" }));
	set("nickname", "辣手灭倭");
//	set("long", 
//	");
	set("gender", "男性");
	set("age", 38);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 26);
	set("con", 15);
	set("dex", 19);
	
	set("max_qi", 520);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 5000);

	set_skill("force", 80);
	set_skill("dodge", 88);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("strike", 85);
	set_skill("hand", 95);
	set_skill("claw", 80);
	set_skill("cuff", 95);
	set_skill("club", 50);
	set_skill("literate", 80);
	set_skill("xiuluo-dao", 100);
	set_skill("zui-gun",55);
	set_skill("shaolin-shenfa", 85);
	set_skill("jingang-quan", 90);
	set_skill("hunyuan-yiqi", 80);
	set_skill("buddhism", 85);

	map_skill("cuff", "jingang-quan");
	map_skill("force", "hunyuan-yiqi");
	map_skill("parry", "xiuluo-dao");
	map_skill("blade", "xiuluo-dao");
	map_skill("club", "zui-gun");
	map_skill("dodge", "shaolin-shenfa");
	
	prepare_skill("cuff", "jingang-quan");

	create_family("少林派", 38, "弟子");

	set("inquiry", ([
	    "浪人" : (: ask_me :),
	    "日本浪人" : (: ask_me :),
	    "灭倭" : (: ask_me :),
	    "辣手灭倭" : "贫僧生平最痛恨倭寇，歼倭无数，承蒙同道爱戴，送我这个名号。",
	]));

	setup();
	carry_object("/clone/weapon/jiedao")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	object obj, me = this_object();

	::init();
	if( strsrch(file_name(environment()), "/d/quanzhou/") == -1 ) {
		message_vision("$N快步走了过来。\n$N神色慌张地离开了。\n", me);
                this_object()->move("/d/quanzhou/ganlu");
		message_vision("$N快步走了过来。\n", me);
		return;
	}
	else if( obj = present("lang ren", environment(me)) ) {
                call_out("kill_ob", 1, obj);
		call_out("checking", 1, me, obj);
		me->set_leader(0);
		if ( !me->query("said") ) message_vision("$N大喝道：东洋鬼子，纳命来吧！\n", me);
		me->set("said", 1);
		remove_call_out("home2");
	}
}

string ask_me()
{
        object me = this_object(), leader = this_player();

	me->set_leader(leader);

	message_vision("$N勃然大怒！\n", me);
	call_out("home2", 100, me);
	return "快带我去！\n";
}

int accept_fight(object ob)
{
        object me = this_object();
        int my_max_qi = me->query("max_qi");

        if ( me->query("qi")*100 / my_max_qi <= 80 ) {
                call_out("checking1", 1, me, ob);
                return 0;
        }

        remove_call_out("checking");
        call_out("checking", 1, me, ob);

        return 1;
}

int accept_kill(object ob)
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

	if (me->query("said")) me->delete("said");

	if (me->is_fighting()) {
           if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
                command("exert recover");
           }

           call_out("checking", 1, me, ob);
           return 1;
        }

	if (!me->is_fighting()) {
		call_out("home", 1, me);
        }

	if (!present(ob, environment())) {
		command("haha");
                message_vision("$N头也不回地走了。\n", me);
                me->move("/d/quanzhou/ganlu");
		return 1;
	}

	return 1;
}

int home(object me) 
{
	object obj;

	obj = present("lang ren", environment(me));
	if ( !obj && present("corpse", environment(me)) ) {
		command("haha");
                message_vision("$N头也不回地走了。\n", me);
                me->move("/d/quanzhou/ganlu");
        }
	else {
		kill_ob(obj);
		call_out("checking", 1, me, obj);
	}

	return 1;
}

int home2(object me)
{
	object obj;

	if ( !me->is_fighting() && !obj = present("lang ren", environment(me)) ) {
		message_vision("$N大怒说道：你是存心跟贫僧开玩笑吧，怎么走了这么久都不见有日本浪人？\n", me);
		message_vision("$N气鼓鼓地走了。\n", me);
		me->move("/d/quanzhou/ganlu");
	}

	return 1;
}
