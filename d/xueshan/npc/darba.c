//Cracked by Roath

inherit NPC;

int ask_me();
int do_qiecuo();

void create()
{
set_name("达而巴", ({ "darba", "dar", "ba" }));
        set("long",
"他是金轮法王的二弟子，已得法王五、六分真传，兼天生神力，一身外门功夫 \n"
"甚是了得，虽身形高瘦，却使一根长达四尺的纯金降魔杵。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "heroism");
        set("class","lama");
        set("inquiry",([
               "引见"  : (: ask_me :),
                "金轮法王" : "他是在下师父。\n",
        ]));

        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 26);
	set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 450);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 100000);

        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("staff", 90);
        set_skill("hand", 90);
        set_skill("jingang-chu", 100);
        set_skill("dashou-yin", 90);
        set_skill("xueshitiao", 100);
        set_skill("longxiang-banruo", 100);

        map_skill("force", "longxiang-banruo");
        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");
        map_skill("hand", "dashou-yin");
	map_skill("dodge", "xueshitiao");

        prepare_skill("hand", "dashou-yin");


        setup();
        carry_object("/d/qilian/obj/xiangmo-chu")->wield();
        carry_object("/d/qilian/obj/lamajiasha")->wear();	
}

/*void init()
{
        ::init();
        add_action("do_qiecuo", "qiecuo");
}
*/
int ask_me()
{
        say(
"达而巴看了" + this_player()->name() + "一眼不屑地说：想找我师父，得先过我\n"
"这一关，这位" + RANK_D->query_respect(this_player()) + "是不是先和我切搓一下？\n");
        this_player()->set_temp("marks/引1", 1);
        return 1;
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp("marks/引1") ) {
        say(ob->name() + "对达而巴说：好吧，那" 
             "我就同你切搓几招吧，点到为止。\n");
	  remove_call_out("checking");
          call_out("checking", 1, me, ob);
          ob->set_temp("marks/引1", 0);
          return 1;
        }
        else
	  return 0;
}

int checking(object me, object ob)
{

        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
	say(
                  "达而巴说：阁下武功确是不一般，在下十分佩服。\n"
                  "出了永昌往北走八十里，再往东二十里，然後往北走三十里，再往东、往北\n"
                  "各十里，我师父可能在那附近的草原上授猎。\n"
                );
                ob->set_temp("marks/引", 1);
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
	"达而巴冲着" + ob->name() + "嘿嘿奸笑两声：阁下还是回去再练几年吧。\n"
                );
                return 1;
        }
        return 1;
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
