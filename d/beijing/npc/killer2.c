//Cracked by Roath
inherit NPC;
inherit F_SSERVER;

#include "/d/beijing/beijing_defs.h"
#include "/d/beijing/job_info.h"

int do_move();

void create()
{
    set_name("江湖汉子", ({
	    "jianghu hanzi", "han",
    }));
    set("long",
	"这是一个风尘扑扑的江湖汉子，一看就知道身怀武功。\n"
    );


    set("gender", "男性");
    set("attitude", "heroism");

    set("age", 25);
    set("shen_type",10000);
    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);
    set("max_qi", 800);
    set("max_jing", 800);
    set("neili", 1000);
    set("max_neili", 1000);
    set("combat_exp", 200000);
    set("score", 100);
    set("jiali", 50);
        

    set_skill("force", 80);
    set_skill("taiji-shengong", 80);
    set_skill("dodge", 80);
    set_skill("parry", 80);
    set_skill("tiyunzong", 80);
    set_skill("cuff", 80);
    set_skill("taiji-quan", 80);
    set_skill("sword",80);
    set_skill("taiji-jian",80);

    map_skill("force", "taiji-shengong");
    map_skill("sword", "taiji-jian");
    map_skill("cuff", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("dodge", "tiyunzong");
    prepare_skill("cuff", "taiji-quan");

    set("shiwei_level", 2);

    setup();

    carry_object("/clone/armor/cloth")->wear();
    carry_object("/clone/weapon/gangjian")->wield();

}

void init()
{
    remove_call_out("do_move");
    call_out("do_move", 10);
}

void upgrade(int level)
{
    set("shiwei_level", level);
    set_skill("force", 120);
    set_skill("taiji-shengong", 120);
    set_skill("dodge", 120);
    set_skill("parry", 120);
    set_skill("tiyunzong", 120);
    set_skill("cuff", 120);
    set_skill("taiji-quan", 120);
    set_skill("sword",120);
    set_skill("taiji-jian", 120);
    set("jiali", 100);
    set("combat_exp", 400000);
}

void do_move()
{
    object me = this_object();
    object env = environment(me);

    if (query_temp("no_move")) return;

    if (! env) destruct(me);

    if (env->query("is_inner_gate")) {	// we are at gate
	if (!me->is_fighting()) {
	    if (random(2) == 0) command("go south");
	    else command("go east");
	}
	call_out("do_move", 10);
	set_temp("attempt", 0);
    } else {
	message_vision("$N走进了人群，一会儿就不见了。\n", me);
	destruct(me);
    }
}

void die()
{
    object me = this_object();
    object env = environment(me);
    object player, *inv;
    int    kill_num, i, found_shiwei=0;

    inv = all_inventory(env);
    if (me->query_temp("pancha_stage")==3 && inv) {
	for (i=0; i<sizeof(inv); i++){
	    if (inv[i]->is_character() && IS_SHIWEI(inv[i]) && 
		is_fighting(inv[i]) &&
		SHIWEI_LEVEL(inv[i]) == query("shiwei_level") &&
		inv[i]->query_temp("can_pancha") ) {
		found_shiwei++;
		message_vision("\n$N一脚踢开$n的尸体，得意地笑了笑。\n",
		    inv[i], me);
		player = inv[i];
		if (env->query("is_inner_gate")){
		    kill_num = player->query_temp("kill_num");
		    player->set_temp("kill_num", kill_num+1);
		}
	    }
	}
    }
    if (! found_shiwei){
	message_vision("\n$N倒在地上，挣扎了几下就死了。\n", me);
    }


    destruct(me);
}
