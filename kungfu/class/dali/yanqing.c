//Cracked by Roath
inherit NPC;

void create()
{
        set_name("段延庆", ({ "duan yanqing", "duan", "yanqing" }));
        set("nickname", "恶贯满盈");
        set("long", 
"此人身形修长，其胸凸出，由如一鼓，但是瘸了双腿，拄着根钢制拐杖。\n");
        set("gender", "男性");
        set("age", 55);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing",1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set_temp("apply/attack",  120);
        set_temp("apply/defense", 120);

        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("finger", 180);
        set_skill("kurong-changong", 180);
        set_skill("yiyang-zhi", 180);
        
        set_skill("strike", 180);
        set_skill("staff", 180);
        
        map_skill("dodge", "ding-dodge");
        map_skill("force", "kurong-changong");
        map_skill("finger", "yiyang-zhi");

        prepare_skill("finger", "yiyang-zhi");

        create_family("大理段家", 13, "弟子");

        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
        object ob;
//      ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_condition("xakiller")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

void attempt_apprentice(object me)
{

        if ((int)me->query("shen") > -100000){
                command("say 似你这类白道上的卧底也敢斗胆来找我?。");
                return;
        }
       if( me->query("combat_exp") < 100000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "
		武功尚未登堂入室，还是再修练修练去吧。");
                return;
        }

	if ((string)me->query("gender") !== "男性") {
                command("say 我只收男徒，" + RANK_D->query_respect(ob) + 
"还是另投高明吧。");
                return;
        } 
if( me->query("PKS) < 50) {
command ("say " + RANK_D->query_respect(this_player()) + "
你先去干掉几个白道人物再来拜我，局时我一定收你。");
                return;
        }
    command("say 好吧，我就收下你了。希望你能多杀几个旷世高手，涂害武林。");
        command("recruit " + me->query("id"));
       
 void init()
{
        object ob;

        ::init();
        if (interactive(me=this_player()) && 
me->query("family/master_id") == "duan yanqing"
        && me->query("shen") > -100000 ) {
                command("say " + RANK_D->query_rude(me) + 
"胆敢不尊师训，不去为非作歹，你好大的胆子！" );
                command( "expell " + me->query("id"));
        }
}
}
