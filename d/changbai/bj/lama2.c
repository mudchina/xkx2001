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

int is_splama() { return 1; }

void create()
{
        set_name("密宗二老", ({ "erlama" }));
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
        set("jiali", 0);

        set("combat_exp", 500000 + random(500000));

        set_temp("apply/armor", 200);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 40 + random(40));

        set_skill("necromancy", 300);
        set_skill("lamaism", 300);

        set_skill("force", 150 + random(50));
        set_skill("dodge", 150 + random(50));
        set_skill("parry", 150 + random(50));
        set_skill("strike", 150 + random(50));
        set_skill("hammer", 150 + random(50));

        set_skill("longxiang-banruo", 150 + random(50));
        set_skill("shenkongxing", 150 + random(50));
        set_skill("huoyan-dao", 150 + random(50));
        set_skill("riyue-lun", 150 + random(50));

        map_skill("force", "longxiang-banruo");
        map_skill("dodge", "shenkongxing");
        map_skill("parry", "riyue-lun");
        map_skill("strike", "huoyan-dao");
        map_skill("hammer", "riyue-lun");

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
        carry_object("/d/qilian/obj/lubo")->wield();
        carry_object("/d/qilian/obj/klguan")->wear();
        carry_object("/d/qilian/obj/rtlian")->wear();
}

int auto_perform()
{
        object weapon, victim, obj, ob = this_object(), *inv;
        int i;
 
        victim = offensive_target(ob);

        command("hehe " + victim->query("id"));

        if( !(obj = present("lubo", ob)) ) {
                obj = new("/d/qilian/obj/lubo");
                obj->move(ob);
                COMMAND_DIR"std/halt"->main(ob);
                message_vision("$N从袈裟中抽出一" + obj->query("unit") + obj->name() + "来。\n", ob);
                "/cmds/std/wield"->do_wield(ob, obj);
                ob->kill_ob(victim);
        } else if( !obj->query("equipped") ) {
                COMMAND_DIR"std/halt"->main(ob);
                "/cmds/std/wield"->do_wield(ob, obj);
                ob->kill_ob(victim);
        }

        if( !(obj = present("kulou guan", ob)) ) {
                obj = new("/d/qilian/obj/klguan");
                obj->move(ob);
                COMMAND_DIR"std/halt"->main(ob);
                message_vision("$N从袈裟中拿出一" + obj->query("unit") + obj->name() + "来。\n", ob);
                "/cmds/std/wear"->do_wear(ob, obj);
                ob->kill_ob(victim);
        } else if( !obj->query("equipped") ) {
                COMMAND_DIR"std/halt"->main(ob);
                "/cmds/std/wear"->do_wear(ob, obj);
                ob->kill_ob(victim);
        }

        if( !(obj = present("rentou lian", ob)) ) {
                obj = new("/d/qilian/obj/rtlian");
                obj->move(ob);
                COMMAND_DIR"std/halt"->main(ob);
                message_vision("$N从袈裟中拿出一" + obj->query("unit") + obj->name() + "来。\n", ob);
                "/cmds/std/wear"->do_wear(ob, obj);
                ob->kill_ob(victim); 
        } else if( !obj->query("equipped") ) {
                COMMAND_DIR"std/halt"->main(ob);
                "/cmds/std/wear"->do_wear(ob, obj);
                ob->kill_ob(victim);
        } 

        call_other("/d/changbai/bj/sing2", "exert", ob, victim);

        inv = all_inventory(environment(ob));
        for(i = 0; i < sizeof(inv); i++ ) {
                if( strsrch(inv[i]->query("name"), "断掉的") == 0 )
                          destruct(inv[i]);
        }

        return 1;
}

#include "/d/changbai/bj/lama.h";









