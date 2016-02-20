//Cracked by Roath
// /d/changbai/bj/lama.h
// by aln 2 / 98

void init()
{
        ::init();

        add_action("do_check", "fight");
        add_action("do_check", "kill");
        add_action("do_check", "hit");
        add_action("do_check", "halt");

        add_action("do_check", "throw");
        add_action("do_check", "trap");
        add_action("do_check", "train");
        add_action("do_check", "forcekill");
        add_action("do_check", "persuade");
        add_action("do_check", "zhanbu");

        add_action("do_check", "exert");
        add_action("do_check", "yun");
        add_action("do_check", "lian");
        add_action("do_check", "practice");
        add_action("do_check", "prepare");
        add_action("do_check", "yield");

        add_action("do_check", "wear");
        add_action("do_check", "remove");
        add_action("do_check", "wield");
        add_action("do_check", "unwield");

        add_action("do_check", "lead");
        add_action("do_check", "follow");

        add_action("do_put", "put");
        add_action("do_check", "get");
        add_action("do_check", "drop");
        add_action("do_check", "open");
        add_action("do_check", "close");

        add_action("do_check", "eat");
        add_action("do_check", "chi");
        add_action("do_drink", "drink");
        add_action("do_check", "fu");

        add_action("do_check", "go");
        add_action("do_check", "look");
        add_action("do_check", "check");
        add_action("do_check", "dating");

        add_action("do_check", "ask");
        add_action("do_check", "reply");
        add_action("do_check", "say");
        add_action("do_check", "tell");
        add_action("do_check", "team");
        add_action("do_check", "whisper");

        add_action("do_check", "quit");
        add_action("do_check", "wimpy");

        add_action("do_perform", "perform");
}

int do_check(string arg)
{
        if( !living(this_object()) ) return 0;

        return this_player()->query_temp("cursed");
}

int auto_disappear()
{
        object room, ob = this_object();
        string partner, ob_id = (string)this_object()->query("id");

        if( !living(ob) ) return 1;

        if( !is_fighting() ) {
                switch(ob_id) {
                case "dalama": command("lama"); break;
                case "erlama": command("lasa"); break;
                }
        }

        room = environment(ob);
        if( !mapp(environment(ob)->query("exits")) ) 
                { destroy(ob); return 1; }

        switch(ob_id) {
        case "dalama": partner = "erlama"; break;
        case "erlama": partner = "dalama"; break;
        }

        if( !present(partner, room) 
        &&  !ob->is_fighting() && !ob->is_busy() )
                { destroy(ob); return 1; }

        return 1;
}

int auto_check()
{
        object room, obj, corpse, victim, ob = this_object();
        string partner, partner_name;

        if( !living(ob) ) return 1;
        if( ob->is_busy() ) return 1;

        switch((string)ob->query("id")) {
        case "dalama": 
                partner = "erlama";
                partner_name = "密宗二老";
                break;
        case "erlama":
                partner = "dalama";
                partner_name = "密宗大老";
                break;
        }

        room = environment(ob);
        if( !(obj = present(partner, room)) ) {
                COMMAND_DIR"std/halt"->main(ob);
                destroy(ob);
                return 1;
        }

        if( !living(obj) ) {
                COMMAND_DIR"std/halt"->main(ob);
                GET_CMD->do_get(ob, obj);
                destroy(ob);
                return 1;
        }

        if( corpse = present("corpse", room) ) {
                if( corpse->query("victim_name") == partner_name ) { 
                        COMMAND_DIR"std/halt"->main(ob);
                        GET_CMD->do_get(ob, corpse);
                        destroy(ob);
                        return 1;
                }
        }

        call_other("/d/changbai/bj/lifeheal2", "exert", ob, obj);

   // let two lamas focus on one enemy
        victim = offensive_target(ob);
        if( !obj->is_fighting(victim) ) {
                COMMAND_DIR"std/halt"->main(obj);
                obj->kill_ob(victim);
        }

        return 1;
}

void destroy(object ob)
{
        if( !living(ob) ) return;

        message("vision",
                ob->name() + "急急忙忙地离开了。\n",
                environment(ob), ({ob}));
        destruct(ob);
}

int accept_kill(object me)
{
        object obj, ob = this_object();
        string partner;

        if( !living(ob) ) return 1;
        if( ob->is_busy() ) return 1;

        switch((string)ob->query("id")) {
        case "dalama": partner = "erlama"; break;
        case "erlama": partner = "dalama"; break;
        }


        if( !(obj = present(partner, environment(ob))) ) {
                COMMAND_DIR"std/halt"->main(ob);
                call_out("destroy", 1, ob);
                return notify_fail("");
        }

        if( !living(obj) ) {
                COMMAND_DIR"std/halt"->main(ob);
                GET_CMD->do_get(ob, obj);
                call_out("destroy", 1, ob);
                return notify_fail("");
        }

        if( !obj->is_busy() && !obj->is_fighting(me) ) {
                COMMAND_DIR"std/halt"->main(obj);
                obj->kill_ob(me);
                return 1;
        }

        command("sneer");
        call_other("/kungfu/skill/longxiang-banruo/shield", "exert", ob, ob);
        return 1;
}

int accept_fight(object me)
{
        if( !living(this_object()) ) return 1;

        command("say " + "滚！！！你没见大喇嘛我有要事缠身？！");
        command("consider " + me->query("id"));
        return 0;
}

int ask_lama(string arg)
{
        if( !living(this_object()) ) return 1;

        if( this_object()->is_fighting() )
                command("angry");
        else 
                command(arg + " " + this_player()->query("id"));
        return 1;
}

int do_perform(string arg)
{
        object ob;

        if( !living(this_object()) ) return 0;

        if( this_player()->query_temp("cursed") ) return 1;

        if( !arg ) return notify_fail("");

        if( arg == "chan" || arg == "chanrao" );
	else if( arg == "chan " + this_object()->query("id") 
             ||  arg == "chanrao " + this_object()->query("id") )  
                ob = this_object();
        else    return 0;

        call_other("/d/changbai/bj/chan2", "perform", this_player(), ob);
        return 1;
}
