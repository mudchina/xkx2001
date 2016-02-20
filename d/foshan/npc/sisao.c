//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("锺四嫂", ({ "zhong sisao", "zhong", "sisao" }) );
        set("gender", "女性" );
        set("age", 47);
        set("long", 
	     "她头发散乱，满身是血，哭一阵，笑一阵，原来是个疯子。\n");
        set("shen_type", 1);

        set("combat_exp", 100);

        set("attitude", "aggressive");
        set("chat_chance", 10);
        set("chat_msg", ({
                "锺四嫂说道：“凤老爷，你长命百岁，富贵双全啊，我老婆子给你磕头，叫老天爷生眼睛保佑你啊。\n",
		"锺四嫂突然跪倒在地，登登登地磕头。\n",
		"锺四嫂呼叫：“凤老爷，你日进斗金，夜进斗银，大富大贵，百子千孙啊。\n",
		"锺四嫂捶胸大哭，号叫连声：“我那小三宝贝儿啊，你死得好苦啊。老天爷生眼睛，你可没偷人家的鹅吃啊。\n",
                (: random_move :)
        }) );

        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/caidao")->wield();
}
