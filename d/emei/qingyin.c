//Cracked by Roath
// qingyinge.c 清音阁
// Shan: 96/06/22
// haowen 10/10/00 add busy check in jump
inherit ROOM;

void create()
{
        set("short", "清音阁");
	set("long", @LONG
这里是峨嵋山的清音阁。此阁位于牛心岭下，东有白龙江，西有黑龙江，
两江之水交汇于清音阁下。江上有拱桥两座，分夸黑龙白龙二江，这就是双飞
桥。两江合流处，有一数米高的黑褐色巨石傲然挺立，形似牛心，名之为「牛
心石」。桥边立有一石碑(shibei)。由此向西上，左行是黑龙江栈道，右路至
白龙洞，东去中峰寺。
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"zhandao1",
		"northwest" : __DIR__"bailong",
		"southeast" : __DIR__"zhongfeng",
	]));

        set("resource/water", 1);

        set("objects", ([
		__DIR__"npc/f_dizi1" :1,
                CLASS_D("emei") + "/jingxian" :1,
        ]));

        set("item_desc", ([
                "shibei" :
"石碑刻有一诗曰：\n\n"
"　　　　　　　杰 然 高 阁 出 清 音，\n\n"
"              仿 佛 仙 人 下 抚 琴。\n\n"
"　　　　　　　试 向 双 溪 一 倾 耳，\n\n"
"              无 情 两 水 漱 牛 心。\n\n"
"这就是“峨嵋十景诗”中专咏这“双桥清音”的诗。\n"

])  ) ;

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if (!arg || arg != "牛心石" ) return 0;

        if(me->is_busy())
                {
                tell_object(me,"你现在正忙着呢！\n");
                return 0;
                }     
	message_vision("$N一纵身往牛心石跳去。", me);

	if ( me->query_skill("dodge") < 30+random(6) ) {
		message_vision("可惜轻功火候太浅，跃到离巨石几尺之处再也支持不住，\n直堕入江中，一下就被湍急的江流冲得无影无踪了。\n", me);
		me->set_temp("last_damage_from", "跳进江中淹死了。");
		me->die();
	}
	else {
		message("vision", "\n", environment(me));
		me->move(__DIR__"niuxin");
		message("vision", me->name() + "纵身由江边跳了过来。\n", 
			environment(me), ({me}) );
	}
	return 1;
}
