//Cracked by Roath
// /d/huanghe/npc/bangzhu.c
// by aln 2/98

#ifndef BANGS
#define BANGS  "/d/huanghe/"
#endif

#define BANGJOB    BANGS + "bangjob/bangjob"
#define BANGSKILLS BANGS + "skills/"
#define BANGZHONG  BANGS + "npc/bangzhong"
#define BANGZHU2   BANGS + "npc/bangzhu2"
#define BIAOTOU    BANGS + "npc/biaotou"
#define BANGYIN    BANGS + "obj/bangyin"
#define BANGLING   BANGS + "obj/bangling"
#define BIAOHUO    BANGS + "obj/biaohuo"
#define CAILI      BANGS + "obj/caili"

inherit NPC;
inherit F_SSERVER;

#include <ansi.h>
#include <localtime.h>

#include "/d/huanghe/doc/bangskills.h"
#include "/d/huanghe/doc/info_bang.h"
#include "/d/huanghe/doc/info_store.h"
#include "/d/huanghe/doc/info_biao.h"
#include "/d/huanghe/doc/info_guest.h"
#include "/d/huanghe/doc/info_destine.h"
#include "/d/REGIONS.h"


int check_bang();
int ask_join();
string ask_job();
string ask_skills();
int ask_me(string);
int is_victim(object, string);

void set_bang(object);
void set_follower(object, object);

void create()
{
        object *obj;
        string *names, fam, name;
        string bc_skill, *bc_skills, sp_skill, *sp_skills, *weapons;
        int i, temp, level, exp = 100000 + random(200000);

        names = keys(info_bang);

        obj = filter_array(children(__FILE__), (: clonep :));
        if( temp = sizeof(obj) ) {
	        for(i = 0; i < temp; i++)
                        names -= ({obj[i]->query("fam")});
        }

        if( sizeof(names) ) {
                fam = names[random(sizeof(names))];
                name = info_bang[fam];
        } else {
                fam = "无名帮";
                name = "草上飞";
        }

        set_name(name, ({ "bangzhu" }));
        set("title", fam + "帮主");
        set("fam", fam);
        set("gender", "男性");
        set("age", 30 + random(20));
        set("long",
"一个魁梧之极的大汉，脸庞极尽苍桑，精神却甚矍铄。\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("combat_exp", exp);
        level = ceil( pow( to_float(exp) * 10.0, 0.333333) ) * 4 / 5;

        set("max_qi",   level * 10 + 200);
        set("qi",       level * 10 + 200);
        set("max_jing", level *  5 + 100);
        set("jing",     level *  5 + 100);
        set("max_neili",level *  6 + 500);
        set("neili",    level *  6 + 500);
        set("jiali", level / 3);

        set_temp("apply/defense", level/5);
        set_temp("apply/armor",   level/2);
        set_temp("apply/damage",  level/5);

        set_skill("dodge", level);
        set_skill("force", level);
        set_skill("parry", level);

        bc_skill = knowledge_skills[random(sizeof(knowledge_skills))];
        set_skill(bc_skill, level);

        sp_skill = force_skills[random(sizeof(force_skills))];
        set_skill(sp_skill, level);
        map_skill("force", sp_skill);

        sp_skill = dodge_skills[random(sizeof(dodge_skills))];
        set_skill(sp_skill, level);
        map_skill("dodge", sp_skill);

        bc_skills = keys(unarmed_skills);
        bc_skill = bc_skills[random(sizeof(bc_skills))];
        set_skill(bc_skill, level);
        sp_skills = unarmed_skills[bc_skill];
        sp_skill = sp_skills[random(sizeof(sp_skills))];
        set_skill(sp_skill, level);
        map_skill(bc_skill, sp_skill);
        map_skill("parry", sp_skill);
        prepare_skill(bc_skill, sp_skill);

        i = random(sizeof(info_weapon));
        bc_skill = info_weapon[i]["type"];
        weapons = info_weapon[i]["weapons"];
        sp_skills = info_weapon[i]["skills"];
        sp_skill = sp_skills[random(sizeof(sp_skills))];

        set_skill(bc_skill, level);
        set_skill(sp_skill, level);
        map_skill(bc_skill, sp_skill);

        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :)
        }) );
