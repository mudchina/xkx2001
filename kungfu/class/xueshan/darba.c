//Cracked by Roath

inherit NPC;
int auto_perform();
int ask_me();
int do_qiecuo();

void create()
{
set_name("达尔巴", ({ "darba", "dar", "ba" }));
        set("long",
"他是金轮法王的二弟子，已得法王五、六分真传，兼天生神力，一身外门功夫 \n"
"甚是了得，虽身形高瘦，却使一根长达四尺的纯金降魔杵。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "heroism");
        set("class","lama");
        set("inquiry",([
               "引见"  : (: ask_me :),
                "金轮法王" : (: ask_me :),
        ]));

        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 26);
	set("dex", 25);

        set("max_qi", 1500);
	set("qi", 1500);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 60);
        set("combat_exp", 250000);

        set_skill("force", 130);
        set_skill("dodge", 130);
        set_skill("parry", 130);
        set_skill("staff", 130);
        set_skill("hand", 130);
        set_skill("jingang-chu", 130);
        set_skill("dashou-yin", 130);
        set_skill("shenkongxing", 130);
        set_skill("longxiang-banruo", 130);

        map_skill("force", "longxiang-banruo");
        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");
        map_skill("hand", "dashou-yin");
	map_skill("dodge", "shenkongxing");

        prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
        if (clonep()) carry_object("/clone/weapon/xiangmo-chu");
//	if (ob = carry_object("/d/qilian/obj/xiangmo-chu")) //ob->wield();
}

/*void init()
{
        ::init();
        add_action("do_qiecuo", "qiecuo");
}
*/
int ask_me()
{
	if( this_player()->query("family/family_name") != "雪山派"
        && this_player()->query("family/family_name") != "血刀门")
	return 0;

	if( !present("xiangmo chu", this_object())){
	say("达尔巴摇了摇头：今天没力气跟你说了，你明天再来问我吧。\n");
	return 1;
	}

	if( this_player()->query("jlfw")){
	say("达尔巴说道：师兄要找师父再问我可没用。\n");
	return 1;
	}

        say(
"达尔巴看了" + this_player()->name() + "一眼不屑地说：想找我师父，得先过我\n"
"这一关，这位" + RANK_D->query_respect(this_player()) + "是不是先和我切搓一下？\n");
        this_player()->set_temp("marks/引1", 1);
        return 1;
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp("marks/引1") 
	&& present("xiangmo chu", me)) {
        say(ob->name() + "对达而巴说：好吧，那" 
             "我就同你切搓几招吧，点到为止。\n");
	  command("wield chu");
	  me->set_temp("challenger", ob);
          ob->set_temp("marks/引1", 0);
	  me->set("qi", (int)me->query("max_qi"));
	  me->set("eff_qi", (int)me->query("max_qi"));
	  me->set("neili", (int)me->query("max_neili"));
          return 1;
        }
        else
	  return 0;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
        int my_max_qi, his_max_qi;

	if ( !objectp(ob) ) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting(ob)) return ::chat();

	me->delete_temp("challenger");
        if ( !present(ob, environment()) ) return ::chat(); 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
	say(
                  "达而巴说：阁下武功确是不一般，在下十分佩服。\n"
                  "出了永昌往北走八十里，再往东二十里，然後往北走三十里，再往东、往北\n"
                  "各十里，我师父可能在那附近的草原上授猎。\n"
                );
                ob->set_temp("marks/引", 1);
		ob->set("jlfw", 1);
                return ::chat();
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
	"达而巴冲着" + ob->name() + "嘿嘿奸笑两声：阁下还是回去再练几年吧。\n"
                );
                return ::chat();
        }
        return ::chat();
}
/* init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
	if (ob->query("shen") > 10000) 
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
			this_object()->kill_ob(ob);
                }
}
void do_killing(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}
*/
void attempt_apprentice(object ob)
{
        command("say  法王可不允许我收徒。");
        //command("recruit " + ob->query("id"));
}
int accept_kill(object me)
{
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	if (present("xiangmo chu", this_object())){
	command("wield chu");
	}
        kill_ob(me);
        return 1;
}
int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !objectp(weapon) ) {
        if ( present("xiangmo chu", me))
        command("wield chu");
        return 1;
        }
}
