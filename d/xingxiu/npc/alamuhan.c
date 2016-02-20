//Cracked by Roath
// npc: /d/xingxiu/npc/alamuhan.c
// Jay 3/17/96

inherit NPC;

int ask_me();
int do_qiecuo();

void create()
{
        set_name("李文秀", ({ "li wenxiu", "li", "wenxiu" }));
        set("long", "她一身回人的打扮，却是汉人的模样。\n");
        set("gender", "女性");
        set("age", 17);

        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("whip", 40);

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 20);

        set("combat_exp", 15000);
        set("attitude","friendly");
	set("horse_count", 1);
        set("inquiry", ([
		"高昌谜宫" : "听说就在天山那边。",
                "姑娘追" : (: ask_me :),
		"赛马" : (: ask_me :),
                "马" : (: ask_me :),
        ]) );

        set("shen_type", 1);
        setup();
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/changbian")->wield();
}

/*void init()
{
        ::init();
        add_action("do_qiecuo", "qiecuo");
}
*/
int ask_me()
{
        if ((int)this_player()->query_temp("marks/马")) {
                say(
"李文秀对" + this_player()->name() + "说：你这孩子怎么老缠着本姑娘。\n");
                return 1;
        } 
	
	if (query("horse_count") < 1){
                say(
"李文秀对" + this_player()->name() + "说：今天太晚了，本姑娘累了，你明天早点儿来。\n");
                return 1;
	}
	else{
        say(
"李文秀看了" + this_player()->name() + "一眼，说道：\n"
"本姑娘在这里的鞭法也小有点儿名气，这位" + RANK_D->query_respect(this_player()) + "\n"
"想不想和我切搓几下?\n");
        this_player()->set_temp("marks/马1", 1);
        return 1;
        }
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp("marks/马1") ) {
        say(ob->name() + "对李文秀说：好吧，那" 
             "我就同你切搓几招吧，点到为止。\n");
          me->set_temp("challenger", ob);
          ob->set_temp("marks/马1", 0);
          return 1;
        }
        else
	  return 0;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
        object horse;
        int my_max_qi, his_max_qi;

	if( !objectp(ob) ) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting(ob)) return ::chat();
	
	me->delete_temp("challenger");
	
	if (me->is_fighting()) return ::chat();

        if ( !present(ob, environment()) ) return ::chat(); 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                say(
                  "李文秀说：中原武学果然不一般，小女子十分佩服，过些日子我也要回中原去。\n"
                  "送你一匹伊犁马略表寸心。\n"
                );
		horse = new("/clone/horse/yilima");
                horse->move("/d/xingxiu/saimachang");
		horse->set_lord(ob);
		horse->set_leader(ob);
                ob->set_temp("marks/马", 1);
                message_vision("$N交给$n一匹马。\n", me, ob);
		add("horse_count", -1);
                return ::chat();
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "李文秀冲着" + ob->name() + "撇了撇嘴，说道：中原武学不过如此。\n"
                );
                message("vision",
                   ob->name() + "对李文秀恭恭敬敬地磕了一个头，离开赛马场。\n", environment(ob), ({ob}) );
                ob->move("/d/xingxiu/beijiang");
                message("vision",
                   ob->name() + "从赛马场垂头丧气地走回来。\n", environment(ob), ({ob}) );
                return ::chat();
        }
        return ::chat();
}
