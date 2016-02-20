//Cracked by Roath
// room: /mingjiao/zishan.c

inherit ROOM;

void create()
{
        set("short", "紫山");
        set("long", @LONG
这里地势低平，虽称为山，其实只是一座小丘罢了。然而正因如此，
此处树木颇为繁茂，地上也生着厚厚的长草，偶尔草丛乱动，一些野兔獐
狍之类跳跃而过，各色野花竞相开放，景致宜人。
LONG );

        set("exits", ([
                "westdown" : __DIR__"lingjia",
        ]));

	set("objects",([
		__DIR__"obj/xiaohuangshi" : 2,
]));
        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}