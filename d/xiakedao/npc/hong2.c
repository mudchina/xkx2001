//Cracked by Roath
// hong antong 洪安通

inherit NPC;

void create()
{
        set_name("洪安通", ({ "hong antong","hong", "jiaozhu" }));
        set("long",
                "年纪甚老，白鬓垂胸，脸上都是伤疤皱纹，丑陋之极。\n");
        set("gender", "男性");
        set("age", 51);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 31);
        set("int", 32);
        set("con", 29);
        set("dex", 29);
        set("max_qi", 1900);
        set("max_jing", 1800);
        set("neili", 1800);
        set("max_neili", 1800);
        set("combat_exp", 1800000);
        set("shen", -100000);

        set_skill("force", 180);
        set_skill("dulong-dafa", 180);
        set_skill("dodge", 150);
        set_skill("lingshe-shenfa", 160);
        set_skill("strike", 180);
        set_skill("huagu-mianzhang", 180);
        set_skill("parry", 150);
        set_skill("medicine", 120);
        set_skill("yingxiong-sanzhao", 180);
        set_skill("literate", 80);
        set_skill("digging", 180);
        set_skill("kick", 120);
        set_skill("jueming-tui", 150);
        set_skill("finger", 140);

        map_skill("dodge", "lingshe-shenfa");
        map_skill("strike", "huagu-mianzhang");
        map_skill("parry", "huagu-mianzhang");
        map_skill("finger", "yingxiong-sanzhao");

        prepare_skill("finger", "yingxiong-sanzhao");

        create_family("神龙教", 1, "开山祖师");
        setup();

        carry_object("/clone/armor/cloth")->wear();

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

      if (opp = present("su quan", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say 夫人所说甚是有理，但这句似更含深意。");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				command("say 横剑似指剑行之势。。。");

				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}
void attempt_apprentice(object ob)
{
        command ("say 我和夫人再这钻研这武学秘录，别来烦我们，快滚。");
}
