//Cracked by Roath
// /d/changbai/bj/bangyin2.c 帮印
// by aln 1 / 98
// modified by aln 4 / 98

#define KILLER  "/d/changbai/bj/killer"

inherit ITEM;

void create()
{
        set_name("帮印", ({ "bangyin" }) );
        set("weight", 30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 30);
                set("material", "wood");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
        }

        setup();

        call_out("message_killer", 20 + random(20));
}

void message_killer()
{
        object ob = this_object(), owner, env, *enemy, killer_ob, weapon;
        string region, attack_skill, skill, bangname;
        int i, danger, bonus, extra, owner_qi, p;
        mapping prepare;

        call_out("message_killer", 10 + random(10));

        if( !(owner = query("owner")) ) {
                destruct(ob);
                return;
        }

        if( environment() != owner ) {
                owner->delete_temp("apply/short");
                owner->delete_temp("shan/bangzhu");
                destruct(ob);
                return;
        }

        env = environment(owner);
        if( env->query("no_fight") )
                return;

        region = explode(base_name(env), "/")[1];
        if( region == "city" )
                return;

   // let players walk around, do not always stay in one region as a bangzhu
        if( region == (string)owner->query_temp("last_region") )
                owner->add_temp("shan/idle", 1);
        else {
                owner->set_temp("last_region", region);
                owner->delete_temp("shan/idle");
        }

        if( (int)owner->query_temp("shan/idle") > owner->query("kar")/2 ) {
                owner->delete_temp("apply/short");
                owner->delete_temp("shan/bangzhu");
                owner->delete_temp("shan/idle");
                destruct(ob); 
                return;
        }

        enemy = owner->query_enemy();
        danger = 0;
        if( sizeof(enemy) ) {
        for(i= 0; i < sizeof(enemy); i++) {
                if( enemy[i]->query("victim") != owner )
                        continue;
                if( enemy[i]->is_busy() )
                        continue;
                if( !enemy[i]->is_fighting(owner) )
                        continue;
                if( (int)enemy[i]->query("jingli") < 100 )
                        continue;
                if( (int)enemy[i]->query("neili") < 50 )
                        continue;

                danger++;
        }
        }

        if( danger < 1 ) {
                killer_ob = new(KILLER);
                killer_ob->set("victim", owner);

                bangname = (string)query("bangname");
                killer_ob->set("bangname", bangname);
                killer_ob->set("inquiry/" + bangname,  "老子想当" + bangname + "帮主都快想疯了！！！");
                killer_ob->set("inquiry/" + "帮印", "老子要的就是" + bangname + "的帮印！");
                killer_ob->set("combat_exp", (int)owner->query("combat_exp") - 1000);
                killer_ob->move(env);
                say(killer_ob->name() + "走了过来。\n");
                message_vision("$N盯了$n一眼。\n", killer_ob, owner);
                killer_ob->set_leader(owner);
                remove_call_out("do_kill");
                call_out("do_kill", 1, killer_ob, owner);

                return;
        }

        bonus = 3 + (int)owner->query("combat_exp")/200000;

        owner_qi = (int)owner->query("max_qi");
        if( danger > 5 ) danger = 5;

        extra = 1 + danger * (danger + 1) / 3; 

        if( random(owner_qi) <  500 )
                bonus *= extra;
        if( random(owner_qi) < danger* 30 && danger > 2)
                bonus *= extra;
        if( random(owner_qi) < danger* 10 && danger > 3)
                bonus *= extra;

        bonus += random(bonus);

        if( bonus > 100 )
                log_file("ShanJob2", sprintf("%s于%s时拿了%s经验点\n", owner->query("name"), ctime(time()), chinese_number(bonus)));

        owner->add("combat_exp", bonus);
}

void do_kill(object killer_ob, object owner)
{
        message_vision("$N对$n大声喝道：" + RANK_D->query_rude(owner) + "！赶快把帮印交给老子！！！\n", killer_ob, owner);
        killer_ob->kill_ob(owner);
}
