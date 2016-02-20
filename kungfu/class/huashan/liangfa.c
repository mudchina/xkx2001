//Cracked by Roath
// liangfa.c 梁发

inherit NPC;

void create()
{
	set_name("梁发", ({ "liang fa", "liang", "fa" }));
	set("long", 
"梁发在华山弟子中排行第三，为人耿直。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 21);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 750);
	set("max_neili", 750);
	set("jiali", 20);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("zixia-gong", 50);
	set_skill("dodge", 55);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("huashan-jianfa", 60);
	set_skill("strike", 55);
	set_skill("hunyuan-zhang", 55);
	set_skill("huashan-shenfa", 55);
	set_skill("cuff", 60);
        set_skill("pishi-poyu", 60);
	set_skill("ziyin-yin", 45);
        set_skill("zhengqi-jue", 45);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("华山派", 14, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

int accept_object(object me, object obj)
{

	object ob = this_player();

	if ( obj->query("id") == "zhengqi book" || obj->query("id") == "sword book" 
	|| obj->query("id") == "ziyin book" ) {
		if ( !ob->query_temp("huashan/书") ) {
                	command( "shake" );
			command( "say 你又没有从书院里拿书出来，还我这书干吗？");
           		return 0;
		}
		else {
			command( "nod" );
			command( "say 好吧，你可以进去了。" );
			ob->delete_temp("huashan/书");
			remove_call_out("destroy_it");
           		call_out("destroy_it", 1, obj);
			return 1;
		}
	}
	else if ( obj->query("money_id") ) {
		command( "haha" );
		command( "say 难得这位"+RANK_D->query_respect(ob)+"如此慷慨，我便收下做为书院的经费啦。" );
		return 1;
	}
	else {
		command( "hmm" );
		command( "say 这东西吗还是你自个儿留下来用吧。" );
                return 0;
	}

}

void destroy_it(object obj)
{
	destruct(obj);
}
