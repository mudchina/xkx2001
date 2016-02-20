//Cracked by Roath
// Room: /d/snow/herbshop1.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间光线阴暗的密室，从地上厚厚的灰尘看得出来这里很少有
人出入，靠西边的地上放着一副脚镣，连着一条铁链镶在墙上，不知道
是用来锁什麽人，南面的墙(wall)是用红杉木做的，跟另外三面的灰土
墙比起来显得有些不寻常。
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"chuchang",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
void init()
{
	object me = this_player();

	if ( me->query("eat_wan") && me->query("mud_age") < me->query("eat_age")+86400)
	{
	tell_object(me, "你已服仙丸，应在一年内再次服用，否则功力大损！！！\n");
	}

	if ( me->query("eat_wan") && me->query("mud_age") > me->query("eat_age")+86400)
	{
	tell_object(me, "你一年内未服仙丸，功力大损！！！\n");
	me->add("max_jingli", -100);
	me->add("max_neili", -100);
	me->set("eat_age", me->query("mud_age"));
	}

}
