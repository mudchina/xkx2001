//Cracked by Roath
inherit NPC;
inherit F_SSERVER;

#include "/d/beijing/beijing_defs.h"
#include "/d/beijing/job_info.h"

int do_move();

void create()
{
    set_name("壮汉", ({
	    "zhuang han", "han",
    }));
    set("long",
	"这是一个满脸横肉的乡下汉子。\n"
    );


    set("gender", "男性");
    set("attitude", "heroism");

    set("age", 25);
    set("shen_type",10000);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("max_qi", 400);
    set("max_jing", 400);
    set("neili", 600);
    set("max_neili", 600);
    set("combat_exp", 50000);
    set("score", 100);

    set("shiwei_level", 0);
        

    set_skill("force", 80);
    set_skill("dodge", 80);
    set_skill("cuff", 80);
    set_skill("parry", 80);
    set_skill("blade",80);

    setup();

    carry_object("/clone/armor/cloth")->wear();
    carry_object("/clone/weapon/gangdao")->wield();

}

void init()
{
    remove_call_out("do_move");
    call_out("do_move", 10);
}

void upgrade(int lvl)
{
    set("combat_exp", 100000);
    set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("cuff", 100);
    set_skill("parry", 100);
    set_skill("blade",100);
    set("shiwei_level", 1);
}

void do_move()
{
    object me = this_object();
    object env = environment(me);

    if (query_temp("no_move")) return;
    if (! env) destruct(me);

    if (env->query("is_outer_gate")) {	// we are at gate
	if (! me->is_fighting())
	    command("go "+env->query("enter_dir"));
	call_out("do_move", 10);
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
    if (inv) {
	for (i=0; i<sizeof(inv); i++){
	    if (inv[i]->is_character() && IS_SHIWEI(inv[i]) && 
		SHIWEI_LEVEL(inv[i]) == query("shiwei_level") &&
		is_fighting(inv[i]) && 
		inv[i]->query_temp("can_allow") ) {
		message_vision("\n$N踢了一脚$n的尸体，得意地笑了笑。\n",
		    inv[i], me);
		player = inv[i];
		if (env->query("is_outer_gate")){
		    kill_num = player->query_temp("kill_num");
		    player->set_temp("kill_num", kill_num+1);
		}
		found_shiwei ++;
	    }
	}
    }
    if (! found_shiwei) {
	message_vision("\n$N倒在地上，挣扎了几下就死了。\n", me);
    }


    destruct(me);
}
