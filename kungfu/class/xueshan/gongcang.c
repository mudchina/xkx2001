//Cracked by Roath
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;

string ask_for_join();

void create()
{
	set_name("昌齐大喇嘛", ({ "changqi lama", "changqi", "lama" }));
	set("long", 
"一个白发喇嘛，平日庙里的杂务均由他处理。据闻他由六岁出家，寻访明师，\n"
"足迹遍布青海、甘肃、和乌丝藏。于二十年前来到本寺，深受尊重。\n");
	set_weight(10000000);
	set("gender", "男性");
	set("age", 60);
	set("attitude", "peaceful");
	set("class","lama");
	set("inquiry",([
                "剃度"  : (: ask_for_join :),
                "出家"  : (: ask_for_join :),
	]));

	set("shen_type", 1);
	set("str", 25);
	set("int", 27);
	set("con", 26);
	set("dex", 25);
	
	set("max_qi", 600);
	set("max_jing", 450);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("dodge", 60);
	set_skill("parry", 50);
	set_skill("staff", 45);
        set_skill("lamaism", 80);
	set_skill("cuff", 40);
	set_skill("necromancy", 60);
	set_skill("jingang-chu", 55);
	set_skill("yujiamu-quan", 50);
	set_skill("shenkongxing", 60);
	set_skill("longxiang-banruo", 50);

	map_skill("force", "longxiang-banruo");
	map_skill("parry", "jingang-chu");
	map_skill("staff", "jingang-chu");
	map_skill("cuff", "yujiamu-quan");
	map_skill("dodge", "shenkongxing");
	
	prepare_skill("cuff", "yujiamu-quan");

	create_family("雪山派", 12, "弟子");

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query("gender") == "女性") {
		command("say 女施主请回吧，本寺不收女徒。");
	return; 
	}
	
	 if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
                return;
        }
	if( ob->query("family/family_name") != "雪山派" 
	&& ob->query("family/family_name") != "血刀门"
	&& ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                        +ob->query("family/family_name")+"高手，本派可不敢收留！");
                return;
        }
        command("say 好吧，我就收下你了，可不要忘了去度母殿敬奉稣油。");
        command("recruit " + ob->query("id"));
}
void init()
{
	::init();
        add_action("do_kneel", "kneel");
}

string ask_for_join()
{
        object me;

        me = this_player();

	if( (string)me->query("class")=="lama" )
                return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？\n";

	if( me->query("family/family_name") != "雪山派"
        && me->query("family/family_name") != "血刀门"
	&& me->query("combat_exp") >= 10000 ) 
                return "这位" +RANK_D->query_respect(this_player()) + "是"
                        +me->query("family/family_name")+"高手，何故来大轮寺出家？\n";

        if( (string)me->query("gender") == "女性" )
                return "阿弥陀佛！善哉！善哉！女施主若真心皈依我佛，可去后山庵里
受戒。\n";

        me->set_temp("pending/join_lama", 1);
        return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n"
;
}
int do_kneel()
{
	object me = this_player();
	if( !me->query_temp("pending/join_lama") )
                return 0;

        message_vision(
                "$N双手合十，恭恭敬敬地跪了下来。\n\n"
                "$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n"
,
                me, this_object() );
	command("smile");
        me->delete_temp("pending/join_lama");
        me->set("class", "lama");
}
