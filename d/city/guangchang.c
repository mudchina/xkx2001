//Cracked by Roath
// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

string* locations = ({
	"/d/shaolin/bamboo1",	//竹林
	"/d/shaolin/damodong",	//达摩洞
	"/d/shaolin/beilin3",	//地下室
	"/d/shaolin/dzdian",	//木人
	"/d/shaolin/bydian",	//木人
	"/d/shaolin/wuchang1",	//木人
	"/d/shaolin/wuchang2",	//木人
	"/d/shaolin/wuchang3",	//木人
	"/d/shaolin/dmyuan2",	//达摩院
	"/d/shaolin/cjlou1",	//藏经阁
	"/d/wudang/donglang2",	//东厢走廊
	"/d/wudang/liangongfang",	//练功房
	"/d/wudang/shanmen",	//山门
	"/d/emei/leidong",	//雷洞坪
	"/d/emei/chanfang_fs",	//禅房
	"/d/emei/chanfang_qf",	//禅房
	"/d/emei/chanfang_wn",	//禅房
	"/d/emei/hz_chanfang",	//禅房
	"/d/zhongnan/c_dlang",	//沙袋
	"/d/zhongnan/c_xilang",	//木桩
	"/d/zhongnan/yangxin",	//养心殿
	"/d/zhongnan/bingdong",	//冰洞
	"/d/zhongnan/fengdong",	//风洞
	"/d/zhongnan/xuanya1",	//悬崖
	"/d/zhongnan/xuanya2",	//悬崖
	"/d/zhongnan/xuanya3",	//悬崖
	"/d/zhongnan/xuanya4",	//悬崖
	"/d/huashan/midong",	//密洞
	"/d/dali/wangfu7",	//承光壁
	"/d/dali/diziarea",	//小院
	"/d/dali/chufang",	//伙房
	"/d/dali/yideng12",	//一灯
	"/d/xueshan/houyuan",	//后院
	"/d/xueshan/wangyou",	//忘忧谷
	"/d/xueshan/luyeyuan",	//鹿野苑
	"/d/taohua/guanchao",	//观潮台
	"/d/taohua/shijian",	//试剑亭
	"/d/taishan/nantian",	//南天门
	"/d/taishan/fengchan",	//封禅台
	"/d/taishan/zhengqi",	//正气厅
	"/d/taishan/xiayi",	//侠义厅
	"/d/xixia/wangling",	//石人武士
	"/d/xixia/deling",	//石人武士
	"/d/xixia/huilang",	//侍卫
	"/d/xixia/square",	//侍卫
	"/d/xixia/piandian2",	//侍卫
	"/d/xixia/jytang",	//一品堂武士
	"/d/xixia/ypgate",	//一品堂武士
	"/d/xixia/gate",	//皇宫卫士
});
void create()
{
	set("short", "中央广场");
	set("long", @LONG
城市的正中心是一个很宽阔的广场，地面上铺着青石，经常有艺人在这里表
演。一些游手好闲的人在这里溜溜达达。中央有一棵大槐树，盘根错节，据传已
有千年的树龄，是这座城市的历史见证。树干底部有一个很大的洞(dong)。你可
以看到北边有来自各地的行人来来往往，南面人声鼎沸，一派繁华景象，东边不
时地传来朗朗的读书声，西边则见不到几个行人，一片肃静。
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city");

	set("item_desc", ([
		"dong" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n",
	]));

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
//		"enter" : "/u/xuy/bwdh1/kantai1",
	]));

	set("objects", ([
		__DIR__"npc/liumang" : 1,
		__DIR__"npc/liumangtou" : 1,
		CLASS_D("emei")+"/ji" : 1,
                "/kungfu/class/shenlong/zhang" : 1,
	]));

	set("cost", 1);
	setup();

	remove_call_out("determine_target");
        call_out("determine_target", 50);

}

