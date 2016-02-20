//Cracked by Roath
int do_find(string item)
{       object holder;
        object holdee;
        object *list;
        object it;
        object helper = this_object();
        object temp = this_player();
        int iNum;
        if (!item)
        {       return 0;       }
        if (!temp->query_temp("xkd/give"))
        {       return 0;       }
        if ((int)temp->query("combat_exp") < 10000)
        {       command("say 小孩子找那麽贵重的东西干嘛，你大一点再来吧。");
                call_out("do_return", 0, ling, temp);
                return 1;
        }
        if ((int)temp->query("xkd/find") == 1 ) 
        {       command("say 我已经帮过你了，不能再帮你了。");
	          this_object()->delete_temp("xkd/busy");
  		    destruct(ling);
                return 1;
        }
        home = environment(helper);
        helpee = temp;
        iNum = item_num(item);
        if (iNum == -1)
        {       command("say 你要找的东西，好像不存在。");
                call_out("do_return", 0, ling, helpee);
                helpee->delete_temp("xkd/give");
                return 1;
        }
        list = children(items[iNum]);
        if (sizeof(list) == 0)
        {       command("say 你要找东西，好像没有。");
                call_out("do_return", 0, ling, helpee);
                helpee->delete_temp("xkd/give");
                return 1;
        }
        it = list[0];
        if (!holder = environment(it)) 
        {       command("say 你要找东西，好像没有。");
                call_out("do_return", 0, ling, helpee);
                helpee->delete_temp("xkd/give");
                return 1;
        }
        if ( holder->is_container())
        {       holdee = environment(holder);
        }
        else
        {       holdee = holder;
        }
        if (!userp(holdee) && !holdee->is_trainee())
        {       command("say " + item + "物归原主，我怎能帮你去把它搞来。");
                call_out("do_return", 0, ling, helpee);
                helpee->delete_temp("xkd/give");
                return 1;
        }
        if (helpee == holdee)
        {       command("say 在你身上了还要我去找什麽找。");
                call_out("do_return", 0, ling, helpee);
                helpee->delete_temp("xkd/give");
                return 1;
        }
        set_temp("xkd/busy", 1);
        command("whisper " + helpee->query("id") + " " + item + "在" + holdee->query("name")+"("+holder->query("id") + ")那。");
        //command("say home is " + home->query("short") + " helpee is " + helpee->query("id"));
        command("say 你在这稍等，我去去就来。");
	  message_vision("$N走了出去。\n", helper);

        helper->move(environment(holdee));
	  message_vision("$N走了过来。\n", helper);
        if (holder->query("id") == holdee->query("id"))
        {       command("steal " + it->query("id") + " from " + holdee->query("id"));
                remove_call_out("do_steal");
                call_out("do_steal", 10, it, holdee, 0);
        }
        else
        {       if (holder->query("no_steal") || holder->query("no_get")) 
                {       remove_call_out("do_finished");
                        call_out("do_finished", 10, it);
                }
                else
                {       command("steal " + holder->query("id") + " from " + holdee->query("id"));
                        remove_call_out("do_steal");
                        call_out("do_steal", 10, holder, holdee, 0);
                }
        }
        return 1;
}
int do_steal(object item, object whom, int count)
{       object me = this_object();
        if (me->is_busy())
        {       remove_call_out("do_steal");
                call_out("do_steal", 10, item, whom, count);
                return 1;
        }
	  if (me->is_fighting())
	  {	    remove_call_out("do_steal");
		    command("halt");
                call_out("do_steal", 10, item, whom, count);
                return 1;
	  }
        if (count > 5)
        {       //command("say count over");
                remove_call_out("do_steal");
                call_out("do_finished", 1, item);
                return 1;
        }
        if (environment(item)->query("id") != whom->query("id"))
        {       //command("say change player");
                whom = environment(item);
        }
        if (whom->query("id") == me->query("id"))
        {       //command("say got it");
                remove_call_out("do_steal");
                call_out("do_finished", 1, item);
                return 1;
        }
        //command("say stealing it ");
        me->move(environment(whom));
        count = count + 1;
        command("steal " + item->query("id") + " from " + whom->query("id"));
        remove_call_out("do_steal");
        call_out("do_steal", 10, item, whom, count);
        return 1;
}
int do_finished(object item)
{       object me = this_object();
	  message_vision("$N走了出去。\n", me);
        me->move(environment(helpee));
	  message_vision("$N走了过来。\n", me);
        if (environment(item) == me)
        {       command("tell " + helpee->query("id") + " 总算找到了。");
                call_out("do_return", 0, item, helpee);
             command("give " + helpee->query("id") + " " + item->query("id"));
//              command("give " + helpee->query("id") + " " + item->query("id"));
                helpee->set("xkd/find", 1);
                destruct(ling);
        }
        else
        {       command("tell " + helpee->query("id") + " 对不起没法帮你弄到" + item->query("name") +"。");
                call_out("do_return", 0, ling, helpee);
        }
        helpee->delete_temp("xkd/give");
        delete_temp("xkd/busy");
        return 1;
}
int do_valify_find(object me)
{       
        if ((int)me->query("xkd/find") == 1) 
        {       return 0;       }
        else
        {       return 1;       }
}
int do_return(object ob, object whom)
{       
        if(whom->query("env/no_accept"))
        {       command("drop " + ob->query("id"));
        }
        else
        {       command("give " + ob->query("id") + " to " + whom->query("id"));
        }
        this_object()->delete_temp("xkd/busy");

        return 1;
}
