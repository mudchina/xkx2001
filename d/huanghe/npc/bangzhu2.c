//Cracked by Roath
// /d/huanghe/npc/bangzhu2.c
// by aln 2 / 98

#define BANGZHONG2 "/d/huanghe/npc/bangzhong2"

inherit NPC;

#include <ansi.h>
#include <localtime.h>

#include "/d/huanghe/doc/info_bang.h"

void create()
{
        set_name("草上飞", ({ "bangzhu" }));
        set("gender", "男性");
        set("age", 30);
        set("long",
"一个魁梧之极的大汉，脸庞极尽苍桑，精神却甚矍铄。\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("combat_exp", 60000);

        set("max_qi", 300);
        set("max_jing", 200);
        set("max_jingli", 60);
        set("max_neili", 200);
        set("neili", 200);

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("cuff", 80);

        set_skill("ding-force", 80);
        map_skill("force", "ding-force");

        set_skill("wuxingbu", 80);
        map_skill("dodge", "wuxingbu");

        set("no_get", "帮主太重了");

        setup();

        call_out("come_attacker", 10);
}

void init()
{
        ::init();

        add_action("do_ask", "ask");
}

int do_ask(string arg)
{
        object ob, me = this_object();
        string dest, topic;

        if( !arg || sscanf(arg, "%s about %s", dest, topic) != 2 ) {
                write("你要问谁什么事？\n");
                return 1;
        }

        if( !objectp(ob = present(dest, environment(me))) ) {
                write("这里没有这个人。\n");
                return 1;
        }

        if( ob != me )
                return notify_fail("");

        if( !living(me) )
                return 1;

        say(name() + "大怒道：没见老子生了病烦着呢？滚！！！\n");
        return 1;
}

void come_attacker()
{
        object me = this_object(), helper, *myenemy, room, ob, obj;
        string *bangs;
        int temp, bonus, record;

        if( !(room = environment()) ) {
                destruct(me);
                return;
        }

        if( !(helper = query("helper")) ) {
                say(name() + "自言自语道：此地不可久留，三十六计走为上！\n");
                say(name() + "急急忙忙地离开了。\n");
                destruct(me);
                return;
        }

        if( room != environment(helper) ) {
                say(name() + "自言自语道：此地不可久留，三十六计走为上！\n");
                say(name() + "急急忙忙地离开了。\n");
                destruct(me);
                return;
        }

        if( !is_fighting() &&  living(me)
        &&  explode(base_name(room), "/")[1] == (string)query("dest") ) {
                command("thumb " + helper->query("id"));
                if( obj = present("bang ling", helper) ) {
                        bonus = (int)obj->query("job/bonus");
                        bonus = bonus * 100000 / ( 100000 + (int)helper->query("combat_exp") );
                        record = bonus/2 + random(bonus);
                        helper->add("combat_exp", record);
                        log_file("BangJob", sprintf("%s于%s时因护驾有功得%s经验点\n", helper->query("name"), ctime(time()), chinese_number(record)));
                        bonus /= 4;
                        obj->add("score", bonus);
                        obj->delete("job");
                }
                say(name() + "双手一抱拳道：帮主养伤要化一段时间，你好自为之吧！\n");
                say(name() + "扬长而去。\n");
                destruct(me);
                return;
        }

        remove_call_out("come_attacker");
        call_out("come_attacker", 5 + random(5));

        if( room->query("no_fight") ) return;

        if( temp = sizeof(myenemy = query_enemy()) ) {
                for(int i = 0; i < temp; i++)
                        if( myenemy[i]->query("victim") == me )
                                return;
        }

        ob = new(BANGZHONG2);
        bangs = keys(info_bang);
        bangs -= ({query("fam")});
        ob->set("title", bangs[random(sizeof(bangs))]);
        ob->set("victim", me);

        ob->move(room);
        message("vision",
                ob->name() + "走了过来。\n",
                room, ({ob}));
        ob->set_leader(me);
        message_vision("$N对$n喝道：看你还往哪里跑？！\n", ob, me);
        ob->kill_ob(me);
        command("!!!");
        me->kill_ob(ob);
}
        
