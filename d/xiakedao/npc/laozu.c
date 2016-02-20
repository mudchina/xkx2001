//Cracked by Roath
inherit NPC;
int auto_perform();
void create()
{
        set_name("血刀老祖", ({ "xuedao laozu", "xuedao", "laozu" }));
        set("long", 
"这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。 \n");
        set("gender", "男性");
        set("age", 80);
        set("attitude", "friendly");
        set("class","lama");

        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 1800);
        set("max_jing", 950);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("apply/armor", 100);

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("blade", 150);
        set_skill("lamaism", 130);
        set_skill("cuff", 150);
        set_skill("yujiamu-quan", 150);
        set_skill("xue-dao", 150);
        set_skill("xueshitiao", 150);
        set_skill("shenkongxing", 150);
        set_skill("longxiang-banruo", 150);

        map_skill("force", "longxiang-banruo");
        map_skill("blade", "xue-dao");
        map_skill("dodge", "xueshitiao");
        map_skill("parry", "xue-dao");
        map_skill("cuff", "yujiamu-quan");


        prepare_skill("cuff", "yujiamu-quan");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );   
        set("inquiry", ([
        "血刀门" : "咱们这一派是西藏青教中的一支，叫做血刀门。你祖师爷\n"
                   "爷我是这一门的第四代掌教，你好好学功夫，第五代掌教就说不定落在你身上。\n",
        "血刀" : "这柄宝刀每奉月圆之际，须割人头相祭，否则锋锐顿减，与刀主不利。\n",
        "血刀密藉" : "找宝象他们要去。\n",
        ]) );

        create_family("血刀门", 4, "掌门人");

        set("blade_count", 1);
        setup();
        carry_object("/d/qilian/obj/lamajiasha")->wear();
        carry_object("/clone/weapon/mudao")->wield(); 
}
void init()
{
        object me = this_player();

        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

void greeting(object me)
{     object obj = this_object();
      object opp;
	int maxqi, maxjingli;
	int qi, jingli;
	qi = obj->query("max_qi");
	jingli = obj->query("max_jingli");

      if (opp = present("jiumozhi", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say 缦胡缨是说他头上所带之缨并不精致，胡乃胡乱之意。");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );

				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}
void attempt_apprentice(object ob)
{
        command ("say 快滚。");
}
