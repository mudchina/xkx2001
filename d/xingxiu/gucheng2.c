//Cracked by Roath
// 古城
// maco

inherit ROOM;

void create()
{
	set("short", "古城");
	set("long", @LONG
这地方极是干燥，草木不生，屋中物品虽然经历了不知多少
年月，但大部仍然完好。沿路只见遍地白骨，刀枪剑戟，到处乱
丢。像是经过了一场大战，全城居民都给敌人杀光一般。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gucheng1",
		"west" : __DIR__"gucheng3",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

