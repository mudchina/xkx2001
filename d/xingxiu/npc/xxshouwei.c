//Cracked by Roath
// tianlang.c 天狼子
inherit NPC;
void create()
{
	set_name("星宿守卫", ({ "xingxiu shouwei", "shouwei" }));
	set("long", 
		"他是星宿派的普通弟子。\n"
		"他身形稍长，脸色严肃。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 500000);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("huagong-dafa", 100);
	set_skill("dodge", 100);
	set_skill("zhaixinggong", 100);
	set_skill("strike", 100);
	set_skill("chousui-zhang", 100);
	set_skill("poison", 100);
	set_skill("parry", 100);
	set_skill("staff", 100);
  	set_skill("tianshan-zhang", 100);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "chousui-zhang");

	create_family("星宿派", 3, "弟子");
        set("inquiry",
           ([
           "拜帖" : "我们武林中人出门拜会天下同道，拜帖是基本的礼节．",
           ]));
	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
}
void init()
{
}

int accept_object(object who,object ob)
{
        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

        if (  (string)ob->query("name") == "拜帖")
           {    tell_object(who,"星宿守卫看了一下拜帖，又看了你两眼。\n");
                if(who->query("name")!=ob->query_temp("owner"))
                        return notify_fail("星宿守卫对你大喝：＂这不是你自己的拜帖，你到底有何企图！＂\n");
                else
                {       switch(random(4)){
                        case(0):
                                tell_object(who,"星宿守卫对你说道：＂本派今日不欢迎拜访，你还是请回吧。＂\n");
                                break;
                        case(1):
                                tell_object(who,"星宿守卫爱理不理的说：＂大爷我今天不高兴传话，你过两天再来。＂\n");
                                break;
                        case(2):
                                tell_object(who,"星宿守卫对你说道：＂阁下既然是" + ob->query_temp("fam") +"的朋友，那就请便吧。＂ \n");
                                who->set_temp("xx_pass");
                                break;
                        case(3):
                                tell_object(who,"星宿守卫尊敬的对你说道：＂" + ob->query_temp("fam") + "名动天下，贵客请自便吧。＂ \n");
                                who->set_temp("xx_pass");
                                break;
                        case(4):
                                tell_object(who,"星宿守卫恶狠狠的对你说道：＂你们" + ob->query_temp("fam") +"和我们结下的梁子还没清，今天就拿你开刀！＂ \n");
                                kill_ob(who);
                                ob->stat_busy(1);
                                break;
                        }
                  }
         }
         return 1;

}

                

