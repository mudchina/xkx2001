//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "白虎坛");
	set("long", @LONG
这里是封禅台西南角的白虎坛。整个白虎坛是个方形的广场，
正中地面上站着一头白虎，似乎由整块汉白玉雕成，吊睛巨额，
威风凛凛。白虎的牙齿与利爪都戴上了钢套，一望而知乃是极为
锋利之物。
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"fengchan",
		"east" : __DIR__"xiayi",
	]));

	set("outdoors", "taishan");
	setup();

	replace_program(ROOM);
}

