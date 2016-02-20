//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("袁紫衣", ({ "yuan ziyi", "yuan", "ziyi" }) );
        set("gender", "女性" );
        set("age", 17);
        set("long", 
	"她身材婀娜，但面露寒色，淡淡的哀愁锁在眉头。一张瓜子脸，双眉修长，皮肤虽然"
	+ "微黑，却掩不了姿形秀丽，容光照人。\n");
        set("shen_type", 1);
	set("title","九个半门派总掌门");
	set("horse_count",2);

        set("combat_exp", 500000);

        set("attitude", "peaceful");
	set("inquiry", ([
		"name" : "我叫圆，嗯，袁紫衣。\n",
		"圆性" : "你，你到底是谁？\n",
		"凤天南" : "干嘛问我这个？自己去佛山打听。\n",
		"九个半门派" : "有少林韦陀门门，八仙剑，嗯，我也记不住啦。\n",
		"掌门" : "本姑娘是十二门派的掌门人，正要进京参加福大帅的掌门人大会。\n",
		"掌门人" : "本姑娘是十二门派的掌门人，正要进京参加福大帅的掌门人大会。\n",
		"掌门人大会" : "本姑娘正要去。\n",
		"福大帅" : "一个满洲的官，叫福康安，听说是皇上的私生子。\n",
		"福康安" : "一个满洲的官，听说是皇上的私生子。\n",
		"赵三叔" : "他是红花会的大英雄，千臂如来赵半山。\n",
		"赵半山" : "他是赵三叔。\n",
		"红花会" : "怎么，你是朝廷鹰犬吗？！\n",
		"赵三哥" : "好啊，你敢占我便宜！\n",
		"胡斐" : "他，他，他，。。。\n",
		"白龙马" : "那可是文四婶的宝马，行走如飞，还会游水呢。\n",
		"文四婶" : "就是红花会的大英雄，鸳鸯刀骆冰。\n",
		"骆冰" : "就是文四婶。\n",
		"文四叔" : "他是红花会的大英雄，奔雷手文泰来。\n",
		"文泰来" : "他是文四叔。\n",
	]));

	set("max_neili",1400);
	set("neili",1400);
	set("max_qi", 900);
	set("qi", 900);
	set("jing", 900);
	set("max_jing", 900);
	set("jiali",100);
        set_skill("force", 120);
        set_skill("linji-zhuang", 120);
        set_skill("strike", 120);
        set_skill("jinding-zhang", 120);
        set_skill("finger", 120);
        set_skill("tiangang-zhi", 120);
        set_skill("whip", 120);
        set_skill("feifeng-bian", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("zhutian-bu", 120);
        map_skill("force", "linji-zhuang");
	map_skill("whip","feifeng-bian");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");

        setup();
        carry_object(__DIR__"obj/ziyi")->wear();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()
	&& environment(this_object())->query("short") == "茶亭" ) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}

void greeting(object me)
{
	object ring;
	object h;
    if (!me->query_temp("ziyi-zhihuan") && !ring = present("zhi huan",me)){
       command("say 本姑娘在这里休息，别来打搅！");
       command("kick " + me->query("id"));
       message("vision", me->name() +"被袁紫衣一脚踢出门外。\n",
                environment(me), ({me}));
       me->move("/d/foshan/road3");
       message("vision", me->name() +"被人从茶亭里踢了出来。\n", 
                environment(me), ({me}));
	if (h = me->query("rided")) h->move("/d/foshan/road3");
	return;
    }
	else if (me->query_temp("ziyi-zhihuan")) {
	command("say 你找到那刀谱了吗？对了，我的那个朋友姓胡。");
	}
	else {
	command("say 哼，你就是赵三叔说的那个英雄吗？怎么拿人家的指环？");
	message_vision("$N趁$n一不留神，把指环抢了过去。\n",this_object(),me);
	command("xixi");
	destruct(ring);
	command("say 赵三叔老夸你了不起，文四婶便让我这次来中原把她的白龙马带给你。");
	command("say 可我不信你真那么能干，除非你帮我找到我的一个朋友家传刀谱的头两页。");
	me->set_temp("ziyi-zhihuan",1);
	}
}

int accept_object(object me, object obj)
{
	object horse, *obs;

	if ((string)obj->query("id") != "hujia daofa") 
		return 0;

	if (!me->query_temp("ziyi-zhihuan") ){ 
	command("? " + me->query("id"));
	return 0;
	}

	obs = filter_array(children("/clone/horse/bailong.c"), (: clonep :));
        if (sizeof(obs) != 0){

//	if (query("horse_count") < 1) {
	command("thumb " + me->query("id"));
        command("say 可惜有人比你先找到刀谱了。");
	return 0;
	}
	command("ah");
	command("thumb " + me->query("id"));
	command("say 果然不简单，来，我这就把白龙马给你。");
	horse = new("/clone/horse/bailong");
	horse->move(environment(me));
	horse->set_lord(me);
	horse->set_leader(me);
	message_vision("袁紫衣交给$N一匹白龙马。\n", me);
	command("say 这可是文四婶的宝马，行走如飞，还会渡河(duhe)呢。");
	add("horse_count", -1);
	me->delete_temp("ziyi-zhihuan");
	return 1;
}
