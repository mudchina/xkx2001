//Cracked by Roath
// /d/hangzhou/npc/zhuang.c
// by aln  2 / 98

inherit NPC;

#include <ansi.h>

string ask_book();

void create()
{
        set_name("庄允城", ({ "zhuang yuncheng" , "zhuang" }));
        set("gender", "男性");
        set("age", 65);
        set("long", 
"他就是南浔镇的富户，素来慷慨。\n"       
"他心伤爱子之逝，招请工匠，刊印《明书辑略》。\n");
        set("shen_type", 1);
        set("combat_exp", 200);

        set("str", 20);
        set("int", 30);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 100);
        set("max_jing", 100);

        set("score", 100);

        set_skill("dodge", 10);

        set("inquiry", ([
                 "《明书辑略》" : (: ask_book :),
		 "明书辑略" : (: ask_book :),
                 "book" : (: ask_book :),
        ]));

        setup();
}

string ask_book()
{
        object ob, me = this_player();

        if( time() < (int)me->query("mh_time") + 1200 )
                return RANK_D->query_respect(me) + "不是刚问过我吗？";

        if( (int)me->query_skill("literate", 1) < 30 )
                return RANK_D->query_respect(me) + "字不识一斗，要此书何干？";

	return;
        command("nod");
        me->set("mh_time", time());
        ob = new("/d/hangzhou/obj/mh_book");
        ob->move(me);
        message_vision("$N将一" + ob->query("unit") + ob->name() + "交给$n。\n", this_object(), me);
        return "此乃故子之遗作，谬赞了。如遇到顾先生，务必劳他修撰。";
}
