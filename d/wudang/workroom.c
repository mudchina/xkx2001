//Cracked by Roath
// Room: /u/xqin/workroom.c

inherit ROOM;
#include <ansi.h>
void init();
string look_dashi();

void create()
{
        set("short", HIW "水云间" NOR);
        set("long", @LONG
这里是无量山後的深谷，东南西北尽是悬崖峭壁。仰望高崖，白雾封谷
。左边山崖上一条大瀑布如玉龙悬空，滚滚而下，倾入一座清澈异常的大湖
中。瀑布注入处湖水翻滚，离得瀑布十余丈，湖水便一平如镜。淡淡的月光
照入湖中，湖心也有一个皎洁的圆月(moon)。
LONG
        );
        set("valid_startroom", 1);
     //   call_other("/clone/board/xqin_b", "???");
        
        set("exits", ([
                "gb" : "/d/gaibang/undertre",
  		"sl" : "/d/shaolin/guangchang1",
	        "bt" : "/d/xingxiu/btyard",
  		"yz" : "/d/city/kedian",
  		"xx" : "/d/xingxiu/xxh2",
  		"zn" : "/d/zhongnan/taijie2",
  		"th" : "/d/taohua/jingshe",
  		"hs" : "/d/huashan/pianting",
  		"sh" : "/d/shenlong/tingkou",
  		"wd" : "/d/wudang/sanqingdian",
  		"xs" : "/d/xueshan/guangchang",
  		"dl" : "/d/dali/wangfu1",
  		"em" : "/d/emei/hz_guangchang",
  		"xk" : "/d/xiakedao/dadong",
  		"gy" : "/d/taihu/qianyuan",
  		"bj" : "/d/beijing/kedian",
  		"xy" : "/d/xiangyang/kedian",
  		"kt" : "/d/city/kantai",
  		"qz" : "/d/quanzhou/qianting",
  		"ft" : "/d/city/ft_datang",
  		"xj" : "/d/qilian/datang",
  		"wiz" : "/d/wizard/wizard_room",
  		"pig" : "/d/city/duchang2",
  		"blk" : "/d/death/blkbot",
        ]));

                set("objects", ([
                "d/city/npc/obj/flower/white_rose" : 1,
        ]));

    set("item_desc",([
        "dashi"        : HIW"  
     不 虽 古 得 云 时 只 琼  羽 终 晓 机  愿 如 又 自 亦 赤 方 月  回 得 无 一
     悔 历 都 一 端 光 是 楼  化 能 阳 缘  弃 人 谁 古 叹 诚 道 暗  首 居 量 箫    侠
     当 无 踏 知 一 逝 高 玉  乘 拨 清 济  钨 饮 想 只 不 之 青 风  昔 今 玉 一
     初 数 雪 己 刻 去 处 宇  风 云 枫 遇  砂 水 过 道 得 心 天 高  时 朝 壁 琴    客
     侠 风 三 已 凡 如 不 无  上 见 为 柳  吐 冷 心 仙 见 日 非 移  子 凌 映 水 
 萧  客 雨 生 无 几 流 胜 限  九 皓 我 下  真 自 默 人 光 月 青 换  夜 宵 华 云    行   
 琴  行 摧 缘 憾 千 水 寒 好  天 月 师 逸  言 知 泪 笑 明 鉴 天 影  宁 殿 年 间\n"NOR,
		
        "moon" :       "你抬头向月亮瞧去，却已见不到月亮，原来皓月西沉，已落到了西首峭壁之後，
峭壁上有一洞孔，月光自洞孔彼端照射过来，洞孔(hole)中隐隐有光彩流动。\n",
        "hole" :       "月亮透过峭壁洞孔，将一把彩色缤纷的剑影映到小无量玉壁上。见壁上剑
影斜指北方，剑尖对准了一块大岩石(dashi)。\n",
    ]));

    setup();
}

void init()
{
    add_action("do_qu", "qu");
    if (this_player()->query("id") == "xqin")
    add_action("do_setup", "setup");
    
}



int do_qu(string arg) {
      object me;

        me=this_player();
        if( !arg )
                return notify_fail("去哪里？\n");
        
        if( file_size("/u/"+arg + "/workroom.c") <= 0 )
                return notify_fail("现在还没有那个地方。\n");
         message_vision(HIW"$N钻进时空隧道，霎时间没了踪影。\n"NOR,
                  this_player());
         this_player()->move("/u/"+arg+"/workroom");             
         message_vision(HIW"$N钻出时空穿梭机，突然出现在一阵烟雾中。\n"NOR,me);
         
       return 1;
}

int do_setup()
{
	object me = this_player();

	if (me->query("id") == "xqin")
	{
	me->set("max_jing", 10000);
	me->set("max_jingli", 10000);
	me->set("max_neili", 20000);
	me->set("max_qi", 20000);
	me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
        me->set("neili", (int)me->query("max_neili"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
	me->clear_condition();
	
	me->set_skill("parry", 400);
	me->set_skill("sword", 400);
	me->set_skill("taiji-jian", 400);
	me->set_skill("dodge", 400);
	me->set_skill("force", 400);
	me->set_skill("taiji-shengong", 400);
        me->set_skill("mian-zhang", 400);
        me->set_skill("strike", 400);
        me->set_skill("cuff", 400);
        me->set_skill("taiji-quan", 400);
        me->set_skill("taoism", 400);
        me->set_skill("literate", 400);
        me->set_skill("poison", 600);
        me->set("combat_exp", 6400000);
        
        me->map_skill("force", "taiji-shengong");
        me->map_skill("dodge", "tiyunzong");
        me->map_skill("cuff", "taiji-quan");
        me->map_skill("strike", "mian-zhang");
        me->map_skill("parry", "taiji-quan");
        me->map_skill("sword", "taiji-jian");

        me->prepare_skill("cuff", "taiji-quan");
        me->prepare_skill("strike", "mian-zhang");
	return 1;
	}
	else { 
		return notify_fail("什么？\n");
	}
	
}