//Cracked by Roath
// yudaiyan.c 俞岱岩
// xQin 12/00
// xQin 04/01

inherit NPC;
inherit F_MASTER;
string ask_drug1();
string ask_drug2();
string ask_drug3();
string ask_drug4();

void create()
{
        set_name("俞岱岩", ({ "yu daiyan", "yu" }));
        set("nickname", "武当三侠");
        set("long", "他是武当七侠中的愈三侠，现掌管丹药房。\n"
        	    "只见他面目憔悴，右手支撑着拐杖似乎十分吃力。\n"
        	    "据说多年前因被歹人以大力金刚指捏碎四肢，后来虽得以黑玉断续膏治疗但仍无法痊愈。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 5);
        set("int", 38);
        set("con", 10);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 0);
        set("combat_exp", 1050000);
        set("shen", 80000);

        set_skill("force", 120);
        set_skill("taiji-shengong", 120);
        set_skill("dodge", 100);
        set_skill("tiyun-zong", 100);
        set_skill("strike", 90);
        set_skill("mian-zhang",90);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("taiji-jian", 100);
        set_skill("literate", 150);
        set_skill("taoism", 150);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "mian-zhang");
        map_skill("sword", "taiji-jian");

        prepare_skill("strike", "mian-zhang");

        create_family("武当派", 2, "弟子");
	set("inquiry", ([
	"丹药房" : "这里还没用完全开放，请耐心等待。\n",
	"天心解毒丹" : (:ask_drug1:),
	"三黄宝腊丸" : (:ask_drug2:),
	"天王护心丹" : (:ask_drug3:),
	"白虎夺命丸" : (:ask_drug4:),
	
	]));
	
	set("drug1_count", 5);
	set("drug2_count", 5);
	set("drug3_count", 5);
	set("drug4_count", 3);
	
        setup();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

string ask_drug1()
{ 
	mapping fam; 
	object me, ob,*obs;
	me=this_player();
	ob=this_object();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        
        if (me->query_temp("obtained_drug1"))
        {
      	command("hmm "+me->query("id"));
        return "天心解毒丹不是已经给过你了吗？";
	}
	
	obs = filter_array(children("/clone/drug/tianxin.c"), (: clonep :));
        if (sizeof(obs) > 5)
                return "你来晚了，天心解毒丹都已经被其他同们拿走了，需要再行练制。";

	if (query("drug1_count") < 1)
        return "你来晚了，天心解毒丹都已经被其他同们拿走了，需要再行练制。";
        
	ob=new("/clone/drug/tianxin");
	ob->move(me);
	add("drug1_count", -1);
	me->set_temp("obtained_drug1", 1);
	message_vision("俞岱岩转身找了找，在架子上拿下了一个小白瓶，从里面倒了一颗药丸出来给$N。\n",me);
	return "好吧，这里有一颗天心解毒丹，切记要慎用。";
}
	
string ask_drug2()
{ 
	mapping fam; 
	object me, ob,*obs;
	me=this_player();
	ob=this_object();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        
        if (me->query_temp("obtained_drug2"))
        {
      	command("hmm "+me->query("id"));
        return "三黄宝腊丸不是已经给过你了吗？";
	}
	
	obs = filter_array(children("/clone/drug/sanhuang-wan.c"), (: clonep :));
        if (sizeof(obs) > 5)
                return "你来晚了，三黄宝腊丸都已经被其他同们拿走了，需要再行练制。";

	if (query("drug2_count") < 1)
        return "你来晚了，三黄宝腊丸都已经被其他同们拿走了，需要再行练制。";
        
	ob=new("/clone/drug/sanhuang-wan");
	ob->move(me);
	add("drug2_count", -1);
	me->set_temp("obtained_drug2", 1);
	message_vision("俞岱岩转身找了找，在架子上拿下了一个小白瓶，从里面倒了一颗药丸出来给$N。\n",me);
	return "好吧，这里有一颗三黄宝腊丸，切记要慎用。";
}

string ask_drug3()
{ 
	mapping fam; 
	object me, ob,*obs;
	me=this_player();
	ob=this_object();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        
        if (me->query_temp("obtained_drug3"))
        {
      	command("hmm "+me->query("id"));
        return "天王护心丹不是已经给过你了吗？";
	}
	
	obs = filter_array(children("/clone/drug/huxin"), (: clonep :));
        if (sizeof(obs) > 5)
                return "你来晚了，天王护心丹都已经被其他同们拿走了，需要再行练制。";

	if (query("drug3_count") < 1)
        return "你来晚了，天王护心丹都已经被其他同们拿走了，需要再行练制。";
        
	ob=new("/clone/drug/huxin");
	ob->move(me);
	add("drug3_count", -1);
	me->set_temp("obtained_drug3", 1);
	message_vision("俞岱岩转身找了找，在架子上拿下了一个小白瓶，从里面倒了一颗药丸出来给$N。\n",me);
	return "好吧，这里有一颗天王护心丹，切记要慎用。";
}

string ask_drug4()
{ 
	mapping fam; 
	object me, ob,*obs;
	me=this_player();
	ob=this_object();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        
        if (me->query_temp("obtained_drug2"))
        {
      	command("hmm "+me->query("id"));
        return "白虎夺命丸不是已经给过你了吗？";
	}
	
	obs = filter_array(children("/clone/drug/baihu.c"), (: clonep :));
        if (sizeof(obs) > 5)
                return "你来晚了，白虎夺命丸都已经被其他同们拿走了，需要再行练制。";

	if (query("drug2_count") < 1)
        return "你来晚了，白虎夺命丸都已经被其他同们拿走了，需要再行练制。";
        
        if (me->query("combat_exp") < 50000 )
        {
        command("look "+me->query("id"));
        return "白虎夺命丸配置极为不易，以你目前的功力应该不会需要的，以后再说吧。";
        }
	ob=new("/clone/drug/baihu");
	ob->move(me);
	add("drug2_count", -1);
	me->set_temp("obtained_drug2", 1);
	message_vision("俞岱岩转身找了找，在架子上拿下了一个小白瓶，从里面倒了一颗药丸出来给$N。\n",me);
	return "好吧，这里有一颗白虎夺命丸，它配置不易切记要慎用。";
}
// End of file 
