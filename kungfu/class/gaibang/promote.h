//Cracked by Roath
// promote.h for fight and get promotion of 丐帮
// created by ???

// Modified by xxx@xkx 01.01 for allowing some npc accept special objects other than 青竹令

/**************************************************************
 All NPCs who need to accept special objects need:

1. define:
#define ACCEPT_SPECIAL_OBJECT
2. declare:
int accept_special_object(object ob, object obj);
3. the npc set:
set("accept_special_object", 1);

If you need an example for this, please read peng.c  彭长老的文件
***************************************************************/

// Use a macro guard to avoid duplicate accept_special_object() function definition 
// by placing the function's inside a compiler directive.

#ifndef ACCEPT_SPECIAL_OBJECT
#define ACCEPT_SPECIAL_OBJECT

int accept_special_object(object ob, object obj) {return 0;}

#endif

// End of macro guard

int accept_object(object ob, object obj)
{
        object me = this_object();

        // For special NPCs accept special objects
        
        if( obj->query("id") != "qingzhu ling" && query("accept_special_object") )
          return accept_special_object(ob, obj);
        
        // For 青竹令
        
        if( ob->query("family/family_name") != me->query("family/family_name") ) {
                command("say 你我不属同一门派，你给我青竹令又有何用？！");
                return 0;
        }

        if( ob->query("rank") != me->query("rank") ) {
                command("say 你我帮中辈份不同，我没有资格考验你的武功，你还是找同辈的大师兄去吧！");
                return 0;
        }

        if( obj->query("id") == "qingzhu ling" ) 
        {
                if( obj->query_temp("owner") != ob->query("name") ) {
                        command("say 你不是这快青竹令的主人！");
                        return 0;
                } else if( obj->query_temp("win_times") < 1 ) {
                        command("say 你尚未战胜一个同门师兄弟，不符合挑战我的条件。");
                        return 0;
                } else if( obj->query_temp("win_last") ) {
                        command("say 你已经战胜一位师兄弟和同辈大师兄，可以直接找简长老要求晋升了！");
                        return 0;
                } else {
                        ob->set_temp("fight_ok",1);
                        command("say 好，我们这就来验证一下武功，看你是否能够成为一名合格的丐帮" +
                        chinese_number(ob->query("rank")) + "袋弟子。");
                        return 1;
                }
        }

        command("shake");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}

int accept_fight(object ob)
{
        object me  = this_object();
        
        if ( !ob->query_temp("fight_ok") ) return 0;

        me->set_temp("challenger", ob);
        ob->delete_temp("fight_ok");
        
        return 1;
}

int chat()
{
        object me = this_object();
        object ob = me->query_temp("challenger");
        object obj;
        int my_max_qi, his_max_qi;

        if( !objectp(ob) ) return ::chat();;
        if (me->is_fighting(ob)) return ::chat();

        me->delete_temp("challenger");

        if (me->is_fighting()) return ::chat();

        if ( !present(ob, environment()) ) return ::chat(); 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                command("say 师弟武功卓绝，令为兄汗颜之至，惭愧，惭愧！\n");
                message_vision("\n$N取过青竹令，在背面签上自己的名字后递给$n。\n\n", 
                                me, ob);

                obj = present("qingzhu ling", me);
                obj->set_temp("win_last", 1);
                obj->move(ob);

                command("say 你已经战胜我和另一位师兄弟，可以直接找简长老要求晋升了！");
                return ::chat();
        } 
        else if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                command("say 看来师弟还得多加练习，方能在丐帮众弟子中出人头地！\n");
                return ::chat();
        }

        return ::chat();  
}
