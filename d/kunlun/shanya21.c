//Cracked by Roath
// Room: /d/mingjiao/shanya21.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "小山崖");
	set("long", @LONG
崖上生满草木。崖不高，教中弟子早已把此处修得可以通人，路虽不太好
走，可对都有一身功夫的教中弟子来说，亦不算些什么。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"shanlu19",
  "northeast" : __DIR__"shangang",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
