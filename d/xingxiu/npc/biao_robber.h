//Cracked by Roath
void init()
{
        object victim = this_player();
        object me = this_object();

        if ( !me->query_temp("said") ) {
             command( "rob" );
             switch( random(2) )
             {
                case 0:
                        command( "say 留下红镖，老子便饶你狗命！" );
                        break;
                case 1:
                        command( "say 相好的，留下红镖滚吧！" );
                        break;
                case 2:
                        command( "say 大爷今天要请客，留想向你借些钱财花用，留下红镖滚吧！" );
			break;
	     }
             me->set_temp("said", 1);
        }
	
	if ( !me->query_temp("victim") ) {
                remove_call_out("rob_kill");
                call_out("rob_kill", 20, me, victim);
                me->set_temp("victim", 1);
        }
}

int accept_object(object who, object ob)
{
        object me = this_object();

        if ( me->is_fighting() ) {
                command( "grin" );
                command( "say 现在才给已太迟了，纳命来吧！" );
                return 0;
        }

	if ( ob->name()=="红镖" ) {
                remove_call_out("rob_kill");
		message_vision( "$n飞起一脚踢在$N的屁股上，不屑地哼了一声。\n", who, me);
		command( "say 算你识时务，老子今天放你一马，快滚吧！" );
                message_vision( "$N说完便扬长而去。\n", me );
		if (environment(me)->query("short") == "山路") who->delete_temp("biao/ma");
		who->delete_temp("apply/short");
                who->set_temp("biao/fail", 1);
                remove_call_out("destroy_me");
                call_out("destroy_me", 1, me);
                return 1;
        }
        else {
                command( "say 大爷要的是红镖，你这龟儿子可是耍老子来着？" );
                return 0;
        }
}

void rob_kill(object me, object victim)
{
        message_vision( "$n对着$N大吼：你竟敢不交！老子宰了你！\n", victim, me );
        me->kill_ob(victim);
        remove_call_out("checking");
        call_out("checking", 1, me, victim);
}

void destroy_me(object me)
{
        destruct(me);
}

int checking(object me, object victim)
{
        if ( me->query("qi") < 100 ) return 1;

        if ( !me->is_fighting() ) destruct(me);

        if ( present(victim, environment()) ) call_out("checking", 1, me, victim);

	return 1;
}
