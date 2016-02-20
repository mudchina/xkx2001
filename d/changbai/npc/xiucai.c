//Cracked by Roath
// /d/changbai/npc/xiucai.c

#include <ansi.h>
inherit NPC;

int do_forge();

void create()
{
        set_name(HIY"落第秀才"NOR, ({ "xiucai" }));
        set("long", 
"他年青时颇有抱负，后来自暴自弃。\n"
"只凭一点墨才经常干些偷梁换柱的勾当度日。\n"); 
        set("gender", "男性");
        set("age", 35);

        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);

        set("combat_exp", 2000);
        set("shen_type", -1);

        set("inquiry", ([
                "伪造" : (: do_forge :),
                "weizao" : (: do_forge :),
                "forge" : (: do_forge :),
        ]) );

        setup();
}

int do_forge()
{
        object me = this_player(); 
        if( !me->query_temp("cbs_落第/a") )
                return 0;

        me->delete_temp("cbs_落第/a");
        
        command("hehe");
        command("whisper " + me->query("id") + " " + "一两黄金，不二价。\n");

        me->set_temp("cbs_落第/b", 1);
        return 1;
}

int accept_object(object who, object ob)
{
        object obj;

        if( ob->name() == "甲骨文" ) {
                command("ah " + who->query("id"));
                who->set_temp("cbs_落第/a", 1);
                call_out("destroy", 1, ob);
                return 1;
        }

        if( ob->value() >= 10000 && who->query_temp("cbs_落第/b") ) {
	        who->delete_temp("cbs_落第");
                say("落第秀才笑嘻嘻说道：这幅颂词保证错不了。\n");

                obj = new("/d/shenlong/obj/songci");
                obj->move(who);
                message_vision("$N将一" + obj->query("unit") + obj->query("name") + "交给$n。\n", this_object(), who);
                return 1;
        }

        return 0;
}

void destroy(object ob)
{
        destruct(ob);
}
