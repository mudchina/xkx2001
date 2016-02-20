//Cracked by Roath
// mozhen.c 磨针井
// by Fang 8/26/96

inherit ROOM;

void create()
{
	set("short", "磨针井");
	set("long", @LONG
相传当年真武进山修炼，日久思归，偶遇一老妇持铁杵研磨。问磨杵
为何？答以磨针。又问铁杵岂能磨针？答云功到自然成。真武由此醒悟，
终于修炼成仙。后人因建磨针井道观以为纪念。殿前立大铁杵一根，殿
旁有老母亭，亭正中有井(jing)。
LONG
	);
        set("outdoors", "wudang");
        set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"shanlu",
	]));
    set("item_desc", ([
            "jing" : "古色古香、黑咕隆咚一口井。\n",
    ]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

