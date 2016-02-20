//Cracked by Roath
// /d/shenlong/sg_process.h
// this file only takes care all shenlong business
// by ALN 2/98

void sg_process()
{
        object pang_ob;
        mixed spys;
        mapping sg_ob;
        int t, bonus;

   // list all spys on line
        spys = filter_array(users(), "is_spy", this_object());

        remove_call_out("sg_process");
        if( !sizeof(spys) )  {
                call_out("sg_process", 10000);
                return;
        } else  call_out("sg_process", 1000);

   // do zhong job to persuade highhands to leave shenlong
        if( !random(10) )
                message_zhong(spys);

   // do hong job to chase those highhands who refused to leave shenlong
        if( !random(100) )
                message_hong(spys);
}

void message_zhong(object *spys)
{
        mixed leaver;
        object ob, zhong_ob, *obj;
        int i;

        if( sizeof(leaver = filter_array(spys, "is_leaving", this_object())) < 1)
                return;

        obj = filter_array(children(SGNPCS + "zhong.c"), (: clonep :));
        if( sizeof(obj) ) {
                zhong_ob = obj[0];
                if( !living(zhong_ob) || zhong_ob->query("sgwork/persuaded")
                ||  zhong_ob->is_busy() || zhong_ob->is_fighting() )
                       return;
        }  else zhong_ob = new(SGNPCS + "zhong.c");

        ob = leaver[random(sizeof(leaver))];

        message("vision",
                zhong_ob->name() + "急急忙忙地离开了。\n",
                environment(zhong_ob), ({zhong_ob}));
        zhong_ob->move(environment(ob));
        message_vision("\n$N走了过来。\n", zhong_ob);
        zhong_ob->set_leader(ob);
        zhong_ob->set("sgwork/persuaded", 1);

        call_out("persuade_leave", 1, zhong_ob, ob);
}

void persuade_leave(object zhong_ob, object ob)
{
        if( !zhong_ob ) return;

        if( !living(zhong_ob) ) {
                call_out("persuade_leave", 5, zhong_ob, ob);
                return;
        }

        if( !ob || environment(zhong_ob) != environment(ob)
        || !ob->query("sg/spy") ) {
                call_out("destroy_ob", 1, zhong_ob);
                return;
        }

        if( !living(ob) ) {
                call_out("persuade_leave", 10 + random(10), zhong_ob, ob);
                return;
        }

        if( !zhong_ob->query_temp("yield") )
                zhong_ob->set_temp("yield", 1);

        message_vision("\n$N对$n苦苦规劝道：既然教主不再信任你，你还是尽快离开神龙教吧。\n", zhong_ob, ob);
        if( !ob->query_temp("zhong/nod") )
                ob->set_temp("zhong/nod", 1);
        tell_object(ob, "你只要打一个指令：leave shenlong，就算离开神龙了。\n");
        ob->add_temp("sg/zhong_persuade", 1);

        if( ob->query_temp("sg/zhong_persuade") > 3 ) {
                ob->add("sg/zhong_persuade", 1);
                ob->set("sg/zhong_time", time());
                call_out("destroy_ob", 10 + random(10), zhong_ob);
        } else  call_out("persuade_leave", 10 + random(10), zhong_ob, ob);
}

