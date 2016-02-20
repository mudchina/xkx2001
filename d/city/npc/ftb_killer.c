//Cracked by Roath
// npc: /d/city/npc/ftb_killer.c
// Chu 2/10/99

#include <ansi.h>
inherit NPC;
#include "/clone/obj/npc_setup.h"

string ask_cike();
string ask_move();

void create()
{
        set_random_name();
        set("gender", "男性" );
        set("age", 32);
        set("str", 23);
        set("dex", 30);
        set("con", 23);
        set("int", 23);
        set("shen_type", -1);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("no_refresh", 1);

        set("inquiry", ([
            "斧头帮" : "斧头帮? 你可知道他们帮主的所在吗？",
            "程金斧" : (: ask_move :),
            "刺客" : (: ask_cike :)
        ]));

        setup();
        carry_object("/clone/armor/beixin")->wear();
        remove_call_out("self_destruct");
        call_out("self_destruct", 1200);

}

void self_destruct() {
    object me = this_object();
    message("vision", name(1)+"急急忙忙地离开了。\n", environment(me), me);
    destruct(me);
}

void check_corpse() {
    int sacrifice;
    string player_name, room_name;
    object me, room, dead, player;

    player_name = query("player_name");
    me = this_object();
    player = find_player(player_name);
    dead = present("corpse", environment(me));

    if (objectp(dead) && objectp(player)) {
        room_name=file_name(environment(player));

        // I killed this corpse
        // this guy's name matches the one I am looking for
        // and the real player object is in hell (prevent duplicated name)

        if (dead->query("my_killer")==me->query("id") &&
            dead->query("victim_name")==player->name(1) &&
            strsrch(room_name, "/d/death/")==0) {

            // make sure this player is not mengzhu
            room = find_object("/d/taishan/fengchan");
            if (!objectp(room)) room = load_object("/d/taishan/fengchan");
            if (!objectp(room)) return; // taishan has bug?
            if (player_name == room->query("winner") )  return;
            // what about shangshan/fae?
 
            sacrifice = player->query("futou_bang/sacrifice");
            if (player->query("combat_exp") >= sacrifice*10000) {
                player->set("futou_bang/sacrifice", sacrifice+1);
            }
            return;     // no need to check again
        }
    }
    call_out("check_corpse", 10);
}

void set_status(mixed player_arg) {
    int exp, sacrifice, exp_rate, skill_rate;
    object player;
    string menpai;

    if (stringp(player_arg)) player = find_player(player_arg);
    else if (objectp(player_arg)) player = player_arg;
    else return;
    if (!objectp(player)) return;

    set("player_name", player->query("id"));
    exp = player->query("combat_exp");

    sacrifice = (int)player->query("futou_bang/sacrifice");
    if (sacrifice < 50) exp = exp * (200-sacrifice)/200;
    else exp = exp*3/4;

    if (exp < 1000) exp = 1000;
    else  if (exp < 50000) {
        exp = exp/2;
        set("dex", 15);
    }else if (exp < 100000) {
        exp = exp*2/3;
        set("dex", 20);
    }else if (exp < 500000) {
        exp = exp*2/3;
        set("dex", 25);
    }else if (exp < 800000) {
        set("dex", 25);
    }

    // exp 1M add 7%     2M add 14%     3M add 21%
    exp_rate = 80;
    skill_rate = 80;
    if (exp > 1000000) {
        exp_rate += 7*exp/1000000;
        skill_rate += 7*exp/1000000;
    }
    exp_rate += random(20);
    skill_rate += random(10);

    menpai = set_skills(0, exp*exp_rate/100, skill_rate);
    set("long", "他看起来是"+menpai+"派高手。\n");
    set_hp(query_skill("force", 1));
    if (exp > 100000) carry_object(query("default_weapon"))->wield();

    remove_call_out("check_corpse");
    call_out("check_corpse", 10);
}

void die()
{
    mixed killer;
    int kill_num;

    killer = query_temp("last_damage_from");
    if (stringp(killer)) killer = (object)find_player((string)killer);
    if (objectp(killer)) {
        if (killer->query("id") == query("player_name")) {
            kill_num = killer->query("ftb_search/kill_num");
            killer->set("ftb_search/kill_num", kill_num+1);
        }
    }
    ::die();
}

string ask_cike() 
{
    object player = this_player();
    if (query("player_name") == player->query("id")) {
        return "老子怎么越看越觉得你像是个杀手呢?";
    }else {
        return "青天白日的, 哪里有刺客? 笑话.";
    }
}

string ask_move()
{
    object player, room;
    mapping exits;
    string  *dirs;

    player = this_player();
    if (query("player_name") == player->query("id")) {
        room = environment(this_object());
        exits = room->query("exits");
        dirs = keys(exits);
        command("go "+dirs[random(sizeof(dirs))]);
        return "好家伙，真来了。";
    }else {
        return 0;
    }
}
#include "/clone/obj/npc_setup.c"
