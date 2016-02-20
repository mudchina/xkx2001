//Cracked by Roath
// d/emei/npc/guard.c 文菲
// Shan 96/07/09

inherit NPC;
string ask_me(string name);

void create()
{
	set_name("文菲", ({"wenfei", "wen fei", "guard"}) );
	set("rank_info/respect", "小师太");
	set("gender", "女性" );
	set("age", 16+random(6));
	set("long",
	  "这是个年龄不大，眉清目秀的小师太，在这里看墓。\n");
	set("attitude", "friendly");
        set("shen_type", 1);
        set("class", "bonze");

        set("str", 20);
        set("int", 18);
        set("con", 24);
        set("dex", 22);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);

	set("combat_exp", 2000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 3);

        create_family("峨嵋派", 5, "弟子");

	set("book_count", random(2));
	set("jing_count", random(3)==2);
	set("xiang_count", 10);

        set("inquiry", ([
	    "here" : "这里就是本派祖师郭襄女侠的墓了。\n",
	    "name" : "我是文菲，这几天师父派我在这里看守打扫墓地。\n",
	    "出去" : "啊，从后面出去，沿着山路走一会儿，就到九十九道拐，从那里可以下山。\n",
	    "秘籍" : "你想借什么书？我不知道我这里有没有。\n",
	    "扫墓" : "啊，太好了，你可以帮我把墓旁的草清理一下。\n",
	    "郭襄" : "这里就是本派祖师郭襄女侠的墓了。\n",
	    "墓" : "这里就是本派祖师郭襄女侠的墓了。\n",
	    "周芷若" : "周师叔教了我几招新功夫，这几日不知躲到哪里去了。\n",
	    "九阴真经" : (: ask_me, "jing" :),
	    "基本爪法" : (: ask_me, "book" :),
	    "上香" : (: ask_me, "xiang" :),
	    "敬香" : (: ask_me, "xiang" :),
        ]));

	set("chat_chance", 2);
        set("chat_msg", ({
                "文菲道：不知接班的师姐什么时候来呢？\n", 
                "文菲走到门口，看了看天，又回到石几前坐下读书。\n", 
		"文菲放下手中的书，闭上眼睛想了想，又伸出手来比划了两下。\n", 
		"文菲合上书，走到书架前，换了一本书，回来接着读了起来。\n",
        }) );

        setup();
        
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

string ask_me(string name)
{
	object me = this_player();
        object book;
        object jing;
	object incense;

	if ( name == "book" ) {
        /*	if (query("book_count") < 1)
                	return "那本「基本爪法」刚才有人借去看了，你问他借吧。";
        	add("book_count", -1);
        	book = new(__DIR__"obj/claw-book");
        	book->move(this_player());
        	return "这本「基本爪法」我现在不用，你可以拿去看看。";
	*/
		return "我怎么会有这书？";
	}
	if ( name == "jing" ) {
	/*		if ((int)me->query_temp("visit_tomb") < 10) 
			return "那是本派郭师祖留下来的，不能随便借给人看。";
		if (query("jing_count") < 1)
			return "我从周师叔那里抄了一些「九阴真经」上的功夫，刚刚借给人拿去看了，不知什么时候还回来。";
		add("jing_count", -1);
        	jing = new(__DIR__"obj/jiuyin-jing1");
        	jing->move(this_player());
        	return "好吧，我就借你这本「九阴真经」，是我从周师叔那里抄的。看完还给我就行了。";
	*/
		return "我怎么会有这书？";
	}
	if ( name == "xiang" ) {
		if (query("xiang_count") < 1)
			return "我这里没有了，你下次来帮我带点吧？。";
		add("xiang_count", -1);
        	incense = new(__DIR__"obj/incense");
        	incense->move(this_player());
        	return "这里有只香，你拿去吧。";
	}
}

