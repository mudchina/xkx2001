//Cracked by Roath
// Room: /d/dali/tusi4.c

inherit ROOM;

void create()
{
	set("short", "后厅");
	set("long", @LONG
议事厅后是后厅，是一楼一底的中式建筑。屋角雕刻细密，纹饰精美，各种
图案和禽兽花木的雕刻，栩栩如生，纹路新颖。这是云南十八座土司府中保留最
好的一座。
LONG);
	set("exits", ([
		"south" : __DIR__"tusi3",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
