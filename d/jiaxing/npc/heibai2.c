//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("黑白子",({ "heibai zi","zi","heibai" }) );
        set("gender", "男性");
        set("age", 55);
	set("long",
		"他眉目清秀，头发极黑而皮肤极白，"
		"似乎一具僵尸模样。\n");
       // set("nickname","");
        set("title","梅庄二庄主");
        set("combat_exp", 47000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 85);
	set_skill("force",85);
        set_skill("parry", 85);
        set_skill("dodge", 85);
	set_skill("hammer",85);

	set("max_neili",450);
	set("neili",450);
	set("jiali",45);

        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/qiping")->wield();
	carry_object("/d/taishan/obj/mianzhao");
}

void init()
{
        object ob;

        ::init();
	add_action("do_suck","suck");
        if (interactive(ob = this_player())) {
                remove_call_out("check_sangong");
                call_out("check_sangong",1,ob);
	}
}

void check_sangong(object me)
{

	if (environment(me)->query("short")!="地牢")
	return;
	if (me->query("max_neili")>0 || !me->query("mz_neili")) {
		command("look "+me->query("id"));
		command("say 你好大的胆子，竟敢冒充任我行！");
		tell_object(me,"黑白子手持棋枰向你挥来，正打中你的脑後！\n\n");
		me->set("startroom","/d/city/kedian");
		me->set_temp("tieslept",0);
		me->move("/d/jiaxing/mzgate1");
		message_vision("黑白子把"+me->name()+"架了出去。\n",
			this_object());
		destruct(this_object());
		return;
	}
	command("say 请任老先生传我神功秘诀。");
	command("bow "+me->query("id"));
	tell_object(me,"你一看黑白子进了屋，突然灵机一动，想起可以吸他(suck heibai zi)"
			"的内力。\n\n");

	me->set_temp("suck/can",1);
	return;
}

int do_suck(string arg)
{
	object me=this_player();
	if (!me->query_temp("suck/can") || 
             !(arg=="heibai zi" || arg=="zi" || arg=="heibai")) 
	return 0;

	if (present("liaokao",me)) {
		write("你得先想办法去掉镣铐。\n");
		return 1;
	}

	message("vision",me->name()+"突然伸手抓住了黑白子的手腕！\n",
		environment(me),({me}));
	write("你突然伸手抓住了黑白子的手腕！\n");
	command("fear");

	me->set("max_neili",me->query("mz_neili"));
	write("你感觉内力从黑白子的手腕「内关」「外关」两处穴道源源流入，"
		"你的内力又恢复了！\n");
	this_object()->unconcious();
	return 1;
}





