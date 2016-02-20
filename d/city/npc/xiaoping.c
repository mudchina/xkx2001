//Cracked by Roath
// Npc: 
// Date: 

#include <ansi.h>
#include <dbase.h>
inherit NPC;

string ask_me();
int do_repair(string arg);

void create()
{
	set_name("小萍", ({
		"xiao ping",
		"ping",
	}));
	set("long",
		"这是一个看起来十分伶俐乖巧的小丫环，柳叶眉，削肩膀，水蛇腰，\n"
		"十足一个美人胚子，但举手投足之间似乎身有武功。\n"
		"据说她本是嵩山脚下一个孤女，但在女红刺绣方面极有天份。\n"
	);


	set("gender", "女性");
	set("attitude", "friendly");

	set("age", 18);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("strike", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("literate", 50);


	set("inquiry", ([
		"缝衣"     : (: ask_me :),
		"缝补"	   : (: ask_me :),
		"缝纫"   : (: ask_me :)
	]));

	setup();

        carry_object("/d/taihu/obj/red_cloth")->wear();
}

void init()
{
	add_action("do_repair", "sew");
}

string ask_me()
{
        object me = this_player();
	
        if (query_temp("busy"))
                return "哟，抱歉啊，我这儿正忙着呢……您请稍候。\n";
	
	if (!me->query_temp("allow_repair")) 
		return "这位"+RANK_D->query_respect(me)+"您请先付一两白银。\n";

        me->set_temp("pending/sewing", 1);
        return "不知道这位"+RANK_D->query_respect(me)+"需要我补(sew)些什麽？\n";
}

int do_repair(string arg)
{
        object obj,me;
        string file;

        me = this_player();

	if (!arg) return notify_fail("你要补什么东西？\n");        

	if( !objectp(obj = present(arg, me)) )
                return notify_fail("你要缝补什么东西？\n");

        if (!obj->query("armor_prop/armor") || obj->query("armor_prop/armor")<1)
                return notify_fail("这东西能缝补吗？\n");

        if (obj->query("material")=="steel" || obj->query("material")=="iron")
                return notify_fail(CYN"小萍说道：您最好找双儿姐补这东西。\n"NOR);

        if (obj->query("shaolin"))
                return notify_fail(CYN"小萍说道：啊！这不是爹寺里....... 这臭东西打死我也不会碰一碰！！\n"NOR);

        set_temp("busy",1);
	start_busy(2);
        file = base_name(obj);

        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, obj);

	obj = new(file);
        write("小萍吁了一口长气，说道：“补好了，拿去吧，下次小心点哦。\n");
        if(obj) obj->move(me);
        me->delete_temp("allow_repair");
        
	remove_call_out("enough_rest");
	call_out("enough_rest", 2);
		
        return 1;
}

void enough_rest()
{
        delete_temp("busy");
}

int accept_object(object me, object ob)
{
	command("jump");
	command("say 真是多谢" + RANK_D->query_respect(me) + "您了 ！");

	if(ob->query("money_id") && ob->value() >= 100)
		me->set_temp("allow_repair", 1);
	
	remove_call_out("destroy_ob");
	call_out("destroy_ob", 1, ob);

	return 1;
}

void destroy_ob(object ob)
{
	if(ob) destruct(ob);
}