/*
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: check_bang :),
        }) );
*/
        set("inquiry", ([
                "入帮" : (: ask_join :),
                "join" : (: ask_join :),
                "帮务" : (: ask_job :),
                "job" : (: ask_job :),
		"武功" : (: ask_skills :),
                "skills" : (: ask_skills :),
        ]));

        set("inquiry/" + fam, (: ask_me, fam :));

        setup();

        if( !random(2) ) {
              map_skill("parry", sp_skill);
              carry_object(weapons[random(sizeof(weapons))])->wield();
        }

        call_out("set_bang", 1, this_object());
}

void init()
{
        object ob = this_player();

        ::init();

        if( !is_fighting()
        &&  interactive(ob) ) {
                remove_call_out("checking");
                call_out("checking", 1, ob);
        }

        add_action("do_check", "exert");
        add_action("do_check", "yun");
        add_action("do_xue", "xue");
}

void checking(object ob)
{
        object me = this_object();

        if( !living(me) || is_fighting() ) return;

        if( environment() != environment(ob) ) return;

        if( !random(2) )
                message_vision("$N双手抱拳，牛里牛气地说道：见到本帮主，难道没有任何表示吗？\n", me);
        else    message_vision("$N说道：还不赶快加入" + query("fam") + "！！！\n", me);
}

int ask_me(string arg)
{
        message_vision("$N「哈哈哈」大笑几声。\n", this_object());
        message_vision("$N说道：" + arg + "威震江湖，指日可待！哈！哈！哈！\n", this_object());
        return 1;
}

int do_check(string arg)
{
        string what, who;

        if( !arg ) return notify_fail("");

        if( arg != "play" ) {
                 if( sscanf(arg, "%s %s", what, who) != 2 )
                          return notify_fail("");

                 if( what != "play" )
                          return notify_fail("");
        }

        call_other(BANGSKILLS + "play2", "exert", this_player(), this_player());
        return 1;
}
       
int accept_kill(object me)
{
        object *follower, *obj = ({}), room;
        int i, temp;

        say(name() + "说道：你想谋害本帮主，当真是吃了熊心豹子胆了！！\n");

        follower = query("follower");
        room = environment();
        for(i = 0; i < sizeof(follower); i++) {
                if( !follower[i] ) continue;
                if( !living(follower[i]) ) continue;
                if( environment(follower[i]) != room ) continue;
                obj += ({follower[i]});
        }

        if( !(temp = sizeof(obj)) ) return 1;

        say(name() + "说道：各位帮众何在！\n");

        for(i = 0; i < temp; i++) {
                say(obj[i]->name() + "说道：在！\n");
                obj[i]->kill_ob(me);
        }

        return 1;
}

/*
int check_bang()
{
        object *follower, *obj = ({}), ob;
        int i, temp;

        if( !living(this_object()) )  return 1;

        follower = query("follower");
        for(i = 0; i < sizeof(follower); i++) {
                if( !follower[i] ) continue;
                if( !living(follower[i]) ) continue;
                if( environment(follower[i]) != environment() ) continue;
                obj += ({follower[i]});
        }

        if( (temp = sizeof(obj)) < 2 ) {
                if( !is_busy() ) {
                        COMMAND_DIR"std/halt"->main(this_object());
                        command("escape");
                        destruct(this_object());
                        return 1;
                }
                return 1;
        }

        if( !objectp(ob = offensive_target(this_object())) ) return 1;
        if( !userp(ob) ) return 1;
        for(i = 0; i < temp; i++) {
                if( obj[i]->is_fighting(ob) ) continue;
                message_vision("$N对着$n吼道：还楞着干吗？\n", this_object(), obj[i]);
                message_vision("$N诚惶诚恐地说道：望帮主恕罪！\n", obj[i]);
                obj[i]->kill_ob(ob);
        }
        return 1;
}
*/          

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void die()
{
        object ob, corpse, killer;

        if( !living(this_object()) ) revive(1);
        clear_condition();

        if( objectp(killer = query_temp("last_damage_from")) ) {
                ob = new(BANGYIN);
                ob->set("long", query("title") + ob->query("name") + "。\n");
                ob->move(environment());
                message_vision(HIR"\n突然从$N衣袋中掉下一" + ob->query("unit") + ob->name() + "。\n"NOR, this_object());
                set_temp("my_killer", killer->query("id"));
                ob->set("my_killer",  killer->query("id"));
                ob->set("combat_exp", query("combat_exp"));
        }
    
        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        dismiss_team();
        destruct(this_object());
}

#include "/d/huanghe/npc/bangzhu_duty.h";
#include "/d/huanghe/doc/set_bang.h";
