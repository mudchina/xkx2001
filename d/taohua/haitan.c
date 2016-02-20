//Cracked by Roath
// kane, 16/5/97
// modified by aln 4 / 98

#include <ansi.h>

inherit HARBOR;

void create()
{
	set("short", "海滩");
	set("long", @LONG
这里就是名震江湖的桃花岛了。你放眼望去，除了海天交际处几点海鸥
的影子若隐若现，四周见不到一个人影，不由得心里一阵发慌。北面是一片
灿若云霞的桃林，繁花似锦，五色缤纷，但静悄悄的，似乎透着古怪。桃林
前立了一块石碑(shibei)，上面似乎有些字迹，旁边有一块大石(stone)。
LONG
	);

	set("exits", ([
		"north" : __DIR__"thzhen1",
	]));

	set("item_desc",([
	    "shibei" : "
先天......伏羲......占其地利......
......后天......文王......得其天时......
\n",
	    "stone" : "
大石上方有一块凹痕，象是一个扭曲的八卦形状。
\n",
	]));

/*	set("objects", ([
		"/kungfu/class/taohua/xuanfeng" : 1,
		"/kungfu/class/taohua/chaofeng" : 1,
	]));
*/

	set("cost", 2);
	set("outdoors", "taohua");

        set("island", "桃花岛");
        set("shape", "有一股夹着扑鼻花香的海风吹来。");
        set("navigate/locx", 30);
        set("navigate/locy", -180);

	setup();

}

void init()
{
        ::init();

        add_action("do_put", "put");
        add_action("do_pozhen", "pozhen");
        add_action("do_pozhen","破阵");
}

int do_put(string arg)
{
  object me;
  string item, target;

  me = this_player();

  if (!arg || sscanf(arg, "%s in %s", item, target) != 2)
    return notify_fail("什麽？\n");

  if (!present("bagua", me))
    return notify_fail("什麽？\n");

  if (item != "bagua")
    return notify_fail("什麽？\n");

  if (target != "stone")
    return notify_fail("什麽？\n");

  message_vision("$N把铁八卦放入大石凹痕里\n", me);
  message_vision(HIW"只听得轧轧数声响，桃林向左右两边分开，一条小路出现在$N面前\n$N连忙收起铁八卦，走入桃林。桃林在$N身后又恢复了原状。\n\n"NOR, me);

  me->move("/d/taohua/xiaojing");

  return 1;

}

int do_pozhen()
{
  object me;

  me = this_player();

  if (me->query_skill("qimen-dunjia", 1) < 120) {
    me->receive_damage("jing", 50);
    me->receive_damage("qi", 50);
    me->receive_damage("jingli", 50);
    message_vision("$N冥思苦想半晌不得其解，神困力疲，如同着了魔一样，居然一步步走向桃林\n", me);
    me->move("/d/taohua/thzhen1");
    
  } else {

    message_vision(HIW"$N凝思片刻，桃林的种种生克变化已全盘了然于胸，仰天一声长笑，袍袖一拂，掠入桃林，左一弯，右一转，已影踪不见\n"NOR, me);

  me->move("/d/taohua/xiaojing");
  }
  return 1;

}
/*
int valid_leave(object me, string dir)
{
	mapping myfam;

  	if (dir) {
        	if (!myfam || myfam["family_name"] != "桃花岛") {
         	       me->set_skill("qimen-dunjia", 0);
		}
  	}  
	
	return ::valid_leave(me,dir);
}
*/
