//Cracked by Roath
// Room: /d/shaolin/fumoquan.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "金刚伏魔圈");
	set("long", @LONG
三棵大松树的树干上各挖了个可容身一人的大洞，有个洞口
露出黑色僧袍一角，似乎住得有人。中央是一片大草坪，中心处
光秃秃的，似乎经常受大力击打，以致寸草不生。
LONG
	);

	set("exits", ([
		"out" : __DIR__"qyping",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/du-nan" : 1,
		CLASS_D("shaolin") + "/du-e" : 1,
		CLASS_D("shaolin") + "/du-jie" : 1,
	]));
	set("cost", 2);
	setup();
}

void init()
{	
	mapping fam;
	string name;	
	
	fam = this_player()->query("family");
	name = this_player()->query("name");

	if ( mapp(fam) && fam["family_name"] == "少林派" && fam["generation"] <= 37 && (name[0..1] == "玄" || name[0..1] == "渡")) return;

	if( interactive( this_player()) ) {
		message_vision(HIR "突然间劲气纵横，三根黑索如三条黑蟒般就地滚来，瞬间近身，\n" +
		"化成一条笔自的兵刃，如长矛，如杆棒，如利剑，分别向$N的头，\n" +
		"胸，腹三处要害疾刺而至。$N一瞥间，看到三个老僧分居三个树  \n" +
		"洞之中，正全力持鞭向$N攻来！$N已陷身于少林寺之蕴含无上降  \n" +
		"魔大法的金刚伏魔圈！\n\n" NOR, this_player());
	}

	if ( mapp(fam)
	&& fam["generation"] > 36 
	&& fam["family_name"] == "少林派" 
	&& this_player()->query("qi") < 300 ) 
	{

		message_vision(HIR "$N被一道排山倒海般的劲气击中，顿时飞了出去 !\n" NOR, this_player());
	}

}

int valid_leave(object me, string dir)
{

	if( dir == "out" && present("puti zi", me) )
	{
		return notify_fail("渡难说道: 不能带着菩提子离开伏魔圈 !\n");
	}
	me->delete_temp("fighter");

	return ::valid_leave(me, dir);
}
