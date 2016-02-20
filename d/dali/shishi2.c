//Cracked by Kafei
// Room: /dali/shishi2.c
// AceP

inherit ROOM;

int do_gui();
int do_ketou();
int do_leave();

void create()
{
	set("short", "石室");
	set("long", @LONG
这石室正中立着一座白玉雕成的美女石像(shixiang)，东变石壁上写着许多字，
都是《庄子》中的句子，笔法飘逸，似是极强腕力用利器写成，每一字都深入石壁
近半寸，文末是“逍遥子为秋水妹书。洞中无日月，人间至乐也。”。玉像前有两
个蒲团(putuan)。左侧有个月洞门，右侧似乎是一道石阶(shijie)。
LONG );

	set("exits", ([
		"left"  : __DIR__"shishi3",
	]));

	set("item_desc", ([
		"shixiang" :
"这是一座白玉石像，和生人一样大小，身上一件淡黄的绸衫，微微颤动，手持一柄\n"
"长剑，更奇的是一对眸子莹然有光，神采飞扬。这对眼珠是用黑宝石做成，眼光灵\n"
"动，象极了活人。",
		"putuan" : "一大一小两个蒲团，大的是供人跪下之用，小的是供人磕头之用。\n",
		"shijie" : "一道石阶，长长的看不到头，不知通往何处，可能是出去(leave)的路吧。\n",
	]));
	set("book_count", 1);
	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_gui", "gui");
	add_action("do_ketou", "ketou");
	add_action("do_leave", "leave");
}

int do_gui()
{
	object me;
	me=this_player();

	if (me->query_temp("in_putuan")) {
		tell_object(me,"你已经跪下了。\n"); }
	else {
		tell_object(me,"你在大蒲团上跪下。\n");
		me->set_temp("in_putuan",1);}
	return 1;
}

int do_ketou()
{
	object me, ob;
	me=this_player();

	if (me->query_temp("in_putuan")) 
	{
		if (me->query_temp("ketou_times")>100 && me->query("int")>25) {
			if (query("book_count") > 0){
			tell_object(me,
"你磕得头都晕了，突然发现小蒲团上一层的蒲草已经断裂，露出下面有物！\n"
"里面是个绸包，一尺来长，上面写着：汝既磕首千遍，自当供我驱策，终身无悔。\n"
"此卷是我逍遥派武功精要，每日务需用心练习。\n"
"你得到了北冥秘籍！！！\n");
			ob=new(__DIR__"obj/beiming-miji");
			ob->move(me);
			add("book_count", -1);
			me->set("got_beiming",1);
			me->set_temp("got_miji",1);
			me->delete_temp("ketou_times");
			return 1;
			}
			else {
			tell_object(me,
"你磕得头都晕了，突然发现小蒲团上一层的蒲草已经断裂，但是下面什么也没有。\n");
			me->delete_temp("ketou_times");
			return 1;
			}
		}
		if (!me->query_temp("ketou_times")) {
			tell_object(me,"你在小蒲团上磕了个头，突然发现玉像双脚的鞋子旁刻有字！\n"
"右：磕首千遍，供我驱策。左：遵行我命，百死无悔。\n");
			me->set_temp("ketou_times",1); }
		else {
			tell_object(me,"你磕了个头。\n");
			me->add_temp("ketou_times", 1);	
		}
		return 1;
	}
	return 0;
}

int do_leave()
{
	object me;
	me=this_player();

	tell_object(me,
"你慢慢地走在石阶上，走出一百多步，转了三个弯，耳边听到越来越大的水声，又\n"
"走了二百多步，水声震耳欲聋，前面并有光线透入，走到尽头，前面是个仅可容身\n"
"的小洞，向外一望，外面怒涛汹涌，水流湍急，竟是一条大江。你钻了出去，来到\n"
"了江边。\n");
	me->move(__DIR__"jb1");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("ketou_times") >= 0) {
		me->delete_temp("in_putuan");
		me->delete_temp("ketou_times"); }
	return ::valid_leave();
}