void message_hong(object *spys)
{
        mixed discarder;
        object *obj, ob, hong_ob, dest;
        string file;
        int i;

        if( sizeof(discarder = filter_array(spys, "is_discarding", this_object())) < 1 )
                return;

        obj = filter_array(children(SGNPCS + "hong.c"), (: clonep :));
        if( !sizeof(obj) ) return;

        hong_ob = obj[0];
        if( !living(hong_ob) || hong_ob->query("sgwork/chased")
        ||   hong_ob->is_busy() || hong_ob->is_fighting() )
                return;

        ob = discarder[random(sizeof(discarder))];

        if( !(dest = environment(ob)) ) return;

        file = base_name(dest);
        if( dest->query("no_fight")
        ||  strsrch(file, "/u/") == 0
        ||  strsrch(file, "/d/death/") == 0
        ||  strsrch(file, "/d/wizard/") == 0
        ||  strsrch(file, "/d/gaibang/") == 0
        ||  strsrch(file, "/d/taohua/") == 0
        ||  strsrch(file, "/d/shaolin/") == 0
        ||  strsrch(file, "/d/xiakedao/") == 0 )  return;

        message("vision",
                hong_ob->name() + "急急忙忙地离开了。\n",
                environment(hong_ob), ({hong_ob}));
        hong_ob->move(dest);
        message_vision("\n$N走了过来。\n", hong_ob);
        hong_ob->set_leader(ob);
        "/cmds/std/look"->main(hong_ob, ob->query("id"));
        hong_ob->set("sgwork/chased", 1);

        call_out("do_killing", 3 + random(10), hong_ob, ob);
}

void do_killing(object hong_ob, object ob)
{
        object dest;
        string file;

        if( !hong_ob ) return;

        if( !living(hong_ob) ) {
                call_out("do_killing", 5, hong_ob, ob);
                return;
        }

        if( !ob || !ob->query("sg/spy")
        ||  !(dest = environment(ob)) ) {
                call_out("destroy_ob", 1, hong_ob);
                return;
        }

        file = base_name(dest);
        if( dest != environment(hong_ob) || dest->query("no_fight")
        ||  strsrch(file, "/u/") == 0
        ||  strsrch(file, "/d/death/") == 0
        ||  strsrch(file, "/d/wizard/") == 0
        ||  strsrch(file, "/d/gaibang/") == 0
        ||  strsrch(file, "/d/taohua/") == 0
        ||  strsrch(file, "/d/shaolin/") == 0
        ||  strsrch(file, "/d/xiakedao/") == 0 ) {
                call_out("destroy_ob", 1, hong_ob);
                return;
        }

        message_vision(RED"\n$N对$n大声喝道：" + RANK_D->query_rude(ob) + "！在讨姓饷炊嗄昃尤缓廖藿ㄊ鳎曳狭四惆桑。。n\n"NOR, hong_ob, ob);
        hong_ob->kill_ob(ob);
        call_out("check_killing", 1, hong_ob, ob);
}

void check_killing(object hong_ob, object ob)
{
        object dest;
        string file;

        if( !hong_ob ) return;

        if( !living(hong_ob) ) {
                call_out("check_killing", 5, hong_ob, ob);
                return;
        }

        if( !ob || !ob->query("sg/spy")
        ||  !(dest = environment(ob)) ) {
                call_out("destroy_ob", 1, hong_ob);
                return;
        }

        file = base_name(dest);
        if( dest != environment(hong_ob) || dest->query("no_fight")
        ||  strsrch(file, "/u/") == 0
        ||  strsrch(file, "/d/death/") == 0
        ||  strsrch(file, "/d/wizard/") == 0
        ||  strsrch(file, "/d/gaibang/") == 0
        ||  strsrch(file, "/d/taohua/") == 0
        ||  strsrch(file, "/d/shaolin/") == 0
        ||  strsrch(file, "/d/xiakedao/") == 0 ) {
                call_out("destroy_ob", 1, hong_ob);
                return;
        }

        call_out("check_killing", 1, hong_ob, ob);
}

private int is_spy(object ob)
{
        if( !ob->query("sg/spy") ) return 0;

        return 1;
}

private int is_open(object ob)
{
        if( !ob->query_temp("pang_message") ) return 0;

        return 1;
}

private int is_leaving(object ob)
{
        if( (int)ob->query("combat_exp") > 500000
        &&  (int)ob->query("sg/exp") * 100 < (int)ob->query("combat_exp")
        &&  time() > (int)ob->query("sg/zhong_time") + 259200
        &&  (int)ob->query("sg/zhong_persuade") < 4 )
                return 1;

        return 0;
}

private int is_discarding(object ob)
{
        if( (int)ob->query("sg/zhong_persuade") >= 3 
        &&  (int)ob->query("sg/spy") )  return 1;

        return 0;
}
