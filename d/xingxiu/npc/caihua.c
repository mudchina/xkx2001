//Cracked by Roath
// npc: /d/xingxiu/npc/caihua.c
// Jay 5/13/96

inherit NPC;

void create()
{
        set_name("采花子", ({ "caihua zi", "caihua" }) );
        set("gender", "男性" );
//	set("title", "星宿淫贼");
	set("nickname", "赛昆仑");
        set("age", 38);
        set("long", 
             "采花子是星宿派的一个小喽罗，武功虽不好，但生性淫邪，"
	     "经常奸淫良家妇女，是官府通缉的犯人，故而星宿派名义上"
	     "也不承认有这个弟子。\n");
        set("str", 25);
        set("dex", 30);
        set("con", 17);
        set("int", 15);
        set("shen_type", -1);

        set_skill("unarmed", 20);
	set_skill("force", 50);
        set_skill("dodge", 95);
	set_skill("zhaixinggong", 95);
	map_skill("dodge","zhaixinggong");

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        create_family("星宿派", 5, "弟子");

        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "我也记不清我姓甚名谁了，江湖朋友送我雅号采花子。",
            "采花" : "那可是学问，我不能随便教。",
       ]) );

        setup();
        carry_object("/d/city/obj/pink_cloth")->wear();
        add_money("silver", 10);
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
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (myfam && myfam["family_name"] == "星宿派") 
          command("say 我昨天从山下捉了个小妞来，水灵极了，就关在我的逍遥洞里"
		+"，你要不要进去试试？");
	me->set_temp("marks/花",0);

}


void attempt_apprentice(object ob)
{
	command("hehe");
	command("say 想学我的采花神技？没门儿！");
	return;
}

int accept_object(object me, object obj)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (!myfam || myfam["family_name"] != "星宿派") 
	  command("say 少跟我套近乎。");
	else {
	  if (!obj->query("money_id")) {
 	    if (me->query("gender")=="女性") {
	  	command("kiss " + me->query("id"));
		command("say 想不到师姐也有这个爱好。");
	    }
	    else {
		command("bow " + me->query("id"));
                command("say 多谢师兄。");
		call_out("destroy_it", 1, obj);
            }
            command("say 对不起，那小妞昨天晚上被不知道哪个混蛋救走了，不过"
			+ "你可以进洞睡一觉。");
	    me->set_temp("marks/花", 1);
          }
          else {
		command("thank " + me->query("id"));
		command("say 钱我有的是，你还是给我点别的什么吧。");
          }
        }
	call_out("destroy_it", 1, obj);
        return 1;
}
void destroy_it(object ob)
{
	if(ob)
        destruct (ob);
}
