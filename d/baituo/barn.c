//Cracked by Roath
// room: /d/xingxiu/btbarn
// Jay 10/8/96

inherit ROOM;

void create()
{
	set("short", "蛇舍");
	set("long", @LONG
这是白驼山庄的蛇舍，屋里到处都是毒蛇，墙上有一张「蛇经」
(shejing)，角落摆了一堆捕蛇用的竹篓(zhulou)。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"road1",
	]));
	set("item_desc", ([
		"shejing" : 
		"白驼山训蛇密法：当驭兽术达到三十级以上，可尝试将毒蛇变(bian)成蛇杖，\n"
		"蛇杖乃是白驼山庄的独门兵器。也可以把蛇杖变回毒蛇，驱使害人。\n",
		"zhulou" : "一堆捕蛇用的竹篓，白驼山庄的人想要捕蛇时，可以来这里拿(take)。\n",
	]));
	set("objects", ([ 
		"/d/xingxiu/npc/snake" : 3,
	 ]) );
//	replace_program(ROOM);
	set("cost", 0);
	setup();
}


void init()
{
	add_action("do_lingwu","lingwu");
	add_action("do_take","take");
//	add_action("do_consult","consult");
//	add_action("do_chayue","chayue");
}

int do_lingwu(string arg)
{
	object me = this_player();
	int level, check;

	level = (int)me->query_skill("poison",1);
	check = level*level*level;

	if (!arg || arg!="shejing") 
		return notify_fail("你要领悟什么？\n");
	
	if (!me->query("family") || me->query("family/family_name") != "白驼山")
		return notify_fail("你是未入白驼，难悟白驼蛇经。\n");

	if ( level < 30) 
		return notify_fail("经中所言对你过于高深，你无法领悟。\n");

	if ( level > 100) 
		return notify_fail("经中所言对你太浅，没有任何帮助。\n");

	if ( check > (int)me->query("combat_exp")*10 )
		return notify_fail("你实战经验不足，无法领悟。\n");

	if ( (int)me->query("jing") < 30 )
		return notify_fail("你精神无法集中。\n");

	me->receive_damage("jing", 20);
	me->improve_skill("poison", me->query("int"));
	write("你钻研蛇经，领悟了施毒的法门。\n");
	return 1;
}

int do_take(string arg)
{
	object me = this_player(), obj, fire;

	if( me->query("family/family_name") != "白驼山" ) return 0;

	if (!arg && arg != "zhulou" && arg != "basket" ) 
		return notify_fail("你要拿什麽？\n");

	if ( this_object()->query("take/"+me->query("id") ) >= 3 )
		return notify_fail("你已经拿了不少竹篓，暂时够用了吧？\n");

	obj = new("/d/baituo/obj/zhulou");
	obj->move(me);
	obj->set("keeper", me->query("id"));
	obj->set("long", 
	"一个竹条编成的篓子，是白驼山庄的人专门用来捕(catch)蛇的。\n"
	"篓子外边贴了一张小纸片，上面写着"+me->name()+"。\n"
	);
	message_vision("$N在蛇舍角落找出了一个竹篓。\n", me );

	add("take/"+me->query("id"), 1);
	fire = new("/d/xingxiu/npc/obj/fire");
	fire->move(obj);

	return 1;
}
