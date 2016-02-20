//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("凤一鸣", ({ "feng yiming", "feng", "yiming" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", 
	"他是佛山镇上大财主凤天南之子。只见他步履轻捷，脸上英气勃勃，"
	"显是武功不弱。\n");
        set("shen_type", -1);

        set("combat_exp", 20000);

        set("attitude", "heroism");
	set("inquiry", ([
            	"拔凤毛" : "小子，你找死！\n",
		"凤天南" : "便是家父。\n",
                "五虎门" : "那是家父的门派。\n",
	]));

	set("max_neili",500);
	set("neili",500);
	set("jiali",50);
        set_skill("cuff", 30);
	set_skill("wuxing-quan", 30);
	set_skill("force",30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("blade", 30);
	set_skill("wuhu-duanmen", 30);
	set_skill("wuxingbu",70);

	map_skill("cuff", "wuxing-quan");
	map_skill("blade", "wuhu-duanmen");
	map_skill("dodge","wuxingbu");
        map_skill("parry","wuhu-duanmen");

	prepare_skill("cuff", "wuxing-quan");
        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
