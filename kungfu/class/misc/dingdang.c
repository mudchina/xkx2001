//Cracked by Roath
// dingdang.c 叮叮当当
// xQin 8/00

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void init();

string ask_wine();
string ask_tian();

void create()
{
	set_name("丁当" , ({"ding dang", "ding"}));
	set("long",
		"只见你眼前出现了一张清丽白腻的脸庞，小嘴边带着俏皮的微笑。\n"
		"她身上散发着少女的悠香，让人闻了不由心中一荡。\n");
	set("nickname", HIC"叮叮当当"NOR);
	set("gender", "女性");
	set("attitude", "friendly");
	set("age", 18);
	set("per", 27);
	
        set("str", 18);
        set("int", 26);
        set("con", 20);
        set("dex", 19);
        
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 700);
        set("max_jing", 700);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 70000);
        set("score", 70000);

	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("hand", 85);
	set_skill("taixuan-gong", 70);
	set_skill("ding-dodge", 70);
	set_skill("dingjia-qinnashou", 80);
	set_skill("literate", 60);
	
	map_skill("force", "taixuan-gong");
	map_skill("parry", "dingjia-qinnashou");
	map_skill("hand", "dingjia-qinnashou");
	map_skill("dodge", "ding-dodge");
	prepare_skill("hand", "dingjia-qinnashou");
	
	set("inquiry", ([
	"玄冰碧火酒" : (:ask_wine:),
	"wine" : (:ask_wine:),
	"丁不三" : "丁不三是我爷爷啊，你找他有事？我爷爷很凶的，你还是别找他了。\n",
	"天哥" : (:ask_tian:),
	"石破天" : (:ask_tian:),
	"雪山派" : "爷爷最讨厌雪山派的人了，你千万不要在他面前提起。\n",
	"xueshan" : "爷爷最讨厌雪山派的人了，你千万不要在他面前提起。\n",
	"name" : "我姓丁名当，大家都叫我叮叮当当。\n",
	"名字" : "我姓丁名当，大家都叫我叮叮当当。\n",
	]));
	
	setup();
	carry_object("/d/city/obj/moon_dress")->wear();

}

void init()
{
	object ob, me;
	me=this_player();
	
	if ( environment(me)==find_object("/d/forest/clbajiaoting.c")) {
	if ( me->query_temp("find/dddd"))
	{
	command("say 天哥的伤不知道什么时候才全愈，真教人担心。");
	command("sigh");
	return;
		}
	}
}

string ask_tian()
{
	object me=this_player();
	
	if ( me->query_temp("find/dddd"))
	{
	command("sigh");
	return "天哥受了重伤，我刚喂了点「玄冰碧火酒」给他服用，希望他没事。";
	}
	else {
	return "你也认识天哥吗？噢，对了，你是他的属下吧。";
	}
}

string ask_wine()
{
	object me=this_player();
	
	if (me->query("combat_exp") < 100000)
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "凭你这点本事配来管本姑娘的闲事？！";
	}
	if ( me->query_temp("find/dddd"))
	{
	command("ah "+me->query("id"));
	add_action("do_pretty", "pretty");
	command("say 一定是爷爷派你来劝我回去的是不是？原来他已经知道我偷了他的宝贝。");
	command("sigh");
	command("say 天哥以前风流涕淌，对人家老是油腔滑调的，可是最近不知道怎么变傻了，连哄人家的话也不会说了。");
	command("disapp");
	me->set_temp("pretty/ding", 1);
	return "我真宁愿他是以前那个会哄人家开心的天哥。";
	}
	else {
		return "这酒是我爷爷的，你自己问他要吧。";
		}
}

int do_pretty(string arg)
{
	object me, ob, *obs;
	me=this_player();
	
	if ( !arg ) return 0;

	ob = present(arg, environment());
        
	if (!objectp(ob)) return 0;
        
	if (me->query_temp("pretty/ding")) 
        {
        command("giggle");
        command("happy2 "+me->query("id"));
        command("blush");
        command("say 谢谢你啦，不过我要留在这里陪天哥，你帮我把这剩下的「玄冰碧火酒」带回去给爷爷吧。");
        ob=new("/clone/unique/jiu.c");
	message_vision("丁当将一瓶「玄冰碧火酒」交了给$N。\n", me);
	ob->move(this_player());
	me->set("got/wine", 1);
	me->delete_temp("find/dddd", 1);
	me->delete_temp("pretty/ding", 1);
	me->delete_temp("first/ask");
        return 1;
	} 
}