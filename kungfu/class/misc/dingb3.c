//Cracked by Roath
// dingb3.c 丁不三
// xQin 8/00 

#include <ansi.h>
inherit	NPC;
inherit F_MASTER;

void init();
void do_say(string);
void do_fear();

string ask_nick(object);
string ask_dingdang();

void create()
{
	set_name("丁不三", ({"ding busan", "ding", "busan" }));
	set("long",
		"只见这人须发皓然，眉花眼笑，是个面目慈祥的老头儿。\n"
		"但与他目光一触，登时不由自主的机伶伶打个冷战，这人\n"
		"眼中射出一股难以形容的凶狠之意，叫人一看之下，浑身\n"
		"感到一股寒意，几乎要冷到骨髓中去。\n");
	set("nickname", WHT"一日不过三"NOR);
	set("gender", "男性");
	set("attitude", "heroism");
	set("age", 65);
	set("shen_type", -1);
	
        set("str", 22);
        set("int", 24);
        set("con", 26);
        set("dex", 20);
        
        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);

        set("combat_exp", 500000);
        set("score", 500000);

	set_skill("force", 180);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("hand", 180);
	set_skill("taixuan-gong", 160);
	set_skill("ding-dodge", 160);
	set_skill("dingjia-qinnashou", 170);
	set_skill("literate", 60);
	
	map_skill("force", "taixuan-gong");
	map_skill("parry", "dingjia-qinnashou");
	map_skill("hand", "dingjia-qinnashou");
	map_skill("dodge", "ding-dodge");
	prepare_skill("hand", "dingjia-qinnashou");
	
	set("inquiry", ([
	"nickname" : (:ask_nick:),
	"外号" : (:ask_nick:),
	"一日不过三" : (:ask_nick:),
	"丁当" : (:ask_dingdang:),
	"叮叮当当" : (:ask_dingdang:),
	"阿当": (:ask_dingdang:),
	"玄冰碧火酒" : ""+RANK_D->query_rude(this_player()) +"在胡说八道些什么？！\n",
	"雪山派" : "哼，雪山派没一个好人，尤其是那个白自在，还自称什么「威德先生」，放他的狗屁！\n",
	"xueshan" : "哼，雪山派没一个好人，尤其是那个白自在，还自称什么「威德先生」，放他的狗屁！\n",
	]));
	 
	set("chat_chance",6);
        set("chat_msg", ({
        	"丁不三神气的说道：老子这「一日不过三」自然大有道理，只可惜江湖中人都不明白这其中的妙处。\n",
        	"丁不三拿起酒瓶咕噜咕噜的喝了几口。\n",
        	"丁不三骂道：阿当那个丫头不知道溜那去了，竟然把爷爷的陈年绍兴也偷走了！\n"
        	"丁不三自言自语说道：老子杀人一日不过三，好比那孙万年、褚万春，就只两个而已。\n",
        }));
        set_temp("first/ask", 1);
        setup();
        carry_object("/d/city/npc/wine/nuerhong");
	carry_object("/d/city/obj/qcloth")->wear();
        carry_object("/d/city/obj/zi_shoes")->wear();
}

void init()
{
	object me;
	me=this_player();
	
	if( me->query("family/family_name") == "雪山派") 
        {
        command("look "+getuid(me));
        command("sneer "+getuid(me));
	}
	add_action("do_say","say");
	add_action("do_fear","fear");
}


string ask_nick(object me)
{
        me=this_player();
	
	if (query_temp("first/ask") > 1)
	{
	command("say 这样一来便有了节制，就算日日都杀人名，一年也不过一千，何况往往数日不杀，杀起来也或许只一二人。");
	command("idea "+me->query("id"));
	return "觉得爷爷的名字怎么样？快老老实实给爷爷说，要是爷爷高兴，自然有你好处。";
	}
	add_temp("first/ask", 1);
	return "老子当年杀人太多，后来定下规矩，一日之中杀人不得过三名。";

}

void do_say(string arg)
{
        object me;
        me=this_player();
        
        if (arg=="爷爷的名字很好听啊" || arg=="爷爷的外号很好听啊") {
        if (me->query("got/wine")) 
        {
        command("goodkid "+me->query("id"));
        return;
	}
	if (query_temp("first/ask") > 1)
	{
	command("haha");
	command("haha "+me->query("id"));
	command("pat "+me->query("id"));
	command("say 别人听到我的名字都闻风丧胆，难得你还真心觉得爷爷的外号好听。");
	command("secret "+me->query("id"));
	message_vision("丁不三拉住$N在$N的耳边轻声说了些话。\n",me);
	command("whisper " +me->query("id") + " " + "爷爷本想赏你件宝贝，可是爷爷的「玄冰碧火酒」被阿当那个丫头偷走了，如果你能找到她，并且帮我劝她回来，这宝贝就送你吧！");
	command("say 好了，快去快回！");
	me->set_temp("find/dddd", 1);
	return;
	} 
	else {
	command("en "+me->query("id"));
	command("say 你懂什么，别假惺惺的在这乱拍马屁。");
	command("consider "+me->query("id"));
	me->add_temp("potential/victim", 1);
	return;
	}
	}
}

string ask_dingdang()
{
	object me;
	me=this_player();
	
	if (me->query_temp("find/dddd"))
	{
	command("whisper " +me->query("id") + " " + "阿当那丫头好象往长乐帮那方向走了，记得要劝她回来！");
	return "还不快去，磨蹭什么？！";	
	}
	else {
	return "阿当这丫头不知道溜哪去了。";
	}
}

void do_fear()
{
	object ob, me;
	ob=this_object();
	me=this_player();
	
	if ( environment(me)==find_object("/d/city/jiuguan2.c")
	&& ob->query_temp("did/kill") < 3) {
	if (me->query_temp("potential/victim") > 2)
	{
	command("hehe");
	command("kill "+me->query("id"));
	ob->add_temp("did/kill", 1);
	me->delete_temp("potential/victim");
	return;
	} 
	else {
	command("hmm");
	me->add_temp("potential/victim", 2);
	return;
	}
		}
	else {
	command("say 老子今天杀够了，你就留到明天再收拾吧！");
	return;
	}
			
}

	