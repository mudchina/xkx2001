// Room: /d/taohuacun/taohua2.c

inherit ROOM;

void create()
{
	set("short", "桃花溪");
	set("long", @LONG
“桃花林畔桃花溪，桃花溪水清如洗。浪子浮云空相照，浣衣
歌女梦依稀。”这里就是桃花溪岸长草小径。桃花开有花落时，桃
花落时，片片飞红空坠溪中，流水送去，决无怜惜。你伶立溪上，
睹物思人，伤情无限。 
LONG );
	set("outdoors", "city");
	set("no_clean_up", 0);

	set("exits", ([
		"westup" : __DIR__"taohua3",
		"south"  : __DIR__"taohua1",
		"north"  : __DIR__"taohua6",
	]));
	setup();
	replace_program(ROOM);
}