void init()
{
	object ob, obj1, obj2, maskman, me = this_player();
	int level;

	if ( interactive(ob=this_player()) ) {
		if ( ob->query_temp("biao/zhu") && present("hong biao", ob) && random(3)==1 ) {
		   message_vision("$N在人潮中被人撞了一下。\n", ob);
		   if ( random(ob->query("combat_exp")) <= ob->query("combat_exp")/2 ) {
			tell_object( ob, "你的红镖被扒走了！\n" );	
			ob->delete_temp("biao/zhu");
			ob->delete_temp("apply/short");
			ob->set_temp("biao/fail", 1);
			obj1 = present("hong biao", ob);
			destruct(obj1);
		   }
		   else message_vision("$N发现原来那人是个扒手，那人见时机败露，便落荒而逃了！\n", ob);
		}

		if ( query("target_found") == 1 ) {
			delete("target_found");
		}

		if ( random(10) == 5 && !query("target_found") ) {
			//remove_call_out("determine_target");
			call_out("determine_target", 1);
			set("target_found", 1);
                        //maskman = new(__DIR__"npc/maskman");
                        //maskman->move(environment(me));
                }
	}


        add_action("do_enter", "enter");
}
private int is_suitable(object target)
{
        if ( target->query("combat_exp") < 100000  || wizardp(target) 
	|| target->is_ghost() || environment(target)->query("no_fight")
	|| environment(target)->query("short") == "监狱" 
	|| environment(target)->query("short") == "地牢" 
	|| environment(target)->query("short") == "牢房"
	|| environment(target)->query("short") == "铁牢"
	|| ( target->is_busy() && ( !target->query_temp("pending/excercise") 
	&& !target->query_temp("pending/respirate") ) )
	|| target->is_fighting() || !living(target) ) {
                return 0;
        }

        return 1;
}

private int copyvictim(object me, object victim)
{
	mapping skill_status;
	string *sname;
	int i, max = 0, max1, j, power;

	if ( mapp(skill_status = victim->query_skills()) ) {
		skill_status = victim->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
		}
		
		max1 = (int)max*4/5 + 1;
		max = (int)max*4/5 + 1 + random((int)max/2);
		
		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );
		me->set_skill("force", max1);
		switch( random(4) )
		{
			case 0:
				me->set_skill("cuff", max1);
				me->set_skill("yujiamu-quan", max1);
				me->map_skill("cuff", "yujiamu-quan");
				me->prepare_skill("cuff", "yujiamu-quan");
				me->set_skill("hand", max1);
				me->set_skill("dashou-yin", max1);
				me->map_skill("hand", "dashou-yin");
				me->prepare_skill("hand", "dashouyin");
				me->set_skill("longxiang-banruo", max1);
				me->map_skill("force", "longxiang-banruo");
				me->set_skill("shenkongxing", max1);
				me->map_skill("dodge", "shenkongxing");
				switch( random(2) ) {
				   case 0:
					me->set_skill("staff", max);
					me->set_skill("jingang-chu", max);
					me->map_skill("staff", "jingang-chu");
					me->map_skill("parry", "jingang-chu");
					me->carry_object("/clone/weapon/tiezhang")->wield();
					break;
				   case 1:
					me->set_skill("sword", max);
					me->set_skill("mingwang-jian", max);
					me->map_skill("sword", "mingwang-jian");
					me->map_skill("parry", "mingwang-jian");
					me->carry_object("/clone/weapon/changjian")->wield();
					break;
				}
				break;
			case 1:
				me->set_skill("strike", max1);
				me->set_skill("chousui-zhang", max1);
				me->map_skill("strike", "xingxiu-duzhang");
				me->prepare_skill("strike", "xingxiu-duzhang");
				me->set_skill("claw", max1);
				me->set_skill("sanyin-zhua", max1);
				me->map_skill("claw", "sanyin-zhua");
				me->prepare_skill("claw", "sanyin-zhua");
				me->set_skill("huagong-dafa", max1);
				me->map_skill("force", "huagong-dafa");
				me->set_skill("staff", max);
				me->set_skill("tianshan-zhang", max);
				me->map_skill("staff", "tianshan-zhang");
				me->set_skill("zhaixinggong", max1);
				me->map_skill("dodge", "zhaixinggong");
				me->map_skill("parry", "tianshan-zhang");
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
			case 2:
				me->set_skill("strike", max1);
				me->set_skill("lingshe-shenfa", max1);
				me->map_skill("dodge", "lingshe-shenfa");
				me->set_skill("huagu-mianzhang", max1);
				me->map_skill("strike", "huagu-mianzhang");
				me->prepare_skill("strike", "huagu-mianzhang");
				me->set_skill("kick", max1);
				me->set_skill("jueming-tui", max1);
				me->map_skill("kick", "jueming-tui");
				me->prepare_skill("kick", "jueming-tui");
				me->set_skill("dulong-dafa", max1);
				me->map_skill("force", "dulong-dafa");
				me->set_skill("ruyi-gou", max);
				me->map_skill("hook", "ruyi-gou");
				me->set_skill("hook", max);
				me->carry_object("/clone/weapon/hook")->wield();
				break;
			case 3: 
				me->set_skill("strike", max1);
				me->set_skill("hamagong", max1);
				me->set_skill("hand", max1);
				me->set_skill("shexing-diaoshou", max1);
				me->map_skill("hand", "shexing-diaoshou");
				if ( max > 100 ) {
					me->map_skill("strike", "hamagong");
					me->prepare_skill("strike", "hamagong");
				}
				else {
					me->prepare_skill("hand", "shexing-diaoshou");
				}
				me->map_skill("force", "hamagong");
				me->set_skill("staff", max);
				me->set_skill("lingshe-zhang", max);
				me->map_skill("staff", "lingshe-zhang");
				me->map_skill("parry", "lingshe-zhang");
				me->set_skill("chanchubu", max1);
				me->map_skill("dodge", "chanchubu");
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
		}

		me->set("combat_exp", victim->query("combat_exp")+random(victim->query("combat_exp")/10));
		me->set("max_qi", victim->query("max_qi"));
		me->set("eff_qi", victim->query("max_qi"));
		me->set("max_jing", victim->query("max_jing"));
		me->set("eff_jing", victim->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", victim->query("jiali")*3/4);

		if ( victim->query("max_neili") > 0 ) {
			me->set("max_neili", victim->query("max_neili"));
		}
		else me->set("max_neili", 500);

		if ( victim->query("max_jingli") > 0 ) {
			me->set("max_jingli", victim->query("max_jingli"));
		}
		else me->set("max_jingli", 500);

		power = me->query("combat_exp")/10000;
		if ( power < 100 ) power = 100;
		if ( power > 1000 ) power = 1000;

		me->add_temp("apply/attack", power);
		me->add_temp("apply/dodge", power);
		me->add_temp("apply/armor", power);
                me->add_temp("apply/defense", power);

		me->set("neili", me->query("max_neili"));
		me->set("jingli", me->query("max_jingli"));
		
		me->set_leader(victim);
		me->set("no_sing", 1);
	}

	return 1;
}

