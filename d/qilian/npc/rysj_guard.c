//Cracked by Roath
// maskman.c 蒙面人

inherit NPC;

void create()
{
	int level;

	seteuid(getuid());
	set_name("日月神教卫士", ({ "rysj weishi","weishi","shi" }) );
	set("gender", "男性");
	set("age", 25+random(25));
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("str", 25);
	set("long",
		"这家伙黑巾蒙面，胸口绣有火焰标记，双眸均有杀气，时不时低沉地阴笑。\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");

	setup();

	level = 150 + (-1)^random(2) * random(100);
	if ( level < 100 ) level = 100;

	set("combat_exp", level*level*level/10);

	switch( random(4) )
                {
                case 0:
                       set_skill("cuff", level);
                       set_skill("yujiamu-quan", level);
                       map_skill("cuff", "yujiamu-quan");
                       prepare_skill("cuff", "yujiamu-quan");
                       set_skill("hand", level);
                       set_skill("dashou-yin", level);
                       map_skill("hand", "dashou-yin");
                       prepare_skill("hand", "dashouyin");
		       set_skill("force", level);		
                       set_skill("longxiang-banruo", level);                                set_skill("longxiang-banruo", level);
                       map_skill("force", "longxiang-banruo");
		       set_skill("dodge", level);
                       set_skill("shenkongxing", level);
                       map_skill("dodge", "shenkongxing");
		       set_skill("parry", level);	
                       switch( random(2) ) {
                          case 0:
                               set_skill("staff", level);
                               set_skill("jingang-chu", level);
                               map_skill("staff", "jingang-chu");
                               map_skill("parry", "jingang-chu");
                               carry_object("/clone/weapon/tiezhang")->wield();
                               break;
                          case 1:
                               set_skill("sword", level);
                               set_skill("mingwang-jian", level);
                               map_skill("sword", "mingwang-jian");
                               map_skill("parry", "mingwang-jian");
                               carry_object("/clone/weapon/changjian")->wield();
                               break;
			}
                	break;

                case 1:
                        set_skill("strike", level);
                      	set_skill("chousui-zhang", level);
                        map_skill("strike", "xingxiu-duzhang");
                        prepare_skill("strike", "xingxiu-duzhang");
                        set_skill("claw", level);
                        set_skill("sanyin-zhua", level);
                        map_skill("claw", "sanyin-zhua");
                        prepare_skill("claw", "sanyin-zhua");
                        set_skill("huagong-dafa", level);
			set_skill("force", level);
                        map_skill("force", "huagong-dafa");
                        set_skill("staff", level);
                        set_skill("tianshan-zhang", level);
                        map_skill("staff", "tianshan-zhang");
			set_skill("dodge", level);
                        set_skill("zhaixinggong", level);
                        map_skill("dodge", "zhaixinggong");
			set_skill("parry", level);
                        map_skill("parry", "tianshan-zhang");
                        carry_object("/clone/weapon/tiezhang")->wield();
                        break;

                case 2:
                        set_skill("strike", level);
                        set_skill("strike", level);
                        set_skill("lingshe-shenfa", level);
		        set_skill("dodge", level);
                        map_skill("dodge", "lingshe-shenfa");
                        set_skill("huagu-mianzhang", level);
                        map_skill("strike", "huagu-mianzhang");
                        prepare_skill("strike", "huagu-mianzhang");
                        set_skill("kick", level);
                        set_skill("jueming-tui", level);
                        map_skill("kick", "jueming-tui");
                        prepare_skill("kick", "jueming-tui");
			set_skill("force", level);
                        set_skill("dulong-dafa", level);
                        map_skill("force", "dulong-dafa");
                        set_skill("ruyi-gou", level);
                        map_skill("hook", "ruyi-gou");
                        set_skill("hook", level);
                        carry_object("/clone/weapon/hook")->wield();
                        break;

                case 3: 
                        set_skill("strike", level);
                        set_skill("hamagong", level);
                        set_skill("hand", level);
                        set_skill("shexing-diaoshou", level);
                        map_skill("hand", "shexing-diaoshou");
                        if ( level > 100 ) {
                                map_skill("strike", "hamagong");
                                prepare_skill("strike", "hamagong");
                        }
                        else {
                                prepare_skill("hand", "shexing-diaoshou");
                        }
			set_skill("force", level);
                        map_skill("force", "hamagong");
                        set_skill("staff", level);
                        set_skill("lingshe-zhang", level);
                        map_skill("staff", "lingshe-zhang");
			set_skill("parry", level);
                        map_skill("parry", "lingshe-zhang");
			set_skill("dodge", level);
                        set_skill("chanchubu", level);
                        map_skill("dodge", "chanchubu");
                        carry_object("/clone/weapon/tiezhang")->wield();
                        break;
                }

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		"蒙面使者大声说道：神教一统江湖指日可待，你可别不识时务，到时后悔莫及！\n",
		"蒙面使者桀笑说道：神教东方教主天下无敌，你简直是膛臂挡车，自取灭亡！\n",
		"蒙面使者低沉说道：神教东方教主乃千古第一人，识相的赶快向本神教投诚！\n",
		"蒙面使者高声呐喊：日出东方、唯我不败、文成武德、泽被苍生！\n",
		"蒙面使者高声呐喊：熊熊圣火、光耀神州、一统江湖、天下归诚！\n",
	}) );

	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", random(10));
}
