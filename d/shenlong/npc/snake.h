//Cracked by Roath
// animal snake.h
// ALN Sep / 97

#include <ansi.h>

void init()
{
        object ob = this_player();

        ::init();

// here is the quest to catch snakes
// of course it is also a nice trick for smart players to catch snakes
        if( interactive(ob) && objectp(present("xionghuang", ob)) && !query_temp("xionghuang") ) {
                message_vision("$N激烈地扭动了几下\n", this_object());
                add_temp("apply/attack", -10);
                add_temp("apply/damage", -10);
                set_temp("xionghuang", 1);

                call_out("recover", 10 + random(10));
        }

        if( interactive(ob) && ob->query("combat_exp") < 100000 
        &&  !query_temp("xionghuang")
        &&  !is_busy() && !is_fighting() && living(this_object()) ) {
                message_vision(HIR "" + query("name") + "将身子一卷随即便向$N袭击！！！\n" NOR, ob);
                add_temp("apply/attack", 20);
                add_temp("apply/damage", 20);
                for(int i = 0; i < snake_attspeed(ob); i++ )
                        COMBAT_D->do_attack(this_object(), ob);
                add_temp("apply/attack", -20);
                add_temp("apply/damage", -20);

                kill_ob(ob);
                ob->fight_ob(this_object()); 
        }
}

void recover()
{
        delete_temp("xionghuang");
        add_temp("apply/attack", 10);
        add_temp("apply/damage", 10);
}

void die()
{
        object ob;
//        message_vision("$N啪的一声断成两截！$N死了。\n", this_object());
        ob = new(DRUG_D("shedan"));
        ob->move(environment(this_object()));
        destruct(this_object());
}

int snake_attspeed(object ob)
{
        int cp;

        cp = 10 * query("combat_exp") / (ob->query("combat_exp") + 10);

        if( cp > 1000 ) return 5;
        if( cp > 300 ) return 4;
        if( cp > 100 ) return 3;
        if( cp > 30 ) return 2;
        if( cp > 5 ) return 1;
        return 0;
}







