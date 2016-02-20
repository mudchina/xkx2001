//Cracked by Roath
// /d/changbai/bj/zhanglao.c

#include <ansi.h>
#include <localtime.h>
inherit NPC;
inherit F_SSERVER;

#include "/d/changbai/bj/xkxskills.h"
#include "/d/changbai/bj/info_zhanglao.h"

string ask_me(string);
int auto_perform();
int auto_check();

int is_mjzhanglao() { return 1; }

void create()
{
        object *obj;
        string *zl_names, zl_name, *zl_id;

        string bc_skill, *bc_skills, sp_skill, *sp_skills;
        int i, temp, level, exp, extra;

        zl_names = keys(zl_ids);
        obj = filter_array(children(__FILE__), (: clonep :));
        if( temp = sizeof(obj) ) {
                for(i = 0; i < temp; i++) {
                        zl_names -= ({obj[i]->query("name")});
                }
        }

        if( !sizeof(zl_names) ) {
                zl_name = "魔教长老",
                zl_id = ({ "mojiao zhanglao", "zhanglao" });
        } else {
                zl_name = zl_names[random(sizeof(zl_names))];
                zl_id = zl_ids[zl_name];
        }

        set_name(zl_name, zl_id);
        set("title", "魔教长老");
        set("gender", "男性");
        set("age", 60 + random(20));
        set("long",
"一名白须老者，两边太阳穴高高突起，便如藏了一枚核桃相似。\n");
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_perform :),
                (: auto_check :),
        }) );

        set("max_qi", 3000);
        set("max_jing", 2000);
        set("max_neili", 2500);
        set("neili", 2500);

        exp = 1200000 + random(600000);
        set("combat_exp", exp);

        extra = exp / 30000;
        extra += random(extra);
        set_temp("apply/damage", extra);
        set_temp("apply/speed", 2 * extra);
        set_temp("apply/defense", extra / 2);
        set_temp("apply/attack", extra / 2);
        set_temp("apply/armor", 100 + 2 * extra);

        level = ceil( pow( to_float(exp) * 10.0, 0.333333) ) * 4 / 5;

        set_skill("force", level);
        sp_skill = force_skills[random(sizeof(force_skills))];
        set_skill(sp_skill, level);
        map_skill("force", sp_skill);

        set_skill("dodge", level);
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
        prepare_skill(bc_skill, sp_skill);

        set_skill("stick", level);
        set_skill("mo-bang", level);
        map_skill("stick", "mo-bang");
        map_skill("parry", "mo-bang");

        set("inquiry", ([
                  "魔教" : (: ask_me, "魔教" :),
                  "长老" : (: ask_me, "长老" :),
        ]));

        setup();

        carry_object(zl_weapons[random(sizeof(zl_weapons))])->wield();
}

string ask_me(string arg)
{
        switch(arg) {
        case "魔教":
                command("stare " + this_player()->query("id"));
                return "什么魔教不魔教？！再说魔教俩字我杀了你！！！";
        case "长老":
                command("haha");
                return "想当年我们十长老杀尽五岳剑派是何等气势！哈！哈！哈！";
	}
}

int auto_perform()
{
        object weapon, *inv, ob = this_object(), victim;
        int i, temp;

        inv = all_inventory(environment(ob));
        for(i = 0; i < sizeof(inv); i++ ) {
                if( strsrch(inv[i]->query("name"), "断掉的") == 0 )
                          destruct(inv[i]);
        }

        if( !objectp(weapon = ob->query_temp("weapon")) ) {
                inv = all_inventory(ob);
                if( temp = sizeof(inv) ) {
                        for(i = 0; i < temp; i++ ) {
                                if( inv[i]->query("skill_type") == "stick" ) {
                                         weapon = inv[i];
                                         COMMAND_DIR"std/halt"->main(ob);
                                         "/cmds/std/wield"->do_wield(ob, weapon);
                                         victim = offensive_target(ob);
                                         ob->kill_ob(victim);
                                         break;
                                }
                        }
                }

                if( !weapon ) {
                        weapon = new(zl_weapons[random(sizeof(zl_weapons))]);
                        weapon->move(ob);
                        COMMAND_DIR"std/halt"->main(ob);
                        message_vision(HIR"$N从背袋中抽出一" + weapon->query("unit") + weapon->name() + "来。\n"NOR, ob);
                        "/cmds/std/wield"->do_wield(ob, weapon);
                        victim = offensive_target(ob);
                        ob->kill_ob(victim);
                }
        }

        if( !random(2) )  return perform_action("stick.mo");

        return 1;
}

