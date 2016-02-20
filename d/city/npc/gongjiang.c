//Cracked by Roath
// 工匠
// ssy

#include <ansi.h>
#include <dbase.h>
inherit NPC;

string ask_me();
int do_repair(string arg);

void create()
{
        set_name("工匠", ({ "gong jiang", "jiang", "worker"}));
     
        set("long",
"一位专门靠给兵器镀色(setcolor)刻字(setname)为生的工匠。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 20);
        set("con", 20);
        set("dex", 18);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 0);
        set("max_neili", 0);
        set("jiali", 0);
        set("combat_exp", 1000);
        set("score", 1000);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);

        set("inquiry", ([
                "setname"     : (: ask_me :),
                "setcolor"     : (: ask_me :),
        ]));

        setup();
        carry_object("/d/city/obj/cloth")->wear();

}

void init()
{
        add_action("do_setname", "setname");
        add_action("do_setcolor", "setcolor");

}

string ask_me()
{
        object me = this_player();

        if (query_temp("busy"))
                return "哟，抱歉啊，我这儿正忙着呢……您请稍候。\n";
        if (!me->query_temp("allow_set"))
                return "这位"+RANK_D->query_respect(me)+"您请先付十两白银。\n";

        me->set_temp("pending/sewing", 1);
        return "不知道这位"+RANK_D->query_respect(me)+"需要我做些什麽？
(setcolor weapon_name color) (setname weapon_name)\n";
}

int do_setcolor(string arg)
{
        object obj,me;
        string file;
	string target,thecolor; 

        me = this_player();

        if (!me->query_temp("allow_set"))
	  return notify_fail("这位"+RANK_D->query_respect(me)+"您请先付十两白银。\n");
          
	if(!arg)
	  return notify_fail("什么？\n");
	else if (sscanf(arg, "%s %s", target, thecolor)!=2)
          return notify_fail("什么？\n");
        if( !objectp(obj = present(target, me)) )
                return notify_fail("你要在什么兵器上刻名字？\n");

        if (!obj->query("weapon_prop/damage") || obj->query("weapon_prop/damage")<1)
                return notify_fail("这东西是兵器吗？\n");

        if (query_temp("busy"))
	  return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	if (thecolor=="HIY")
	  obj->set("name",HIY+obj->query("name")+NOR);
        else if (thecolor=="HIG")
          obj->set("name",HIG+obj->query("name")+NOR);
        else if (thecolor=="HIR")
          obj->set("name",HIR+obj->query("name")+NOR);
        else if (thecolor=="HIB")
          obj->set("name",HIB+obj->query("name")+NOR);
        else if (thecolor=="HIM")
          obj->set("name",HIM+obj->query("name")+NOR);
        else if (thecolor=="HIC")
          obj->set("name",HIC+obj->query("name")+NOR);
        else if (thecolor=="HIW")
          obj->set("name",HIW+obj->query("name")+NOR);
        else if (thecolor=="RED")
          obj->set("name",RED+obj->query("name")+NOR);
        else if (thecolor=="GRN")
          obj->set("name",GRN+obj->query("name")+NOR);
        else if (thecolor=="YEL")
          obj->set("name",YEL+obj->query("name")+NOR);
        else if (thecolor=="BLU")
          obj->set("name",BLU+obj->query("name")+NOR);
        else if (thecolor=="MAG")
          obj->set("name",MAG+obj->query("name")+NOR);
        else if (thecolor=="CYN")
          obj->set("name",CYN+obj->query("name")+NOR);
        else if (thecolor=="WHT")
          obj->set("name",WHT+obj->query("name")+NOR);
	else return notify_fail("颜色必须是 help color 中的一种\n");

        write("工匠抹了一把汗，说道：“镀好了，拿去吧。”\n");
        me->delete_temp("allow_set");

        remove_call_out("enough_rest");
        call_out("enough_rest", 2);

        return 1;
       
}
 
int do_setname(string arg)
{
        object obj,me;

        me = this_player();

	if (!me->query_temp("allow_set"))
	  return notify_fail("这位"+RANK_D->query_respect(me)+"您请先付十两白银。\n");
	  
	if (!arg) return notify_fail("你要在什么兵器上刻名字？\n");        

	if( !objectp(obj = present(arg, me)) )
                return notify_fail("你要在什么兵器上刻名字？\n");

        if (!obj->query("weapon_prop/damage") || obj->query("weapon_prop/damage")<1)
                return notify_fail("这东西是兵器吗？\n");
//	if (obj->query("value")>=1000000)
	//        return notify_fail("这样兵器太贵重了，不能被刻字。\n");
        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

        if (obj->query("owner"))
                return notify_fail(obj->query("name")+"上不是已经有字了吗？\n");


        set_temp("busy",1);
        start_busy(2);

	obj->set("long",obj->query("long")+"\n"+obj->query("name")+"上刻有："+me->query("name")+"之兵器。\n");
        obj->set("short",obj->query("short"));
        obj->set("owner",me->query("id"));

        write("工匠抹了一把汗，说道：“刻好了，拿去吧。”\n");

	me->delete_temp("allow_set");

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
        command("smile");
	command("say 真是多谢" + RANK_D->query_respect(me) + "您了 ！");

        if(ob->query("money_id") && ob->value() >= 1000)
                me->set_temp("allow_set", 1);

        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, ob);

        return 1;
}

void destroy_ob(object ob)
{
        if (ob) destruct(ob);
}
