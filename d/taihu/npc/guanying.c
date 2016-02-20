//Cracked by Roath
// Npc: 
// Date: 

inherit NPC;

string ask_for_ruhuo();
int do_decide();
void create()
{
	set_name("陆冠英", ({
		"lu guanying",
		"guanying",
		"lu",
	}));
	set("title", "归云庄少庄主");
	set("long",
		"他是归云庄少庄主陆冠英。他肩宽背阔，躯体甚是壮健，\n"
		"但行动之间温文尔雅，谦恭有礼，一派世家子弟风范。\n"
		"传闻他就是太湖群盗的首领，不知是真是假。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 23);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 100000);
	set("score", 100);
	

	set_skill("force", 60);
	set_skill("hunyuan-yiqi", 60);
	set_skill("dodge", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("cuff", 60);
	set_skill("luohan-quan", 60);
	set_skill("parry", 60);
	set_skill("blade",60);
	set_skill("cibei-dao",60);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");

        set("inquiry",([
                "归云庄"  : (: ask_for_ruhuo :),
        ]));

	setup();

        carry_object("/d/taihu/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

void init()
{
        add_action("do_decide", "decide");
}

string ask_for_ruhuo()
{
        object me = this_player();    
    	mapping myfam = (mapping)me->query("family");

	if (  present("shu xin", this_player()) )
		return RANK_D->query_respect(me) + "你怎么现在还没去归云庄？\n";

      if ( myfam ) {
	if (  myfam["family_name"] == "桃花岛"  )
		return RANK_D->query_respect(me) + "既然与我们志同道合，以后不妨多切磋切磋\n";
      }
	me->set_temp("pending/ruhuo", 1);
        return "归云庄就是在下居处，如果"+RANK_D->query_respect(me)+"有意(decide)，我可修书一封代为引荐。\n";
}

int do_decide()
{
        object ob;
        if( !this_player()->query_temp("pending/ruhuo") )
                return 0;

        message_vision(
                "$N双手抱拳，道：有劳少庄主费心了。\n", this_player());
        this_player()->delete_temp("pending/ruhuo");
//RYU!!! DO NOT DELETE PLAYER'S CLASS!!!!!!!! 
	ob=new("/d/taihu/obj/shuxin");
	ob->move(this_player());

	message_vision("陆冠英说道：好！\n陆冠英给$N一封书信。\n", this_player());

	message_vision("陆冠英说道：这位"+RANK_D->query_respect(this_player())+"请先到敝庄盘恒数日，以后再图相叙\n",this_player());
	return 1;
}