int auto_check()
{
        object ob, room, weapon, me = this_object();
        string skill, attack_skill, v_id = (string)me->query("bj_victim");
        mapping prepare;
        int bonus, p, extra, ob_qi;

        if( !v_id ) return 1;

        if( (!ob = present(v_id, environment(me))) )
                return 1;

        if( !me->is_fighting(ob) ) return 1;

        if( !me->is_killing(v_id) ) return 1;

        if( me->is_busy() ) return 1;

        if( sizeof(me->query_enemy()) > 1 ) return 1;

        if( !( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");
        if( v_id == room->query("winner") ) 
                return 1;

        if( !( room = find_object("/d/taishan/xiayi")) )
                room = load_object("/d/taishan/xiayi");
        if( v_id == room->query("winner") ) 
                return 1;

        if( !( room = find_object("/d/taishan/zhengqi")) )
                room = load_object("/d/taishan/zhengqi");
        if( v_id == room->query("winner") ) 
                return 1;

        if( (int)me->query("eff_qi") * 10 < (int)me->query("max_qi") ) 
                return 1;

        if( (int)me->query("neili") < 50 )
                return 1;

        bonus = 100 * ((int)ob->query("int") + (int)ob->query("str")) / 
                     ((int)ob->query("con") + (int)ob->query("dex"));
        bonus = bonus * bonus * bonus / 100000;

        extra = 100 * (int)me->query("combat_exp") / ((int)ob->query("combat_exp") + 1000);
        extra = extra * extra / 1000;
        bonus += extra;

        ob_qi = (int)ob->query("max_qi");
        if( ob_qi < 800 )  ob_qi = 800;
        bonus = bonus * 1200 / ob_qi * 1200 / ob_qi * 1200 / ob_qi;

        if( !objectp(weapon = ob->query_temp("weapon")) )
                bonus *= 3;

        bonus = bonus/2 + random(bonus);

        ob->improve_skill("dodge", bonus);
        if( stringp(skill = ob->query_skill_mapped("dodge")) )
        ob->improve_skill(skill, bonus);

        if( (int)ob->query_skill("force", 1) < 200 )
                ob->improve_skill("force", bonus/3);
        if( stringp(skill = ob->query_skill_mapped("force")) ) {
        if( (int)ob->query_skill(skill, 1) < 200 )
                ob->improve_skill(skill, bonus/3);
        }

        ob->improve_skill("parry", bonus);

        if( ob->query_temp("yield") ) {
                ob->add("combat_exp", bonus/2);
                return 1;
        }

        ob->add("combat_exp", bonus);
        if( bonus > 100 )
                log_file("ShanJob3", sprintf("%s于%s时拿了%s经验点\n", ob->query("name"), ctime(time()), chinese_number(bonus)));

        if( objectp(weapon) ) {
                attack_skill = weapon->query("skill_type");
                ob->improve_skill(attack_skill, bonus);
        if( stringp(skill = ob->query_skill_mapped(attack_skill)) )
                ob->improve_skill(skill, bonus);
        } else {
                prepare = ob->query_skill_prepare();
                for(p = 0; p < sizeof(prepare); p++) {
                        attack_skill = (keys(prepare))[p];
                        ob->improve_skill(attack_skill, bonus);
                if( stringp(skill = ob->query_skill_mapped(attack_skill)) )
                        ob->improve_skill(skill, bonus);
                }
	}

        return 1;
}
        
void die()
{
        object corpse, killer, room, me = this_object(), exp;
        int bonus, period;

        if( !living(me) ) revive(1);
        me->clear_condition();

        if( objectp(killer = me->query_temp("last_damage_from"))
        && sizeof(me->query_enemy()) < 2 ) {
                if( killer->query("id") == me->query("bj_victim") ) {
                        if( !( room = find_object("/d/taishan/fengchan")) )
                                room = load_object("/d/taishan/fengchan");

                        if( killer->query("id") != room->query("winner") ) {
                                period = time() - (int)killer->query("shan/s3time");
                                if( period > 1800 )  period = 1800;
     bonus = period * 160000 / ( 800000 + (int)killer->query("combat_exp") );
                                bonus += random(bonus);
                                killer->add("combat_exp", bonus );

                                killer->set("shan/s3time", time());

          log_file("ShanBonus", sprintf("%s于%s时杀%s拿了%s经验点\n", killer->query("name"), ctime(time()), me->name(), chinese_number(bonus)));

                                bonus /= 4;
                                killer->add("potential", bonus);
           if( killer->query("potential") > killer->query("max_potential") )
                     killer->set("potential", killer->query("max_potential"));
                        }
                }
        }

        COMBAT_D->announce(me, "dead");
        if( objectp(corpse = CHAR_D->make_corpse(me, killer)) )
                corpse->move(environment());
        me->remove_all_killer();
        all_inventory(environment())->remove_killer(me);

        me->dismiss_team();
        destruct(me);
}

void unconcious()
{
        object killer, me = this_object();
        int ap, dp;

        if( objectp(killer = me->query_temp("last_damage_from")) ) {
                if( userp(killer) && !me->is_busy() ) {
                        ap = (int)killer->query_skill("dodge");
                        ap = ap * ap * ap / 3 + (int)killer->query("combat_exp");
                        ap *= killer->query("dex");

                        dp = (int)me->query_skill("dodge");
                        dp = dp * dp * dp / 3 + (int)me->query("combat_exp");
                        dp *= me->query("dex");

                        if( random(dp + ap) > ap ) {
                                command("fear " + killer->query("id"));
                                message("vision",
                                        me->name() + "急急忙忙地离开了。\n",
                                        environment(me), ({me}));
                                destruct(me);
                                return;
                        }
                }
	}

        me->disable_player(" <昏迷不醒>");
        me->set("jing", 0);
        me->set("qi", 0);
        COMBAT_D->announce(me, "unconcious");

        remove_call_out("revive");
        call_out("revive", random(100 - me->query("con")) + 30);
}

varargs void revive(int quiet)
{
        remove_call_out("revive");
        while( environment()->is_character() )
                this_object()->move(environment(environment()));
        this_object()->enable_player();
        COMBAT_D->announce(this_object(), "revive");
}


