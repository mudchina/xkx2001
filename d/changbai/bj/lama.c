//Cracked by Roath
//  /d/changbai/bj/lama.c
// by Aln 2/98

#include <ansi.h>
#include <command.h>

inherit F_SSERVER;
inherit NPC;

int ask_lama(string);
int auto_check();
int auto_perform();
int auto_disappear();
void destroy(object);

void create()
{
        set_name("密宗大老", ({ "dalama" }));
        set("long",
"他身穿黄色袈裟，目光炯炯双拳紧握，全身肌肉紧匝得几乎快要爆裂。\n"
"他孤陋寡闻，只知道喇嘛，拉萨，西藏和密宗。\n");
        set("gender", "男性");
        set("age", 30 + random(20));
        set("attitude", "heroism");
        set("class","bonze");
        set("shen_type", -1);

        set("str", 40);
        set("int", 20);
        set("con", 40);
        set("dex", 25);

        set("max_qi", 2500);
        set("max_jing", 2000);
        set("max_neili", 2500);
        set("neili", 2500);
        set("jiali", 60);

        set("combat_exp", 500000 + random(50000));

        set_temp("apply/armor", 200);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 40 + random(40));

        set_skill("necromancy", 100);
        set_skill("lamaism", 100);

        set_skill("force", 150 + random(50));
        set_skill("dodge", 150 + random(50));
        set_skill("parry", 150 + random(50));
        set_skill("strike", 150 + random(50));

        set_skill("longxiang-banruo", 150 + random(50));
        set_skill("shenkongxing", 150 + random(50));
        set_skill("huoyan-dao", 150 + random(50));

        map_skill("force", "longxiang-banruo");
        map_skill("dodge", "shenkongxing");
        map_skill("parry", "huoyan-dao");
        map_skill("strike", "huoyan-dao");

        prepare_skill("strike", "huoyan-dao");

        set("chat_chance", 5);
        set("chat_msg",({
                (: auto_disappear :)
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_check :),
                (: auto_perform :),
        }) );

        set("inquiry",([
                  "喇嘛" : (: ask_lama, "lama" :),
                  "拉萨" : (: ask_lama, "lasa" :),
                  "西藏" : (: ask_lama, "lasa" :),
                  "密宗" : (: ask_lama, "flirt" :),
        ]));

        setup();
        carry_object("/d/qilian/obj/lamajiasha")->wear();
}

int auto_perform()
{
        object victim, ob = this_object();

        call_other("/kungfu/skill/longxiang-banruo/shield", "exert", ob, ob);

        victim = offensive_target(ob);

        if( (int)ob->query("neili") <= 500 ) return 1;

        if( victim->query_temp("cursed") ) {
                command("haha " + victim->query("id"));
                ob->add_temp("apply/attack", 50);
                ob->add_temp("apply/damage", 50);
      call_other("/d/changbai/bj/fen2", "perform", ob, victim);
                ob->add_temp("apply/attack", -50);
                ob->add_temp("apply/damage", -50);
        } else
      call_other("/d/changbai/bj/fen2", "perform", ob, victim);

        return 1;
}

void die()
{
        object lama, ob, corpse, killer, room;
        int bonus, exp;

        if( !living(this_object()) ) revive(1);
        this_object()->clear_condition();

        if( objectp(killer = query_temp("last_damage_from")) ) {
                if( !( room = find_object("/d/taishan/fengchan")) )
                        room = load_object("/d/taishan/fengchan");

                if( userp(killer) && killer->query("id") != room->query("winner")) {
                        ob = new("/d/changbai/bj/sword");
                        ob->move(environment(this_object()));
                        ob->set("my_killer", killer->query("id"));
                        message_vision(HIR"\n突然从$N衣袋中掉下一" + ob->query("unit") + ob->name() + "。\n"NOR, this_object());

                        bonus = 100 + (int)query("combat_exp")/3000;

          // decrease bonus if players kill erlama at first
          // because, without erlama, this job is much easier
               if( !(lama = present("erlama", environment(this_object()))) )
                        bonus /= 2;
               else if( !living(lama) )
                        bonus += (int)lama->query("combat_exp")/10000;
               else     bonus += (int)lama->query("combat_exp")/3000;

                        exp = (int)killer->query("combat_exp")/1000 + 1;
                        if( exp < 500 ) exp = 500;
                        bonus = bonus * 1000 / ( exp + 500);

                        ob->set("bonus", bonus);

                        if( lama ) {
                               if( !lama->is_busy() ) {
                                      COMMAND_DIR"std/halt"->main(lama);
                                      GET_CMD->do_get(lama, ob);
                                      destroy(lama);
                               }
                        } 
                }
        }

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        this_object()->dismiss_team();
        destruct(this_object());
}

#include "/d/changbai/bj/lama.h";

