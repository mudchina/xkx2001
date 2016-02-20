//Cracked by Roath
// dayou.c 

inherit NPC;

void create()
{
	set_name("陆大有", ({ "lu dayou", "lu", "dayou" }));
	set("nickname", "六猴儿");
	set("long", 
"陆大有身材很瘦，又长的尖嘴猴腮的，但别看他其貌不扬，他在\n"
"同门中排行第六，是华山派年轻一代中的好手。\n");
	set("gender", "男性");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);
	
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 20);
	set("combat_exp", 65000);
	set("score", 5000);

	set_skill("force", 65);
	set_skill("zixia-gong", 65);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("sword", 65);
	set_skill("huashan-jianfa", 65);
	set_skill("strike", 60);
	set_skill("hunyuan-zhang", 60);
	set_skill("huashan-shenfa", 65);
	set_skill("cuff", 60);
	set_skill("pishi-poyu", 60);
	set_skill("ziyin-yin", 50);
	set_skill("zhengqi-jue", 50);

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

void init()
{
	object me = this_object();

	::init();

	remove_call_out("location");
	call_out("location", 1, me);
}

int location(object me)
{
	object ob;

	if ( interactive(ob=this_player()) && living(me)
	&& environment(me)->query("short")!="后院" ) {
		message_vision("$N匆匆忙忙地离开了。\n", me);
		me->move("/d/huashan/houyuan");
	}

	return 1;
}