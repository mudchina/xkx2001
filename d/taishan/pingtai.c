//Cracked by Kafei
// pingtai.c 峭壁上的平台
// qfy July 13, 1996

inherit ROOM;

void create()
{
        set("short", "平台");
        set("long", @LONG
平台大石上「剑冢」两个大字之旁，尚有两行字体较小的石刻(shike)
。另有一个由许多石块堆成的大坟(grave)。这坟背向山谷，俯仰空阔，占
尽形势，想见堆成此坟的前辈文武全才，抱负非常！
LONG
        );

	set("item_desc",([
            "shike" : "「剑魔独孤求败既无敌於天下，乃埋剑於斯。\n"
	   	      "呜呼！群雄束手，长剑空利，不亦悲夫！」\n",
	    "grave" : "大坟由许多石块堆成。\n"
        ]));


	set("cost", 1);
        setup();
}

void init()
{
	this_player()->delete_temp("marks/风");
	add_action("do_climb", "climb");
	add_action("do_move", "move");
	add_action("do_put", "put");
}

int do_climb(string arg)
{
	object me = this_player();
	me->delete_temp("diao_winner");

	if ( !arg )
	   return notify_fail( "什么？\n" );

	if ( arg != "down" ) 
	   return notify_fail( "你不能往那儿爬！\n" );

   	message_vision("$N手足并用，小心翼翼地往峭壁下爬去。\n", me);
   	me->move(__DIR__"qiaobi1");
	message("vision", me->name()+"由平台上爬了下来。\n", environment(me), me);

	return 1;
}

int do_move(string arg)
{
        object sword, diao, me = this_player();

        if ( !arg || arg != "stone" )
           return notify_fail( "什么？\n" );

     if ( !me->query_temp("marks/玄") ) {
      if ( !objectp(present("xuantie jian", me)) && !objectp(present("xuantie jian", environment(me))) ) {
	me->set_temp("marks/搬", 1);

	if ( !me->query_temp("diao_winner") ) {
	   message_vision("$N企图将大坟上的石块搬开。\n", me);

	   if ( !me->query_temp("fought_diao") ) {
	      message_vision("忽听得“咕咕”数声，一股劲风扑面而来，原来神雕已跟随而至阻止$N移石。\n", me);
              if ( !present("shen diao", environment(me) ) ) {
		diao = new(__DIR__"npc/shendiao");
              	diao->move(environment(me));
	      }
	      diao = present( "shen diao", environment(me) ); 
              COMBAT_D->do_attack(diao, me, query_temp("weapon") );
              me->set_temp("fighter", 1);
              diao->fight_ob(me);
              me->fight_ob(diao);
	      me->set_temp("fought_diao", 1);
	      call_out("observe",1,me,diao);
	   }
	   else return notify_fail("你尝试移开第一个大石块，却发现力有不怠，石块恒然不动。\n");
	}
	else {
	   message_vision("$N将石块搬开，移在一旁。\n", me);
	   sword = new("/clone/unique/xuantie-jian");
           if (!sword) 
	   return notify_fail("你发现原来这里曾经有人来过，不知其人有何意图。\n");
	   sword->move(environment(me));
	   CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了一柄玄铁重剑。", me->query("name")));
	   message_vision("大坟里原来埋藏着一柄黑黝黝毫不起眼的长剑。\n", me);
	   message_vision("$N试着提起长剑，只数尺便呛的一声脱手掉下，在石上一碰，火花四溅。\n", me);
	   message_vision("原来那剑沉重之极，三尺多长的一把剑，重量竟自不下七八十斤！\n", me);
	   message_vision("剑旁的一块石片上写着：「重剑无锋，大巧不工。四十岁前恃之横行天下。」\n", me);
	   me->set_temp("marks/玄", 1);
	   me->delete_temp("diao_winner");			
	   me->delete_temp("fought_diao");
	   me->delete_temp("marks/搬");
	}
     }
     else return notify_fail( "你已有玄铁重剑或玄铁重剑就在地上，何必多此一举？\n");
   } 
   else return notify_fail( "你已取过玄铁重剑了！\n" ); 

     return 1;
}

int observe(object me, object diao)
{
	object ob;

	if( me->is_fighting() && me->query_temp("marks/搬") ) {
            call_out("observe",1,me,diao);
            return 1;
        }

	if( diao->query("qi")*2 <= diao->query("max_qi") ) {
	     me->remove_enemy(diao);
	     diao->remove_enemy(me);
             me->set_temp("diao_winner", 1);
             message_vision("神雕对$N点点头意示嘉许，将坟上最重的一块大石挪开。\n", me);
	     message_vision("神雕侧身让$N搬石，接着便独个儿离开平台。\n", me);
	     destruct(diao);
        }

	return 1;
}

int do_put(string arg)
{
        string sword, what;
        object ob, obj, me = this_player();

        if( !arg || sscanf(arg, "%s in %s", sword, what)!=2 )
                return notify_fail("命令格式: put <物品> in <物品>。\n");

	if ( what != "grave" ){
	printf("你要把东西往哪里放?\n"); 
	return 1;
	}

	if (!(ob=present(sword,me))){
	printf("你身上没有这样东西。\n"); 
	return 1;
	}

	if (ob->query("id")!="xuantie jian"){
	printf("你不能把" + ob->name() + "放进石块堆砌大坟里。\n"); 
	return 1;
	}

//	printf("%s , %s ", sword, what); return 1;

        message_vision("$N将" + ob->name() + "放回石块堆砌大坟里。\n", me);
        destruct(ob);

	message_vision("突然$N背后一个声音说道：“没想到后世小子竟有如此出息者上得此处来。”\n", me);
	message_vision("$N一惊回头看来，见身后五丈开外站着一个青袍客，右臂一只长袖空空如也。\n", me);
	me->set_temp("marks/yangguo", 1);
	obj = load_object("/kungfu/class/gumu/yangguo");
	obj->move("/d/taishan/pingtai");
	if ( me->query("shen") >= -100000 ) {      
		message("vision","杨过对"+me->name()+"低声地说了几句话。\n", environment(me), ({me})); 	
          }
          else {	
          	message_vision( "杨过凝视$N良久，一声长叹，便飘然下山离去。\n", me );
		destruct(obj);
          }	
	return 1;
}
