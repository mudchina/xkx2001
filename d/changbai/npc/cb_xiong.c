//Cracked by Roath
// xiong.c

#include <ansi.h>
inherit NPC;

void check_fight(object, object);
int random_walk();

string *walkrooms = ({
        "/d/changbai/jiaxz",
        "/d/changbai/erld",
        "/d/changbai/banlp",
        "/d/changbai/pubu",
        "/d/changbai/tieby",
        "/d/changbai/jiglz",
});

void create()
{
        set_name("黑熊", ({ "hei xiong", "xiong" }) );
        set("race", "野兽");
        set("age", 25);
        set("long", "一只身体硕大的狗熊，它正瞪着眼睛看着你。\n");
        set("attitude", "aggressive");
        set_weight(200000);
        set("max_qi", 2000);
        set("max_jing", 500);
        set("max_jingli", 500);

        set("str", 90);
        set("con", 80);
        set("dex", 30);
        set("int", 10);

        set("combat_exp", 80000);

        set_temp("apply/attack", 50);
        set_temp("apply/damage", 60);
        set_temp("apply/armor", 80);

        set("chat_chance", 5);
        set("chat_msg", ({
              (: random_walk :),
        }) );

        setup();
}

void die()
{
        object ob;

        ob = new(DRUG_D("xiongdan"));
        ob->move(environment());

        message_vision("$N惨嚎一声，死了！\n", this_object());
        destruct(this_object());
}

init()
{
        object me;

        ::init();

        if( interactive(me = this_player()) 
        &&  !is_fighting() && living(this_object()) ) {
                remove_call_out("do_killing");
                call_out("do_killing", 1, me);
        }
}

void do_killing(object me)
{
        if( !me || environment(me) != environment() )
                return;

        kill_ob(me);
}

int random_walk()
{
        mapping exits;
        string *dirs, dir;

        if( member_array(base_name(environment()), walkrooms) == -1 ) {
                message_vision("$N一溜烟跑掉了。\n", this_object());
                destruct(this_object());
        }

        if( !objectp(environment()) 
        || !mapp(exits = environment()->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 ) 
                return 0;

        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        if( member_array(exits[dir], walkrooms) == -1 ) return 0;

        command("go " + dir);
        return 1;
}

