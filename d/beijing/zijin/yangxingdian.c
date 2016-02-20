//Cracked by Roath
// Room: /d/beijing/zijincheng/yangxingdian.c

inherit ROOM;

void create()
{
	set("short", "养性殿");
	set("long", @LONG
这里是乾隆预备归政后的寝兴之所，但实际上乾隆从没在此住过。
只在乾隆四十六年十二月，在此殿赐宴王公大臣、蒙古王公、贝勒和
额驸，台吉等。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"leshoutang",
  "south" : __DIR__"yangxingmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
