//Cracked by Kafei
// Room: /dali/shishi4.c
// AceP

inherit ROOM;

void create()
{
	set("short", "琅寰福地");
	set("long", @LONG
这里原来是个极大的石洞，比外面房间大了数倍，一排排全是书架，可空空的
一本书也没有。你走近细看，书架上贴满了签条，上写江湖各门各派的名称，少林
下注：缺《易筋经》，丐帮下注：缺《降龙十八掌》，大理下注：缺《一阳指》、
《六脉神剑》，撼甚！
LONG );

	set("exits", ([
		"out"    : __DIR__"shishi3",
	]));

	set("cost", 0);
	setup();
}
