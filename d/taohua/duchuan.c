//Cracked by Roath
// Room: /d/taohua/duchuan.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "海船");
	set("long", @LONG
一艘海船，大概能载十七、八个人。几名健硕的水手
正在船头船尾忙来忙去。
LONG
	);

	set("invalid_startroom", 1);
	set("outdoors", "taohua");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



