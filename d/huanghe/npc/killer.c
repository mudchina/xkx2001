//Cracked by Roath
// /d/changbai/bj/killer.c

#include <ansi.h>
inherit NPC;

#include "/d/huanghe/doc/xkxskills.h"
#include "/d/huanghe/doc/info_killer.h"

int auto_check();
int do_destroy(object);

void create()
{
        string *killer_names = keys(info_killer);
        string killer_name = killer_names[random(sizeof(killer_names))];

        set_name(killer_name, ({ info_killer[killer_name] }));
        set("gender", "男性");
        set("age", 50 + random(20));
        set("long",
"一名白须老者，两边太阳穴高高突起，便如藏了一枚核桃相似。\n");
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 5000);
	set("max_jing", 3000);

        set("combat_exp", 500000);

        set("chat_chance", 10);
        set("chat_msg",({
                (: auto_check :)
        }));

        setup();

        call_out("set_data", 1, this_object());
}

void set_data(object ob)
{
        string bc_skill, *bc_skills, sp_skill, *sp_skills, *weapons;
        string weapon_skill, unarmed_skill, force_skill, dodge_skill;
        int i, level, exp, extra;

        exp = ob->query("combat_exp");
        exp = (4 * exp + random(2 * exp)) / 7;

        level = ceil( pow( to_float(exp) * 10.0, 0.333333) ) * 4 / 5;

        ob->set("max_qi", level * 10 + 1000);
        ob->set("eff_qi", level * 10 + 1000);
        ob->set("qi", level * 10 + 1000);
        ob->set("max_jing", level * 5 + 500);
        ob->set("eff_jing", level * 5 + 500);
        ob->set("jing", level * 5 + 500);
        ob->set("max_neili", level * 8 + 1000);
        ob->set("neili", level * 8 + 1000);

        extra = exp / 20000;
        extra = random(2 * extra);
        ob->set_temp("apply/defense", extra / 2);
        ob->set_temp("apply/armor", extra * 2);
        ob->set_temp("apply/damage", extra / 4);
        ob->set("jiali", extra / 3);

        ob->set_skill("force", level);
        sp_skill = force_skills[random(sizeof(force_skills))];
        ob->set_skill(sp_skill, level);
        ob->map_skill("force", sp_skill);

        ob->set_skill("dodge", level);
        sp_skill = dodge_skills[random(sizeof(dodge_skills))];
        ob->set_skill(sp_skill, level);
        ob->map_skill("dodge", sp_skill);

        bc_skills = keys(unarmed_skills);
        bc_skill = bc_skills[random(sizeof(bc_skills))];
        ob->set_skill(bc_skill, level);
        sp_skills = unarmed_skills[bc_skill];
        sp_skill = sp_skills[random(sizeof(sp_skills))];
        ob->set_skill(sp_skill, level);
        ob->map_skill(bc_skill, sp_skill);
        ob->map_skill("parry", sp_skill);
        ob->prepare_skill(bc_skill, sp_skill);

        i = random(sizeof(info_weapon));
        bc_skill = info_weapon[i]["type"];
        weapons = info_weapon[i]["weapons"];
        sp_skills = info_weapon[i]["skills"];
        sp_skill = sp_skills[random(sizeof(sp_skills))];

        ob->set_skill(bc_skill, level);
        ob->set_skill(sp_skill, level);
        ob->map_skill(bc_skill, sp_skill);

        if( !random(2) ) {
              ob->map_skill("parry", sp_skill);
              ob->carry_object(weapons[random(sizeof(weapons))])->wield();
        }
}

void init()
{
        ::init();

        add_action("do_check", "exert");
        add_action("do_check", "yun");

        add_action("do_ask", "ask");
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

        call_other("/d/huanghe/skills/play2", "exert", this_object(), this_object());
        return 1;
}

int do_ask(string arg)
{
        string dest, topic;
  
        if( !arg || sscanf(arg, "%s about %s", dest, topic) != 2 )
                 return notify_fail("");

        if( dest != this_object()->query("id") )
                 return notify_fail("");

        if( !this_object()->is_killing(this_player()->query("id")) ) {
                 command("say 你找死？！还不给我快点滚开！！！");
                 return 1;
        }

        command("say 废话少说，拿命来吧！！！");
        return 1;
}

void die()
{
        object corpse, killer;

        if( !living(this_object()) ) revive(1);
        this_object()->clear_condition();

        if( objectp(killer = query_temp("last_damage_from")) ) {
                if( killer == query("victim") )
                        killer->add("combat_exp", 10 + random(10));
        }

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        this_object()->dismiss_team();
        destruct(this_object());
}

void unconcious()
{
        object killer;

        if( objectp(killer = query_temp("last_damage_from")) ) {
                if( killer == query("victim") ) {
                        killer->add("combat_exp", 10 + random(10));
                        say(name() + "长叹一声便扬长而去。\n");
                        this_object()->remove_all_killer();
                        all_inventory(environment())->remove_killer(this_object());
                        this_object()->dismiss_team();
                        destruct(this_object());
                }
        }
}

int do_destroy(object ob)
{
        COMMAND_DIR"std/halt"->main(ob);
        message("vision",
                ob->name() + "急急忙忙地离开了。\n",
                environment(ob), ({ob}));
        destruct(ob);
        return 1;
}

int auto_check()
{
        object room, victim, ob = this_object(), dest;

        if( !living(ob) ) return 1;
        if( is_busy() ) return 1;


        if( !(room = environment()) ) 
                return do_destroy(ob);

        if( !mapp(room->query("exits")) )
                return do_destroy(ob);

        if( room->query("no_fight") ) {
                command("shrug");
                return do_destroy(ob);
        }

        if( !(victim = query("victim")) ) {
                command("sigh");
                return do_destroy(ob);
        }

        if( !present("bangyin", victim) ) {
                command("disapp");
                return do_destroy(ob);
        }

        dest = environment(victim);
        if( room == dest ) return 1;

        message("vision",
                ob->name() + "急急忙忙地离开了。\n",
                room, ({ob}));
        ob->move(dest);
        message("vision",
                ob->name() + "走了过来。\n",
                dest, ({ob}));

        message_vision(HIR"$N对$n大声喝道：" + RANK_D->query_rude(victim) + "我看你这次还往哪里跑？！\n\n"NOR, ob, victim);
        ob->set_leader(victim);
        ob->kill_ob(victim);
        return 1;
}

