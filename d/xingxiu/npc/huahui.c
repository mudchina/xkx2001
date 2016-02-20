//Cracked by Roath
// npc: /d/xingxiu/npc/huahui.c
// Jay 6/30/96

inherit NPC;

void create()
{
        set_name("华辉", ({ "hua hui", "hua" }) );
        set("gender", "男性" );
        set("age", 68);
	set("nickname","一指震江南");
        set("long", 
            "他身披白色罩袍，满脸都是鲜血，白袍上也血迹淋漓，"
	    "身形高大之极，至少比常人高了五尺。"
	    "十根指甲比手指还长，满手也都是鲜血。\n");
        set("str", 35);
        set("dex", 30);
        set("con", 27);
        set("int", 25);
        set("shen_type", 0);

        set_skill("unarmed", 100);
        set_skill("dodge", 95);
	set_skill("hammer",100);
	set_skill("parry",100);
        set("combat_exp", 200000);

        set("attitude", "heroism");

        set("max_qi", 1000);
        set("eff_qi", 1000);
        set("qi", 1000);
        set("max_jing", 600);
        set("jing", 600);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 80);
 
        set("inquiry", ([
            "瓦耳拉齐" : "既然你猜到了我就不瞒你了，我就是。",
	    "车尔库" : "他这个浑蛋抢走了我的雅丽仙。",
	    "马家骏": "他是我的逆徒，你可不要相信任何人。",
	    "雅丽仙": "我得不到她，车尔库也别想。",
	    "name" : "我叫瓦耳...我是江南人氏，姓华名辉。",
	    "here" : "这里就是高昌迷宫。",
 	    "高昌迷宫" : "这里就是。",
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
             "华辉呻吟了一声：我身上中了毒针，要有一只雪莲就好了。\n",
        }) );
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/liuxing")->wield();
}

int accept_object(object who, object ob)
{
    object hammer;

     if((string)ob->query("name")=="雪莲") {
           if( who->query_temp("marks/xuelian") ) {
                 write("华辉笑了笑，说：你刚给过我一只，这只你自己留着吧。\n");
		 command ("give xuelian to "+who->query("id"));
                 return 1;
           }
           else {
                 command("say 多谢这位" + 
                       RANK_D->query_respect(who) + "相救。");
		if (who->query_skill("hammer",1)<15) {
		 	command("say 我看你是个学武之人，就教你几"+
		"招功夫吧。若是教你独指点穴刀法拳法，至少也得半年才能奏"+
		"效。我教你一招流星锤吧。");
		who->improve_skill("hammer",226);	
		}
		else if (present("liuxing chui", this_object())){
		command("say 我本有意教你一招流星锤，可惜阁下锤法已属不俗。");
//		hammer = new(__DIR__"obj/liuxing");
//		hammer->move(this_object());
		command("say 送你一副流星锤吧。");
		command ("give chui to " + who->query("id"));		
		who->set_temp("marks/xuelian",1);
                  return 1;
		}
		else
		command("joythank " + who->query("id"));
		return 1;
            }
      }
    return 0;
}

 

   
