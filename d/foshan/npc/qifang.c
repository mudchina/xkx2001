//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("戚芳", ({ "qi fang", "qi", "fang" }) );
        set("gender", "女性" );
        set("age", 17);
        set("long", 
	     "一个可爱的农村姑娘，圆圆的脸蛋，一双大眼黑溜溜的。\n");
        set("shen_type", 1);

        set("combat_exp", 15000);

        set("attitude", "friendly");
	set("inquiry", ([
            "空心菜" : "后面菜园子里就有。\n",
	    "戚长发" : "他是我爹。\n",
		"大黄" : "它就站在我们家院外。\n",
		"师兄" : "他被关到大牢里了。\n",
       ]) );

	set("max_neili",500);
	set("neili",500);
	set("jiali",30);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
	set_skill("force",30);
        set_skill("parry", 30);
        set_skill("sword", 30);
	set_skill("tangshi-jian",30);
	map_skill("sword","tangshi-jian");

        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/zhujian")->wield();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
   if (random(3)>1) {
	command("say 这位"+RANK_D->query_respect(me)+"，为了买新衣服进城，我爹要把大黄卖了。");
	command("cry " + me->query("id"));
	command("say 你能帮我想想办法吗？");
   }
}

int accept_object(object me, object obj)
{
	if (obj->query("armor_type")=="cloth") {
		if (obj->query("id")=="pink cloth") {
		     command("ah");
		     command("thank "+me->query("id"));
		     command("say 可惜我师兄不在。");
		     command("whisper "+me->query("id")+" 从前我常和师兄在村子"
			+ "南面的小山上玩。到了那拨开杂草(bocao)就能看见一个山洞。"
			+ "那里除了我和我师兄谁也找不到的。");
		     me->set_temp("qi/bocao",1);
		     return 1;
                 }
		 command("thank "+me->query("id"));
                 command("say 可惜这不是我爱穿的衣服。");
		 return 0;
	}
	if (obj->query("id")=="tangshi xuanji") {
                     command("ah");
                     command("cry");
		     command("say 这是我和我师兄从前在一起时我夹绣样用的书。");
		     remove_call_out("destbook");
		     call_out("destbook",10,obj);
		     remove_call_out("wet");
                     call_out("wet",30, me);
		     return 1;
         }
	return 0;
}

void destbook(object book){
	destruct(book);
	command("nocry");
}

void wet(object me){
	object book;
	command("cry");
	if (me->query_temp("qi/bocao") && objectp(present("qi fang", environment(me)))) {
	  	tell_object(me,"你突然发现戚芳的眼泪滴到「唐诗选辑」上之后，那书上显出些字迹。\n");
                tell_object(me,"你趁戚芳不注意又把「唐诗选辑」偷了回来。\n");
		book = new(__DIR__"obj/tangshi2");
		book->move(me);
		me->set_temp("qi/tangshi",1);
	}
} 
