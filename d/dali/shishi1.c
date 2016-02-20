//Cracked by Kafei
// Room: /dali/shishi1.c
// AceP

inherit ROOM;

int do_push(string);

void create()
{
	set("short", "石室");
	set("long", @LONG
你现在所处之地是座圆型石室，光亮由左边透来，但朦朦胧胧地不似天光，走
向光亮之处，忽见一只大虾在窗(window)外悠然游过。这房中放着一张石桌，桌前
有凳，桌上竖着一面铜镜，镜旁放有梳子钗等，看来竟是闺房所居，铜镜上结满了
铜绿，桌上也是尘土寸积，不知道已有多少年无人来此。东首一面斜置的铜镜反映
光亮照向西南隅的石壁(shibi)。
LONG );

	set("item_desc", ([
		"window" :
"细看那窗时，原是镶在石壁的一块大水晶，约有铜盆大小，光亮便从水晶中透入。\n"
"正在看着，又见一条花纹斑烂的鲤鱼在窗悠然而过。你大奇，双眼帖着水晶几外瞧\n"
"去，只见碧绿水流不住幌动，鱼虾水族来回游动，极目所至，竟无尽处。你恍然大\n"
"悟，原来处身之地意在水底，当年造石室之人花了偌大的心力，将外面的水光引了\n"
"进来，这块大水晶更是极难得的宝物。\n",
		"shibi"  : "这石壁上似有一道缝。\n",
	]));

	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_push", "push");
	add_action("do_enter","enter");
}

int do_push(string arg)
{
	object me;
	me=this_player();

	if (arg=="shibi") {
		tell_object(me,"你使力推那石壁，果然是一道门，缓缓移开，露出一洞，洞内有一道石级。\n");
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
"你顺着石级走下。石级向下十馀级后，面前隐隐约约的似有一门，伸手推门，眼前\n"
"陡然一亮，你失声惊呼出来：“啊哟！”\n"
"眼前一个宫装美女，手持长剑，剑尖对准了你的胸膛！\n");
		me->move(__DIR__"shishi2");
		delete("opened");
		return 1;
	}
	return 0;
}