void determine_target()
{
        object victim, maskman, room, *all, *all1;
        int i, j, k, num, attempt1, attempt2;

	attempt1 = 0;
	attempt2 = 0;
	k = sizeof(locations) / 10;
	if ( k > 20 ) {
	   k = 20;
	}
	else if ( k < 15 ) {
	   k = 15;
	}

	while( query("target_found") < 2 && attempt2 < 10 ) {
	   while ( attempt1 < k ) {
		if ( !room = find_object(locations[random(sizeof(locations))]) )
			room = load_object(locations[random(sizeof(locations))]);

		if ( objectp(room) && file_name(room) != query("last_room") ) {
		   all = all_inventory(room);
		   all1 = allocate(sizeof(all));

		   for ( i=0; i<sizeof(all); i++ ) {
                      if ( all[i]->is_character() && userp(all[i]) ) {
				all1[num] = all[i];
				num++;
		      }	
        	   }

		   if ( num > 0 ) {	
        	      j = random(num);
		      victim = all1[j];

		      if ( objectp(victim) && query("last_target") != victim->query("id") ) {
			   if ( is_suitable(victim) ) {
			   	set("target_found", 2);
				set("last_room", file_name(room));
				set("last_target", victim->query("id"));
				attempt1 = k;
				victim->start_busy(2);
			   	maskman = new(__DIR__"npc/maskman");
        		   	maskman->set_temp("target", victim->query("id"));
				copyvictim( maskman, victim );
        		   	maskman->move(environment(victim));
			   }
		      }
		   }
		}
		
		attempt1++;
	   }

	   if ( query("target_found") < 2 && attempt1 >= k ) {
		all = users();
	
		j = random(sizeof(all));
                victim = all[j];

                if ( objectp(victim) && is_suitable(victim) ) {
                        set("target_found", 2);
				victim->start_busy(2);
                        maskman = new(__DIR__"npc/maskman");
                        maskman->set_temp("target", victim->query("id"));
				copyvictim(maskman, victim);
                        maskman->move(environment(victim));
                }
		else attempt2++;
	   }
	}

	set("target_found", 2);
	remove_call_out("resume_targeting");
	call_out("resume_targeting", 900);
	remove_call_out("determine_target");
        call_out("determine_target", 1200);
}

void resume_targeting()
{
	delete("target_found");
}

int do_enter(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" ) 
        {
                if ( me->query_temp("exit_blocked") )
                        return notify_fail("你正忙着挡住别人的出路呢！\n");
                if ( me->query("rided") ) 
                        return notify_fail("骑着东西钻洞？！\n");

                if ( me->is_busy() || me->is_fighting() )
                        return notify_fail("你正忙着呢！\n");

               message("vision",
                        me->name() + "一弯腰往洞里走了进去。\n",
                        environment(me), ({me}) );

                me->move("/d/gaibang/inhole");
                message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );

                return 1;
        }
}
