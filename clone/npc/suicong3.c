//Cracked by Roath


#include <ansi.h>

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
 
inherit NPC;
inherit F_SAVE;

int auto_perform();

void create()
{
        set_name("随从", ({ "sui cong", "sui" }));

        set("long", 
        "这是一个忠心耿耿的随从。\n");
        set("gender", "男性");
        set("age", 34);
        set("attitude", "heroism");
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 1200);
        set("max_jing", 1200);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 100000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("blade", 100);
        set_skill("strike", 100);
        set_skill("cuff", 100);
        set_skill("huashan-jianfa", 100);
        set_skill("liangyi-dao", 100);
        set_skill("huashan-shenfa", 100);
        set_skill("zixia-gong", 100);
	set_skill("pishi-poyu", 100);
	set_skill("hunyuan-zhang", 100);
 
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "pishi-poyu");
        map_skill("dodge", "tiyunzong");
        map_skill("sword", "huashan-jianfa");
        map_skill("blade", "liangyi-dao");
        
        prepare_skill("cuff", "pishi-poyu");
        prepare_skill("strike", "hunyuan-zhang");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}));

        setup();
        carry_object("/d/xixia/obj/robe")->wear();
	carry_object("/d/city/obj/gangjian")->wield();
}

string query_save_file()
{
    object me = this_object();
    string master = query("master");
    int serial = query("serial");

    if (master){
	return NPCDATA+"suicong/"+serial;
    }else{
	return NPCDATA+"suicong/none";
    }
}

void new_master(object player, int serial)
{
    set("master", player->query("id"));
    set("serial", serial);

    // TODO: we can set the init status of the
    // suicong according to the status of the player.

    save();	
}


int is_suicong_of(object player)
{
    restore();
    if (player->query("id") == query("master")){
        return query("serial");
    }else{
	return 0;
    }
}

int reload_suicong(object player, int serial)
{
    set("master", player->query("id"));
    set("serial", serial);

    restore();    
}

void remove_suicong(object player, int serial)
{
    set("master", player->query("id"));
    set("serial", serial);
    rm(query_save_file());
}


int auto_perform()
{
        object me=this_object();
        object weapon=me->query_temp("weapon");
        object opp=me->select_opponent();

        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi")/2 )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "sword" )
                        return perform_action("sword.jianzhang");
        }
        else if ( !me->query_temp("leidong") ) {
                        return perform_action("cuff.leidong");
        }
        else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
                        return perform_action("strike.wuji");
        }
}

