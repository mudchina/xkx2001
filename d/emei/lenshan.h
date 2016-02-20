//Cracked by Roath
void init() {
    remove_call_out("shine");
    call_out("shine", 5+random(5));
    add_action("do_lingwu", "lingwu");
}

int shine() {
    object me = this_object();
    object *inv = all_inventory(me);
    object player;
    int i;

    for (i=0; i<sizeof(inv); i++) {
   	player = inv[i];

	if (environment(player) != me) continue;
	if (player->query_skill("linji-zhuang", 1) < 150) continue;
	if (player->query_temp("lenshan/canlingwu") == 1) continue;

	tell_object(player, "你看见林中日光若隐若现, 枝叶似死实生, 心中不禁一动.\n");
	player->set_temp("lenshan/canlingwu", 1);
    }
    return 1;
}

int do_lingwu() {
    object player=this_player();
    int neili, force, ljz;

    if (player->query_temp("lenshan/canlingwu")!=1) return 0;
    if ((ljz=player->query_skill("linji-zhuang", 1)) < 180) {
	return notify_fail("你的临济庄火候不到, 无法领悟.\n");
    }
    if ((force=player->query_skill("force", 1)) < ljz*2/3) {
	return notify_fail("你的基本内功火候不到, 无法领悟.\n");
    }
    if (player->query("jingli") < 100 ||
	player->query("qi") < 100 ||
	player->query("neili") < 200 ||
	player->query("jing") < 200) {
	return notify_fail("你自身状态不佳, 无法领悟.\n");
    }
    if (! SKILL_D("linji-zhuang")->valid_learn(player)) {
	return notify_fail("你体内几种真气互相冲撞, 燥热难当.\n");
    }

    message_vision("$N盘腿坐下, 默想周天搬运乾坤挪移的要旨, 似有所悟.\n",
	player, 0);
    neili=player->query("neili");
    player->set("neili", 100);
    player->set("jing", 100);
    
    // normal lian (zxg, htqg) costs 60 neili to gain 1+force/5
    // points, here we do the same.
    player->improve_skill("linji-zhuang", force*(neili-100)/300);
    return 1;
}
