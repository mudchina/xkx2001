// taohuatong.c
inherit NPC;

int get_short(string rep, string arg, string *householder);
int get_long(string arg, string *householder,string short,string rep);
int save_file(string short, string llong, string *householder);

void create()
{
        set_name("桃花童", ({"taohua tong","kid"}));
        set("gender", "男性");
        set("age", 9);
        set("long",
"一个天真顽皮的小童，他管着鸳鸯溪的别塾。也许调皮，也许年幼，总是
不时有恶作剧。\n");
        set("attitude", "friendly");
        set("combat_exp", 2500);
        set("per", 25);
        set_skill("dodge", 60);
        set("max_jing",100);
        set("max_qi",100);
        set("neili",10);
        set("max_neili",10);
        setup();

        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 100);

}
void init()
{
       ::init();
       add_action("do_apply", "shenqing");
}

int do_apply(string arg)
{
       object me,spouse,officer,room;
       string str, partner, *householder,laotou;
       int i,j;
       me = this_player();
       officer = present("taohua tong", environment(me));
       laotou = officer->query("name");
       if(!arg)
           return notify_fail("你要申请什么？\n");
       if(arg != "house" )
           return notify_fail("你要申请什么？\n");
       if(!(me->query("spouse/id")))
       {
             message_vision(laotou+"故作老成地叹了叹道：" +
             RANK_D->query_respect(me)
+"既是独身一人，自然逍遥自在。何苦自求束缚？\n", officer);
             return 3;
        }

        if(file_size("/data/playerhomes/h_"+me->query("id")+".o") != -1)
        {
                message_vision(laotou+"调皮地刮了刮"+me->query("name")+"的脸，嘻笑道：" +
RANK_D->query_respect(me) +"不是已经有了房子吗？还想再骗一个？\n",officer,me);
                return 1;
        }
        if((me->query("gender")) == "男性")
        {       str = "妻子";
        }
        else
        {    str = "丈夫";
        }
        partner = me->query("spouse/id");
        if(file_size("/data/playerhomes/h_"+partner+".o") != -1)
        {
                message_vision(laotou+"调皮地刮了刮"+me->query("name")+"的脸，嘻笑道：" +
RANK_D->query_respect(me) +"，你们家不是已经有了房子吗？还想再骗一个？\n",officer,me);
                return 1;
        }
        if(!(spouse = present(partner, environment(me))))
        {
                message_vision(laotou+"对着"+me->query("name")+"摇了摇头道：领房这么大的事，"+
RANK_D->query_respect(me)+"还是和你"+str+"一起来的好！\n", officer, me);
                return notify_fail("你得让你"+str+"一起来！\n");
        }
        if(!me->query_temp("rental_paid") && !spouse->query_temp("rental_paid"))
                return notify_fail(laotou+"嘻嘻笑道：世上只怕没有便宜的房子哦。\n");
        message_vision(laotou+"笑眯眯地对$N道：娶妻、领房、生子，人生三大事耶！\n", me);
        me->set_temp("is_applying_house",1);
//   officer->set_temp("house_applied",1);

        room=new("/d/taohuacun/obj/home");
        room->set("file_name","h_"+me->query("id"));
        room->set("home_host",({me->query("id")})+({partner}));
        room->save();

        message_vision("$N说道：房子已经建好了，您这就去装修吧！\n",officer);

/*
       message_vision("$N笑眯眯地对$n道：取妻、领房、生子，人生三大事耶！\n",officer,me);
       message_vision("$N说道：我去检查检查房子，去去就来。" +
RANK_D->query_respect(me)+
"在这儿稍待片刻，可别走啊！\n",officer);
        officer->move(filename);
*/
        return 1;
}

int accept_object(object who, object ob)
{
        if(!ob->query("money_id"))
              return 0;
        if (ob->value()< 1000000)
        {
              if(who->query_temp("is_applying_house"))
                    command("say "+RANK_D->query_respect(who)+"出手这么大方。府上保准富丽堂皇。\n");
              else
                    command("say "+RANK_D->query_respect(who)+"这么客气，我这就给您办。\n");
        }
        else
        {
              if(who->query_temp("is_applying_house"))
                    command("say "+RANK_D->query_respect(who)+"出手这么大方。府上保准富丽堂皇。\n");
              else
              {
                    command("say "+RANK_D->query_respect(who)+"若是想申请房子，尽管说。\n");
                    who->set_temp("rental_paid", 1);
              }
        }
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), ob);
        return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

