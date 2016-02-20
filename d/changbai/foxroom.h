//Cracked by Roath
// /d/changbai/foxroom.h

#include <ansi.h>
#include <combat.h>

int is_food(object);
int is_enemy(object);

void init()
{
        if( (int)this_player()->query("combat_exp") > 100000
        ||  present("fox", this_object()) )
                return;

        if( interactive(this_player()) ) {
                remove_call_out("fox_showup");
                call_out("fox_showup", 5 + random(5));
        }
}

void fox_showup()
{
        object *inv, food, fox;
        mixed foods;

        inv = all_inventory(this_object());
        if( filter_array(inv, "is_enemy", this_object())
        ||  !(foods = filter_array(inv, "is_food", this_object())) )
                return;

        fox = new("/d/changbai/npc/cb_fox");
        fox->move(this_object());

        message_vision(HIR"\n$N犹如风驰电掣般地奔了过来。\n"NOR, fox);
        food = foods[random(sizeof(foods))];
        message_vision("$N迅速地抓起" + food->name() + "，转身便想离开。\n", fox);
        destruct(food);

        call_out("fox_disappear", 1 + random(3), fox);
}

void fox_disappear(object fox)
{
        object *enemy;
        int i, ap, dp = 0;

        if( !fox ) return;

        if( !living(fox) ) {
                call_out("fox_disappear", 10 + random(5), fox);
                return;
        }

        if( fox->is_fighting() ) {
                ap = COMBAT_D->skill_power(fox, "dodge", SKILL_USAGE_DEFENSE);

                enemy = fox->query_enemy();
                for( i = 0; i < sizeof(enemy); i++)
                        dp += COMBAT_D->skill_power(enemy[i], "dodge", SKILL_USAGE_DEFENSE);

                if( ap < 1 ) ap = 1;
                if( dp < 1 ) dp = 1;
                if( random(ap + dp) < dp ) {
                        call_out("fox_disappear", 3 + random(3), fox);
                        if( sizeof(enemy)==1 && userp(enemy[0]) && ap > dp ) {
                                enemy[0]->improve_skill("dodge", enemy[0]->query("int"));
                                enemy[0]->add("combat_exp", random(20 * ap/(ap + dp)));
                        }
	        }
        }

        message_vision("\n$N一转眼便消失了。\n", fox);
        destruct(fox);
}
			
int is_enemy(object ob)
{
        if( userp(ob) && living(ob) && ob->query("combat_exp") > 100000 )
                return 1;

        return 0;
}

int is_food(object ob)
{
        if( ob->query("food_remaining") > 1 ) return 1;

        return 0;
}
         


