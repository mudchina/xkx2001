//Cracked by Kafei
// Room: /dali/jhg.c
// AceP, Xuy

inherit ROOM;

string do_look();
int do_laugh();

void create()
{
	set("short", "剑湖宫斗剑厅");
	set("long", @LONG
练武厅东坐着二人。上首是个四十左右的中年道姑，铁青着脸，嘴唇紧闭。下
首是个五十余老者，右手捻着才须，神情甚是得意。两人的座位相距一丈有余，身
后各站着二十余名男女弟子。西边一排椅子上坐着十余位宾客。东西双方的目光都
集注于场中二人的角斗(fighting)。
LONG
	);

	set("item_desc", ([
		"fighting" : (: do_look :),
	]));

	set("exits", ([
		"south"    : __DIR__"jhg1",
	]));

	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_laugh","laugh");
}

string do_look()
{
	this_player()->set_temp("mark/looked", 1);
	return  "    场中二人正在争斗，青光闪动，一柄青钢剑倏地刺出，指向在年汉子左肩，使剑\n"
+"少年不等招用老，腕抖剑斜，剑锋已削向那汉子右颈。那中年汉子剑挡格，铮的一声\n"
+"响，双剑相击，嗡嗡作声，震声未绝，双剑剑光霍霍，已拆了三招，中年汉子诀一引，\n"
+"青钢剑疾刺那汉子大腿。两人招来招往，眼见已拆到七十余招，剑招越来越紧，兀自\n"
+"未分胜败。突然中年汉子一剑挥出，用力猛了，身子微微一幌，似欲摔跌。便在这时，\n"
+"场中少年左手呼一掌拍出，击向那汉子后心，那汉子向前跨出一步避开，手中长剑蓦\n"
+"地圈转，喝一声：“着！”那少年左腿已然中剑，腿下一个踉跄，长剑在地下撑，站\n"
+"直身子待欲再斗，那中年汉子已还剑入鞘，笑道：“褚师弟，承让、承让，伤得不厉\n"
+"害么？”那少年脸色苍白，咬着嘴唇道：“多谢龚师兄剑下留情。”\n";
}

int do_laugh()
{
	object room, me;
	me=this_player();

	if (me->query("combat_exp")>50000 || !me->query_temp("mark/looked")) return 0;

	tell_object(me,"你看到那中年汉子样子很滑稽，忍不住“嗤”的一声笑，知道失态，忙伸手按住嘴。\n");
	tell_object(me,"左子穆对你“哼”的一声冷笑，道：“光杰，人家笑你呢，你下场请教请教吧。”\n"
		"那中年汉子龚光杰巴不得师父有这句话，当下抽出长剑，跳过来向你当胸一刺，把你刺穿了个透明窟窿！\n");

	if (me->query("combat_exp")<30000) {
                me->receive_wound("qi", me->query("max_qi",1)+100 ,"被龚光杰杀死了。");
		return 1; }

	me->unconcious();
        me->set("said",1);
	set("exits/north", __DIR__"houshan");
	delete("looked");
	if (room=find_object(__DIR__"jhg1")) { room->delete("exits/north");	}
	return 1;
}
