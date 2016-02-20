//Cracked by Roath
// Jay 10/7/96

inherit NPC;
inherit F_MASTER;
string ask_camel();

void create()
{
        set_name("马光佐", ({ "ma guangzuo","ma","guangzuo" }));
        set("long", "马光佐是个西域的回人，新近投靠到白驼山庄。他粗眉粗眼，身上的肌肉好像石头一样，有一身的好武艺。\n");
	set("title","白驼山庄武师");
        set("gender", "男性");
        set("age", 45);
        set_skill("cuff", 60);
	set_skill("lingshe-quan", 60);
        set_skill("dodge", 50);
	set_skill("chanchubu", 50);
        set_skill("parry", 50);
        set_skill("force", 40);
	set_skill("hamagong", 40);
	set_skill("poison",20);
	set_skill("strike",50);
	set_skill("training",40);
	map_skill("cuff","lingshe-quan");
        map_skill("dodge","chanchubu");
	map_skill("force","hamagong");
	prepare_skill("cuff","lingshe-quan");

        set("str", 28);
        set("int", 21);
        set("con", 27);
        set("dex", 21);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);
        set("combat_exp", 80000);

        set("attitude", "heroism");
        set("shen_type", 0);

	set("inquiry", ([
                "骆驼" : (: ask_camel :),
                "坐骑" : (: ask_camel :),
		"白驼山庄" : "从这里向西北方走，快到天山时路边有一块石碑，从那里入沙漠向西走很久就到了。记着要骑骆驼。\n",
        ]));
        create_family("白驼山", 3 , "弟子");
	setup();
	carry_object("/clone/armor/wcloth")->wear();
}

void init()
{
 	add_action("return_camel", "还");
	add_action("return_camel", "return");
}
int return_camel(string arg)
{
    object ob, me = this_player();

    if( !arg || arg=="" ) return 0;

    if (!ob=present("camel", environment(me)))  return 0;

    if (ob->query_lord() != me) return 0;

    
    if( arg=="camel" ) {
	message_vision("$N把手中骆驼的缰绳交给了$n。\n", me, this_object());
	add("camel_count", -1);

	if(me->query("rided"))
	me->set("rided", 0);

	destruct(ob);
	return 1;
	}
}
	
void attempt_apprentice(object ob)
{
        mapping fam;
	string ttt;

	command ("look "+ob->query("id"));
	if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="女性")
		command ("say 小尼姑练蛤蟆功，不怕别人叫你秃头蛤蟆吗？");
	     else
		command ("say 大师傅练蛤蟆功，不怕别人叫你秃头蛤蟆吗？");
	     return;
	}
        if( ob->query("family/family_name") == "丐帮") {
		command ("say 庄主平生最恨叫化子，我可不想收你。");
		return;
	}
        if ( ob->query("family/family_name") == "武当派") {
		command ("say 老道练蛤蟆功，不怕别人叫你牛鼻子蛤蟆吗？");
		return;
	}

	if (ob->query("combat_exp") > 30000) {
		command ("say "+ RANK_D->query_respect(ob) + 
                           "是武林高手，拜我为师？别取笑于在下了。");
		return;
	}

	if (ob->query("gender")=="女性") ttt="婢女";
	else  ttt = "家丁";
	command("say 好吧，你就在我山庄做个" + ttt + "吧。");
        command("recruit " + ob->query("id"));
	ob->set("title","白驼山庄"+ttt);
	return;
}
string ask_camel()
{
        object ob, me=this_player();

        if (me->query("family/family_name")!="白驼山") {
                command("say 你是哪里来的" + RANK_D->query_rude(me) +
                        "到我们庄来混食？快给我滚！");
                command("kick " + me->query("id"));
                return ("小心我宰了你！");
        }

        if (me->query("rided") || me->query_temp("mark/驼")){
                return("你不是有坐骑了吗？");
        }

	if (query("camel_count") > 20)
                return("骆驼都让你师兄弟们骑走了，"+ RANK_D->query_respect(me)+
                       "要回山，等他们回来在说吧。");

        ob=new("/clone/horse/btcamel");
        ob->move("/d/xingxiu/btroad");
	add("camel_count", 1);
        ob->set_lord(me);
        ob->set_leader(me);
        me->set_temp("mark/驼", 1);
                command("nod");
                say("马光佐从身边的树丛里牵出一匹骆驼来交给你。\n");
		return(RANK_D->query_respect(me) + "路上小心，早去早归！");
}
