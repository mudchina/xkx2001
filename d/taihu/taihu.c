//Cracked by Roath
//Kane

inherit FERRY;

void create()
{
	set("short", "太湖");
	set("long", @LONG
太湖古称五湖，襟带三州，周行五百里，东南之水皆归于此。
其时但见长天无波，放眼皆碧，七十二峰苍翠挺立于三万六千顷波
涛之中，不觉令人心怀大畅。由此登船可前往太湖之中的归云庄。
LONG
	);
	set("exits", ([
	 	"east" : __DIR__"taihu2",
		"southwest" : __DIR__"road",
	]));
	set("cost", 2);
	set("outdoors", "guiyun");

	set("objects", ([
		"/d/taihu/npc/guanying" : 1,
	]));

	set("name", "湖");
	set("boat", __DIR__"duchuan");
	set("opposite", __DIR__"matou");

	setup();
}
