//Cracked by Roath
// surrender.c
// arthurgu 1999/10

#include <ansi.h>

inherit F_CLEAN_UP;

void waittime1( object me ) ;
void waittime2( object me ) ;

int main(object me, string arg)
{     
	object ob,obj;
	object op;
	if ( !objectp(op = find_object("/d/city/npc/aqingsao")) )
                        op = load_object("/d/city/npc/aqingsao");

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("你向谁投降？\n");

        if( !obj->is_character() )
                return notify_fail("看清楚一点，那并不是生物。\n");

        if( !userp(obj) )
                return notify_fail("你只能向玩家投降。\n");

	if( me->is_busy())
		return notify_fail("你还在忙！！\n");
		
	if( me->query_temp("surrender_not")==1)
		return notify_fail("他现在不接受你投降，等一回再试试！！\n");	
	
	if( !me->is_fighting() )
		return notify_fail("投降？现在没有人在打你啊....？\n");
	
	ob = me->query_temp("last_opponent");
	if( random(3)==0)
	     {
		message_vision( HIC "\n $N向$n求饶，但是$n大声说道："
			+ RANK_D->query_rude(me) + "废话少说，纳命来！\n" NOR, me, ob);
		me->set_temp("surrender_not",1);
		 call_out("waittime1", 60 , me );	
			
		return 1; }
		
	else if( random(3)!=0)
	     {
	       me->set("shen", 99*(int)me->query("shen")/100 );
	       if( (int)me->query("combat_exp") <= 5000 )
                me->add("combat_exp", 0 );
        else
                me->add("combat_exp", -(int)me->query("combat_exp")/5000 );
                
                me->set_temp("surrender",1);
	        me->set_temp("surrender/ownder", ob->query("id"));                 
       	
	        me->remove_all_enemy();
	        ob->remove_killer(me);
	        me->remove_killer(ob);
	        message_vision( HIW "\n$N向$n连声求饶道：「不打了，不打了，我投降....」\n" NOR, me,ob );
	        message_vision( HIC "$n不屑地撇了撇嘴，向$N说道：「看你这熊样，我今天就放你一马，以后可得小心！！」\n\n" NOR, me,ob );
	        CHANNEL_D->do_channel(op,"rumor",""+me->query("name") +"贪生怕死，向"+ob->query("name") +"投降了！\n");
	        call_out("waittime2", 1000 , me );	
	  
	        
	      }
		return 1;
}


void waittime1( object me )
{
  me->delete_temp("surrender_not");
  
}

void waittime2( object me)
{ 
  me->delete_temp("surrender/ownder");
  message_vision("你恢复了一些因投降而降低的信心。\n", me);
  
}


int help(object me)
{
  write(@HELP
指令格式 : surrender <id>
 
这个指令可以让你有机会向敌人投降而终止战斗，但投降后你将有一定的损失。
 
HELP
    );
    return 1;
}
 
