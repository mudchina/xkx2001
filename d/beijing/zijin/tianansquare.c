//Cracked by Roath
// Room: /d/beijing/zijincheng/tianansquare.c

inherit ROOM;

void create()
{
	set("short", "天安门广场");
	set("long", @LONG
天安门广场被五米多高的宫墙围绕，形成一个封闭的丁字型广场。
广场中建有南北走向联檐通脊朝房一百四十间，名为千步廊；东有六部
、宗人府、钦天监，西有太常寺、都察院，时人谓之“东边掌生，西边
掌死”。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xichangan",
  "north" : __DIR__"tiananmen",
  "south" : "/d/beijing/west/zhengyangmen",
  "east" : __DIR__"dongchangan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
