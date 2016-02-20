//Cracked by Kafei
// Room: /dali/gudi.c
// AceP

inherit ROOM;

int do_eat(string);
int do_drink(string);
int do_sit();
int do_push(string);
int do_enter(string);

void create()
{
	set("short", "谷底");
	set("long", @LONG
你站在谷底，举目一望，不由得喝了一声彩。只见左边山崖上的大瀑布(pubu)
如玉龙悬空，滚滚而下，倾入一座清澈无比的大湖(lake)之中。瀑布注入处湖水翻
腾，只离得瀑布十余丈，湖水便一平如镜。湖畔生着一丛茶花，随风摇曳生姿。谷
中静悄悄的，别说人迹，连兽踪也无半点，唯闻鸟语间关，遥相和呼。崖边有一大
丛小树，树上有不少野果(yeguo)。
LONG );

	set("item_desc", ([
		"lake"   :
"这湖作椭圆之形，大半部隐在花丛之中，东南西北尽是悬崖峭壁(qiaobi)，绝无出路，\n"
"大瀑布不断注入，湖水却不满溢，想来另有泄水之处。\n",
		"qiaobi" :
"你仰望四壁，发现除了你下来的山路比较最斜，其它各处均是直上直下决计无法攀援，\n"
"仰望高崖，白雾封谷，下来已是这般艰难，再想上去，你决无这般能耐。\n",
		"pubu"   :
"眼光逆着瀑布自下而上的看去，只见瀑布之石一片石壁光润如玉，料想千万年前瀑布比\n"
"今日更大，不知道经过多少年的冲激磨洗，将这半面石壁磨得如此平整。后来瀑布水量\n"
"减少，才露出了这片如琉璃，如明镜的石壁出来。\n",
	]));

	set("cost", 2);
        set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_drink", "drink");
	add_action("do_eat", "eat");
	add_action("do_sit", "sit");
	add_action("do_push", "push");
	add_action("do_enter", "enter");
}

int do_drink(string arg)
{
	object me;
	me=this_player();

	if (arg=="lake") {
		tell_object(me,"你走到湖边，抄起几口湖水吃了，入口清冽，甘美异常，一条冰凉的水线直通入腹中。\n");
		me->set("jing", me->query("max_jing"));
		set("drunk",1);
		return 1;
	}
	return 0;
}

int do_eat(string arg)
{
	object me;
	me=this_player();

	if (arg=="yeguo" && query("drunk")) {
		tell_object(me,"你走过去摘了几个野果吃了，感觉味道好极了。\n");
		me->set("qi", me->query("max_qi"));
		set("ate", 1);
		delete("drunk");
		return 1;
	}
	return 0;
}

int do_sit()
{
	object me;
	me=this_player();

	if (query("ate")) {
		tell_object(me,
"你抱膝坐下，静观湖光山色，四下里清冷幽艳，不觉时光之过，一瞥眼间，忽见身\n"
"旁石壁上似有彩色流动，郝然有一把剑的影子，剑影清澈异常，剑柄，剑身，剑尖，\n"
"护手，无一不是似到十处，而剑影中更发出彩虹一般的晕光闪烁流动，游走不定。\n"
"你大奇，站起来仔细观察，发现壁上的剑影斜指向北，剑尖对准了一块大岩石。你\n"
"走到岩石跟前伸手推去，竟是微微摇晃，岩石高齐胸，按理绝对推不动，伸手到岩\n"
"石下摸去，原来大石是凌空置于一块小石之上，也不知道是天生还是人为。\n\n");
		delete("ate");
		set("found",1);
		return 1;
	}
	return 0;
}

int do_push(string arg)
{
	object me;
	me=this_player();

	if (arg=="right" && query("found")) {
		tell_object(me,
"你双手又推岩石右侧，岩石又晃了一下，但一晃就回，石底发出滕蔓断裂的声音，\n"
"俯身把大小岩石间的藤蔓全部扯去，拨尽泥沙，再推，果见岩石缓缓转动，便如一\n"
"扇大门相似，转到一半，见岩石后露出一个三尺大的洞口。\n");
		delete("found");
		set("opened",1);
		return 1;
	}
	return 0;
}

int do_enter(string arg)
{
	object me;
	me=this_player();

	if (arg=="dong" && query("opened")) 
	{
		tell_object(me,
"你弯腰走进洞去，走得十余步，洞中已无光亮，每一步都先试过虚实，但觉脚下平\n"
"整便似走在石板大道上一样，只是道路不断下斜，突然之间，右手碰到一块凉冰冰\n"
"的圆物，一触之下，那圆物当的一下，声音清亮，伸手再摸，原来是个门环。于是\n"
"伸手推门，那门是铜铁做成，甚是沉重，但里面并未插上，一使力，那门就缓缓的\n"
"开了，走了进去，仍然看不到任何物事，只觉霉气甚重，似乎久已没有人住。继续\n"
"向前，额头撞上了什么东西，原来又是一个门，你慢慢使劲，把门打开，眼前陡然\n"
"明亮了起来。你来到了一间石室。\n");
		me->move(__DIR__"shishi1");
		delete("opened");
		return 1;
	}
	return 0;
}
