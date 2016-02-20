//Cracked by Roath
// /d/hangzhou/npc/du.c  都大锦
// by aln  2 / 98
// modified by aln 4 / 98

inherit NPC;

#include <ansi.h>

int auto_throw();
int come_killer();
string ask_job();
       
void create()
{
        set_name("都大锦", ({ "du dajin", "du" }));
        set("gender", "男性");
        set("age", 45);
        set("long", 
"他是少林派的俗家弟子，拳掌单刀，都有相当造诣。\n"
"尤其一手连珠钢镖，能一口气连发七七四十九枚钢镖。\n"
"因此江湖上送了他一个外号，叫作多臂熊。\n");
        set("shen_type", 1);
        set("combat_exp", 220000);

        set("str", 25);
        set("int", 10);
        set("con", 20);
        set("dex", 20);
 
        set("max_qi", 800);
        set("max_jing", 400);
        set("max_neili", 800);
        set("neili", 800);
        set("jiali", 50);
        set("score", 10000);

        set_temp("apply/armor", 30);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("strike", 80);
        set_skill("throwing", 100);

        set_skill("hunyuan-yiqi", 80);
        set_skill("shaolin-shenfa", 80);
        set_skill("banruo-zhang", 80);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "banruo-zhang");
        map_skill("strike", "banruo-zhang");

        prepare_skill("strike", "banruo-zhang");

        set("chat_chance", 3);
        set("chat_msg",({
                (: come_killer :)
        }));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_throw :),
        }) );

        set("inquiry", ([
                "工作" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

        setup();

        carry_object("/clone/anqi/feibiao")->set_amount(3);
}

int come_killer()
{
        object ob, room;

        if( is_fighting() || is_busy() ) return 1;

        if( !(room = environment()) ) return 1;

        if( base_name(room) != "/d/hangzhou/biaoju" ) return 1;

        if( ob = present("mengmian ren", room) ) {
                if( !ob->is_fighting(this_object()) )
                        ob->kill_ob(this_object());
                return 1;
        }
        
        ob = new(__DIR__"figure");
        ob->move(room);
        ob->set_leader(this_object());
        say("突然一个蒙面人快步走了过来对" + name() + "喝道：都大锦！明年的今天是你的忌日！\n");
        command("go enter");
        command("!!!");
        ob->kill_ob(this_object());
        return 1;
}

string ask_job()
{
        object obj, wage, me = this_player();
        mapping myfam;
        int bonus;

        if( is_fighting() || is_busy() )
                return "我正忙着。";

        if( base_name(environment()) != "/d/hangzhou/biaoju" ) {
                call_out("do_back", 1);
                return "等我查了帐再说吧。";
        }

        if( !mapp(myfam = me->query("family")) )
                return RANK_D->query_respect(me) + "不是少林弟子，恕不录用。";

        if( myfam["family_name"] != "少林派" )
                return RANK_D->query_respect(me) + "不是少林弟子，恕不录用。";

        if( myfam["generation"] > 37 )
                return RANK_D->query_respect(me) + "还是在少林寺再练几年吧。";

        if( me->query_condition("lmjob") )
                return RANK_D->query_respect(me) + "已经被录用了。";

        if( me->query_temp("lmjob/ok") ) {
                bonus = (int)me->query("combat_exp") / 10000;
                bonus += random(bonus);
                wage = new("/clone/money/silver");
                wage->set_amount(bonus);
                wage->move(me);
                message_vision("$N转身拿出一个红包递给$n。\n", this_object(), me);

                me->delete_temp("lmjob");
          //      me->add("combat_exp", bonus);
                return RANK_D->query_respect(me) + "辛苦了。";
        }

        if( !(obj = present("tuijian xin", me)) )
                return RANK_D->query_respect(me) + "没有少林寺方丈的推荐信，恕不录用。";

        if( (string)obj->query("owner") != me->query("id") )
                return "这封推荐信不是为了" + RANK_D->query_respect(me);

        message_vision("$N交给$n一封推荐信。\n", me, this_object());
        destruct(obj);

        me->apply_condition("lmjob", 10 + random(10));
        command("nod");

        return "太好了，我们这儿正需要一名少林弟子传授武功。";
}

void do_back()
{
        say("都大锦急急忙忙离开了。\n");
        move("/d/hangzhou/biaoju");
        say("都大锦快步走了过来。\n");
}

#include "/clone/npc/auto_throw.h";
