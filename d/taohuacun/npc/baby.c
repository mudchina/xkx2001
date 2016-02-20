// baby.c

inherit NPC;

void try_move();

void create()
{
        set_name("宝宝", ({"xiao baobao","baby"}) );
        set("gender", "女性");
        set("age", 1);
        set("attitude", "friendly");
        set("long","乖宝宝。\n");
        set("combat_exp", 1);
        set("str",3);
        set("parents",({"dad","mom"}));
   
        set("chat_chance", 2);
        set("chat_msg", ({
           (: random_move :)
        }));

        set("is_baby",1);
        // to allow the identification of baby. by mon.

        setup();
}

void init()
{
       add_action("do_kill",({"kill","fight","hit","steal"}));
       add_action("do_get","get");
       add_action("do_drop","drop");
       /* follow is very costly to execute. 5/6/98 mon.
       if(member_array(this_player()->query("id"),
             this_object()->query("parents"))>-1)
       {
             this_object()->set_leader(this_player());
       }
   */
   
       remove_call_out("try_move");
       call_out("try_move",1);
}

void try_move()
{
      if(random(20)==0)
      {
             remove_call_out("random_move");
             call_out("random_move",5);
      }
}

int do_drop(string arg)
{
      object me=this_object(),who=this_player(),env;
      if(!arg) return 0;
      env = environment(who);
      if(present(arg,who)!=me) return 0;
      if(me->move(env))
      {
             message_vision("$N把$n从怀里放了下来。\n",who,me);
             return 1;
      }
      return 0;
}

int do_get(string arg)
{
      object me=this_object(),who=this_player(),env;

      if(!arg) return 0;
      env = environment(who);
      if(present(arg,env)!=me) return 0;
      if(member_array(who->query("id"),
             me->query("parents"))>-1)
      {
             if(me->move(who))
             {
                   message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n",who,me);
             }
             else
             {
                   message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n",who,me);
             }
      }
      else
      {
             message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．\n",who,me);
      }
      return 1;
}

int do_kill(string arg)
{       
      object me,who;
      string name,verb,what,obj;
      if (!arg) return 0;
      verb=query_verb();
      me=this_player();
   
      if(verb=="steal")
      {
             if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
             return 0;
      }
      else obj=arg;

      if(!objectp(who=present(obj,environment(me))) 
            || !living(who)) return 0;
//    if(who->query("is_baby")) {
      if(who==this_object())
      {
             switch(verb)
             {
                    case "kill":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"拼命地哭了起来：爹～～，娘～～，"+
                             me->query("name")+"要杀我．．．快回来呀！\n");
                         break;
                    case "hit":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"大哭了起来：爹～～，娘～～，"+
                             me->query("name")+"欺负我．．．快回来呀！\n");
                         break;
                    case "fight":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"哭了起来：爹～～，娘～～，"+
                             me->query("name")+"要抢我的糖吃．．．快回来呀！\n");
                         break;
                    case "steal":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"哭了起来：爹～～，娘～～，"+
                             me->query("name")+"要偷吃我的糖！\n");
                         break;
                    case "beg":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"小嘴一歪哭了起来：爹～～，娘～～，"+
                             me->query("name")+"要骗我的糖吃！\n");
                         break;
             }
      }
      command(verb);
      return 0;
}

void relay_emote(object ob, string verb)
{
      if( !userp(ob) ) return;

      switch(verb)
      {
            case "kick":
                 command("say 爹～～，娘～～，"  + ob->query("name") + "踢我耶！");
                 command("kick " + ob->query("id"));
                 break;
            case "slap":
                 command("say 爹～～，娘～～，"  + ob->query("name") +
                 "打我耶，好痛啊～～～～");
                 command("slap " + ob->query("id"));
                 break;
            case "hit":
                 command("pain " + ob->query("id"));
                 break;
            case "bite":
                 command("face " + ob->query("id"));
                 break;  
            case "papaya":
                 command("angry");
                 break;  
      }
}

void relay_whisper(object me, string msg)
{
      if (member_array(me->query("id"),query("parents"))==-1)
      {
            message_vision((string)this_object()->query("name")
                        + "疑惑地看着$N。\n", me);
            return;
      }

      //note, do not allow the order contain "chat", "tell"...
      //may need disable more later...
      if( strsrch(msg, "chat") != -1 ||
          strsrch(msg, "tell") != -1 ||
          strsrch(msg, "follow") != -1 ||
          strsrch(msg, "apprentice") != -1 ||
          strsrch(msg, "recruit") != -1 )
            return;

      if (msg)
      {
            remove_call_out ("relaying");
            call_out ("relaying", 1+random(3), msg);
      }
}

void relaying (string msg)
{
//execute the order.
      command (msg);
}

