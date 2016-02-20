//Cracked by Roath
// /d/hangzhou/npc/gu.c
// by aln  2 / 98

inherit NPC;

#include <ansi.h>

string ask_book();

void create()
{
        set_name("顾炎武", ({ "gu yanwu" , "gu" }));
        set("gender", "男性");
        set("age", 55);
        set("long", 
"他又高又瘦，面目黝黑。\n"
"他字亭林，江苏昆山人士。\n");
        set("shen_type", 1);
        set("combat_exp", 2000);

        set("str", 20);
        set("int", 30);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 500);

        set("score", 10000);

        set_skill("dodge", 30);
        set_skill("sword", 30);

        set("inquiry", ([
                 "《明书辑略》" : (: ask_book :),
                 "明书辑略" : (: ask_book :),
                 "修撰" : (: ask_book :),
                 "book" : (: ask_book :),
        ]));

        setup();

        carry_object("/d/dali/npc/obj/dagger")->wield();
}

string ask_book()
{
        object ob;

        if( !(ob = present("mingshi", this_player())) )
                return "没有原稿，我怎么修撰？";

        if( ob->query("checked") )
                return "我已经修撰过此书了。";

        ob->set("checked", 1);
        message_vision("顾炎武将书阅后修改了几处谬误，同时也给$N讲解了一下。\n", this_player());
        if( (int)this_player()->query_skill("literate", 1) < 60 )
                this_player()->improve_skill("literate", 
                          10 * this_player()->query("int"));

        return "修撰明史乃是一件美事，老夫已尽力而为了。";
}
