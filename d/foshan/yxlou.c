//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "英雄楼");
        set("long", @LONG
酒楼里桌椅洁净。座中客人衣饰豪奢，十九是富商大贾。
佛山地处交通要地，来这吃饭的人还真不少。
LONG
        );
        set("exits", ([
		"north" : __DIR__"street2",
		"up" : __DIR__"yxlou2",
	]));

	set("objects", ([
		__DIR__"npc/feng7" : 1,
	]));
	set("cost",1);
	setup();
        replace_program(ROOM);
}
