//Cracked by Roath
// biaotou.c

inherit NPC;

#include "/d/huanghe/doc/bangskills.h"
#include "/d/huanghe/doc/info_biao.h"

#define BIAOHUO "/d/huanghe/obj/biaohuo"

void create()
{
        string *biaojus, biaoju;
        string *bc_skills, *weapons;
        int i, level, exp = 10000 + random(90000);

        biaojus = keys(info_biaoju);
        biaoju = biaojus[random(sizeof(biaojus))];

        set_name("镖头", ({ "biao tou" }));
        set("nickname", biaoju + "镖局");
        set("gender", "男性");
        set("age", 35);
        set("long",
"一名身材高大的壮汉。\n");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 24);
        set("int", 10);
        set("con", 24);
        set("dex", 24);

        set("combat_exp", exp);
        level = ceil( pow( to_float(exp) * 10.0, 0.333333) ) * 4 / 5;

        set("max_qi",    level * 8 + 100);
        set("max_jing",  level * 5 + 100);
        set("max_neili", level * 6 + 200);
        set("neili",     level * 6 + 200);

        set_skill("dodge", level);
        set_skill("force", level);
        set_skill("parry", level);

        bc_skills = keys(unarmed_skills);
        set_skill(bc_skills[random(sizeof(bc_skills))], level);

        i = random(sizeof(info_weapon));
        set_skill(info_weapon[i]["type"], level);

        level /= 3;
        set_temp("apply/defense", level);
        set_temp("apply/armor",   level);
        set_temp("apply/damage",  level);
        set_temp("apply/attack",  level);

        setup();

        if( !random(2) ) {
                weapons = info_weapon[i]["weapons"];
                carry_object(weapons[random(sizeof(weapons))])->wield();
        }
}

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
                ob = new(BIAOHUO);
                ob->set("my_killer", killer->query("id"));
                ob->set("combat_exp", (int)query("combat_exp"));
                ob->move(this_object());
        }

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        dismiss_team();
        destruct(this_object());
}

