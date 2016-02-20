//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("凤天南", ({ "feng tiannan", "feng", "tiannan" }) );
        set("gender", "男性" );
	set("title","五虎门掌门人");
	set("nickname","南霸天");
        set("age", 55);
        set("long", 
	"此人上唇留着两撇花白小髭，俨然一个养尊处优的大乡绅模样。\n"
	"但他脚步凝稳，双目有威，多半武功高强。\n");
        set("shen_type", -1);

        set("combat_exp", 250000);

        set("attitude", "heroism");
	set("inquiry", ([
            	"拔凤毛" : "小子，你找死！\n",
		"凤一鸣" : "便是犬子。\n",
                "五虎门" : "当年老夫全仗一根熟铜棍，打遍岭南无敌手，才创下这五虎门。\n",
	]));

	set("max_neili",1000);
	set("neili",1000);
	set("jiali",100);
        set_skill("cuff", 80);
	set_skill("wuxing-quan", 80);
	set_skill("force",80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("club", 80);
	set_skill("wuhu-gun",80);
	set_skill("wuxingbu",70);
	map_skill("club","wuhu-gun");
	map_skill("cuff", "wuxing-quan");
	map_skill("dodge","wuxingbu");
        map_skill("parry","wuhu-gun");

	prepare_skill("cuff", "wuxing-quan");
        create_family("五虎门", 1, "掌门人");


        setup();
        carry_object("/d/dali/obj/zipao")->wear();
	carry_object("/clone/weapon/jingun")->wield();
}

void attempt_apprentice(object ob)
{
        command("shake");
	command("say 本门人手已经够了，老夫不想收徒找累了。");
}

void unconcious()
{
	object me = this_object();
	object ring;
        message_vision("\n$N脸露苦笑，忽然抢过一把单刀，说道：“一人做事一人当，凤某不敢再活，但求饶了小儿性命。”\n",
		me);
	message_vision("眼看$N单刀横颈，就要血溅当场，忽听得嗖得一声，一件暗器"+
	"从殿门外飞射进来，把单刀打歪。\n",me);
	message_vision("众人一愣神之际，$N乘机逃走了。\n",me);
	ring = new(__DIR__"obj/zhihuan");
	ring->move(environment(me));
        destruct(me);
}

void die()
{
        object me = this_object();
        object ring;
        message_vision("\n$N脸露苦笑，忽然抢过一把单刀，说道：“一人做事一人当，凤某不敢再活，但求饶了小儿性命。”\n",
                me);
        message_vision("眼看$N单刀横颈，就要血溅当场，忽听得嗖得一声，一件暗器"+
        "从殿门外飞射进来，把单刀打歪。\n",me);
        message_vision("众人一愣神之际，$N乘机逃走了。\n",me);
        ring = new(__DIR__"obj/zhihuan");
        ring->move(environment(me));
        destruct(me);

}

