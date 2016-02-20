//Cracked by Roath
//wzfeng@xkx 2000 3-2
#include <ansi.h>
#include <dbase.h>

inherit NPC;
//inherit F_VENDOR;
int ask_me();
int ask_songhua();
int do_song(string arg);
void create()
{
                  set_name("英莲", ({ "ying lian", "ying" ,"lian" }));
                  set("shen_type", 1);

                  set("gender", "女性");
                  set("age", 15);
                  set("long",
"她是这里的卖花女，只见其含笑如春桃，玉唇含香,纤纤细腰,婀娜多姿，
虽粗布花衣，但不掩其清秀，实乃人间绝色。\n"
);
                  set("attitude", "friendly");
                  set("inquiry", ([
                                "送花" : (: ask_songhua :),
                                "song" : (: ask_me :),
								"songhua" : (:ask_songhua :),
                  ]));
/*
				  set("vendor_goods", ({
					      __DIR__"obj/flower/red_rose",
						  __DIR__"obj/flower/white_rose",
						  __DIR__"obj/flower/qingren_cao",
						  __DIR__"obj/flower/ding_xiang",
						  __DIR__"obj/flower/mu_dan",
						  __DIR__"obj/flower/yu_jinxiang",
						  __DIR__"obj/flower/bai_he",
						  __DIR__"obj/flower/kang_naixin",
						  __DIR__"obj/flower/ma_tilian",
						  __DIR__"obj/flower/jin_yucao",
						  __DIR__"obj/flower/huo_he",
						  __DIR__"obj/flower/hu_dielan",
						  __DIR__"obj/flower/qiu_haitang",
						  __DIR__"obj/flower/shi_hulan",
			

				  }));
*/
				  set("vendor_goods", ([
					  __DIR__"obj/flower/red_rose":99,
					  __DIR__"obj/flower/white_rose":99,
					  __DIR__"obj/flower/qingren_cao":99,
					  __DIR__"obj/flower/ding_xiang":99,
					  __DIR__"obj/flower/mu_dan":99,
					  __DIR__"obj/flower/yu_jinxiang":99,
					  __DIR__"obj/flower/bai_he":99,
					  __DIR__"obj/flower/kang_naixin":99,
					  __DIR__"obj/flower/ma_tilian":99,
					  __DIR__"obj/flower/jin_yucao":99,
					  __DIR__"obj/flower/huo_he":99,
					  __DIR__"obj/flower/hu_dielan":99,
					  __DIR__"obj/flower/qiu_haitang":99,
					  __DIR__"obj/flower/shi_hulan":99,
			

				  ]));
	


                  setup();
	              carry_object("d/city/obj/pink_cloth")->wear();
		          carry_object("d/city/obj/flower_shoe")->wear();


                  remove_call_out("do_check_flower");
                  call_out("do_check_flower", 10+random(10) );

				  remove_call_out("do_full_flower");
                  call_out("do_full_flower", 1800 );
}


int do_full_flower()
{
   
	tell_room(environment(), "\n几个花匠走了进来。\n");
	 tell_room(environment(), "“嗨！英莲，给你送鲜花来了。”带头的那个花匠对英莲打招呼。\n");
	 tell_room(environment(), "“英莲喜声道：“谢谢花匠叔叔，放在后面的花室里吧。”\n");
 	 tell_room(environment(), "花匠们走过去将花放置好。\n");
	 tell_room(environment(), "花匠们走了出来对英莲说道：“花放好了，我们下次再来。”\n");
	 tell_room(environment(), "花匠们走了出去。\n");
	 set("vendor_goods", ([
					  __DIR__"obj/flower/red_rose":99,
					  __DIR__"obj/flower/white_rose":99,
					  __DIR__"obj/flower/qingren_cao":99,
					  __DIR__"obj/flower/ding_xiang":99,
					  __DIR__"obj/flower/mu_dan":99,
					  __DIR__"obj/flower/yu_jinxiang":99,
					  __DIR__"obj/flower/bai_he":99,
					  __DIR__"obj/flower/kang_naixin":99,
					  __DIR__"obj/flower/ma_tilian":99,
					  __DIR__"obj/flower/jin_yucao":99,
					  __DIR__"obj/flower/huo_he":99,
					  __DIR__"obj/flower/hu_dielan":99,
					  __DIR__"obj/flower/qiu_haitang":99,
					  __DIR__"obj/flower/shi_hulan":99,
			

				  ]));
	 remove_call_out("do_full_flower");
                  call_out("do_full_flower",1800);
	 return 1;
	
}

