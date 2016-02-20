//Cracked by Roath
// hai.c 海公公
// Jay 4/6/96

inherit NPC;

string ask_for_zigong();

void create()
{
        set_name("海老公", ({"hai laogong", "hai", "laogong"}));
        set("title", "御膳房总管");
        set("long",
                "他是御膳房太监海大富，乔装改扮成商人模样出京寻欢作乐。他长得既像老头又像老太太，咳个不停。\n"
        );

        set("gender", "无性");
	set("class","eunach");
        set("attitude", "heroism");

        set("inquiry",([
                "自宫"  : (: ask_for_zigong :),
        ]));

        set("age", 60);
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 100);
        set("combat_exp", 25000);
        set("score", 100);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 70);
        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("damo-jian", 70);
	set_skill("shaolin-shenfa", 70);

        map_skill("dodge", "shaolin-shenfa");
        map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	map_skill("force", "hunyuan-yiqi");

        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
		"海老公咳嗽了两声。\n",
		"海老公从怀中掏出一个小药瓶，用小手指甲挑了一撮白色的药面到酒袋中，把酒喝了下去。\n",
		"海老公说：这药可不敢多吃，吃多了会送命的。\n",
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/city/npc/obj/jiudai");
	carry_object("/d/xingxiu/obj/huashi");
        add_money("silver", 50);
}

void init()
{
	::init();
        add_action("do_decide", "decide");
}

string ask_for_zigong()
{
        object me;

        me = this_player();

        if( (string)me->query("gender")=="无性" )
                return "你我同是阉人，何必开如此无聊的玩笑？\n";

        if( (string)me->query("gender") == "女性" )
                return "我虽已废，但一样可以给你这个小美人带来快乐，要不要试试？\n";
        if ((int)me->query_str() > 28 )
                return "这位好汉过于粗壮，自宫有碍观瞻，不妥，不妥。\n";
        if ((int)me->query("age") < 16 )
                return "嘿嘿…自宫？你那玩艺还没长出来呢！\n";

       me->set_temp("pending/zigong", 1);
        return "自宫？这位公子相貌堂堂，何必... 我真希望能有你的那个。自宫之后，不可后悔，你若决心已定(decide)，告诉我。\n";
}

int do_decide()
{
        if( !this_player()->query_temp("pending/zigong") )
                return 0;

        message_vision(
                "$N一咬牙，褪下中衣。（女玩家闭眼！）\n\n"
                "$n伸出长剑插到$N两腿之间，飞速一剜，……\n\n"
                "$N顿时惨叫一声昏了过去……\n\n",
                this_player(), this_object() );
        command("chat 嗨……");
        command("hehe");
        this_player()->delete_temp("pending/zigong");
        this_player()->set("gender","无性");
//        this_player()->set("class", "eunach");
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
	this_player()->set("per",(this_player()->query("per")+30)/2);
        this_player()->unconcious();
        return 1;
}

