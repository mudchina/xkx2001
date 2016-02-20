//Cracked by Roath
// /d/huanghe/doc/set_bang.h
// by aln 2 / 98

#ifndef BANGZHONG
#define BANGZHONG  "/d/huanghe/npc/bangzhong"
#endif

void set_bang(object owner)
{
        object ob, *obj = ({}), room = environment(owner);

        if( !room ) return;

        ob = new(BANGZHONG);
        set_follower(ob, owner);
        ob->move(room);
        obj += ({ob});

        ob = new(BANGZHONG);
        set_follower(ob, owner);
        ob->move(room);
        obj += ({ob});

        owner->set("follower", obj);

        message("vision",
                ob->name() + "×ßÁË¹ıÀ´¡£\n",
                room, ({ob}));
        message_vision("$N¶Ô×Å$n×÷ÁË¸öÒ¾£¬µÀ£º°ïÖ÷ÀÏÈË¼ÒĞÁ¿àÁË¡£\n", ob, owner);
        message_vision("$NµãÁËµãÍ·£¬µÀ£ºµÜĞÖÃÇĞÁ¿àÁË¡£\n", owner);
}


void set_follower(object ob, object owner)
{
        string fam, name;
        string *bc_skills, *weapons;
        int i, exp, level;

        ob->set("owner", owner);
        ob->set_leader(owner);

        fam = (string)owner->query("fam");
        ob->set("title", fam);

        exp = (int)owner->query("combat_exp") / 2;
        ob->set("combat_exp", exp);
        level = ceil( pow( to_float(exp) * 10.0, 0.333333) ) * 4 / 5;

        ob->set("max_qi",    level * 8 + 100);
        ob->set("eff_qi",    level * 8 + 100);
        ob->set("qi",        level * 8 + 100);
        ob->set("max_jing",  level * 5 + 100);
        ob->set("eff_jing",  level * 5 + 100);
        ob->set("jing",      level * 5 + 100);
        ob->set("max_neili", level * 6 + 200);
        ob->set("neili",     level * 6 + 200);
        ob->set("max_jingli",level * 5 + 150);
        ob->set("jingli",    level * 5 + 150);
        ob->set("jiali", level / 4);

        ob->set_skill("dodge", level);
        ob->set_skill("force", level);
        ob->set_skill("parry", level);

        bc_skills = keys(unarmed_skills);
        ob->set_skill(bc_skills[random(sizeof(bc_skills))], level);

        i = random(sizeof(info_weapon));
        ob->set_skill(info_weapon[i]["type"], level);

        if( !random(2) ) {
                weapons = info_weapon[i]["weapons"];
                ob->carry_object(weapons[random(sizeof(weapons))])->wield();
        }

        level /= 3;
        ob->set_temp("apply/defense", level);
        ob->set_temp("apply/armor",   level);
        ob->set_temp("apply/damage",  level);
        ob->set_temp("apply/attack",  level);

        ob->set("inquiry/" + fam, fam + "ÍşÕğ½­ºş£¬Ö¸ÈÕ¿É´ı£¡£¡£¡");
        name = (string)owner->query("name");
        ob->set("inquiry/" + "°ïÖ÷", "ÎÒ¶ÔÎÒÃÇ" + name[0..01] + "°ïÖ÷µÄ¾°ÑöÖ®Çé¬ÓĞÈçÌÏÌÏ½­Ë®Á¬Ãà²»¾ø¡£");
        ob->set("inquiry/" + name, "Õâ¼¸¸ö×ÖÊÇÄãËµµÄÂğ£¿");
        ob->set("inquiry/" + name[0..01] + "°ïÖ÷", "ÎÒ¶ÔÎÒÃÇ" + name[0..01] + "ïÖ÷µÄ¾°ÑöÖ®Çé£¬ÓĞÈçÌÏÌÏ½­Ë®Á¬Ãà²»¾ø¡£");
}