private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N神色慌张地离开了。\n", this_object());
        this_object()->move("/d/city/huadian");
	message_vision("$N快步走了过来。\n", this_object());
}
	



void init()
{
     if( environment() != load_object("/d/city/huadian") ) 
		{
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
         add_action("do_check", "list");
    	 //add_action("do_list", "list");
         add_action("do_buy", "buy");
         add_action("do_song", "song");
         add_action("do_check_flower", "check_test");

}
string inventory_desc(object ob)
{
	return sprintf("%s%s",
		ob->query("equipped")? HIC "□" NOR:"  ",
		ob->short()
	);
}
string price_string(int v)
{
        if( v%10000 == 0 )
                return chinese_number(v/10000) + "两黄金";
        if( v%100 == 0 )
                return chinese_number(v/100) + "两白银";
        return chinese_number(v) + "文铜板";
}

int do_buy(string what)
{
    int i, amount, value, val_factor;
	string ob_file;
	object ob, me = this_player();
	mapping goods;
	string *name, last = "";
	amount=1;
	val_factor=10;
	if( !what ) return notify_fail("你想买什么？\n");

	        if( sscanf(what, "%d %s", amount, what)!=2 )
        {
                amount = 1;
                 
        }
	if( amount < 1 ) return notify_fail("您想买多少？\n");
    if( amount > 10 ) return notify_fail("我这里一次最多买十朵。\n");


	if( !mapp(goods = query("vendor_goods")) ) return notify_fail("这儿的东西全卖光了。\n");
	if(this_player()->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	
	
	name = keys(goods);
	for(i=0; i<sizeof(name); i++) {
		if(what ==  name[i]->name() || name[i]->id(what)) {
			if( stringp(ob_file = name[i]) ) {
				if(goods[name[i]]<amount)
					return notify_fail("我这里没有这么多你要买的这种花了。\n");
				ob = new(ob_file);
			
				
				if(goods[name[i]]<10)
				{
					val_factor=30;
						tell_object(this_player(),"现在这"+ob->query("name")+"只剩下很少了，价格上涨两倍，合"
						+MONEY_D->price_str(ob->query("value")*val_factor/10)+
						"一"+name[i]->query("unit")+"\n");

				}
				else
				if(goods[name[i]]<20)
				{
					val_factor=20;
					tell_object(this_player(),"现在这"+ob->query("name")+"太走俏了，价格上涨一倍，合"
						+MONEY_D->price_str(ob->query("value")*val_factor/10)+
						"一"+name[i]->query("unit")+"\n");

				}
				else
					if(goods[name[i]]<50)
				{
					val_factor=15;
					tell_object(this_player(),"现在这"+ob->query("name")+"喜欢的人很多，价格上涨一半，合"
						+MONEY_D->price_str(ob->query("value")*val_factor/10)+
						"一"+name[i]->query("unit")+"\n");
					
				}
				
	               
////////////////////////////////////////////////////////////

                switch (MONEY_D->player_pay(me, ob->query("value")*amount*val_factor/10)) {
					
                    case 0: destruct(ob); return notify_fail("穷光蛋，一边呆着去！\n");
                    case 2: destruct(ob); return notify_fail("您的零钱不够了，银票又没人找得开。\n");
                }
				ob->set_amount(amount);
                if (ob->move(me)) {
					
					goods[name[i]]=goods[name[i]]-amount;
					if(goods[name[i]] <= 0) {
						map_delete(goods,name[i]);
						last = "最后";
					}
					message_vision(sprintf("$N向$n买下%s"+ chinese_number(amount) +"%s%s。\n", last, ob->query("unit"), ob->name()),
						me, this_object());
				} else destruct(ob);
				this_player()->start_busy(1);
				return 1;
			}
		}
	}
	return notify_fail("您想买什么？\n");
}
int do_check(string arg)
{
	mapping goods;
	string list, *name;
	
	int i;

	if( arg && !this_object()->id(arg) ) return 0;
	
	if( !mapp(goods = query("vendor_goods")) ) return 0;
	name = keys(goods);
	if(!sizeof(name)) return 0;
	list = "你可以购买下列这些东西：\n";
	for(i=0; i<sizeof(name); i++)
		list += sprintf("%-20s(%-5s)：\t%s\t还剩%s%s\n",
			name[i]->query("name"),name[i]->query("id"),
			MONEY_D->price_str(name[i]->query("value")),
			CHINESE_D->chinese_number(goods[name[i]]),
			name[i]->query("unit"));
			
	write(list);
	return 1;	
	
	
}




string query_flower_file( string arg)
{
         return sprintf( DATA_DIR "flower/%c/%s", arg[0], arg );
}

int do_check_flower()
{
                object *ob,ob_letter;
                 string file ;
                  int i;
                  ob=objects();
                  i = sizeof(ob);
                  while (i--)
                {
                        if (userp(ob[i]))
                        {

                                file = query_flower_file( ob[i]->query("id")+".o" );
                                assure_file( file );

                                if(file_size(file)!=-1)
                                {

                                        if(interactive(ob[i]))
                                        if(living(ob[i]))
                                        if(!ob[i]-> is_busy())
                                        if(!ob[i]-> is_fighting() )
                                        {
                                                ob_letter=new("/clone/misc/flower");
                                                ob_letter->set_owner(ob[i]->query("id"));
                                                ob_letter->check(ob[i],this_object());
												destruct(ob_letter);
                                        }
                                }
                        }
                }
				  

          remove_call_out("do_check_flower");
          call_out("do_check_flower", 10+random(10) );

          return 1;
}






int ask_songhua()
{
        write("英莲欠身说到：“感谢客官光临小店，您先在这里将花买好，\n"
			  "然后告诉小女要送给谁，小女一定为您送到。\n"
			  "(song flower_name to playername)”\n"
			  "我们花店收费规则是：送花费用最低十两纹银。\n"
			  "每一朵花收取一两纹银的送花费。\n");

                
                return 1;
}
int do_song(string arg)
{
	object ob_flower,me,send_flower;
	object tar;
    int i,k,money_amount;
    mapping flower,*flowers;
	string flower_name,who;
	me=this_player();
    if( !arg || sscanf(arg, "%s to %s", flower_name, who)!=2 )
		return notify_fail("你要送什么花给谁？\n");
	
	 if(!FINGER_D->acquire_login_ob(who))
		  return notify_fail("这里有这个人吗？\n");
	 ob_flower=present(flower_name,me);
     if(!ob_flower)
        return notify_fail("你身上好像并没有这种物品？\n");
	if(!ob_flower->query("flower_w"))
        return notify_fail("对不起！我们这里不负责送这个。\n");
	if(me->is_busy())
		return notify_fail("你现在正忙着呢。\n");


		if(!send_flower=new("/clone/misc/flower"))
			return notify_fail("/clone/misc/flower初始化错误。\n");
		send_flower->set_owner(who);

		if(send_flower->query("flowername")==flower_name)
		  {
			  command("hmm ");
			  return notify_fail("对不起，我还没将您上次的花送到呢，请您稍后再来吧。\n");
		  }
		
		if(send_flower->query("from")==(me->name(1) + "(" + me->query("id") + ")"))
		  {
			  command("hmm ");
			  return notify_fail("对不起，我还没将您上次的花送到呢，请您稍后再来吧。\n");
		  }

		/////////////////////////////////////////////////////////////////////////////////
		//******************************收费*******************************************//
		if(ob_flower->query_amount()<10)
			money_amount=10;
		else
			money_amount=ob_flower->query_amount();
		
		if(ob_flower->query_amount()>1000)
			money_amount=1000;
		else
			money_amount=ob_flower->query_amount();


		
		switch (MONEY_D->player_pay(me, money_amount*100) )
		{
	        case 0:  destruct(send_flower);
					
					return notify_fail("您好像没有足够的银两来支付送花费用。\n");
            case 2: destruct(send_flower);
					
					return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        }
		message_vision("$N对$n说道：“送花共收您"+price_string(money_amount*100)+"”。\n",this_object(),this_player());
		////////////////////////////////////////////////////////////////////////////////
		send_flower->set("flowername",ob_flower->query("name"));
		send_flower->set("flower_id",ob_flower->query("id"));
		send_flower->set("to",who);
		send_flower->set("from",me->name(1) + "(" + me->query("id") + ")");
		send_flower->set("amount",ob_flower->query_amount());

		flower = ([
                
			"flowername":ob_flower->query("name"),
            "flower_id": ob_flower->query("id"),
            "to": who,
            "from": me->name(1) + "(" + me->query("id") + ")",
			"amount": ob_flower->query_amount(),

        ]);
		send_flower->send_flower(flower);
		send_flower->save();
	


        destruct(send_flower);
		destruct(ob_flower);

		me->start_busy(1);
		
		message_vision("$n将身上的"+flower["flowername"]+"拿出交给$N。\n",this_object(),this_player());
		message_vision("$N对$n说道：“好吧，小女子定会将花送到。\n",this_object(),this_player());
		
		remove_call_out("do_check_flower");
         call_out("do_check_flower", 10+random(10) );

			return 1;


}
