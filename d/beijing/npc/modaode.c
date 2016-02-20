//Cracked by Roath
// modaode.c

inherit NPC;
inherit F_VENDOR;

#include "/d/beijing/npc/bjnpc.h"

string ask_mo();

void create()
{
        set_name("磨刀匠", ({ "modao jiang","jiang"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是个饱经风霜的汉子，肩头挑着磨刀的工具，走街串巷吆喝着。\n");
        set("combat_exp", 3000);
        set("str", 26);
        set("dex", 20);
        set("con", 17);
        set("int", 17);
        set("attitude", "friendly");
        set("chat_chance", 40);
        set("chat_msg", ({
                  "磨刀匠纵声唱道：磨剪子嘞，戗菜刀！\n",
		  (: random_walk :)
	}) );

        set("vendor_goods", ({
                "/clone/weapon/caidao.c",
	}) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin", 100);

	set("inquiry", ([
	       "modao" : (: ask_mo :),
	       "磨刀" :  (: ask_mo :),
        ]));
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

string ask_mo()
{
        object me = this_player();
	object obj;
        if (query_temp("busy"))
                return "哟，抱歉啊，我这儿正忙着呢……您请稍候。\n";
        if (me->query_temp("allow_modao")!=1)
                return "这位"+RANK_D->query_respect(me)+"您请先付一两白银。\n";
        me->delete_temp("allow_modao");

        if( !objectp(obj = present("cai dao", me)) )
                return "您没有菜刀，磨什么啊？\n";

        set_temp("busy",1);
        start_busy(2);
        obj = new("/d/beijing/obj/caidao2");
        obj->move(me);

        remove_call_out("enough_rest");
        call_out("enough_rest", 2);

        return "磨刀匠擦了擦汗，道：“好了，这把刀比以前快多了！”\n";
}

void enough_rest()
{
        delete_temp("busy");
}

int accept_object(object me, object ob)
{     
        if(ob->query("money_id") && ob->value() >= 100)
	  {
	    remove_call_out("enough");
	    call_out("enough", 1, 1,me);
	  }
	else 
	  {
	    remove_call_out("enough");
	    call_out("enough", 1,0,me);
	  }
        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, ob);

        return 1;
}

void enough(int i, object me)
{
        if (i==1)
	  {
	    command("bow");
	    command("say 多谢" + RANK_D->query_respect(me) + "您了 ！");
	    me->set_temp("allow_modao", 1);
	  }
	else
	  command("say 抱歉，您至少要付一两白银。");
}

void destroy_ob(object ob)
{
        if (ob) destruct(ob);
}
