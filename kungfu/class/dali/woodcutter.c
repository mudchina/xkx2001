//Cracked by Roath
// woodcutter.c 樵夫
// A.P.

inherit NPC;

string ask_me();

void create()
{
	set_name("樵夫", ({ "qiao fu", "qiao", "woodcutter" }));
	set("long", "一个中年樵夫，看起来普普通通，但眼中隐隐闪动着一股霸气。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 30);
	set("shen", 0);
	set("max_qi", 1800);
	set("max_jing", 1800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 10);
	set("score", 5000);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("axe", 150);
	set_skill("finger", 120);
	set_skill("yiyang-zhi", 100);
	set_skill("duanshi-shenfa", 100);
	set_skill("kurong-changong", 80);
	map_skill("dodge", "duanshi-shenfa");
	map_skill("force", "kurong-changong");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger", "yiyang-zhi");

	set("inquiry", ([
		"上山" : "要想上山，先过了我这关再说。\n",
		]));
	
	setup();
	carry_object("/d/dali/obj/axe1")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

string ask_me()
{
	set("combat_exp",350000);
	return ;
}

int accept_fight(object ob)
{
	object me = this_object();

	if (environment(me)==find_object("/d/dali/yideng4.c")) {
		set("combat_exp",350000);
		me->set_temp("challenger", ob);
		return 1;
	}
	else { return 1; }
}

int chat()
{
	object axx, me = this_object();
	object ob = me->query_temp("challenger");
	object weapon;

	if ( !objectp(ob) ) return ::chat();

	if (me->is_fighting(ob)) {
		if (objectp(weapon=me->query_temp("weapon"))) {
			command("unwield axe");
			message_vision("樵夫大喝一声，向$N连点了三指。\n", ob);
			call_out("fast_hit", 1, me, ob, 0);
			call_out("fast_hit", 2, me, ob, 0);
			call_out("fast_hit", 3, me, ob, 1);
		}
		return ::chat();
        }

	me->delete_temp("challenger");
	remove_call_out("fast_hit");
	if (me->is_fighting()) return ::chat();

	if (me->query("qi")*2 <= me->query("max_qi")) {
		command("say "+"果然高明。");
		command("thumb "+getuid(ob));
		axx=new("/d/dali/obj/axe1.c");
		axx->move(me);
		command("give "+getuid(ob)+" axe");
		message_vision("樵夫转身大步下山而去，一会儿就不见了\n",ob);
		destruct(me);
		return ::chat();
	}
	else {
		if (ob->query("qi")*2 <= ob->query("max_qi")) {
			message_vision("樵夫不屑地对$N撇了撇嘴：“就这点功夫，还想上山见我师傅？滚你的吧！”\n",ob);
			ob->move("/d/dali/droad2.c");
			set("combat_exp",10);
			if (!present("axe", me)) {
				axx=new("/d/dali/obj/axe1.c");
				axx->move(me);
			}
			weapon = present("axe", me);
			command("wield axe");
			return ::chat();
		}
	}
	return ::chat();
}

void fast_hit(object me, object ob,int a)
{
	COMBAT_D->do_attack(me, ob);
	if (a==1) command("wield axe");
	return;
}
