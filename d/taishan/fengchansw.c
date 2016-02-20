//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "青龙坛");
	set("long", @LONG
这里是封禅台西南角的青龙坛。整个青龙坛是个方形的广场，
正中地面上镶嵌着一条巨龙，似乎全由青铜铸成，张牙舞爪，呼之
欲出。青龙上无数鳞片闪闪发光，据说每一片都从战死沙场的将士
盔甲上获得。千百冤魂缠绕龙身，以无边厌气镇压此坛。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"fengchan",
		"west" : __DIR__"zhengqi",
	]));

	set("outdoors", "taishan");
	setup();

	replace_program(ROOM);
}


