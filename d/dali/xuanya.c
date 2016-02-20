//Cracked by Kafei
// Room: /dali/xuanya.c
// AceP

inherit ROOM;

int do_say(string);
int do_walk();

void create()
{
	set("short", "悬崖边");
	set("long", @LONG
你走在深密的树丛当中。这里就在悬崖边上，听得水声响亮，轰轰隆隆，便如
湖水大至一般，抬头一看，只见西北角上犹如银河倒悬，那条大瀑布从高崖上直泻
下来。玉壁如一面大镜子立在白龙峰顶，仍然清晰可见。向下望去，只见深谷中云
雾弥漫，兀自不见尽头。
LONG
	);

	set("exits", ([
		"east"  : __DIR__"yubi",
	]));

	set("cost", 5);
        set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_say", "say");
	add_action("do_walk", "walk");
}

int do_say(string arg)
{
	if (arg=="玉壁月华明" && !this_player()->query("got_beiming"))
		set("said",1);
	return 0;
}

int do_walk()
{
	object me;
	me = this_player();
	
	if (query("said") && me->query_skill("dodge",1)<50 && me->query("dex")<20)
	{
		tell_object(me,"你想随便走走，没想到突然脚下踏了个空，一头向深谷里堕下了去！\n");
		if (me->query("con")<20 || me->query("dex")<15 || me->query("kar")<(15+random(10))) {
			tell_object(me,"你身在半空，双手乱挥，只盼能抓到什么东西，这么乱挥一阵，可什么也没抓住！\n结果，你重重地摔在了谷底的大石头上，成肉饼了！\n");
                        me->receive_wound("qi", me->query("max_qi")+100,"失手跌下悬崖死了。");
			return 1; }
		
		tell_object(me,
"你身在半空，双手乱挥，只盼能抓到什么东西，这么乱挥一阵，转眼间已堕下百馀丈！\n"
"突然间蓬一声，你的屁股撞上了什么物事，不仅下坠的巨力消了。身子反而向上弹起！\n"
"原来你恰好撞到崖边伸出的一株古松。喀喇喇几声响，古松粗大的枝干登时断折了。\n"
"(运气真好，呵呵，大难不死，必有后福！)\n"
"当再次落下时，你赶紧伸出双臂，牢牢抓住了一根树枝，登时挂在半空，不住地摇幌。\n"
"你荡到崖壁边找到了立足之处，惊魂略定，长长地舒了一口气，向崖下张望。\n"
"只见山崖中裂开了一条大缝，勉强可攀授而下。谷底传来轰隆轰隆的声音。\n"
"你喘息了一阵，开始沿着崖缝慢慢爬落。起先山崖似乎无穷无尽，但到后来越爬越快，\n"
"片刻间你便已到了谷底。\n");
		me->move(__DIR__"gudi");
		return 1;
	}
	return 0;
}
